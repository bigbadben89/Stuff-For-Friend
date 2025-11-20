#include "pch.h"
#include <cstdio> // Para sprintf ou snprintf
using namespace std;

BYTE countBytes = 0;


const int arrayLenght = 17; // Defina o tamanho do array

int arrayMonster[] = { 835, 1259, 2785, 2803, 2821, 2839, 1800, 1801, 1802, 1803, 1804, 1805, 2469, 2950, 2382, 2383, 1716 };

bool verificaMobID(const int array[], int tamanho, int MobID) {
	for (int i = 0; i < tamanho; ++i) {
		if (array[i] == MobID) {
			return true;
		}
	}
	return false;
}

#define BUFFER_SIZE 256

char buffer[BUFFER_SIZE];
char* mensagemGlobal;

bool imprimirMensagem(int porcentagem, int faccao) {
	switch (faccao) {
	case 0:
		snprintf(buffer, sizeof(buffer), "#bosswarning I am being attacked by the (Alliance of Light), HP: %d%%", porcentagem);
		mensagemGlobal = buffer;
		break;

	case 1:
		snprintf(buffer, sizeof(buffer), "#bosswarning I'm being attacked by the (Union of Fury), HP: %d%%", porcentagem);
		mensagemGlobal = buffer;
		break;

	default:
		return false;
	}

	// Imprime ou faz algo com mensagemGlobal
	//printf("%s\n", mensagemGlobal);

	return true; // Retorno padr?o indicando sucesso
}


int calcularPorcentagem(int vidaAtual, int vidaTotal) {
	int PorcentageMonster; // Declarando a vari?vel aqui

	if (vidaTotal == 0) {
		// Se a vida total for 0, a porcentagem tamb?m ser? 0
		PorcentageMonster = 0;
	}
	else {
		// Calcular a porcentagem da vida restante
		PorcentageMonster = (static_cast<double>(vidaAtual) / vidaTotal) * 100;
	}
	return PorcentageMonster;
}

int isPercent;
int isCountry;

bool isBossMenssage() {
	return imprimirMensagem(isPercent, isCountry);
}


char packetSentAttacked[100];
DWORD isPlayerPointer = 0;
DWORD countBossAttacked = 0;
DWORD sendPacket = 0x0051D7C0;
DWORD is_register_time = 0;
DWORD continuePacketSend = 0x004D55B0;
_declspec(naked) void isBossAttackedNoticeMain() {
	_asm {
		push eax
		mov eax, dword ptr ds : [esp + 0x04]
		cmp eax, 0x0049D483
		je popContinueFunc
		cmp eax, 0x0049D61A
		pop eax


		jne originalcode

		continueFunc :

		inc[countBossAttacked]

			cmp byte ptr ds : [countBossAttacked] , 10
			jge sentPacketAttackedNotice

			jmp originalcode

			sentPacketAttackedNotice :
		mov dword ptr ds : [countBossAttacked] , 0
			mov word ptr ds : [packetSentAttacked] , 0x1108
			pushad
			test ebx, ebx
			je getPlayerPointerFunc
			movzx ecx, byte ptr ds : [ebx + 0x12D]
			continueFuncPlayerCountry :
			mov byte ptr ds : [isCountry] , cl

			movzx ebx, word ptr ds : [edi + 0x2A4]
			push ebx
			mov ecx, arrayLenght
			push ecx
			lea eax, dword ptr ds : arrayMonster
			push eax

			call verificaMobID // check MobIDs
			add esp, 0x0C
			test al, al
			je pop_and_close
			mov ecx, [edi + 0xD4]
			mov edx, [ecx + 0x30]
			push edx
			mov eax, [edi + 0x2A8]
			push eax
			call calcularPorcentagem
			add esp, 0x08
			cmp al, 50 // current percent 100-50% for start show
			jb pop_and_close
			mov byte ptr ds : [isPercent] , al // current porcent 
			call isBossMenssage
			test al, al
			je pop_and_close
			mov esi, [edi + 0xD4]
			mov edx, offset packetSentAttacked + 0x02
			xor ecx, ecx
			xor eax, eax

			start_loop :
		mov al, byte ptr ds : [esi + 0x02]
			mov byte ptr ds : [edx + ecx] , al
			cmp al, 0x00
			je close_func
			inc esi
			inc ecx
			jmp start_loop
			close_func :
		mov esi, offset buffer
			mov edx, offset packetSentAttacked + 0x18
			xor ecx, ecx
			start_loop2 :
		mov al, byte ptr ds : [esi]
			mov[edx + ecx], al
			cmp al, 00
			je close_pop
			inc esi
			inc ecx
			jmp start_loop2

			close_pop :
		mov dword ptr ds : [countBytes] , ecx
			mov dl, byte ptr ds : [countBytes]
			add dl, 0x01
			mov byte ptr ds : [packetSentAttacked + 0x17] , dl
			movzx edi, dl // byte lenght
			push edi
			lea esi, dword ptr ds : buffer
			lea edx, dword ptr ds : [packetSentAttacked + 0x18]
			push esi
			push edx
			call sendPacket
			add esp, 0x0C


			call dword ptr ds : [0x005540D0] // tickount
			mov edx, dword ptr ds : [is_register_time]
			add edx, 20000 // 1.2 seg ms
			cmp eax, edx
			jna pop_and_close
			call dword ptr ds : [0x005540D0]
			mov dword ptr ds : [is_register_time] , eax


			add edi, 0x18
			push edi
			lea eax, dword ptr ds : packetSentAttacked
			push eax
			mov eax, ebp
			call continuePacketSend
			pop_and_close :
		popad


			originalcode :
		mov al, byte ptr ds : [eax + 0x1C]
			ret

			popContinueFunc :
		pop eax
			jmp continueFunc


			getPlayerPointerFunc :
		movzx ecx, byte ptr ds : [ebp + 0x12D]
			jmp continueFuncPlayerCountry


	}
}






void isBossAttackedNotice() {
	Hook((PVOID)0x00458609, isBossAttackedNoticeMain, 5);
}