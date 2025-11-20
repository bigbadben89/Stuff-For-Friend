#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"

DWORD x10Return = 0x00528DB0;
_declspec(naked) void x10stats()

{
	_asm {
		pushad
		push 0x10
		call GetAsyncKeyState
		shr ax, 0xF
		cmp ax, 0x1
		popad
		jne x10original
		add dword ptr ds : [esi + 0x4C] , 0x0A
		jmp x10Return


		x10original :
		inc[esi + 0x4C]
			mov ecx, 0x0000FFFF
			jmp x10Return





	}


}



DWORD x10Return2 = 0x00528DA6;

DWORD x10Block = 0x00528DBF;
_declspec(naked) void x10stats2()

{
	_asm {
		pushad
		push 0x10
		call GetAsyncKeyState
		shr ax, 0xF
		cmp ax, 0x1
		popad
		jne x10original2
		cmp word ptr ds : [esi + eax * 0x2 + 0x34] , 0x0A
		jna block

		x10original2 :
		cmp word ptr ds : [esi + eax * 0x2 + 0x34] , 0x0
			jmp x10Return2


			block :
		jmp x10Block


	}


}



DWORD x10Return3 = 0x00528DB5;

_declspec(naked) void x10stats3()

{
	_asm {
		pushad
		push 0x10
		call GetAsyncKeyState
		shr ax, 0xF
		cmp ax, 0x1
		popad
		jne x10Originalcode3
		sub dword ptr ds : [esi + eax * 0x2 + 0x34] , 0x0A
		jmp x10Return3

		x10Originalcode3 :
		add[esi + eax * 0x2 + 0x34], cx
			jmp x10Return3


	}


}


DWORD x10block2 = 0x00528DBF;
DWORD dwx10return = 0x00528D96;
_declspec(naked) void dwX10Stat()

{

	_asm
	{

		pushad
		push 0x10
		call GetAsyncKeyState
		shr ax, 0xF
		cmp ax, 0x1
		popad
		jne originalcode22
		mov ecx, [esi + 0x4C]
		sub ecx, 0x0A
		test ecx, ecx
		jle x10block22
		add word ptr ds : [esi + eax * 0x2 + 0x40] , 0x0A
		jmp originalcode22


		originalcode22 :
		dec ecx
			mov[esi + 0x4C], ecx
			inc word ptr ds : [esi + eax * 0x2 + 0x40]
			jmp dwx10return

			x10block22 :
		jmp x10block2




	}

}

void hook::Shiftx10() {
	util::detour((void*)0x00528D8D, dwX10Stat, 9);
	util::detour((void*)0x00528DB0, x10stats3, 5);
	util::detour((void*)0x00528DA0, x10stats2, 6);
	util::detour((void*)0x00528DA8, x10stats, 8);
}