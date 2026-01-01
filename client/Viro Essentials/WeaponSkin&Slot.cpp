#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"

DWORD dwExitEquip = 0x0051909D;

__declspec(naked) void ItemEquip() {
	__asm {
		cmp ebx, 80
		je _label_slot17

		cmp ebx, 79
		je _label_slot18

		_label_original :
		mov bl, al
			mov[esp + 0x0C], bl
			jmp dwExitEquip

			_label_slot17 :
		mov al, 17
			jmp _label_original

			_label_slot18 :
		mov al, 18
			jmp _label_original
	}
}

DWORD dwExitSetCorrectSlotByType = 0x0059F4AE;

__declspec(naked) void SetCorrectSlotByType() {
	__asm {
		mov al, [esp + 0x14]
		mov cl, [esp + 0x18]

		cmp al, 80
		je _label_slot17

		cmp al, 79
		je _label_slot18

		_label_return :
		jmp dwExitSetCorrectSlotByType

			_label_slot17 :
		mov ebx, 17
			jmp _label_return

			_label_slot18 :
		mov ebx, 18
			jmp _label_return
	}
}

DWORD dwExitItemRemove = 0x0051800F;
DWORD dwAllowItemRemove = 0x005180A9;

__declspec(naked) void ItemRemove() {
	__asm {
		mov dl, [esp + 0x1C]

		cmp dl, 17
		je _label_allow_remove

		cmp dl, 18
		je _label_allow_remove

		cmp[esp + 0x0F], dl
		jmp dwExitItemRemove

		_label_allow_remove :
		jmp dwAllowItemRemove
	}
}

DWORD dwExitRemoveStackText = 0x004E5637;

__declspec(naked) void RemoveStackText() {
	__asm {
		mov al, [esp + 0x04]

		cmp al, 80
		je _label_return

		cmp al, 79
		je _label_return

		movzx ecx, al
		jmp dwExitRemoveStackText

		_label_return :
		ret 0x04
	}
}

DWORD dwRemoveTypeEffectJe = 0x0051953B;
DWORD dwExitRemoveTypeEffect = 0x00519036;

__declspec(naked) void RemoveTypeEffect() {
	__asm {
		cmp ebx, 17
		je _label_exit

		cmp ebx, 18
		je _label_exit

		cmp al, 0x19
		je _label_original_je

		_label_exit :
		jmp dwExitRemoveTypeEffect

			_label_original_je :
		jmp dwRemoveTypeEffectJe
	}
}

DWORD dwExitSetSlotIconSize = 0x00517507;

__declspec(naked) void SetSlotIconSize() {
	__asm {
		mov eax, [esp + 0x04]

		cmp eax, 17
		je _label_size16

		cmp eax, 18
		je _label_size32

		cmp eax, 0x08
		jmp dwExitSetSlotIconSize

		_label_size16 :
		mov eax, 0x01
			ret 0x04

			_label_size32 :
			xor eax, eax
			ret 0x04


	}
}

float bag1 = 13.00f;

DWORD dwExitFixBag1BtnA = 0x00519C60;

__declspec(naked) void FixBag1BtnA() {
	__asm {
		fld dword ptr[offset bag1]
		jmp dwExitFixBag1BtnA
	}
}

DWORD dwExitFixBag1BtnB = 0x0051A344;

__declspec(naked) void FixBag1BtnB() {
	__asm {
		fld dword ptr[offset bag1]
		jmp dwExitFixBag1BtnB
	}
}

float bag2A = 225.80f;
float bag2B = 61.00f;

DWORD dwExitFixBag2BtnA = 0x0051A357;

__declspec(naked) void FixBag2BtnA() {
	__asm {
		fld dword ptr[offset bag2A]
		jmp dwExitFixBag2BtnA
	}
}

DWORD dwExitFixBag2BtnB = 0x0051A36A;

__declspec(naked) void FixBag2BtnB() {
	__asm {
		fld dword ptr[offset bag2B]
		jmp dwExitFixBag2BtnB
	}
}

float slot17PositionX = 175.00f;
float slot17PositionY = 112.00f;
float slot18PositionX = 168.00f;
float slot18PositionY = 145.00f;

DWORD dwExitSetSlotIconPosition = 0x005183D7;

__declspec(naked) void SetSlotIconPosition() {
	__asm {
		push eax
		mov eax, [slot17PositionX]
		mov dword ptr[esi + 17 * 0x8 + 0x79C], eax
		mov eax, [slot17PositionY]
		mov dword ptr[esi + 17 * 0x8 + 0x7A0], eax
		mov eax, [slot18PositionX]
		mov dword ptr[esi + 18 * 0x8 + 0x79C], eax
		mov eax, [slot18PositionY]
		mov dword ptr[esi + 18 * 0x8 + 0x7A0], eax
		pop eax

		fld dword ptr[esi + ebx * 0x8 + 0x79C]
		jmp dwExitSetSlotIconPosition
	}
}

float bag2C = 53.00f;

DWORD dwExitFixBag2BtnC = 0x00519C73;

__declspec(naked) void FixBag2BtnC() {
	__asm {
		fld dword ptr[offset bag2C]
		jmp dwExitFixBag2BtnC
	}
}

DWORD dwExitFixBag2BtnD = 0x00519C89;

__declspec(naked) void FixBag2BtnD() {
	__asm {
		fld dword ptr[offset bag2B]
		jmp dwExitFixBag2BtnD
	}
}

void hook::WeaponSkin_Slot() {
	BYTE bySlotCap = 19;
	//new slots
	memcpy((LPVOID)0x0051909F, &bySlotCap, 1);
	memcpy((LPVOID)0x0051A270, &bySlotCap, 1);
	memcpy((LPVOID)0x00518598, &bySlotCap, 1);
	memcpy((LPVOID)0x00517F8C, &bySlotCap, 1);

	util::detour((PVOID)0x00519097, ItemEquip, 6);
	util::detour((PVOID)0x0059F4A6, SetCorrectSlotByType, 8);
	util::detour((PVOID)0x00518007, ItemRemove, 8);
	util::detour((PVOID)0x004E5630, RemoveStackText, 7);
	util::detour((PVOID)0x0051902E, RemoveTypeEffect, 8);
	util::detour((PVOID)0x00517500, SetSlotIconSize, 7);
	util::detour((PVOID)0x00519C5A, FixBag1BtnA, 6);
	util::detour((PVOID)0x0051A33E, FixBag1BtnB, 6);
	util::detour((PVOID)0x0051A351, FixBag2BtnA, 6);
	util::detour((PVOID)0x0051A364, FixBag2BtnB, 6);
	util::detour((PVOID)0x00519C6D, FixBag2BtnC, 6);
	util::detour((PVOID)0x00519C83, FixBag2BtnD, 6);

	util::detour((PVOID)0x005183D0, SetSlotIconPosition, 7);

}


