#include "all.h"


void mem_unprotect(const void *addr, size_t len)
{
	void  *page_addr = (void *)((uintptr_t)addr & ~(PAGE_SIZE - 1));
	size_t page_len  = len + ((uintptr_t)addr % PAGE_SIZE);
	
	if (mprotect(page_addr, page_len,
		PROT_READ | PROT_WRITE | PROT_EXEC) != 0) {
		warn("mprotect failed in mem_unprotect(%p)", addr);
	}
}

void mem_protect(const void *addr, size_t len)
{
	void  *page_addr = (void *)((uintptr_t)addr & ~(PAGE_SIZE - 1));
	size_t page_len  = len + ((uintptr_t)addr % PAGE_SIZE);
	
	if (mprotect(page_addr, page_len,
		PROT_READ | PROT_EXEC) != 0) {
		warn("mprotect failed in mem_protect(%p)", addr);
	}
}


void func_unprotect(const func_t *func)
{
	mem_unprotect((void *)func->func_addr, func->func_size);
}

void func_protect(const func_t *func)
{
	mem_protect((void *)func->func_addr, func->func_size);
}


void mem_dump(const void *addr, size_t len, bool align)
{
	uintptr_t start = (uintptr_t)addr;
	uintptr_t end   = (uintptr_t)addr + len;
	
	if (align) {
		/* round down to 16 bytes */
		start &= ~0xf;
		
		/* round up to 16 bytes */
		if ((end & 0xf) != 0) {
			end &= ~0xf;
			end += 0x10;
		}
	}
	
	pr_info("mem_dump @ %p, len %u\n", addr, len);
	
	const uint8_t *ptr = (const uint8_t *)start;
	int i = 0;
	
	while (ptr != (uint8_t *)end) {
		if (i == 0) {
			pr_debug("  %08x: ", (uintptr_t)ptr);
		} else if (i == 8) {
			pr_debug(" ");
		}
		
		pr_debug(" %02x", *ptr);
		
		if (i == 15 || (ptr + 1) == (uint8_t *)end) {
			pr_debug("\n");
		}
		
		++ptr;
		if (++i >= 0x10) {
			i = 0;
		}
	}
}


void func_dump(const func_t *func)
{
	mem_dump((void *)func->func_addr, func->func_size, false);
}


static bool _find_string_internal(const char *haystack, size_t limit,
	const char *needle, uintptr_t *result)
{
	size_t str_len = strlen(needle) + 1;
	
	for (int i = 0; i + str_len <= limit; ++i) {
		if (memcmp(haystack + i, needle, str_len) == 0) {
			*result = i;
			return true;
		}
	}
	
	return false;
}

uintptr_t find_string(const char *lib_name, const char *str, bool absolute)
{
	library_info_t *lib = lib_find(lib_name);
	
	uintptr_t off;
	if (_find_string_internal(lib->map + lib->rodata_off, lib->rodata_size,
		str, &off)) {
		off += lib->rodata_off;
		if (absolute) {
			return lib->baseaddr + off;
		} else {
			return off;
		}
	} else {
		return 0;
	}
}

uintptr_t find_string_global(const char *lib_name, const char *str,
	bool absolute)
{
	library_info_t *lib = lib_find(lib_name);
	
	uintptr_t off;
	if (_find_string_internal(lib->map, lib->size, str, &off)) {
		if (absolute) {
			return lib->baseaddr + off;
		} else {
			return off;
		}
	} else {
		return 0;
	}
}


int64_t conv_timespec_to_nsec(const struct timespec *t)
{
	return ((int64_t)t->tv_nsec + (1000000000LL * (int64_t)t->tv_sec));
}


const char *try_demangle(const char *mangled)
{
	const char *demangled = cplus_demangle(mangled,
		DMGL_GNU_V3 | DMGL_TYPES | DMGL_ANSI | DMGL_PARAMS);
	
	if (demangled != NULL) {
		return demangled;
	} else {
		return mangled;
	}
}


int conv_EHANDLE_to_entindex(EHANDLE handle)
{
	/* top    20 bits of EHANDLE: serial number
	 * bottom 12 bits of EHANDLE: ent index
	 */
	return handle & (4096 - 1);
}


void cl_con_printf(const char *fmt, ...)
{
	static char buf[16384];
	
	va_list va;
	va_start(va, fmt);
	vsnprintf(buf, sizeof(buf), fmt, va);
	va_end(va);
	
	char *saveptr;
	char *line = strtok_r(buf, "\n", &saveptr);
	while (line != NULL) {
		UTIL_ClientPrintAll(HUD_PRINTCONSOLE, line, NULL, NULL, NULL, NULL);
		line = strtok_r(NULL, "\n", &saveptr);
	}
}


