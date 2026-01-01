#include "include/main.h"
#include <util/util.h>

char pointerOptionTrueFalse[35];
char pointerSystemEnabled[35];
_declspec(dllexport) _declspec(naked) void saveOptionSystem() {
	_asm {
		test edi,edi
		je isfpsboost_save
		cmp edi, 01
		je smallicon_save
		cmp edi, 02
		je effects_save
		cmp edi, 03
		je titles_save
		cmp edi,04
		je aura_save
		cmp edi,05
		je hplight_save
		cmp edi,06
		je hpdark_save
		cmp edi, 07
		je feed_save
		cmp edi, 8
		je shiftbar_save
		jmp return_

		isfpsboost_save:
		mov al, [pointerOptionTrueFalse]
		mov byte ptr ds : [cBoostPointer] , al
		mov byte ptr ds : [globalBoost] , al
		mov byte ptr ds : [pointerSystemEnabled],al
		push [globalBoost]
		call saveBoost
		add esp, 04
		jmp return_

		smallicon_save:
		mov al, [pointerOptionTrueFalse+4]
		mov byte ptr ds : [cSmall] , al
		mov byte ptr ds : [globalSmall] , al
		mov byte ptr ds : [pointerSystemEnabled+4] , al
		push [globalSmall]
		call saveSmall
		add esp, 04
		jmp return_

		effects_save :
		mov al, [pointerOptionTrueFalse+8]
		mov byte ptr ds : [globalEffects] , al
		mov byte ptr ds : [Effect] , al
		mov byte ptr ds : [pointerSystemEnabled+8] , al
		push [globalEffects]
		call saveEffects
		add esp, 04
		jmp return_

		titles_save :
		mov al, [pointerOptionTrueFalse+12]
		mov byte ptr ds : [globalTitle] , al
		mov byte ptr ds : [Titulo] , al
		mov byte ptr ds : [pointerSystemEnabled+12] , al
		push [globalTitle]
		call saveTitle
		add esp, 04
		jmp return_

		aura_save:
		mov al, [pointerOptionTrueFalse+16]
		mov byte ptr ds : [globalAura] , al
		mov byte ptr ds : [Traje_Effect] , al
		mov byte ptr ds : [pointerSystemEnabled+16] , al
		push [globalAura]
		call saveAura
		add esp, 04
		jmp return_

		hplight_save:
		mov al, [pointerOptionTrueFalse+20]
		mov byte ptr ds : [globalLight] , al
		mov byte ptr ds : [Light_Pointer] , al
		mov byte ptr ds : [pointerSystemEnabled+20] , al
		push [globalLight]
		call saveLight
		add esp, 04
		jmp return_

		hpdark_save:
		mov al, [pointerOptionTrueFalse+24]
		mov byte ptr ds : [globalDark] , al
		mov byte ptr ds : [Dark_Pointer] , al
		mov byte ptr ds : [pointerSystemEnabled+24] , al
		push [globalDark]
		call saveDark
		add esp, 04
		jmp return_

		feed_save:
		mov al, [pointerOptionTrueFalse+28]
		mov byte ptr ds : [globalFeed] , al
		mov byte ptr ds : [isFeedEnable] , al
		mov byte ptr ds : [pointerSystemEnabled+28] , al
		push [globalFeed]
		call saveFeed
		add esp, 04
	    jmp return_

		shiftbar_save:
		mov al, [pointerOptionTrueFalse+32]
		mov byte ptr ds : [globalShift] , al
		mov byte ptr ds : [isShiftEnable] , al
		mov byte ptr ds : [pointerSystemEnabled+32] , al
		push [globalShift]
		call saveShiftBar
		add esp, 04

		return_:

        ret
	}
}



