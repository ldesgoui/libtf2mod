#ifndef _LIBTF2MOD_SYMBOLS_H
#define _LIBTF2MOD_SYMBOLS_H


#ifdef _LIBTF2MOD_SYMBOLS_C
#define extern
#endif


void symbols_init(void);


/* RTTI */

extern void *typeinfo_for_CBaseEntity;
extern void *typeinfo_for_CBaseAnimating;
extern void *typeinfo_for_CBasePlayer;
extern void *typeinfo_for_CTFPlayer;
extern void *typeinfo_for_CTFBot;
extern void *typeinfo_for_NextBotPlayer_CTFPlayer;
extern void *typeinfo_for_CBaseObject;
extern void *typeinfo_for_CTFWeaponBase;
extern void *typeinfo_for_CTFWeaponBaseGun;
extern void *typeinfo_for_CWeaponMedigun;
extern void *typeinfo_for_CTFMinigun;
extern void *typeinfo_for_CTFCrossbow;
extern void *typeinfo_for_CTFTankBoss;
extern void *typeinfo_for_INextBot;


/* strings */

extern char const *((*g_aAmmoNames)[]);           // TF_AMMO_*
extern char const *((*g_aWeaponNames)[]);         // TF_WEAPON_*
extern char const *((*g_szSpecialDamageNames)[]); // TF_DMG_CUSTOM_*
extern char const *((*taunt_attack_name)[]);      // TANTATK_*
extern char const *((*g_szProjectileNames)[]);    // projectile_*

extern char const *((*g_aConditionNames)[]); // TF_COND_*

extern char const *((*g_szWeaponTypeSubstrings)[]); // primary/melee/etc
extern char const *((*g_szLoadoutStrings)[]);       // loadout slots
extern char const *((*g_szQualityStrings)[]);       // item qualities

extern char const *((*g_aClassNames)[]);                    // TF_CLASS_*
extern char const *((*g_aRawPlayerClassNames)[]);           // heavyweapons etc
extern char const *((*g_aRawPlayerClassNamesShort)[]);      // heavy etc
extern char const *((*g_aPlayerClassNames_NonLocalized)[]); // capitalized

extern char const *((*g_pszMPConcepts)[]); // TLK_*

extern char const *((*g_aCTFEventNames)[]); // TF_FLAGEVENT_*

extern char const (*g_szBotModels)[10][260];         // models: non-giants
extern char const (*g_szBotBossModels)[10][260];     // models: giants
extern char const **g_szBotBossSentryBusterModel;    // models: sentry buster
extern char const (*g_szPlayerRobotModels)[10][260]; // models: obsolete

extern char const *((*s_TankModel)[]);     // models: tank
extern char const *((*s_TankModelRome)[]); // models: tank (romevision)

extern char const (*g_szRomePromoItems_Hat)[10][260];  // models: romevision hats
extern char const (*g_szRomePromoItems_Misc)[10][260]; // models: romevision miscs


/* globals */

extern CVEngineServer **engine;

extern CGlobalVars **gpGlobals;

extern CGlobalEntityList *gEntList;

extern CEngineTrace **enginetrace;

extern CGameEventManager **gameeventmanager;

extern CTFGameRules **g_pGameRules;

extern CTFGameStats *CTF_GameStats;

extern CTFObjectiveResource **g_pObjectiveResource;

extern ConVar *CONVAR_mp_restartgame;


/* functions: global */

extern ServerClass* (*SV_FindServerClass)(char const*);

extern int (*ENTINDEX)(CBaseEntity*);

extern unknown_t (*UserMessageBegin)(IRecipientFilter*, char const*);
extern unknown_t (*MessageEnd)(void);
extern unknown_t (*MessageWriteAngle)(float);
extern unknown_t (*MessageWriteAngles)(QAngle const*);
extern unknown_t (*MessageWriteBits)(void const*, int);
extern unknown_t (*MessageWriteBool)(bool);
extern unknown_t (*MessageWriteByte)(int);
extern unknown_t (*MessageWriteChar)(int);
extern unknown_t (*MessageWriteCoord)(float);
extern unknown_t (*MessageWriteEHandle)(CBaseEntity*);
extern unknown_t (*MessageWriteEntity)(int);
extern unknown_t (*MessageWriteFloat)(float);
extern unknown_t (*MessageWriteLong)(int);
extern unknown_t (*MessageWriteSBitLong)(int, int);
extern unknown_t (*MessageWriteShort)(int);
extern unknown_t (*MessageWriteString)(char const*);
extern unknown_t (*MessageWriteUBitLong)(unsigned int, int);
extern unknown_t (*MessageWriteVec3Coord)(Vector const*);
extern unknown_t (*MessageWriteVec3Normal)(Vector const*);
extern unknown_t (*MessageWriteWord)(int);

extern CBaseEntity* (*CreateEntityByName)(char const*, int);

