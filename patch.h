#ifndef _LIBTF2MOD_PATCH_H
#define _LIBTF2MOD_PATCH_H


#define PATCH_CHECK \
	static bool patch_check(void)
#define PATCH_APPLY \
	static void patch_apply(void)

#define PATCH(_name) \
	PATCH_CHECK; \
	PATCH_APPLY; \
	patch_info_t patch_ ## _name = { \
		.name  = #_name, \
		.check = &patch_check, \
		.apply = &patch_apply, \
	};


typedef struct {
	const char *name;
	
	bool (*check)(void);
	void (*apply)(void);
	
	bool ok;
} patch_info_t;


void patch_all(void);

void func_read(void *pfunc, size_t off, size_t len, void *dst);
bool func_verify(void *pfunc, size_t off, size_t len, const void *cmp);
bool func_verify_quiet(void *pfunc, size_t off, size_t len, const void *cmp);

void func_write(void *pfunc, size_t off, size_t len, const void *src);
void func_write_nop(void *pfunc, size_t off, size_t count);

void *alloc_func(size_t pages);

#endif
