#include "pch.h"
#include <random>
#include <ctime>
int BalanceLightRaidFunction(int MembersLight, int MembersDark) {
    int total = MembersLight + MembersDark;
    int target = total / 2; // alvo ideal por lado


    if (MembersLight > target) {
        return MembersLight - target;
    }

    return 0;
}

int BalanceFuryRaidFunction(int MembersLight, int MembersDark) {
    int total = MembersLight + MembersDark;
    int target = total / 2; // alvo ideal por lado


    if (MembersDark > target) {
        return MembersDark - target;
    }

    return 0;
}

int randomGenMembersBalance(int Members) {
    if (Members <= 0) return 0;

    int maxValue = (Members * 8) - 8;
    int steps = Members; // quantidade de múltiplos de 8 de 0 até maxValue

    std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<int> dist(0, steps); // de 0 a membros

    int resultado = dist(rng) * 8;
    return resultado;
}

// Exemplo de uso
int getPlayersBalanced(int Members) {

    int valor = randomGenMembersBalance(Members);


    return valor;
}



int BalanceRaidFunction(int MembersLight, int MembersDark) {


    int returnLightMove = BalanceLightRaidFunction(MembersLight, MembersDark);

    return returnLightMove;
}
int BalanceRaidFuryFunction(int MembersLight, int MembersDark) {


    int returnFuryMove = BalanceLightRaidFunction(MembersLight, MembersDark);

    return returnFuryMove;
}
DWORD getMainRaidReturn = 0x00467E2A;
DWORD currentRaidLight = 0;
DWORD currentRaidFury = 0;
_declspec(naked) void getMainRaid() {
    _asm {

        cmp byte ptr ds : [edi + 0x12D] , 01
        je getRaidFury
        cmp dword ptr ds : [edi + 0x000017F4] , 00
        je originalcode

        pushad
        mov eax, dword ptr ds : [edi + 0x17F4]
        test eax, eax
        je closeFunction
        mov dword ptr ds : [currentRaidLight] , eax
        closeFunction :
        popad

            originalcode :
        mov edx, dword ptr ds : [edi + 0x0000582C]

            jmp getMainRaidReturn

            getRaidFury :
        cmp dword ptr ds : [edi + 0x000017F4] , 00
            je originalcode

            pushad
            mov eax, dword ptr ds : [edi + 0x17F4]
            test eax, eax
            je closeFunction
            mov dword ptr ds : [currentRaidFury] , eax

            jmp closeFunction


    }
}
char packetJoinRaidBalance[32];
DWORD tickTime = 0;
DWORD MainBalanceFunctionReturn = 0x004035BE;
DWORD balancePlayerPointer = 0;
DWORD playerCountBalance = 0;
DWORD loopCountBalance = 0;

