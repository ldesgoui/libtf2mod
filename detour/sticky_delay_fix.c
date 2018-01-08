#include "all.h"


DETOUR(sticky_delay_fix);
/*
*/

static void (*trampoline_CTFWeaponBase_ItemBusyFrame)(void *);

static void detour_CTFWeaponBase_ItemBusyFrame(void *this){
	trampoline_CTFWeaponBase_ItemBusyFrame(this);

	CBasePlayer *pOwner = CBaseCombatWeapon_GetOwner(this);
	if (pOwner && *prop_CBasePlayer_m_nButtons(pOwner) & IN_ATTACK2) {
		CTFPlayer_DoClassSpecialSkill(pOwner);
	}
}


DETOUR_SETUP
{
	DETOUR_CREATE(CTFWeaponBase_ItemBusyFrame);
	
	return true;
}
