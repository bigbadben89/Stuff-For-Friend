#include "include/main.h"
#include <util/util.h>
const char* stringFind = "#bosswarning";
const char* stringFind2 = "[Boss]";
DWORD originalStack = 0;
char resultado[100]; 
void extrairSubstring(const char* mensagemPrincipal, const char* substring) {

    const char* posicao = strstr(mensagemPrincipal, substring);


    if (posicao == nullptr) {
        return;
    }


    int indiceInicial = posicao - mensagemPrincipal + strlen(substring) + 1;

    
    strcpy_s(resultado, sizeof(resultado), posicao + strlen(substring) + 1);
}


bool encontrarSubstring(const char* mensagemPrincipal, const char* substring) {
   
    if (strstr(mensagemPrincipal, substring) != nullptr) {
        return true;
    }
    else {
        return false;
    }
}

DWORD setColorWarningReturn = 0x004D848E;
_declspec(naked) void setColorWarning() {
    _asm {
        pushad

        mov eax,stringFind2 
        lea eax,[eax]
        push eax
        lea edx,[edi]
        push edx
        call encontrarSubstring
        add esp,0x08
        test al,al
        je pop_original
        
        jmp pop_continue

        pop_original:
        popad

        originalcode:
        push 0xFFFF80FF
        jmp setColorWarningReturn 

        pop_continue:
        popad
        push 0xFFFFFF00
        jmp setColorWarningReturn
    }
}
DWORD sendStringSysmsg = 0x00420990;
DWORD extractAndSetBossWarningReturn = 0x0059C84F;
DWORD extractAndSetBossWarningReturn2 = 0x0059C85B;
_declspec(naked) void  extractAndSetBossWarning() {
    _asm {
        mov dword ptr ds:[originalStack],eax
        pushad
        mov ebx, stringFind
        lea ebx, [ebx]
        push ebx
        lea edx, [eax]
        push edx
        
        call encontrarSubstring
        add esp, 0x08


        test al, al
        je pop_original
        mov eax,[originalStack]

        mov ebx,stringFind
        lea ebx,[ebx]
        push ebx
        lea edx,[eax]
        push edx
        call extrairSubstring
        add esp,0x08
        popad
        mov eax,offset resultado 

        push eax
        push 0x007C1D38
        call sendStringSysmsg
        push 0x34
        push 12016

        jmp extractAndSetBossWarningReturn2

        originalcode:
        push eax
        push 0x007C1D38
        jmp extractAndSetBossWarningReturn

        pop_original:
        popad
        jmp originalcode
    }
}

void hook::BossWarning() {
    util::detour((PVOID)0x004D8489, setColorWarning, 5);
    util::detour((PVOID)0x0059C849, extractAndSetBossWarning, 6);
}