_declspec(naked) void MainBalanceFunction() {
    _asm {

        cmp dword ptr ds : [balancePointer] , 01
        jne originalcode

        pushad

        call dword ptr ds : [0x005540D0]
        mov edx, dword ptr ds : [tickTime]
        add edx, 1000 // 1 second
        cmp eax, edx
        jna closeFunc
        call dword ptr ds : [0x005540D0]
        mov dword ptr ds : [tickTime] , eax


        mov eax, dword ptr ds : currentRaidLight
        test eax, eax
        je closeFunc
        mov ebx, dword ptr ds : currentRaidFury
        test ebx, ebx
        je closeFunc
        mov edx, dword ptr ds : [eax + 0x10]
        test edx, edx
        je closeFunc
        mov esi, dword ptr ds : [ebx + 0x10]
        test esi, esi
        je closeFunc
        cmp edx, esi
        jg checkBalanceDifference
        cmp esi, edx
        jg checkBalanceDifferenceFury




    closeFunc:
        popad

            originalcode :
        mov ecx, dword ptr ds : [0x0058796C]
            jmp MainBalanceFunctionReturn

            checkBalanceDifference :
        sub edx, esi
            cmp edx, 02 // difference 
            jb closeFunc // no major


            mov edx, dword ptr ds : [eax + 0x10]
            mov esi, dword ptr ds : [ebx + 0x10]
            push esi
            push edx
            call BalanceRaidFunction
            add esp, 0x08

            xor esi, esi
            mov dword ptr ds : [loopCountBalance] , esi
            startBalanceLoopFunction :
        cmp dword ptr ds : [loopCountBalance] , eax
            jg closeFunc

            push eax
            call getPlayersBalanced
            add esp, 0x04

            mov edx, dword ptr ds : currentRaidLight
            test edx, edx
            je closeFunc
            mov edi, [edx + 0x18 + eax]
            mov esi, [isLightCharCurrent]
            cmp edi, esi
            je closeFunc
            balanceLoopFunction :
        mov dword ptr ds : [balancePlayerPointer] , edi
            cmp edi, -0x01
            je closeFunc
            test edi, edi
            je closeFunc
            mov esi, edi
            call userShape2
            mov eax, balancePlayerPointer // restaura o ponteiro do player faccionado

            mov ecx, dword ptr ds : [eax + 0x17F4]
            test ecx, ecx
            je checkCountrySentParty // se não tiver em raid o player faccionado vai tentar pegar a raid
            call isPlayerDestroyParty

            checkCountrySentParty :
        mov eax, balancePlayerPointer // verificando a facção para enviar o lider correto!
            movzx ecx, byte ptr ds : [eax + 0x12D]
            test cl, cl
            jne sentFuryRaid


            mov eax, isLightCharCurrent
            test eax, eax
            je continueLoopBalance
            cmp dword ptr ds : [eax + 0x17F4] , 0
            je continueLoopBalance
            mov esi, eax
            call getLeaderName

            continueFuncPacketSent :
        mov word ptr ds : [packetJoinRaidBalance] , 0x02F14
            mov eax, dword ptr ds : packetJoinRaidBalance + 03
            test eax, eax
            je continueLoopBalance // func to not sent null packet
            push 32
            lea ecx, dword ptr ds : packetJoinRaidBalance
            push ecx
            mov ecx, balancePlayerPointer
            call sentPacketClient

            continueLoopBalance :
        inc[loopCountBalance]
            jmp startBalanceLoopFunction

            sentFuryRaid :
        mov eax, isDarkCharCurrent
            test eax, eax
            je continueLoopBalance
            cmp dword ptr ds : [eax + 0x17F4] , 0
            je continueLoopBalance
            mov esi, eax
            call getLeaderName
            jmp continueFuncPacketSent


            getLeaderName :
        mov edi, offset packetJoinRaidBalance + 0x03
            xor ecx, ecx
            start_loop_get_leader_name :
        mov al, [esi + 0x184]
            mov byte ptr ds : [edi + ecx] , al
            test al, al
            je pop_ret_code
            inc ecx
            inc esi
            jmp start_loop_get_leader_name

            pop_ret_code :
        ret

            checkBalanceDifferenceFury :
        sub esi, edx
            cmp esi, 02 // difference 
            jb closeFunc // no major


            mov edx, dword ptr ds : [eax + 0x10]
            mov esi, dword ptr ds : [ebx + 0x10]
            push esi
            push edx
            call BalanceFuryRaidFunction
            add esp, 0x08

            xor esi, esi
            mov dword ptr ds : [loopCountBalance] , esi
            cmp dword ptr ds : [loopCountBalance] , eax
            jg closeFunc

            push eax
            call getPlayersBalanced
            add esp, 0x04

            mov edx, dword ptr ds : currentRaidFury
            test edx, edx
            je closeFunc
            mov edi, [edx + 0x18 + eax]
            mov esi, [isDarkCharCurrent]
            cmp esi, edi
            je closeFunc

            jmp balanceLoopFunction



    }
}
DWORD EraseRaidRetn = 0x0044F6CD;
_declspec(naked) void EraseRaid() {
    _asm {

        pushad
        cmp byte ptr ds : [esi + 0x12D] , 0
        jne sideFury
        mov eax, [esi + 0x17F4]
        cmp byte ptr ds : [eax + 0x10] , 02
        jbe eraseRaidLight
        popClose :
        popad

            mov dword ptr ds : [esi + 0x17F4] , 0
            jmp EraseRaidRetn

            eraseRaidLight :
        mov eax, [esi + 0x17F4]
            mov edx, [currentRaidLight]
            cmp eax, edx
            jne popClose
            mov dword ptr ds : [currentRaidLight] , 0
            jmp popClose

            eraseRaidFury :
        mov eax, [esi + 0x17F4]
            mov edx, [currentRaidFury]
            cmp eax, edx
            jne popClose
            mov dword ptr ds : [currentRaidFury] , 0
            jmp popClose

            sideFury :
        mov eax, [esi + 0x17F4]
            cmp byte ptr ds : [eax + 0x10] , 02
            jbe eraseRaidFury
            jmp popClose


    }
}

void autoBalance() {
    Hook((PVOID)0x00467E24, getMainRaid, 6);
    Hook((PVOID)0x004035B8, MainBalanceFunction, 6);
    Hook((PVOID)0x0044F6C3, EraseRaid, 10);
}