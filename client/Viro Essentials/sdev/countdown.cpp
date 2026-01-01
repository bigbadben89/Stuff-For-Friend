#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"

DWORD dwRenderTimer = 0x4B62F0;
DWORD dwOriginalRenderText = 0x573A00;

LPCSTR stringFormat = "%d\x00";
LPCSTR stringFormat2 = "0%d\x00";

__declspec(naked) void RenderText() {
	__asm {

		push eax

		cmp eax, 0x09
		jg _label_format1

		push[stringFormat2]
		jmp _label_continue

		_label_format1 :
		push[stringFormat]

			_label_continue :
			push 0x00

			cmp ecx, 0x01
			je _label_shadow

			push 0x80
			push 0xFF
			push 0xFF
			jmp _label_continue2

			_label_shadow :
		push 0x00
			push 0x00
			push 0x00

			_label_continue2 :
			push ebp
			push ebx
			mov ebx, 0x022B69B0
			push ebx
			call dwOriginalRenderText
			add esp, 0x24
			ret
	}
}

__declspec(naked) void Sub60() {
	__asm {
		cmp eax, 60
		jge _label_sub
		ret

		_label_sub :
		sub eax, 60
			jmp Sub60
	}
}

DWORD dwExitCountdownSkill = 0x4FFC0C;

__declspec(naked) void CountdownSkill() {
	__asm {
		cmp dword ptr[esi + 0x10], 0x00
		je _label_original

		pushad
		mov edx, 0x00
		mov eax, [esi + 0x10]
		mov ecx, 1000
		div ecx
		mov edx, 0x00
		mov ecx, 60
		div ecx
		add ebp, 0x08
		add ebx, 0x03
		mov ecx, 0x1
		call RenderText
		popad

		pushad
		mov edx, 0x00
		mov eax, [esi + 0x10]
		mov ecx, 1000
		div ecx
		mov edx, 0x00
		mov ecx, 60
		div ecx
		add ebp, 10
		add ebx, 0x03
		mov ecx, 0x1
		call RenderText
		popad

		pushad
		mov edx, 0x00
		mov eax, [esi + 0x10]
		mov ecx, 1000
		div ecx
		mov edx, 0x00
		mov ecx, 60
		div ecx
		add ebp, 0x09
		add ebx, 0x02
		mov ecx, 0x1
		call RenderText
		popad

		pushad
		mov edx, 0x00
		mov eax, [esi + 0x10]
		mov ecx, 1000
		div ecx
		mov edx, 0x00
		mov ecx, 60
		div ecx
		add ebp, 0x09
		add ebx, 0x04
		mov ecx, 0x1
		call RenderText
		popad

		pushad
		mov edx, 0x00
		mov eax, [esi + 0x10]
		mov ecx, 1000
		div ecx
		mov edx, 0x00
		mov ecx, 60
		div ecx
		add ebp, 0x09
		add ebx, 0x03
		mov ecx, 0x00
		call RenderText
		popad

		pushad
		mov edx, 0x00
		mov eax, [esi + 0x10]
		mov ecx, 1000
		div ecx
		call Sub60
		add ebp, 0x08
		add ebx, 18
		mov ecx, 0x01
		call RenderText
		popad

		pushad
		mov edx, 0x00
		mov eax, [esi + 0x10]
		mov ecx, 1000
		div ecx
		call Sub60
		add ebp, 10
		add ebx, 18
		mov ecx, 0x01
		call RenderText
		popad

		pushad
		mov edx, 0x00
		mov eax, [esi + 0x10]
		mov ecx, 1000
		div ecx
		call Sub60
		add ebp, 0x09
		add ebx, 17
		mov ecx, 0x01
		call RenderText
		popad

		pushad
		mov edx, 0x00
		mov eax, [esi + 0x10]
		mov ecx, 1000
		div ecx
		call Sub60
		add ebp, 0x09
		add ebx, 19
		mov ecx, 0x01
		call RenderText
		popad

		pushad
		mov edx, 0x00
		mov eax, [esi + 0x10]
		mov ecx, 1000
		div ecx
		call Sub60
		add ebp, 0x09
		add ebx, 18
		mov ecx, 0x00
		call RenderText
		popad

		_label_original :
		movzx ecx, word ptr[esi + 0x02]
			mov edx, 0x007C4918
			mov edx, [edx]
			jmp dwExitCountdownSkill
	}
}

DWORD dwCallCountdownInventory1 = 0x46CB30;

DWORD dwExitCountdownInventory = 0x5182ED;

