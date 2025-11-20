#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"

DWORD Remove_Effect = 0x00416970;

std::array<int, 2048> Costume_Array_1;
std::array<int, 2048> Costume_Array_2;
std::array<int, 2048> Costume_Array_3;
std::array<int, 2048> Costume_Array_4;
std::array<int, 2048> Costume_Array_5;
std::array<int, 2048> Costume_Array_6;
std::array<int, 2048> Costume_Array_7;
std::array<int, 2048> Costume_Array_8;
std::array<int, 2048> Costume_Array_9;
std::array<int, 2048> Costume_Array_10;

std::array<int, 512> Costume_Effect_Array_1 = {  };
std::array<int, 512> Costume_Effect_Array_2 = {  };
std::array<int, 512> Costume_Effect_Array_3 = {  };
std::array<int, 512> Costume_Effect_Array_4 = {  };
std::array<int, 512> Costume_Effect_Array_5 = {  };
std::array<int, 512> Costume_Effect_Array_6 = {  };
std::array<int, 512> Costume_Effect_Array_7 = {  };
std::array<int, 512> Costume_Effect_Array_8 = {  };
std::array<int, 512> Costume_Effect_Array_9 = {  };
std::array<int, 512> Costume_Effect_Array_10 = {  };

bool Costume_Find_1(int Costume_ID) {
	auto res = std::find(std::begin(Costume_Effect_Array_1), std::end(Costume_Effect_Array_1), Costume_ID);
	return res != std::end(Costume_Effect_Array_1);
}

bool Costume_Find_2(int Costume_ID) {
	auto res = std::find(std::begin(Costume_Effect_Array_2), std::end(Costume_Effect_Array_2), Costume_ID);
	return res != std::end(Costume_Effect_Array_2);
}

bool Costume_Find_3(int Costume_ID) {
	auto res = std::find(std::begin(Costume_Effect_Array_3), std::end(Costume_Effect_Array_3), Costume_ID);
	return res != std::end(Costume_Effect_Array_3);
}

bool Costume_Find_4(int Costume_ID) {
	auto res = std::find(std::begin(Costume_Effect_Array_4), std::end(Costume_Effect_Array_4), Costume_ID);
	return res != std::end(Costume_Effect_Array_4);
}

bool Costume_Find_5(int Costume_ID) {
	auto res = std::find(std::begin(Costume_Effect_Array_5), std::end(Costume_Effect_Array_5), Costume_ID);
	return res != std::end(Costume_Effect_Array_5);
}

bool Costume_Find_6(int Costume_ID) {
	auto res = std::find(std::begin(Costume_Effect_Array_6), std::end(Costume_Effect_Array_6), Costume_ID);
	return res != std::end(Costume_Effect_Array_6);
}

bool Costume_Find_7(int Costume_ID) {
	auto res = std::find(std::begin(Costume_Effect_Array_7), std::end(Costume_Effect_Array_7), Costume_ID);
	return res != std::end(Costume_Effect_Array_7);
}

bool Costume_Find_8(int Costume_ID) {
	auto res = std::find(std::begin(Costume_Effect_Array_8), std::end(Costume_Effect_Array_8), Costume_ID);
	return res != std::end(Costume_Effect_Array_8);
}

bool Costume_Find_9(int Costume_ID) {
	auto res = std::find(std::begin(Costume_Effect_Array_9), std::end(Costume_Effect_Array_9), Costume_ID);
	return res != std::end(Costume_Effect_Array_9);
}

bool Costume_Find_10(int Costume_ID) {
	auto res = std::find(std::begin(Costume_Effect_Array_10), std::end(Costume_Effect_Array_10), Costume_ID);
	return res != std::end(Costume_Effect_Array_10);
}