const char *get_string_for_damagebits(uint32_t m_bitsDamageType)
{
	static const char *const lut[] = {
		"CRUSH",
		"BULLET",
		"SLASH",
		"BURN",
		"VEHICLE",
		"FALL",
		"BLAST",
		"CLUB",
		"SHOCK",
		"SONIC",
		"RADIUS_MAX", // DMG_ENERGYBEAM
		"PREVENT_PHYSICS_FORCE",
		"NEVERGIB",
		"ALWAYSGIB",
		"DROWN",
		"PARALYZE",
		"NERVEGAS",
		"NOCLOSEDISTANCEMOD", // DMG_SLOWBURN
		"HALF_FALLOFF", // DMG_RADIATION
		"DROWNRECOVER",
		"CRIT", // DMG_ACID
		"USEDISTANCEMOD", // DMG_SLOWBURN
		"REMOVENORAGDOLL",
		"PHYSGUN",
		"IGNITE", // DMG_PLASMA
		"USE_HITLOCATIONS", // DMG_AIRBOAT
		"DISSOLVE",
		"BLAST_SURFACE",
		"DIRECT",
		"BUCKSHOT",
		"BAD<bit30>",
		"BAD<bit31>",
	};
	
	if (m_bitsDamageType == 0) {
		return "GENERIC";
	}
	
	static char buf[4096];
	buf[0] = '\0';
	bool is_first = true;
	
	for (int i = 0; i < 32; ++i) {
		if ((m_bitsDamageType & (1 << i)) != 0) {
			if (!is_first) {
				strlcat(buf, "|", sizeof(buf));
			}
			strlcat(buf, lut[i], sizeof(buf));
			is_first = false;
		}
	}
	
	return buf;
}

const char *get_string_for_customkill(int m_iCustomKill)
{
	static const char *const lut[] = {
		"???",
		"HEADSHOT",
		"BACKSTAB",
		"BURNING",
		"WRENCH_FIX",
		"MINIGUN",
		"SUICIDE",
		"TAUNT_HADOUKEN",
		"BURNING_FLARE",
		"TAUNT_HIGH_NOON",
		"TAUNT_GRAND_SLAM",
		"PENETRATE_MY_TEAM",
		"PENETRATE_ALL_PLAYERS",
		"TAUNT_FENCING",
		"PENETRATE_HEADSHOT",
		"TAUNT_ARROW_STAB",
		"TELEFRAG",
		"BURNING_ARROW",
		"FLYINGBURN",
		"PUMPKIN_BOMB",
		"DECAPITATION",
		"TAUNT_GRENADE",
		"BASEBALL",
		"CHARGE_IMPACT",
		"TAUNT_BARBARIAN_SWING",
		"AIR_STICKY_BURST",
		"DEFENSIVE_STICKY",
		"PICKAXE",
		"ROCKET_DIRECTHIT",
		"TAUNT_UBERSLICE",
		"PLAYER_SENTRY",
		"STANDARD_STICKY",
		"SHOTGUN_REVENGE_CRIT",
		"TAUNT_ENGINEER_SMASH",
		"BLEEDING",
		"GOLD_WRENCH",
		"CARRIED_BUILDING",
		"COMBO_PUNCH",
		"TAUNT_ENGINEER_ARM",
		"FISH_KILL",
		"TRIGGER_HURT",
		"DECAPITATION_BOSS",
		"STICKBOMB_EXPLOSION",
		"AEGIS_ROUND",
		"FLARE_EXPLOSION",
		"BOOTS_STOMP",
		"PLASMA",
		"PLASMA_CHARGED",
		"PLASMA_GIB",
		"PRACTICE_STICKY",
		"EYEBALL_ROCKET",
		"HEADSHOT_DECAPITATION",
		"TAUNT_ARMAGEDDON",
		"FLARE_PELLET",
		"CLEAVER",
		"CLEAVER_CRIT",
		"SAPPER_RECORDER_DEATH",
		"MERASMUS_PLAYER_BOMB",
		"MERASMUS_GRENADE",
		"MERASMUS_ZAP",
		"MERASMUS_DECAPITATION",
		"CANNONBALL_PUSH",
		"TAUNT_ALLCLASS_GUITAR_RIFF",
	};
	
	if (m_iCustomKill >= sizeof(lut) / sizeof(*lut)) {
		return "???";
	} else {
		return lut[m_iCustomKill];
	}
}

