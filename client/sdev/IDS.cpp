#include <sstream>
#include <string>
#include <vector>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
#include <map>
using namespace shaiya;

// Define the address to be modified (0x4E6D76 in this case)

// Custom detour function in naked assembly
void _declspec(naked) naked_0x4E6D76()
{
    _asm
    {
        // Custom logic based on the Cheat Engine script
        mov al, byte ptr ds : [0x0090D1D4]
        cmp al, 1                          // Compare AL with 1
        je originalcode                    // Jump to original code if AL == 1
        cmp al, 2                          // Compare AL with 2
        je originalcode                    // Jump to original code if AL == 2
        cmp al, 3                          // Compare AL with 3
        sete al                            // Set AL to 1 if equal
        ret                                // Return

        originalcode :
        mov al, 1                          // Original code: set AL to 1
            ret                                // Return
    }
}

// Function to set up the detour
void hook::viewID()
{
    // Set up the detour to redirect execution to naked_0x4E6D76
    util::detour((void*)0x004E5876, naked_0x4E6D76, 5);

}

using namespace shaiya;

// Forward declaration for helper function
void DisplayMonsterDrops(DWORD monsterID);

// Helper function to display the drops
void DisplayMonsterDrops(DWORD monsterID)
{
    // Example structure of drop data for each monster
    struct DropInfo {
        std::string itemName;
        float dropRate; // In percentage
    };

    // Example monster drop database
    std::map<DWORD, std::vector<DropInfo>> monsterDrops = {
        { 1001, { {"Health Potion", 30.5f}, {"Mana Potion", 15.0f}, {"Rare Sword", 5.0f} } },
        { 1002, { {"Gold Coin", 50.0f}, {"Legendary Shield", 1.0f} } },
        { 1003, { {"Magic Scroll", 20.0f}, {"Crystal", 25.0f} } }
    };

    // Check if the monster exists in the database
    auto it = monsterDrops.find(monsterID);
    if (it != monsterDrops.end()) {
        const std::vector<DropInfo>& drops = it->second;

        // Construct the message to display
        std::ostringstream message;
        message << "Drops for Monster ID " << monsterID << ":\n";
        for (const auto& drop : drops) {
            message << "- " << drop.itemName << ": " << drop.dropRate << "%\n";
        }

        // Display the message (can be shown in-game using game's chat system or message box)
        MessageBoxA(nullptr, message.str().c_str(), "Monster Drops", MB_OK | MB_ICONINFORMATION);
    }
    else {
        // No drops found for this monster
        std::ostringstream message;
        message << "No drop data found for Monster ID " << monsterID;
        MessageBoxA(nullptr, message.str().c_str(), "Monster Drops", MB_OK | MB_ICONEXCLAMATION);
    }
}

// Function to set up the drop-view logic
void hook::viewMonsterDrops()
{
    // Assuming the naked_0x4E6D76 function is already defined elsewhere
    util::detour((void*)0x004E5876, naked_0x4E6D76, 5);
}

