
#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
int avaibleRess = 0;
int* windowIndex = reinterpret_cast<int*>(0x007C3C19);
BYTE isDeathWidow = 0;
char currentTimeRessLocal[100];
void imprimirCountdownRessTime(int count) {
    if (count > 0) {
        snprintf(currentTimeRessLocal, sizeof(currentTimeRessLocal),
            "Local resurrection in: %d seconds", count);
    }
    else {
        snprintf(currentTimeRessLocal, sizeof(currentTimeRessLocal),
            "Current location reset available");
    }
}

void updateCountdownRess(int& count) {
   
    if (count == 0) {
        avaibleRess = 1; 
        

        if (isDeathWidow == 0) {
            count = 10;
            avaibleRess = 0; 
        }
    }
    else {
        count--;  
    }
}

DWORD WINAPI getLocalRessTimer(LPVOID lpParam) {
    int count = 10; // Contador inicial de 10 segundos

    // Espera até que isDeathWidow == 3 antes de iniciar a contagem
    while (isDeathWidow != 3) {
        Sleep(100);  // Espera 100ms antes de verificar novamente
    }

    while (true) {
        if (isDeathWidow == 0) {
            // Resetar o contador e esperar até que isDeathWidow seja alterado
            count = 10;
            avaibleRess = 0;

            // printf("Personagem morto, aguardando ress...\n");
            while (isDeathWidow != 3) {
                Sleep(100);
            }
        }

        imprimirCountdownRessTime(count);
        Sleep(1000); // Espera 1 segundo
        updateCountdownRess(count); // Atualiza o contador e o estado
    }

    return 0;
}

DWORD startTimeRessLocalReturn = 0x004DC842;
_declspec(naked) void startTimeRessLocal() {
    _asm {

        cmp eax,07
        jne originalcode
        cmp byte ptr ds : [avaibleRess] , 0
        pushad
        lea eax, dword ptr ds : currentTimeRessLocal
        mov ecx, -0x01
        push eax
        push ecx
        call sendPosText
        mov eax, ebx
        add eax, 85
        add edi, 26
        push eax
        push edi
        call loadText
        add esp, 0x10
        popad
        originalcode:
        push ebx
        push edi
        lea ecx, dword ptr ds : [esi + 0x0000061C]
        cmp eax,07
        jne returntoJump
        push eax
        movzx eax, byte ptr ds : [avaibleRess]
        mov byte ptr ds : [ecx + 04] , al
        pop eax
        returntoJump:
        jmp startTimeRessLocalReturn
    }
}
DWORD getInfoCharacterReturn = 0x004236EA;
_declspec(naked) void getInfoCharacter() {
    _asm {


        cmp byte ptr ds : [esi + 0x000000C1] , 00
        push eax
        mov eax, dword ptr ds : [0x007C3C19]
        mov dword ptr ds : [isDeathWidow] , eax
        pop eax
        jmp getInfoCharacterReturn

    }
}

void hook::RessLocalTimerMain() {
    CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(getLocalRessTimer), NULL, 0, 0);
    util::detour ((PVOID)0x004DC83A, startTimeRessLocal, 8);
    util::detour ((PVOID)0x004236E3, getInfoCharacter, 7);
}