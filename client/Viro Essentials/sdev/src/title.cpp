#include <map>
#include <set>
#include <tuple>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
#include "include/shaiya/include/CCharacter.h"
#include "include/shaiya/include/CDataFile.h"
#include "include/shaiya/include/CMonster.h"
#include "include/shaiya/include/CStaticText.h"
#include "include/shaiya/include/ItemInfo.h"
#include "include/shaiya/include/HexColor.h"
using namespace shaiya;

#ifndef D3DX_PI
#define D3DX_PI 3.14159265358979323846f
#endif

// External reference to Titulo setting from GraphicOptions.cpp
extern BYTE Titulo;

namespace title
{
    using ItemId = uint32_t;

    // Constants for better maintainability
    constexpr float kTitleYOffset = 30.0f;
    constexpr float kChatYAdd = 1.75f;
    constexpr float kRainbowSpeed = 10000.0f;  // Lower = faster color change
    constexpr float kTwoPi = 2.0f * D3DX_PI;
    constexpr float kPhaseOffset1 = 2.0944f;   // 2*PI/3 for green
    constexpr float kPhaseOffset2 = 4.1888f;   // 4*PI/3 for blue

    // Title data structure - includes rainbow flag
    struct TitleInfo {
        const char* text;
        HexColor color;
        bool isRainbow;
    };

    // Cache to track current title per character to detect changes
    std::map<CCharacter*, ItemId> characterTitleCache;

    // Cleanup title text and release resources
    void CleanupTitle(CCharacter* user)
    {
        if (!user)
            return;

        if (user->title.text)
        {
            // Release the D3D texture if present
            if (user->title.text->texture)
            {
                user->title.text->texture->Release();
                user->title.text->texture = nullptr;
            }
            // The SStaticText struct is allocated by the game engine
            // We set to nullptr to prevent dangling pointer
            user->title.text = nullptr;
            user->title.pointX = 0;
        }

        // Remove from cache
        characterTitleCache.erase(user);
    }

    std::map<ItemId, TitleInfo> items
    {
        { 24028, { "The Flash", HexColor::Orange, false } },
        { 24029, { "Gladiator", HexColor::Orange, false } },
        { 24030, { "Guild Master", HexColor::Orange, false } },
        { 24031, { "Guild Officer", HexColor::Orange, false } },
        { 24032, { "Guild Guardian", HexColor::Orange, false } },
        { 24033, { "Origins", HexColor::Crimson, false } },
        { 24034, { "Ashigaru", HexColor::Crimson, false } },
        { 24035, { "Samourai", HexColor::Crimson, false } },
        { 24036, { "Damiyo", HexColor::Crimson, false } },
        { 24037, { "Semi God", HexColor::Indigo, false } },
        { 24038, { "Beserker", HexColor::Indigo, false } },
        { 24039, { "The Guardian", HexColor::Indigo, false } },
        { 24040, { "Shinobi", HexColor::Indigo, false } },
        { 24041, { "Legolas", HexColor::Indigo, false } },
        { 24042, { "Sourcerer", HexColor::Indigo, false } },
        { 24043, { "Holy Support", HexColor::Indigo, false } },
        { 24044, { "Cresus", HexColor::Gold, false } },
        { 24045, { "Musk", HexColor::Gold, false } },
        { 24046, { "Cleopatre", HexColor::Gold, false } },
        { 24047, { "Gold Digger", HexColor::Gold, false } },
        { 24048, { "Solomon", HexColor::Gold, false } },
        { 24049, { "Witch", HexColor::Teal, false } },
        { 24050, { "Paladin", HexColor::MediumSpringGreen, false } },
        { 24051, { "Shaman", HexColor::GoldenRod, false } },
        { 24052, { "Druid", HexColor::FireBrick, false } },
        { 24053, { "Death Knight", HexColor::GreenYellow, true } },      // Rainbow
        { 24054, { "High Priestess", HexColor::Chartreuse, true } },     // Rainbow
        { 24055, { "Interloper", HexColor::Crimson, false } },
        { 24056, { "Crazy Cat Lady", HexColor::HotPink, true } },        // Rainbow
        { 24057, { "Mercenary", HexColor::Salmon, false } },
        { 24058, { "Salty", HexColor::BlueViolet, true } },              // Rainbow
        { 24059, { "MVP", HexColor::CadetBlue, false } },
        { 24060, { "Old School", HexColor::PowderBlue, true } },         // Rainbow
        { 24061, { "Cryptic", HexColor::FireBrick, false } },
        { 24062, { "Chill Player", HexColor::SaddleBrown, true } },      // Rainbow
        { 24063, { "Farmer", HexColor::AntiqueWhite, true } },           // Rainbow
        { 24064, { "Enigmatic", HexColor::LawnGreen, false } },
        { 24065, { "Rich", HexColor::Gold, false } },
        { 24066, { "Fairy", HexColor::Orchid, false } },
        { 24067, { "Survivor", HexColor::SpringGreen, false } },
        { 24068, { "Untouchable", HexColor::SteelBlue, false } },
        { 24069, { "Maniac", HexColor::LimeGreen, false } },
        { 24104, { "Love Fool", HexColor::DeepPink, false } },
        { 24105, { "Archivist", HexColor::LightSlateBlue, false } },
        { 24106, { "Hero", HexColor::Turquoise, false } },
        { 24107, { "Mad Scientist", HexColor::DodgerBlue, false } },
        { 24108, { "DEV", HexColor::MediumSlateBlue, true } },           // Rainbow
        { 24109, { "Staff Member", HexColor::Magenta, true } },          // Rainbow
        { 24110, { "Game Master", HexColor::DarkGoldenRod, true } },     // Rainbow
        { 24114, { "Content Creator", HexColor::RosyBrown, false } },
    };

