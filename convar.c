#include "all.h"


static ConCommand cmd;


static void callback_command(CCommand const* args)
{
	// TODO
}


void convar_init(void)
{
	ConCommand_ctor(&cmd, "ptf", &callback_command,
		NULL, 0, NULL);
}