extern void (*ClientPrint)(CBasePlayer*, int, char const*, char const*, char const*, char const*, char const*);
extern void (*UTIL_ClientPrintAll)(int, char const*, char const*, char const*, char const*, char const*);
extern void (*UTIL_ClientPrintFilter)(IRecipientFilter*, int, char const*, char const*, char const*, char const*, char const*);
extern int (*UTIL_EntitiesAlongRay)(Ray_t *const, CFlaggedEntitiesEnum*);
extern int (*UTIL_EntitiesInBox)(Vector const*, Vector const*, CFlaggedEntitiesEnum*);
extern int (*UTIL_EntitiesInSphere)(Vector const*, float, CFlaggedEntitiesEnum*);
extern CBaseEntity* (*UTIL_EntityByIndex)(int);
extern int (*UTIL_GetHolidayForString)(char const*);
extern void (*UTIL_HudHintText)(CBaseEntity*, char const*);
extern void (*UTIL_HudMessage)(CBasePlayer*, hudtextparams_t const*, char const*);
extern void (*UTIL_HudMessageAll)(hudtextparams_t const*, char const*);
extern bool (*UTIL_IsHolidayActive)(int);
extern unknown_t (*UTIL_LogPrintf)(char const*, ...);
extern CBasePlayer* (*UTIL_PlayerByIndex)(int);
extern CBasePlayer* (*UTIL_PlayerByName)(char const*);
extern CBasePlayer* (*UTIL_PlayerBySteamID)(CSteamID const*);
extern CBasePlayer* (*UTIL_PlayerByUserId)(int);
extern void (*UTIL_SayText)(char const*, CBasePlayer*);
extern void (*UTIL_SayTextAll)(char const*, CBasePlayer*, bool);
extern void (*UTIL_SayTextFilter)(IRecipientFilter*, CBasePlayer*, bool, char const*, char const*, char const*, char const*, char const*);
extern void (*UTIL_ScreenShake)(Vector const*, float, float, float, float, ShakeCommand_t, bool);
extern void (*UTIL_ShowMessage)(char const*, CBasePlayer*);
extern void (*UTIL_ShowMessageAll)(char const*);

extern int (*V_stricmp)(char const*, char const*);

extern string_t (*AllocPooledString)(char const*);
extern string_t (*AllocPooledString_StaticConstantStringPointer)(char const*);

extern char const* (*TranslateWeaponEntForClass)(char const*, int);

extern bool (*WeaponID_IsSniperRifle)(int);
extern bool (*WeaponID_IsSniperRifleOrBow)(int);

extern unknown_t (*FX_FireBullets)(CTFWeaponBase*, int, Vector const*, QAngle const*, int, int, int, float, float, bool);

extern CTFWearableDemoShield* (*GetEquippedDemoShield)(CTFPlayer*);

extern void (*EconEntity_OnOwnerKillEaterEventNoPartner)(CEconEntity*, CTFPlayer*, int, int);


/* functions: static */

extern datamap_t* (*CBaseEntity_GetDataDescMap)(void);
extern void (*CBaseEntity_PrecacheScriptSound)(char const*);

extern datamap_t* (*CBasePlayer_GetDataDescMap)(void);

extern datamap_t* (*CTFPlayer_GetDataDescMap)(void);

extern datamap_t* (*CBaseObject_GetDataDescMap)(void);

extern datamap_t* (*CObjectSentrygun_GetDataDescMap)(void);

extern void (*CGameRulesProxy_NotifyNetworkStateChanged)(void);

extern CTFMedigunShield* (*CTFMedigunShield_Create)(CTFPlayer*);

extern CEconItemView* (*CTFPlayerSharedUtils_GetEconItemViewByLoadoutSlot)(CTFPlayer*, int, CEconEntity**);

extern unknown_t (*CTFDroppedWeapon_Create)(CTFPlayer*, Vector const*, QAngle const*, char const*, CEconItemView const*);

extern float (*CAttributeManager_AttribHookValue_float)(float, char const*, CBaseEntity const*, CUtlVector*, bool);
extern int (*CAttributeManager_AttribHookValue_int)(int, char const*, CBaseEntity const*, CUtlVector*, bool);


/* functions: member */

extern bool (*CServerGameDLL_DLLInit)(CServerGameDLL* this, void* (*)(char const*, int*), void* (*)(char const*, int*), void* (*)(char const*, int*), CGlobalVars*);
extern void (*CServerGameDLL_PreClientUpdate)(CServerGameDLL* this, bool);
extern float (*CServerGameDLL_GetTickInterval)(CServerGameDLL* this);

extern edict_t* (*CVEngineServer_PEntityOfEntIndex)(CVEngineServer* this, int);

extern void (*ConVar_ctor)(ConVar* this, char const*, char const*, int, char const*);
extern void (*ConVar_ctor_callback)(ConVar* this, char const*, char const*, int, char const*, void (*)(IConVar*, char const*, float));
extern void (*ConVar_SetValue_int)(ConVar* this, int);

extern void (*ConCommand_ctor)(ConCommand* this, char const*, void (*)(CCommand const*), char const*, int, int (*)(char const*, char (*) [64]));

extern IGameEvent* (*CGameEventManager_CreateEvent)(CGameEventManager* this, char const*, bool);
extern bool (*CGameEventManager_FireEvent)(CGameEventManager* this, IGameEvent*, bool);

extern CBaseEntity* (*CGlobalEntityList_FindEntityByName)(CGlobalEntityList* this, CBaseEntity*, char const*, CBaseEntity*, CBaseEntity*, CBaseEntity*, IEntityFindFilter*);

