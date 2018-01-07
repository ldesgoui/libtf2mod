#include "all.h"


DETOUR(get_tick_interval);
/*
*/


static float (*trampoline_CServerGameDLL_GetTickInterval)();


static float detour_CServerGameDLL_GetTickInterval()
{
	return 1.0/128.0;
}


DETOUR_SETUP
{
	DETOUR_CREATE(CServerGameDLL_GetTickInterval);
	
	return true;
}
