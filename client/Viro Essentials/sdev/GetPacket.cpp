#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
#include <vector>
#include <iostream>
const size_t MESSAGE_CAPACITY = 10;

std::vector<std::string> messages(MESSAGE_CAPACITY);

void addMessage(const std::string& message, bool isKillMessage) {
	if (!isKillMessage) return;

	// Shift all messages down
	for (size_t i = MESSAGE_CAPACITY - 1; i > 0; --i) {
		messages[i] = messages[i - 1];
	}

	// Insert the new message at the beginning
	messages[0] = message;
}

void printMessages() {
	for (size_t i = 0; i < MESSAGE_CAPACITY; ++i) {
		if (!messages[i].empty()) {
			std::cout << "Message " << i + 1 << ": " << messages[i] << std::endl;
		}
	}
}
#define MAX_MSG_LENGTH 256

// Função para adicionar uma nova mensagem
void addNewMessage(const char* SourceNotice) {
	// Move todas as mensagens uma posição para baixo
	for (int i = 9; i > 0; --i) {
		switch (i) {
		case 1:
			memcpy(KillMsg2, KillMsg1, sizeof(KillMsg2));
			break;
		case 2:
			memcpy(KillMsg3, KillMsg2, sizeof(KillMsg3));
			break;
		case 3:
			memcpy(KillMsg4, KillMsg3, sizeof(KillMsg4));
			break;
		case 4:
			memcpy(KillMsg5, KillMsg4, sizeof(KillMsg5));
			break;
		case 5:
			memcpy(KillMsg6, KillMsg5, sizeof(KillMsg6));
			break;
		case 6:
			memcpy(KillMsg7, KillMsg6, sizeof(KillMsg7));
			break;
		case 7:
			memcpy(KillMsg8, KillMsg7, sizeof(KillMsg8));
			break;
		case 8:
			memcpy(KillMsg9, KillMsg8, sizeof(KillMsg9));
			break;
		case 9:
			memcpy(KillMsg10, KillMsg9, sizeof(KillMsg10));
			break;
		default:
			break;
		}
	}

	// Adiciona a nova mensagem na primeira posição
	memcpy(KillMsg1, SourceNotice, sizeof(KillMsg1));
}
char isSource[255];
void SetMessage() {
	addNewMessage(isSource);
}
char OwnKillName[70];
char OwnKillName2[70];
char OwnKillName3[70];
char OwnKillName4[70];
char OwnKillName5[70];
char KillMsg1[MAX_MSG_LENGTH];
char KillMsg2[MAX_MSG_LENGTH];
char KillMsg3[MAX_MSG_LENGTH];
char KillMsg4[MAX_MSG_LENGTH];
char KillMsg5[MAX_MSG_LENGTH];
char KillMsg6[MAX_MSG_LENGTH];
char KillMsg7[MAX_MSG_LENGTH];
char KillMsg8[MAX_MSG_LENGTH];
char KillMsg9[MAX_MSG_LENGTH];
char KillMsg10[MAX_MSG_LENGTH];
DWORD isKillFeedIndex = 0;
DWORD mensagem = 0x00423150;

DWORD EventModeReceiveReturn = 0x005F4541;
_declspec(naked) void EventModeReceive() {
	_asm {
		cmp word ptr ds : [esp + 0x0C] , 0x02F12
		je getInfoPacket 
		pushad
		cmp word ptr ds : [esp + 0x2C] , 0x01F9
		je writePacketOwnKill
		cmp word ptr ds : [esp + 0x2C] , 0xF182
		je loadErrorMsg
		cmp word ptr ds : [esp + 0x2C] , 0x02F9
		je writePacketOwnKill2
		cmp word ptr ds : [esp + 0x2C] , 0x03F9
		je writePacketOwnKill3
		cmp word ptr ds : [esp + 0x2C] , 0x04F9
		je writePacketOwnKill4
		cmp word ptr ds : [esp + 0x2C] , 0x05F9
		je writePacketOwnKill5
		is_pop_close :
		popad


		originalcode :
		mov edx, [esp + 0x0C]
		push eax
		jmp EventModeReceiveReturn


		writePacketOwnKill :
		mov edi, offset OwnKillName

		callFunc:
		call OwnKillPacket

		jmp is_pop_close

		writePacketOwnKill2 :
		mov edi, offset OwnKillName2
		jmp callFunc

		writePacketOwnKill3 :
		mov edi, offset OwnKillName3
		jmp callFunc

		writePacketOwnKill4 :
		mov edi, offset OwnKillName4
		jmp callFunc

		writePacketOwnKill5 :
		mov edi, offset OwnKillName5
		jmp callFunc


		OwnKillPacket :
		mov esi, esp
		xor ecx, ecx
		mov ebp, 60
		start_loop :
		mov al, byte ptr ds : [esi + 0x2C]
		mov byte ptr ds : [edi + ecx] , al

		inc esi
		inc ecx
		dec ebp
		test ebp, ebp
		jne start_loop

		pop_close :
		ret

		loadErrorMsg:
		push 0x0C
		push 0x2EEF
		push 0x16
		call mensagem
		add esp, 0x0C
		jmp is_pop_close

	    getInfoPacket:
		pushad
		beginFeed :
		mov edi, offset isSource
		isContinue :
		mov esi, esp
		mov ecx, 49
		xor ebp, ebp
		kill_feed_loop :
		mov al, [esi + 0x2C + 0x0A]
		mov byte ptr ds : [edi + ebp] , al
		test ecx, ecx
		je is_pop_close_organize
		inc esi
		inc ebp
		dec ecx
		jmp kill_feed_loop

		is_pop_close_organize :
		call SetMessage
		popad

		jmp originalcode
	}
}

char pvpPacketJoin[50];
DWORD getServerPacketPvPReturn = 0x005F454C;
_declspec(naked) void getServerPacketPvP() {
	_asm {
		mov word ptr ds : [pvpPacketJoin] , 0x00000B11
		cmp word ptr ds : [ecx] , 0x2F14
		je sentPacketFcJoin
		cmp word ptr ds : [ecx] , 0xF581
		je sentPacketPvPJoin
		jmp originalcode
		sentPacketFcJoin :

		pushad

			mov edi, offset pvpPacketJoin + 0x02
			copy_loop :
			mov dl, byte ptr ds : [ecx + 0x03]
			mov byte ptr ds : [edi] , dl
			inc ecx
			inc edi
			cmp dl, 0
			je end_copy

			jmp copy_loop


			end_copy :

		popad
			jmp originalcode
			sentPacketPvPJoin :
		pushad
			mov edi, offset pvpPacketJoin + 0x02
			copy_loop_pvp :
			mov dl, byte ptr ds : [ecx + 0x02]
			mov byte ptr ds : [edi] , dl
			inc ecx
			inc edi
			cmp dl, 0
			je end_copy

			jmp copy_loop_pvp
			originalcode :
		push ecx
			push edx
			push 0x0075D944

			jmp getServerPacketPvPReturn
	}
}
void hook::EventModeMain() {
	util::detour((PVOID)0x005F4545, getServerPacketPvP, 7);
	util::detour((PVOID)0x005F453C, EventModeReceive, 5);
}
