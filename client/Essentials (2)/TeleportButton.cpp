#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
std::string paginationCount = "1/2";
std::string savePosY2[48];
std::string savePosX2[48];
DWORD isPosX=0;
DWORD isPosY=0;
DWORD isPosX_2 = 0;
DWORD isPosY_2 = 0;
DWORD isSavePosX= 208;
DWORD isSavePosY= 48;
DWORD isMousePosX=0;
DWORD isMousePosY=0;
DWORD isPressed=0;
DWORD pointer_close=1;
DWORD pointer_open_close=0;
DWORD largura = 254;
DWORD altura = 353;
DWORD isPointerPagination = 0;
DWORD isRenderObject = 0x00551B40;
DWORD isRenderObjectSingle = 0x0057B860;
DWORD isRenderMouseClick = 0x00550A10;
DWORD isTeleportReturn = 0x00532803;
__declspec(dllexport) _declspec(naked) void isTeleport() {
	_asm {
		pushad
		mov eax, dword ptr ds : [esi + 0x08]
		mov ecx, dword ptr ds : [esi + 0x04]
		add eax, 0x41 // aqui 
		add ecx, 20 // aqui
		push eax
		push ecx
		lea ecx, dword ptr ds:teleportButton
		call isRenderObject
		lea ecx, dword ptr ds : teleportButton
		call isRenderMouseClick
		test eax, eax
		jne set_pointer_close
		cmp dword ptr ds:[pointer_close], 01
		je pop_and_close
		mov byte ptr ds:[teleportButton + 06], 01



		mov eax, dword ptr ds:[esi + 0x08]
		add eax, 0x72
		mov [isPosY], eax
		mov eax, dword ptr ds:[esi + 04]
		mov [isPosX], eax
		cmp dword ptr ds:[isPressed], 01
		je newParam
		push dword ptr ds:[isSavePosY]
		push dword ptr ds:[isSavePosX]
		jmp continue_
		newParam:
		push dword ptr ds:[isPosY_2]
		push dword ptr ds:[isPosX_2]
		continue_:
		lea ecx, dword ptr ds:battleground
		call isRenderObjectSingle

		mov eax, dword ptr ds:[isSavePosY]
		mov ecx, dword ptr ds:[isSavePosX]
		add eax, 0x145
		add ecx, 75
		push eax
		push ecx
		lea ecx, dword ptr ds:isPagination
		call isRenderObject
		lea ecx, dword ptr ds:isPagination
		call isRenderMouseClick
		test eax, eax
		jne set_pagination
		continue_pagination :
		mov eax, dword ptr ds:[isSavePosY]
		mov ecx, dword ptr ds:[isSavePosX]
		add eax, 0x145
		add ecx, 145
		push eax
		push ecx
		lea ecx, dword ptr ds:isPagination2
		call isRenderObject
		lea ecx, dword ptr ds:isPagination2
		call isRenderMouseClick
		jne set_pagination2
		continue_pagination2 :
		mov eax, dword ptr ds:[isSavePosY]
		mov ecx, dword ptr ds:[isSavePosX]
		add ecx, 225
		add eax, 0x0A
		push eax
		push ecx
		lea ecx, dword ptr ds:closeButton
		call isRenderObject
		lea ecx, dword ptr ds:closeButton
		call isRenderMouseClick
		test eax, eax
		jne close_window
		mov eax, dword ptr ds:[0x022B24D0] // get click
		sub eax, 0x00
		je noClick
		sub eax, 0x01
		je send_click
		sub eax, 0x01
		jne getPosMouse
		cmp dword ptr ds:[isPressed], eax
		mov dword ptr ds:[isPressed], eax
		je getPosMouse

		popad


		originalcode:
		mov eax, dword ptr ds:[0x007AB0D4]
		jmp isTeleportReturn



		send_click:
		cmp dword ptr ds:[0x022B24D4], 00
		jne getPosMouse
		mov esi, dword ptr ds:[isSavePosX]
		mov eax, dword ptr ds:[0x007C3C0C]
		cmp eax, esi
		jl checkPressed
		mov edx,dword ptr ds:[largura] // largura
		add edx, esi
		cmp eax, edx
		jg checkPressed
		mov edx, dword ptr ds:[isSavePosY]
		mov edi, dword ptr ds:[0x007C3C10]
		cmp edi, edx
		jl checkPressed
		mov ebp, dword ptr ds:[altura] // altura
		add ebp, edx
		cmp edi, ebp
		jg checkPressed
		cmp dword ptr ds:[isPressed], 00
		jne pop_and_close
		sub eax, esi
		mov dword ptr ds:[isMousePosX], eax
		mov eax, dword ptr ds:[0x007C3C10]
		sub eax, edx
		mov[isMousePosY], eax
		mov[isPressed], 00000001
		jmp pop_and_close


		noClick:
		mov dword ptr ds:[isPressed], 0

		getPosMouse :
		mov eax, dword ptr ds:[0x007C3C0C]
		checkPressed :
		cmp dword ptr ds:[isPressed], 00
		je pop_and_close
		sub eax, dword ptr ds:[isMousePosX]
		mov dword ptr ds:[isPosX_2], eax
		mov dword ptr ds:[isSavePosX], eax
		mov edx, dword ptr ds:[0x007C3C10]
		sub edx, dword ptr ds:[isMousePosY]
		mov dword ptr ds:[isPosY_2], edx
		mov dword ptr ds:[isSavePosY], edx


		pop_and_close:
		popad
		jmp originalcode

		set_pointer_close:
		xor eax,eax
		cmp dword ptr ds : [pointer_close] , eax
		lea ecx, dword ptr ds:pointer_open_close
		sete al
		push ecx
		push 00
		mov dword ptr ds: [pointer_close] , eax
		call isSave_2
		jmp pop_and_close

		isSave_2:
		xor eax, eax
		ret 0x008

		set_pagination:
		mov dword ptr ds:[isPointerPagination], 00
		mov byte ptr ds:[paginationCount], 0x31
		jmp continue_pagination

		set_pagination2 :
		mov dword ptr ds:[isPointerPagination], 01
		mov byte ptr ds:[paginationCount], 0x32
		jmp continue_pagination2

		close_window :
		mov byte ptr ds:[paginationCount], 0x31
		mov dword ptr ds:[isPointerPagination], 00
		mov dword ptr ds:[pointer_close], 0x01
		jmp pop_and_close
	}
}

DWORD ignoreMouseAddr = 0x0044CE97;
DWORD ignoreMouseActionReturn = 0x0044CA7B;
__declspec(dllexport) _declspec(naked) void ignoreMouseAction() {
	_asm {
		cmp byte ptr ds:[teleportButton+06], 0
		jne ignoreMouse

		cmp dword ptr ds:[pointer_close], 0
		je ignoreMouse


		mov dword ptr ds:[eax + 0x00000188], ebx

		jmp ignoreMouseActionReturn

		ignoreMouse:
		jmp ignoreMouseAddr
	}
}


void hook::TeleportButton() {
	util::detour((PVOID)0x005327FE, isTeleport, 5);
	util::detour((PVOID)0x0044CA75, ignoreMouseAction, 6);
	isMapName();
	SendTeleport();

	//isLoadMapNames();
}