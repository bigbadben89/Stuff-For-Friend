#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <array>

#include <include/main.h>
#include <util/util.h>

// Custom kill thresholds per rank (1-32)
std::array<DWORD, 32> customThresholds = {
    1,           // Rank 1
    50,          // Rank 2
    300,         // Rank 3
    1000,        // Rank 4
    2000,        // Rank 5
    4000,        // Rank 6
    6000,        // Rank 7
    8000,        // Rank 8
    10000,       // Rank 9
    15000,       // Rank 10
    20000,       // Rank 11
    30000,       // Rank 12
    40000,       // Rank 13
    60000,       // Rank 14
    80000,       // Rank 15
    100000,      // Rank 16
    200000,      // Rank 17
    400000,      // Rank 18
    600000,      // Rank 19
    1000000,     // Rank 20
    1500000,     // Rank 21
    2000000,     // Rank 22
    3000000,     // Rank 23
    5000000,     // Rank 24
    7500000,     // Rank 25
    10000000,    // Rank 26
    15000000,    // Rank 27
    20000000,    // Rank 28
    25000000,    // Rank 29
    30000000,    // Rank 30
    35000000,    // Rank 31
    69000000     // Rank 32 (final cap)
};

void hook::patch_rank_thresholds()
{
    constexpr DWORD baseAddr = 0x7AEE08; // Rank 1 offset from Game.exe
    DWORD oldProtect;
    SIZE_T byteSize = customThresholds.size() * sizeof(DWORD);

    // Unlock memory for writing
    VirtualProtect(reinterpret_cast<void*>(baseAddr), byteSize, PAGE_EXECUTE_READWRITE, &oldProtect);

    // Write thresholds
    memcpy(reinterpret_cast<void*>(baseAddr), customThresholds.data(), byteSize);

    // Restore memory protection
    VirtualProtect(reinterpret_cast<void*>(baseAddr), byteSize, oldProtect, &oldProtect);
}










