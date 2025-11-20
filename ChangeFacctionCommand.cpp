#include "pch.h"
#include "database.h"
using namespace std;
extern CDataBase g_DBobj;
char packetChangeCountry[130]; // packet lenght

_declspec(naked) void userShape2() {
    _asm {
        mov eax, 0x0303
        mov word ptr ds : [packetChangeCountry] , ax
        mov eax, dword ptr ds : [esi + 0xDC]
        xor edx, edx
        // 4 bytes charID
        mov dword ptr ds : [packetChangeCountry + 02] , eax
        cmp dword ptr ds : [esi + 0x00001444] , 01
        sete dl
        mov byte ptr ds : [packetChangeCountry + 06] , dl
        mov al, byte ptr ds : [esi + 0x144C]// sitting
        mov byte ptr ds : [packetChangeCountry + 07] , al
        mov al, byte ptr ds : [esi + 0x12D] // country
        mov byte ptr ds : [packetChangeCountry + 0x08] , al
        test al, al
        je setneAl
        xor al, al
        mov byte ptr ds : [esi + 0x12D] , al
        mov byte ptr ds : [packetChangeCountry + 0x08] , al
        jmp packetSendShapeContinue

        setneAl :
        mov al, 01
            mov byte ptr ds : [esi + 0x12D] , al
            mov byte ptr ds : [packetChangeCountry + 0x08] , al
            packetSendShapeContinue :
        mov al, byte ptr ds : [esi + 0x12E]
            mov byte ptr ds : [packetChangeCountry + 0x09] , al
            mov al, byte ptr ds : [esi + 0x131] // hair
            mov byte ptr ds : [packetChangeCountry + 0x0A] , al
            mov al, byte ptr ds : [esi + 0x132] // face
            mov byte ptr ds : [packetChangeCountry + 0x0B] , al
            mov al, byte ptr ds : [esi + 0x133] // size
            mov byte ptr ds : [packetChangeCountry + 0x0C] , al
            mov al, byte ptr ds : [esi + 0x135] // sex
            mov byte ptr ds : [packetChangeCountry + 0x0E] , al
            mov al, byte ptr ds : [esi + 0x134] // job
            mov byte ptr ds : [packetChangeCountry + 0x0D] , al
            push esi
            call getPartyValue

            mov byte ptr ds : [packetChangeCountry + 0x0F] , al
            mov al, byte ptr ds : [esi + 0x12F]
            mov byte ptr ds : [packetChangeCountry + 0x10] , al
            mov eax, [esi + 0x148]
            mov dword ptr ds : [packetChangeCountry + 0x11] , eax
            xor ebx, ebx
            mov edi, offset packetChangeCountry + 0x15

            _start_loop :
            cmp ebx, 0x07
            jg backCode
            cmp dword ptr ds : [esi + ebx * 04 + 0x00001C0] , 0
            je continue_clean
            mov ebp, dword ptr ds : [esi + ebx * 04 + 0x00001C0]
            movzx eax, byte ptr ds : [ebp + 0x40]
            movzx edx, byte ptr ds : [ebp + 0x41]
            cmp ebx, 0x07
            je slot_mantle_check
            mov byte ptr ds : [edi + ebx] , al
            mov byte ptr ds : [edi + 01 + ebx] , dl
            add edi, 2
            inc ebx
            jmp _start_loop

            continue_clean :
        mov dword ptr ds : [edi + ebx] , 0x00 // null byte
            mov dword ptr ds : [edi + 0x01 + ebx] , 0x00 // null byte
            add edi, 0x2
            inc ebx
            jmp _start_loop


            slot_mantle_check :
        mov byte ptr ds : [packetChangeCountry + 0x2A] , al
            mov byte ptr ds : [packetChangeCountry + 0x2B] , dl


            backCode :
        call getShapeName
            mov ebx, 0x0E
            xor ecx, ecx
            mov edi, offset packetChangeCountry + 0x31
            wing_pet_costume_loop :
            cmp ebx, 0x0D
            jbe is_end_wing_pet_costume_lop
            cmp ebx, 0x10
            jg is_end_wing_pet_costume_lop

            continue_loop :
        cmp ebx, 0x10
            je wing_packet_shape

            cmp dword ptr ds : [esi + ebx * 04 + 0x1C0] , 0
            je continue_loop_wing_pet_costume_clean
            mov ebp, dword ptr ds : [esi + ebx * 04 + 0x00001C0]
            movzx eax, byte ptr ds : [ebp + 0x40]
            movzx edx, byte ptr ds : [ebp + 0x41]
            mov byte ptr ds : [edi + ebx] , al
            mov byte ptr ds : [edi + 0x01 + ebx] , dl
            add edi, 0x02


            continue_loop_wing_pet_costume :
            inc ebx
            jmp wing_pet_costume_loop


            continue_loop_wing_pet_costume_clean :
        mov dword ptr ds : [edi + ebx] , 0x00
            mov dword ptr ds : [edi + 0x01 + ebx] , 00
            add edi, 0x02
            jmp continue_loop_wing_pet_costume

            wing_clean :
        mov byte ptr ds : [packetChangeCountry + 0x45] , 00
            mov byte ptr ds : [packetChangeCountry + 0x46] , 00
            jmp continue_loop_wing_pet_costume

            wing_packet_shape :
        cmp dword ptr ds : [esi + ebx * 04 + 0x1C0] , 0
            je wing_clean
            mov ebp, dword ptr ds : [esi + ebx * 04 + 0x00001C0]
            movzx eax, byte ptr ds : [ebp + 0x40]
            movzx edx, byte ptr ds : [ebp + 0x41]
            mov byte ptr ds : [packetChangeCountry + 0x45] , al
            mov byte ptr ds : [packetChangeCountry + 0x46] , dl

            is_end_wing_pet_costume_lop :
        xor ebx, ebx // clean ebx register
            mov eax, [esi + 0xE0]
            test eax, eax
            je pop_out
            push 128
            lea edx, dword ptr ds : packetChangeCountry
            push edx
            push eax
            mov eax, [esi + 0x000000E8]
            mov ecx, [esi + 0x000000E4]
            call sendPacketView
            pop_out :
        ret


            getShapeName :
        mov edi, offset packetChangeCountry + 0x48
            mov ecx, 0x00
            mov edx, esi
            loop_get_shape_name :
        mov al, byte ptr ds : [edx + 0x184]
            mov byte ptr ds : [edi + ecx] , al

            cmp al, 0x00
            je _end_loop
            inc ecx
            inc edx
            jmp loop_get_shape_name

            _end_loop :
        mov edi, dword ptr ds : [esi + 0x00001810]
            test edi, edi
            je pop_and_clean_bytes
            cmp byte ptr ds : [packetChangeCountry + 0x2A] , 0 // checking if have mantle or no
            jne mantle_desing_addiotonal_bytes
            mov edx, offset packetChangeCountry + 0x5D
            mov dword ptr ds : [packetChangeCountry + 0x63] , 00
            jmp back_get_guild_name
            mantle_desing_addiotonal_bytes :
        mov dword ptr ds : [packetChangeCountry + 0x5D] , 00
            mov edx, offset packetChangeCountry + 0x63
            back_get_guild_name :
            mov ecx, 0x00
            get_guild_shape_name :
            mov al, [edi + 0x0C]
            mov byte ptr ds : [edx + ecx] , al
            cmp al, 0x00
            je pop_ret
            inc edi
            inc ecx
            jmp get_guild_shape_name
            pop_ret :
        ret

            pop_and_clean_bytes :
        xor edi, edi
            mov dword ptr ds : [packetChangeCountry + 0x63] , edi
            mov dword ptr ds : [packetChangeCountry + 0x5D] , edi
            ret
    }
}
char isCountryCharName[32];
int isCharCharIDCountry;
int getCountryCharID(const std::string& charName) {
    CStringW charCountryIDStr = getCharCountryCharID(charName);
    wstring charCountryIDWStr;
    charCountryIDWStr.assign(charCountryIDStr, charCountryIDStr.GetLength()); // Converte CStringW para wstring

    // Chama ConvertToInt com a string convertida
    int conversionResult = ConvertToInt(charCountryIDWStr, isCharCharIDCountry);
    if (conversionResult != 0) {
        return -1;
    }

    return 0;
}

