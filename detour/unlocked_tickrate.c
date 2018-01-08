#include "all.h"


DETOUR(unlocked_tickrate);
/*
*/


static float (*trampoline_CServerGameDLL_GetTickInterval)();


static float detour_CServerGameDLL_GetTickInterval()
{
	return 0.008;
}


DETOUR_SETUP
{
	DETOUR_CREATE(CServerGameDLL_GetTickInterval);
	
	return true;
}
