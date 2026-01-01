#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
typedef void (*IsSentPacketFunction)(void*, int);
void callIsSentPacketCountry(void* address, int length, IsSentPacketFunction isSentPacketFunction) {
	isSentPacketFunction(address, length);
}
unsigned char packetChangeCountry[32] = { 0x13, 0x2F };
void packetSentCountry() {
	IsSentPacketFunction funcPtr = reinterpret_cast<IsSentPacketFunction>(0x005EA9A0);
	callIsSentPacketCountry(&packetChangeCountry, 32, funcPtr);
}

DWORD sentCountryCommandReturn = 0x004867CF;
DWORD cmd_jump = 0x487532;
DWORD Comand_imput = 0x00632D07;
DWORD sendPacketServer = 0x005EA9A0;
LPCSTR fcCommand = "!fc";
LPCSTR isEventOnCommand = "!event on";
LPCSTR isEventOffCommand = "!event off";
char pvppacketcommand[50];
_declspec(naked) void sentCountryCommand() {
	_asm {
	    cmp dword ptr ds:[0x0090D1D8],01
	    jne originalcode
		pushad
		push 0x09
		push isEventOnCommand
		push edi
		call Comand_imput
		add esp, 0x0C
		test eax, eax
		jne checkEventDisabled

		mov word ptr ds : [pvppacketcommand] , 0xF180
		lea eax, [pvppacketcommand]
		push 0x02
		push eax
		call sendPacketServer
		add esp, 0x08

		jmp pop_out
		checkEventDisabled:
		push 0x0A
		push isEventOffCommand
		push edi
		call Comand_imput
		add esp, 0x0C
		test eax, eax
		jne labelFacctionChange

		mov word ptr ds : [pvppacketcommand] , 0xF181
		lea eax, [pvppacketcommand]
		push 0x02
		push eax
		call sendPacketServer
		add esp, 0x08

		jmp pop_out

		labelFacctionChange:

		push 0x03
		push fcCommand
		push edi
		call Comand_imput
		add esp, 0x0C
		test eax, eax
		je sendPacketInfo
		pop_out:
		popad
		




		originalcode:
		push eax
	    push edi
		call Comand_imput
		jmp sentCountryCommandReturn



		sendPacketInfo:
		call getCharName
		call packetSentCountry
		jmp pop_out


		getCharName:
		mov esi, edi // char player info
		mov edi, offset packetChangeCountry+0x03 // sent to this addr
		xor ecx, ecx
		start_insert_name:
		mov al, byte ptr ds:[esi + 0x04]
		mov byte ptr ds:[edi + ecx], al
		test al, al
		je pop_ret_out
		inc esi
		inc ecx
		jmp start_insert_name

		pop_ret_out:
		ret
	}
}

DWORD fixCountryClientSideReturn = 0x00453882;
_declspec(naked) void fixCountryClientSide() {
	_asm {
		pushad
		mov ebx, 0x00904AA0
		mov eax, [ebx] //
		test eax, eax
		je pop_out
		mov ecx, dword ptr ds:[eax + 0x34]
		cmp dword ptr ds:[esi + 0x34], ecx
		je setCountryChar
		pop_out :
		popad


		originalcode:
		cmp cl, byte ptr ds:[esi + 0x000002B7]
		jmp fixCountryClientSideReturn


		setCountryChar:
		movzx eax,byte ptr [esi+0x2B7] // country
        mov byte ptr ds:[0x022AA816],al
        mov cl,al
        jmp pop_out
	}
}


void hook::sentCommandCountryMain() {
	util::detour((PVOID)0x004867C8, sentCountryCommand, 7);
	util::detour((PVOID)0x0045387C, fixCountryClientSide, 6);
}