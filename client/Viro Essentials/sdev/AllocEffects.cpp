#include <windows.h>
#include <array>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"

// ============================================================================
// EFFECT FILE CONFIGURATION - 50 EFFECTS
// ============================================================================
// All effects use vanilla pattern: 0xD9, 0xDA, 0xDB, etc.
// Memory addresses follow the original pattern:
// Effect 0 @ 0x022CB704, Effect 1 @ 0x022CBA88, then +0x12C spacing
// ============================================================================

constexpr int MAX_ALLOC_EFFECTS = 50;

// Hardcoded addresses matching original vanilla pattern
DWORD Effect_Addresses[MAX_ALLOC_EFFECTS] = {
    0x022CB704,  // Effect 0 (0xD9)
    0x022CBA88,  // Effect 1 (0xDA)
    0x022CBBB4,  // Effect 2 (0xDB)
    0x022CBCE0,  // Effect 3 (0xDC)
    0x022CBE0C,  // Effect 4 (0xDD)
    0x022CBF38,  // Effect 5 (0xDE)
    0x022CC064,  // Effect 6 (0xDF)
    0x022CC190,  // Effect 7 (0xE0)
    0x022CC2BC,  // Effect 8 (0xE1)
    0x022CC3E8,  // Effect 9 (0xE2)
    0x022CC514,  // Effect 10 (0xE3)
    0x022CC640,  // Effect 11 (0xE4)
    0x022CC76C,  // Effect 12 (0xE5)
    0x022CC898,  // Effect 13 (0xE6)
    0x022CC9C4,  // Effect 14 (0xE7)
    0x022CCAF0,  // Effect 15 (0xE8)
    0x022CCC1C,  // Effect 16 (0xE9)
    0x022CCD48,  // Effect 17 (0xEA)
    0x022CCE74,  // Effect 18 (0xEB)
    0x022CCFA0,  // Effect 19 (0xEC)
    0x022CD0CC,  // Effect 20 (0xED)
    0x022CD1F8,  // Effect 21 (0xEE)
    0x022CD324,  // Effect 22 (0xEF)
    0x022CD450,  // Effect 23 (0xF0)
    0x022CD57C,  // Effect 24 (0xF1)
    0x022CD6A8,  // Effect 25 (0xF2)
    0x022CD7D4,  // Effect 26 (0xF3)
    0x022CD900,  // Effect 27 (0xF4)
    0x022CDA2C,  // Effect 28 (0xF5)
    0x022CDB58,  // Effect 29 (0xF6)
    0x022CDC84,  // Effect 30 (0xF7)
    0x022CDDB0,  // Effect 31 (0xF8)
    0x022CDEDC,  // Effect 32 (0xF9)
    0x022CE008,  // Effect 33 (0xFA)
    0x022CE134,  // Effect 34 (0xFB)
    0x022CE260,  // Effect 35 (0xFC)
    0x022CE38C,  // Effect 36 (0xFD)
    0x022CE4B8,  // Effect 37 (0xFE)
    0x022CE5E4,  // Effect 38 (0xFF)
    0x022CE710,  // Effect 39 (0x100)
    0x022CE83C,  // Effect 40 (0x101)
    0x022CE968,  // Effect 41 (0x102)
    0x022CEA94,  // Effect 42 (0x103)
    0x022CEBC0,  // Effect 43 (0x104)
    0x022CECEC,  // Effect 44 (0x105)
    0x022CEE18,  // Effect 45 (0x106)
    0x022CEF44,  // Effect 46 (0x107)
    0x022CF070,  // Effect 47 (0x108)
    0x022CF19C,  // Effect 48 (0x109)
    0x022CF2C8   // Effect 49 (0x10A)
};

