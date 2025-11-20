#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"

LPCSTR isMap1 = "Dungeon 2 (floor 3)";
LPCSTR isMap2 = "Caelum Sacra (floor 3)";
LPCSTR isMap3 = "Deep Desert 1";
LPCSTR isMap4 = "Deep Desert 2";
LPCSTR isMap5 = "Jungle";
LPCSTR isMap6 = "Proelium";
LPCSTR isMap7 = "Cantabilian";
LPCSTR isMap8 = "Auction House";
LPCSTR isMap9 = "Caelum Greendieta (Floor 1)";
LPCSTR isMap10 = "Pandorashys / Ranhaar";
LPCSTR isMap11 = "Cloron / Fantasma Lair";
LPCSTR isMap12 = "Oblivion Insula";
LPCSTR isMap13 = "Stigma / Aurizen Ruins";
LPCSTR isMap14 = "Capital";
LPCSTR isMap15 = "EC / RC";
LPCSTR isMap16 = "Sky Arena";
LPCSTR isMap17 = "Dungeon 1";
char save_pos_y_2[48];
char save_pos_x_2[48];
DWORD sendPosText = 0x00631BE0;
DWORD loadText = 0x00531640;
DWORD isColor = -0x55AA55;
DWORD isMapNamesReturn = 0x00532816;
__declspec(dllexport) _declspec(naked) void isMapNames() {
	_asm {
		

		cmp dword ptr ds:[pointer_close], 01
		je originalcode
		pushad
		pushfd
		xor ebp, ebp
		start_loop :
		cmp ebp, 8
		jg end_loop
		cmp ebp, 0
		je load_map1
		cmp ebp, 1
		je load_map2
		cmp ebp, 2
		je load_map3
		cmp ebp, 3
		je load_map4
		cmp ebp, 4
		je load_map5
		cmp ebp, 5
		je load_map6
		cmp ebp, 6
		je load_map7
		cmp ebp, 7
		je load_map8
		cmp ebp, 8
		je load_pagination
		jmp continue_

		load_map1 :
		cmp byte ptr ds:[isPointerPagination], 01
		jne map_continue
		mov eax,dword ptr ds:isMap9
		lea eax,[eax]
		jmp continue_load
		map_continue :
		mov eax, dword ptr ds : isMap1
		lea eax,[eax]
		jmp continue_load
		load_map2 :
		cmp byte ptr ds:[isPointerPagination], 01
		jne map_continue2
		mov eax, dword ptr ds : isMap10
		lea eax,[eax]
		jmp continue_load
		map_continue2 :
		mov eax, dword ptr ds : isMap2
		lea eax, [eax]
		jmp continue_load
		load_map3 :
		cmp byte ptr ds:[isPointerPagination], 01
		jne map_continue3
		mov eax, dword ptr ds : isMap11
		lea eax, [eax]
		jmp continue_load
		map_continue3 :
		mov eax, dword ptr ds : isMap3
		lea eax, [eax]
		jmp continue_load
		load_map4 :
		cmp byte ptr ds:[isPointerPagination], 01
		jne map_continue4
		mov eax, dword ptr ds : isMap12
		lea eax, [eax]
		jmp continue_load
		map_continue4 :
		mov eax, dword ptr ds : isMap4
		lea eax, [eax]
		jmp continue_load
		load_map5 :
		cmp byte ptr ds:[isPointerPagination], 01
		jne map_continue5
		mov eax, dword ptr ds : isMap13
		lea eax, [eax]
		jmp continue_load
		map_continue5 :
		mov eax, dword ptr ds : isMap5
		lea eax, [eax]
		jmp continue_load
		load_map6 :
		cmp byte ptr ds:[isPointerPagination], 01
		jne map_continue6
		mov eax, dword ptr ds : isMap14
		lea eax, [eax]
		jmp continue_load
		map_continue6 :
		mov eax, dword ptr ds : isMap6
		lea eax, [eax]
		jmp continue_load
		load_map7 :
		cmp byte ptr ds:[isPointerPagination], 01
		jne map_continue7
		mov eax, dword ptr ds : isMap15
		lea eax, [eax]
		jmp continue_load
		map_continue7 :
		mov eax, dword ptr ds : isMap7
		lea eax, [eax]
		jmp continue_load
		load_map8 :
		cmp byte ptr ds:[isPointerPagination], 01
		jne map_continue8
		mov eax, dword ptr ds : isMap16
		lea eax, [eax]
		jmp continue_load
		map_continue8 :
		mov eax, dword ptr ds: isMap8
		lea eax,[eax]
		jmp continue_load
		load_pagination :
		lea eax, dword ptr ds:paginationCount


		continue_load:
		mov ecx, dword ptr ds:[isColor]
		push eax
		push ecx
		call sendPosText
		mov eax, dword ptr ds:[isSavePosY]
		mov edi, dword ptr ds:[isSavePosX]
		add eax, 0x39
		add edi, 0x15
		mov dword ptr ds:[save_pos_y_2], eax
		mov dword ptr ds:[save_pos_x_2], edi
		add eax, 0x20
		mov dword ptr ds:[save_pos_y_2 + 04], eax
		mov dword ptr ds:[save_pos_x_2 + 04], edi
		add eax, 0x20
		mov dword ptr ds:[save_pos_y_2 + 0x08], eax
		mov dword ptr ds:[save_pos_x_2 + 0x08], edi
		add eax, 0x20
		mov dword ptr ds:[save_pos_y_2 + 0x0C], eax
		mov dword ptr ds:[save_pos_x_2 + 0x0C], edi
		add eax, 0x20
		mov dword ptr ds:[save_pos_y_2 + 0x10], eax
		mov dword ptr ds:[save_pos_x_2 + 0x10], edi
		add eax, 0x20
		mov dword ptr ds:[save_pos_y_2 + 0x14], eax
		mov dword ptr ds:[save_pos_x_2 + 0x14], edi
		add eax, 0x20
		mov dword ptr ds:[save_pos_y_2 + 0x18], eax
		mov dword ptr ds:[save_pos_x_2 + 0x18], edi
		add eax, 0x20
		mov dword ptr ds:[save_pos_y_2 + 0x1C], eax
		mov dword ptr ds:[save_pos_x_2 + 0x1C], edi
		add eax, 0x30
		add edi, 0x5B
		mov dword ptr ds:[save_pos_y_2 + 0x20], eax
		mov dword ptr ds:[save_pos_x_2 + 0x20], edi
		add eax, 0x20
		mov dword ptr ds:[save_pos_y_2 + 0x24], eax
		mov dword ptr ds:[save_pos_x_2 + 0x24], edi
		mov eax, dword ptr ds:[ebp * 0x4 + save_pos_y_2]
		mov edi, dword ptr ds:[ebp * 0x4 + save_pos_x_2]
		push eax
		push edi
		call loadText
		add esp, 0x10
		continue_:
		inc ebp
		jmp start_loop
		popfd
		popad




		originalcode:
		mov edx, dword ptr ds:[esi + 0x08]
		mov ebx, dword ptr ds:[0x0090D1E4]
		jmp isMapNamesReturn


		end_loop:
		popfd
		popad
		jmp originalcode

	}
}


void isMapName() {
	util::detour((PVOID)0x0053280D, isMapNames, 9);
}