#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
DWORD dwRRReturn = 0x004C42C4;
_declspec(naked) void dwRR()
{


	_asm
	{


		add eax, 0x96
		cmp edx, eax
		jmp dwRRReturn


	}

}



DWORD dwRRReturn2 = 0x004C42A4;
_declspec(naked) void dwRR2()
{


	_asm
	{

		add eax, 0x3C
		cmp ecx, eax
		jmp dwRRReturn2



	}

}


DWORD dwRRReturn3 = 0x004C428E;
_declspec(naked) void dwRR3()
{


	_asm
	{

		mov eax, [esi + 0x000024C8]
		add eax, -0x10
		jmp dwRRReturn3


	}

}

void hook::SeeOrangeStatus() {
	util::detour((void*)0x004C4288, dwRR3, 6);
	util::detour((void*)0x004C429F, dwRR2, 5);
	util::detour((void*)0x004C42BF, dwRR, 5);
}