__declspec(naked) void CountdownInventory() {
	__asm {
		pushad
		push ebx
		push edi
		mov ecx, 0x0091AD64
		call dwCallCountdownInventory1
		test eax, eax
		je _label_return
		cmp byte ptr[eax + 0x27], 0x00
		je _label_return

		cmp byte ptr[eax + 0x08], 25
		je _label_continue
		cmp byte ptr[eax + 0x08], 44
		je _label_continue
		cmp byte ptr[eax + 0x08], 100
		je _label_continue

		jmp _label_return

		_label_continue :
		movzx eax, byte ptr[eax + 0x27]
			add eax, eax
			mov eax, [eax + eax + 0x22AADDC]

			cmp eax, 0x00
			je _label_return

			push eax
			mov edx, 00
			mov ecx, 1000
			div ecx
			mov edx, 00
			mov ecx, 60
			div ecx

			push eax
			push ebp
			mov ecx, 1
			mov ebx, ebp
			mov ebp, [esp + 0x3C]
			add ebp, 0x08
			add ebx, 0x03
			call RenderText
			pop ebp
			pop eax

			push eax
			push ebp
			mov ecx, 1
			mov ebx, ebp
			mov ebp, [esp + 0x3C]
			add ebp, 10
			add ebx, 0x03
			call RenderText
			pop ebp
			pop eax

			push eax
			push ebp
			mov ecx, 1
			mov ebx, ebp
			mov ebp, [esp + 0x3C]
			add ebp, 0x09
			add ebx, 0x02
			call RenderText
			pop ebp
			pop eax

			push eax
			push ebp
			mov ecx, 1
			mov ebx, ebp
			mov ebp, [esp + 0x3C]
			add ebp, 0x09
			add ebx, 0x04
			call RenderText
			pop ebp
			pop eax

			push eax
			push ebp
			mov ecx, 0
			mov ebx, ebp
			mov ebp, [esp + 0x3C]
			add ebp, 0x09
			add ebx, 0x03
			call RenderText
			pop ebp
			pop eax
			pop eax

			mov edx, 00
			mov ecx, 1000
			div ecx

			call Sub60

			push eax
			push ebp
			mov ecx, 1
			mov ebx, ebp
			mov ebp, [esp + 0x38]
			add ebp, 0x08
			add ebx, 18
			call RenderText
			pop ebp
			pop eax

			push eax
			push ebp
			mov ecx, 1
			mov ebx, ebp
			mov ebp, [esp + 0x38]
			add ebp, 10
			add ebx, 18
			call RenderText
			pop ebp
			pop eax

			push eax
			push ebp
			mov ecx, 1
			mov ebx, ebp
			mov ebp, [esp + 0x38]
			add ebp, 0x09
			add ebx, 17
			call RenderText
			pop ebp
			pop eax

			push eax
			push ebp
			mov ecx, 1
			mov ebx, ebp
			mov ebp, [esp + 0x38]
			add ebp, 0x09
			add ebx, 19
			call RenderText
			pop ebp
			pop eax

			push eax
			push ebp
			mov ecx, 0
			mov ebx, ebp
			mov ebp, [esp + 0x38]
			add ebp, 0x09
			add ebx, 18
			call RenderText
			pop ebp
			pop eax

			_label_return :
		popad

			_label_original :
		mov eax, 0x007C3C0C
			mov eax, [eax]
			cmp eax, ebp
			jmp dwExitCountdownInventory
	}
}

DWORD dwExitCountdownItemsSkillBar = 0x4FFD79;

