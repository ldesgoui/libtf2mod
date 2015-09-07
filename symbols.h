#ifndef _LIBTF2MOD_SYMBOLS_H
#define _LIBTF2MOD_SYMBOLS_H


#ifdef _LIBTF2MOD_SYMBOLS_C
#define extern
#endif


void symbols_init(void);


/* RTTI */

extern void *typeinfo_for_CBaseEntity;
extern void *typeinfo_for_CBaseObject;
extern void *typeinfo_for_CTFWeaponBase;
extern void *typeinfo_for_CWeaponMedigun;
extern void *typeinfo_for_CTFCrossbow;


/* globals */

extern CGlobalVars **gpGlobals;

extern CGameEventManager **gameeventmanager;

extern CTFGameRules **g_pGameRules;

extern CTFGameStats *CTF_GameStats;

extern CTFObjectiveResource **g_pObjectiveResource;

extern ConVar **CONVAR_mp_restartgame;


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

extern CBaseEntity* (*UTIL_EntityByIndex)(int);
extern unknown_t (*UTIL_LogPrintf)(char const*, ...);
extern CBasePlayer* (*UTIL_PlayerByIndex)(int);
extern void (*UTIL_ScreenShake)(Vector const*, float, float, float, float, ShakeCommand_t, bool);

extern char const* (*TranslateWeaponEntForClass)(char const*, int);

extern bool (*WeaponID_IsSniperRifle)(int);
extern bool (*WeaponID_IsSniperRifleOrBow)(int);

extern unknown_t (*FX_FireBullets)(CTFWeaponBase*, int, Vector const*, QAngle const*, int, int, int, float, float, bool);


/* functions: static */

extern void (*CBaseEntity_PrecacheScriptSound)(char const*);

extern datamap_t* (*CBaseObject_GetDataDescMap)(void);
extern datamap_t* (*CObjectSentrygun_GetDataDescMap)(void);

extern CTFMedigunShield* (*CTFMedigunShield_Create)(CTFPlayer*);

extern CEconItemView* (*CTFPlayerSharedUtils_GetEconItemViewByLoadoutSlot)(CTFPlayer*, int, CEconEntity**);

extern int (*CAttributeManager_AttribHookValue_int)(int, char const*, CBaseEntity const*, CUtlVector*, bool);


/* functions: member */

extern unknown_t (*CServerGameDLL_DLLInit)(CServerGameDLL* this, void* (*)(char const*, int*), void* (*)(char const*, int*), void* (*)(char const*, int*), CGlobalVars*);

extern void (*ConVar_SetValue_int)(ConVar* this, int);

extern void (*ConCommand_ctor)(ConCommand* this, char const*, void (*)(CCommand const*), char const*, int, int (*)(char const*, char (*) [64]));

extern IGameEvent* (*CGameEventManager_CreateEvent)(CGameEventManager* this, char const*, bool);
extern bool (*CGameEventManager_FireEvent)(CGameEventManager* this, IGameEvent*, bool);

extern void (*CBaseEntity_ApplyAbsVelocityImpulse)(CBaseEntity* this, Vector const*);
extern int (*CBaseEntity_GetMaxHealth)(CBaseEntity* this);
extern int (*CBaseEntity_GetTeamNumber)(CBaseEntity* this);
extern bool (*CBaseEntity_IsBaseObject)(CBaseEntity* this);
extern unknown_t (*CBaseEntity_NetworkStateChanged)(CBaseEntity* this, void*);

extern void (*CBaseAnimating_SetModelScale)(CBaseAnimating* this, float, float);

extern unknown_t (*CBasePlayer_GiveNamedItem)(CBasePlayer* this, char const*, int);
extern bool (*CBasePlayer_IsBot)(CBasePlayer* this);

extern void (*CTFPlayerShared_AddCond)(CTFPlayerShared* this, ETFCond, float, CBaseEntity*);
extern bool (*CTFPlayerShared_IsInvulnerable)(CTFPlayerShared* this);
extern void (*CTFPlayerShared_RadiusCurrencyCollectionCheck)(CTFPlayerShared* this);

