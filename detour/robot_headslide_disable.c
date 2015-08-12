#include "all.h"


DETOUR(robot_headslide_disable);
/* remove the push force imparted on you when standing on a robot's head */


static unknown_t (*trampoline_CTFPlayer_ApplyAbsVelocityImpulse)(CTFPlayer* this, Vector const*);


static unknown_t detour_CTFPlayer_ApplyAbsVelocityImpulse(CTFPlayer* this, Vector const* vec)
{
	uintptr_t caller = (uintptr_t)__builtin_extract_return_addr(
		__builtin_return_address(0));
	uintptr_t caller_frame = (uintptr_t)__builtin_frame_address(1);
	
	/* CTFPlayer::TFPlayerThink only calls this function for MvM robot head
	 * sliding purposes, so we can safely ignore its calls */
	if (func_owns_addr(CTFPlayer_TFPlayerThink, caller)) {
		return 0;
	}
	
	return trampoline_CTFPlayer_ApplyAbsVelocityImpulse(this, vec);
}


DETOUR_SETUP
{
	DETOUR_CREATE(CTFPlayer_ApplyAbsVelocityImpulse);
}