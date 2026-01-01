#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"

using namespace std;
std::string mensagemGlobal;
string hpMenssagem;

void imprimirMensagem(int porcentagem) {
	mensagemGlobal = std::to_string(porcentagem) + "%";

}

char currentbuffer[50];

void imprimirCurrentHP(int currentHP) {
	snprintf(currentbuffer, sizeof(currentbuffer), "HP: %d%", currentHP);
	mensagemGlobal = currentbuffer;
}

char buffer[50];

std::string test = "HP: ";
void imprimirHPMenssagem(int CurrentHP, int MaxHP) {

	int charsWritten = std::snprintf(buffer, sizeof(buffer), "%s%d", test.c_str(), CurrentHP);

	if (CurrentHP == 0 && MaxHP == 0) {
		mensagemGlobal = "Dead";
	}

	else if (MaxHP == 0) {

		if (charsWritten >= 0 && static_cast<std::size_t>(charsWritten) < sizeof(buffer)) {
			hpMenssagem = buffer;
		}

		else {
			hpMenssagem = "Dead";
		}
	}

	else {
		mensagemGlobal = std::to_string(CurrentHP) + "/" + std::to_string(MaxHP);
	}
}




int maxIncrement = 2;
int modeVariable = 0;

void incrementGlobalVariable() {
	if (modeVariable < maxIncrement) {
		modeVariable++;
	}
	else {
		modeVariable = 0;
	}
}
bool rightButtonDown = false;
ULONGLONG lastTickCountReward = 0;  // Fixed: Changed from DWORD to ULONGLONG for GetTickCount64
DWORD tickIntervalReward = 250;
void modeMouseChange() {
	ULONGLONG currentTickCount = GetTickCount64();  // Fixed: Changed from DWORD to ULONGLONG
	if (GetAsyncKeyState(VK_RBUTTON) & 0x8000) {
		if (!rightButtonDown) {
			rightButtonDown = true;
			if (currentTickCount - lastTickCountReward >= tickIntervalReward) {
				incrementGlobalVariable();
				lastTickCountReward = currentTickCount;
			}
		}
	}
	else {
		rightButtonDown = false;
	}
}

DWORD load_info_string2 = 0x00631BE0;
DWORD send_string2 = 0x00531640;
BYTE PorcentageEnemy = 0;
DWORD showEnemyPercentReturn = 0x00534ADE;
DWORD get_pos_x_ = 0;
DWORD get_pos_y_ = 0;
DWORD isBarPointer = 0;
LPCSTR isDeathString = "Dead";
DWORD redColor = 0xFFFF0000;
_declspec(naked) void showEnemyPercent() {
	_asm {

		//mov eax, dword ptr ds : [0x0090E2F4]
		//cmp eax, [ebx + 0x34]
		//je originalcode

		cmp dword ptr ds : [ebx + 0x15C] , 0
		je renderDeath
		cmp dword ptr ds : [ebx + 0x158] , 0
		je renderDeath

		mov eax, [esi + 0x08]
		mov dword ptr ds : [get_pos_y_] , eax
		mov eax, [esi + 0x04]
		mov dword ptr ds : [get_pos_x_] , eax

		mov eax, dword ptr ds : [0x7C3C10]// y mouse
		mov edx, [get_pos_y_] // posição y do objeto
		sub eax, 16
		cmp eax, edx
		jl continue
		add edx, 32
		cmp eax, edx
		jg continue
		mov eax, dword ptr ds : [0x7C3C0C]// x mouse
		mov edx, [get_pos_x_]
		add edx, 30
		cmp eax, edx
		jb continue
		add edx, 170
		cmp eax, edx
		jg continue

		pushad

		call modeMouseChange

		popad


		continue:

		cmp byte ptr ds : [modeVariable] , 00
			je continue_func // default 

			cmp byte ptr ds : [modeVariable] , 01
			je currentHP // default 

			cmp byte ptr ds : [modeVariable] , 02
			je hpMode2

			continue_func :
		pushad
			pushfd
			mov esi, ebx
			mov eax, [esi + 0x0000015C]
			mov ebx, [esi + 0x00000158]
			sub eax, ebx
			imul eax, eax, 0x64
			cdq
			mov ebx, [esi + 0x0000015C]
			test ebx, ebx
			je division_per_zero

			idiv ebx
			mov ebx, 0x00000064
			sub ebx, eax
			mov eax, ebx
			mov byte ptr ds : [PorcentageEnemy] , al
			jmp pop_end
			division_per_zero :
		mov[PorcentageEnemy], 00

			pop_end :
			movzx eax, byte ptr ds : [PorcentageEnemy]
			push eax
			call imprimirMensagem
			add esp, 0x04
			popfd
			popad



		renderMessage:
		pushad
			cmp byte ptr ds : [modeVariable] , 1
			jne normalMessage
			lea eax, [currentbuffer]
			jmp continue_
			normalMessage :
		lea eax, [mensagemGlobal]
			continue_ :
			mov ecx, -0x225F22 // white color default
			continue_2 :
			push eax
			push ecx
			call sendPosText
			mov eax, [get_pos_y_]
			mov edi, [get_pos_x_]
			add eax, 22 // pos y
			add edi, 90 // pos X
			push eax
			push edi
			call loadText
			add esp, 0x10
			popad


			originalcode :
		movzx eax, byte ptr ds : [ebx + 0x000002EC]
			jmp showEnemyPercentReturn



		hpMode:
		mov eax, dword ptr ds : [ebx + 0x158]
			xor edx, edx
			push edx
			push eax
			call imprimirHPMenssagem
			add esp, 0x08
			sub[get_pos_x_], 29
			jmp renderMessage


			hpMode2 :
		mov eax, dword ptr ds : [ebx + 0x15C]
			mov edx, dword ptr ds : [ebx + 0x158]
			push eax
			push edx
			call imprimirHPMenssagem
			add esp, 0x08
			sub[get_pos_x_], 20
			jmp renderMessage


			currentHP :
		mov edx, dword ptr ds : [ebx + 0x158]
			push edx
			call imprimirCurrentHP
			add esp, 0x04
			sub[get_pos_x_], 35
			jmp renderMessage

			renderDeath :
		pushad
			mov eax, [esi + 0x08]
			mov dword ptr ds : [get_pos_y_] , eax
			mov eax, [esi + 0x04]
			mov dword ptr ds : [get_pos_x_] , eax

			mov eax, [isDeathString]
			lea eax, [eax]
			mov ecx, [redColor]
			jmp continue_2


	}
}




void hpmode() {
	util::detour((PVOID)0x00534AD7, showEnemyPercent, 7);
}

// Thread wrapper function with correct signature for CreateThread
DWORD WINAPI hpmodeThread(LPVOID lpParam) {
	hpmode();
	return 0;
}