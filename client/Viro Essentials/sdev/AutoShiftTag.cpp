#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
#include <iostream>

// Constants
DWORD click_time = ::GetTickCount();
DWORD Return_Original = 0x534B2B;
DWORD Send_Packet_Menssage = 0x5F1560;

// Prefix for the message
char TargetMessagePrefix[] = "Leader wants you to target: "; //i added this , for this reason then.. yes my assembly is low IQ ... xD

char pointerMenssage[100];

void menssageTarget(const char*name) {

	snprintf(pointerMenssage, sizeof(pointerMenssage), "Leader wants you to target: %s", name);

	std::cout << pointerMenssage << std::endl;
}



_declspec(naked) void Call_Raid_Menssage()
{

	while (true) {

		if ((GetAsyncKeyState(VK_SHIFT) & 0x01)) {

			if (GetTickCount() > click_time + 1000) {
				click_time = GetTickCount();
				_asm {
					cmp byte ptr ds : [0x007C13AC] , 0 // verificar se o jogo tá fechado 
					je originalcode
					cmp byte ptr ds : [0x0090C988] , 1 // verificar se o chat tá aberto 
					je originalcode
					cmp byte ptr ds : [0x022AA730] , 0 // leader
					je Send_Target_Menssage
					cmp byte ptr ds : [0x022AA730] , 1 // sub-	leader 
					je Send_Target_Menssage


					originalcode :
					cmp byte ptr ds : [ebx + 0x000002C8] , 00
						jmp Return_Original


						Send_Target_Menssage :
					pushad
						lea edx, [ebx + 0x121] // CUser:TargetName 
						push edx
						call menssageTarget
						add esp,0x04
						lea edx,[pointerMenssage]
						push edx
						call Send_Packet_Menssage
						add esp, 0x04
						popad
				}

			}
			else
			{
				_asm {
					cmp byte ptr ds : [ebx + 0x000002C8] , 00
					jmp Return_Original
				}
			}

		}
		else _asm {
			cmp byte ptr ds : [ebx + 0x000002C8] , 00
			jmp Return_Original
		}
	}

}


// Hook function to apply the detour
void hook::ShiftTagRaidMenssage()
{
    util::detour((void*)0x534B24, Call_Raid_Menssage, 7);
}
