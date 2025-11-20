#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"

DWORD sahRet = 0x0040E0BD;
DWORD sahCall = 0x00633B16;
_declspec(naked) void SahEncrypt()
{
	_asm {


		call sahCall
		pushad
		mov esi, ss: [esp + 0x24]
		mov ebx, dword ptr ds : [esi]
		//mov edx,0x0072BBA7
		xor ebx, 0x74
		xor ebx, 0x61
		xor ebx, 0x68
		xor ebx, 0x10
		mov dword ptr ds : [esi] , ebx
		popad
		jmp sahRet

		originalcode :
		call sahCall
			jmp sahRet
	}
}

DWORD SahNameRet = 0x0040E46D;
LPCSTR GetNameSah = "fff";
_declspec(naked) void SahName()
{
	_asm {
		push GetNameSah
		jmp SahNameRet
	}
}


void hook::SahProtect() {
	util::detour((void*)0x0040E468, SahName, 5);
	util::detour((void*)0x0040E0B8, SahEncrypt, 5);
}