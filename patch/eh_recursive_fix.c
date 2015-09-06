#include "all.h"


PATCH(eh_recursive_fix);
/* check for bleed damage and disallow it from causing explosive headshots */


PATCH_CHECK
{
	size_t check1_base = 0x10d6;
	uint8_t check1[] = {
		0x83, 0xf8, 0x33,                   // +10D6  cmp eax,0x33
		0x0f, 0x85, 0xf5, 0x08, 0x00, 0x00, // +10D9  jne +0x8f5
	};
	
	size_t check2_base = 0x19d4;
	uint8_t check2[] = {
		0x83, 0xf8, 0x01,                         // +19D4  cmp eax,0x1
		0x0f, 0x84, 0x02, 0xf7, 0xff, 0xff,       // +19D7  je -0x8fe
		0x8b, 0xb5, 0x44, 0xff, 0xff, 0xff,       // +19DB  mov esi,DWORD PTR [ebp-0xbc]
		0x85, 0xf6,                               // +19E3  test esi,esi
		0x0f, 0x84, 0x0a, 0xeb, 0xff, 0xff,       // +19E5  je -0x14f6
		0x83, 0xbb, 0xa8, 0x06, 0x00, 0x00, 0x01, // +19EB  cmp DWORD PTR [ebx+0x6a8],0x1
		0x0f, 0x85, 0xfd, 0xea, 0xff, 0xff,       // +19F2  jne -0x1503
		0xe9, 0xe2, 0xf6, 0xff, 0xff,             // +19F8  jmp -0x91e
	};
	
	
	bool result = true;
	if (!func_verify(CTFPlayer_OnTakeDamage_Alive,
		check1_base, sizeof(check1), check1)) result = false;
	if (!func_verify(CTFPlayer_OnTakeDamage_Alive,
		check2_base, sizeof(check2), check2)) result = false;
	return result;
}


PATCH_APPLY
{
	void *new_func = alloc_func(1);
	
	
	uintptr_t off1 = CALC_RELJMP(CTFPlayer_OnTakeDamage_Alive, 0x10db,
		new_func);
	
	
	size_t data1_base = 0x10d6;
	uint8_t data1[] = {
		0xe9, CONV_LE(off1)     // jmp new_func
		0x90, 0x90, 0x90, 0x90, // nop x 4
	};
	
	
	uintptr_t dest_bad  = (uintptr_t)CTFPlayer_OnTakeDamage_Alive + 0x04f5;
	uintptr_t dest_good = (uintptr_t)CTFPlayer_OnTakeDamage_Alive + 0x10df;
	
	uintptr_t off2 = dest_bad  - ((uintptr_t)new_func + 0x0009);
	uintptr_t off3 = dest_good - ((uintptr_t)new_func + 0x0012);
	uintptr_t off4 = dest_good - ((uintptr_t)new_func + 0x001b);
	uintptr_t off5 = dest_bad  - ((uintptr_t)new_func + 0x0029);
	uintptr_t off6 = dest_bad  - ((uintptr_t)new_func + 0x0036);
	uintptr_t off7 = dest_good - ((uintptr_t)new_func + 0x003b);
	
	
	/* add a test for m_iDamageCustom == 0x22 (bleed) */
	size_t data2_base = 0x0000;
	uint8_t data2[] = {
		0x83, 0xf8, 0x22,                         // +0000  cmp eax,0x22
		0x0f, 0x84, CONV_LE(off2)                 // +0003  je BAD
		0x83, 0xf8, 0x33,                         // +0009  cmp eax,0x33
		0x0f, 0x84, CONV_LE(off3)                 // +000c  je GOOD
		0x83, 0xf8, 0x01,                         // +0012  cmp eax,0x01
		0x0f, 0x84, CONV_LE(off4)                 // +0015  je GOOD
		0x8b, 0x85, 0x44, 0xff, 0xff, 0xff,       // +001b  mov eax,DWORD PTR [ebp-0xbc]
		0x85, 0xc0,                               // +0021  test eax,eax
		0x0f, 0x84, CONV_LE(off5)                 // +0023  je BAD
		0x83, 0xbb, 0xa8, 0x06, 0x00, 0x00, 0x01, // +0029  cmp DWORD PTR [ebx+0x6a8],0x1
		0x0f, 0x85, CONV_LE(off6)                 // +0030  jne BAD
		0xe9, CONV_LE(off7)                       // +0036  jmp GOOD
	};
	
	
	/* modify the original function to jump to our new function */
	func_write(CTFPlayer_OnTakeDamage_Alive,
		data1_base, sizeof(data1), data1);
	
	
	/* write the contents of the new function */
	memcpy(new_func, data2, sizeof(data2));
}
