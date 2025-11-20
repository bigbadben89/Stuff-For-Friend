#include "pch.h"

char packetChangeAppareance[130]; // packet lenght
DWORD sendPacketView = 0x00427470;
DWORD getPartyValue = 0x0049B120;
DWORD sendEquipament = 0x00492C00;
_declspec(naked) void userShape() {
    _asm {
        mov eax, 0x0303
        mov word ptr ds : [packetChangeAppareance] , ax
        mov eax, dword ptr ds : [esi + 0xDC]
        xor edx, edx
        // 4 bytes charID
        mov dword ptr ds : [packetChangeAppareance + 02] , eax
        cmp dword ptr ds : [esi + 0x00001444] , 01
        sete dl
        mov byte ptr ds : [packetChangeAppareance + 06] , dl
        mov al, byte ptr ds : [esi + 0x144C]// sitting
        mov byte ptr ds : [packetChangeAppareance + 07] , al
        mov al, byte ptr ds : [esi + 0x12D] // country
        mov byte ptr ds : [packetChangeAppareance + 0x08] , al
        movzx eax, byte ptr ds : [esi + 0x134] // job
        movzx edx, byte ptr ds : [esi + 0x12E] // family
        push eax
        push edx
        call setFamily
        add esp, 0x08
        cmp eax, -0x01
        je default_value
        mov ebx, 0x11 // wing slot , select slot as you want
        cmp dword ptr ds : [esi + ebx * 4 + 0x1C0] , 0x00
        je default_value
        mov edx, dword ptr ds : [esi + ebx * 4 + 0x1C0]
        cmp byte ptr ds : [edx + 0x40] , 80
        jne default_value
        cmp byte ptr ds : [edx + 0x41] , 01
        je updateShapeAppareance
        jmp default_value

        updateShapeAppareance :
        mov byte ptr ds : [packetChangeAppareance + 0x09] , al
            jmp shape_character_continue
            default_value :
        mov al, byte ptr ds : [esi + 0x12E]
            mov byte ptr ds : [packetChangeAppareance + 0x09] , al
            shape_character_continue :
        mov al, byte ptr ds : [esi + 0x131] // hair
            mov byte ptr ds : [packetChangeAppareance + 0x0A] , al
            mov al, byte ptr ds : [esi + 0x132] // face
            mov byte ptr ds : [packetChangeAppareance + 0x0B] , al
            mov al, byte ptr ds : [esi + 0x133] // size
            mov byte ptr ds : [packetChangeAppareance + 0x0C] , al
            mov al, byte ptr ds : [esi + 0x135] // sex
            mov byte ptr ds : [packetChangeAppareance + 0x0E] , al
            mov al, byte ptr ds : [esi + 0x134] // job
            mov byte ptr ds : [packetChangeAppareance + 0x0D] , al
            push esi
            call getPartyValue

            mov byte ptr ds : [packetChangeAppareance + 0x0F] , al
            mov al, byte ptr ds : [esi + 0x12F]
            mov byte ptr ds : [packetChangeAppareance + 0x10] , al
            mov eax, [esi + 0x148]
            mov dword ptr ds : [packetChangeAppareance + 0x11] , eax
            xor ebx, ebx
            mov edi, offset packetChangeAppareance + 0x15

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
        mov byte ptr ds : [packetChangeAppareance + 0x2A] , al
            mov byte ptr ds : [packetChangeAppareance + 0x2B] , dl


            backCode :

        call getShapeName
            mov ebx, 0x0E
            xor ecx, ecx
            mov edi, offset packetChangeAppareance + 0x31
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
        mov byte ptr ds : [packetChangeAppareance + 0x45] , 00
            mov byte ptr ds : [packetChangeAppareance + 0x46] , 00
            jmp continue_loop_wing_pet_costume

            wing_packet_shape :
        cmp dword ptr ds : [esi + ebx * 04 + 0x1C0] , 0
            je wing_clean
            mov ebp, dword ptr ds : [esi + ebx * 04 + 0x00001C0]
            movzx eax, byte ptr ds : [ebp + 0x40]
            movzx edx, byte ptr ds : [ebp + 0x41]
            mov byte ptr ds : [packetChangeAppareance + 0x45] , al
            mov byte ptr ds : [packetChangeAppareance + 0x46] , dl

            is_end_wing_pet_costume_lop :
        xor ebx, ebx // clean ebx register
            mov eax, [esi + 0xE0]
            test eax, eax
            je pop_out
            push 128
            lea edx, dword ptr ds : packetChangeAppareance
            push edx
            push eax
            mov eax, [esi + 0x000000E8]
            mov ecx, [esi + 0x000000E4]
            call sendPacketView
            push 0x05
            mov ecx, esi
            call sendEquipament

            push 0x06
            mov ecx, esi
            call sendEquipament
            pop_out :
        ret


            getShapeName :
        mov edi, offset packetChangeAppareance + 0x48
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
            cmp byte ptr ds : [packetChangeAppareance + 0x2A] , 0 // checking if have mantle or no
            jne mantle_desing_addiotonal_bytes
            mov edx, offset packetChangeAppareance + 0x5D
            mov dword ptr ds : [packetChangeAppareance + 0x63] , 00
            jmp back_get_guild_name
            mantle_desing_addiotonal_bytes :
        mov dword ptr ds : [packetChangeAppareance + 0x5D] , 00
            mov edx, offset packetChangeAppareance + 0x63
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
            mov dword ptr ds : [packetChangeAppareance + 0x63] , edi
            mov dword ptr ds : [packetChangeAppareance + 0x5D] , edi
            ret
    }
}
BYTE currentAppareance = 0;
BYTE currentType = 0;
DWORD updateUserShapeReturn = 0x00426B0C;
_declspec(naked) void updateUserShape() {
    _asm {
        pushad
        movzx eax, byte ptr ds : [ebx + 0x134]
        movzx edx, byte ptr ds : [ebx + 0x12E]
        push eax
        push edx
        call setFamily
        add esp, 0x08
        cmp eax, -0x01
        je pop_default
        cmp dword ptr ds : [ebx + 0x11 * 4 + 0x1C0] , 0
        je pop_default
        mov edx, dword ptr ds : [ebx + 0x11 * 4 + 0x1C0]
        cmp byte ptr ds : [edx + 0x40] , 80
        jne pop_default
        cmp byte ptr ds : [edx + 0x41] , 01
        je updateShapeAppareance


        pop_default :
        popad
            originalcode :
        movzx edx, byte ptr ds : [ebx + 0x0000012E]
            jmp updateUserShapeReturn

            updateShapeAppareance :
        mov byte ptr ds : [currentAppareance] , al
            popad
            movzx edx, byte ptr ds : [currentAppareance]
            jmp updateUserShapeReturn
    }
}


