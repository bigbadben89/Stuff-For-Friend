#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"

DWORD fps_boostjmp = 0x580D36;

DWORD fps_boostjejmp = 0x580DCE;

_declspec(naked) void fpsboost() {

	_asm {

		cmp byte ptr ds : [fpsboost_cmd] , 01
		je fps_boostjejmps
		push ebx
		mov ebx, 0x007B19B0

		jmp fps_boostjmp

		fps_boostjejmps :
		jmp fps_boostjejmp


	}
}

void hook::FpsBoost() {
	util::detour((void*)0x580D30, fpsboost, 6);
}