__declspec(naked) void CountdownItemsSkillBar() {
	__asm {
		push 0xA0000000
		call dwRenderTimer

		pushad
		push ebx
		push ebp
		mov ecx, 0x0091AD64
		call dwCallCountdownInventory1

		test eax, eax
		je _label_return

		cmp byte ptr[eax + 0x27], 0x00
		je _label_return

		cmp byte ptr[eax + 0x08], 25
		je _label_continue
		cmp byte ptr[eax + 0x08], 44
		je _label_continue
		cmp byte ptr[eax + 0x08], 100
		je _label_continue

		jmp _label_return

		_label_continue :
		movzx eax, byte ptr[eax + 0x27]
			add eax, eax
			mov eax, [eax + eax + 0x22AADDC]

			cmp eax, 00
			je _label_return

			push eax

			mov edx, 00
			mov ecx, 1000
			div ecx
			mov edx, 00
			mov ecx, 60
			div ecx

			push eax
			mov ecx, 1
			mov ebx, [esp + 0x44]
			mov ebp, [esp + 0x40]
			add ebp, 0x08
			add ebx, 0x03
			call RenderText
			pop eax

			push eax
			mov ecx, 1
			mov ebx, [esp + 0x44]
			mov ebp, [esp + 0x40]
			add ebp, 10
			add ebx, 0x03
			call RenderText
			pop eax

			push eax
			mov ecx, 1
			mov ebx, [esp + 0x44]
			mov ebp, [esp + 0x40]
			add ebp, 0x09
			add ebx, 0x02
			call RenderText
			pop eax

			push eax
			mov ecx, 1
			mov ebx, [esp + 0x44]
			mov ebp, [esp + 0x40]
			add ebp, 0x09
			add ebx, 0x04
			call RenderText
			pop eax

			push eax
			mov ecx, 0
			mov ebx, [esp + 0x44]
			mov ebp, [esp + 0x40]
			add ebp, 0x09
			add ebx, 0x03
			call RenderText
			pop eax
			pop eax

			mov edx, 00
			mov ecx, 1000
			div ecx

			call Sub60

			push eax
			mov ecx, 1
			mov ebx, [esp + 0x40]
			mov ebp, [esp + 0x3C]
			add ebp, 0x08
			add ebx, 18
			call RenderText
			pop eax

			push eax
			mov ecx, 1
			mov ebx, [esp + 0x40]
			mov ebp, [esp + 0x3C]
			add ebp, 10
			add ebx, 18
			call RenderText
			pop eax

			push eax
			mov ecx, 1
			mov ebx, [esp + 0x40]
			mov ebp, [esp + 0x3C]
			add ebp, 0x09
			add ebx, 17
			call RenderText
			pop eax

			push eax
			mov ecx, 1
			mov ebx, [esp + 0x40]
			mov ebp, [esp + 0x3C]
			add ebp, 0x09
			add ebx, 19
			call RenderText
			pop eax

			push eax
			mov ecx, 0
			mov ebx, [esp + 0x40]
			mov ebp, [esp + 0x3C]
			add ebp, 0x09
			add ebx, 18
			call RenderText
			pop eax

			_label_return :
		popad

			_label_original :
		jmp dwExitCountdownItemsSkillBar
	}
}

DWORD dwExitCountdownZX = 0x4FCD8F;

__declspec(naked) void CountdownZX() {
	__asm {
		push 0xA0000000
		call dwRenderTimer

		pushad
		mov ecx, [esp + 0x48]
		push ecx
		push ebp
		mov ecx, 0x0091AD64
		call dwCallCountdownInventory1

		test eax, eax
		je _label_return

		cmp byte ptr[eax + 0x27], 0x00
		je _label_return

		cmp byte ptr[eax + 0x08], 25
		je _label_continue
		cmp byte ptr[eax + 0x08], 44
		je _label_continue
		cmp byte ptr[eax + 0x08], 100
		je _label_continue

		jmp _label_return

		_label_continue :
		movzx eax, byte ptr[eax + 0x27]
			add eax, eax
			mov eax, [eax + eax + 0x22AADDC]

			cmp eax, 00
			je _label_return

			push eax

			mov edx, 00
			mov ecx, 1000
			div ecx
			mov edx, 00
			mov ecx, 60
			div ecx

			push eax
			mov ecx, 1
			mov ebx, [esp + 0x40]
			mov ebp, [esp + 0x48]
			add ebp, 0x08
			add ebx, 0x03
			call RenderText
			pop eax

			push eax
			mov ecx, 1
			mov ebx, [esp + 0x40]
			mov ebp, [esp + 0x48]
			add ebp, 10
			add ebx, 0x03
			call RenderText
			pop eax

			push eax
			mov ecx, 1
			mov ebx, [esp + 0x40]
			mov ebp, [esp + 0x48]
			add ebp, 0x09
			add ebx, 0x02
			call RenderText
			pop eax

			push eax
			mov ecx, 1
			mov ebx, [esp + 0x40]
			mov ebp, [esp + 0x48]
			add ebp, 0x09
			add ebx, 0x04
			call RenderText
			pop eax

			push eax
			mov ecx, 0
			mov ebx, [esp + 0x40]
			mov ebp, [esp + 0x48]
			add ebp, 0x09
			add ebx, 0x03
			call RenderText
			pop eax

			pop eax

			mov edx, 00
			mov ecx, 1000
			div ecx

			call Sub60

			push eax
			mov ecx, 1
			mov ebx, [esp + 0x3C]
			mov ebp, [esp + 0x44]
			add ebp, 0x08
			add ebx, 18
			call RenderText
			pop eax

			push eax
			mov ecx, 1
			mov ebx, [esp + 0x3C]
			mov ebp, [esp + 0x44]
			add ebp, 10
			add ebx, 18
			call RenderText
			pop eax

			push eax
			mov ecx, 1
			mov ebx, [esp + 0x3C]
			mov ebp, [esp + 0x44]
			add ebp, 0x09
			add ebx, 17
			call RenderText
			pop eax

			push eax
			mov ecx, 1
			mov ebx, [esp + 0x3C]
			mov ebp, [esp + 0x44]
			add ebp, 0x09
			add ebx, 19
			call RenderText
			pop eax

			push eax
			mov ecx, 0
			mov ebx, [esp + 0x3C]
			mov ebp, [esp + 0x44]
			add ebp, 0x09
			add ebx, 18
			call RenderText
			pop eax

			_label_return :
		popad

			jmp dwExitCountdownZX
	}
}