DWORD Effect_Equip_Return = 0x0059F4A4;
DWORD Render_Effect = 0x0041A2C0;
_declspec(naked) void Effect_Costume() {
	_asm {



		cmp byte ptr ds : [esi + ebx + 0x1A8] , 150
		jne originalcode

		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov [Costume_Array_1], edx
		mov ebx, [Costume_Array_1]
		push ebx
		call Costume_Find_1
		add esp, 04
		test al, al
		popad
		jne call_effect1


		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_2], edx
		mov ebx, [Costume_Array_2]
		push ebx
		call Costume_Find_2
		add esp, 04
		test al, al
		popad
		jne call_effect2

		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_3], edx
		mov ebx, [Costume_Array_3]
		push ebx
		call Costume_Find_3
		add esp, 04
		test al, al
		popad
		jne call_effect3
	

		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_4], edx
		mov ebx, [Costume_Array_4]
		push ebx
		call Costume_Find_4
		add esp, 04
		test al, al
		popad
		jne call_effect4

		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_5], edx
		mov ebx, [Costume_Array_5]
		push ebx
		call Costume_Find_5
		add esp, 04
		test al, al
		popad
		jne call_effect5

		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_6], edx
		mov ebx, [Costume_Array_6]
		push ebx
		call Costume_Find_6
		add esp, 04
		test al, al
		popad
		jne call_effect6

		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_7], edx
		mov ebx, [Costume_Array_7]
		push ebx
		call Costume_Find_7
		add esp, 04
		test al, al
		popad
		jne call_effect7

		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_8], edx
		mov ebx, [Costume_Array_8]
		push ebx
		call Costume_Find_8
		add esp, 04
		test al, al
		popad
		jne call_effect8


		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_9], edx
		mov ebx, [Costume_Array_9]
		push ebx
		call Costume_Find_9
		add esp, 04
		test al, al
		popad
		jne call_effect9

		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_10], edx
		mov ebx, [Costume_Array_10]
		push ebx
		call Costume_Find_10
		add esp, 04
		test al, al
		popad
		jne call_effect10

		pushad
		mov ecx, esi
		call Remove_Effect
		popad

		originalcode :
		cmp dword ptr ds : [0x90E2F4] , edx
		jmp Effect_Equip_Return

			Call_Effect1 :
		pushad
			mov ecx, esi
			call Remove_Effect
			popad


			pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xD9
			call Render_Effect // Render Effect
			popad

			jmp originalcode


			Call_Effect2 :
		pushad
			mov ecx, esi
			call Remove_Effect
			popad


			pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 0x02
			push 0xDC
			call Render_Effect // Render Effect
			popad

			jmp originalcode


			Call_Effect3 :
		pushad
			mov ecx, esi
			call Remove_Effect
			popad


			pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xDD
			call Render_Effect // Render Effect
			popad

			jmp originalcode

			Call_Effect4 :
		pushad
			mov ecx, esi
			call Remove_Effect
			popad


			pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xDE
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect5 :
		pushad
			mov ecx, esi
			call Remove_Effect
			popad


			pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xDF
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect6 :
		pushad
			mov ecx, esi
			call Remove_Effect
			popad


			pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE0
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect7 :
		pushad
			mov ecx, esi
			call Remove_Effect
			popad


			pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE1
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect8 :
		pushad
			mov ecx, esi
			call Remove_Effect
			popad


			pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE2
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect9 :
		pushad
			mov ecx, esi
			call Remove_Effect
			popad


			pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE3
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect10 :
		pushad
			mov ecx, esi
			call Remove_Effect
			popad


			pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE4
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect11 :
		pushad
			mov ecx, esi
			call Remove_Effect
			popad


			pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE5
			call Render_Effect // Render Effect
			popad


			jmp originalcode
	}
}

