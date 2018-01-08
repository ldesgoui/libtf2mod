#define _LIBTF2MOD_SYMBOLS_C
#include "all.h"


#define SYMBOL_OBJ(_var, _mangled) \
	symtab_obj_absolute(_mangled, (void **)&_var, NULL)
#define SYMBOL_FUNC(_var, _mangled) \
	symtab_func_absolute(_mangled, (void **)&_var, NULL)

#define SYMBOL_OBJ_LIB(_lib, _var, _mangled) \
	symtab_obj_absolute_onelib(lib_find(_lib), _mangled, (void **)&_var, NULL)
#define SYMBOL_FUNC_LIB(_lib, _var, _mangled) \
	symtab_func_absolute_onelib(lib_find(_lib), _mangled, (void **)&_var, NULL)


void symbols_init(void)
{
	/* RTTI */
	
	SYMBOL_OBJ(typeinfo_for_CBaseEntity,
		"_ZTI11CBaseEntity");
	SYMBOL_OBJ(typeinfo_for_CBaseAnimating,
		"_ZTI14CBaseAnimating");
	SYMBOL_OBJ(typeinfo_for_CBasePlayer,
		"_ZTI11CBasePlayer");
	SYMBOL_OBJ(typeinfo_for_CTFPlayer,
		"_ZTI9CTFPlayer");
	SYMBOL_OBJ(typeinfo_for_CTFBot,
		"_ZTI6CTFBot");
	SYMBOL_OBJ(typeinfo_for_NextBotPlayer_CTFPlayer,
		"_ZTI13NextBotPlayerI9CTFPlayerE");
	SYMBOL_OBJ(typeinfo_for_CBaseObject,
		"_ZTI11CBaseObject");
	SYMBOL_OBJ(typeinfo_for_CTFWeaponBase,
		"_ZTI13CTFWeaponBase");
	SYMBOL_OBJ(typeinfo_for_CTFWeaponBaseGun,
		"_ZTV16CTFWeaponBaseGun");
	SYMBOL_OBJ(typeinfo_for_CWeaponMedigun,
		"_ZTI14CWeaponMedigun");
	SYMBOL_OBJ(typeinfo_for_CTFMinigun,
		"_ZTV10CTFMinigun");
	SYMBOL_OBJ(typeinfo_for_CTFCrossbow,
		"_ZTI11CTFCrossbow");
	SYMBOL_OBJ(typeinfo_for_CTFTankBoss,
		"_ZTI11CTFTankBoss");
	SYMBOL_OBJ(typeinfo_for_INextBot,
		"_ZTI8INextBot");
	
	
	/* strings */
	
	SYMBOL_OBJ(g_aAmmoNames,
		"g_aAmmoNames");
	SYMBOL_OBJ(g_aWeaponNames,
		"g_aWeaponNames");
	SYMBOL_OBJ(g_szSpecialDamageNames,
		"g_szSpecialDamageNames");
	SYMBOL_OBJ(taunt_attack_name,
		"_ZL17taunt_attack_name");
	SYMBOL_OBJ(g_szProjectileNames,
		"g_szProjectileNames");

	SYMBOL_OBJ(g_aConditionNames,
		"_ZL17g_aConditionNames");

	SYMBOL_OBJ(g_szWeaponTypeSubstrings,
		"g_szWeaponTypeSubstrings");
	SYMBOL_OBJ(g_szLoadoutStrings,
		"g_szLoadoutStrings");
	SYMBOL_OBJ(g_szQualityStrings,
		"g_szQualityStrings");

	SYMBOL_OBJ(g_aClassNames,
		"g_aClassNames");
	SYMBOL_OBJ(g_aRawPlayerClassNames,
		"g_aRawPlayerClassNames");
	SYMBOL_OBJ(g_aRawPlayerClassNamesShort,
		"g_aRawPlayerClassNamesShort");
	SYMBOL_OBJ(g_aPlayerClassNames_NonLocalized,
		"g_aPlayerClassNames_NonLocalized");

	SYMBOL_OBJ(g_pszMPConcepts,
		"g_pszMPConcepts");

	SYMBOL_OBJ(g_aCTFEventNames,
		"g_aCTFEventNames");

	SYMBOL_OBJ(g_szBotModels,
		"g_szBotModels");
	SYMBOL_OBJ(g_szBotBossModels,
		"g_szBotBossModels");
	SYMBOL_OBJ(g_szBotBossSentryBusterModel,
		"g_szBotBossSentryBusterModel");
	SYMBOL_OBJ(g_szPlayerRobotModels,
		"g_szPlayerRobotModels");

	SYMBOL_OBJ(s_TankModel,
		"_ZL11s_TankModel");
	SYMBOL_OBJ(s_TankModelRome,
		"_ZL15s_TankModelRome");

	SYMBOL_OBJ(g_szRomePromoItems_Hat,
		"g_szRomePromoItems_Hat");
	SYMBOL_OBJ(g_szRomePromoItems_Misc,
		"g_szRomePromoItems_Misc");
	
	
	/* globals */
	
	SYMBOL_OBJ(engine,
		"engine");
	
	SYMBOL_OBJ(gpGlobals,
		"gpGlobals");
	
	SYMBOL_OBJ(gEntList,
		"gEntList");
	
	SYMBOL_OBJ(enginetrace,
		"enginetrace");
	
	SYMBOL_OBJ(gameeventmanager,
		"gameeventmanager");
	
	SYMBOL_OBJ(g_pGameRules,
		"g_pGameRules");
	
	SYMBOL_OBJ(CTF_GameStats,
		"CTF_GameStats");
	
	SYMBOL_OBJ(g_pObjectiveResource,
		"g_pObjectiveResource");
	
	SYMBOL_OBJ(CONVAR_mp_restartgame,
		"mp_restartgame");
	
	
	/* functions: global */
	
	SYMBOL_FUNC(SV_FindServerClass,
		"_Z18SV_FindServerClassPKc");
	
	SYMBOL_FUNC(ENTINDEX,
		"_Z8ENTINDEXP11CBaseEntity");
	
	SYMBOL_FUNC(UserMessageBegin,
		"_Z16UserMessageBeginR16IRecipientFilterPKc");
	SYMBOL_FUNC(MessageEnd,
		"_Z10MessageEndv");
	SYMBOL_FUNC(MessageWriteAngle,
		"_Z17MessageWriteAnglef");
	SYMBOL_FUNC(MessageWriteAngles,
		"_Z18MessageWriteAnglesRK6QAngle");
	SYMBOL_FUNC(MessageWriteBits,
		"_Z16MessageWriteBitsPKvi");
	SYMBOL_FUNC(MessageWriteBool,
		"_Z16MessageWriteBoolb");
	SYMBOL_FUNC(MessageWriteByte,
		"_Z16MessageWriteBytei");
	SYMBOL_FUNC(MessageWriteChar,
		"_Z16MessageWriteChari");
	SYMBOL_FUNC(MessageWriteCoord,
		"_Z17MessageWriteCoordf");
	SYMBOL_FUNC(MessageWriteEHandle,
		"_Z19MessageWriteEHandleP11CBaseEntity");
	SYMBOL_FUNC(MessageWriteEntity,
		"_Z18MessageWriteEntityi");
	SYMBOL_FUNC(MessageWriteFloat,
		"_Z17MessageWriteFloatf");
	SYMBOL_FUNC(MessageWriteLong,
		"_Z16MessageWriteLongi");
	SYMBOL_FUNC(MessageWriteSBitLong,
		"_Z20MessageWriteSBitLongii");
	SYMBOL_FUNC(MessageWriteShort,
		"_Z17MessageWriteShorti");
	SYMBOL_FUNC(MessageWriteString,
		"_Z18MessageWriteStringPKc");
	SYMBOL_FUNC(MessageWriteUBitLong,
		"_Z20MessageWriteUBitLongji");
	SYMBOL_FUNC(MessageWriteVec3Coord,
		"_Z21MessageWriteVec3CoordRK6Vector");
	SYMBOL_FUNC(MessageWriteVec3Normal,
		"_Z22MessageWriteVec3NormalRK6Vector");
	SYMBOL_FUNC(MessageWriteWord,
		"_Z16MessageWriteWordi");
	
	SYMBOL_FUNC(CreateEntityByName,
		"_Z18CreateEntityByNamePKci");
	
	SYMBOL_FUNC(ClientPrint,
		"_Z11ClientPrintP11CBasePlayeriPKcS2_S2_S2_S2_");
	SYMBOL_FUNC(UTIL_ClientPrintAll,
		"_Z19UTIL_ClientPrintAlliPKcS0_S0_S0_S0_");
	SYMBOL_FUNC(UTIL_ClientPrintFilter,
		"_Z22UTIL_ClientPrintFilterR16IRecipientFilteriPKcS2_S2_S2_S2_");
	SYMBOL_FUNC(UTIL_EntitiesAlongRay,
		"_Z21UTIL_EntitiesAlongRayRK5Ray_tP20CFlaggedEntitiesEnum");
	SYMBOL_FUNC(UTIL_EntitiesInBox,
		"_Z18UTIL_EntitiesInBoxRK6VectorS1_P20CFlaggedEntitiesEnum");
	SYMBOL_FUNC(UTIL_EntitiesInSphere,
		"_Z21UTIL_EntitiesInSphereRK6VectorfP20CFlaggedEntitiesEnum");
	SYMBOL_FUNC(UTIL_EntityByIndex,
		"_Z18UTIL_EntityByIndexi");
	SYMBOL_FUNC(UTIL_GetHolidayForString,
		"_Z24UTIL_GetHolidayForStringPKc");
	SYMBOL_FUNC(UTIL_HudHintText,
		"_Z16UTIL_HudHintTextP11CBaseEntityPKc");
	SYMBOL_FUNC(UTIL_HudMessage,
		"_Z15UTIL_HudMessageP11CBasePlayerRK14hudtextparms_sPKc");
	SYMBOL_FUNC(UTIL_HudMessageAll,
		"_Z18UTIL_HudMessageAllRK14hudtextparms_sPKc");
	SYMBOL_FUNC(UTIL_IsHolidayActive,
		"_Z20UTIL_IsHolidayActivei");
	SYMBOL_FUNC(UTIL_LogPrintf,
		"_Z14UTIL_LogPrintfPKcz");
	SYMBOL_FUNC(UTIL_PlayerByIndex,
		"_Z18UTIL_PlayerByIndexi");
	SYMBOL_FUNC(UTIL_PlayerByName,
		"_Z17UTIL_PlayerByNamePKc");
	SYMBOL_FUNC(UTIL_PlayerBySteamID,
		"_Z20UTIL_PlayerBySteamIDRK8CSteamID");
	SYMBOL_FUNC(UTIL_PlayerByUserId,
		"_Z19UTIL_PlayerByUserIdi");
	SYMBOL_FUNC(UTIL_SayText,
		"_Z12UTIL_SayTextPKcP11CBasePlayer");
	SYMBOL_FUNC(UTIL_SayTextAll,
		"_Z15UTIL_SayTextAllPKcP11CBasePlayerb");
	SYMBOL_FUNC(UTIL_SayTextFilter,
		"_Z19UTIL_SayText2FilterR16IRecipientFilterP11CBasePlayerbPKcS4_S4_S4_S4_");
	SYMBOL_FUNC(UTIL_ScreenShake,
		"_Z16UTIL_ScreenShakeRK6Vectorffff14ShakeCommand_tb");
	SYMBOL_FUNC(UTIL_ShowMessage,
		"_Z16UTIL_ShowMessagePKcP11CBasePlayer");
	SYMBOL_FUNC(UTIL_ShowMessageAll,
		"_Z19UTIL_ShowMessageAllPKc");
	
	SYMBOL_FUNC(V_stricmp,
		"_Z9V_stricmpPKcS0_");
	
	SYMBOL_FUNC(AllocPooledString,
		"_Z17AllocPooledStringPKc");
	SYMBOL_FUNC(AllocPooledString_StaticConstantStringPointer,
		"_Z45AllocPooledString_StaticConstantStringPointerPKc");
	
	SYMBOL_FUNC(TranslateWeaponEntForClass,
		"_Z26TranslateWeaponEntForClassPKci");
	
	SYMBOL_FUNC(WeaponID_IsSniperRifle,
		"_Z22WeaponID_IsSniperRiflei");
	SYMBOL_FUNC(WeaponID_IsSniperRifleOrBow,
		"_Z27WeaponID_IsSniperRifleOrBowi");
	
	SYMBOL_FUNC(FX_FireBullets,
		"_Z14FX_FireBulletsP13CTFWeaponBaseiRK6VectorRK6QAngleiiiffb");
	
	SYMBOL_FUNC(GetEquippedDemoShield,
		"_Z21GetEquippedDemoShieldP9CTFPlayer");
	
	SYMBOL_FUNC(EconEntity_OnOwnerKillEaterEventNoPartner,
		"_Z41EconEntity_OnOwnerKillEaterEventNoPartnerP11CEconEntityP9CTFPlayer18kill_eater_event_ti");
	
	
	/* functions: static */
	
	SYMBOL_FUNC(CBaseEntity_GetDataDescMap,
		"_ZN11CBaseEntity14GetDataDescMapEv");
	SYMBOL_FUNC(CBaseEntity_PrecacheScriptSound,
		"_ZN11CBaseEntity19PrecacheScriptSoundEPKc");
	
	SYMBOL_FUNC(CBasePlayer_GetDataDescMap,
		"_ZN11CBasePlayer14GetDataDescMapEv");
	
	SYMBOL_FUNC(CTFPlayer_GetDataDescMap,
		"_ZN9CTFPlayer14GetDataDescMapEv");
	
	SYMBOL_FUNC(CBaseObject_GetDataDescMap,
		"_ZN11CBaseObject14GetDataDescMapEv");
	
	SYMBOL_FUNC(CObjectSentrygun_GetDataDescMap,
		"_ZN16CObjectSentrygun14GetDataDescMapEv");
	
	SYMBOL_FUNC(CGameRulesProxy_NotifyNetworkStateChanged,
		"_ZN15CGameRulesProxy25NotifyNetworkStateChangedEv");
	
	SYMBOL_FUNC(CTFMedigunShield_Create,
		"_ZN16CTFMedigunShield6CreateEP9CTFPlayer");
	
	SYMBOL_FUNC(CTFPlayerSharedUtils_GetEconItemViewByLoadoutSlot,
		"_ZN20CTFPlayerSharedUtils28GetEconItemViewByLoadoutSlotEP9CTFPlayeriPP11CEconEntity");
	
	SYMBOL_FUNC(CTFDroppedWeapon_Create,
		"_ZN16CTFDroppedWeapon6CreateEP9CTFPlayerRK6VectorRK6QAnglePKcPK13CEconItemView");
	
	SYMBOL_FUNC(CAttributeManager_AttribHookValue_float,
		"_ZN17CAttributeManager15AttribHookValueIfEET_S1_PKcPK11CBaseEntityP10CUtlVectorIPS4_10CUtlMemoryIS8_iEEb");
	SYMBOL_FUNC(CAttributeManager_AttribHookValue_int,
		"_ZN17CAttributeManager15AttribHookValueIiEET_S1_PKcPK11CBaseEntityP10CUtlVectorIPS4_10CUtlMemoryIS8_iEEb");
	
	
	/* functions: member */
	
	SYMBOL_FUNC(CServerGameDLL_DLLInit,
		"_ZN14CServerGameDLL7DLLInitEPFPvPKcPiES5_S5_P11CGlobalVars");
	SYMBOL_FUNC(CServerGameDLL_PreClientUpdate,
		"_ZN14CServerGameDLL15PreClientUpdateEb");
	SYMBOL_FUNC(CServerGameDLL_GetTickInterval,
		"_ZNK14CServerGameDLL15GetTickIntervalEv");
	
	SYMBOL_FUNC(CVEngineServer_PEntityOfEntIndex,
		"_ZN14CVEngineServer17PEntityOfEntIndexEi");
	
	SYMBOL_FUNC(ConVar_ctor,
		"_ZN6ConVarC1EPKcS1_iS1_");
	SYMBOL_FUNC(ConVar_ctor_callback,
		"_ZN6ConVarC1EPKcS1_iS1_PFvP7IConVarS1_fE");
	SYMBOL_FUNC_LIB("server_srv.so", ConVar_SetValue_int,
		"_ZN6ConVar8SetValueEi");
	
	SYMBOL_FUNC(ConCommand_ctor,
		"_ZN10ConCommandC1EPKcPFvRK8CCommandES1_iPFiS1_PA64_cE");
	
	SYMBOL_FUNC(CGameEventManager_CreateEvent,
		"_ZN17CGameEventManager11CreateEventEPKcb");
	SYMBOL_FUNC(CGameEventManager_FireEvent,
		"_ZN17CGameEventManager9FireEventEP10IGameEventb");
	
	SYMBOL_FUNC(CGlobalEntityList_FindEntityByName,
		"_ZN17CGlobalEntityList16FindEntityByNameEP11CBaseEntityPKcS1_S1_S1_P17IEntityFindFilter");
	
	SYMBOL_FUNC(CBaseEntity_ApplyAbsVelocityImpulse,
		"_ZN11CBaseEntity23ApplyAbsVelocityImpulseERK6Vector");
	SYMBOL_FUNC(CBaseEntity_GetBaseEntity,
		"_ZN11CBaseEntity13GetBaseEntityEv");
	SYMBOL_FUNC(CBaseEntity_GetMaxHealth,
		"_ZNK11CBaseEntity12GetMaxHealthEv");
	SYMBOL_FUNC(CBaseEntity_GetTeamNumber,
		"_ZNK11CBaseEntity13GetTeamNumberEv");
	SYMBOL_FUNC(CBaseEntity_IsAlive,
		"_ZN11CBaseEntity7IsAliveEv");
	SYMBOL_FUNC(CBaseEntity_IsBaseObject,
		"_ZNK11CBaseEntity12IsBaseObjectEv");
	SYMBOL_FUNC(CBaseEntity_IsPlayer,
		"_ZNK11CBaseEntity8IsPlayerEv");
	SYMBOL_FUNC(CBaseEntity_TakeDamage,
		"_ZN11CBaseEntity10TakeDamageERK15CTakeDamageInfo");
	
	SYMBOL_FUNC(CBaseAnimating_DrawServerHitboxes,
		"_ZN14CBaseAnimating18DrawServerHitboxesEfb");
	SYMBOL_FUNC(CBaseAnimating_SetModelScale,
		"_ZN14CBaseAnimating13SetModelScaleEff");
	
	SYMBOL_FUNC(CBasePlayer_ChangeTeam,
		"_ZN11CBasePlayer10ChangeTeamEi");
	SYMBOL_FUNC(CBasePlayer_CommitSuicide,
		"_ZN11CBasePlayer13CommitSuicideEbb");
	SYMBOL_FUNC(CBasePlayer_GiveNamedItem,
		"_ZN11CBasePlayer13GiveNamedItemEPKci");
	SYMBOL_FUNC(CBasePlayer_IsBot,
		"_ZNK11CBasePlayer5IsBotEv");
	
	SYMBOL_FUNC(CBaseMultiplayerPlayer_SpeakConceptIfAllowed,
		"_ZN22CBaseMultiplayerPlayer21SpeakConceptIfAllowedEiPKcPcjP16IRecipientFilter");
	
	SYMBOL_FUNC(CTFPlayer_AddBuildResources,
		"_ZN9CTFPlayer17AddBuildResourcesEi");
	SYMBOL_FUNC(CTFPlayer_ApplyAbsVelocityImpulse,
		"_ZN9CTFPlayer23ApplyAbsVelocityImpulseERK6Vector");
	SYMBOL_FUNC(CTFPlayer_CanBeForcedToLaugh,
		"_ZN9CTFPlayer18CanBeForcedToLaughEv");
	SYMBOL_FUNC(CTFPlayer_CanBuild,
		"_ZN9CTFPlayer8CanBuildEii");
	SYMBOL_FUNC(CTFPlayer_CanHearAndReadChatFrom,
		"_ZN9CTFPlayer22CanHearAndReadChatFromEP11CBasePlayer");
	SYMBOL_FUNC(CTFPlayer_CanPickupBuilding,
		"_ZN9CTFPlayer17CanPickupBuildingEP11CBaseObject");
	SYMBOL_FUNC(CTFPlayer_ChangeTeam,
		"_ZN9CTFPlayer10ChangeTeamEi");
	SYMBOL_FUNC(CTFPlayer_CommitSuicide,
		"_ZN9CTFPlayer13CommitSuicideEbb");
	SYMBOL_FUNC(CTFPlayer_CreateRagdollEntity,
		"_ZN9CTFPlayer19CreateRagdollEntityEbbbbbbbbib");
	SYMBOL_FUNC(CTFPlayer_DeathSound,
		"_ZN9CTFPlayer10DeathSoundERK15CTakeDamageInfo");
	SYMBOL_FUNC(CTFPlayer_DoClassSpecialSkill,
		"_ZN9CTFPlayer19DoClassSpecialSkillEv");
	SYMBOL_FUNC(CTFPlayer_Event_Killed,
		"_ZN9CTFPlayer12Event_KilledERK15CTakeDamageInfo");
	SYMBOL_FUNC(CTFPlayer_Event_KilledOther,
		"_ZN9CTFPlayer17Event_KilledOtherEP11CBaseEntityRK15CTakeDamageInfo");
	SYMBOL_FUNC(CTFPlayer_FireBullet,
		"_ZN9CTFPlayer10FireBulletEP13CTFWeaponBaseRK17FireBulletsInfo_tbii");
	SYMBOL_FUNC(CTFPlayer_ForceChangeTeam,
		"_ZN9CTFPlayer15ForceChangeTeamEib");
	SYMBOL_FUNC(CTFPlayer_GetActiveTFWeapon,
		"_ZNK9CTFPlayer17GetActiveTFWeaponEv");
	SYMBOL_FUNC(CTFPlayer_GetClosestCaptureZone,
		"_ZN9CTFPlayer21GetClosestCaptureZoneEv");
	SYMBOL_FUNC(CTFPlayer_GetNumObjects,
		"_ZN9CTFPlayer13GetNumObjectsEii");
	SYMBOL_FUNC(CTFPlayer_GiveNamedItem,
		"_ZN9CTFPlayer13GiveNamedItemEPKciPK13CEconItemViewb");
	SYMBOL_FUNC(CTFPlayer_HandleCommand_JoinClass,
		"_ZN9CTFPlayer23HandleCommand_JoinClassEPKcb");
	SYMBOL_FUNC(CTFPlayer_IsMiniBoss,
		"_ZNK9CTFPlayer10IsMiniBossEv");
	SYMBOL_FUNC(CTFPlayer_IsPlayerClass,
		"_ZNK9CTFPlayer13IsPlayerClassEi");
	SYMBOL_FUNC(CTFPlayer_OnTakeDamage,
		"_ZN9CTFPlayer12OnTakeDamageERK15CTakeDamageInfo");
	SYMBOL_FUNC(CTFPlayer_OnTakeDamage_Alive,
		"_ZN9CTFPlayer18OnTakeDamage_AliveERK15CTakeDamageInfo");
	SYMBOL_FUNC(CTFPlayer_Regenerate,
		"_ZN9CTFPlayer10RegenerateEb");
	SYMBOL_FUNC(CTFPlayer_RememberUpgrade,
		"_ZN9CTFPlayer15RememberUpgradeEiP13CEconItemViewiib");
	SYMBOL_FUNC(CTFPlayer_RemoveAmmo,
		"_ZN9CTFPlayer10RemoveAmmoEii");
	SYMBOL_FUNC(CTFPlayer_RemoveCurrency,
		"_ZN9CTFPlayer14RemoveCurrencyEi");
	SYMBOL_FUNC(CTFPlayer_RemoveDisguise,
		"_ZN9CTFPlayer14RemoveDisguiseEv");
	SYMBOL_FUNC(CTFPlayer_ShouldDropAmmoPack,
		"_ZN9CTFPlayer18ShouldDropAmmoPackEv");
	SYMBOL_FUNC(CTFPlayer_ShouldGib,
		"_ZN9CTFPlayer9ShouldGibERK15CTakeDamageInfo");
	SYMBOL_FUNC(CTFPlayer_SpeakConceptIfAllowed,
		"_ZN9CTFPlayer21SpeakConceptIfAllowedEiPKcPcjP16IRecipientFilter");
	SYMBOL_FUNC(CTFPlayer_TFPlayerThink,
		"_ZN9CTFPlayer13TFPlayerThinkEv");
	SYMBOL_FUNC(CTFPlayer_TraceAttack,
		"_ZN9CTFPlayer11TraceAttackERK15CTakeDamageInfoRK6VectorP10CGameTraceP15CDmgAccumulator");
	SYMBOL_FUNC(CTFPlayer_TryToPickupBuilding,
		"_ZN9CTFPlayer19TryToPickupBuildingEv");
	
	SYMBOL_FUNC(CTFBot_AddItem,
		"_ZN6CTFBot7AddItemEPKc");
	SYMBOL_FUNC(CTFBot_EquipRequiredWeapon,
		"_ZN6CTFBot19EquipRequiredWeaponEv");
	SYMBOL_FUNC(CTFBot_IsAllowedToPickUpFlag,
		"_ZNK6CTFBot21IsAllowedToPickUpFlagEv");
	SYMBOL_FUNC(CTFBot_PressFireButton,
		"_ZN6CTFBot15PressFireButtonEf");
	SYMBOL_FUNC(CTFBot_PressAltFireButton,
		"_ZN6CTFBot18PressAltFireButtonEf");
	SYMBOL_FUNC(CTFBot_PressSpecialFireButton,
		"_ZN6CTFBot22PressSpecialFireButtonEf");
	SYMBOL_FUNC(CTFBot_SelectRandomReachableEnemy,
		"_ZN6CTFBot26SelectRandomReachableEnemyEv");
	SYMBOL_FUNC(CTFBot_SetMission,
		"_ZN6CTFBot10SetMissionENS_11MissionTypeEb");
	SYMBOL_FUNC(CTFBot_ShouldGib,
		"_ZN6CTFBot9ShouldGibERK15CTakeDamageInfo");
	
	SYMBOL_FUNC(NextBotPlayer_CTFPlayer_GetEntity,
		"_ZNK13NextBotPlayerI9CTFPlayerE9GetEntityEv");
	SYMBOL_FUNC(NextBotPlayer_CTFPlayer_IsBot,
		"_ZNK13NextBotPlayerI9CTFPlayerE5IsBotEv");
	SYMBOL_FUNC(NextBotPlayer_CTFPlayer_PressFireButton,
		"_ZN13NextBotPlayerI9CTFPlayerE15PressFireButtonEf");
	SYMBOL_FUNC(NextBotPlayer_CTFPlayer_ReleaseFireButton,
		"_ZN13NextBotPlayerI9CTFPlayerE17ReleaseFireButtonEv");
	SYMBOL_FUNC(NextBotPlayer_CTFPlayer_PressMeleeButton,
		"_ZN13NextBotPlayerI9CTFPlayerE16PressMeleeButtonEf");
	SYMBOL_FUNC(NextBotPlayer_CTFPlayer_ReleaseMeleeButton,
		"_ZN13NextBotPlayerI9CTFPlayerE18ReleaseMeleeButtonEv");
	SYMBOL_FUNC(NextBotPlayer_CTFPlayer_PressSpecialFireButton,
		"_ZN13NextBotPlayerI9CTFPlayerE22PressSpecialFireButtonEf");
	SYMBOL_FUNC(NextBotPlayer_CTFPlayer_ReleaseSpecialFireButton,
		"_ZN13NextBotPlayerI9CTFPlayerE24ReleaseSpecialFireButtonEv");
	SYMBOL_FUNC(NextBotPlayer_CTFPlayer_PressUseButton,
		"_ZN13NextBotPlayerI9CTFPlayerE14PressUseButtonEf");
	SYMBOL_FUNC(NextBotPlayer_CTFPlayer_ReleaseUseButton,
		"_ZN13NextBotPlayerI9CTFPlayerE16ReleaseUseButtonEv");
	SYMBOL_FUNC(NextBotPlayer_CTFPlayer_PressReloadButton,
		"_ZN13NextBotPlayerI9CTFPlayerE17PressReloadButtonEf");
	SYMBOL_FUNC(NextBotPlayer_CTFPlayer_ReleaseReloadButton,
		"_ZN13NextBotPlayerI9CTFPlayerE19ReleaseReloadButtonEv");
	SYMBOL_FUNC(NextBotPlayer_CTFPlayer_PressForwardButton,
		"_ZN13NextBotPlayerI9CTFPlayerE18PressForwardButtonEf");
	SYMBOL_FUNC(NextBotPlayer_CTFPlayer_ReleaseForwardButton,
		"_ZN13NextBotPlayerI9CTFPlayerE20ReleaseForwardButtonEv");
	SYMBOL_FUNC(NextBotPlayer_CTFPlayer_PressBackwardButton,
		"_ZN13NextBotPlayerI9CTFPlayerE19PressBackwardButtonEf");
	SYMBOL_FUNC(NextBotPlayer_CTFPlayer_ReleaseBackwardButton,
		"_ZN13NextBotPlayerI9CTFPlayerE21ReleaseBackwardButtonEv");
	SYMBOL_FUNC(NextBotPlayer_CTFPlayer_PressLeftButton,
		"_ZN13NextBotPlayerI9CTFPlayerE15PressLeftButtonEf");
	SYMBOL_FUNC(NextBotPlayer_CTFPlayer_ReleaseLeftButton,
		"_ZN13NextBotPlayerI9CTFPlayerE17ReleaseLeftButtonEv");
	SYMBOL_FUNC(NextBotPlayer_CTFPlayer_PressRightButton,
		"_ZN13NextBotPlayerI9CTFPlayerE16PressRightButtonEf");
	SYMBOL_FUNC(NextBotPlayer_CTFPlayer_ReleaseRightButton,
		"_ZN13NextBotPlayerI9CTFPlayerE18ReleaseRightButtonEv");
	SYMBOL_FUNC(NextBotPlayer_CTFPlayer_PressJumpButton,
		"_ZN13NextBotPlayerI9CTFPlayerE15PressJumpButtonEf");
	SYMBOL_FUNC(NextBotPlayer_CTFPlayer_ReleaseJumpButton,
		"_ZN13NextBotPlayerI9CTFPlayerE17ReleaseJumpButtonEv");
	SYMBOL_FUNC(NextBotPlayer_CTFPlayer_PressCrouchButton,
		"_ZN13NextBotPlayerI9CTFPlayerE17PressCrouchButtonEf");
	SYMBOL_FUNC(NextBotPlayer_CTFPlayer_ReleaseCrouchButton,
		"_ZN13NextBotPlayerI9CTFPlayerE19ReleaseCrouchButtonEv");
	SYMBOL_FUNC(NextBotPlayer_CTFPlayer_PressWalkButton,
		"_ZN13NextBotPlayerI9CTFPlayerE15PressWalkButtonEf");
	SYMBOL_FUNC(NextBotPlayer_CTFPlayer_ReleaseWalkButton,
		"_ZN13NextBotPlayerI9CTFPlayerE17ReleaseWalkButtonEv");
	SYMBOL_FUNC(NextBotPlayer_CTFPlayer_SetButtonScale,
		"_ZN13NextBotPlayerI9CTFPlayerE14SetButtonScaleEff");
	
	SYMBOL_FUNC(CTFPlayerShared_AddCond,
		"_ZN15CTFPlayerShared7AddCondE7ETFCondfP11CBaseEntity");
	SYMBOL_FUNC(CTFPlayerShared_Burn,
		"_ZN15CTFPlayerShared4BurnEP9CTFPlayerP13CTFWeaponBasef");
	SYMBOL_FUNC(CTFPlayerShared_ConditionGameRulesThink,
		"_ZN15CTFPlayerShared23ConditionGameRulesThinkEv");
	SYMBOL_FUNC(CTFPlayerShared_GetActiveTFWeapon,
		"_ZNK15CTFPlayerShared17GetActiveTFWeaponEv");
	SYMBOL_FUNC(CTFPlayerShared_HasDemoShieldEquipped,
		"_ZNK15CTFPlayerShared21HasDemoShieldEquippedEv");
	SYMBOL_FUNC(CTFPlayerShared_IsAlly,
		"_ZN15CTFPlayerShared6IsAllyEP11CBaseEntity");
	SYMBOL_FUNC(CTFPlayerShared_IsControlStunned,
		"_ZN15CTFPlayerShared16IsControlStunnedEv");
	SYMBOL_FUNC(CTFPlayerShared_IsInvulnerable,
		"_ZNK15CTFPlayerShared14IsInvulnerableEv");
	SYMBOL_FUNC(CTFPlayerShared_OnAddBurning,
		"_ZN15CTFPlayerShared12OnAddBurningEv");
	SYMBOL_FUNC(CTFPlayerShared_OnAddReprogrammed,
		"_ZN15CTFPlayerShared17OnAddReprogrammedEv");
	SYMBOL_FUNC(CTFPlayerShared_OnAddSpeedBoost,
		"_ZN15CTFPlayerShared15OnAddSpeedBoostEb");
	SYMBOL_FUNC(CTFPlayerShared_OnAddDisguisedAsDispenser,
		"_ZN15CTFPlayerShared25OnAddDisguisedAsDispenserEv");
	SYMBOL_FUNC(CTFPlayerShared_OnConditionAdded,
		"_ZN15CTFPlayerShared16OnConditionAddedE7ETFCond");
	SYMBOL_FUNC(CTFPlayerShared_OnConditionRemoved,
		"_ZN15CTFPlayerShared18OnConditionRemovedE7ETFCond");
	SYMBOL_FUNC(CTFPlayerShared_OnRemoveDisguisedAsDispenser,
		"_ZN15CTFPlayerShared28OnRemoveDisguisedAsDispenserEv");
	SYMBOL_FUNC(CTFPlayerShared_OnRemoveReprogrammed,
		"_ZN15CTFPlayerShared20OnRemoveReprogrammedEv");
	SYMBOL_FUNC(CTFPlayerShared_OnRemoveSpeedBoost,
		"_ZN15CTFPlayerShared18OnRemoveSpeedBoostEb");
	SYMBOL_FUNC(CTFPlayerShared_OnRemoveStunned,
		"_ZN15CTFPlayerShared15OnRemoveStunnedEv");
	SYMBOL_FUNC(CTFPlayerShared_RadiusCurrencyCollectionCheck,
		"_ZN15CTFPlayerShared29RadiusCurrencyCollectionCheckEv");
	SYMBOL_FUNC(CTFPlayerShared_RemoveCond,
		"_ZN15CTFPlayerShared10RemoveCondE7ETFCondb");
	SYMBOL_FUNC(CTFPlayerShared_StunPlayer,
		"_ZN15CTFPlayerShared10StunPlayerEffiP9CTFPlayer");
	
	SYMBOL_FUNC(CTFPlayerClassShared_SetCustomModel,
		"_ZN20CTFPlayerClassShared14SetCustomModelEPKcb");
	
	SYMBOL_FUNC(CTFBaseBoss_ResolvePlayerCollision,
		"_ZN11CTFBaseBoss22ResolvePlayerCollisionEP9CTFPlayer");
	
	SYMBOL_FUNC(CTFTankBoss_ModifyDamage,
		"_ZNK11CTFTankBoss12ModifyDamageEP15CTakeDamageInfo");
	SYMBOL_FUNC(CTFTankBoss_OnTakeDamage_Alive,
		"_ZN11CTFTankBoss18OnTakeDamage_AliveERK15CTakeDamageInfo");
	SYMBOL_FUNC(CTFTankBoss_Spawn,
		"_ZN11CTFTankBoss5SpawnEv");
	SYMBOL_FUNC(CTFTankBoss_TankBossThink,
		"_ZN11CTFTankBoss13TankBossThinkEv");
	
	SYMBOL_FUNC(CEconItemSchema_GetAttributeDefinitionByName,
		"_ZN15CEconItemSchema28GetAttributeDefinitionByNameEPKc");
	SYMBOL_FUNC(CEconItemSchema_GetItemDefinitionByName,
		"_ZN15CEconItemSchema23GetItemDefinitionByNameEPKc");
	
	SYMBOL_FUNC(CEconItemView_GetItemDefIndex,
		"_ZNK13CEconItemView15GetItemDefIndexEv");
	
	SYMBOL_FUNC(CSchemaFieldHandle_CEconItemDefinition_ctor,
		"_ZN18CSchemaFieldHandleI19CEconItemDefinitionEC1EPKc");
	
	SYMBOL_FUNC(CItemGeneration_GenerateRandomItem,
		"_ZN15CItemGeneration18GenerateRandomItemEP22CItemSelectionCriteriaRK6VectorRK6QAngle");
	SYMBOL_FUNC(CItemGeneration_SpawnItem,
		"_ZN15CItemGeneration9SpawnItemEiRK6VectorRK6QAngleiiPKc");
	
	SYMBOL_FUNC(CBaseCombatWeapon_SetWeaponVisible,
		"_ZN17CBaseCombatWeapon16SetWeaponVisibleEb");
	SYMBOL_FUNC(CBaseCombatWeapon_GetOwner,
		"_ZNK17CBaseCombatWeapon8GetOwnerEv");
	
	SYMBOL_FUNC(CTFWeaponBase_AreRandomCritsEnabled,
		"_ZN13CTFWeaponBase21AreRandomCritsEnabledEv");
	SYMBOL_FUNC(CTFWeaponBase_CalcIsAttackCritical,
		"_ZN13CTFWeaponBase20CalcIsAttackCriticalEv");
	SYMBOL_FUNC(CTFWeaponBase_CalcIsAttackCriticalHelper,
		"_ZN13CTFWeaponBase26CalcIsAttackCriticalHelperEv");
	SYMBOL_FUNC(CTFWeaponBase_CalcIsAttackCriticalHelperNoCrits,
		"_ZN13CTFWeaponBase33CalcIsAttackCriticalHelperNoCritsEv");
	SYMBOL_FUNC(CTFWeaponBase_CanBeCritBoosted,
		"_ZN13CTFWeaponBase16CanBeCritBoostedEv");
	SYMBOL_FUNC(CTFWeaponBase_CanFireRandomCriticalShot,
		"_ZN13CTFWeaponBase25CanFireRandomCriticalShotEf");
	SYMBOL_FUNC(CTFWeaponBase_GetWeaponID,
		"_ZNK13CTFWeaponBase11GetWeaponIDEv");
	SYMBOL_FUNC(CTFWeaponBase_StartEffectBarRegen,
		"_ZN13CTFWeaponBase19StartEffectBarRegenEv");
	SYMBOL_FUNC(CTFWeaponBase_ItemBusyFrame,
		"_ZN13CTFWeaponBase13ItemBusyFrameEv");
	
	SYMBOL_FUNC(CTFWeaponBaseGun_GetWeaponProjectileType,
		"_ZNK16CTFWeaponBaseGun23GetWeaponProjectileTypeEv");
	SYMBOL_FUNC(CTFWeaponBaseGun_PrimaryAttack,
		"_ZN16CTFWeaponBaseGun13PrimaryAttackEv");
	
	SYMBOL_FUNC(CWeaponMedigun_CreateMedigunShield,
		"_ZN14CWeaponMedigun19CreateMedigunShieldEv");
	SYMBOL_FUNC(CWeaponMedigun_GetTargetRange,
		"_ZN14CWeaponMedigun14GetTargetRangeEv");
	SYMBOL_FUNC(CWeaponMedigun_IsAttachedToBuilding,
		"_ZN14CWeaponMedigun20IsAttachedToBuildingEv");
	
	SYMBOL_FUNC(CTFRocketLauncher_Precache,
		"_ZN17CTFRocketLauncher8PrecacheEv");
	
	SYMBOL_FUNC(CTFSniperRifle_DestroySniperDot,
		"_ZN14CTFSniperRifle16DestroySniperDotEv");
	SYMBOL_FUNC(CTFSniperRifle_ExplosiveHeadShot,
		"_ZN14CTFSniperRifle17ExplosiveHeadShotEP9CTFPlayerS1_");
	SYMBOL_FUNC(CTFSniperRifle_ItemPostFrame,
		"_ZN14CTFSniperRifle13ItemPostFrameEv");
	SYMBOL_FUNC(CTFSniperRifleClassic_ItemPostFrame,
		"_ZN21CTFSniperRifleClassic13ItemPostFrameEv");
	SYMBOL_FUNC(CTFSniperRifleDecap_SniperRifleChargeRateMod,
		"_ZN19CTFSniperRifleDecap24SniperRifleChargeRateModEv");
	
	SYMBOL_FUNC(CTFKnife_DisguiseOnKill,
		"_ZN8CTFKnife14DisguiseOnKillEv");
	SYMBOL_FUNC(CTFKnife_PrimaryAttack,
		"_ZN8CTFKnife13PrimaryAttackEv");
	
	SYMBOL_FUNC(CTFWearableDemoShield_EndSpecialAction,
		"_ZN21CTFWearableDemoShield16EndSpecialActionEP9CTFPlayer");
	
	SYMBOL_FUNC(CTFStickBomb_Smack,
		"_ZN12CTFStickBomb5SmackEv");
	
	SYMBOL_FUNC(CTFSword_OnDecapitation,
		"_ZN8CTFSword14OnDecapitationEP9CTFPlayer");
	
	SYMBOL_FUNC(CTFWeaponBuilder_StartBuilding,
		"_ZN16CTFWeaponBuilder13StartBuildingEv");
	
	SYMBOL_FUNC(CTFBaseRocket_Explode,
		"_ZN13CTFBaseRocket7ExplodeEP10CGameTraceP11CBaseEntity");
	
	SYMBOL_FUNC(CTFWeaponBaseGrenadeProj_Explode,
		"_ZN24CTFWeaponBaseGrenadeProj7ExplodeEP10CGameTracei");
	
	SYMBOL_FUNC(CTFProjectile_Arrow_StrikeTarget,
		"_ZN19CTFProjectile_Arrow12StrikeTargetEP13mstudiobbox_tP11CBaseEntity");
	SYMBOL_FUNC(CTFProjectile_Flare_Explode,
		"_ZN19CTFProjectile_Flare7ExplodeEP10CGameTraceP11CBaseEntity");
	
	SYMBOL_FUNC(CBaseObject_DoQuickBuild,
		"_ZN11CBaseObject12DoQuickBuildEb");
	SYMBOL_FUNC(CBaseObject_GetBuilder,
		"_ZNK11CBaseObject10GetBuilderEv");
	SYMBOL_FUNC(CBaseObject_GetMaxHealthForCurrentLevel,
		"_ZN11CBaseObject27GetMaxHealthForCurrentLevelEv");
	SYMBOL_FUNC(CBaseObject_GetReversesBuildingConstructionSpeed,
		"_ZN11CBaseObject36GetReversesBuildingConstructionSpeedEv");
	SYMBOL_FUNC(CBaseObject_GetSapper,
		"_ZN11CBaseObject9GetSapperEv");
	SYMBOL_FUNC(CBaseObject_GetType,
		"_ZNK11CBaseObject7GetTypeEv");
	SYMBOL_FUNC(CBaseObject_MakeDisposableBuilding,
		"_ZN11CBaseObject22MakeDisposableBuildingEP9CTFPlayer");
	SYMBOL_FUNC(CBaseObject_OnTakeDamage,
		"_ZN11CBaseObject12OnTakeDamageERK15CTakeDamageInfo");
	SYMBOL_FUNC(CBaseObject_SetHealth,
		"_ZN11CBaseObject9SetHealthEf");
	SYMBOL_FUNC(CBaseObject_SetSolidToPlayers,
		"_ZN11CBaseObject17SetSolidToPlayersENS_12OBJSOLIDTYPEEb");
	SYMBOL_FUNC(CBaseObject_ShouldBeMiniBuilding,
		"_ZN11CBaseObject20ShouldBeMiniBuildingEP9CTFPlayer");
	SYMBOL_FUNC(CBaseObject_ShouldCollide,
		"_ZNK11CBaseObject13ShouldCollideEii");
	SYMBOL_FUNC(CBaseObject_StopPlacement,
		"_ZN11CBaseObject13StopPlacementEv");
	
	SYMBOL_FUNC(CObjectDispenser_MakeMiniBuilding,
		"_ZN16CObjectDispenser16MakeMiniBuildingEP9CTFPlayer");
	SYMBOL_FUNC(CObjectDispenser_ShouldBeMiniBuilding,
		"_ZN16CObjectDispenser20ShouldBeMiniBuildingEP9CTFPlayer");
	SYMBOL_FUNC(CObjectDispenser_StartPlacement,
		"_ZN16CObjectDispenser14StartPlacementEP9CTFPlayer");
	
	SYMBOL_FUNC(CObjectSentrygun_GetBaseTurnRate,
		"_ZN16CObjectSentrygun15GetBaseTurnRateEv");
	SYMBOL_FUNC(CObjectSentrygun_GetMaxHealthForCurrentLevel,
		"_ZN16CObjectSentrygun27GetMaxHealthForCurrentLevelEv");
	SYMBOL_FUNC(CObjectSentrygun_MakeDisposableBuilding,
		"_ZN16CObjectSentrygun22MakeDisposableBuildingEP9CTFPlayer");
	SYMBOL_FUNC(CObjectSentrygun_MoveTurret,
		"_ZN16CObjectSentrygun10MoveTurretEv");
	SYMBOL_FUNC(CObjectSentrygun_SentryRotate,
		"_ZN16CObjectSentrygun12SentryRotateEv");
	SYMBOL_FUNC(CObjectSentrygun_SentryThink,
		"_ZN16CObjectSentrygun11SentryThinkEv");
	SYMBOL_FUNC(CObjectSentrygun_Spawn,
		"_ZN16CObjectSentrygun5SpawnEv");
	SYMBOL_FUNC(CObjectSentrygun_StartBuilding,
		"_ZN16CObjectSentrygun13StartBuildingEP11CBaseEntity");
	
	SYMBOL_FUNC(CObjectTeleporter_FinishedBuilding,
		"_ZN17CObjectTeleporter16FinishedBuildingEv");
	SYMBOL_FUNC(CObjectTeleporter_Spawn,
		"_ZN17CObjectTeleporter5SpawnEv");
	SYMBOL_FUNC(CObjectTeleporter_StartBuilding,
		"_ZN17CObjectTeleporter13StartBuildingEP11CBaseEntity");
	
	SYMBOL_FUNC(CObjectSapper_ApplyRoboSapper,
		"_ZN13CObjectSapper15ApplyRoboSapperEP9CTFPlayerfi");
	SYMBOL_FUNC(CObjectSapper_ApplyRoboSapperEffects,
		"_ZN13CObjectSapper22ApplyRoboSapperEffectsEP9CTFPlayerf");
	SYMBOL_FUNC(CObjectSapper_IsValidRoboSapperTarget,
		"_ZN13CObjectSapper23IsValidRoboSapperTargetEP9CTFPlayer");
	SYMBOL_FUNC(CObjectSapper_Spawn,
		"_ZN13CObjectSapper5SpawnEv");
	
	SYMBOL_FUNC(CTFPowerupBottle_ReapplyProvision,
		"_ZN16CTFPowerupBottle16ReapplyProvisionEv");
	
	SYMBOL_FUNC(CTFGameRules_Activate,
		"_ZN12CTFGameRules8ActivateEv");
	SYMBOL_FUNC(CTFGameRules_BetweenRounds_Think,
		"_ZN12CTFGameRules19BetweenRounds_ThinkEv");
	SYMBOL_FUNC(CTFGameRules_CanUpgradeWithAttrib,
		"_ZN12CTFGameRules20CanUpgradeWithAttribEP9CTFPlayeritP22CMannVsMachineUpgrades");
	SYMBOL_FUNC(CTFGameRules_DistributeCurrencyAmount,
		"_ZN12CTFGameRules24DistributeCurrencyAmountEiP9CTFPlayerbbb");
	SYMBOL_FUNC(CTFGameRules_FireGameEvent,
		"_ZN12CTFGameRules13FireGameEventEP10IGameEvent");
	SYMBOL_FUNC(CTFGameRules_GameModeUsesUpgrades,
		"_ZN12CTFGameRules20GameModeUsesUpgradesEv");
	SYMBOL_FUNC(CTFGameRules_GetBonusRoundTime,
		"_ZN12CTFGameRules17GetBonusRoundTimeEb");
	SYMBOL_FUNC(CTFGameRules_GetCostForUpgrade,
		"_ZN12CTFGameRules17GetCostForUpgradeEP22CMannVsMachineUpgradesiiP9CTFPlayer");
	SYMBOL_FUNC(CTFGameRules_GetUpgradeTier,
		"_ZN12CTFGameRules14GetUpgradeTierEi");
	SYMBOL_FUNC(CTFGameRules_IsInTraining,
		"_ZN12CTFGameRules12IsInTrainingEv");
	SYMBOL_FUNC(CTFGameRules_IsPVEModeActive,
		"_ZNK12CTFGameRules15IsPVEModeActiveEv");
	SYMBOL_FUNC(CTFGameRules_IsPVEModeControlled,
		"_ZNK12CTFGameRules19IsPVEModeControlledEP11CBaseEntity");
	SYMBOL_FUNC(CTFGameRules_IsUpgradeTierEnabled,
		"_ZN12CTFGameRules20IsUpgradeTierEnabledEP9CTFPlayerii");
	SYMBOL_FUNC(CTFGameRules_PlayerReadyStatus_HaveMinPlayersToEnable,
		"_ZN12CTFGameRules40PlayerReadyStatus_HaveMinPlayersToEnableEv");
	SYMBOL_FUNC(CTFGameRules_PlayerReadyStatus_ShouldStartCountdown,
		"_ZN12CTFGameRules38PlayerReadyStatus_ShouldStartCountdownEv");
	SYMBOL_FUNC(CTFGameRules_PlayerReadyStatus_UpdatePlayerState,
		"_ZN12CTFGameRules35PlayerReadyStatus_UpdatePlayerStateEP9CTFPlayerb");
	SYMBOL_FUNC(CTFGameRules_PushAllPlayersAway,
		"_ZN12CTFGameRules18PushAllPlayersAwayERK6VectorffiP10CUtlVectorIP9CTFPlayer10CUtlMemoryIS5_iEE");
	SYMBOL_FUNC(CTFGameRules_UsePlayerReadyStatusMode,
		"_ZN12CTFGameRules24UsePlayerReadyStatusModeEv");
	
	SYMBOL_FUNC(CTeamplayRoundBasedRules_CheckReadyRestart,
		"_ZN24CTeamplayRoundBasedRules17CheckReadyRestartEv");
	
	SYMBOL_FUNC(CTFGameRulesProxy_Activate,
		"_ZN17CTFGameRulesProxy8ActivateEv");
	
	SYMBOL_FUNC(CTFGameStats_IncrementStat,
		"_ZN12CTFGameStats13IncrementStatEP9CTFPlayer12TFStatType_ti");
	SYMBOL_FUNC(CTFGameStats_ResetPlayerStats,
		"_ZN12CTFGameStats16ResetPlayerStatsEP9CTFPlayer");
	
	SYMBOL_FUNC(CMannVsMachineStats_ResetPlayerEvents,
		"_ZN19CMannVsMachineStats17ResetPlayerEventsEP9CTFPlayer");
	SYMBOL_FUNC(CMannVsMachineStats_ResetStats,
		"_ZN19CMannVsMachineStats10ResetStatsEv");
	
	SYMBOL_FUNC(CTFObjectiveResource_AddMannVsMachineWaveClassFlags,
		"_ZN20CTFObjectiveResource30AddMannVsMachineWaveClassFlagsEij");
	SYMBOL_FUNC(CTFObjectiveResource_ClearMannVsMachineWaveClassFlags,
		"_ZN20CTFObjectiveResource32ClearMannVsMachineWaveClassFlagsEv");
	SYMBOL_FUNC(CTFObjectiveResource_DecrementMannVsMachineWaveClassCount,
		"_ZN20CTFObjectiveResource36DecrementMannVsMachineWaveClassCountE8string_tj");
	SYMBOL_FUNC(CTFObjectiveResource_DecrementTeleporterCount,
		"_ZN20CTFObjectiveResource24DecrementTeleporterCountEv");
	SYMBOL_FUNC(CTFObjectiveResource_GetMannVsMachineWaveClassCount,
		"_ZN20CTFObjectiveResource30GetMannVsMachineWaveClassCountEi");
	SYMBOL_FUNC(CTFObjectiveResource_IncrementMannVsMachineWaveClassCount,
		"_ZN20CTFObjectiveResource36IncrementMannVsMachineWaveClassCountE8string_tj");
	SYMBOL_FUNC(CTFObjectiveResource_IncrementTeleporterCount,
		"_ZN20CTFObjectiveResource24IncrementTeleporterCountEv");
	SYMBOL_FUNC(CTFObjectiveResource_SetMannVsMachineWaveClassActive,
		"_ZN20CTFObjectiveResource31SetMannVsMachineWaveClassActiveE8string_tb");
	SYMBOL_FUNC(CTFObjectiveResource_SetMannVsMachineWaveClassCount,
		"_ZN20CTFObjectiveResource30SetMannVsMachineWaveClassCountEii");
	SYMBOL_FUNC(CTFObjectiveResource_SetMannVsMachineWaveClassName,
		"_ZN20CTFObjectiveResource29SetMannVsMachineWaveClassNameEi8string_t");
	
	SYMBOL_FUNC(CPopulationManager_IsInEndlessWaves,
		"_ZN18CPopulationManager16IsInEndlessWavesEv");
	SYMBOL_FUNC(CPopulationManager_IsValidMvMMap,
		"_ZN18CPopulationManager13IsValidMvMMapEPKc");
	SYMBOL_FUNC(CPopulationManager_JumpToWave,
		"_ZN18CPopulationManager10JumpToWaveEjf");
	
	SYMBOL_FUNC(CMissionPopulator_UpdateMission,
		"_ZN17CMissionPopulator13UpdateMissionEN6CTFBot11MissionTypeE");
	SYMBOL_FUNC(CMissionPopulator_UpdateMissionDestroySentries,
		"_ZN17CMissionPopulator28UpdateMissionDestroySentriesEv");
	
	SYMBOL_FUNC(CWaveSpawnPopulator_ForceFinish,
		"_ZN19CWaveSpawnPopulator11ForceFinishEv");
	
	SYMBOL_FUNC(CWave_ForceFinish,
		"_ZN5CWave11ForceFinishEv");
	
	SYMBOL_FUNC(CTFBotSpawner_Spawn,
		"_ZN13CTFBotSpawner5SpawnERK6VectorP10CUtlVectorI7CHandleI11CBaseEntityE10CUtlMemoryIS6_iEE");
	
	SYMBOL_FUNC(CSquadSpawner_Spawn,
		"_ZN13CSquadSpawner5SpawnERK6VectorP10CUtlVectorI7CHandleI11CBaseEntityE10CUtlMemoryIS6_iEE");
	
	SYMBOL_FUNC(CUpgrades_ApplyUpgradeAttributeBlock,
		"_ZN9CUpgrades26ApplyUpgradeAttributeBlockEP20UpgradeAttribBlock_tiP9CTFPlayerb");
	SYMBOL_FUNC(CUpgrades_ApplyUpgradeToItem,
		"_ZN9CUpgrades18ApplyUpgradeToItemEP9CTFPlayerP13CEconItemViewiibb");
	SYMBOL_FUNC(CUpgrades_EndTouch,
		"_ZN9CUpgrades8EndTouchEP11CBaseEntity");
	SYMBOL_FUNC(CUpgrades_FireGameEvent,
		"_ZN9CUpgrades13FireGameEventEP10IGameEvent");
	SYMBOL_FUNC(CUpgrades_GetUpgradeAttributeName,
		"_ZNK9CUpgrades23GetUpgradeAttributeNameEi");
	SYMBOL_FUNC(CUpgrades_GrantOrRemoveAllUpgrades,
		"_ZN9CUpgrades24GrantOrRemoveAllUpgradesEP9CTFPlayerbb");
	SYMBOL_FUNC(CUpgrades_InputDisable,
		"_ZN9CUpgrades12InputDisableER11inputdata_t");
	SYMBOL_FUNC(CUpgrades_InputEnable,
		"_ZN9CUpgrades11InputEnableER11inputdata_t");
	SYMBOL_FUNC(CUpgrades_InputReset,
		"_ZN9CUpgrades10InputResetER11inputdata_t");
	SYMBOL_FUNC(CUpgrades_NotifyItemOnUpgrade,
		"_ZN9CUpgrades19NotifyItemOnUpgradeEP9CTFPlayertb");
	SYMBOL_FUNC(CUpgrades_PlayerPurchasingUpgrade,
		"_ZN9CUpgrades23PlayerPurchasingUpgradeEP9CTFPlayeriibbb");
	SYMBOL_FUNC(CUpgrades_ReportUpgrade,
		"_ZN9CUpgrades13ReportUpgradeEP9CTFPlayeriiiibbb");
	SYMBOL_FUNC(CUpgrades_RestoreItemAttributeToBaseValue,
		"_ZN9CUpgrades31RestoreItemAttributeToBaseValueEP28CEconItemAttributeDefinitionP13CEconItemView");
	SYMBOL_FUNC(CUpgrades_RestorePlayerAttributeToBaseValue,
		"_ZN9CUpgrades33RestorePlayerAttributeToBaseValueEP28CEconItemAttributeDefinitionP9CTFPlayer");
	SYMBOL_FUNC(CUpgrades_UpgradeTouch,
		"_ZN9CUpgrades12UpgradeTouchEP11CBaseEntity");
	
	SYMBOL_FUNC(CMannVsMachineUpgradeManager_GetAttributeIndexByName,
		"_ZN28CMannVsMachineUpgradeManager23GetAttributeIndexByNameEPKc");
	
	SYMBOL_FUNC(CTFBotLocomotion_Jump,
		"_ZN16CTFBotLocomotion4JumpEv");
	SYMBOL_FUNC(CTFBotLocomotion_GetRunSpeed,
		"_ZNK16CTFBotLocomotion11GetRunSpeedEv");
	
	SYMBOL_FUNC(CTFBotMainAction_GetName,
		"_ZNK16CTFBotMainAction7GetNameEv");
	SYMBOL_FUNC(CTFBotMainAction_OnContact,
		"_ZN16CTFBotMainAction9OnContactEP6CTFBotP11CBaseEntityP10CGameTrace");
	SYMBOL_FUNC(CTFBotMainAction_Update,
		"_ZN16CTFBotMainAction6UpdateEP6CTFBotf");
	
	SYMBOL_FUNC(CTFBotScenarioMonitor_DesiredScenarioAndClassAction,
		"_ZN21CTFBotScenarioMonitor29DesiredScenarioAndClassActionEP6CTFBot");
	
	SYMBOL_FUNC(CTFBotTacticalMonitor_Update,
		"_ZN21CTFBotTacticalMonitor6UpdateEP6CTFBotf");
	
	SYMBOL_FUNC(CTFBotMedicHeal_IsReadyToDeployUber,
		"_ZNK15CTFBotMedicHeal19IsReadyToDeployUberEPK14CWeaponMedigun");
	SYMBOL_FUNC(CTFBotMedicHeal_Update,
		"_ZN15CTFBotMedicHeal6UpdateEP6CTFBotf");
	
	SYMBOL_FUNC(CTFBotMvMEngineerIdle_Update,
		"_ZN21CTFBotMvMEngineerIdle6UpdateEP6CTFBotf");
	
	SYMBOL_FUNC(CTFBotMvMEngineerBuildSentryGun_Update,
		"_ZN31CTFBotMvMEngineerBuildSentryGun6UpdateEP6CTFBotf");
	
	SYMBOL_FUNC(CTFBotMvMEngineerBuildTeleportExit_Update,
		"_ZN34CTFBotMvMEngineerBuildTeleportExit6UpdateEP6CTFBotf");
	
	SYMBOL_FUNC(CTFBotMissionSuicideBomber_Detonate,
		"_ZN26CTFBotMissionSuicideBomber8DetonateEP6CTFBot");
	SYMBOL_FUNC(CTFBotMissionSuicideBomber_OnStart,
		"_ZN26CTFBotMissionSuicideBomber7OnStartEP6CTFBotP6ActionIS0_E");
	
	SYMBOL_FUNC(INextBotComponent_GetBot,
		"_ZNK17INextBotComponent6GetBotEv");
	
	SYMBOL_FUNC(IBody_AimHeadTowards_ent,
		"_ZN5IBody14AimHeadTowardsEP11CBaseEntityNS_18LookAtPriorityTypeEfP13INextBotReplyPKc");
	SYMBOL_FUNC(IBody_AimHeadTowards_vec,
		"_ZN5IBody14AimHeadTowardsERK6VectorNS_18LookAtPriorityTypeEfP13INextBotReplyPKc");
	
	SYMBOL_FUNC(PlayerBody_AimHeadTowards_ent,
		"_ZN10PlayerBody14AimHeadTowardsEP11CBaseEntityN5IBody18LookAtPriorityTypeEfP13INextBotReplyPKc");
	SYMBOL_FUNC(PlayerBody_AimHeadTowards_vec,
		"_ZN10PlayerBody14AimHeadTowardsERK6VectorN5IBody18LookAtPriorityTypeEfP13INextBotReplyPKc");
	
	SYMBOL_FUNC(CTFReviveMarker_AddMarkerHealth,
		"_ZN15CTFReviveMarker15AddMarkerHealthEf");
	
	SYMBOL_FUNC(CTFPowerup_ValidTouch,
		"_ZN10CTFPowerup10ValidTouchEP11CBasePlayer");
	
	SYMBOL_FUNC(CCurrencyPack_ComeToRest,
		"_ZN13CCurrencyPack10ComeToRestEv");
	SYMBOL_FUNC(CCurrencyPack_MyTouch,
		"_ZN13CCurrencyPack7MyTouchEP11CBasePlayer");
	
	SYMBOL_FUNC(CFuncNavCost_HasTag,
		"_ZNK12CFuncNavCost6HasTagEPKc");
	SYMBOL_FUNC(CFuncNavCost_IsApplicableTo,
		"_ZNK12CFuncNavCost14IsApplicableToEP20CBaseCombatCharacter");
	
	SYMBOL_FUNC(Action_CTFBot_OnContact,
		"_ZN6ActionI6CTFBotE9OnContactEP11CBaseEntityP10CGameTrace");
	
	SYMBOL_FUNC(CTraceFilterObject_ShouldHitEntity,
		"_ZN18CTraceFilterObject15ShouldHitEntityEP13IHandleEntityi");
	
	SYMBOL_FUNC(CSoundEmitterSystemBase_AddSoundOverrides,
		"_ZN23CSoundEmitterSystemBase17AddSoundOverridesEPKcb");
	
	SYMBOL_FUNC(CEngineTrace_ClipRayToEntity,
		"_ZN12CEngineTrace15ClipRayToEntityERK5Ray_tjP13IHandleEntityP10CGameTrace");
	SYMBOL_FUNC(CEngineTrace_GetPointContents_Collideable,
		"_ZN12CEngineTrace28GetPointContents_CollideableEP12ICollideableRK6Vector");
	SYMBOL_FUNC(CEngineTrace_TraceRay,
		"_ZN12CEngineTrace8TraceRayERK5Ray_tjP12ITraceFilterP10CGameTrace");
	
	SYMBOL_FUNC(CBulletPenetrateEnum_EnumEntity,
		"_ZN20CBulletPenetrateEnum10EnumEntityEP13IHandleEntity");
	
	SYMBOL_FUNC(CAttributeManager_ApplyAttributeFloatWrapper,
		"_ZN17CAttributeManager26ApplyAttributeFloatWrapperEfP11CBaseEntity8string_tP10CUtlVectorIS1_10CUtlMemoryIS1_iEE");
	
	SYMBOL_FUNC(CAttributeList_SetRuntimeAttributeValue,
		"_ZN14CAttributeList24SetRuntimeAttributeValueEPK28CEconItemAttributeDefinitionf");
	
	SYMBOL_FUNC(CCollisionProperty_SetSolid,
		"_ZN18CCollisionProperty8SetSolidE11SolidType_t");
}