DWORD dwExitCountdownR = 0x5078CA;

__declspec(naked) void CountdownR() {
	__asm {
		call dwRenderTimer

		pushad
		mov eax, [edi + 0x10]

		cmp eax, 00
		je _label_return

		mov ebp, ebx
		mov ebx, [esp + 0x30]

		mov edx, 00
		mov ecx, 1000
		div ecx

		push eax

		mov edx, 00
		mov ecx, 60
		div ecx

		push eax
		push ebp
		push ebx
		mov ecx, 1
		add ebp, 0x08
		add ebx, 0x03
		call RenderText
		pop ebx
		pop ebp
		pop eax

		push eax
		push ebp
		push ebx
		mov ecx, 1
		add ebp, 10
		add ebx, 0x03
		call RenderText
		pop ebx
		pop ebp
		pop eax

		push eax
		push ebp
		push ebx
		mov ecx, 1
		add ebp, 0x09
		add ebx, 0x02
		call RenderText
		pop ebx
		pop ebp
		pop eax

		push eax
		push ebp
		push ebx
		mov ecx, 1
		add ebp, 0x09
		add ebx, 0x04
		call RenderText
		pop ebx
		pop ebp
		pop eax

		push eax
		push ebp
		push ebx
		mov ecx, 0
		add ebp, 0x09
		add ebx, 0x03
		call RenderText
		pop ebx
		pop ebp
		pop eax
		pop eax

		call Sub60

		push eax
		push ebp
		push ebx
		mov ecx, 1
		add ebp, 0x08
		add ebx, 18
		call RenderText
		pop ebx
		pop ebp
		pop eax

		push eax
		push ebp
		push ebx
		mov ecx, 1
		add ebp, 10
		add ebx, 18
		call RenderText
		pop ebx
		pop ebp
		pop eax

		push eax
		push ebp
		push ebx
		mov ecx, 1
		add ebp, 0x09
		add ebx, 17
		call RenderText
		pop ebx
		pop ebp
		pop eax

		push eax
		push ebp
		push ebx
		mov ecx, 1
		add ebp, 0x09
		add ebx, 19
		call RenderText
		pop ebx
		pop ebp
		pop eax

		push eax
		push ebp
		push ebx
		mov ecx, 0
		add ebp, 0x09
		add ebx, 18
		call RenderText
		pop ebx
		pop ebp
		pop eax

		_label_return :
		popad

			mov eax, [esp + 0x10]
			jmp dwExitCountdownR
	}
}

DWORD dwExitCountdownR2 = 0x507D31;

