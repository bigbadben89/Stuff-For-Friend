#pragma once
#include <string>

namespace util
{
    template<typename T>
    T deserialize(unsigned char* buffer, int offset)
    {
        T data{};
        std::memcpy(&data, &buffer[offset], sizeof(T));
        return data;
    }

    int detour(void* addr, void* func, int size);
    int write_memory(void* addr, void* buffer, int size);
    int write_memory(void* addr, int value, int count);
}
extern std::string ownKillTable[32];
extern std::string isOwnKillClose[255];
extern std::string isOwnKillIcon[255];
extern std::string isFace[16];
extern std::string isFace2[16];
extern std::string isFace3[16];
extern std::string isFace4[16];
extern std::string isFace5[16];
extern std::string isFace6[16];
extern std::string isFace7[16];
extern std::string isFace8[16];
extern std::string pvp_list[255];
extern std::string warMove[255];
extern std::string pvp_cover[255];
extern std::string check_btn[255];
extern std::string teleportButton[255];
extern std::string closeButton[255];
extern std::string battleground[255];
extern std::string debuff[255];
extern std::string isPagination[255];
extern std::string isPagination2[255];
extern std::string isCheckChat[255];
extern std::string isClassIconDPSLoad[255];
extern std::string isClassIconRangeLoad[255];
extern std::string isClassIconMagicLoad[255];
extern std::string isClassIconCureLoad[255];
extern std::string isClassIconBloodLoad[255];
extern std::string isClassIconTankLoad[255];
extern int skillbarlock_cmd;
extern int fpsboost_cmd;

extern char OwnKillName[70];
extern char OwnKillName2[70];
extern char OwnKillName3[70];
extern char OwnKillName4[70];
extern char OwnKillName5[70];
extern std::string earth_lapis[16];
extern std::string fire_lapis[16];
extern std::string wind_lapis[16];
extern std::string water_lapis[16];
