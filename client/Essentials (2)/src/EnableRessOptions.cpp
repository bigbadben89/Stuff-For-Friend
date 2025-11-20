#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"

//DWORD isNotLocalRessAddr = 0x004D5EA0;
//DWORD sendRessLocalAddr = 0x004D5DE1;
//DWORD enable_local_ress_ultimate_mode_return = 0x004D5DC4;
//_declspec(naked) void enable_local_ress_ultimate_mode() {
//	_asm {
//		test eax, eax
//		je sendRessLocal
//
//		cmp eax, 01
//		jne isNotLocalRess
//		jmp enable_local_ress_ultimate_mode_return
//
//		isNotLocalRess :
//		jmp isNotLocalRessAddr
//
//			sendRessLocal :
//		jmp sendRessLocalAddr
//	}
//}



void hook::EnableRessOptions() {
	BYTE Enable_Ress_Leader_2[] = { 0xE9,0x85,0x00,0x00,0x00,0x90 };
	BYTE Enable_Ress_Leader[] = { 0xEB };
	BYTE Enable_Local_Ress[] = { 0x90, 0x90,  0x90,  0x90,  0x90,  0x90 };
	memcpy((void*)0x004D5A03, Enable_Ress_Leader, 1);
	memcpy((void*)0x004D5DDB, Enable_Local_Ress, 6);
	memcpy((void*)0x004D5BB4, Enable_Ress_Leader_2, 6);
	BYTE Enable_Mov_Stone[] = { 0x90,0x90 };
	memcpy((void*)0x004ED146, Enable_Mov_Stone, 2);
	//util::detour((PVOID)0x004D5DBB, enable_local_ress_ultimate_mode, 9);

}