int getCharIDCountry() {
    int result = getCountryCharID(isCountryCharName);

    return result != -1; // Retorna true se a conversão foi bem-sucedida
}
char packetJoinRaid[32];
BYTE byteCountCharName = 0;
DWORD isLightCharCurrent = 0;
DWORD isDarkCharCurrent = 0;
DWORD PlayerPointer = 0;
DWORD isPlayerDestroyParty = 0x0044F5F0;
DWORD getPacketFcCommandReturn = 0x00474BBE;
DWORD sentPacketClient = 0x004ED0E0;
_declspec(naked) void getPacketFcCommand() {
    _asm {
        cmp word ptr ds : [edi] , 0x02F13
        jne originalcode
        cmp byte ptr ds : [ebx + 0x5808] , 02
        je packetFacctionChange
        cmp byte ptr ds : [ebx + 0x5808] , 03
        je packetFacctionChange
        cmp byte ptr ds : [ebx + 0x5808] , 04
        je packetFacctionChange

        cmp byte ptr ds : [ebx + 0x5808] , 01 // isUserAdmin
        jne isReturnPacket



    packetFacctionChange:
        pushad
            mov eax, [edi + 03] // check nullptr
            test eax, eax
            je pop_out
            mov esi, edi
            call getCountryName



            call getCharIDCountry

            cmp eax, -01
            je pop_out
            mov edx, dword ptr ds : isCharCharIDCountry
            push edx
            call findUserByCharID
            test eax, eax
            je pop_out
            mov dword ptr ds : [PlayerPointer] , eax

            mov esi, eax
            call userShape2

            mov eax, PlayerPointer // restaura o ponteiro do player faccionado

            mov ecx, dword ptr ds : [eax + 0x17F4]
            test ecx, ecx
            je checkCountrySentParty // se não tiver em raid o player faccionado vai tentar pegar a raid
            call isPlayerDestroyParty

            checkCountrySentParty :
        mov eax, PlayerPointer // verificando a facção para enviar o lider correto!
            movzx ecx, byte ptr ds : [eax + 0x12D]
            test cl, cl
            jne sentFuryRaid


            mov eax, isLightCharCurrent
            test eax, eax
            je pop_out
            cmp dword ptr ds : [eax + 0x17F4] , 0
            je pop_out
            mov esi, eax
            call getLeaderName

            continueFuncPacketSent :
        mov word ptr ds : [packetJoinRaid] , 0x02F14
            mov eax, dword ptr ds : packetJoinRaid + 03
            test eax, eax
            je pop_out // func to not sent null packet
            push 32
            lea ecx, dword ptr ds : packetJoinRaid
            push ecx
            mov ecx, PlayerPointer
            call sentPacketClient

            pop_out :
        popad
            isReturnPacket :
        jmp continueFuncPacket

            sentFuryRaid :
        mov eax, isDarkCharCurrent
            test eax, eax
            je pop_out
            cmp dword ptr ds : [eax + 0x17F4] , 0
            je pop_out
            mov esi, eax
            call getLeaderName
            jmp continueFuncPacketSent


            getLeaderName :
        mov edi, offset packetJoinRaid + 0x03
            xor ecx, ecx
            start_loop_get_leader_name :
        mov al, [esi + 0x184]
            mov byte ptr ds : [edi + ecx] , al
            test al, al
            je pop_ret_code
            inc ecx
            inc esi
            jmp start_loop_get_leader_name

            pop_ret_code :
        ret

            originalcode :
        cmp eax, 0x00001C00
            jmp getPacketFcCommandReturn


            getCountryName :
        mov edi, offset isCountryCharName
            xor ecx, ecx
            start_loop_insert_name :
        mov al, byte ptr ds : [esi + 0x03]
            mov byte ptr ds : [edi + ecx] , al
            test al, al
            je pop_ret_func
            inc esi
            inc ecx
            jmp start_loop_insert_name

            pop_ret_func :
        ret

    }
}