extern unknown_t (*CTFPlayer_ApplyAbsVelocityImpulse)(CTFPlayer* this, Vector const*);
extern unknown_t (*CTFPlayer_ApplyAirBlastImpulse)(CTFPlayer* this, Vector const*);
extern bool (*CTFPlayer_CanBeForcedToLaugh)(CTFPlayer* this);
extern int (*CTFPlayer_CanBuild)(CTFPlayer* this, int, int);
extern bool (*CTFPlayer_CanHearAndReadChatFrom)(CTFPlayer* this, CBasePlayer*);
extern bool (*CTFPlayer_CanPickupBuilding)(CTFPlayer* this, CBaseObject*);
extern void (*CTFPlayer_CreateRagdollEntity)(CTFPlayer* this, bool, bool, bool, bool, bool, bool, bool, bool, int, bool);
extern void (*CTFPlayer_DeathSound)(CTFPlayer* this, CTakeDamageInfo const*);
extern void (*CTFPlayer_Event_Killed)(CTFPlayer* this, CTakeDamageInfo const*);
extern unknown_t (*CTFPlayer_FireBullet)(CTFPlayer* this, CTFWeaponBase*, FireBulletsInfo_t const*, bool, int, int);
extern unknown_t (*CTFPlayer_GiveNamedItem)(CTFPlayer* this, char const*, int, CEconItemView const*, bool);
extern bool (*CTFPlayer_IsMiniBoss)(CTFPlayer* this);
extern bool (*CTFPlayer_IsPlayerClass)(CTFPlayer* this, int);
extern unknown_t (*CTFPlayer_OnTakeDamage)(CTFPlayer* this, CTakeDamageInfo const*);
extern unknown_t (*CTFPlayer_OnTakeDamage_Alive)(CTFPlayer* this, CTakeDamageInfo const*);
extern void (*CTFPlayer_Regenerate)(CTFPlayer* this, bool);
extern void (*CTFPlayer_RememberUpgrade)(CTFPlayer* this, int, CEconItemView*, int, int, bool);
extern void (*CTFPlayer_RemoveCurrency)(CTFPlayer* this, int);
extern void (*CTFPlayer_RemoveDisguise)(CTFPlayer* this);
extern bool (*CTFPlayer_ShouldGib)(CTFPlayer* this, CTakeDamageInfo const*);
extern unknown_t (*CTFPlayer_TFPlayerThink)(CTFPlayer* this);
extern unknown_t (*CTFPlayer_TraceAttack)(CTFPlayer* this, CTakeDamageInfo const*, Vector const*, CGameTrace*, CDmgAccumulator*);

extern void (*CTFBot_AddItem)(CTFBot* this, char const*);
extern bool (*CTFBot_EquipRequiredWeapon)(CTFBot* this);
extern bool (*CTFBot_ShouldGib)(CTFBot* this, CTakeDamageInfo const*);

extern bool (*NextBotPlayer_CTFPlayer_IsBot)(NextBotPlayer_CTFPlayer* this);

extern void (*CTFTankBoss_TankBossThink)(CTFTankBoss* this);

extern CEconItemAttributeDefinition* (*CEconItemSchema_GetAttributeDefinitionByName)(CEconItemSchema* this, char const*);

extern int (*CEconItemView_GetItemDefIndex)(CEconItemView* this);

extern void (*CSchemaFieldHandle_CEconItemDefinition_ctor)(CSchemaFieldHandle_CEconItemDefinition* this, char const*);

extern unknown_t (*CItemGeneration_GenerateRandomItem)(CItemGeneration* this, CItemSelectionCriteria*, Vector const*, QAngle const*);
extern unknown_t (*CItemGeneration_SpawnItem)(CItemGeneration* this, int, Vector const*, QAngle const*, int, int, char const*);

