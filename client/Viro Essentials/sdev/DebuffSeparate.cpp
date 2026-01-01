#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
std::string pos_x_stack[128];
std::string buff_stack[128];
std::string isPos[128];
std::string stack[128];
DWORD checkDebuffSkill = 0x0046CDA0;
DWORD isBuffRender = 0x004B57B0;
DWORD isLoadTime = 0x004B6BD0;
DWORD loadWhite = 0x004B6180;
DWORD loadDebuffIcon = 0x0057B860;
DWORD isBuffReturn = 0x004D740A;
_declspec(naked) void separateDebuffMain() {
	_asm {
		pushad
		xor esi, esi
		mov eax, dword ptr ds : [0x007AB0D8]
		cdq
		sub eax, edx
		mov edi, eax
		mov eax, dword ptr  ds : [0x022AA6F8]
		mov ecx, [eax]
		sar edi, 1
		sub edi, -0x00000069  // X
		add ebx, 0x00000030  // Y
		mov dword ptr ds : [stack] , esi
		mov edx, dword ptr ds : buff_stack
		sub ebx, edx
		add edx, ebx
		cmp ebx, edx
		je continue_pos
		mov ebx, dword ptr ds : buff_stack
		cmp byte ptr ds : [small_icon_cmd] , 1
		jne largeIconYSpacing2

		smallIconYSpacing2 :
		add ebx, 0x20;
			jmp continueYSpacing2

			largeIconYSpacing2 :
		add ebx, 0x31; 

			continueYSpacing2 :


		continue_pos :
		add edi,0x30
		mov dword ptr ds : [isPos] , ebx
		xor esi, esi
		mov [esp + 0x3C], esi
		mov dword ptr ds : [0x022AA700] , ecx
		cmp ecx, eax
		jne continue_stack
		popad
		jmp originalcode


		get_pos_y_stack :
		mov ebx, dword ptr ds : [isPos]
			continue_stack :
			mov esi, dword ptr ds : [ecx + 0x10]
			test esi, esi
			je check_buff_stack
			cmp dword ptr ds : [esi + 0x20] , 01
			je check_buff_stack
			cmp byte ptr ds : [esi + 0x06] , 100
			je continue_to_stack
			mov al, [esi + 0x06]
			movzx ecx, word ptr ds : [esi + 0x04]
			push eax
			push ecx
			mov ecx, 0x0091AD64
			call checkDebuffSkill
			mov ebp, eax
			test ebp, ebp
			je check_buff_stack_ebp
			cmp byte ptr ds : [ebp + 0x1F] , 03
			je continue_to_stack
			jmp check_buff_stack

			continue_to_stack :
		movzx eax, byte ptr ds : [esi + 0x06]
			movzx ecx, word ptr ds : [esi + 0x04]
			push 01
			push eax
			push ecx
			push ebx
			push edi
			push - 0x01
			mov ecx, ebp
			call isBuffRender
			mov edx, [esi + 0x10]
			mov eax, [esi + 0x08]
			push edx
			push eax
			push ebx
			push edi
			push 0xFFFFFF00
			mov ecx, ebp
			call isLoadTime
			mov al, [esi + 0x06]
			xor ebx, ebx
			cmp al, 0x64
			je continue_white
			movzx ecx, word ptr ds : [esi + 0x04]
			push eax
			push ecx
			mov ecx, 0x0091AD64
			call checkDebuffSkill
			mov ebp, eax
			test ebp, ebp
			je check_buff_stack_ebp
			cmp byte ptr ds : [ebp + 0x1F] , 0x03
			je continue_message
			jmp check_buff_stack
			continue_white :
		mov ebx, 0x00000001
			condition_menssage :
			mov eax, 0x10624DD3
			mul dword ptr ds : [esi + 0x10]
			shr edx, 0x06
			condition_menssage_2 :
			cmp dword ptr ds : [0x007C3C0C] , edi
			jl isCondition
			lea ecx, [edi + 0x20]
			cmp dword ptr ds : [0x007C3C0C] , ecx
			jg isCondition
			mov eax, dword ptr ds : [isPos]
			cmp dword ptr ds : [0x007C3C10] , eax
			jl isCondition
			cmp byte ptr ds:[small_icon_cmd],01
			je setDebuffSmall
			add eax, 0x20
			jmp debuffContinueFunc
			setDebuffSmall:
		    add eax, 0x11
			debuffContinueFunc:
			cmp dword ptr ds : [0x007C3C10] , eax
			jg isCondition
			mov[ebp + 0x00], 00000001
			mov ax, [esi + 0x04]
			mov[ebp + 0x14], ax
			mov cl, [esi + 0x06]
			mov[ebp + 0x16], cl
			mov[esp + 0x3C], edx
			isCondition :
		test ebx, ebx
			je set_stack
			mov edx, dword ptr ds : [isPos]
			mov eax, dword ptr ds : [0x022AB854]
			cmp byte ptr ds : [small_icon_cmd] , 01
			jne isNormalSize
			push 0x11
			push 0x11
			jmp continue_size
			isNormalSize :
		push 0x20
			push 0x20
			continue_size :
			push edx
			push edi
			push eax
			call loadWhite
			add esp, 0x14
			mov eax, dword ptr ds : [isPos]
			sub eax, 0x0C
			push eax
			mov ecx, edi
			add ecx, 0x13
			push ecx
			lea ecx, dword ptr ds : debuff
			call loadDebuffIcon
			set_stack :
		mov eax, dword ptr ds : [stack]
			inc eax
			cmp byte ptr ds : [small_icon_cmd] , 1
			jne largeIconEndSpacing

			smallIconEndSpacing :
		add edi, 0x15; 
			jmp continueEndSpacing

			largeIconEndSpacing :
		add edi, 0x28;

			continueEndSpacing :

			cmp eax, 0x06
			mov dword ptr ds : [stack] , eax
			jng is_buff_stack
			mov eax, dword ptr ds : [0x007AB0D8]
			cdq
			sub eax, edx
			mov edi, eax
			sar edi, 1
			sub edi, 0x00000082
			add dword ptr ds : [isPos] , 0x28
			mov dword ptr ds : [stack] , 0x00000000
			is_buff_stack :
			mov ecx, dword ptr ds : [0x022AA700]
			check_buff_stack :
			cmp byte ptr ds : [ecx + 0x15] , 0x00
			jne label_end
			mov eax, [ecx + 0x08]
			cmp byte ptr ds : [eax + 0x15] , 0x00
			jne label_1
			mov ecx, eax
			mov eax, [ecx]
			cmp byte ptr ds : [eax + 0x15] , 00
			jne label_2
			nop
			back_ :
		mov ecx, eax
			mov eax, [ecx]
			cmp byte ptr ds : [eax + 0x15] , 00
			je back_
			jmp label_2
			label_1 :
		mov eax, [ecx + 0x04]
			cmp byte ptr ds : [eax + 0x15] , 00
			jne label_3
			label_4 :
		cmp ecx, [eax + 0x08]
			jne label_3
			mov ecx, eax
			mov dword ptr ds : [0x022AA700] , ecx
			mov eax, [eax + 0x04]
			cmp byte ptr ds : [eax + 0x15] , 00
			je label_4
			label_3 :
		mov ecx, eax
			label_2 :
		mov dword ptr ds : [0x022AA700] , ecx
			label_end :
		cmp ecx, dword ptr ds : [0x022AA6F8]
			jne get_pos_y_stack
			popad

			originalcode :
		mov dword ptr ds : [0x022AA700] , ecx
			jmp isBuffReturn


			check_buff_stack_ebp :
		mov ebp, dword ptr ds : [esp + 0x34]
			jmp is_buff_stack


			pop_original :
		popad
			jmp originalcode

			continue_message :
		mov ebx, 0x01
			cmp byte ptr ds : [ebp + 0x93] , 01
			mov ebp, dword ptr ds : [esp + 0x34]
			jne condition_menssage
			mov edx, dword ptr ds : [esi + 0x10]
			jmp condition_menssage_2
	}
}

DWORD originalConditionAddr = 0x004D76A6;
DWORD isHideDebuffReturn = 0x004D7439;
DWORD ignoreDebuff = 0x004D76A0;
_declspec(naked) void isHideDebuff() {
	_asm {
		mov dword ptr ds : [buff_stack] , ebx
		pushad
		mov al, [esi + 0x06]
		cmp al, 0x64
		je pop_and_jmp
		movzx ecx, word ptr ds : [esi + 0x04]
		push eax
		push ecx
		mov ecx, 0x0091AD64
		call checkDebuffSkill
		mov ebp, eax
		test ebp, ebp
		je pop_original
		cmp byte ptr ds : [ebp + 0x1F] , 03
		je pop_and_jmp
		popad

		originalcode :
		cmp dword ptr ds : [esi + 0x20] , 01
			je originalCondition
			jmp isHideDebuffReturn

			pop_and_jmp :
		popad
			jmp ignoreDebuff

			pop_original :
		popad
			jmp originalcode

			originalCondition :
		jmp originalConditionAddr
	}
}

void hook::DebuffSeparate() {
	util::detour((PVOID)0x004D7404, separateDebuffMain, 6);
	util::detour((PVOID)0x004D742F, isHideDebuff, 10);
}