char registerOptionPosX[100];
char registerOptionPos[100];
char registerOptionPosY[100];
DWORD optionWindowOpen = 0;
DWORD optionDropWindowOpen = 0;
DWORD optionPointerCloseOpen = 0;
DWORD optionSystemRenderReturn = 0x0051F296;
_declspec(naked) void optionSystemRender() {
	_asm {
		pushad
		mov edx, dword ptr ds : [esi + 0x08]
		add edx, 328
		mov eax, dword ptr ds : [esi + 0x04]
		add eax, 74
		push edx
		push eax
		lea ecx, dword ptr ds : optionSystemDrop
		call isRenderObject
		lea ecx, dword ptr ds : optionSystemDrop
		call isRenderMouseClick
		test eax,eax
		jne set_pointer_close_drop
		cmp byte ptr ds : [optionDropWindowOpen] , 01
		je openWindowOptionSystemDrop
		continueFunc:
		mov edx, dword ptr ds:[esi + 0x08]
		add edx, 0x30
		mov eax, dword ptr ds:[esi + 0x04]
		add eax, 0x49
		push edx
		push eax
		lea ecx, dword ptr ds:optionSystem
		call isRenderObject
		lea ecx, dword ptr ds:optionSystem
		call isRenderMouseClick
		test eax,eax
		jne set_pointer_close
		cmp byte ptr ds : [optionWindowOpen] , 01
		je openWindowOptionSystem
		pop_out:
		popad
		


		mov edx, dword ptr ds:[esi + 0x08]
		mov eax, dword ptr ds:[esi + 0x04]
		jmp optionSystemRenderReturn

		openWindowOptionSystem:
		mov byte ptr ds : [optionSystem + 0x06] , 01// hover
		mov eax,dword ptr ds:[esi+0x08]
		mov ecx,dword ptr ds:[esi+0x04]
        push eax
	    add ecx,250
		push ecx
		lea ecx,dword ptr ds:optionWindow
		call isRenderObjectSingle
		mov edx, dword ptr ds :[esi + 0x08]
		add edx,01
		mov eax, dword ptr ds:[esi + 0x04]
		add eax,600
		push edx
		push eax
		lea ecx, dword ptr ds : optionSystemCloseButton
		call isRenderObject
		lea ecx, dword ptr ds : optionSystemCloseButton
		call isRenderMouseClick
		test eax, eax
		jne set_close_window

		mov edx, dword ptr ds : [esi + 0x08]
		add edx, 400
		mov eax, dword ptr ds : [esi + 0x04]
		add eax, 550
		push edx
		push eax
		lea ecx, dword ptr ds : optionCancelButton
		call isRenderObject
		lea ecx, dword ptr ds : optionCancelButton
		call isRenderMouseClick
		test eax, eax
		jne set_close_window

		mov edx, dword ptr ds : [esi + 0x08]
		add edx, 401
		mov eax, dword ptr ds : [esi + 0x04]
		add eax, 470
		push edx
		push eax
		lea ecx, dword ptr ds : optionOkButton
		call isRenderObject
		lea ecx, dword ptr ds : optionOkButton
		call isRenderMouseClick
		test eax, eax
		jne set_close_and_save

		jmp pop_out

		openWindowOptionSystemDrop:
		mov byte ptr ds : [optionSystemDrop + 0x06] , 01// hover
		mov eax, dword ptr ds : [esi + 0x08]
		mov ecx, dword ptr ds : [esi + 0x04]
		push eax
		add ecx, -590
		push ecx
		lea ecx, dword ptr ds : optionWindowDrop
		call isRenderObjectSingle
		mov edx, dword ptr ds :[esi + 0x08]
		add edx,01
		mov eax, dword ptr ds:[esi + 0x04]
		add eax,-590
		push edx
		push eax
		lea ecx, dword ptr ds : optionSystemCloseButton
		call isRenderObject
		lea ecx, dword ptr ds : optionSystemCloseButton
		call isRenderMouseClick
		test eax, eax
		jne set_close_window_drop
		jmp continueFunc

		set_pointer_close:
		xor eax, eax
		cmp dword ptr ds : [optionWindowOpen] , eax
		sete al



		mov byte ptr ds:[optionWindowOpen],al
		test al,al
		jne showCheckMark
		jmp pop_out

		set_pointer_close_drop:
		xor eax, eax
		cmp dword ptr ds : [optionDropWindowOpen] , eax
		sete al
		mov byte ptr ds : [optionDropWindowOpen] , al
		jmp pop_out

		set_close_window:
		mov byte ptr ds:[optionWindowOpen],00
		jmp pop_out

		set_close_window_drop:
		mov byte ptr ds : [optionDropWindowOpen] , 00
		jmp pop_out

		set_close_and_save:
		mov byte ptr ds : [optionWindowOpen] , 00
		call isSaveLoop
		jmp pop_out 

		isSaveLoop:
		xor edi,edi
		startSaveLoop:
		cmp edi,9
		jge end_loop

		call saveOptionSystem


		inc edi
		jmp startSaveLoop

		end_loop:
	    ret

		showCheckMark:
		mov al, [pointerSystemEnabled]
		mov byte ptr ds : [pointerOptionTrueFalse] , al
		mov al, [pointerSystemEnabled + 4]
		mov byte ptr ds : [pointerOptionTrueFalse + 4] , al
		mov al, [pointerSystemEnabled + 8]
		mov byte ptr ds : [pointerOptionTrueFalse + 8] , al
		mov al, [pointerSystemEnabled + 12]
		mov byte ptr ds : [pointerOptionTrueFalse + 12] , al
		mov al, [pointerSystemEnabled + 16]
		mov byte ptr ds : [pointerOptionTrueFalse + 16] , al
		mov al, [pointerSystemEnabled + 20]
		mov byte ptr ds : [pointerOptionTrueFalse + 20] , al
		mov al, [pointerSystemEnabled + 24]
		mov byte ptr ds : [pointerOptionTrueFalse + 24] , al
		mov al, [pointerSystemEnabled + 28]
		mov byte ptr ds : [pointerOptionTrueFalse + 28] , al
		mov al, [pointerSystemEnabled + 32]
		mov byte ptr ds : [pointerOptionTrueFalse + 32] , al
		jmp pop_out
	}
}