extern bool (*CTFWeaponBase_AreRandomCritsEnabled)(CTFWeaponBase* this);
extern bool (*CTFWeaponBase_CalcIsAttackCritical)(CTFWeaponBase* this);
extern bool (*CTFWeaponBase_CalcIsAttackCriticalHelper)(CTFWeaponBase* this);
extern bool (*CTFWeaponBase_CalcIsAttackCriticalHelperNoCrits)(CTFWeaponBase* this);
extern bool (*CTFWeaponBase_CanBeCritBoosted)(CTFWeaponBase* this);
extern bool (*CTFWeaponBase_CanFireCriticalShot)(CTFWeaponBase* this, bool);
extern bool (*CTFWeaponBase_CanFireRandomCriticalShot)(CTFWeaponBase* this, float);
extern int (*CTFWeaponBase_GetWeaponID)(CTFWeaponBase* this);

extern int (*CTFWeaponBaseGun_GetWeaponProjectileType)(CTFWeaponBaseGun* this);
extern void (*CTFWeaponBaseGun_PrimaryAttack)(CTFWeaponBaseGun* this);

extern float (*CWeaponMedigun_GetTargetRange)(CWeaponMedigun* this);
extern bool (*CWeaponMedigun_IsAttachedToBuilding)(CWeaponMedigun* this);

extern void (*CTFRocketLauncher_Precache)(CTFRocketLauncher* this);

extern bool (*CTFSniperRifle_CanFireCriticalShot)(CTFSniperRifle*, bool);
extern void (*CTFSniperRifle_ExplosiveHeadShot)(CTFSniperRifle* this, CTFPlayer*, CTFPlayer*);
extern void (*CTFSniperRifle_ItemPostFrame)(CTFSniperRifle* this);
extern void (*CTFSniperRifleClassic_ItemPostFrame)(CTFSniperRifleClassic* this);
extern float (*CTFSniperRifleDecap_SniperRifleChargeRateMod)(CTFSniperRifleDecap* this);

extern void (*CTFKnife_DisguiseOnKill)(CTFKnife* this);
extern void (*CTFKnife_PrimaryAttack)(CTFKnife* this);

extern unknown_t (*CTFProjectile_Arrow_StrikeTarget_clone321)(CTFProjectile_Arrow* this, mstudiobbox_t*, CBaseEntity*);
extern unknown_t (*CTFProjectile_Flare_Explode)(CTFProjectile_Flare* this, CGameTrace*, CBaseEntity*);

extern void (*CBaseObject_DoQuickBuild)(CBaseObject* this);
extern int (*CBaseObject_GetMaxHealthForCurrentLevel)(CBaseObject* this);
extern float (*CBaseObject_GetReversesBuildingConstructionSpeed)(CBaseObject* this);
extern CObjectSapper* (*CBaseObject_GetSapper)(CBaseObject* this);
extern int (*CBaseObject_GetType)(CBaseObject* this);
extern void (*CBaseObject_MakeDisposableBuilding)(CBaseObject* this, CTFPlayer*);
extern void (*CBaseObject_SetHealth)(CBaseObject* this, float);
extern bool (*CBaseObject_ShouldBeMiniBuilding)(CBaseObject* this, CTFPlayer*);

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

extern void (*CObjectTeleporter_FinishedBuilding)(CObjectTeleporter* this);

extern void (*CTFGameRules_BetweenRounds_Think)(CTFGameRules* this);
extern bool (*CTFGameRules_CanUpgradeWithAttrib)(CTFGameRules* this, CTFPlayer*, int, unsigned short, CMannVsMachineUpgrades*);
extern unknown_t (*CTFGameRules_DistributeCurrencyAmount)(CTFGameRules* this, int, CTFPlayer*, bool, bool, bool);
extern bool (*CTFGameRules_GameModeUsesUpgrades)(CTFGameRules* this);
extern int (*CTFGameRules_GetCostForUpgrade)(CTFGameRules* this, CMannVsMachineUpgrades*, int, int, CTFPlayer*);
extern int (*CTFGameRules_GetUpgradeTier)(CTFGameRules* this, int);
extern bool (*CTFGameRules_IsInTraining)(CTFGameRules* this);
extern bool (*CTFGameRules_IsPVEModeActive)(CTFGameRules* this);
extern bool (*CTFGameRules_IsPVEModeControlled)(CTFGameRules* this, CBaseEntity*);
extern bool (*CTFGameRules_IsUpgradeTierEnabled)(CTFGameRules* this, CTFPlayer*, int, int);
extern bool (*CTFGameRules_PlayerReadyStatus_HaveMinPlayersToEnable)(CTFGameRules* this);
extern bool (*CTFGameRules_PlayerReadyStatus_ShouldStartCountdown)(CTFGameRules* this);
extern void (*CTFGameRules_PushAllPlayersAway)(CTFGameRules* this, Vector const*, float, float, int, CUtlVector*);
extern bool (*CTFGameRules_UsePlayerReadyStatusMode)(CTFGameRules* this);