extern void (*CBaseEntity_ApplyAbsVelocityImpulse)(CBaseEntity* this, Vector const*);
extern CBaseEntity* (*CBaseEntity_GetBaseEntity)(CBaseEntity* this);
extern int (*CBaseEntity_GetMaxHealth)(CBaseEntity* this);
extern int (*CBaseEntity_GetTeamNumber)(CBaseEntity* this);
extern bool (*CBaseEntity_IsAlive)(CBaseEntity* this);
extern bool (*CBaseEntity_IsBaseObject)(CBaseEntity* this);
extern bool (*CBaseEntity_IsPlayer)(CBaseEntity* this);
extern int (*CBaseEntity_TakeDamage)(CBaseEntity* this, CTakeDamageInfo const*);

extern void (*CBaseAnimating_DrawServerHitboxes)(CBaseAnimating* this, float, bool);
extern void (*CBaseAnimating_SetModelScale)(CBaseAnimating* this, float, float);

extern void (*CBasePlayer_ChangeTeam)(CBasePlayer* this, int);
extern void (*CBasePlayer_CommitSuicide)(CBasePlayer* this, bool, bool);
extern CBaseEntity* (*CBasePlayer_GiveNamedItem)(CBasePlayer* this, char const*, int);
extern bool (*CBasePlayer_IsBot)(CBasePlayer* this);

extern bool (*CBaseMultiplayerPlayer_SpeakConceptIfAllowed)(CBaseMultiplayerPlayer* this, int, char const*, char*, size_t, IRecipientFilter*);

extern unknown_t (*CTFPlayer_AddBuildResources)(CTFPlayer* this, int);
extern void (*CTFPlayer_ApplyAbsVelocityImpulse)(CTFPlayer* this, Vector const*);
extern bool (*CTFPlayer_CanBeForcedToLaugh)(CTFPlayer* this);
extern int (*CTFPlayer_CanBuild)(CTFPlayer* this, int, int);
extern bool (*CTFPlayer_CanHearAndReadChatFrom)(CTFPlayer* this, CBasePlayer*);
extern bool (*CTFPlayer_CanPickupBuilding)(CTFPlayer* this, CBaseObject*);
extern void (*CTFPlayer_ChangeTeam)(CTFPlayer* this, int);
extern void (*CTFPlayer_CommitSuicide)(CTFPlayer* this, bool, bool);
extern void (*CTFPlayer_CreateRagdollEntity)(CTFPlayer* this, bool, bool, bool, bool, bool, bool, bool, bool, int, bool);
extern void (*CTFPlayer_DeathSound)(CTFPlayer* this, CTakeDamageInfo const*);
extern bool (*CTFPlayer_DoClassSpecialSkill)(CTFPlayer* this);
extern void (*CTFPlayer_Event_Killed)(CTFPlayer* this, CTakeDamageInfo const*);
extern unknown_t (*CTFPlayer_Event_KilledOther)(CTFPlayer* this, CBaseEntity*, CTakeDamageInfo const*);
extern unknown_t (*CTFPlayer_FireBullet)(CTFPlayer* this, CTFWeaponBase*, FireBulletsInfo_t const*, bool, int, int);
extern void (*CTFPlayer_ForceChangeTeam)(CTFPlayer* this, int, bool);
extern CTFWeaponBase* (*CTFPlayer_GetActiveTFWeapon)(CTFPlayer* this);
extern unknown_t (*CTFPlayer_GetClosestCaptureZone)(CTFPlayer* this);
extern int (*CTFPlayer_GetNumObjects)(CTFPlayer* this, int, int);
extern CBaseEntity* (*CTFPlayer_GiveNamedItem)(CTFPlayer* this, char const*, int, CEconItemView const*, bool);
extern void (*CTFPlayer_HandleCommand_JoinClass)(CTFPlayer* this, char const*, bool);
extern bool (*CTFPlayer_IsMiniBoss)(CTFPlayer* this);
extern bool (*CTFPlayer_IsPlayerClass)(CTFPlayer* this, int);
extern unknown_t (*CTFPlayer_OnTakeDamage)(CTFPlayer* this, CTakeDamageInfo const*);
extern unknown_t (*CTFPlayer_OnTakeDamage_Alive)(CTFPlayer* this, CTakeDamageInfo const*);
extern void (*CTFPlayer_Regenerate)(CTFPlayer* this, bool);
extern void (*CTFPlayer_RememberUpgrade)(CTFPlayer* this, int, CEconItemView*, int, int, bool);
extern void (*CTFPlayer_RemoveAmmo)(CTFPlayer* this, int, int);
extern void (*CTFPlayer_RemoveCurrency)(CTFPlayer* this, int);
extern void (*CTFPlayer_RemoveDisguise)(CTFPlayer* this);
extern bool (*CTFPlayer_ShouldDropAmmoPack)(CTFPlayer* this);
extern bool (*CTFPlayer_ShouldGib)(CTFPlayer* this, CTakeDamageInfo const*);
extern unknown_t (*CTFPlayer_SpeakConceptIfAllowed)(CTFPlayer* this, int, char const*, char*, unsigned int, IRecipientFilter*);
extern unknown_t (*CTFPlayer_TFPlayerThink)(CTFPlayer* this);
extern unknown_t (*CTFPlayer_TraceAttack)(CTFPlayer* this, CTakeDamageInfo const*, Vector const*, CGameTrace*, CDmgAccumulator*);
extern bool (*CTFPlayer_TryToPickupBuilding)(CTFPlayer* this);