__declspec(naked) void CountdownR2() {
	__asm {
		push 0xA0000000
		call dwRenderTimer

		pushad
		mov eax, ebx
		mov ebx, ebp
		mov ebp, eax

		mov eax, [edi + 0x10]

		cmp eax, 00
		je _label_return

		mov edx, 00
		mov ecx, 1000
		div ecx

		push eax

		mov edx, 00
		mov ecx, 60
		div ecx

		push eax
		push ebx
		push ebp
		mov ecx, 1
		add ebp, 0x08
		add ebx, 0x03
		call RenderText
		pop ebp
		pop ebx
		pop eax

		push eax
		push ebx
		push ebp
		mov ecx, 1
		add ebp, 10
		add ebx, 0x03
		call RenderText
		pop ebp
		pop ebx
		pop eax

		push eax
		push ebx
		push ebp
		mov ecx, 1
		add ebp, 0x09
		add ebx, 0x02
		call RenderText
		pop ebp
		pop ebx
		pop eax

		push eax
		push ebx
		push ebp
		mov ecx, 1
		add ebp, 0x09
		add ebx, 0x04
		call RenderText
		pop ebp
		pop ebx
		pop eax

		push eax
		push ebx
		push ebp
		mov ecx, 0
		add ebp, 0x09
		add ebx, 0x03
		call RenderText
		pop ebp
		pop ebx
		pop eax

		pop eax

		call Sub60

		push eax
		push ebx
		push ebp
		mov ecx, 1
		add ebp, 0x08
		add ebx, 18
		call RenderText
		pop ebp
		pop ebx
		pop eax

		push eax
		push ebx
		push ebp
		mov ecx, 1
		add ebp, 10
		add ebx, 18
		call RenderText
		pop ebp
		pop ebx
		pop eax

		push eax
		push ebx
		push ebp
		mov ecx, 1
		add ebp, 0x09
		add ebx, 17
		call RenderText
		pop ebp
		pop ebx
		pop eax

		push eax
		push ebx
		push ebp
		mov ecx, 1
		add ebp, 0x09
		add ebx, 19
		call RenderText
		pop ebp
		pop ebx
		pop eax

		push eax
		push ebx
		push ebp
		mov ecx, 0
		add ebp, 0x09
		add ebx, 18
		call RenderText
		pop ebp
		pop ebx
		pop eax

		_label_return :
		popad

			jmp dwExitCountdownR2
	}
}

DWORD dwExitCountdownK = 0x525B4F;

__declspec(naked) void CountdownK() {
	__asm {
		pushad
		// ebp cima // ebx baixo
		mov eax, [esi + 0x10]

		cmp eax, 00
		je _label_return

		mov ebp, ebx
		mov ebx, [esp + 0x3C]

		mov edx, 00
		mov ecx, 1000
		div ecx

		push eax

		mov edx, 00
		mov ecx, 60
		div ecx

		push eax
		push ebx
		push ebp
		mov ecx, 1
		add ebp, 0x08
		add ebx, 0x03
		call RenderText
		pop ebp
		pop ebx
		pop eax

		push eax
		push ebx
		push ebp
		mov ecx, 1
		add ebp, 10
		add ebx, 0x03
		call RenderText
		pop ebp
		pop ebx
		pop eax

		push eax
		push ebx
		push ebp
		mov ecx, 1
		add ebp, 0x09
		add ebx, 0x02
		call RenderText
		pop ebp
		pop ebx
		pop eax

		push eax
		push ebx
		push ebp
		mov ecx, 1
		add ebp, 0x09
		add ebx, 0x04
		call RenderText
		pop ebp
		pop ebx
		pop eax

		push eax
		push ebx
		push ebp
		mov ecx, 0
		add ebp, 0x09
		add ebx, 0x03
		call RenderText
		pop ebp
		pop ebx
		pop eax

		pop eax

		call Sub60

		push eax
		push ebx
		push ebp
		mov ecx, 1
		add ebp, 0x08
		add ebx, 18
		call RenderText
		pop ebp
		pop ebx
		pop eax

		push eax
		push ebx
		push ebp
		mov ecx, 1
		add ebp, 10
		add ebx, 18
		call RenderText
		pop ebp
		pop ebx
		pop eax

		push eax
		push ebx
		push ebp
		mov ecx, 1
		add ebp, 0x09
		add ebx, 17
		call RenderText
		pop ebp
		pop ebx
		pop eax

		push eax
		push ebx
		push ebp
		mov ecx, 1
		add ebp, 0x09
		add ebx, 19
		call RenderText
		pop ebp
		pop ebx
		pop eax

		push eax
		push ebx
		push ebp
		mov ecx, 0
		add ebp, 0x09
		add ebx, 18
		call RenderText
		pop ebp
		pop ebx
		pop eax

		_label_return :
		popad

			mov ecx, [esp + 0x1C]
			movzx edx, word ptr[esi + 0x02]
			jmp dwExitCountdownK
	}
}

void hook::Coutdown() {
	util::detour((PVOID)0x4FFC02, CountdownSkill, 10);
	util::detour((PVOID)0x5182E6, CountdownInventory, 7);
	util::detour((PVOID)0x4FFD6F, CountdownItemsSkillBar, 10);
	util::detour((PVOID)0x4FCD85, CountdownZX, 10);
	util::detour((PVOID)0x5078C1, CountdownR, 9);
	util::detour((PVOID)0x507D27, CountdownR2, 10);
	util::detour((PVOID)0x525B47, CountdownK, 8);
}