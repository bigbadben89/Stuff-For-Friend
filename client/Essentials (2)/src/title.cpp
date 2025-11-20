#include <map>
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

namespace title
{
    using ItemId = uint32_t;

    std::map<ItemId, std::tuple<const char*, HexColor>> items
    {
        { 24028, { "The Flash", HexColor::Orange } },
        { 24029, { "Gladiator", HexColor::Orange } },
        { 24030, { "Guild Master", HexColor::Orange } },
        { 24031, { "Guild Officer", HexColor::Orange } },
        { 24032, { "Guild Guardian", HexColor::Orange } },
        { 24033, { "Origins", HexColor::Crimson } },
        { 24034, { "Ashigaru", HexColor::Crimson } },
        { 24035, { "Samourai", HexColor::Crimson } },
        { 24036, { "Damiyo", HexColor::Crimson } },
        { 24037, { "Semi God", HexColor::Indigo } },
        { 24038, { "Beserker", HexColor::Indigo } },
        { 24039, { "The Guardian", HexColor::Indigo } },
        { 24040, { "Shinobi", HexColor::Indigo } },
        { 24041, { "Legolas", HexColor::Indigo } },
        { 24042, { "Sourcerer", HexColor::Indigo } },
        { 24043, { "Holy Support", HexColor::Indigo } },
        { 24044, { "Cresus", HexColor::Gold } },
        { 24045, { "Musk", HexColor::Gold } },
        { 24046, { "Cleopatre", HexColor::Gold } },
        { 24047, { "Gold Digger", HexColor::Gold } },
        { 24048, { "Solomon", HexColor::Gold } },
        { 24049, { "Witch", HexColor::Teal } },
        { 24050, { "Paladin", HexColor::MediumSpringGreen } },
        { 24051, { "Shaman", HexColor::GoldenRod } },
        { 24052, { "Druid", HexColor::FireBrick } },
        { 24053, { "Death Knight", HexColor::GreenYellow } },
        { 24054, { "High Priestess", HexColor::Chartreuse } },
        { 24055, { "Interloper", HexColor::Crimson } },
        { 24056, { "Crazy Cat Lady", HexColor::HotPink } },
        { 24057, { "Mercenary", HexColor::Salmon } },
        { 24058, { "Salty", HexColor::BlueViolet } },
        { 24059, { "MVP", HexColor::CadetBlue } },
        { 24060, { "Old School", HexColor::PowderBlue } },
        { 24061, { "Cryptic", HexColor::FireBrick } },
        { 24062, { "Chill Player", HexColor::SaddleBrown } },
        { 24063, { "Farmer", HexColor::AntiqueWhite } },
        { 24064, { "Enigmatic", HexColor::LawnGreen } },
        { 24065, { "Rich", HexColor::Gold } },
        { 24066, { "Fairy", HexColor::Orchid } },
        { 24067, { "Survivor", HexColor::SpringGreen } },
        { 24068, { "Untouchable", HexColor::SteelBlue } },
        { 24069, { "Maniac", HexColor::LimeGreen } },
        { 24104, { "Love Fool", HexColor::DeepPink } },
        { 24105, { "Archivist", HexColor::LightSlateBlue } },
        { 24106, { "Hero", HexColor::Turquoise } },
        { 24107, { "Mad Scientist", HexColor::DodgerBlue } },
        { 24108, { "DEV", HexColor::MediumSlateBlue } },
        { 24109, { "Staff Member", HexColor::Magenta } },
        { 24110, { "Game Master", HexColor::DarkGoldenRod } },
        { 24114, { "Content Creator", HexColor::RosyBrown } },
    };

    constexpr float chat_y_add = 1.75F;

    void hook(CCharacter* user, float x, float y, float extrusion)
    {
        if (!user || !user->mantleType || !user->mantleTypeId)
            return;

        auto itemInfo = CDataFile::GetItemInfo(user->mantleType, user->mantleTypeId);
        if (!itemInfo)
            return;

        auto itemId = (itemInfo->type * 1000) + itemInfo->typeId;

        auto it = items.find(itemId);
        if (it == items.end())
            return;

        const char* text = std::get<0>(it->second);
        if (!text || !*text)
            return;

        DWORD color = std::to_underlying(std::get<1>(it->second));

        // Safe animated rainbow for certain titles only
        if (strcmp(text, "Death Knight") == 0 ||// rainbow color titles
            strcmp(text, "High Priestess") == 0 ||
            strcmp(text, "Crazy Cat Lady") == 0 ||
            strcmp(text, "Salty") == 0 ||
            strcmp(text, "Old School") == 0 ||
            strcmp(text, "Chill Player") == 0 ||
            strcmp(text, "DEV") == 0 ||
            strcmp(text, "Farmer") == 0 ||
            strcmp(text, "Staff Member") == 0 ||
            strcmp(text, "Game Master") == 0)
        {
            ULONGLONG tick = GetTickCount64();
            float time = fmodf(tick / 10000.0f, 1.0f) * 2.0f * D3DX_PI;// same here we can change speed of the change 

            int r = static_cast<int>(sinf(time) * 127 + 128);
            int g = static_cast<int>(sinf(time + 2.0944f) * 127 + 128);
            int b = static_cast<int>(sinf(time + 4.1888f) * 127 + 128);

            color = D3DCOLOR_ARGB(255, r, g, b);
        }

        if (!user->title.text)
        {
            user->title.text = CStaticText::Create(text);
            if (user->title.text)
            {
                auto w = CStaticText::GetTextWidth(text);
                user->title.pointX = int(w * 0.5);
            }
        }

        if (!user->title.text)
            return;

        auto posY = y - 30.0;
        auto posX = x - user->title.pointX;

        CStaticText::Draw(user->title.text, int(posX), int(posY), extrusion, color);
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
        fld dword ptr[title::chat_y_add]
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
