#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"

DWORD cSendSmall = 0x0057B990;
DWORD cStopFuncAddr = 0x004B58F2;
DWORD cSmallReturn = 0x004B58E5;
DWORD cSmallReturn2 = 0x004B58B7;
_declspec(naked) void cSmallIcon()
{
	_asm {
		cmp byte ptr[small_icon_cmd], 1
		jne originalcode

		push eax
		mov eax, 0x004D7450
		cmp [esp + 0x24], eax
		je isSmall
		mov eax,0x00900000
		cmp [esp+ 0x024],eax
		jg isSmall
		mov eax,0x00401000
		cmp[esp + 0x024], eax
		jb isSmall
		pop eax

		jmp originalcode

		isSmall:
		pop eax

		push 0x11
		push 0x11
		push esi
		push ebp
		push ecx
		lea ecx, [edi + 0x0090CE10]
		call cSendSmall
		cmp ebx, 0x64
		jmp cStopFunc
		push ebx
		push 0x0074E61C
		push 00
		push 00
		push 0x000000FF
		push 0x000000FF
		add esi, 4
		push esi
		add ebp, 1
		push ebp
		jmp cSmallReturn


		cStopFunc :
		jmp cStopFuncAddr

		originalcode:
		push 0x20
		push 0x20
		push esi
		jmp cSmallReturn2
	}
}

DWORD cStackReturn = 0x004D74ED;
_declspec(naked) void cStack()
{
	_asm {
		cmp byte ptr ds : [small_icon_cmd] , 0x1
		jne originalcode

		add edi, 0x15
		cmp eax, 0x07
		jmp cStackReturn

		originalcode :
		add edi, 0x28
		cmp eax, 0x07
		jmp cStackReturn
	}
}

DWORD cWhiteReturn = 0x004D74D8;
_declspec(naked) void cWhiteSmall() {
	_asm {
		cmp byte ptr ds : [small_icon_cmd] , 0x1
		jne originalcode

		push 0x11
		push 0x11
		push edx
		jmp cWhiteReturn

		originalcode :
		push 0x20
		push 0x20
		push edx
		jmp cWhiteReturn
	}
}

DWORD cAjustTimeReturn = 0x004B6C38;
_declspec(naked) void cAjustTime()
{
	_asm {
		cmp byte ptr ds : [small_icon_cmd] , 0x1
		jne originalcode
		fmul qword ptr ss : [0x748438]
		jmp cAjustTimeReturn

		originalcode :
		fmul qword ptr ss : [0x007480D0]
		jmp cAjustTimeReturn
	}
}
DWORD cAjustTime2Return = 0x004B6BF3;
_declspec(naked) void cAjustTime2()
{
	_asm {
		cmp byte ptr ds : [small_icon_cmd] , 0x1
		jne originalcode
		push 0x03
		push 0x11
		add esi, 0x11
		jmp cAjustTime2Return
		originalcode :
		push 0x03
		push 0x20
		add esi, 0x20
		jmp cAjustTime2Return
	}
}
DWORD cAjustMenssageReturn = 0x004D74AB;
_declspec(naked) void cAjustMenssage()
{
	_asm {
		cmp byte ptr ds : [small_icon_cmd] , 0x1
		jne originalcode
		add eax, 0x11
		cmp dword ptr ds : [0x7C3C10] , eax
		jmp cAjustMenssageReturn

		originalcode :
		add eax, 0x20
		cmp dword ptr ds : [0x7C3C10] , eax
		jmp cAjustMenssageReturn
	}
}

void hook::isSmallIcon() {
	util::detour((void*)0x004B58B2, cSmallIcon, 5);
	util::detour((void*)0x004D74E7, cStack, 6);
	util::detour((void*)0x004D74D3, cWhiteSmall, 5);
	util::detour((void*)0x004B6C32, cAjustTime, 6);
	util::detour((void*)0x004B6BEC, cAjustTime2, 7);
	util::detour((void*)0x004D74A2, cAjustMenssage, 9);
}