extern bool (*CTeamplayRoundBasedRules_AreLobbyPlayersOnTeamReady)(CTeamplayRoundBasedRules* this, int);
extern void (*CTeamplayRoundBasedRules_CheckReadyRestart)(CTeamplayRoundBasedRules* this);

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

extern unknown_t (*CUpgrades_ApplyUpgradeAttributeBlock)(CUpgrades* this, UpgradeAttribBlock_t, int, CTFPlayer*, bool);
extern unsigned short (*CUpgrades_ApplyUpgradeToItem)(CUpgrades* this, CTFPlayer*, CEconItemView*, int, int, bool, bool);
extern unknown_t (*CUpgrades_EndTouch)(CUpgrades* this, CBaseEntity*);
extern unknown_t (*CUpgrades_FireGameEvent)(CUpgrades* this, IGameEvent*);
extern unknown_t (*CUpgrades_GetUpgradeAttributeName)(CUpgrades* this, int);
extern unknown_t (*CUpgrades_GrantOrRemoveAllUpgrades)(CUpgrades* this, CTFPlayer*, bool, bool);
extern unknown_t (*CUpgrades_InputDisable)(CUpgrades* this, inputdata_t*);
extern unknown_t (*CUpgrades_InputEnable)(CUpgrades* this, inputdata_t*);
extern unknown_t (*CUpgrades_InputReset)(CUpgrades* this, inputdata_t*);
extern void (*CUpgrades_NotifyItemOnUpgrade)(CUpgrades* this, unsigned short, bool);
extern void (*CUpgrades_PlayerPurchasingUpgrade)(CUpgrades* this, CTFPlayer*, int, int, bool, bool, bool);
extern unknown_t (*CUpgrades_ReportUpgrade)(CUpgrades* this, CTFPlayer*, int, int, int, int, bool, bool, bool);
extern unknown_t (*CUpgrades_RestoreItemAttributeToBaseValue)(CUpgrades* this, CEconItemAttributeDefinition*, CEconItemView*);
extern unknown_t (*CUpgrades_RestorePlayerAttributeToBaseValue)(CUpgrades* this, CEconItemAttributeDefinition*, CTFPlayer*);
extern unknown_t (*CUpgrades_UpgradeTouch)(CUpgrades* this, CBaseEntity*);

extern unknown_t (*CTFBotMainAction_OnContact)(CTFBotMainAction* this, CTFBot*, CBaseEntity*, CGameTrace*);
extern unknown_t (*CTFBotMainAction_Update)(CTFBotMainAction* this, CTFBot*, float);

extern bool (*CTFBotMedicHeal_IsReadyToDeployUber)(CTFBotMedicHeal* this, CWeaponMedigun const*);
extern unknown_t (*CTFBotMedicHeal_Update)(CTFBotMedicHeal* this, CTFBot*, float);

extern unknown_t (*CTFBotMvMEngineerIdle_Update)(CTFBotMvMEngineerIdle* this, CTFBot*, float);

extern unknown_t (*CTFReviveMarker_AddMarkerHealth)(CTFReviveMarker* this, float);

extern unknown_t (*CCurrencyPack_ComeToRest)(CCurrencyPack* this);

extern unknown_t (*Action_CTFBot_OnContact)(Action_CTFBot* this, CBaseEntity*, CGameTrace*);


#undef extern


#endif
