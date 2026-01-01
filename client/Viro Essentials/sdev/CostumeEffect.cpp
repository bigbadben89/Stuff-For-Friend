#include <windows.h>
#include <array>
#include <algorithm>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
#include "include/shaiya/include/CCharacter.h"

using namespace shaiya;

// Function addresses
DWORD Remove_Effect = 0x00416970;
DWORD Render_Effect = 0x0041A2C0;

// ============================================================================
// COSTUME EFFECT CONFIGURATION - 50 AURAS
// ============================================================================
// All effects use vanilla IDs starting at 0xD9
// Effect 0 = 0xD9, Effect 1 = 0xDA, etc.
// Testing: Effects 10+ (0xE3+) for new auras
// ============================================================================
constexpr int MAX_EFFECTS = 50;
constexpr DWORD EFFECT_BASE_ID = 0xD9;

// Costume IDs that trigger each effect (0 = unused)
std::array<int, MAX_EFFECTS> Costume_Effect_IDs = {
    61,  // Effect 0 (0xD9)
    62,  // Effect 1 (0xDA)
    63,  // Effect 2 (0xDB)
    64,  // Effect 3 (0xDC)
    65,  // Effect 4 (0xDD)
    66,  // Effect 5 (0xDE)
    67,  // Effect 6 (0xDF)
    68,  // Effect 7 (0xE0)
    69,  // Effect 8 (0xE1)
    70,  // Effect 9 (0xE2)
    71,  // Effect 10 (0xE3) - Test from here
    72,  // Effect 11 (0xE4)
    73,  // Effect 12 (0xE5)
    74,  // Effect 13 (0xE6)
    75,  // Effect 14 (0xE7)
    76,  // Effect 15 (0xE8)
    77,  // Effect 16 (0xE9)
    78,  // Effect 17 (0xEA)
    79,  // Effect 18 (0xEB)
    80,  // Effect 19 (0xEC)
    81,  // Effect 20 (0xED)
    82,  // Effect 21 (0xEE)
    83,  // Effect 22 (0xEF)
    84,  // Effect 23 (0xF0)
    85,  // Effect 24 (0xF1)
    86,  // Effect 25 (0xF2)
    87,  // Effect 26 (0xF3)
    88,  // Effect 27 (0xF4)
    89,  // Effect 28 (0xF5)
    90,  // Effect 29 (0xF6)
    0,   // Effect 30 - Unused
    0,   // Effect 31 - Unused
    0,   // Effect 32 - Unused
    0,   // Effect 33 - Unused
    0,   // Effect 34 - Unused
    0,   // Effect 35 - Unused
    0,   // Effect 36 - Unused
    0,   // Effect 37 - Unused
    0,   // Effect 38 - Unused
    0,   // Effect 39 - Unused
    0,   // Effect 40 - Unused
    0,   // Effect 41 - Unused
    0,   // Effect 42 - Unused
    0,   // Effect 43 - Unused
    0,   // Effect 44 - Unused
    0,   // Effect 45 - Unused
    0,   // Effect 46 - Unused
    0,   // Effect 47 - Unused
    0,   // Effect 48 - Unused
    0    // Effect 49 - Unused
};

// Find effect index for costume ID (-1 if not found)
int FindCostumeEffect(int costumeID) {
    if (costumeID == 0) return -1;
    for (int i = 0; i < MAX_EFFECTS; i++) {
        if (Costume_Effect_IDs[i] == costumeID) return i;
    }
    return -1;
}

// Render effect by index
void RenderEffectByIndex(void* character, int effectIndex) {
    if (effectIndex < 0 || effectIndex >= MAX_EFFECTS) return;
    
    DWORD effectID = EFFECT_BASE_ID + effectIndex;
    DWORD renderFunc = Render_Effect;
    DWORD removeFunc = Remove_Effect;
    
    __asm {
        pushad
        mov ecx, character
        call removeFunc
        popad
        
        pushad
        fldz
        push 0
        push 0
        push 0
        push 1
        push 1
        fstp dword ptr [esp]
        mov ecx, character
        push 0x02
        push effectID
        call renderFunc
        popad
    }
}

// Render effect without removing
void RenderEffectByIndexNoRemove(void* character, int effectIndex) {
    if (effectIndex < 0 || effectIndex >= MAX_EFFECTS) return;
    
    DWORD effectID = EFFECT_BASE_ID + effectIndex;
    DWORD renderFunc = Render_Effect;
    
    __asm {
        pushad
        fldz
        push 0
        push 0
        push 0
        push 1
        push 1
        fstp dword ptr [esp]
        mov ecx, character
        push 0x02
        push effectID
        call renderFunc
        popad
    }
}

