#ifndef _LIBTF2MOD_DETOUR_H
#define _LIBTF2MOD_DETOUR_H


#define DETOUR_SETUP \
	static bool detour_setup(void)

#define DETOUR(_name) \
	DETOUR_SETUP; \
	detour_info_t detour_ ## _name = { \
		.name  = #_name, \
		.setup = &detour_setup, \
	};

#define DETOUR_CREATE(_func) \
	trampoline_ ## _func = func_detour(_func, detour_ ## _func)


typedef struct {
	const char *name;
	
	bool (*setup)(void);
	
	bool ok;
} detour_info_t;


void detour_all(void);

func_t *func_register(void *pfunc);

void *func_detour(void *pfunc, void *detour);
//void func_detour_enable(func_t *func, void *detour);
//void func_detour_disable(func_t *func, void *detour);


static inline bool func_owns_addr(uintptr_t addr, const func_t *func)
{
	uintptr_t addr_begin = func->func_addr;
	uintptr_t addr_end   = func->func_addr + func->func_size;
	
	return (addr >= addr_begin && addr < addr_end);
}


extern detour_info_t detour_init;

#endif