DWORD optionSystemCheckRenderReturn = 0x0051F2A6;
_declspec(naked) void optionSystemCheckRender() {
	_asm {
		cmp byte ptr ds : [optionWindowOpen] , 01
		jne originalcode
		pushad
		pushfd
		xor edi,edi
		start_loop:
		cmp edi,8
		jg end_loop

		call getEnabledSystems

		cmp byte ptr ds:[edi*0x4+eax], 00
		jne render_inv_check
		jmp continue_
		render_inv_check:
		mov eax, [esi + 0x08]
		mov ecx, [esi + 0x04]
		add eax,65
		add ecx,280
		mov dword ptr ds:[registerOptionPosX], ecx
		mov dword ptr ds:[registerOptionPosY], eax
		add eax,31
		mov dword ptr ds:[registerOptionPosX+0x04], ecx
		mov dword ptr ds:[registerOptionPosY+0x04], eax
		add eax,30
		mov dword ptr ds:[registerOptionPosX+0x08], ecx
		mov dword ptr ds:[registerOptionPosY+0x08], eax
		add eax,29
		mov dword ptr ds:[registerOptionPosX+12], ecx
		mov dword ptr ds:[registerOptionPosY+12], eax
		add eax,28
		mov dword ptr ds:[registerOptionPosX+16] , ecx
		mov dword ptr ds:[registerOptionPosY+16] , eax
		add eax,29
		mov dword ptr ds:[registerOptionPosX+20] , ecx
		mov dword ptr ds:[registerOptionPosY+20] , eax
		add eax,29
		mov dword ptr ds:[registerOptionPosX+24] , ecx
		mov dword ptr ds:[registerOptionPosY+24] , eax
		add eax,29
		mov dword ptr ds:[registerOptionPosX+28] , ecx
		mov dword ptr ds:[registerOptionPosY+28] , eax
		add eax,29
		mov dword ptr ds:[registerOptionPosX+32] , ecx
		mov dword ptr ds:[registerOptionPosY+32] , eax
		mov eax, dword ptr ds:[edi*0x4+registerOptionPosY]
		mov ecx, dword ptr ds:[edi*0x4+registerOptionPosX]
		push eax
		push ecx
		lea ecx,dword ptr ds:check_btn_2
		call isRenderObjectSingle
		continue_:
		inc edi
		jmp start_loop

		end_loop:
		popfd
		popad
		jmp originalcode_pop

		originalcode:
		lea edi, dword ptr ds:[esi + 0x00000C00]
		jmp optionSystemCheckRenderReturn

		originalcode_pop:
		pushad
		mov eax, [esi + 0x08]
		mov ecx, [esi + 0x04]
		add eax,63
		add ecx,280
		mov dword ptr ds:[registerOptionPosX], ecx
		mov dword ptr ds:[registerOptionPosY], eax
		add eax,31
		mov dword ptr ds:[registerOptionPosX+0x04], ecx
		mov dword ptr ds:[registerOptionPosY+0x04], eax
		add eax,30
		mov dword ptr ds:[registerOptionPosX+0x08], ecx
		mov dword ptr ds:[registerOptionPosY+0x08], eax
		add eax,29
		mov dword ptr ds:[registerOptionPosX+12], ecx
		mov dword ptr ds:[registerOptionPosY+12], eax
		add eax,28
		mov dword ptr ds:[registerOptionPosX+16] , ecx
		mov dword ptr ds:[registerOptionPosY+16] , eax
		add eax,29
		mov dword ptr ds:[registerOptionPosX+20] , ecx
		mov dword ptr ds:[registerOptionPosY+20] , eax
		add eax,29
		mov dword ptr ds:[registerOptionPosX+24] , ecx
		mov dword ptr ds:[registerOptionPosY+24] , eax
		add eax,29
		mov dword ptr ds:[registerOptionPosX+28] , ecx
		mov dword ptr ds:[registerOptionPosY+28] , eax
	    add eax,29
		mov dword ptr ds:[registerOptionPosX+32] , ecx
		mov dword ptr ds:[registerOptionPosY+32] , eax
		popad
		jmp originalcode


		getEnabledSystems:
		lea eax, dword ptr ds : pointerOptionTrueFalse
		ret 
	}
}
DWORD optionSystemClickReturn = 0x00487B4E;
_declspec(naked) void optionSystemClick() {
	_asm {
		cmp byte ptr ds : [optionWindowOpen] , 01
		jne originalcode

		pushad
		pushfd
		mov ecx, dword ptr ds:[0x7C3C10]// y mouse
		mov edi, dword ptr ds:[0x7C3C0C]// x mouse
		mov ebp, dword ptr ds:[0x7AB0DC]// resolução
		cmp ecx, ebp
		jg pop_and_jmp
		xor edi, edi
		get_pos :
		mov edx, dword ptr ds:[edi*4+registerOptionPosX]
		lea eax, [edx]
		mov edx, dword ptr ds:[edi*4+registerOptionPosY]
		lea edx, [edx]
		mov dword ptr ds:[registerOptionPos], edx
		mov edx, dword ptr ds:[0x7C3C0C]
		cmp edx, eax
		jl start_inc
		add eax, 0x10
		cmp edx, eax
		jg start_inc
		mov eax, dword ptr ds:[registerOptionPos]
		cmp ecx, eax
		jl start_inc
		add eax, 19
		cmp ecx, eax
		jg start_inc
		cmp edi, 8
		jg pop_and_jmp
		xor eax, eax
		cmp edi, eax
		je check_fpsboost
		cmp edi, 01
		je check_smallbuff
		cmp edi, 02
		je check_effects
		cmp edi, 03
		je check_title
		cmp edi,04
		je check_aura
		cmp edi,05
		je check_hplight
		cmp edi,06
		je check_hpdark
		cmp edi,07
		je check_feed
		cmp edi, 8
		je check_shiftbar
		jmp start_inc

		check_fpsboost:
		cmp dword ptr ds:[pointerOptionTrueFalse], eax
		sete al
		mov byte ptr ds:[pointerOptionTrueFalse], al
		jmp end_

		check_smallbuff:
		cmp dword ptr ds:[pointerOptionTrueFalse+4], eax
		sete al
		mov byte ptr ds:[pointerOptionTrueFalse+4], al
		jmp end_

		check_effects:
		cmp dword ptr ds:[pointerOptionTrueFalse+8], eax
		sete al
		mov byte ptr ds:[pointerOptionTrueFalse+8], al
		jmp end_

		check_title:
		cmp dword ptr ds:[pointerOptionTrueFalse+12], eax
		sete al
		mov byte ptr ds:[pointerOptionTrueFalse+12], al
		jmp end_

		check_aura:
		cmp dword ptr ds : [pointerOptionTrueFalse+16] , eax
		sete al
		mov byte ptr ds : [pointerOptionTrueFalse+16] , al
		jmp end_

		check_hplight:
		cmp dword ptr ds:[pointerOptionTrueFalse+20], eax
		sete al
		mov byte ptr ds:[pointerOptionTrueFalse+20], al
		jmp end_

		check_hpdark:
		cmp dword ptr ds:[pointerOptionTrueFalse+24], eax
		sete al
		mov byte ptr ds:[pointerOptionTrueFalse+24], al
		jmp end_ 

		check_feed:
		cmp dword ptr ds : [pointerOptionTrueFalse + 28] , eax
		sete al
		mov byte ptr ds : [pointerOptionTrueFalse + 28] , al
		jmp end_

		check_shiftbar:
		cmp dword ptr ds : [pointerOptionTrueFalse + 32] , eax
		sete al
		mov byte ptr ds : [pointerOptionTrueFalse + 32] , al

		end_:
		mov ecx, dword ptr ds:[0x7C06F8]
		mov ecx, dword ptr ds:[0x7C3C10]
		mov ebp, dword ptr ds:[0x7AB0DC]
		start_inc:
		inc edi
		cmp edi,9
		jl get_pos
		popfd
		popad

		originalcode:
		cmp dword ptr ds:[esi + 0x00000084], 00
		jmp optionSystemClickReturn

		pop_and_jmp:
		popfd
		popad
		jmp originalcode
	}
}

DWORD closeCurrentWindowsReturn = 0x0049E9C6;
_declspec(naked) void closeCurrentWindows() {
	_asm {
		mov dword ptr ds : [edi + 0x20] , ebx
		mov dword ptr ds : [optionWindowOpen] , ebx
		mov dword ptr ds : [optionDropWindowOpen] , ebx
		pop ebp
		pop ebx
		jmp closeCurrentWindowsReturn
	}
}
void hook::OptionSystemMain() {
	util::detour((PVOID)0x0051F290, optionSystemRender, 6);
	util::detour((PVOID)0x0051F2A0, optionSystemCheckRender, 6);
	util::detour((PVOID)0x00487B47, optionSystemClick, 7);
	util::detour((PVOID)0x0049E9C1, closeCurrentWindows, 5);
}