extern void (*CTFBot_AddItem)(CTFBot* this, char const*);
extern void (*CTFBot_ChangeTeam)(CTFBot* this, int, bool, bool);
extern bool (*CTFBot_EquipRequiredWeapon)(CTFBot* this);
extern bool (*CTFBot_IsAllowedToPickUpFlag)(CTFBot* this);
extern void (*CTFBot_PressFireButton)(CTFBot* this, float);
extern void (*CTFBot_PressAltFireButton)(CTFBot* this, float);
extern void (*CTFBot_PressSpecialFireButton)(CTFBot* this, float);
extern CTFPlayer* (*CTFBot_SelectRandomReachableEnemy)(CTFBot* this);
extern unknown_t (*CTFBot_SetMission)(CTFBot* this, CTFBot_MissionType, bool);
extern bool (*CTFBot_ShouldGib)(CTFBot* this, CTakeDamageInfo const*);

extern CBaseEntity* (*NextBotPlayer_CTFPlayer_GetEntity)(NextBotPlayer_CTFPlayer* this);
extern bool (*NextBotPlayer_CTFPlayer_IsBot)(NextBotPlayer_CTFPlayer* this);
extern void (*NextBotPlayer_CTFPlayer_PressFireButton)(NextBotPlayer_CTFPlayer* this, float);
extern void (*NextBotPlayer_CTFPlayer_ReleaseFireButton)(NextBotPlayer_CTFPlayer* this);
extern void (*NextBotPlayer_CTFPlayer_PressMeleeButton)(NextBotPlayer_CTFPlayer* this, float);
extern void (*NextBotPlayer_CTFPlayer_ReleaseMeleeButton)(NextBotPlayer_CTFPlayer* this);
extern void (*NextBotPlayer_CTFPlayer_PressSpecialFireButton)(NextBotPlayer_CTFPlayer* this, float);
extern void (*NextBotPlayer_CTFPlayer_ReleaseSpecialFireButton)(NextBotPlayer_CTFPlayer* this);
extern void (*NextBotPlayer_CTFPlayer_PressUseButton)(NextBotPlayer_CTFPlayer* this, float);
extern void (*NextBotPlayer_CTFPlayer_ReleaseUseButton)(NextBotPlayer_CTFPlayer* this);
extern void (*NextBotPlayer_CTFPlayer_PressReloadButton)(NextBotPlayer_CTFPlayer* this, float);
extern void (*NextBotPlayer_CTFPlayer_ReleaseReloadButton)(NextBotPlayer_CTFPlayer* this);
extern void (*NextBotPlayer_CTFPlayer_PressForwardButton)(NextBotPlayer_CTFPlayer* this, float);
extern void (*NextBotPlayer_CTFPlayer_ReleaseForwardButton)(NextBotPlayer_CTFPlayer* this);
extern void (*NextBotPlayer_CTFPlayer_PressBackwardButton)(NextBotPlayer_CTFPlayer* this, float);
extern void (*NextBotPlayer_CTFPlayer_ReleaseBackwardButton)(NextBotPlayer_CTFPlayer* this);
extern void (*NextBotPlayer_CTFPlayer_PressLeftButton)(NextBotPlayer_CTFPlayer* this, float);
extern void (*NextBotPlayer_CTFPlayer_ReleaseLeftButton)(NextBotPlayer_CTFPlayer* this);
extern void (*NextBotPlayer_CTFPlayer_PressRightButton)(NextBotPlayer_CTFPlayer* this, float);
extern void (*NextBotPlayer_CTFPlayer_ReleaseRightButton)(NextBotPlayer_CTFPlayer* this);
extern void (*NextBotPlayer_CTFPlayer_PressJumpButton)(NextBotPlayer_CTFPlayer* this, float);
extern void (*NextBotPlayer_CTFPlayer_ReleaseJumpButton)(NextBotPlayer_CTFPlayer* this);
extern void (*NextBotPlayer_CTFPlayer_PressCrouchButton)(NextBotPlayer_CTFPlayer* this, float);
extern void (*NextBotPlayer_CTFPlayer_ReleaseCrouchButton)(NextBotPlayer_CTFPlayer* this);
extern void (*NextBotPlayer_CTFPlayer_PressWalkButton)(NextBotPlayer_CTFPlayer* this, float);
extern void (*NextBotPlayer_CTFPlayer_ReleaseWalkButton)(NextBotPlayer_CTFPlayer* this);
extern void (*NextBotPlayer_CTFPlayer_SetButtonScale)(NextBotPlayer_CTFPlayer* this, float, float);