// Remove effect from character
void RemoveCharacterEffect(void* character) {
    DWORD removeFunc = Remove_Effect;
    __asm {
        pushad
        mov ecx, character
        call removeFunc
        popad
    }
}

// ============================================================================
// WEAPON SKIN APPEARANCE
// ============================================================================
// Apply weapon skin - overrides weaponType/weaponTypeId with skin values
void ApplyWeaponSkin(void* esi)
{
    CCharacter* character = (CCharacter*)esi;
    if (!character)
        return;

    // If weapon skin is equipped (type 80 in slot 17), override weapon appearance
    if (character->weaponSkinType != 0)
    {
        character->weaponType = character->weaponSkinType;
        character->weaponTypeId = character->weaponSkinTypeId;
    }
}

// ============================================================================
// EQUIP/UNEQUIP HOOK
// ============================================================================
DWORD Effect_Equip_Return = 0x0059F4A4;

void HandleCostumeEquip(void* esi) {
    BYTE* charPtr = (BYTE*)esi;
    int costumeID = charPtr[0x1B9 + 0xF];
    
    if (costumeID == 0) {
        RemoveCharacterEffect(esi);
        return;
    }
    
    int effectIndex = FindCostumeEffect(costumeID);
    if (effectIndex >= 0) {
        RenderEffectByIndex(esi, effectIndex);
    } else {
        RemoveCharacterEffect(esi);
    }
}

_declspec(naked) void Effect_Costume() {
    _asm {
        cmp byte ptr ds:[esi + ebx + 0x1A8], 0
        jne check_costume_type
        
        pushad
        push esi
        call RemoveCharacterEffect
        add esp, 4
        popad
        jmp originalcode

    check_costume_type:
        // Check for costume type 150 (costume aura)
        cmp byte ptr ds:[esi + ebx + 0x1A8], 150
        jne check_weapon_skin
        
        pushad
        push esi
        call HandleCostumeEquip
        add esp, 4
        popad
        jmp originalcode

    check_weapon_skin:
        // Check for weapon skin type 80
        cmp byte ptr ds:[esi + ebx + 0x1A8], 80
        jne originalcode
        
        pushad
        push esi
        call ApplyWeaponSkin
        add esp, 4
        popad

    originalcode:
        cmp dword ptr ds:[0x90E2F4], edx
        jmp Effect_Equip_Return
    }
}

// ============================================================================
// RESPAWN HOOKS
// ============================================================================
DWORD Respawn_Return = 0x005EB875;
DWORD Respawn_Return_2 = 0x0059547A;

void HandleRespawnEffect(void* esi) {
    BYTE* charPtr = (BYTE*)esi;
    int costumeID = charPtr[0x1B9 + 0xF];
    
    int effectIndex = FindCostumeEffect(costumeID);
    if (effectIndex >= 0) {
        RenderEffectByIndexNoRemove(esi, effectIndex);
    }
    
    // Also apply weapon skin on respawn/login/map change
    ApplyWeaponSkin(esi);
}

_declspec(naked) void Show_Effect_When_Respawn() {
    _asm {
        push eax
        mov eax, 0x0059546B
        cmp [esp + 0x04], eax
        pop eax
        je Check_Costumes_ID

    originalcode:
        mov eax, 0x00002008
        jmp Respawn_Return

    Check_Costumes_ID:
        pushad
        push esi
        call HandleRespawnEffect
        add esp, 4
        popad
        jmp originalcode
    }
}

_declspec(naked) void Show_Effect_When_Respawn_2() {
    _asm {
        pushad
        push esi
        call HandleRespawnEffect
        add esp, 4
        popad

    originalcode:
        mov ecx, esi
        mov [esi + 0x000002C0], bl
        jmp Respawn_Return_2
    }
}

// ============================================================================
// MAP CHANGE HOOK
// ============================================================================
DWORD Effect_Map_Return = 0x004162F5;

_declspec(naked) void Effect_When_Change_Map() {
    _asm {
        push eax
        mov eax, 0x00418FA7
        cmp [esp + 0x04], eax
        pop eax
        jne originalcode

        pushad
        push esi
        call HandleRespawnEffect
        add esp, 4
        popad

    originalcode:
        mov eax, [esp + 0x04]
        push esi
        jmp Effect_Map_Return
    }
}

// ============================================================================
// HOOK INITIALIZATION
// ============================================================================
void hook::CostumeEffect() {
    util::detour((void*)0x0059F49E, Effect_Costume, 6);
    util::detour((void*)0x005EB870, Show_Effect_When_Respawn, 5);
    util::detour((void*)0x00595472, Show_Effect_When_Respawn_2, 8);
    util::detour((void*)0x004162F0, Effect_When_Change_Map, 5);
}
