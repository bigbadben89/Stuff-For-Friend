#include "pch.h"

usign namespace std;
char isKillFeedPacket[100];
char isKillerCharName[30];
char isDeadCharName[30];
int MapID;
int Country;
int setMapName(int MapID) {
	isMapNameFunction(MapID);
	return 0;
}

int killFeedMenssage() {
	FeedMenssage(isMapName, isKillerCharName, isDeadCharName);
	return 0;
}
DWORD isCountBytes = 0;
DWORD sendPacketCWorld = 0x00419120;
DWORD sendKillFeedClientInfoReturn = 0x004652A4;
_declspec(naked)void sendKillFeedClientInfo() {
	_asm {
		



		pushad
		mov edx, dword ptr ds : [esp + 0x34]
		push edx
		call findUserByCharID
		test eax, eax
		je pop_close
		cmp byte ptr ds : [eax + 0x160] , 40 // arena map
		je pop_close
		call getNameKiller
		mov bx,word ptr ds:[edi+0x160] // mapID
		mov word ptr ds:[MapID],bx
		push ebx
	    call setMapName
		add esp,0x04
	    test eax,eax
		jne pop_close
		call killFeedMenssage
		mov word ptr ds:[isKillFeedPacket],0x02F12 // kill feed packet
		call isKillFeedPacketWrite
		mov esi, dword ptr ds:[0x00587960] // CWORLD
		mov eax, [isCountBytes]
		add eax, 04 // LENGHT
		mov edx,[Country]
		mov dword ptr ds:[isKillFeedPacket+eax-01],edx
		lea ecx, dword ptr ds:isKillFeedPacket // DATA
		push eax
		call sendPacketCWorld
		add esp, 0x04



		pop_close:
		popad
		mov edx, dword ptr ds : [esp + 0x14]
		mov eax, 0x00000504
		jmp sendKillFeedClientInfoReturn

		getNameKiller:
		mov edx, offset isKillerCharName
		mov esi,eax
		mov eax,[esi+0x12D] // facction
		mov [Country],eax
		xor ecx, ecx
		xor eax,eax
		start_loop :
		mov al,[esi+0x184]
		mov byte ptr ds : [edx + ecx] , al
		test al, al
		je isGetDeadName
		inc esi
		inc ecx
		jmp start_loop
		isGetDeadName:
		mov edx, offset isDeadCharName
		mov esi, edi // dead player
		xor ecx, ecx
		xor eax, eax
		start_loop_2:
		mov al, [esi + 0x184]
		mov byte ptr ds : [edx + ecx] , al
		test al, al
		je isReturnCallFunction
		inc esi
		inc ecx
		jmp start_loop_2
		isReturnCallFunction:
		ret

		isKillFeedPacketWrite:
		mov edx, offset isKillFeedPacket+02
		mov esi, offset FeedMenssagePointer
		xor ecx,ecx
		start_packet_feed_loop:
		mov al,byte ptr ds:[esi]
		mov byte ptr ds:[edx+ecx],al
		test al,al
		je isReturnCallFunctionGetBytes
		inc esi
		inc ecx
		jmp start_packet_feed_loop

		isReturnCallFunctionGetBytes:
		mov dword ptr ds:[isCountBytes],ecx
		jmp isReturnCallFunction

	}
}


void SendPacketClient() {
	Hook((PVOID)0x0046529B, sendKillFeedClientInfo, 9);

}