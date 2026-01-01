#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
#include "include/shaiya/include/CCharacter.h"


namespace hook {

    void SkillDelayFixed() {
        Nop((LPVOID*)0x4FE8F1, 2);      // Skill delay
        Nop((LPVOID*)0x4FD904, 2);      // ZX delay
        Nop((LPVOID*)0x4FD910, 2);      // Skill delay
        Nop((LPVOID*)0x4FD915, 5);      // Skill delay
        Nop((LPVOID*)0x509D1D, 2);      // Skill delay
        Jump((LPVOID)0x44B308, 0x44C2FA, 6); // Skill delay
    }

}