extern void (*CTFPlayerShared_AddCond)(CTFPlayerShared* this, ETFCond, float, CBaseEntity*);
extern void (*CTFPlayerShared_Burn)(CTFPlayerShared* this, CTFPlayer*, CTFWeaponBase*, float);
extern unknown_t (*CTFPlayerShared_ConditionGameRulesThink)(CTFPlayerShared* this);
extern CTFWeaponBase* (*CTFPlayerShared_GetActiveTFWeapon)(CTFPlayerShared* this);
extern bool (*CTFPlayerShared_HasDemoShieldEquipped)(CTFPlayerShared* this);
extern bool (*CTFPlayerShared_IsAlly)(CTFPlayerShared* this, CBaseEntity*);
extern bool (*CTFPlayerShared_IsControlStunned)(CTFPlayerShared* this);
extern bool (*CTFPlayerShared_IsInvulnerable)(CTFPlayerShared* this);
extern void (*CTFPlayerShared_OnAddBurning)(CTFPlayerShared* this);
extern void (*CTFPlayerShared_OnAddDisguisedAsDispenser)(CTFPlayerShared* this);
extern void (*CTFPlayerShared_OnAddReprogrammed)(CTFPlayerShared* this);
extern void (*CTFPlayerShared_OnAddSpeedBoost)(CTFPlayerShared* this);
extern void (*CTFPlayerShared_OnConditionAdded)(CTFPlayerShared* this, ETFCond);
extern void (*CTFPlayerShared_OnConditionRemoved)(CTFPlayerShared* this, ETFCond);
extern void (*CTFPlayerShared_OnRemoveDisguisedAsDispenser)(CTFPlayerShared* this);
extern void (*CTFPlayerShared_OnRemoveReprogrammed)(CTFPlayerShared* this);
extern void (*CTFPlayerShared_OnRemoveSpeedBoost)(CTFPlayerShared* this);
extern void (*CTFPlayerShared_OnRemoveStunned)(CTFPlayerShared* this);
extern void (*CTFPlayerShared_RemoveCond)(CTFPlayerShared* this, ETFCond, bool);
extern void (*CTFPlayerShared_RadiusCurrencyCollectionCheck)(CTFPlayerShared* this);
extern void (*CTFPlayerShared_StunPlayer)(CTFPlayerShared* this, float, float, int, CTFPlayer*);

extern void (*CTFPlayerClassShared_SetCustomModel)(CTFPlayerClassShared* this, char const*, bool);

extern void (*CTFBaseBoss_ResolvePlayerCollision)(CTFBaseBoss* this, CTFPlayer*);

extern void (*CTFTankBoss_ModifyDamage)(CTFTankBoss* this, CTakeDamageInfo*);
extern unknown_t (*CTFTankBoss_OnTakeDamage_Alive)(CTFTankBoss* this, CTakeDamageInfo const*);
extern void (*CTFTankBoss_Spawn)(CTFTankBoss* this);
extern void (*CTFTankBoss_TankBossThink)(CTFTankBoss* this);

extern CEconItemAttributeDefinition* (*CEconItemSchema_GetAttributeDefinitionByName)(CEconItemSchema* this, char const*);
extern CEconItemDefinition* (*CEconItemSchema_GetItemDefinitionByName)(CEconItemSchema* this, char const*);

extern int (*CEconItemView_GetItemDefIndex)(CEconItemView* this);

extern void (*CSchemaFieldHandle_CEconItemDefinition_ctor)(CSchemaFieldHandle_CEconItemDefinition* this, char const*);

extern unknown_t (*CItemGeneration_GenerateRandomItem)(CItemGeneration* this, CItemSelectionCriteria*, Vector const*, QAngle const*);
extern unknown_t (*CItemGeneration_SpawnItem)(CItemGeneration* this, int, Vector const*, QAngle const*, int, int, char const*);

extern void (*CBaseCombatWeapon_SetWeaponVisible)(CBaseCombatWeapon* this, bool);
extern CBasePlayer *(*CBaseCombatWeapon_GetOwner)(CBaseCombatWeapon* this);

extern bool (*CTFWeaponBase_AreRandomCritsEnabled)(CTFWeaponBase* this);
extern bool (*CTFWeaponBase_CalcIsAttackCritical)(CTFWeaponBase* this);
extern bool (*CTFWeaponBase_CalcIsAttackCriticalHelper)(CTFWeaponBase* this);
extern bool (*CTFWeaponBase_CalcIsAttackCriticalHelperNoCrits)(CTFWeaponBase* this);
extern bool (*CTFWeaponBase_CanBeCritBoosted)(CTFWeaponBase* this);
extern bool (*CTFWeaponBase_CanFireRandomCriticalShot)(CTFWeaponBase* this, float);
extern int (*CTFWeaponBase_GetWeaponID)(CTFWeaponBase* this);
extern void (*CTFWeaponBase_StartEffectBarRegen)(CTFWeaponBase* this);
extern void (*CTFWeaponBase_ItemBusyFrame)(CTFWeaponBase* this);

extern int (*CTFWeaponBaseGun_GetWeaponProjectileType)(CTFWeaponBaseGun* this);
extern void (*CTFWeaponBaseGun_PrimaryAttack)(CTFWeaponBaseGun* this);

extern void (*CWeaponMedigun_CreateMedigunShield)(CWeaponMedigun* this);
extern float (*CWeaponMedigun_GetTargetRange)(CWeaponMedigun* this);
extern bool (*CWeaponMedigun_IsAttachedToBuilding)(CWeaponMedigun* this);

extern void (*CTFRocketLauncher_Precache)(CTFRocketLauncher* this);

extern void (*CTFSniperRifle_DestroySniperDot)(CTFSniperRifle* this);
extern void (*CTFSniperRifle_ExplosiveHeadShot)(CTFSniperRifle* this, CTFPlayer*, CTFPlayer*);
extern void (*CTFSniperRifle_ItemPostFrame)(CTFSniperRifle* this);
extern void (*CTFSniperRifleClassic_ItemPostFrame)(CTFSniperRifleClassic* this);
extern float (*CTFSniperRifleDecap_SniperRifleChargeRateMod)(CTFSniperRifleDecap* this);

extern void (*CTFKnife_DisguiseOnKill)(CTFKnife* this);
extern void (*CTFKnife_PrimaryAttack)(CTFKnife* this);

extern unknown_t (*CTFWearableDemoShield_EndSpecialAction)(CTFWearableDemoShield* this, CTFPlayer*);

extern unknown_t (*CTFStickBomb_Smack)(CTFStickBomb* this);

