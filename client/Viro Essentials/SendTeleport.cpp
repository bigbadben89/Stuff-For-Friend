#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
DWORD isLoad = 0x00550120;
DWORD isHoverObject = 0x00550A20;
DWORD sendUseTeleport = 0x005EBAF0;
DWORD isConditional = 0x00532836;
DWORD isSendTeleportReturn = 0x0053280D;
__declspec(dllexport) _declspec(naked) void isSendTeleport() {
	_asm {
		cmp dword ptr ds:[pointer_close], 01
		je originalcode

		pushad
		pushfd
		xor ebp, ebp
		start_loop :
		cmp ebp, 0x07
		jg end_loop
		get_pos :
		mov eax, [isSavePosY]
		mov ecx, [isSavePosX]
		add eax, 45
		add ecx, 208
		mov dword ptr ds:[save_pos_y_2], eax
		mov dword ptr ds:[save_pos_x_2], ecx
		add eax, 0x20
		mov dword ptr ds:[save_pos_y_2 + 04], eax
		mov dword ptr ds:[save_pos_x_2 + 04], ecx
		add eax, 0x20
		mov dword ptr ds:[save_pos_y_2 + 0x08], eax
		mov dword ptr ds:[save_pos_x_2 + 0x08], ecx
		add eax, 0x20
		mov dword ptr ds:[save_pos_y_2 + 0x0C], eax
		mov dword ptr ds:[save_pos_x_2 + 0x0C], ecx
		add eax, 0x20
		mov dword ptr ds:[save_pos_y_2 + 0x10], eax
		mov dword ptr ds:[save_pos_x_2 + 0x10], ecx
		add eax, 0x20
		mov dword ptr ds:[save_pos_y_2 + 0x14], eax
		mov dword ptr ds:[save_pos_x_2 + 0x14], ecx
		add eax, 0x20
		mov dword ptr ds:[save_pos_y_2 + 0x18], eax
		mov dword ptr ds:[save_pos_x_2 + 0x18], ecx
		add eax, 0x20
		mov dword ptr ds:[save_pos_y_2 + 0x1C], eax
		mov dword ptr ds:[save_pos_x_2 + 0x1C], ecx
		mov eax, dword ptr ds:[ebp * 0x4 + save_pos_y_2]
		mov ecx, dword ptr ds:[ebp * 0x4 + save_pos_x_2]
		push eax
		lea edi, dword ptr ds:warMove
		push ecx
		mov ecx, edi
		call isLoad
		mov ecx, edi
		call isHoverObject
		cmp ebp, 0
		je map_1
		cmp ebp, 1
		je map_2
		cmp ebp, 2
		je map_3
		cmp ebp, 3
		je map_4
		cmp ebp, 4
		je map_5
		cmp ebp, 5
		je map_6
		cmp ebp, 6
		je map_7
		cmp ebp, 7
		je map_8


		continue_:
		inc ebp
		jmp start_loop



		originalcode:
		cmp eax,04
		je isConditionalOriginal
        jmp isSendTeleportReturn 

		isConditionalOriginal:
		jmp isConditional


		send_click:
		lea ecx, dword ptr ds:warMove
		call isRenderMouseClick
		jmp continue_

		end_loop:
		popfd
		popad
		jmp originalcode


		map_1:
		cmp byte ptr ds:[warMove+0xA3], 01
		jne continue_
		cmp byte ptr ds:[isPointerPagination],01
		jne isTeleport1
		mov eax,9
		jmp isContinueTeleport
		isTeleport1:
		mov eax, 01
		isContinueTeleport:
		mov ebx,06
		push eax
		push ebx
		call sendUseTeleport
		add esp, 0x08
		mov dword ptr ds:[pointer_close],1
		jmp end_loop

		map_2 :
		cmp byte ptr ds:[warMove+0xA3], 01
		jne continue_
		cmp byte ptr ds:[isPointerPagination],01
		jne isTeleport2
		mov eax,10
		jmp isContinueTeleport
		isTeleport2:
		mov eax,02
		jmp isContinueTeleport


		map_3 :
		cmp byte ptr ds:[warMove+0xA3], 01
		jne continue_
		cmp byte ptr ds : [isPointerPagination] , 01
		jne isTeleport3
		mov eax, 11
		jmp isContinueTeleport
		isTeleport3:
		mov eax, 03
		jmp isContinueTeleport

		map_4 :
		cmp byte ptr ds:[warMove+0xA3], 01
		jne continue_
		cmp byte ptr ds : [isPointerPagination] , 01
		jne isTeleport4
		mov eax, 12
		jmp isContinueTeleport
		isTeleport4:
		mov eax, 04
		jmp isContinueTeleport


		map_5 :
		cmp byte ptr ds:[warMove+0xA3], 01
		jne continue_
		cmp byte ptr ds : [isPointerPagination] , 01
		jne isTeleport5
		mov eax, 13
		jmp isContinueTeleport
		isTeleport5 :
		mov eax, 05
		jmp isContinueTeleport

		map_6 :
		cmp byte ptr ds:[warMove+0xA3], 01
		jne continue_
		cmp byte ptr ds : [isPointerPagination] , 01
		jne isTeleport6
		mov eax, 14
		jmp isContinueTeleport
		isTeleport6 :
		mov eax, 06
		jmp isContinueTeleport

		map_7 :
		cmp byte ptr ds:[warMove+0xA3], 01
		jne continue_
		cmp byte ptr ds : [isPointerPagination] , 01
		jne isTeleport7
		mov eax, 15
		jmp isContinueTeleport
		isTeleport7:
		mov eax, 07
		jmp isContinueTeleport

		map_8 :
		cmp byte ptr ds:[warMove+0xA3], 01
		jne continue_
		cmp byte ptr ds : [isPointerPagination] , 01
		jne isTeleport8
		mov eax, 16
		jmp isContinueTeleport
		isTeleport8 :
		mov eax, 8
		jmp isContinueTeleport
	}
}


void SendTeleport() {
	util::detour((PVOID)0x00532808, isSendTeleport, 5);
}