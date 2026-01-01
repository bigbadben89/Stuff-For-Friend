#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <array>

#include <include/main.h>
#include <util/util.h>

// Global points table (must be global for ASM to reference as [Points + edi*4])
int Points[34] = {
    0,
    1,  // Rank 1
    2,  // Rank 2
    3,  // Rank 3
    4,  // Rank 4
    5,  // Rank 5
    6,  // Rank 6
    7,  // Rank 7
    8,  // Rank 8
    9,  // Rank 9
    10, // Rank 10
    11, // Rank 11
    12, // Rank 12
    12, // Rank 13
    13, // Rank 14
    13, // Rank 15
    13, // Rank 16
    14, // Rank 17
    14, // Rank 18
    14, // Rank 19
    14, // Rank 20
    15, // Rank 21
    15, // Rank 22
    15, // Rank 23
    15, // Rank 24
    15, // Rank 25
    15, // Rank 26
    15, // Rank 27
    15, // Rank 28
    15, // Rank 29
    15, // Rank 30
    15, // Rank 31
    15,
    15
   
};

// Address to jump back to after the hook
unsigned u0x542112 = 0x542112;

// Naked hook function for detour
__declspec(naked) void naked_0x54210D()
{
    __asm
    {
        push edi
        movzx edi, byte ptr ds : [0x7C273C]        // Load rank index (0–31) into edi
        mov eax, [Points + edi * 4]              // Get Points[edi]
        pop edi
        mov dword ptr ds : [0x7C1930] , eax         // Write result to 0x7C1930
        jmp u0x542112                            // Jump back to game code
    }
}

// Entry point to install the hook
void hook::vet_manager()
{
    util::detour((void*)0x54210D, naked_0x54210D, 5);
}