extern unknown_t (*CTFSword_OnDecapitation)(CTFSword* this, CTFPlayer*);

extern bool (*CTFWeaponBuilder_StartBuilding)(CTFWeaponBuilder* this);

extern unknown_t (*CTFBaseRocket_Explode)(CTFBaseRocket* this, CGameTrace*, CBaseEntity*);

extern unknown_t (*CTFWeaponBaseGrenadeProj_Explode)(CTFWeaponBaseGrenadeProj* this, CGameTrace*, int);

extern unknown_t (*CTFProjectile_Arrow_StrikeTarget)(CTFProjectile_Arrow* this, mstudiobbox_t*, CBaseEntity*);
extern unknown_t (*CTFProjectile_Flare_Explode)(CTFProjectile_Flare* this, CGameTrace*, CBaseEntity*);

extern void (*CBaseObject_DoQuickBuild)(CBaseObject* this);
extern CBaseEntity* (*CBaseObject_GetBuilder)(CBaseObject* this);
extern int (*CBaseObject_GetMaxHealthForCurrentLevel)(CBaseObject* this);
extern float (*CBaseObject_GetReversesBuildingConstructionSpeed)(CBaseObject* this);
extern CObjectSapper* (*CBaseObject_GetSapper)(CBaseObject* this);
extern int (*CBaseObject_GetType)(CBaseObject* this);
extern void (*CBaseObject_MakeDisposableBuilding)(CBaseObject* this, CTFPlayer*);
extern unknown_t (*CBaseObject_OnTakeDamage)(CBaseObject* this, CTakeDamageInfo const*);
extern void (*CBaseObject_SetHealth)(CBaseObject* this, float);
extern void (*CBaseObject_SetSolidToPlayers)(CBaseObject* this, OBJSOLIDTYPE, bool);
extern bool (*CBaseObject_ShouldBeMiniBuilding)(CBaseObject* this, CTFPlayer*);
extern bool (*CBaseObject_ShouldCollide)(CBaseObject* this, int, int);
extern void (*CBaseObject_StopPlacement)(CBaseObject* this);

extern void (*CObjectDispenser_MakeMiniBuilding)(CObjectDispenser* this, CTFPlayer*);
extern bool (*CObjectDispenser_ShouldBeMiniBuilding)(CObjectDispenser* this, CTFPlayer*);
extern void (*CObjectDispenser_StartPlacement)(CObjectDispenser* this, CTFPlayer*);

extern int (*CObjectSentrygun_GetBaseTurnRate)(CObjectSentrygun* this);
extern int (*CObjectSentrygun_GetMaxHealthForCurrentLevel)(CObjectSentrygun* this);
extern void (*CObjectSentrygun_MakeDisposableBuilding)(CObjectSentrygun* this, CTFPlayer*);
extern bool (*CObjectSentrygun_MoveTurret)(CObjectSentrygun* this);
extern void (*CObjectSentrygun_SentryRotate)(CObjectSentrygun* this);
extern void (*CObjectSentrygun_SentryThink)(CObjectSentrygun* this);
extern void (*CObjectSentrygun_Spawn)(CObjectSentrygun* this);
extern bool (*CObjectSentrygun_StartBuilding)(CObjectSentrygun* this, CBaseEntity*);

extern void (*CObjectTeleporter_FinishedBuilding)(CObjectTeleporter* this);
extern void (*CObjectTeleporter_Spawn)(CObjectTeleporter* this);
extern bool (*CObjectTeleporter_StartBuilding)(CObjectTeleporter* this, CBaseEntity*);

extern void (*CObjectSapper_ApplyRoboSapper)(CObjectSapper* this, CTFPlayer*, float, int);
extern bool (*CObjectSapper_ApplyRoboSapperEffects)(CObjectSapper* this, CTFPlayer*, float);
extern bool (*CObjectSapper_IsValidRoboSapperTarget)(CObjectSapper* this, CTFPlayer*);
extern void (*CObjectSapper_Spawn)(CObjectSapper* this);

extern void (*CTFPowerupBottle_ReapplyProvision)(CTFPowerupBottle* this);

extern void (*CTFGameRules_Activate)(CTFGameRules* this);
extern void (*CTFGameRules_BetweenRounds_Think)(CTFGameRules* this);
extern bool (*CTFGameRules_CanUpgradeWithAttrib)(CTFGameRules* this, CTFPlayer*, int, unsigned short, CMannVsMachineUpgrades*);
extern unknown_t (*CTFGameRules_DistributeCurrencyAmount)(CTFGameRules* this, int, CTFPlayer*, bool, bool, bool);
extern unknown_t (*CTFGameRules_FireGameEvent)(CTFGameRules* this, IGameEvent*);
extern bool (*CTFGameRules_GameModeUsesUpgrades)(CTFGameRules* this);
extern int (*CTFGameRules_GetBonusRoundTime)(CTFGameRules* this, bool);
extern int (*CTFGameRules_GetCostForUpgrade)(CTFGameRules* this, CMannVsMachineUpgrades*, int, int, CTFPlayer*);
extern int (*CTFGameRules_GetUpgradeTier)(CTFGameRules* this, int);
extern bool (*CTFGameRules_IsInTraining)(CTFGameRules* this);
extern bool (*CTFGameRules_IsPVEModeActive)(CTFGameRules* this);
extern bool (*CTFGameRules_IsPVEModeControlled)(CTFGameRules* this, CBaseEntity*);
extern bool (*CTFGameRules_IsUpgradeTierEnabled)(CTFGameRules* this, CTFPlayer*, int, int);
extern bool (*CTFGameRules_PlayerReadyStatus_HaveMinPlayersToEnable)(CTFGameRules* this);
extern bool (*CTFGameRules_PlayerReadyStatus_ShouldStartCountdown)(CTFGameRules* this);
extern void (*CTFGameRules_PlayerReadyStatus_UpdatePlayerState)(CTFGameRules* this, CTFPlayer*, bool);
extern void (*CTFGameRules_PushAllPlayersAway)(CTFGameRules* this, Vector const*, float, float, int, CUtlVector*);
extern bool (*CTFGameRules_UsePlayerReadyStatusMode)(CTFGameRules* this);

