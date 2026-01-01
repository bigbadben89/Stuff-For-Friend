#include "include/main.h"
#include "util/util.h"
#include <strsafe.h>
DWORD searchPlayerbyCharID = 0x004527C0;
DWORD playerExpandReturn = 0x005F1E97;
char packetItem[65];
_declspec(naked) void playerExpand() {
	_asm {

		//cmp word ptr ds:[esp + 0x04],0x01F10
		//je getPacketColorName


		cmp word ptr ds:[esp + 0x04], 0xF51C
		jne originalcode
		pushad
		call getPacketSlot



		cmp byte ptr ds:[packetItem + 0x18], 80
		jne zeroMemory
		cmp byte ptr ds:[packetItem + 0x17], 01
		je setMemory01
		cmp byte ptr ds : [packetItem + 0x17] , 02
		je setMemory02
		cmp byte ptr ds : [packetItem + 0x17] , 03
		je setMemory03
		cmp byte ptr ds : [packetItem + 0x17] , 04
		je setMemory04
		cmp byte ptr ds : [packetItem + 0x17] , 05
		je setMemory05
		cmp byte ptr ds : [packetItem + 0x17] , 06
		je setMemory06
		cmp byte ptr ds : [packetItem + 0x17] , 07
		je setMemory07


		zeroMemory:
        call searchPlayer
		test eax, eax
		je pop_out
		mov byte ptr ds:[eax + 0x381], 00

		jmp pop_out

		zeroMemorySlot2:
		call searchPlayer
		test eax, eax
		je pop_out_2
		mov byte ptr ds : [eax + 0x382] , 00
		jmp pop_out_2

		setMemory01:
		call searchPlayer
		test eax, eax
		je pop_out_2
		mov byte ptr ds : [eax + 0x381] , 01
		jmp pop_out_2

		setMemory02:
		call searchPlayer
		test eax, eax
		je pop_out_2
		mov byte ptr ds : [eax + 0x381] , 02
		jmp pop_out_2


		setMemory03:
		call searchPlayer
		test eax, eax
		je pop_out_2
		mov byte ptr ds : [eax + 0x381] , 03
		jmp pop_out_2

			
		setMemory04:
		call searchPlayer
		test eax, eax
		je pop_out_2
		mov byte ptr ds : [eax + 0x381] , 04
		jmp pop_out_2

			
		setMemory05:
		call searchPlayer
		test eax, eax
		je pop_out_2
		mov byte ptr ds : [eax + 0x381] , 05
		jmp pop_out_2

			
		setMemory06:
		call searchPlayer
		test eax, eax
		je pop_out_2
		mov byte ptr ds : [eax + 0x381] , 06
		jmp pop_out_2

			
		setMemory07:
		call searchPlayer
		test eax, eax
		je pop_out_2
		mov byte ptr ds : [eax + 0x381] , 07
		jmp pop_out_2

			

		pop_out:

		cmp byte ptr ds : [packetItem + 0x14],99
		jne zeroMemorySlot2
		cmp byte ptr ds : [packetItem + 0x13],01
		je setSlotMemory01

		jmp zeroMemorySlot2

		pop_out_2:
		popad


		originalcode:
		mov edx, dword ptr ds:[esp + 0x04]
		movzx eax, dx
		jmp playerExpandReturn

		setSlotMemory01:
		call searchPlayer
		test eax, eax
		je pop_out_2
		mov byte ptr ds : [eax + 0x382] , 01
		jmp pop_out_2



		getPacketSlot:
		mov esi, esp
		mov edi, offset packetItem

		mov ecx, 65
		start_loop:
		mov al, byte ptr ds:[esi + 0x34]
		mov byte ptr ds:[edi + ecx], al
		inc esi
		dec ecx
		test ecx,ecx
		jne start_loop
		ret

		


		


		jmp originalcode


	}
}


void hook::ExpandPlayerMemory() {
	util::detour((PVOID)0x005F1E90, playerExpand, 7);
}