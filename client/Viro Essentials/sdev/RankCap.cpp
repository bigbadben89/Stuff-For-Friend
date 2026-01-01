#include <windows.h>
#include <string>
#include <vector>
#include <include/main.h>
#include <util/util.h>

namespace hook
{
    void RankCap()
    {
        packet_ranks();  // Call the hook function
    }
    void packet_ranks();
}

// Extended custom kill thresholds for 31 ranks
const std::vector<DWORD> g_rankThresholds = {
    1,           50,         300,        1000,       2000,
    4000,        6000,       8000,       10000,      15000,
    20000,       30000,      40000,      60000,      80000,
    100000,      200000,     400000,     600000,     1000000,
    1500000,     2000000,    3000000,    5000000,    7500000,
    10000000,    15000000,   20000000,   25000000,   30000000,
    35000000,    40000000,   45000000,   50000000,   55000000,
    60000000,    63000000,   65000000,   67000000,   69000000
};


// Address where the icon path string is stored
constexpr DWORD g_iconPathAddress = 0x0074A9E0;

// Address where player's PvP kill count is stored
constexpr DWORD g_playerKillsAddress = 0x022AAE3C;

// Return address after our hook runs
constexpr DWORD retIconAddr = 0x49D018;

// Safely write memory
void WriteToMemory(DWORD address, const void* data, size_t size)
{
    DWORD oldProtect;
    VirtualProtect(reinterpret_cast<void*>(address), size, PAGE_EXECUTE_READWRITE, &oldProtect);
    memcpy(reinterpret_cast<void*>(address), data, size);
    VirtualProtect(reinterpret_cast<void*>(address), size, oldProtect, &oldProtect);
}

// Always set icon path to grade2.tga
void SetSharedRankIconPath()
{
    const char* sharedIcon = "grade2.tga";
    WriteToMemory(g_iconPathAddress, sharedIcon, strlen(sharedIcon) + 1);
}

// Calculate rank index based on kill count (supports 46 ranks)
int GetRankIndex(DWORD kills)
{
    for (int i = static_cast<int>(g_rankThresholds.size()) - 1; i >= 0; --i)
    {
        if (kills >= g_rankThresholds[i])
            return i;
    }
    return 0;
}

// Inline hook: injects our logic into rank icon processing
void __declspec(naked) naked_0x49D013()
{
    __asm
    {
        pushad
        pushfd

        mov eax, dword ptr ds : [g_playerKillsAddress] // Get current kills
        push eax
        call GetRankIndex                            // Convert kills to rank index
        add esp, 4

        call SetSharedRankIconPath                   // Force icon to grade2.tga

        popfd
        popad

        jmp retIconAddr
    }
}

// Detour patch
void hook::packet_ranks()
{
    util::detour(reinterpret_cast<void*>(0x49D013), naked_0x49D013, 5);
}