const char *get_string_for_weaponid(int id)
{
	static const char *const lut[] = {
		"NONE",
		"BAT",
		"BAT_WOOD",
		"BOTTLE",
		"FIREAXE",
		"CLUB",
		"CROWBAR",
		"KNIFE",
		"FISTS",
		"SHOVEL",
		"WRENCH",
		"BONESAW",
		"SHOTGUN_PRIMARY",
		"SHOTGUN_SOLDIER",
		"SHOTGUN_HWG",
		"SHOTGUN_PYRO",
		"SCATTERGUN",
		"SNIPERRIFLE",
		"MINIGUN",
		"SMG",
		"SYRINGEGUN_MEDIC",
		"TRANQ",
		"ROCKETLAUNCHER",
		"GRENADELAUNCHER",
		"PIPEBOMBLAUNCHER",
		"FLAMETHROWER",
		"GRENADE_NORMAL",
		"GRENADE_CONCUSSION",
		"GRENADE_NAIL",
		"GRENADE_MIRV",
		"GRENADE_MIRV_DEMOMAN",
		"GRENADE_NAPALM",
		"GRENADE_GAS",
		"GRENADE_EMP",
		"GRENADE_CALTROP",
		"GRENADE_PIPEBOMB",
		"GRENADE_SMOKE_BOMB",
		"GRENADE_HEAL",
		"GRENADE_STUNBALL",
		"GRENADE_JAR",
		"GRENADE_JAR_MILK",
		"PISTOL",
		"PISTOL_SCOUT",
		"REVOLVER",
		"NAILGUN",
		"PDA",
		"PDA_ENGINEER_BUILD",
		"PDA_ENGINEER_DESTROY",
		"PDA_SPY",
		"BUILDER",
		"MEDIGUN",
		"GRENADE_MIRVBOMB",
		"FLAMETHROWER_ROCKET",
		"GRENADE_DEMOMAN",
		"SENTRY_BULLET",
		"SENTRY_ROCKET",
		"DISPENSER",
		"INVIS",
		"FLAREGUN",
		"LUNCHBOX",
		"JAR",
		"COMPOUND_BOW",
		"BUFF_ITEM",
		"PUMPKIN_BOMB",
		"SWORD",
		"DIRECTHIT",
		"LIFELINE",
		"LASER_POINTER",
		"DISPENSER_GUN",
		"SENTRY_REVENGE",
		"JAR_MILK",
		"HANDGUN_SCOUT_PRIMARY",
		"BAT_FISH",
		"CROSSBOW",
		"STICKBOMB",
		"HANDGUN_SCOUT_SEC",
		"SODA_POPPER",
		"SNIPERRIFLE_DECAP",
		"RAYGUN",
		"PARTICLE_CANNON",
		"MECHANICAL_ARM",
		"DRG_POMSON",
		"BAT_GIFTWRAP",
		"GRENADE_ORNAMENT",
		"RAYGUN_REVENGE",
		"PEP_BRAWLER_BLASTER",
		"CLEAVER",
		"GRENADE_CLEAVER",
		"STICKY_BALL_LAUNCHER",
		"GRENADE_STICKY_BALL",
		"SHOTGUN_BUILDING_RESCUE",
		"CANNON",
		"THROWABLE",
		"GRENADE_THROWABLE",
		"PDA_SPY_BUILD",
		"GRENADE_WATERBALLOON",
		"HARVESTER_SAW",
		"SPELLBOOK",
		"SPELLBOOK_PROJECTILE",
		"SNIPERRIFLE_CLASSIC",
		"PARACHUTE",
	};
	
	if (id >= sizeof(lut) / sizeof(*lut)) {
		return "???";
	} else {
		return lut[id];
	}
}