    // Calculate rainbow color based on time
    inline DWORD GetRainbowColor()
    {
        ULONGLONG tick = GetTickCount64();
        float time = fmodf(static_cast<float>(tick) / kRainbowSpeed, 1.0f) * kTwoPi;

        int r = static_cast<int>(sinf(time) * 127.0f + 128.0f);
        int g = static_cast<int>(sinf(time + kPhaseOffset1) * 127.0f + 128.0f);
        int b = static_cast<int>(sinf(time + kPhaseOffset2) * 127.0f + 128.0f);

        return D3DCOLOR_ARGB(255, r, g, b);
    }

    void hook(CCharacter* user, float x, float y, float extrusion)
    {
        // Check if titles are enabled in graphics options
        // Titulo == 1 means titles should be shown (checked), Titulo == 0 means hidden (unchecked)
        if (Titulo == 0)
            return;

        if (!user || !user->mantleType || !user->mantleTypeId)
        {
            // Clean up if user has no title item equipped
            CleanupTitle(user);
            return;
        }

        auto itemInfo = CDataFile::GetItemInfo(user->mantleType, user->mantleTypeId);
        if (!itemInfo)
        {
            CleanupTitle(user);
            return;
        }

        auto itemId = static_cast<ItemId>((itemInfo->type * 1000) + itemInfo->typeId);

        auto it = items.find(itemId);
        if (it == items.end())
        {
            CleanupTitle(user);
            return;
        }

        const TitleInfo& titleInfo = it->second;
        
        if (!titleInfo.text || !titleInfo.text[0])
        {
            CleanupTitle(user);
            return;
        }

        // Check if title changed - if so, clean up old one first
        auto cacheIt = characterTitleCache.find(user);
        if (cacheIt != characterTitleCache.end() && cacheIt->second != itemId)
        {
            // Title changed, clean up old resources
            CleanupTitle(user);
        }

        // Determine color - rainbow or static
        DWORD color = titleInfo.isRainbow 
            ? GetRainbowColor() 
            : std::to_underlying(titleInfo.color);

        // Create title text if not exists
        if (!user->title.text)
        {
            user->title.text = CStaticText::Create(titleInfo.text);
            if (!user->title.text)
                return;
                
            auto w = CStaticText::GetTextWidth(titleInfo.text);
            user->title.pointX = static_cast<int>(w * 0.5f);
            
            // Cache the current title item
            characterTitleCache[user] = itemId;
        }

        float posY = y - kTitleYOffset;
        float posX = x - static_cast<float>(user->title.pointX);

        CStaticText::Draw(user->title.text, static_cast<int>(posX), static_cast<int>(posY), extrusion, color);
    }
}

unsigned u0x453E81 = 0x453E81;
void __declspec(naked) naked_0x453E7C()
{
    __asm
    {
        pushad
        pushfd

        sub esp, 0xC
        fld dword ptr[esp + 0x4C]
        fstp dword ptr[esp + 0x8]

        fld dword ptr[esp + 0x48]
        fstp dword ptr[esp + 0x4]

        fld dword ptr[esp + 0x44]
        fstp dword ptr[esp]

        push esi // user
        call title::hook
        add esp, 0x10

        popfd
        popad

        // original
        mov eax, dword ptr ds : [0x22B69A8]
        jmp u0x453E81
    }
}

unsigned n0x4184CF = 0x4184CF;
unsigned u0x418312 = 0x418312;
void __declspec(naked) naked_0x41830D()
{
    __asm
    {
        // monster->model
        cmp dword ptr[eax + 0x74], 0x0
        je _0x4184CF

        // original
        cmp dword ptr[esp + 0x38], 0x0
        jmp u0x418312

        _0x4184CF :
        jmp n0x4184CF
    }
}

unsigned u0x412765 = 0x412765;
void __declspec(naked) naked_0x41275F()
{
    __asm
    {
        fld dword ptr[title::kChatYAdd]
        jmp u0x412765
    }
}

void hook::title()
{
    util::detour((void*)0x453E7C, naked_0x453E7C, 5);
    // hide pets without a model
    util::detour((void*)0x41830D, naked_0x41830D, 5);
    // increase chat balloon height (1.5 to 1.75)
    util::detour((void*)0x41275F, naked_0x41275F, 6);
}
