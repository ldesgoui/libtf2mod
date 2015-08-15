#include "all.h"


DETOUR(robot_gib_improvements);
/* make non-giant robots able to gib, but only if they have a reasonable number
 * of gib models available */


static bool (*trampoline_CTFBot_ShouldGib)(CTFBot* this);

static uintptr_t off_CTFPlayer_m_flModelScale;


static bool detour_CTFBot_ShouldGib(CTFBot* this, CTakeDamageInfo const* info)
{
	/* only meddle with the gibbing logic for MvM robots on BLU team */
	if (CTFGameRules_IsPVEModeActive(*g_pGameRules) &&
		CBaseEntity_GetTeamNumber(this) == TFTEAM_BLUE) {
		
		bool is_miniboss = CTFPlayer_IsMiniBoss(this);
		float *m_flModelScale = (float *)((uintptr_t)this +
			off_CTFPlayer_m_flModelScale);
		
		//pr_info("CTFBot::ShouldGib\n");
		//pr_debug(
		//	"  IsMiniBoss:     %s\n"
		//	"  m_flModelScale: %.2f\n",
		//	(is_miniboss ? "YES" : "NO"),
		//	*m_flModelScale);
		
		
		/* for giants, always gib, because their ragdolls don't scale up and
		 * they just look silly */
		if (is_miniboss || *m_flModelScale > 1.0f) {
			//pr_debug("  is a giant; will ALWAYS gib\n");
			return true;
		}
		
		
		bool is_engie  = CTFPlayer_IsPlayerClass(this, TFCLASS_ENGINEER);
		bool is_medic  = CTFPlayer_IsPlayerClass(this, TFCLASS_MEDIC);
		bool is_sniper = CTFPlayer_IsPlayerClass(this, TFCLASS_SNIPER);
		bool is_spy    = CTFPlayer_IsPlayerClass(this, TFCLASS_SPY);
		
		/* engineer bots have 0 gibs, and medic/sniper/spy have only 1 gib
		 * (head only); so don't let these classes gib at all */
		if (is_engie || is_medic || is_sniper || is_spy) {
			//pr_debug("  is a %s robot; will NEVER gib\n",
			//	is_engie  ? "engie"  :
			//	is_medic  ? "medic"  :
			//	is_sniper ? "sniper" : "spy");
			return false;
		}
		
		
		//pr_debug("  is a common robot; will use regular gibbing logic\n");
		/* fall through */
	}
	
	
	/* defer to the usual gibbing logic in CTFPlayer::ShouldGib */
	return CTFPlayer_ShouldGib(this, info);
}


DETOUR_SETUP
{
	if (off_CTFPlayer_m_flModelScale == 0) {
		off_CTFPlayer_m_flModelScale = sendprop_offset(
			"CTFPlayer", "m_flModelScale");
		
		if (off_CTFPlayer_m_flModelScale == 0) {
			pr_warn("%s: off_CTFPlayer_m_flModelScale = 0\n", __func__);
			return;
		}
	}
	
	
	DETOUR_CREATE(CTFBot_ShouldGib);
}