const char *get_string_for_condition(ETFCond cond)
{
	static const char *lut[] = {
		"AIMING",
		"ZOOMED",
		"DISGUISING",
		"DISGUISED",
		"STEALTHED",
		"INVULNERABLE",
		"TELEPORTED",
		"TAUNTING",
		"INVULNERABLE_WEARINGOFF",
		"STEALTHED_BLINK",
		"SELECTED_TO_TELEPORT",
		"CRITBOOSTED",
		"TMPDAMAGEBONUS",
		"FEIGN_DEATH",
		"PHASE",
		"STUNNED",
		"OFFENSEBUFF",
		"SHIELD_CHARGE",
		"DEMO_BUFF",
		"ENERGY_BUFF",
		"RADIUSHEAL",
		"HEALTH_BUFF",
		"BURNING",
		"HEALTH_OVERHEALED",
		"URINE",
		"BLEEDING",
		"DEFENSEBUFF",
		"MAD_MILK",
		"MEGAHEAL",
		"REGENONDAMAGEBUFF",
		"MARKEDFORDEATH",
		"NOHEALINGDAMAGEBUFF",
		"SPEED_BOOST",
		"CRITBOOSTED_PUMPKIN",
		"CRITBOOSTED_USER_BUFF",
		"CRITBOOSTED_DEMO_CHARGE",
		"SODAPOPPER_HYPE",
		"CRITBOOSTED_FIRST_BLOOD",
		"CRITBOOSTED_BONUS_TIME",
		"CRITBOOSTED_CTF_CAPTURE",
		"CRITBOOSTED_ON_KILL",
		"CANNOT_SWITCH_FROM_MELEE",
		"DEFENSEBUFF_NO_CRIT_BLOCK",
		"REPROGRAMMED",
		"CRITBOOSTED_RAGE_BUFF",
		"DEFENSEBUFF_HIGH",
		"SNIPERCHARGE_RAGE_BUFF",
		"DISGUISE_WEARINGOFF",
		"MARKEDFORDEATH_SILENT",
		"DISGUISED_AS_DISPENSER",
		"SAPPED",
		"INVULNERABLE_HIDE_UNLESS_DAMAGED",
		"INVULNERABLE_USER_BUFF",
		"HALLOWEEN_BOMB_HEAD",
		"HALLOWEEN_THRILLER",
		"RADIUSHEAL_ON_DAMAGE",
		"CRITBOOSTED_CARD_EFFECT",
		"INVULNERABLE_CARD_EFFECT",
		"MEDIGUN_UBER_BULLET_RESIST",
		"MEDIGUN_UBER_BLAST_RESIST",
		"MEDIGUN_UBER_FIRE_RESIST",
		"MEDIGUN_SMALL_BULLET_RESIST",
		"MEDIGUN_SMALL_BLAST_RESIST",
		"MEDIGUN_SMALL_FIRE_RESIST",
		"STEALTHED_USER_BUFF",
		"MEDIGUN_DEBUFF",
		"STEALTHED_USER_BUFF_FADING",
		"BULLET_IMMUNE",
		"BLAST_IMMUNE",
		"FIRE_IMMUNE",
		"PREVENT_DEATH",
		"MVM_BOT_STUN_RADIOWAVE",
		"HALLOWEEN_SPEED_BOOST",
		"HALLOWEEN_QUICK_HEAL",
		"HALLOWEEN_GIANT",
		"HALLOWEEN_TINY",
		"HALLOWEEN_IN_HELL",
		"HALLOWEEN_GHOST_MODE",
		"MINICRITBOOSTED_ON_KILL",
		"OBSCURED_SMOKE",
		"PARACHUTE_DEPLOYED",
		"BLASTJUMPING",
		"HALLOWEEN_KART",
		"HALLOWEEN_KART_DASH",
		"BALLOON_HEAD",
		"MELEE_ONLY",
		"SWIMMING_CURSE",
		"FREEZE_INPUT",
		"HALLOWEEN_KART_CAGE",
		"DONOTUSE_0",
		"RUNE_STRENGTH",
		"RUNE_HASTE",
		"RUNE_REGEN",
		"RUNE_RESIST",
		"RUNE_VAMPIRE",
		"RUNE_WARLOCK",
		"RUNE_PRECISION",
		"RUNE_AGILITY",
		"GRAPPLINGHOOK",
		"GRAPPLINGHOOK_SAFEFALL",
		"GRAPPLINGHOOK_LATCHED",
		"GRAPPLINGHOOK_BLEEDING",
		"AFTERBURN_IMMUNE",
		"RUNE_KNOCKOUT",
		"RUNE_IMBALANCE",
		"CRITBOOSTED_RUNE_TEMP",
		"PASSTIME_INTERCEPTION",
		"SWIMMING_NO_EFFECTS",
		"PURGATORY",
		"RUNE_KING",
		"RUNE_PLAGUE",
		"RUNE_SUPERNOVA",
		"PLAGUE",
		"KING_BUFFED",
		"TEAM_GLOWS",
		"KNOCKED_INTO_AIR",
	};
	
	if (cond >= sizeof(lut) / sizeof(*lut)) {
		return "???";
	} else {
		return lut[cond];
	}
}


void *__dynamic_cast_NULL_safe(const void *__src_ptr,
	const void *__src_type,
	const void *__dst_type,
	ptrdiff_t __src2dst)
{
	if (__src_ptr == NULL) {
		return NULL;
	}
	
	return __dynamic_cast(__src_ptr, __src_type, __dst_type, __src2dst);
}