extern void (*CTeamplayRoundBasedRules_CheckReadyRestart)(CTeamplayRoundBasedRules* this);

extern void (*CTFGameRulesProxy_Activate)(CTFGameRulesProxy* this);

extern unknown_t (*CTFGameStats_IncrementStat)(CTFGameStats* this, CTFPlayer*, TFStatType_t, int);
extern unknown_t (*CTFGameStats_ResetPlayerStats)(CTFGameStats* this, CTFPlayer*);

extern unknown_t (*CMannVsMachineStats_ResetPlayerEvents)(CMannVsMachineStats* this, CTFPlayer*);
extern unknown_t (*CMannVsMachineStats_ResetStats)(CMannVsMachineStats* this);

extern unknown_t (*CTFObjectiveResource_AddMannVsMachineWaveClassFlags)(CTFObjectiveResource* this, int, unsigned int);
extern unknown_t (*CTFObjectiveResource_ClearMannVsMachineWaveClassFlags)(CTFObjectiveResource* this);
extern unknown_t (*CTFObjectiveResource_DecrementMannVsMachineWaveClassCount)(CTFObjectiveResource* this, string_t, unsigned int);
extern unknown_t (*CTFObjectiveResource_DecrementTeleporterCount)(CTFObjectiveResource* this);
extern int (*CTFObjectiveResource_GetMannVsMachineWaveClassCount)(CTFObjectiveResource* this, int);
extern unknown_t (*CTFObjectiveResource_IncrementMannVsMachineWaveClassCount)(CTFObjectiveResource* this, string_t, unsigned int);
extern unknown_t (*CTFObjectiveResource_IncrementTeleporterCount)(CTFObjectiveResource* this);
extern unknown_t (*CTFObjectiveResource_SetMannVsMachineWaveClassActive)(CTFObjectiveResource* this, string_t, bool);
extern unknown_t (*CTFObjectiveResource_SetMannVsMachineWaveClassCount)(CTFObjectiveResource* this, int, int);
extern unknown_t (*CTFObjectiveResource_SetMannVsMachineWaveClassName)(CTFObjectiveResource* this, int, string_t);

extern bool (*CPopulationManager_IsInEndlessWaves)(CPopulationManager* this);
extern bool (*CPopulationManager_IsValidMvMMap)(CPopulationManager* this, char const*);
extern void (*CPopulationManager_JumpToWave)(CPopulationManager* this, unsigned int, float);

extern unknown_t (*CMissionPopulator_UpdateMission)(CMissionPopulator* this, CTFBot_MissionType);
extern unknown_t (*CMissionPopulator_UpdateMissionDestroySentries)(CMissionPopulator* this);

extern void (*CWaveSpawnPopulator_ForceFinish)(CWaveSpawnPopulator* this);

extern void (*CWave_ForceFinish)(CWave* this);

extern int (*CTFBotSpawner_Spawn)(CTFBotSpawner* this, Vector const*, CUtlVector*);

extern int (*CSquadSpawner_Spawn)(CSquadSpawner* this, Vector const*, CUtlVector*);

extern unknown_t (*CUpgrades_ApplyUpgradeAttributeBlock)(CUpgrades* this, UpgradeAttribBlock_t, int, CTFPlayer*, bool);
extern unsigned short (*CUpgrades_ApplyUpgradeToItem)(CUpgrades* this, CTFPlayer*, CEconItemView*, int, int, bool, bool);
extern unknown_t (*CUpgrades_EndTouch)(CUpgrades* this, CBaseEntity*);
extern unknown_t (*CUpgrades_FireGameEvent)(CUpgrades* this, IGameEvent*);
extern unknown_t (*CUpgrades_GetUpgradeAttributeName)(CUpgrades* this, int);
extern unknown_t (*CUpgrades_GrantOrRemoveAllUpgrades)(CUpgrades* this, CTFPlayer*, bool, bool);
extern unknown_t (*CUpgrades_InputDisable)(CUpgrades* this, inputdata_t*);
extern unknown_t (*CUpgrades_InputEnable)(CUpgrades* this, inputdata_t*);
extern unknown_t (*CUpgrades_InputReset)(CUpgrades* this, inputdata_t*);
extern void (*CUpgrades_NotifyItemOnUpgrade)(CUpgrades* this, CTFPlayer*, unsigned short, bool);
extern void (*CUpgrades_PlayerPurchasingUpgrade)(CUpgrades* this, CTFPlayer*, int, int, bool, bool, bool);
extern void (*CUpgrades_ReportUpgrade)(CUpgrades* this, CTFPlayer*, int, int, int, int, bool, bool, bool);
extern unknown_t (*CUpgrades_RestoreItemAttributeToBaseValue)(CUpgrades* this, CEconItemAttributeDefinition*, CEconItemView*);
extern unknown_t (*CUpgrades_RestorePlayerAttributeToBaseValue)(CUpgrades* this, CEconItemAttributeDefinition*, CTFPlayer*);
extern unknown_t (*CUpgrades_UpgradeTouch)(CUpgrades* this, CBaseEntity*);