DWORD Respawn_Return = 0x005EB875;
_declspec(naked) void Show_Effect_When_Respawn() {
	_asm {
		push eax
		mov eax, 0x0059546B
		cmp[esp + 0x04], eax
		pop eax

		je Check_Costumes_ID

		originalcode :
		mov eax, 0x00002008
			jmp Respawn_Return


			Check_Costumes_ID :

		pushad
			movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
			mov[Costume_Array_1], edx
			mov ebx, [Costume_Array_1]
			push ebx
			call Costume_Find_1
			add esp, 04
			test al, al
			popad
			jne call_effect1


			pushad
			movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
			mov[Costume_Array_2], edx
			mov ebx, [Costume_Array_2]
			push ebx
			call Costume_Find_2
			add esp, 04
			test al, al
			popad
			jne call_effect2

			pushad
			movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
			mov[Costume_Array_3], edx
			mov ebx, [Costume_Array_3]
			push ebx
			call Costume_Find_3
			add esp, 04
			test al, al
			popad
			jne call_effect3


			pushad
			movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
			mov[Costume_Array_4], edx
			mov ebx, [Costume_Array_4]
			push ebx
			call Costume_Find_4
			add esp, 04
			test al, al
			popad
			jne call_effect4

			pushad
			movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
			mov[Costume_Array_5], edx
			mov ebx, [Costume_Array_5]
			push ebx
			call Costume_Find_5
			add esp, 04
			test al, al
			popad
			jne call_effect5

			pushad
			movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
			mov[Costume_Array_6], edx
			mov ebx, [Costume_Array_6]
			push ebx
			call Costume_Find_6
			add esp, 04
			test al, al
			popad
			jne call_effect6

			pushad
			movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
			mov[Costume_Array_7], edx
			mov ebx, [Costume_Array_7]
			push ebx
			call Costume_Find_7
			add esp, 04
			test al, al
			popad
			jne call_effect7

			pushad
			movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
			mov[Costume_Array_8], edx
			mov ebx, [Costume_Array_8]
			push ebx
			call Costume_Find_8
			add esp, 04
			test al, al
			popad
			jne call_effect8


			pushad
			movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
			mov[Costume_Array_9], edx
			mov ebx, [Costume_Array_9]
			push ebx
			call Costume_Find_9
			add esp, 04
			test al, al
			popad
			jne call_effect9

			pushad
			movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
			mov[Costume_Array_10], edx
			mov ebx, [Costume_Array_10]
			push ebx
			call Costume_Find_10
			add esp, 04
			test al, al
			popad
			jne call_effect10

			jmp originalcode

			Call_Effect1 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 0x02
			push 0xD9
			call Render_Effect // Render Effect
			popad

			jmp originalcode


			Call_Effect2 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 0x02
			push 0xDC
			call Render_Effect // Render Effect
			popad

			jmp originalcode


			Call_Effect3 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xDD
			call Render_Effect // Render Effect
			popad

			jmp originalcode

			Call_Effect4 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xDE
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect5 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xDF
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect6 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE0
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect7 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE1
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect8 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE2
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect9 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE3
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect10 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE4
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect11 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE5
			call Render_Effect // Render Effect
			popad

			jmp originalcode


	}
}
DWORD Respawn_Return_2 = 0x0059547A;
_declspec(naked) void Show_Effect_When_Respawn_2() {
	_asm {

		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_1], edx
		mov ebx, [Costume_Array_1]
		push ebx
		call Costume_Find_1
		add esp, 04
		test al, al
		popad
		jne call_effect1


		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_2], edx
		mov ebx, [Costume_Array_2]
		push ebx
		call Costume_Find_2
		add esp, 04
		test al, al
		popad
		jne call_effect2

		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_3], edx
		mov ebx, [Costume_Array_3]
		push ebx
		call Costume_Find_3
		add esp, 04
		test al, al
		popad
		jne call_effect3


		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_4], edx
		mov ebx, [Costume_Array_4]
		push ebx
		call Costume_Find_4
		add esp, 04
		test al, al
		popad
		jne call_effect4

		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_5], edx
		mov ebx, [Costume_Array_5]
		push ebx
		call Costume_Find_5
		add esp, 04
		test al, al
		popad
		jne call_effect5

		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_6], edx
		mov ebx, [Costume_Array_6]
		push ebx
		call Costume_Find_6
		add esp, 04
		test al, al
		popad
		jne call_effect6

		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_7], edx
		mov ebx, [Costume_Array_7]
		push ebx
		call Costume_Find_7
		add esp, 04
		test al, al
		popad
		jne call_effect7

		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_8], edx
		mov ebx, [Costume_Array_8]
		push ebx
		call Costume_Find_8
		add esp, 04
		test al, al
		popad
		jne call_effect8


		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_9], edx
		mov ebx, [Costume_Array_9]
		push ebx
		call Costume_Find_9
		add esp, 04
		test al, al
		popad
		jne call_effect9

		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_10], edx
		mov ebx, [Costume_Array_10]
		push ebx
		call Costume_Find_10
		add esp, 04
		test al, al
		popad
		jne call_effect10

		originalcode :
		mov ecx, esi
			mov[esi + 0x000002C0], bl
			jmp Respawn_Return_2

			Call_Effect1 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 0x02
			push 0xD9
			call Render_Effect // Render Effect
			popad

			jmp originalcode


			Call_Effect2 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 0x02
			push 0xDC
			call Render_Effect // Render Effect
			popad

			jmp originalcode


			Call_Effect3 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xDD
			call Render_Effect // Render Effect
			popad

			jmp originalcode

			Call_Effect4 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xDE
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect5 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xDF
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect6 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE0
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect7 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE1
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect8 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE2
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect9 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE3
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect10 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE4
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect11 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE5
			call Render_Effect // Render Effect
			popad

			jmp originalcode
	}
}