DWORD getCharCurrentReturn = 0x00467E1C;
_declspec(naked) void getCharCurrentPvP() {
    _asm {

        cmp byte ptr ds : [edi + 0x12D] , 01 // dark Country
        je getDarkCurrentPvP
        cmp dword ptr ds : [edi + 0x17F4] , 0
        je originalcode
        pushad
        call getLeaderRaidFunc
        cmp edi, ecx
        popad
        jne originalcode

        mov dword ptr ds : [isLightCharCurrent] , edi


        originalcode :
        movzx eax, byte ptr ds : [edi + 0x0000012D] // country
            jmp getCharCurrentReturn

            getDarkCurrentPvP :
        cmp dword ptr ds : [edi + 0x17F4] , 0
            je originalcode
            pushad
            call getLeaderRaidFunc
            cmp edi, ecx
            popad
            jne originalcode
            mov dword ptr ds : [isDarkCharCurrent] , edi // current leader ever
            jmp originalcode

            getLeaderRaidFunc :
        mov eax, dword ptr ds : [edi + 0x17F4]
            mov ecx, dword ptr ds : [eax + 0x0C]
            imul ecx, ecx, 0x8
            add  ecx, 0x18
            mov  ecx, dword ptr ds : [eax + ecx]
            ret
    }
}

void changeFacctionMain() {
   // if (!g_DBobj.LinkDataBase()) return;
  //  Sleep(8000);
    Hook((PVOID)0x00474BB9, getPacketFcCommand, 5);
    Hook((PVOID)0x00467E15, getCharCurrentPvP, 7);
}