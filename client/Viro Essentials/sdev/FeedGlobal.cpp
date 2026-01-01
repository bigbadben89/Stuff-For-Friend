#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
int arrayPosY[11] = {0x0A, -0x5, -0x14, -0x23, -0x32, -0x41, -0x50, -0x5F, -0x6E, -0x7D,-0x8E};
char isFeedString[20][22]{ "Kill Feed" };
char isByteCount[255];

DWORD fadeWindow = 0x005388E0;
DWORD isKilLFeedMainFunctionReturn = 0x0047E4B0;
_declspec(naked) void isKilLFeedMainFunction() {
    _asm {

        cmp byte ptr ds:[g_showFeed],1
        jne originalcode

        pushad
        mov eax, 150
        mov ecx, 350
        mov edx, dword ptr ds : [ebx + 0x08]
        mov esi, dword ptr ds : [ebx + 0x04]
        add edx, -130
        push 0x00
        push 0xFF101010
        push 0xCD1D1F24
        push eax
        push ecx
        push edx
        push esi
        call fadeWindow
        add esp, 0x1C
        call killFeedMenssageLoop
        popad
        originalcode :
        cmp byte ptr ds : [ebx + 0x000075B6] , 00
        jmp isKilLFeedMainFunctionReturn
        killFeedMenssageLoop:
        xor ebp, ebp
        isStartLoop :


        cmp ebp, 10
        jg pop_close
        test ebp, ebp
        je load1
        cmp ebp, 1
        je load2
        cmp ebp, 2
        je load3
        cmp ebp, 3
        je load4
        cmp ebp, 4
        je load5
        cmp ebp, 5
        je load6
        cmp ebp, 6
        je load7
        cmp ebp, 7
        je load8
        cmp ebp, 8
        je load9
        cmp ebp, 9
        je load10
        cmp ebp,10
        je loadKillFeed
        jmp isContinue
        load1:
        mov esi, offset KillMsg1
        call checkCountry
        lea eax, dword ptr ds : KillMsg1

        movzx ecx,byte ptr ds:[isByteCount+ebp*4]

        cmp byte ptr ds : [KillMsg1+ecx+01] , 00 // light faction
        jne FurySide
        jmp LightSide
        isContinueColor:
        push eax
        push ecx
        call sendPosText
        mov eax, dword ptr ds:[ebx + 0x08]
        mov edi, dword ptr ds:[ebx + 0x04]
        add eax, dword ptr ds:[ebp*4+arrayPosY]
        cmp ebp,10
        je increaseAndContinue
        add edi, 9 // pos X
        continuePos:
        push eax
        push edi
        call loadText
        add esp, 0x10
        isContinue:
        inc ebp
        jmp isStartLoop

        increaseAndContinue:
        add edi,02
        jmp continuePos

        load2:
        mov esi, offset KillMsg2
        call checkCountry
        lea eax, dword ptr ds : KillMsg2
        movzx ecx,byte ptr ds:[isByteCount+ebp*4]
        cmp byte ptr ds : [KillMsg2+ecx+01] , 00 // light faction
        jne FurySide
        LightSide:
        mov ecx,0xFF77A9F9
        jmp isContinueColor
        load3:
        mov esi, offset KillMsg3
        call checkCountry
        lea eax, dword ptr ds : KillMsg3
        movzx ecx,byte ptr ds:[isByteCount+ebp*4]
        cmp byte ptr ds : [KillMsg3+ecx+01] , 00 // light faction
        jne FurySide
        jmp LightSide
        load4:
        mov esi, offset KillMsg4
        call checkCountry
        lea eax, dword ptr ds:KillMsg4
        movzx ecx,byte ptr ds:[isByteCount+ebp*4]
        cmp byte ptr ds : [KillMsg4+ecx+01] , 00 // light faction
        jne FurySide
        jmp LightSide
        load5:
        mov esi, offset KillMsg5
        call checkCountry
        lea eax, dword ptr ds:KillMsg5
        movzx ecx,byte ptr ds:[isByteCount + ebp * 4]
        cmp byte ptr ds : [KillMsg5+ecx+01] , 00 // light faction
        jne FurySide
        jmp LightSide
        load6:
        mov esi, offset KillMsg6
        call checkCountry
        lea eax, dword ptr ds:KillMsg6
        movzx ecx,byte ptr ds:[isByteCount + ebp * 4]
        cmp byte ptr ds : [KillMsg6+ecx+01] , 00 // light faction
        jne FurySide
        jmp LightSide
        load7 :
        mov esi, offset KillMsg7
        call checkCountry
        lea eax, dword ptr ds : KillMsg7
        movzx ecx,byte ptr ds:[isByteCount + ebp * 4]
        cmp byte ptr ds : [KillMsg7+ecx+01] , 00 // light faction
        jne FurySide
        jmp LightSide
        load8 :
        mov esi, offset KillMsg8
        call checkCountry
        lea eax, dword ptr ds : KillMsg8
        movzx ecx,byte ptr ds:[isByteCount + ebp * 4]
        cmp byte ptr ds : [KillMsg8+ecx+01] , 00 // light faction
        jne FurySide
        jmp LightSide
        load9 :
        mov esi, offset KillMsg9
        call checkCountry
        lea eax, dword ptr ds : KillMsg9
        movzx ecx,byte ptr ds:[isByteCount + ebp * 4]
        cmp byte ptr ds : [KillMsg9+ecx+01] , 00 // light faction
        jne FurySide
        jmp LightSide
        load10 :
        mov esi, offset KillMsg10
        call checkCountry
        lea eax, dword ptr ds : KillMsg10
        movzx ecx,byte ptr ds:[isByteCount + ebp * 4]
        cmp byte ptr ds : [KillMsg10+ecx+01] , 00 // light faction
        jne FurySide

        jmp LightSide

        checkCountry:
        xor ecx,ecx
        loopCheckCountry:
        mov al, byte ptr ds:[esi]
        test al,al
        je getByteCount
        inc esi
        inc ecx
        jmp loopCheckCountry
        getByteCount:
        test ecx,ecx
        je pop_close
        movzx edx,byte ptr ds:[isByteCount]
        test edx,edx
        jne incPut
        mov edx,offset isByteCount
        mov byte ptr ds:[edx],cl
        pop_close:
        ret

        FurySide:
        mov ecx,0xFFFF6670
        jmp isContinueColor

        incPut:
        mov edx, offset isByteCount
        mov byte ptr ds : [edx+ebp*4] , cl
        jmp pop_close

        loadKillFeed:
        lea eax,dword ptr ds: isFeedString
        mov ecx,-0x01
        jmp isContinueColor
    }
}


void hook::FeedHook() {
    util::detour((PVOID)0x0047E4A9, isKilLFeedMainFunction,7);
}