DWORD Effect_Map_Return = 0x004162F5;
_declspec(naked) void Effect_When_Change_Map() {
	_asm {
		push eax
		mov eax, 0x00418FA7
		cmp[esp + 0x04], eax
		pop eax
		jne originalcode



		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_1], edx
		mov ebx, [Costume_Array_1]
		push ebx
		call Costume_Find_1
		add esp, 04
		test al, al
		popad
		jne call_effect1


		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_2], edx
		mov ebx, [Costume_Array_2]
		push ebx
		call Costume_Find_2
		add esp, 04
		test al, al
		popad
		jne call_effect2

		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_3], edx
		mov ebx, [Costume_Array_3]
		push ebx
		call Costume_Find_3
		add esp, 04
		test al, al
		popad
		jne call_effect3


		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_4], edx
		mov ebx, [Costume_Array_4]
		push ebx
		call Costume_Find_4
		add esp, 04
		test al, al
		popad
		jne call_effect4

		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_5], edx
		mov ebx, [Costume_Array_5]
		push ebx
		call Costume_Find_5
		add esp, 04
		test al, al
		popad
		jne call_effect5

		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_6], edx
		mov ebx, [Costume_Array_6]
		push ebx
		call Costume_Find_6
		add esp, 04
		test al, al
		popad
		jne call_effect6

		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_7], edx
		mov ebx, [Costume_Array_7]
		push ebx
		call Costume_Find_7
		add esp, 04
		test al, al
		popad
		jne call_effect7

		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_8], edx
		mov ebx, [Costume_Array_8]
		push ebx
		call Costume_Find_8
		add esp, 04
		test al, al
		popad
		jne call_effect8


		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_9], edx
		mov ebx, [Costume_Array_9]
		push ebx
		call Costume_Find_9
		add esp, 04
		test al, al
		popad
		jne call_effect9

		pushad
		movzx edx, byte ptr ds : [esi + 0xF + 0x1B9]
		mov[Costume_Array_10], edx
		mov ebx, [Costume_Array_10]
		push ebx
		call Costume_Find_10
		add esp, 04
		test al, al
		popad
		jne call_effect10

		originalcode :
		mov eax, [esp + 0x04]
			push esi
			jmp Effect_Map_Return


			Call_Effect1 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 0x02
			push 0xD9
			call Render_Effect // Render Effect
			popad

			jmp originalcode


			Call_Effect2 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 0x02
			push 0xDC
			call Render_Effect // Render Effect
			popad

			jmp originalcode


			Call_Effect3 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xDD
			call Render_Effect // Render Effect
			popad

			jmp originalcode

			Call_Effect4 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xDE
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect5 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xDF
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect6 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE0
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect7 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE1
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect8 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE2
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect9 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE3
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect10 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE4
			call Render_Effect // Render Effect
			popad
			jmp originalcode

			Call_Effect11 :
		pushad
			fldz
			push 00
			push 00
			push 00
			push 01
			push 01
			fstp dword ptr ds : [esp]
			mov ecx, esi
			//push 03
			push 02
			push 0xE5
			call Render_Effect // Render Effect
			popad

			jmp originalcode

	}
}

void hook::CostumeEffect() {
	util::detour((void*)0x0059F49E, Effect_Costume, 6);
	util::detour((void*)0x005EB870, Show_Effect_When_Respawn, 5);
	util::detour((void*)0x00595472, Show_Effect_When_Respawn_2, 8);
	util::detour((void*)0x004162F0, Effect_When_Change_Map, 5);
}