#include "all.h"


void tf2mod_init(void)
{
	static bool already_init = false;
	if (already_init) {
		return;
	}
	already_init = true;
	
	
	pr_info("libtf2mod: initializing\n");
	
	
	pr_info("libtf2mod: applying patches\n");
	patch_all();
	
	/* patches MUST be done BEFORE detours to avoid problems! */
	
	pr_info("libtf2mod: enabling detours\n");
	detour_all();
}


/* OVERRIDE: dlopen */
void* dlopen(const char* __file, int __mode)
{
	void* (*real_dlopen)(const char*, int) = dlsym(RTLD_NEXT, "dlopen");
	void* handle = (*real_dlopen)(__file, __mode);
	
	lib_hook(__file, handle);
	
	return handle;
}