DWORD sendShapeChangeItemReturn = 0x00492C4C;
DWORD retnFunc = 0x00492C53;
_declspec(naked) void sendShapeChangeItem() {

    _asm {
        cmp dword ptr ds : [ecx + 0x11 * 0x4 + 0x1C0] , 0x00
        jne userShapeChange

        originalcode :
        mov[esp + 0x13], al
            mov dl, byte ptr ds : [esi + 0x41]
            jmp sendShapeChangeItemReturn



        userShapeChange:
        cmp ebx, 0x05
            je set_weapon_appareance
            cmp ebx, 0x06
            je set_weapon_appareance
            cmp ebx, 0x11
            je set_shape_appareance
            jmp originalcode

            set_shape_appareance :
        pushad
            mov eax, dword ptr ds : [ecx + 0x11 * 4 + 0x1C0]
            cmp byte ptr ds : [eax + 0x40] , 80
            jne pop_close_
            cmp byte ptr ds : [eax + 0x41] , 01
            je continue_appareance

            mov esi, edi
            call userShape
            jmp pop_close_
            continue_appareance :
        mov esi, edi
            call userShape
            popad
            jmp originalcode



        set_weapon_appareance:
        pushad
            cmp dword ptr ds : [ecx + 0x12 * 0x4 + 0x000001C0] , 0
            je isCloseFunc
            mov edx, [ecx + 0x12 * 4 + 0x000001C0]
            cmp byte ptr[edx + 0x40], 79
            je pop_close_
            isCloseFunc :
        popad



            cmp dword ptr ds : [ecx + ebx * 4 + 0x1C0] , 0
            je originalcode

            continue_test :
        pushad
            mov edx, dword ptr ds : [ecx + 0x11 * 4 + 0x1C0]
            cmp byte ptr ds : [edx + 0x40] , 80
            jne pop_close_
            cmp byte ptr ds : [edx + 0x41] , 01
            jne pop_close_


            mov esi, dword ptr ds : [ecx + ebx * 0x4 + 0x1C0]
            movzx eax, byte ptr ds : [esi + 0x40]
            push eax
            call setType
            add esp, 04
            cmp eax, -01
            je pop_close_
            mov byte ptr ds : [currentType] , al
            popad
            mov al, byte ptr ds : [currentType]
            cmp dword ptr ds : [ecx + ebx * 0x4 + 0x1C0] , 0
            je normal_shape_type
            cmp byte ptr ds : [ecx + 0x12E] , 0
            je normal_shape_type
            cmp byte ptr ds : [ecx + 0x12E] , 1
            je normal_shape_type
            cmp al, 05
            jne normal_shape_type
            mov al, 01
            mov dl, 138 // proeminence
            mov[esp + 0x13], al
            jmp normal_shape_type_id
            normal_shape_type :
        mov[esp + 0x13], al
            mov dl, [esi + 0x41]
            cmp dl, 190
            je set_light_type_id
            cmp dl, 174
            je set_light_type_id
            cmp dl, 178
            je fury_shape_type_id
            cmp dl, 194
            jne normal_shape_type_id
            sub dl, 0x10
            normal_shape_type_id:
        mov[esp + 0x14], dl
            lea eax, [esi + 0x4C]
            jmp retnFunc


            fury_shape_type_id :
        add dl, 0x10
            jmp normal_shape_type_id

            set_light_type_id :
        sub dl, 16
            jmp normal_shape_type_id

            set_dark_type_id :
        add dl, 16
            jmp normal_shape_type_id

            pop_close_ :
        popad
            jmp originalcode
    }
}
DWORD retnFunc_ = 0x00426BD9;
DWORD sendShapeChangeItemReturn2 = 0x00426BD1;
_declspec(naked) void sendShapeChangeItem2() {
    _asm {
        cmp dword ptr ds : [ebx + 0x11 * 0x4 + 0x1C0] , 0
        je originalcode

        pushad
        mov eax, [ebx + 0x11 * 0x4 + 0x1C0]

        cmp byte ptr ds : [eax + 0x40] , 80
        jne pop_close_
        cmp byte ptr ds : [eax + 0x41] , 01
        je changeAppareanceEquipItems


        pop_close_ :
        popad

            originalcode :
        mov cl, byte ptr ds : [esi + 0x40]
            mov[edi - 0x01], cl
            jmp sendShapeChangeItemReturn2



        changeAppareanceEquipItems:
        cmp dword ptr ds : [ebx + 0x12 * 0x4 + 0x1C0] , 0
            je continue_

            mov eax, dword ptr ds : [ebx + 0x12 * 0x4 + 0x1C0]
            cmp byte ptr ds : [eax + 0x40] , 79
            jne pop_close_





        continue_:
        movzx eax, byte ptr ds : [esi + 0x40]
            push eax
            call setType
            add esp, 0x04
            cmp eax, -01
            je pop_close_
            mov byte ptr ds : [currentType] , al
            popad
            mov cl, byte ptr ds : [currentType]
            cmp byte ptr ds : [ebx + 0x12E] , 0x00
            je normal_shape_type
            cmp byte ptr ds : [ebx + 0x12E] , 0x01
            je normal_shape_type
            cmp cl, 05
            jne normal_shape_type
            mov cl, 01
            mov dl, 138
            mov byte ptr ds : [edi - 0x01] , cl
            lea eax, dword ptr ds : [esi + 0x4C]
            mov byte ptr ds : [edi] , dl
            send_equiped_item_return :
        jmp retnFunc_

            normal_shape_type :
        mov byte ptr ds : [edi - 0x01] , cl
            mov dl, byte ptr ds : [esi + 0x41]
            cmp dl, 190
            je set_light_type_id
            cmp dl, 174
            je set_light_type_id
            cmp dl, 178
            je fury_shape_type_id
            cmp dl, 194
            jne normal_shape_type_id
            sub dl, 0x10
            normal_shape_type_id :
        lea eax, dword ptr ds : [esi + 0x4C]
            mov byte ptr ds : [edi] , dl
            jmp send_equiped_item_return



        fury_shape_type_id:
        add dl, 0x10
            jmp normal_shape_type_id

            set_light_type_id :
        sub dl, 16
            jmp normal_shape_type_id

            set_dark_type_id :
        add dl, 16
            jmp normal_shape_type_id
    }
}
DWORD CZoneUpdateShapeReturn = 0x0041C7E0;
_declspec(naked) void CZoneUpdateShape() {
    _asm {

        mov eax, dword ptr ds : [edi + 0x00000128]

        pushad
        push 0x11 // slot wing for test
        mov ecx, edi
        call sendEquipament


        popad

        pushad
        push 0x05 // slot wing for test
        mov ecx, edi
        call sendEquipament
        popad

        jmp CZoneUpdateShapeReturn
    }
}
DWORD restoreOriginalShapeReturn = 0x00492CC3;
_declspec(naked) void restoreOriginalShape() {
    _asm {
        cmp ebx, 0x11
        je check_slot_17

        originalcode :
        mov byte ptr ds : [esp + 0x13] , 00
            jmp restoreOriginalShapeReturn

            check_slot_17 :
        cmp dword ptr ds : [ecx + ebx * 4 + 0x1C0] , 0
            je original_shape
            jmp originalcode

            original_shape :
        pushad
            mov esi, ecx // CUser
            call userShape
            popad


            jmp originalcode
    }
}



void ChangeAppareance() {
    Sleep(8000);
    Hook((PVOID)0x00492CBE, restoreOriginalShape, 5);
    Hook((PVOID)0x0041C7DA, CZoneUpdateShape, 6);
    Hook((PVOID)0x00426BCB, sendShapeChangeItem2, 6);
    Hook((PVOID)0x00492C45, sendShapeChangeItem, 7);
    Hook((PVOID)0x00426B05, updateUserShape, 7);
}