extern unknown_t (*CMannVsMachineUpgradeManager_GetAttributeIndexByName)(CMannVsMachineUpgradeManager* this, char const*);

extern unknown_t (*CTFBotLocomotion_Jump)(CTFBotLocomotion* this);
extern float (*CTFBotLocomotion_GetRunSpeed)(CTFBotLocomotion* this);

extern char const* (*CTFBotMainAction_GetName)(CTFBotMainAction* this);
extern nextbot_event_response_t (*CTFBotMainAction_OnContact)(CTFBotMainAction* this, CTFBot*, CBaseEntity*, CGameTrace*);
extern nextbot_event_response_t (*CTFBotMainAction_Update)(CTFBotMainAction* this, CTFBot*, float);

extern unknown_t (*CTFBotScenarioMonitor_DesiredScenarioAndClassAction)(CTFBotScenarioMonitor* this, CTFBot*);

extern nextbot_event_response_t (*CTFBotTacticalMonitor_Update)(CTFBotTacticalMonitor* this, CTFBot*, float);

extern bool (*CTFBotMedicHeal_IsReadyToDeployUber)(CTFBotMedicHeal* this, CWeaponMedigun const*);
extern nextbot_event_response_t (*CTFBotMedicHeal_Update)(CTFBotMedicHeal* this, CTFBot*, float);

extern nextbot_event_response_t (*CTFBotMvMEngineerIdle_Update)(CTFBotMvMEngineerIdle* this, CTFBot*, float);
extern nextbot_event_response_t (*CTFBotMvMEngineerBuildSentryGun_Update)(CTFBotMvMEngineerBuildSentryGun* this, CTFBot*, float);
extern nextbot_event_response_t (*CTFBotMvMEngineerBuildTeleportExit_Update)(CTFBotMvMEngineerBuildTeleportExit* this, CTFBot*, float);

extern void (*CTFBotMissionSuicideBomber_Detonate)(CTFBotMissionSuicideBomber* this, CTFBot*);
extern nextbot_event_response_t (*CTFBotMissionSuicideBomber_OnStart)(CTFBotMissionSuicideBomber* this, CTFBot*, Action_CTFBot*);

extern INextBot* (*INextBotComponent_GetBot)(INextBotComponent* this);

extern void (*IBody_AimHeadTowards_ent)(IBody* this, CBaseEntity*, IBody_LookAtPriorityType, float, INextBotReply*, char const*);
extern void (*IBody_AimHeadTowards_vec)(IBody* this, Vector const*, IBody_LookAtPriorityType, float, INextBotReply*, char const*);

extern void (*PlayerBody_AimHeadTowards_ent)(PlayerBody* this, CBaseEntity*, IBody_LookAtPriorityType, float, INextBotReply*, char const*);
extern void (*PlayerBody_AimHeadTowards_vec)(PlayerBody* this, Vector const*, IBody_LookAtPriorityType, float, INextBotReply*, char const*);

extern unknown_t (*CTFReviveMarker_AddMarkerHealth)(CTFReviveMarker* this, float);

extern bool (*CTFPowerup_ValidTouch)(CTFPowerup* this);

extern unknown_t (*CCurrencyPack_ComeToRest)(CCurrencyPack* this);
extern unknown_t (*CCurrencyPack_MyTouch)(CCurrencyPack* this, CBasePlayer*);

extern unknown_t (*CFuncNavCost_HasTag)(CFuncNavCost* this, char const*);
extern unknown_t (*CFuncNavCost_IsApplicableTo)(CFuncNavCost* this, CBaseCombatCharacter*);

extern unknown_t (*Action_CTFBot_OnContact)(Action_CTFBot* this, CBaseEntity*, CGameTrace*);

extern unknown_t (*CTraceFilterObject_ShouldHitEntity)(CTraceFilterObject* this, IHandleEntity*, int);

extern void (*CSoundEmitterSystemBase_AddSoundOverrides)(CSoundEmitterSystemBase* this, char const*, bool);

extern int (*CEngineTrace_GetPointContents_Collideable)(CEngineTrace* this, ICollideable*, Vector const*);
extern void (*CEngineTrace_ClipRayToEntity)(CGameTrace* this, Ray_t const*, unsigned int, IHandleEntity*, CGameTrace*);
extern void (*CEngineTrace_TraceRay)(CEngineTrace* this, Ray_t const*, unsigned int, ITraceFilter*, CGameTrace*);

extern bool (*CBulletPenetrateEnum_EnumEntity)(CBulletPenetrateEnum* this, IHandleEntity*);

extern float (*CAttributeManager_ApplyAttributeFloatWrapper)(CAttributeManager* this, float, CBaseEntity*, string_t, CUtlVector*);

extern void (*CAttributeList_SetRuntimeAttributeValue)(CAttributeList* this, CEconItemAttributeDefinition const*, float);

extern void (*CCollisionProperty_SetSolid)(CCollisionProperty* this, SolidType_t);


#undef extern


#endif
