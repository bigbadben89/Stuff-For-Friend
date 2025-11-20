#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
bool windowOpen = true;
DWORD numpadEnabled = true;
bool shiftPressed = false;
bool shiftClick = false;

void windowCheck() {
    while (true) {
        if (*(BYTE*)0x007C13AC == 0x01) {
            windowOpen = true;
            //ExitProcess(0);
        }
        else {
            windowOpen = false;
        }
        Sleep(10);
    }
}

void disableNumpad2() {

    numpadEnabled = false;

}

void enableNumpad2() {

    numpadEnabled = true;
}

void checkShiftState() {
    while (true) {
        bool isShiftPressed = GetAsyncKeyState(VK_SHIFT) & 0x8000;

        if (isShiftPressed && !shiftPressed) {
            disableNumpad2();
        }
        else if (!isShiftPressed && shiftPressed) {
            enableNumpad2();
        }

        shiftPressed = isShiftPressed;
        Sleep(100);
    }
}


int mainKeyBoard() {
    CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(checkShiftState), NULL, 0, 0);

    return 0;
}

DWORD u_0x0042DA90 = 0x0042DC90;
DWORD Enable_Shift_Holding_Return = 0x004FF388;
DWORD Enable_Shift_Holding_Continue = 0x004FF44D;
_declspec(naked) void Enable_Shift_Holding() {
    _asm {

        cmp byte ptr ds : [shiftPressed] , 01
        je check_esi
        cmp byte ptr ds : [esi + 0x00000124] , 02
        je noUseKeySkill

        originalcode :
        push 0x02
            call u_0x0042DA90
            jmp Enable_Shift_Holding_Return


            check_esi :
        cmp byte ptr ds : [esi + 0x00000124] , 02
            je originalcode
            jmp Enable_Shift_Holding_Continue


            noUseKeySkill :
        jmp Enable_Shift_Holding_Continue



    }

}
DWORD addr_005009A1 = 0x004FF381;
DWORD allow3rdskillbarreturn = 0x004FF2A0;
_declspec(naked) void allow3rdskillbar() {
    _asm {
        cmp byte ptr ds : [esi + 0x00000124] , 02
        je u_005009A1

        originalcode :
        mov eax, dword ptr ds : [0x007C0E8C]
            jmp allow3rdskillbarreturn

            u_005009A1 :
        jmp addr_005009A1
    }
}

DWORD fade_addr = 0x004FFF3C;
DWORD ignore_fade_addr = 0x004FFFAB;
DWORD enable_fade_shift_return = 0x004FFE77;
_declspec(naked) void Enable_Fade_Shift() {
    _asm {

        cmp byte ptr ds : [shiftPressed] , 01
        je send_fade


        cmp byte ptr ds : [edi + 0x124] , 02
        je ignore_fade

        originalcode :
        cmp byte ptr ds : [edi + 0x00000124] , 00
            jmp enable_fade_shift_return

            send_fade :
        cmp byte ptr ds : [edi + 0x00000124] , 00
            je ignore_fade
            cmp byte ptr ds : [edi + 0x00000124] , 01
            je ignore_fade
            mov edx, [esp + 0x14]
            jmp fade_addr

            ignore_fade :
        jmp ignore_fade_addr
    }
}
DWORD isAddrDisableUseShift = 0x004FF147;
DWORD checkif3rdSkillBarIsEnableReturn = 0x004FF053;
_declspec(naked) void checkif3rdSkillBarIsEnable() {
    _asm {
        //    cmp byte ptr ds : [isShiftEnable] , 01
        jmp disableUseShift

        originalcode :
        mov eax, dword ptr ds : [ebp + 0x00000404]
            jmp checkif3rdSkillBarIsEnableReturn

            disableUseShift :
        jmp isAddrDisableUseShift
    }
}


void hook::HoldShiftEnableKeyBar() {
    mainKeyBoard();
    util::detour((PVOID)0x004FF04D, checkif3rdSkillBarIsEnable, 6);


    util::detour((PVOID)0x004FF29B, allow3rdskillbar, 5);
    util::detour((void*)0x004FF381, Enable_Shift_Holding, 7);
    util::detour((void*)0x004FFE70, Enable_Fade_Shift, 7);
}