// Effect file names
const char* Effect_Files[MAX_ALLOC_EFFECTS] = {
    "Aura_Advanced_L_AS.EFT",   // Effect 0 (0xD9)
    "Aura_Advanced_F_A.EFT",    // Effect 1 (0xDA)
    "Aura_Advanced_F_AS.EFT",   // Effect 2 (0xDB)
    "Aura_Advanced_F_SS.EFT",   // Effect 3 (0xDC)
    "Aura_Advanced_F_S.EFT",    // Effect 4 (0xDD)
    "Aura_Advanced_L_SS.EFT",   // Effect 5 (0xDE)
    "Aura_Tianshen_1.EFT",      // Effect 6 (0xDF)
    "Aura_Tianshen_2.EFT",      // Effect 7 (0xE0)
    "Aura_Tianshen_3.EFT",      // Effect 8 (0xE1)
    "Aura_Tianshen_4.EFT",      // Effect 9 (0xE2)
    "Aura_Tianshen_6.EFT",      // Effect 10 (0xE3)
    "Aura_Tianshen_7.EFT",      // Effect 11 (0xE4)
    "Aura_Tianshen_8.EFT",      // Effect 12 (0xE5)
    "Aura_BodyShine.EFT",       // Effect 13 (0xE6)
    "Aura_Tianshen_1.EFT",      // Effect 14 (0xE7)
    "Aura_Tianshen_2.EFT",      // Effect 15 (0xE8)
    "Aura_Tianshen_3.EFT",      // Effect 16 (0xE9)
    "Aura_Advanced_F_A.EFT",    // Effect 17 (0xEA)
    "Aura_Advanced_F_AS.EFT",   // Effect 18 (0xEB)
    "Aura_Advanced_F_S.EFT",    // Effect 19 (0xEC)
    "Aura_Advanced_F_SS.EFT",   // Effect 20 (0xED)
    "Aura_Advanced_L_A.EFT",    // Effect 21 (0xEE)
    "efeito23.eft",             // Effect 22 (0xEF)
    "efeito24.eft",             // Effect 23 (0xF0)
    "efeito25.eft",             // Effect 24 (0xF1)
    "efeito26.eft",             // Effect 25 (0xF2)
    "efeito27.eft",             // Effect 26 (0xF3)
    "efeito28.eft",             // Effect 27 (0xF4)
    "efeito29.eft",             // Effect 28 (0xF5)
    "efeito30.eft",             // Effect 29 (0xF6)
    "",                          // Effect 30 - Unused
    "",                          // Effect 31 - Unused
    "",                          // Effect 32 - Unused
    "",                          // Effect 33 - Unused
    "",                          // Effect 34 - Unused
    "",                          // Effect 35 - Unused
    "",                          // Effect 36 - Unused
    "",                          // Effect 37 - Unused
    "",                          // Effect 38 - Unused
    "",                          // Effect 39 - Unused
    "",                          // Effect 40 - Unused
    "",                          // Effect 41 - Unused
    "",                          // Effect 42 - Unused
    "",                          // Effect 43 - Unused
    "",                          // Effect 44 - Unused
    "",                          // Effect 45 - Unused
    "",                          // Effect 46 - Unused
    "",                          // Effect 47 - Unused
    "",                          // Effect 48 - Unused
    ""                           // Effect 49 - Unused
};

DWORD Send_Load_Effect = 0x0058C460;
DWORD Alloc_Return = 0x0042BDB4;
DWORD Effect_Address = 0x0042BC77;

// C++ function to load all effects
bool LoadAllEffects() {
    DWORD loadFunc = Send_Load_Effect;
    LPCSTR effectPath = (LPCSTR)0x00748864;  // "data/effect"
    bool allSuccess = true;
    
    for (int i = 0; i < MAX_ALLOC_EFFECTS; i++) {
        if (Effect_Files[i] == nullptr || Effect_Files[i][0] == '\0') {
            continue;
        }
        
        DWORD effectAddr = Effect_Addresses[i];
        LPCSTR effectFile = Effect_Files[i];
        int result = 0;
        
        __asm {
            push effectFile
            push effectPath
            mov ecx, effectAddr
            call loadFunc
            mov result, eax
        }
        
        if (result == 0) {
            allSuccess = false;
        }
    }
    
    return allSuccess;
}

_declspec(naked) void Alloc_Effects() {
    _asm {
        pushad
        call LoadAllEffects
        test al, al
        popad
        je Effect_Continue
        
        push 0x00749E74
        push 0x00748864
        jmp Alloc_Return

    Effect_Continue:
        jmp Effect_Address
    }
}

void hook::AllocEffects() {
    util::detour((void*)0x0042BDAA, Alloc_Effects, 5);
}
