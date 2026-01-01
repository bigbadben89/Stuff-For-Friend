#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
using namespace std;
float Float_Y = -21.0f;
float Float_X_Raid_1 = 380.0f;
float Float_X_Raid_2 = 402.0f;
float Float_X_Raid_3 = 424.0f;
float Float_X_Raid_4 = 446.0f;
float Float_X_Raid_5 = 468.0f;
LPCSTR Raid_Button_1_Targa = "RaidButton1.tga";
LPCSTR Raid_Button_2_Targa = "RaidButton2.tga";
LPCSTR Raid_Button_3_Targa = "RaidButton3.tga";
LPCSTR Raid_Button_4_Targa = "RaidButton4.tga";
LPCSTR Raid_Button_5_Targa = "RaidButton5.tga";
DWORD Button_Call = 0x00429FD0;  //0x00429E40;
DWORD Button_Call_2 = 0x0054FCE0;  //005506C0;
DWORD Button_Call_3 = 0x0054F100;  //0054FAE0;
DWORD Button_Call_4 = 0x00631BE0; //00631AB0;
DWORD Button_Call_5 = 0x00551860;//00552240;


string raid_btn_1[255];
string raid_btn_2[255];
string raid_btn_3[255];
string raid_btn_4[255];
string raid_btn_5[255];


_declspec(naked) void Raid_Button_1() {
	_asm {

		push - 0x01
		push 0x007356FE
		mov eax, fs: [0x00000000]
		push eax
		push ecx
		push ebx
		push ebp
		push esi
		push edi
		mov eax, dword ptr ds : [0x007B4DD0]
		xor eax, esp
		push eax
		lea eax, [esp + 0x18]
		mov fs : [0x00000000] , eax
		mov esi, ecx
		mov[esp + 0x14], esi
		xor ebx, ebx
		mov[esi + 0x04], ebx
		mov[esi + 0x08], ebx
		mov[esi + 0x0C], ebx
		mov[esi + 0x10], ebx
		mov[esi + 0x14], ebx
		mov[esi + 0x18], ebx
		mov[esi + 0x1C], ebx
		mov[esi + 0x20], 0x00000001
		mov[esi + 0x24], ebx
		mov[esi + 0x28], ebx
		lea edi, [esi + 0x2C]
		mov[esp + 0x20], ebx
		mov dword ptr ds : [edi] , 0x00748120
		lea ecx, [esi + 0x30]
		mov[esp + 0x20], 01
		mov dword ptr ds : [esi] , 0x00751F78
		mov dword ptr ds : [edi] , 0x00751F60
		call Button_Call
		fldz
		fst dword ptr ds : [esi + 0x00002130]
		mov[esi + 0x00002110], ebx
		fst dword ptr ds : [esi + 0x00002134]
		mov[esi + 0x0000210C], ebx
		fst dword ptr ds : [esi + 0x00002140]
		fst dword ptr ds : [esi + 0x00002144]
		mov[esi + 0x00002120], ebx //
		mov[esi + 0x0000211C], ebx //
		fst dword ptr ds : [esi + 0x00002150] //
		fst dword ptr ds : [esi + 0x00002154] //
		mov[esi + 0x00002130], ebx //
		mov[esi + 0x0000212C], ebx //
		fst dword ptr ds : [esi + 0x00002160] //
		fstp dword ptr ds : [esi + 0x00002164] //
		mov[esi + 0x0000214C], ebx //
		mov[esi + 0x00002148], ebx //
		lea ebp, dword ptr ds : raid_btn_1
		mov ecx, ebp
		mov byte ptr ds : [esp + 0x20] , 0x06
		call Button_Call_2
		fldz
		fst dword ptr ds : [esi + 0x00000724]
		mov[esi + 0x00000720], ebx
		fst dword ptr ds : [esi + 0x00000728]
		mov[esi + 0x0000071C], ebx
		fst dword ptr ds : [esi + 0x00000734]
		fst dword ptr ds : [esi + 0x00000738]
		mov[esi + 0x00000730], ebx
		mov[esi + 0x0000072C], ebx
		fst dword ptr ds : [esi + 0x00000744]
		fstp dword ptr ds : [esi + 0x00000748]
		mov[esi + 0x00000740], ebx
		mov[esi + 0x0000073C], ebx
		mov eax, [edi]
		mov edx, [eax + 0x10]
		mov ecx, edi
		mov byte ptr ds : [esp + 0x20] , 0x0A
		call edx
		mov[esi + 0x20], ebx
		mov eax, dword ptr ds : [0x007AB0D8]
		add eax, 0xFFFFFEEC
		mov[esi + 0x04], eax
		mov al, -0x01
		mov[esi + 0x08], ebx
		mov[esi + 0x0C], 0x00000100
		mov[esi + 0x10], 0x000001E6
		mov byte ptr ds : [esi + 0x00002115] , 0x01
		mov[esi + 0x00002115], al
		mov[esi + 0x00002110], ebx
		mov byte ptr ds : [esi + 0x00002116] , 0x01
		mov edx, [esi]
		mov[esi + 0x0000211], al
		mov eax, [edx + 0x0C]
		mov ecx, esi
		mov[esi + 0x00000744], ebx
		mov[esi + 0x00002158], bl
		call eax
		mov ecx, esi
		call Button_Call_3
		fldz
		push ebx
		sub esp, 0x50
		fst dword ptr ds : [esp + 0x4C]
		fst dword ptr ds : [esp + 0x48]
		fst dword ptr ds : [esp + 0x44]
		fst dword ptr ds : [esp + 0x40]
		fst dword ptr ds : [esp + 0x3C]
		fst dword ptr ds : [esp + 0x38]
		fst dword ptr ds : [esp + 0x34]
		fst dword ptr ds : [esp + 0x30]
		fld1
		fst dword ptr ds : [esp + 0x2C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x28]
		fld dword ptr ds : [0x00748164]
		fstp dword ptr ds : [esp + 0x24]
		fld dword ptr ds : [0x00748160]
		fst dword ptr ds : [esp + 0x20]
		fxch st(2)
		fst dword ptr ds : [esp + 0x1C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x18]
		fxch st(2)
		fstp dword ptr ds : [esp + 0x14]
		fld dword ptr ds : [0x0074815C]
		fst dword ptr ds : [esp + 0x10]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x0C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x08]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x04]
		fstp dword ptr ds : [esp]
		push 0x01
		fld dword ptr ds : [Float_Y]
		push 0x20
		push 0x00000080
		push Raid_Button_1_Targa
		push ebx
		push 0x17
		push 0x18
		push 0x17
		push 0x18
		call Button_Call_4
		fld dword ptr ds : [Float_X_Raid_1]
		push eax
		call Button_Call_4
		mov ecx, [esi + 0x08]
		mov edx, [esi + 0x04]
		push eax
		push ecx
		push edx
		mov ecx, ebp
		call Button_Call_5
		mov[esi + 0x00000750], 00000001
		mov[esi + 0x00000758], ebx
		mov eax, esi
		mov ecx, [esp + 0x18]
		mov fs : [0x00000000] , ecx
		pop ecx
		pop edi
		pop esi
		pop ebp
		pop ebx
		add esp, 0x10
		ret

	}
}

_declspec(naked) void Raid_Button_2() {
	_asm {

		push - 0x01
		push 0x007356FE
		mov eax, fs: [0x00000000]
		push eax
		push ecx
		push ebx
		push ebp
		push esi
		push edi
		mov eax, dword ptr ds : [0x007B4DD0]
		xor eax, esp
		push eax
		lea eax, [esp + 0x18]
		mov fs : [0x00000000] , eax
		mov esi, ecx
		mov[esp + 0x14], esi
		xor ebx, ebx
		mov[esi + 0x04], ebx
		mov[esi + 0x08], ebx
		mov[esi + 0x0C], ebx
		mov[esi + 0x10], ebx
		mov[esi + 0x14], ebx
		mov[esi + 0x18], ebx
		mov[esi + 0x1C], ebx
		mov[esi + 0x20], 0x00000001
		mov[esi + 0x24], ebx
		mov[esi + 0x28], ebx
		lea edi, [esi + 0x2C]
		mov[esp + 0x20], ebx
		mov dword ptr ds : [edi] , 0x00748120
		lea ecx, [esi + 0x30]
		mov[esp + 0x20], 01
		mov dword ptr ds : [esi] , 0x00751F78
		mov dword ptr ds : [edi] , 0x00751F60
		call Button_Call
		fldz
		fst dword ptr ds : [esi + 0x00002130]
		mov ds : [esi + 0x00002110] , ebx
		fst dword ptr ds : [esi + 0x00002134]
		mov[esi + 0x0000210C], ebx
		fst dword ptr ds : [esi + 0x00002140]
		fst dword ptr ds : [esi + 0x00002144]
		mov[esi + 0x00002120], ebx //
		mov[esi + 0x0000211C], ebx //
		fst dword ptr ds : [esi + 0x00002150] //
		fst dword ptr ds : [esi + 0x00002154] //
		mov[esi + 0x00002130], ebx //
		mov[esi + 0x0000212C], ebx //
		fst dword ptr ds : [esi + 0x00002160] //
		fstp dword ptr ds : [esi + 0x00002164] //
		mov[esi + 0x0000214C], ebx //
		mov[esi + 0x00002148], ebx //
		lea ebp, dword ptr ds : raid_btn_2
		mov ecx, ebp
		mov byte ptr ds : [esp + 0x20] , 0x06
		call Button_Call_2
		fldz
		fst dword ptr ds : [esi + 0x00000724]
		mov[esi + 0x00000720], ebx
		fst dword ptr ds : [esi + 0x00000728]
		mov[esi + 0x0000071C], ebx
		fst dword ptr ds : [esi + 0x00000734]
		fst dword ptr ds : [esi + 0x00000738]
		mov[esi + 0x00000730], ebx
		mov[esi + 0x0000072C], ebx
		fst dword ptr ds : [esi + 0x00000744]
		fstp dword ptr ds : [esi + 0x00000748]
		mov[esi + 0x00000740], ebx
		mov[esi + 0x0000073C], ebx
		mov eax, [edi]
		mov edx, [eax + 0x10]
		mov ecx, edi
		mov byte ptr ds : [esp + 0x20] , 0x0A
		call edx
		mov[esi + 0x20], ebx
		mov eax, dword ptr ds : [0x007AB0D8]
		add eax, 0xFFFFFEEC
		mov[esi + 0x04], eax
		mov al, -0x01
		mov[esi + 0x08], ebx
		mov[esi + 0x0C], 0x00000100
		mov[esi + 0x10], 0x000001E6
		mov byte ptr ds : [esi + 0x00002115] , 0x01
		mov[esi + 0x00002115], al
		mov[esi + 0x00002110], ebx
		mov byte ptr ds : [esi + 0x00002116] , 0x01
		mov edx, [esi]
		mov[esi + 0x0000211], al
		mov eax, [edx + 0x0C]
		mov ecx, esi
		mov[esi + 0x00000744], ebx
		mov[esi + 0x00002158], bl
		call eax
		mov ecx, esi
		call Button_Call_3
		fldz
		push ebx
		sub esp, 0x50
		fst dword ptr ds : [esp + 0x4C]
		fst dword ptr ds : [esp + 0x48]
		fst dword ptr ds : [esp + 0x44]
		fst dword ptr ds : [esp + 0x40]
		fst dword ptr ds : [esp + 0x3C]
		fst dword ptr ds : [esp + 0x38]
		fst dword ptr ds : [esp + 0x34]
		fst dword ptr ds : [esp + 0x30]
		fld1
		fst dword ptr ds : [esp + 0x2C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x28]
		fld dword ptr ds : [0x00748164]
		fstp dword ptr ds : [esp + 0x24]
		fld dword ptr ds : [0x00748160]
		fst dword ptr ds : [esp + 0x20]
		fxch st(2)
		fst dword ptr ds : [esp + 0x1C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x18]
		fxch st(2)
		fstp dword ptr ds : [esp + 0x14]
		fld dword ptr ds : [0x0074815C]
		fst dword ptr ds : [esp + 0x10]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x0C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x08]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x04]
		fstp dword ptr ds : [esp]
		push 0x01
		fld dword ptr ds : [Float_Y]
		push 0x20
		push 0x00000080
		push Raid_Button_2_Targa
		push ebx
		push 0x17
		push 0x18
		push 0x17
		push 0x18
		call Button_Call_4
		fld dword ptr ds : [Float_X_Raid_2]
		push eax
		call Button_Call_4
		mov ecx, [esi + 0x08]
		mov edx, [esi + 0x04]
		push eax
		push ecx
		push edx
		mov ecx, ebp
		call Button_Call_5
		mov[esi + 0x00000750], 00000001
		mov[esi + 0x00000758], ebx
		mov eax, esi
		mov ecx, [esp + 0x18]
		mov fs : [0x00000000] , ecx
		pop ecx
		pop edi
		pop esi
		pop ebp
		pop ebx
		add esp, 0x10
		ret

	}
}

_declspec(naked) void Raid_Button_3() {
	_asm {

		push - 0x01
		push 0x007356FE
		mov eax, fs: [0x00000000]
		push eax
		push ecx
		push ebx
		push ebp
		push esi
		push edi
		mov eax, dword ptr ds : [0x007B4DD0]
		xor eax, esp
		push eax
		lea eax, [esp + 0x18]
		mov fs : [0x00000000] , eax
		mov esi, ecx
		mov[esp + 0x14], esi
		xor ebx, ebx
		mov[esi + 0x04], ebx
		mov[esi + 0x08], ebx
		mov[esi + 0x0C], ebx
		mov[esi + 0x10], ebx
		mov[esi + 0x14], ebx
		mov[esi + 0x18], ebx
		mov[esi + 0x1C], ebx
		mov[esi + 0x20], 0x00000001
		mov[esi + 0x24], ebx
		mov[esi + 0x28], ebx
		lea edi, [esi + 0x2C]
		mov[esp + 0x20], ebx
		mov dword ptr ds : [edi] , 0x00748120
		lea ecx, [esi + 0x30]
		mov[esp + 0x20], 01
		mov dword ptr ds : [esi] , 0x00751F78
		mov dword ptr ds : [edi] , 0x00751F60
		call Button_Call
		fldz
		fst dword ptr ds : [esi + 0x00002130]
		mov ds : [esi + 0x00002110] , ebx
		fst dword ptr ds : [esi + 0x00002134]
		mov[esi + 0x0000210C], ebx
		fst dword ptr ds : [esi + 0x00002140]
		fst dword ptr ds : [esi + 0x00002144]
		mov[esi + 0x00002120], ebx //
		mov[esi + 0x0000211C], ebx //
		fst dword ptr ds : [esi + 0x00002150] //
		fst dword ptr ds : [esi + 0x00002154] //
		mov[esi + 0x00002130], ebx //
		mov[esi + 0x0000212C], ebx //
		fst dword ptr ds : [esi + 0x00002160] //
		fstp dword ptr ds : [esi + 0x00002164] //
		mov[esi + 0x0000214C], ebx //
		mov[esi + 0x00002148], ebx //
		lea ebp, dword ptr ds : raid_btn_3
		mov ecx, ebp
		mov byte ptr ds : [esp + 0x20] , 0x06
		call Button_Call_2
		fldz
		fst dword ptr ds : [esi + 0x00000724]
		mov[esi + 0x00000720], ebx
		fst dword ptr ds : [esi + 0x00000728]
		mov[esi + 0x0000071C], ebx
		fst dword ptr ds : [esi + 0x00000734]
		fst dword ptr ds : [esi + 0x00000738]
		mov[esi + 0x00000730], ebx
		mov[esi + 0x0000072C], ebx
		fst dword ptr ds : [esi + 0x00000744]
		fstp dword ptr ds : [esi + 0x00000748]
		mov[esi + 0x00000740], ebx
		mov[esi + 0x0000073C], ebx
		mov eax, [edi]
		mov edx, [eax + 0x10]
		mov ecx, edi
		mov byte ptr ds : [esp + 0x20] , 0x0A
		call edx
		mov[esi + 0x20], ebx
		mov eax, dword ptr ds : [0x007AB0D8]
		add eax, 0xFFFFFEEC
		mov[esi + 0x04], eax
		mov al, -0x01
		mov[esi + 0x08], ebx
		mov[esi + 0x0C], 0x00000100
		mov[esi + 0x10], 0x000001E6
		mov byte ptr ds : [esi + 0x00002115] , 0x01
		mov[esi + 0x00002115], al
		mov[esi + 0x00002110], ebx
		mov byte ptr ds : [esi + 0x00002116] , 0x01
		mov edx, [esi]
		mov[esi + 0x0000211], al
		mov eax, [edx + 0x0C]
		mov ecx, esi
		mov[esi + 0x00000744], ebx
		mov[esi + 0x00002158], bl
		call eax
		mov ecx, esi
		call Button_Call_3
		fldz
		push ebx
		sub esp, 0x50
		fst dword ptr ds : [esp + 0x4C]
		fst dword ptr ds : [esp + 0x48]
		fst dword ptr ds : [esp + 0x44]
		fst dword ptr ds : [esp + 0x40]
		fst dword ptr ds : [esp + 0x3C]
		fst dword ptr ds : [esp + 0x38]
		fst dword ptr ds : [esp + 0x34]
		fst dword ptr ds : [esp + 0x30]
		fld1
		fst dword ptr ds : [esp + 0x2C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x28]
		fld dword ptr ds : [0x00748164]
		fstp dword ptr ds : [esp + 0x24]
		fld dword ptr ds : [0x00748160]
		fst dword ptr ds : [esp + 0x20]
		fxch st(2)
		fst dword ptr ds : [esp + 0x1C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x18]
		fxch st(2)
		fstp dword ptr ds : [esp + 0x14]
		fld dword ptr ds : [0x0074815C]
		fst dword ptr ds : [esp + 0x10]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x0C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x08]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x04]
		fstp dword ptr ds : [esp]
		push 0x01
		fld dword ptr ds : [Float_Y]
		push 0x20
		push 0x00000080
		push Raid_Button_3_Targa
		push ebx
		push 0x17
		push 0x18
		push 0x17
		push 0x18
		call Button_Call_4
		fld dword ptr ds : [Float_X_Raid_3]
		push eax
		call Button_Call_4
		mov ecx, [esi + 0x08]
		mov edx, [esi + 0x04]
		push eax
		push ecx
		push edx
		mov ecx, ebp
		call Button_Call_5
		mov[esi + 0x00000750], 00000001
		mov[esi + 0x00000758], ebx
		mov eax, esi
		mov ecx, [esp + 0x18]
		mov fs : [0x00000000] , ecx
		pop ecx
		pop edi
		pop esi
		pop ebp
		pop ebx
		add esp, 0x10
		ret

	}
}


_declspec(naked) void Raid_Button_4() {
	_asm {

		push - 0x01
		push 0x007356FE
		mov eax, fs: [0x00000000]
		push eax
		push ecx
		push ebx
		push ebp
		push esi
		push edi
		mov eax, dword ptr ds : [0x007B4DD0]
		xor eax, esp
		push eax
		lea eax, [esp + 0x18]
		mov fs : [0x00000000] , eax
		mov esi, ecx
		mov[esp + 0x14], esi
		xor ebx, ebx
		mov[esi + 0x04], ebx
		mov[esi + 0x08], ebx
		mov[esi + 0x0C], ebx
		mov[esi + 0x10], ebx
		mov[esi + 0x14], ebx
		mov[esi + 0x18], ebx
		mov[esi + 0x1C], ebx
		mov[esi + 0x20], 0x00000001
		mov[esi + 0x24], ebx
		mov[esi + 0x28], ebx
		lea edi, [esi + 0x2C]
		mov[esp + 0x20], ebx
		mov dword ptr ds : [edi] , 0x00748120
		lea ecx, [esi + 0x30]
		mov[esp + 0x20], 01
		mov dword ptr ds : [esi] , 0x00751F78
		mov dword ptr ds : [edi] , 0x00751F60
		call Button_Call
		fldz
		fst dword ptr ds : [esi + 0x00002130]
		mov ds : [esi + 0x00002110] , ebx
		fst dword ptr ds : [esi + 0x00002134]
		mov[esi + 0x0000210C], ebx
		fst dword ptr ds : [esi + 0x00002140]
		fst dword ptr ds : [esi + 0x00002144]
		mov[esi + 0x00002120], ebx //
		mov[esi + 0x0000211C], ebx //
		fst dword ptr ds : [esi + 0x00002150] //
		fst dword ptr ds : [esi + 0x00002154] //
		mov[esi + 0x00002130], ebx //
		mov[esi + 0x0000212C], ebx //
		fst dword ptr ds : [esi + 0x00002160] //
		fstp dword ptr ds : [esi + 0x00002164] //
		mov[esi + 0x0000214C], ebx //
		mov[esi + 0x00002148], ebx //
		lea ebp, dword ptr ds : raid_btn_4
		mov ecx, ebp
		mov byte ptr ds : [esp + 0x20] , 0x06
		call Button_Call_2
		fldz
		fst dword ptr ds : [esi + 0x00000724]
		mov[esi + 0x00000720], ebx
		fst dword ptr ds : [esi + 0x00000728]
		mov[esi + 0x0000071C], ebx
		fst dword ptr ds : [esi + 0x00000734]
		fst dword ptr ds : [esi + 0x00000738]
		mov[esi + 0x00000730], ebx
		mov[esi + 0x0000072C], ebx
		fst dword ptr ds : [esi + 0x00000744]
		fstp dword ptr ds : [esi + 0x00000748]
		mov[esi + 0x00000740], ebx
		mov[esi + 0x0000073C], ebx
		mov eax, [edi]
		mov edx, [eax + 0x10]
		mov ecx, edi
		mov byte ptr ds : [esp + 0x20] , 0x0A
		call edx
		mov[esi + 0x20], ebx
		mov eax, dword ptr ds : [0x007AB0D8]
		add eax, 0xFFFFFEEC
		mov[esi + 0x04], eax
		mov al, -0x01
		mov[esi + 0x08], ebx
		mov[esi + 0x0C], 0x00000100
		mov[esi + 0x10], 0x000001E6
		mov byte ptr ds : [esi + 0x00002115] , 0x01
		mov[esi + 0x00002115], al
		mov[esi + 0x00002110], ebx
		mov byte ptr ds : [esi + 0x00002116] , 0x01
		mov edx, [esi]
		mov[esi + 0x0000211], al
		mov eax, [edx + 0x0C]
		mov ecx, esi
		mov[esi + 0x00000744], ebx
		mov[esi + 0x00002158], bl
		call eax
		mov ecx, esi
		call Button_Call_3
		fldz
		push ebx
		sub esp, 0x50
		fst dword ptr ds : [esp + 0x4C]
		fst dword ptr ds : [esp + 0x48]
		fst dword ptr ds : [esp + 0x44]
		fst dword ptr ds : [esp + 0x40]
		fst dword ptr ds : [esp + 0x3C]
		fst dword ptr ds : [esp + 0x38]
		fst dword ptr ds : [esp + 0x34]
		fst dword ptr ds : [esp + 0x30]
		fld1
		fst dword ptr ds : [esp + 0x2C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x28]
		fld dword ptr ds : [0x00748164]
		fstp dword ptr ds : [esp + 0x24]
		fld dword ptr ds : [0x00748160]
		fst dword ptr ds : [esp + 0x20]
		fxch st(2)
		fst dword ptr ds : [esp + 0x1C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x18]
		fxch st(2)
		fstp dword ptr ds : [esp + 0x14]
		fld dword ptr ds : [0x0074815C]
		fst dword ptr ds : [esp + 0x10]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x0C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x08]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x04]
		fstp dword ptr ds : [esp]
		push 0x01
		fld dword ptr ds : [Float_Y]
		push 0x20
		push 0x00000080
		push Raid_Button_4_Targa
		push ebx
		push 0x17
		push 0x18
		push 0x17
		push 0x18
		call Button_Call_4
		fld dword ptr ds : [Float_X_Raid_4]
		push eax
		call Button_Call_4
		mov ecx, [esi + 0x08]
		mov edx, [esi + 0x04]
		push eax
		push ecx
		push edx
		mov ecx, ebp
		call Button_Call_5
		mov[esi + 0x00000750], 00000001
		mov[esi + 0x00000758], ebx
		mov eax, esi
		mov ecx, [esp + 0x18]
		mov fs : [0x00000000] , ecx
		pop ecx
		pop edi
		pop esi
		pop ebp
		pop ebx
		add esp, 0x10
		ret
	}
}



_declspec(naked) void Raid_Button_5() {
	_asm {

		push - 0x01
		push 0x007356FE
		mov eax, fs: [0x00000000]
		push eax
		push ecx
		push ebx
		push ebp
		push esi
		push edi
		mov eax, dword ptr ds : [0x007B4DD0]
		xor eax, esp
		push eax
		lea eax, [esp + 0x18]
		mov fs : [0x00000000] , eax
		mov esi, ecx
		mov[esp + 0x14], esi
		xor ebx, ebx
		mov[esi + 0x04], ebx
		mov[esi + 0x08], ebx
		mov[esi + 0x0C], ebx
		mov[esi + 0x10], ebx
		mov[esi + 0x14], ebx
		mov[esi + 0x18], ebx
		mov[esi + 0x1C], ebx
		mov[esi + 0x20], 0x00000001
		mov[esi + 0x24], ebx
		mov[esi + 0x28], ebx
		lea edi, [esi + 0x2C]
		mov[esp + 0x20], ebx
		mov dword ptr ds : [edi] , 0x00748120
		lea ecx, [esi + 0x30]
		mov[esp + 0x20], 01
		mov dword ptr ds : [esi] , 0x00751F78
		mov dword ptr ds : [edi] , 0x00751F60
		call Button_Call
		fldz
		fst dword ptr ds : [esi + 0x00002130]
		mov[esi + 0x00002110], ebx
		fst dword ptr ds : [esi + 0x00002134]
		mov[esi + 0x0000210C], ebx
		fst dword ptr ds : [esi + 0x00002140]
		fst dword ptr ds : [esi + 0x00002144]
		mov[esi + 0x00002120], ebx //
		mov[esi + 0x0000211C], ebx //
		fst dword ptr ds : [esi + 0x00002150] //
		fst dword ptr ds : [esi + 0x00002154] //
		mov[esi + 0x00002130], ebx //
		mov[esi + 0x0000212C], ebx //
		fst dword ptr ds : [esi + 0x00002160] //
		fstp dword ptr ds : [esi + 0x00002164] //
		mov[esi + 0x0000214C], ebx //
		mov[esi + 0x00002148], ebx //
		lea ebp, dword ptr ds : raid_btn_5
		mov ecx, ebp
		mov byte ptr ds : [esp + 0x20] , 0x06
		call Button_Call_2
		fldz
		fst dword ptr ds : [esi + 0x00000724]
		mov[esi + 0x00000720], ebx
		fst dword ptr ds : [esi + 0x00000728]
		mov[esi + 0x0000071C], ebx
		fst dword ptr ds : [esi + 0x00000734]
		fst dword ptr ds : [esi + 0x00000738]
		mov[esi + 0x00000730], ebx
		mov[esi + 0x0000072C], ebx
		fst dword ptr ds : [esi + 0x00000744]
		fstp dword ptr ds : [esi + 0x00000748]
		mov[esi + 0x00000740], ebx
		mov[esi + 0x0000073C], ebx
		mov eax, [edi]
		mov edx, [eax + 0x10]
		mov ecx, edi
		mov byte ptr ds : [esp + 0x20] , 0x0A
		call edx
		mov[esi + 0x20], ebx
		mov eax, dword ptr ds : [0x007AB0D8]
		add eax, 0xFFFFFEEC
		mov[esi + 0x04], eax
		mov al, -0x01
		mov[esi + 0x08], ebx
		mov[esi + 0x0C], 0x00000100
		mov[esi + 0x10], 0x000001E6
		mov byte ptr ds : [esi + 0x00002115] , 0x01
		mov[esi + 0x00002115], al
		mov[esi + 0x00002110], ebx
		mov byte ptr ds : [esi + 0x00002116] , 0x01
		mov edx, [esi]
		mov[esi + 0x0000211], al
		mov eax, [edx + 0x0C]
		mov ecx, esi
		mov[esi + 0x00000744], ebx
		mov[esi + 0x00002158], bl
		call eax
		mov ecx, esi
		call Button_Call_3
		fldz
		push ebx
		sub esp, 0x50
		fst dword ptr ds : [esp + 0x4C]
		fst dword ptr ds : [esp + 0x48]
		fst dword ptr ds : [esp + 0x44]
		fst dword ptr ds : [esp + 0x40]
		fst dword ptr ds : [esp + 0x3C]
		fst dword ptr ds : [esp + 0x38]
		fst dword ptr ds : [esp + 0x34]
		fst dword ptr ds : [esp + 0x30]
		fld1
		fst dword ptr ds : [esp + 0x2C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x28]
		fld dword ptr ds : [0x00748164]
		fstp dword ptr ds : [esp + 0x24]
		fld dword ptr ds : [0x00748160]
		fst dword ptr ds : [esp + 0x20]
		fxch st(2)
		fst dword ptr ds : [esp + 0x1C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x18]
		fxch st(2)
		fstp dword ptr ds : [esp + 0x14]
		fld dword ptr ds : [0x0074815C]
		fst dword ptr ds : [esp + 0x10]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x0C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x08]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x04]
		fstp dword ptr ds : [esp]
		push 0x01
		fld dword ptr ds : [Float_Y]
		push 0x20
		push 0x00000080
		push Raid_Button_5_Targa
		push ebx
		push 0x17
		push 0x18
		push 0x17
		push 0x18
		call Button_Call_4
		fld dword ptr ds : [Float_X_Raid_5]
		push eax
		call Button_Call_4
		mov ecx, [esi + 0x08]
		mov edx, [esi + 0x04]
		push eax
		push ecx
		push edx
		mov ecx, ebp
		call Button_Call_5
		mov[esi + 0x00000750], 00000001
		mov[esi + 0x00000758], ebx
		mov eax, esi
		mov ecx, [esp + 0x18]
		mov fs : [0x00000000] , ecx
		pop ecx
		pop edi
		pop esi
		pop ebp
		pop ebx
		add esp, 0x10
		ret
	}
}

DWORD Send_Buttons_To_Memory_Return = 0x0042B11B;//0042AF6B;
DWORD Button_Original = 0x005187B0;//0051ABD0;
DWORD Pointer_Test = 0;
_declspec(naked) void Send_Buttons_To_Memory() {
	_asm {


		mov dword ptr ds : [Pointer_Test] , eax
		//mov ecx,eax
		call Raid_Button_3
		mov ecx, Pointer_Test
		call Button_Original
		jmp Send_Buttons_To_Memory_Return
	}
}

DWORD inv_btn_call1 = 0x00429FD0;
DWORD inv_btn_call2 = 0x0054FCE0;
DWORD inv_btn_call3 = 0x0054F100;
DWORD inv_btn_call4 = 0x00631BE0;
DWORD inv_btn_call5 = 0x00551860;



// Çanta
float invenbutton_positionfloat1 = 305.0f; // y
float invenbutton_positionfloat2 = 255.0f; // x
LPCSTR inv_button_name1 = "inven_new_buton1.tga";

float invenbutton_positionfloat3 = 340.0f; // y
float invenbutton_positionfloat4 = 255.0f; // x
LPCSTR inv_button_name2 = "inven_new_buton2.tga";

float invenbutton_positionfloat5 = 375.0f; // y
float invenbutton_positionfloat6 = 255.0f; // x
LPCSTR inv_button_name3 = "inven_new_buton3.tga";

LPCSTR map_button = "main_map_button_1.tga";
LPCSTR map_button_2 = "main_map_button_2.tga";
LPCSTR map_button_3 = "main_map_button_3.tga";


string map_button_pointer[255];
string map_button_pointer_2[255];
string map_button_pointer_3[255];
string inv_btn_pointer_sell[255];



_declspec(naked) void invenbutton_alloc_1()
{
	_asm {

		push - 0x01
		push 0x007356FE
		mov eax, fs: [0x00000000]
		push eax
		push ecx
		push ebx
		push ebp
		push esi
		push edi
		mov eax, [0x007B4DD0]
		xor eax, esp
		push eax
		lea eax, [esp + 0x18]
		mov fs : [00000000] , eax
		mov esi, ecx
		mov[esp + 0x14], esi
		xor ebx, ebx
		mov[esi + 0x04], ebx
		mov[esi + 0x08], ebx
		mov[esi + 0x0C], ebx
		mov[esi + 0x10], ebx
		mov[esi + 0x14], ebx
		mov[esi + 0x18], ebx
		mov[esi + 0x1C], ebx
		mov[esi + 0x20], 00000001
		mov[esi + 0x24], ebx
		mov[esi + 0x28], ebx
		lea edi, [esi + 0x2C]
		mov[esp + 0x20], ebx
		mov dword ptr ds : [edi] , 0x00748120
		lea ecx, [esi + 0x30]
		mov byte ptr[esp + 0x20], 0x01
		mov dword ptr ds : [esi] , 0x00751F78
		mov dword ptr ds : [edi] , 0x00751F60
		call inv_btn_call1
		fldz
		fst dword ptr[esi + 0x00002130]
		mov[esi + 0x00002110], ebx
		fst dword ptr[esi + 0x00002134]
		mov[esi + 0x0000210C], ebx
		fst dword ptr[esi + 0x00002140]
		fst dword ptr[esi + 0x00002144]
		mov[esi + 0x00002120], ebx //
		mov[esi + 0x0000211C], ebx //
		fst dword ptr[esi + 0x00002150] //
		fst dword ptr[esi + 0x00002154] //
		mov[esi + 0x00002130], ebx //
		mov[esi + 0x0000212C], ebx //
		fst dword ptr[esi + 0x00002160] //
		fstp dword ptr[esi + 0x00002164] //
		mov[esi + 0x0000214C], ebx //
		mov[esi + 0x00002148], ebx //
		lea ebp, dword ptr ds : inv_btn_pointer_sell // Buton pointer

		mov ecx, ebp
		mov byte ptr[esp + 20], 0x06
		call inv_btn_call2
		fldz
		fst dword ptr[esi + 0x00000724]
		mov[esi + 0x00000720], ebx
		fst dword ptr[esi + 0x00000728]
		mov[esi + 0x0000071C], ebx
		fst dword ptr[esi + 0x00000734]
		fst dword ptr[esi + 0x00000738]
		mov[esi + 0x00000730], ebx
		mov[esi + 0x0000072C], ebx
		fst dword ptr[esi + 0x00000744]
		fstp dword ptr[esi + 0x00000748]
		mov[esi + 0x00000740], ebx
		mov[esi + 0x0000073C], ebx
		mov eax, [edi]
		mov edx, [eax + 0x10]
		mov ecx, edi
		mov byte ptr[esp + 0x20], 0x0A
		call edx
		mov[esi + 0x20], ebx
		mov eax, [0x007AB0D8]
		add eax, 0xFFFFFEEC
		mov[esi + 0x04], eax
		mov al, -0x01
		mov[esi + 0x08], ebx
		mov[esi + 0x0C], 0x00000100
		mov[esi + 0x10], 0x000001E6
		mov byte ptr[esi + 0x00002115], 0x01
		mov[esi + 0x00002115], al
		mov[esi + 0x00002110], ebx
		mov byte ptr[esi + 0x00002116], 0x01
		mov edx, [esi]
		mov[esi + 0x0000211], al
		mov eax, [edx + 0x0C]
		mov ecx, esi
		mov[esi + 0x0000074C], ebx
		mov[esi + 0x00002158], bl
		call eax
		mov ecx, esi
		call inv_btn_call3
		fldz
		push ebx
		sub esp, 0x50
		fst dword ptr[esp + 0x4C]
		fst dword ptr[esp + 0x48]
		fst dword ptr[esp + 0x44]
		fst dword ptr[esp + 0x40]
		fst dword ptr[esp + 0x3C]
		fst dword ptr[esp + 0x38]
		fst dword ptr[esp + 0x34]
		fst dword ptr[esp + 0x30]
		fld1
		fst dword ptr[esp + 0x2C]
		fxch st(1)
		fst dword ptr[esp + 0x28]
		//fld dword ptr[0x00748164]
		fld dword ptr ds : [0x00748164]
		fstp dword ptr[esp + 0x24]
		fld dword ptr ds : [0x00748160]
		fst dword ptr[esp + 0x20]
		fxch st(2)
		fst dword ptr[esp + 0x1C]
		fxch st(1)
		fst dword ptr[esp + 0x18]
		fxch st(2)
		fstp dword ptr[esp + 0x14]
		fld dword ptr ds : [0x0074815C]
		fst dword ptr[esp + 0x10]
		fxch st(1)
		fstp dword ptr[esp + 0x0C]
		fxch st(1)
		fst dword ptr[esp + 0x08]
		fxch st(1)
		fstp dword ptr[esp + 0x04]
		fstp dword ptr[esp]
		push 0x01
		fld dword ptr[invenbutton_positionfloat1] // y
		push 0x20
		push 0x00000080
		push inv_button_name1
		push ebx
		push 0x20
		push 0x20
		push 0x20
		push 0x20
		call inv_btn_call4
		fld dword ptr[invenbutton_positionfloat2] // x
		push eax
		call inv_btn_call4
		mov ecx, [esi + 0x08]
		mov edx, [esi + 0x04]
		push eax
		push ecx
		push edx
		mov ecx, ebp
		call inv_btn_call5
		mov[esi + 0x00000750], 0x00000001
		mov[esi + 0x00000758], ebx
		mov eax, esi
		mov ecx, [esp + 0x18]
		mov fs : [0x00000000] , ecx
		pop ecx
		pop edi
		pop esi
		pop ebp
		pop ebx
		add esp, 0x10
		ret
	}
}

string inv_btn_pointer_link[255];

_declspec(naked) void invenbutton_alloc_2()
{
	_asm {

		push - 0x01
		push 0x007356FE
		mov eax, fs: [0x00000000]
		push eax
		push ecx
		push ebx
		push ebp
		push esi
		push edi
		mov eax, [0x007B4DD0]
		xor eax, esp
		push eax
		lea eax, [esp + 0x18]
		mov fs : [00000000] , eax
		mov esi, ecx
		mov[esp + 0x14], esi
		xor ebx, ebx
		mov[esi + 0x04], ebx
		mov[esi + 0x08], ebx
		mov[esi + 0x0C], ebx
		mov[esi + 0x10], ebx
		mov[esi + 0x14], ebx
		mov[esi + 0x18], ebx
		mov[esi + 0x1C], ebx
		mov[esi + 0x20], 00000001
		mov[esi + 0x24], ebx
		mov[esi + 0x28], ebx
		lea edi, [esi + 0x2C]
		mov[esp + 0x20], ebx
		mov dword ptr ds : [edi] , 0x00748120
		lea ecx, [esi + 0x30]
		mov byte ptr[esp + 0x20], 0x01
		mov dword ptr ds : [esi] , 0x00751F78
		mov dword ptr ds : [edi] , 0x00751F60
		call inv_btn_call1
		fldz
		fst dword ptr[esi + 0x00002130]
		mov[esi + 0x00002110], ebx
		fst dword ptr[esi + 0x00002134]
		mov[esi + 0x0000210C], ebx
		fst dword ptr[esi + 0x00002140]
		fst dword ptr[esi + 0x00002144]
		mov[esi + 0x00002120], ebx //
		mov[esi + 0x0000211C], ebx //
		fst dword ptr[esi + 0x00002150] //
		fst dword ptr[esi + 0x00002154] //
		mov[esi + 0x00002130], ebx //
		mov[esi + 0x0000212C], ebx //
		fst dword ptr[esi + 0x00002160] //
		fstp dword ptr[esi + 0x00002164] //
		mov[esi + 0x0000214C], ebx //
		mov[esi + 0x00002148], ebx //
		lea ebp, dword ptr ds : inv_btn_pointer_link // Buton pointer

		mov ecx, ebp
		mov byte ptr[esp + 20], 0x06
		call inv_btn_call2
		fldz
		fst dword ptr[esi + 0x00000724]
		mov[esi + 0x00000720], ebx
		fst dword ptr[esi + 0x00000728]
		mov[esi + 0x0000071C], ebx
		fst dword ptr[esi + 0x00000734]
		fst dword ptr[esi + 0x00000738]
		mov[esi + 0x00000730], ebx
		mov[esi + 0x0000072C], ebx
		fst dword ptr[esi + 0x00000744]
		fstp dword ptr[esi + 0x00000748]
		mov[esi + 0x00000740], ebx
		mov[esi + 0x0000073C], ebx
		mov eax, [edi]
		mov edx, [eax + 0x10]
		mov ecx, edi
		mov byte ptr[esp + 0x20], 0x0A
		call edx
		mov[esi + 0x20], ebx
		mov eax, [0x007AB0D8]
		add eax, 0xFFFFFEEC
		mov[esi + 0x04], eax
		mov al, -0x01
		mov[esi + 0x08], ebx
		mov[esi + 0x0C], 0x00000100
		mov[esi + 0x10], 0x000001E6
		mov byte ptr[esi + 0x00002115], 0x01
		mov[esi + 0x00002115], al
		mov[esi + 0x00002110], ebx
		mov byte ptr[esi + 0x00002116], 0x01
		mov edx, [esi]
		mov[esi + 0x0000211], al
		mov eax, [edx + 0x0C]
		mov ecx, esi
		mov[esi + 0x0000074C], ebx
		mov[esi + 0x00002158], bl
		call eax
		mov ecx, esi
		call inv_btn_call3
		fldz
		push ebx
		sub esp, 0x50
		fst dword ptr[esp + 0x4C]
		fst dword ptr[esp + 0x48]
		fst dword ptr[esp + 0x44]
		fst dword ptr[esp + 0x40]
		fst dword ptr[esp + 0x3C]
		fst dword ptr[esp + 0x38]
		fst dword ptr[esp + 0x34]
		fst dword ptr[esp + 0x30]
		fld1
		fst dword ptr[esp + 0x2C]
		fxch st(1)
		fst dword ptr[esp + 0x28]
		//fld dword ptr[0x00748164]
		fld dword ptr ds : [0x00748164]
		fstp dword ptr[esp + 0x24]
		fld dword ptr ds : [0x00748160]
		fst dword ptr[esp + 0x20]
		fxch st(2)
		fst dword ptr[esp + 0x1C]
		fxch st(1)
		fst dword ptr[esp + 0x18]
		fxch st(2)
		fstp dword ptr[esp + 0x14]
		fld dword ptr ds : [0x0074815C]
		fst dword ptr[esp + 0x10]
		fxch st(1)
		fstp dword ptr[esp + 0x0C]
		fxch st(1)
		fst dword ptr[esp + 0x08]
		fxch st(1)
		fstp dword ptr[esp + 0x04]
		fstp dword ptr[esp]
		push 0x01
		fld dword ptr[invenbutton_positionfloat3] // y
		push 0x20
		push 0x00000080
		push inv_button_name2
		push ebx
		push 0x20
		push 0x20
		push 0x20
		push 0x20
		call inv_btn_call4
		fld dword ptr[invenbutton_positionfloat4] // x
		push eax
		call inv_btn_call4
		mov ecx, [esi + 0x08]
		mov edx, [esi + 0x04]
		push eax
		push ecx
		push edx
		mov ecx, ebp
		call inv_btn_call5
		mov[esi + 0x00000750], 0x00000001
		mov[esi + 0x00000758], ebx
		mov eax, esi
		mov ecx, [esp + 0x18]
		mov fs : [0x00000000] , ecx
		pop ecx
		pop edi
		pop esi
		pop ebp
		pop ebx
		add esp, 0x10
		ret
	}
}

string inv_btn_pointer_reroll[255];

_declspec(naked) void invenbutton_alloc_3()
{
	_asm {

		push - 0x01
		push 0x007356FE
		mov eax, fs: [0x00000000]
		push eax
		push ecx
		push ebx
		push ebp
		push esi
		push edi
		mov eax, [0x007B4DD0]
		xor eax, esp
		push eax
		lea eax, [esp + 0x18]
		mov fs : [00000000] , eax
		mov esi, ecx
		mov[esp + 0x14], esi
		xor ebx, ebx
		mov[esi + 0x04], ebx
		mov[esi + 0x08], ebx
		mov[esi + 0x0C], ebx
		mov[esi + 0x10], ebx
		mov[esi + 0x14], ebx
		mov[esi + 0x18], ebx
		mov[esi + 0x1C], ebx
		mov[esi + 0x20], 00000001
		mov[esi + 0x24], ebx
		mov[esi + 0x28], ebx
		lea edi, [esi + 0x2C]
		mov[esp + 0x20], ebx
		mov dword ptr ds : [edi] , 0x00748120
		lea ecx, [esi + 0x30]
		mov byte ptr[esp + 0x20], 0x01
		mov dword ptr ds : [esi] , 0x00751F78
		mov dword ptr ds : [edi] , 0x00751F60
		call inv_btn_call1
		fldz
		fst dword ptr[esi + 0x00002130]
		mov[esi + 0x00002110], ebx
		fst dword ptr[esi + 0x00002134]
		mov[esi + 0x0000210C], ebx
		fst dword ptr[esi + 0x00002140]
		fst dword ptr[esi + 0x00002144]
		mov[esi + 0x00002120], ebx //
		mov[esi + 0x0000211C], ebx //
		fst dword ptr[esi + 0x00002150] //
		fst dword ptr[esi + 0x00002154] //
		mov[esi + 0x00002130], ebx //
		mov[esi + 0x0000212C], ebx //
		fst dword ptr[esi + 0x00002160] //
		fstp dword ptr[esi + 0x00002164] //
		mov[esi + 0x0000214C], ebx //
		mov[esi + 0x00002148], ebx //
		lea ebp, dword ptr ds : inv_btn_pointer_reroll // Buton pointer

		mov ecx, ebp
		mov byte ptr[esp + 20], 0x06
		call inv_btn_call2
		fldz
		fst dword ptr[esi + 0x00000724]
		mov[esi + 0x00000720], ebx
		fst dword ptr[esi + 0x00000728]
		mov[esi + 0x0000071C], ebx
		fst dword ptr[esi + 0x00000734]
		fst dword ptr[esi + 0x00000738]
		mov[esi + 0x00000730], ebx
		mov[esi + 0x0000072C], ebx
		fst dword ptr[esi + 0x00000744]
		fstp dword ptr[esi + 0x00000748]
		mov[esi + 0x00000740], ebx
		mov[esi + 0x0000073C], ebx
		mov eax, [edi]
		mov edx, [eax + 0x10]
		mov ecx, edi
		mov byte ptr[esp + 0x20], 0x0A
		call edx
		mov[esi + 0x20], ebx
		mov eax, [0x007AB0D8]
		add eax, 0xFFFFFEEC
		mov[esi + 0x04], eax
		mov al, -0x01
		mov[esi + 0x08], ebx
		mov[esi + 0x0C], 0x00000100
		mov[esi + 0x10], 0x000001E6
		mov byte ptr[esi + 0x00002115], 0x01
		mov[esi + 0x00002115], al
		mov[esi + 0x00002110], ebx
		mov byte ptr[esi + 0x00002116], 0x01
		mov edx, [esi]
		mov[esi + 0x0000211], al
		mov eax, [edx + 0x0C]
		mov ecx, esi
		mov[esi + 0x0000074C], ebx
		mov[esi + 0x00002158], bl
		call eax
		mov ecx, esi
		call inv_btn_call3
		fldz
		push ebx
		sub esp, 0x50
		fst dword ptr[esp + 0x4C]
		fst dword ptr[esp + 0x48]
		fst dword ptr[esp + 0x44]
		fst dword ptr[esp + 0x40]
		fst dword ptr[esp + 0x3C]
		fst dword ptr[esp + 0x38]
		fst dword ptr[esp + 0x34]
		fst dword ptr[esp + 0x30]
		fld1
		fst dword ptr[esp + 0x2C]
		fxch st(1)
		fst dword ptr[esp + 0x28]
		//fld dword ptr[0x00748164]
		fld dword ptr ds : [0x00748164]
		fstp dword ptr[esp + 0x24]
		fld dword ptr ds : [0x00748160]
		fst dword ptr[esp + 0x20]
		fxch st(2)
		fst dword ptr[esp + 0x1C]
		fxch st(1)
		fst dword ptr[esp + 0x18]
		fxch st(2)
		fstp dword ptr[esp + 0x14]
		fld dword ptr ds : [0x0074815C]
		fst dword ptr[esp + 0x10]
		fxch st(1)
		fstp dword ptr[esp + 0x0C]
		fxch st(1)
		fst dword ptr[esp + 0x08]
		fxch st(1)
		fstp dword ptr[esp + 0x04]
		fstp dword ptr[esp]
		push 0x01
		fld dword ptr[invenbutton_positionfloat5] // y
		push 0x20
		push 0x00000080
		push inv_button_name3
		push ebx
		push 0x20
		push 0x20
		push 0x20
		push 0x20
		call inv_btn_call4
		fld dword ptr[invenbutton_positionfloat6] // x
		push eax
		call inv_btn_call4
		mov ecx, [esi + 0x08]
		mov edx, [esi + 0x04]
		push eax
		push ecx
		push edx
		mov ecx, ebp
		call inv_btn_call5
		mov[esi + 0x00000750], 0x00000001
		mov[esi + 0x00000758], ebx
		mov eax, esi
		mov ecx, [esp + 0x18]
		mov fs : [0x00000000] , ecx
		pop ecx
		pop edi
		pop esi
		pop ebp
		pop ebx
		add esp, 0x10
		ret
	}
}


_declspec(naked) void map_button_alloc()
{
	_asm {

		push - 0x01
		push 0x007356FE
		mov eax, fs: [0x00000000]
		push eax
		push ecx
		push ebx
		push ebp
		push esi
		push edi
		mov eax, [0x007B4DD0]
		xor eax, esp
		push eax
		lea eax, [esp + 0x18]
		mov fs : [00000000] , eax
		mov esi, ecx
		mov[esp + 0x14], esi
		xor ebx, ebx
		mov[esi + 0x04], ebx
		mov[esi + 0x08], ebx
		mov[esi + 0x0C], ebx
		mov[esi + 0x10], ebx
		mov[esi + 0x14], ebx
		mov[esi + 0x18], ebx
		mov[esi + 0x1C], ebx
		mov[esi + 0x20], 00000001
		mov[esi + 0x24], ebx
		mov[esi + 0x28], ebx
		lea edi, [esi + 0x2C]
		mov[esp + 0x20], ebx
		mov dword ptr ds : [edi] , 0x00748120
		lea ecx, [esi + 0x30]
		mov byte ptr[esp + 0x20], 0x01
		mov dword ptr ds : [esi] , 0x00751F78
		mov dword ptr ds : [edi] , 0x00751F60
		call inv_btn_call1
		fldz
		fst dword ptr[esi + 0x00002130]
		mov[esi + 0x00002110], ebx
		fst dword ptr[esi + 0x00002134]
		mov[esi + 0x0000210C], ebx
		fst dword ptr[esi + 0x00002140]
		fst dword ptr[esi + 0x00002144]
		mov[esi + 0x00002120], ebx //
		mov[esi + 0x0000211C], ebx //
		fst dword ptr[esi + 0x00002150] //
		fst dword ptr[esi + 0x00002154] //
		mov[esi + 0x00002130], ebx //
		mov[esi + 0x0000212C], ebx //
		fst dword ptr[esi + 0x00002160] //
		fstp dword ptr[esi + 0x00002164] //
		mov[esi + 0x0000214C], ebx //
		mov[esi + 0x00002148], ebx //
		lea ebp, dword ptr ds : map_button_pointer // Buton pointer

		mov ecx, ebp
		mov byte ptr[esp + 20], 0x06
		call inv_btn_call2
		fldz
		fst dword ptr[esi + 0x00000724]
		mov[esi + 0x00000720], ebx
		fst dword ptr[esi + 0x00000728]
		mov[esi + 0x0000071C], ebx
		fst dword ptr[esi + 0x00000734]
		fst dword ptr[esi + 0x00000738]
		mov[esi + 0x00000730], ebx
		mov[esi + 0x0000072C], ebx
		fst dword ptr[esi + 0x00000744]
		fstp dword ptr[esi + 0x00000748]
		mov[esi + 0x00000740], ebx
		mov[esi + 0x0000073C], ebx
		mov eax, [edi]
		mov edx, [eax + 0x10]
		mov ecx, edi
		mov byte ptr[esp + 0x20], 0x0A
		call edx
		mov[esi + 0x20], ebx
		mov eax, [0x007AB0D8]
		add eax, 0xFFFFFEEC
		mov[esi + 0x04], eax
		mov al, -0x01
		mov[esi + 0x08], ebx
		mov[esi + 0x0C], 0x00000100
		mov[esi + 0x10], 0x000001E6
		mov byte ptr[esi + 0x00002115], 0x01
		mov[esi + 0x00002115], al
		mov[esi + 0x00002110], ebx
		mov byte ptr[esi + 0x00002116], 0x01
		mov edx, [esi]
		mov[esi + 0x0000211], al
		mov eax, [edx + 0x0C]
		mov ecx, esi
		mov[esi + 0x0000074C], ebx
		mov[esi + 0x00002158], bl
		call eax
		mov ecx, esi
		call inv_btn_call3
		fldz
		push ebx
		sub esp, 0x50
		fst dword ptr[esp + 0x4C]
		fst dword ptr[esp + 0x48]
		fst dword ptr[esp + 0x44]
		fst dword ptr[esp + 0x40]
		fst dword ptr[esp + 0x3C]
		fst dword ptr[esp + 0x38]
		fst dword ptr[esp + 0x34]
		fst dword ptr[esp + 0x30]
		fld1
		fst dword ptr[esp + 0x2C]
		fxch st(1)
		fst dword ptr[esp + 0x28]
		//fld dword ptr[0x00748164]
		fld dword ptr ds : [0x00748164]
		fstp dword ptr[esp + 0x24]
		fld dword ptr ds : [0x00748160]
		fst dword ptr[esp + 0x20]
		fxch st(2)
		fst dword ptr[esp + 0x1C]
		fxch st(1)
		fst dword ptr[esp + 0x18]
		fxch st(2)
		fstp dword ptr[esp + 0x14]
		fld dword ptr ds : [0x0074815C]
		fst dword ptr[esp + 0x10]
		fxch st(1)
		fstp dword ptr[esp + 0x0C]
		fxch st(1)
		fst dword ptr[esp + 0x08]
		fxch st(1)
		fstp dword ptr[esp + 0x04]
		fstp dword ptr[esp]
		push 0x01
		fld dword ptr[invenbutton_positionfloat5] // y
		push 0x20
		push 0x00000080
		push map_button
		push ebx
		push 0x20
		push 0x20
		push 0x20
		push 0x20
		call inv_btn_call4
		fld dword ptr[invenbutton_positionfloat6] // x
		push eax
		call inv_btn_call4
		mov ecx, [esi + 0x08]
		mov edx, [esi + 0x04]
		push eax
		push ecx
		push edx
		mov ecx, ebp
		call inv_btn_call5
		mov[esi + 0x00000750], 0x00000001
		mov[esi + 0x00000758], ebx
		mov eax, esi
		mov ecx, [esp + 0x18]
		mov fs : [0x00000000] , ecx
		pop ecx
		pop edi
		pop esi
		pop ebp
		pop ebx
		add esp, 0x10
		ret
	}
}


_declspec(naked) void map_button_alloc_2()
{
	_asm {

		push - 0x01
		push 0x007356FE
		mov eax, fs: [0x00000000]
		push eax
		push ecx
		push ebx
		push ebp
		push esi
		push edi
		mov eax, [0x007B4DD0]
		xor eax, esp
		push eax
		lea eax, [esp + 0x18]
		mov fs : [00000000] , eax
		mov esi, ecx
		mov[esp + 0x14], esi
		xor ebx, ebx
		mov[esi + 0x04], ebx
		mov[esi + 0x08], ebx
		mov[esi + 0x0C], ebx
		mov[esi + 0x10], ebx
		mov[esi + 0x14], ebx
		mov[esi + 0x18], ebx
		mov[esi + 0x1C], ebx
		mov[esi + 0x20], 00000001
		mov[esi + 0x24], ebx
		mov[esi + 0x28], ebx
		lea edi, [esi + 0x2C]
		mov[esp + 0x20], ebx
		mov dword ptr ds : [edi] , 0x00748120
		lea ecx, [esi + 0x30]
		mov byte ptr[esp + 0x20], 0x01
		mov dword ptr ds : [esi] , 0x00751F78
		mov dword ptr ds : [edi] , 0x00751F60
		call inv_btn_call1
		fldz
		fst dword ptr[esi + 0x00002130]
		mov[esi + 0x00002110], ebx
		fst dword ptr[esi + 0x00002134]
		mov[esi + 0x0000210C], ebx
		fst dword ptr[esi + 0x00002140]
		fst dword ptr[esi + 0x00002144]
		mov[esi + 0x00002120], ebx //
		mov[esi + 0x0000211C], ebx //
		fst dword ptr[esi + 0x00002150] //
		fst dword ptr[esi + 0x00002154] //
		mov[esi + 0x00002130], ebx //
		mov[esi + 0x0000212C], ebx //
		fst dword ptr[esi + 0x00002160] //
		fstp dword ptr[esi + 0x00002164] //
		mov[esi + 0x0000214C], ebx //
		mov[esi + 0x00002148], ebx //
		lea ebp, dword ptr ds : map_button_pointer_2 // Buton pointer

		mov ecx, ebp
		mov byte ptr[esp + 20], 0x06
		call inv_btn_call2
		fldz
		fst dword ptr[esi + 0x00000724]
		mov[esi + 0x00000720], ebx
		fst dword ptr[esi + 0x00000728]
		mov[esi + 0x0000071C], ebx
		fst dword ptr[esi + 0x00000734]
		fst dword ptr[esi + 0x00000738]
		mov[esi + 0x00000730], ebx
		mov[esi + 0x0000072C], ebx
		fst dword ptr[esi + 0x00000744]
		fstp dword ptr[esi + 0x00000748]
		mov[esi + 0x00000740], ebx
		mov[esi + 0x0000073C], ebx
		mov eax, [edi]
		mov edx, [eax + 0x10]
		mov ecx, edi
		mov byte ptr[esp + 0x20], 0x0A
		call edx
		mov[esi + 0x20], ebx
		mov eax, [0x007AB0D8]
		add eax, 0xFFFFFEEC
		mov[esi + 0x04], eax
		mov al, -0x01
		mov[esi + 0x08], ebx
		mov[esi + 0x0C], 0x00000100
		mov[esi + 0x10], 0x000001E6
		mov byte ptr[esi + 0x00002115], 0x01
		mov[esi + 0x00002115], al
		mov[esi + 0x00002110], ebx
		mov byte ptr[esi + 0x00002116], 0x01
		mov edx, [esi]
		mov[esi + 0x0000211], al
		mov eax, [edx + 0x0C]
		mov ecx, esi
		mov[esi + 0x0000074C], ebx
		mov[esi + 0x00002158], bl
		call eax
		mov ecx, esi
		call inv_btn_call3
		fldz
		push ebx
		sub esp, 0x50
		fst dword ptr[esp + 0x4C]
		fst dword ptr[esp + 0x48]
		fst dword ptr[esp + 0x44]
		fst dword ptr[esp + 0x40]
		fst dword ptr[esp + 0x3C]
		fst dword ptr[esp + 0x38]
		fst dword ptr[esp + 0x34]
		fst dword ptr[esp + 0x30]
		fld1
		fst dword ptr[esp + 0x2C]
		fxch st(1)
		fst dword ptr[esp + 0x28]
		//fld dword ptr[0x00748164]
		fld dword ptr ds : [0x00748164]
		fstp dword ptr[esp + 0x24]
		fld dword ptr ds : [0x00748160]
		fst dword ptr[esp + 0x20]
		fxch st(2)
		fst dword ptr[esp + 0x1C]
		fxch st(1)
		fst dword ptr[esp + 0x18]
		fxch st(2)
		fstp dword ptr[esp + 0x14]
		fld dword ptr ds : [0x0074815C]
		fst dword ptr[esp + 0x10]
		fxch st(1)
		fstp dword ptr[esp + 0x0C]
		fxch st(1)
		fst dword ptr[esp + 0x08]
		fxch st(1)
		fstp dword ptr[esp + 0x04]
		fstp dword ptr[esp]
		push 0x01
		fld dword ptr[invenbutton_positionfloat5] // y
		push 0x20
		push 0x00000080
		push map_button_2
		push ebx
		push 0x20
		push 0x20
		push 0x20
		push 0x20
		call inv_btn_call4
		fld dword ptr[invenbutton_positionfloat6] // x
		push eax
		call inv_btn_call4
		mov ecx, [esi + 0x08]
		mov edx, [esi + 0x04]
		push eax
		push ecx
		push edx
		mov ecx, ebp
		call inv_btn_call5
		mov[esi + 0x00000750], 0x00000001
		mov[esi + 0x00000758], ebx
		mov eax, esi
		mov ecx, [esp + 0x18]
		mov fs : [0x00000000] , ecx
		pop ecx
		pop edi
		pop esi
		pop ebp
		pop ebx
		add esp, 0x10
		ret
	}
}



_declspec(naked) void map_button_alloc_3()
{
	_asm {

		push - 0x01
		push 0x007356FE
		mov eax, fs: [0x00000000]
		push eax
		push ecx
		push ebx
		push ebp
		push esi
		push edi
		mov eax, [0x007B4DD0]
		xor eax, esp
		push eax
		lea eax, [esp + 0x18]
		mov fs : [00000000] , eax
		mov esi, ecx
		mov[esp + 0x14], esi
		xor ebx, ebx
		mov[esi + 0x04], ebx
		mov[esi + 0x08], ebx
		mov[esi + 0x0C], ebx
		mov[esi + 0x10], ebx
		mov[esi + 0x14], ebx
		mov[esi + 0x18], ebx
		mov[esi + 0x1C], ebx
		mov[esi + 0x20], 00000001
		mov[esi + 0x24], ebx
		mov[esi + 0x28], ebx
		lea edi, [esi + 0x2C]
		mov[esp + 0x20], ebx
		mov dword ptr ds : [edi] , 0x00748120
		lea ecx, [esi + 0x30]
		mov byte ptr[esp + 0x20], 0x01
		mov dword ptr ds : [esi] , 0x00751F78
		mov dword ptr ds : [edi] , 0x00751F60
		call inv_btn_call1
		fldz
		fst dword ptr[esi + 0x00002130]
		mov[esi + 0x00002110], ebx
		fst dword ptr[esi + 0x00002134]
		mov[esi + 0x0000210C], ebx
		fst dword ptr[esi + 0x00002140]
		fst dword ptr[esi + 0x00002144]
		mov[esi + 0x00002120], ebx //
		mov[esi + 0x0000211C], ebx //
		fst dword ptr[esi + 0x00002150] //
		fst dword ptr[esi + 0x00002154] //
		mov[esi + 0x00002130], ebx //
		mov[esi + 0x0000212C], ebx //
		fst dword ptr[esi + 0x00002160] //
		fstp dword ptr[esi + 0x00002164] //
		mov[esi + 0x0000214C], ebx //
		mov[esi + 0x00002148], ebx //
		lea ebp, dword ptr ds : map_button_pointer_3 // Buton pointer

		mov ecx, ebp
		mov byte ptr[esp + 20], 0x06
		call inv_btn_call2
		fldz
		fst dword ptr[esi + 0x00000724]
		mov[esi + 0x00000720], ebx
		fst dword ptr[esi + 0x00000728]
		mov[esi + 0x0000071C], ebx
		fst dword ptr[esi + 0x00000734]
		fst dword ptr[esi + 0x00000738]
		mov[esi + 0x00000730], ebx
		mov[esi + 0x0000072C], ebx
		fst dword ptr[esi + 0x00000744]
		fstp dword ptr[esi + 0x00000748]
		mov[esi + 0x00000740], ebx
		mov[esi + 0x0000073C], ebx
		mov eax, [edi]
		mov edx, [eax + 0x10]
		mov ecx, edi
		mov byte ptr[esp + 0x20], 0x0A
		call edx
		mov[esi + 0x20], ebx
		mov eax, [0x007AB0D8]
		add eax, 0xFFFFFEEC
		mov[esi + 0x04], eax
		mov al, -0x01
		mov[esi + 0x08], ebx
		mov[esi + 0x0C], 0x00000100
		mov[esi + 0x10], 0x000001E6
		mov byte ptr[esi + 0x00002115], 0x01
		mov[esi + 0x00002115], al
		mov[esi + 0x00002110], ebx
		mov byte ptr[esi + 0x00002116], 0x01
		mov edx, [esi]
		mov[esi + 0x0000211], al
		mov eax, [edx + 0x0C]
		mov ecx, esi
		mov[esi + 0x0000074C], ebx
		mov[esi + 0x00002158], bl
		call eax
		mov ecx, esi
		call inv_btn_call3
		fldz
		push ebx
		sub esp, 0x50
		fst dword ptr[esp + 0x4C]
		fst dword ptr[esp + 0x48]
		fst dword ptr[esp + 0x44]
		fst dword ptr[esp + 0x40]
		fst dword ptr[esp + 0x3C]
		fst dword ptr[esp + 0x38]
		fst dword ptr[esp + 0x34]
		fst dword ptr[esp + 0x30]
		fld1
		fst dword ptr[esp + 0x2C]
		fxch st(1)
		fst dword ptr[esp + 0x28]
		//fld dword ptr[0x00748164]
		fld dword ptr ds : [0x00748164]
		fstp dword ptr[esp + 0x24]
		fld dword ptr ds : [0x00748160]
		fst dword ptr[esp + 0x20]
		fxch st(2)
		fst dword ptr[esp + 0x1C]
		fxch st(1)
		fst dword ptr[esp + 0x18]
		fxch st(2)
		fstp dword ptr[esp + 0x14]
		fld dword ptr ds : [0x0074815C]
		fst dword ptr[esp + 0x10]
		fxch st(1)
		fstp dword ptr[esp + 0x0C]
		fxch st(1)
		fst dword ptr[esp + 0x08]
		fxch st(1)
		fstp dword ptr[esp + 0x04]
		fstp dword ptr[esp]
		push 0x01
		fld dword ptr[invenbutton_positionfloat5] // y
		push 0x20
		push 0x00000080
		push map_button_3
		push ebx
		push 0x20
		push 0x20
		push 0x20
		push 0x20
		call inv_btn_call4
		fld dword ptr[invenbutton_positionfloat6] // x
		push eax
		call inv_btn_call4
		mov ecx, [esi + 0x08]
		mov edx, [esi + 0x04]
		push eax
		push ecx
		push edx
		mov ecx, ebp
		call inv_btn_call5
		mov[esi + 0x00000750], 0x00000001
		mov[esi + 0x00000758], ebx
		mov eax, esi
		mov ecx, [esp + 0x18]
		mov fs : [0x00000000] , ecx
		pop ecx
		pop edi
		pop esi
		pop ebp
		pop ebx
		add esp, 0x10
		ret
	}
}

DWORD Send_Buttons_Call = 0x006307F3;
DWORD Continue_Addr = 0x0042B6D2;

_declspec(naked) void New_Send_BUttons_To_Memory() {
	_asm {

		push 0x0001AC3C
		mov[esp + 0x28], bl
		call Send_Buttons_Call
		add esp, 0x04
		mov[esp + 0x18], eax
		mov byte ptr ds : [esp + 0x24] , 0x22
		cmp eax, ebp
		je originalcode
		mov ecx, eax
		Call Raid_Button_1
		mov ecx, eax
		Call Raid_Button_2
		mov ecx, eax
		call Raid_Button_3
		mov ecx, eax
		Call Raid_Button_4
		mov ecx, eax
		Call Raid_Button_5
		jmp button_2



	originalcode:
		xor eax, eax
			mov ecx, 0x00000034
			jmp Continue_Addr


			button_2 :
		push 0x0000C9A4
			mov[esp + 0x28], bl
			call Send_Buttons_Call
			add esp, 0x04
			mov[esp + 0x18], eax
			mov byte ptr ds : [esp + 0x24] , 0x23
			cmp eax, ebp
			je xor_and_continue_2
			mov ecx, eax
			Call invenbutton_alloc_1
			mov ecx, eax
			Call invenbutton_alloc_2
			mov ecx, eax
			Call invenbutton_alloc_3

			button_3 :
		push 0x00005834
			mov[esp + 0x28], bl
			call Send_Buttons_Call
			add esp, 0x04
			mov[esp + 0x18], eax
			mov byte ptr ds : [esp + 0x24] , 0x24
			cmp eax, ebp
			je originalcode
			mov ecx, eax
			call map_button_alloc
			mov ecx, eax
			call map_button_alloc_2
			mov ecx, eax
			call map_button_alloc_3
			jmp originalcode


			xor_and_continue :
		xor eax, eax
			jmp button_2

			xor_and_continue_2 :
		xor eax, eax
			jmp button_3

	}
}


DWORD invenbutton_renderjmp = 0x518778;
DWORD invenbutton_rendercall1 = 0x550120;
DWORD invenbutton_rendercall2 = 0x550A20;

__declspec(naked) void invenbutton_render()
{
	_asm
	{
		// Birinci buton
		mov eax, [esi + 0x08]
		mov ecx, [esi + 0x04]
		push eax
		lea edi, dword ptr ds : inv_btn_pointer_sell // pointer
		push ecx
		mov ecx, edi
		call invenbutton_rendercall1
		mov ecx, edi
		call invenbutton_rendercall2

		// Ýkinci buton
		mov eax, [esi + 0x08]
		mov ecx, [esi + 0x04]
		push eax
		lea edi, dword ptr ds : inv_btn_pointer_link // pointer
		push ecx
		mov ecx, edi
		call invenbutton_rendercall1
		mov ecx, edi
		call invenbutton_rendercall2

		// Üçüncü buton
		mov eax, [esi + 0x08]
		mov ecx, [esi + 0x04]
		push eax
		lea edi, dword ptr ds : inv_btn_pointer_reroll // pointer
		push ecx
		mov ecx, edi
		call invenbutton_rendercall1
		mov ecx, edi
		call invenbutton_rendercall2



		mov ecx, [esi + 0x0000074C]

		pop edi
		pop ebp
		pop ebx
		test ecx, ecx

		jmp invenbutton_renderjmp


	}
}

DWORD invenbutton_clickjmp = 0x51A4E8;
DWORD invenbutton_clickcall = 0x00550A10;
DWORD invenbutton_clicknpcjmp = 0x0051A5A3;

#define invenbutton_click_npctype1 1 // Type
#define invenbutton_click_npctypeid1 300 // TypeID
#define invenbutton_click_npcid1 101 // Npc ID

#define invenbutton_click_npctype2 3 // Type
#define invenbutton_click_npctypeid2 40 // TypeID
#define invenbutton_click_npcid2 102 // Npc ID

#define invenbutton_click_npctype3 1 // Type
#define invenbutton_click_npctypeid3 248 // TypeID
#define invenbutton_click_npcid3 121 // Npc ID

DWORD invenbutton_clickjmk = 0x5EBAF0;

__declspec(naked) void invenbutton_click()
{
	_asm
	{
		// Birinci buton
		lea ecx, dword ptr ds : inv_btn_pointer_sell
		call invenbutton_clickcall
		test eax, eax
		jne invenbutton_npc1
		// Ýkinci buton
		lea ecx, dword ptr ds : inv_btn_pointer_link
		call invenbutton_clickcall
		test eax, eax
		jne invenbutton_npc2
		// Üçüncü buton
		lea ecx, dword ptr ds : inv_btn_pointer_reroll
		call invenbutton_clickcall
		test eax, eax
		jne invenbutton_npc3

		originalcode :
		lea ecx, [esi + 0x00000144]
			jmp invenbutton_clickjmp

			invenbutton_npc1 :
		//fails if a window is already open
		cmp dword ptr ds : [0x009144E4] , 0
			jne originalcode
			//uses a market npc without items
			mov dword ptr ds : [0x091AD44] , invenbutton_click_npctype1 // type
			mov dword ptr ds : [0x091AD40] , invenbutton_click_npctypeid1 // typeid
			mov dword ptr ds : [0x022AB7B8] , 0 // name
			mov dword ptr ds : [0x09144E4] , invenbutton_click_npcid1 // market
			jmp invenbutton_clicknpcjmp

			invenbutton_npc2 :
		//fails if a window is already open
		cmp dword ptr ds : [0x009144E4] , 0
			jne originalcode
			//uses a market npc without items
			mov dword ptr ds : [0x091AD44] , invenbutton_click_npctype2 // type
			mov dword ptr ds : [0x091AD40] , invenbutton_click_npctypeid2 // typeid
			mov dword ptr ds : [0x022AB7B8] , 0 // name
			mov dword ptr ds : [0x09144E4] , invenbutton_click_npcid2 // market
			jmp invenbutton_clicknpcjmp

			invenbutton_npc3 :
		//fails if a window is already open
		cmp dword ptr ds : [0x009144E4] , 0
			jne originalcode
			//uses a market npc without items
			mov dword ptr ds : [0x091AD44] , invenbutton_click_npctype3 // type
			mov dword ptr ds : [0x091AD40] , invenbutton_click_npctypeid3 // typeid
			mov dword ptr ds : [0x022AB7B8] , 0 // name
			mov dword ptr ds : [0x09144E4] , invenbutton_click_npcid3 // market
			jmp invenbutton_clicknpcjmp




	}
}


DWORD Render_Call = 0x00550120;//00550B00;
DWORD Render_Call_2 = 0x00550A20;//00551400;
DWORD Render_Raid_Button_Return = 0x0053F8D4;//00540284;
_declspec(naked) void Render_Raid_Buttons() {
	_asm {
		pushad
		mov eax, [edi + 0x08]
		mov ecx, [edi + 0x04]
		push eax
		lea edi, dword ptr ds : raid_btn_1// button 1
		push ecx
		mov ecx, edi
		call Render_Call
		mov ecx, edi
		call Render_Call_2
		popad

		// 022FE180
		// 022FE220
		// 022FE2E0
		pushad
		mov eax, [edi + 0x08]
		mov ecx, [edi + 0x04]
		push eax
		lea edi, dword ptr ds : raid_btn_2 // button 2
		push ecx
		mov ecx, edi
		call Render_Call
		mov ecx, edi
		call Render_Call_2
		popad

		pushad
		mov eax, [edi + 0x08]
		mov ecx, [edi + 0x04]
		push eax
		lea edi, dword ptr ds : raid_btn_3 // button 3
		push ecx
		mov ecx, edi
		call Render_Call
		mov ecx, edi
		call Render_Call_2
		popad

		pushad
		mov eax, [edi + 0x08]
		mov ecx, [edi + 0x04]
		push eax
		lea edi, dword ptr ds : raid_btn_4 // button 4
		push ecx
		mov ecx, edi
		call Render_Call
		mov ecx, edi
		call Render_Call_2
		popad


		pushad
		mov eax, [edi + 0x08]
		mov ecx, [edi + 0x04]
		push eax
		lea edi, dword ptr ds : raid_btn_5 // button 5
		push ecx
		mov ecx, edi
		call Render_Call
		mov ecx, edi
		call Render_Call_2
		popad

		mov ebx, [esp + 0x28]
		test ebx, ebx
		jmp Render_Raid_Button_Return
	}
}



DWORD render_hover = 0x00550A10;
DWORD hover_and_click_return = 0x004DEE7E;
_declspec(naked) void Hover_and_Click_Map_Button() {
	_asm {
		pushad
		lea ecx, dword ptr ds : map_button_pointer
		call render_hover
		test eax, eax
		jne npc_01
		lea ecx, dword ptr ds : map_button_pointer_2
		call render_hover
		test eax, eax
		jne npc_02
		lea ecx, dword ptr ds : map_button_pointer_3
		call render_hover
		test eax, eax
		jne npc_03
		popad

		originalcode :
		mov eax, [esi + 0x04]
			mov ecx, [0x007C3C0C]
			jmp hover_and_click_return

			npc_01 :
		// gerente veterano
		popad
			mov dword ptr ds : [0x91AD44] , 0x1 //type
			mov dword ptr ds : [0x91AD40] , 240 //type id
			mov dword ptr ds : [0x9144F0] , -0x1 //icon
			mov dword ptr ds : [0x22AB7B8] , 0x0 //name
			mov dword ptr ds : [0x9144E4] , 0x64 //market
			jmp originalcode



		npc_02:
		// decidir
		popad
			mov dword ptr ds : [0x91AD44] , 0x4 //type
			mov dword ptr ds : [0x91AD40] , 0x1 //type id
			mov dword ptr ds : [0x9144F0] , -0x1 //icon
			mov dword ptr ds : [0x22AB7B8] , 0x0 //name
			mov dword ptr ds : [0x9144E4] , 0x64 //market
			jmp originalcode


			npc_03 :
		// leil�o
		popad
			mov dword ptr ds : [0x91AD44] , 1 //type
			mov dword ptr ds : [0x91AD40] , 180 //type id
			mov dword ptr ds : [0x9144F0] , -0x1 //icon
			mov dword ptr ds : [0x22AB7B8] , 0x0 //name
			mov dword ptr ds : [0x9144E4] , 0x64 //market
			jmp originalcode
	}
}

DWORD render_map_addr = 0x00551B40;
DWORD render_map_return = 0x004E1143;
_declspec(naked) void render_map_buttons() {
	_asm {

		mov eax, [esi + 0x08]
		mov ecx, [esi + 0x04]
		add ecx, -285
		add eax, -345
		push eax
		push ecx
		lea ecx, dword ptr ds : map_button_pointer
		call render_map_addr

		mov eax, [esi + 0x08]
		mov ecx, [esi + 0x04]
		add ecx, -285 // Horizontal
		add eax, -378 //Vertical 
		push eax
		push ecx
		lea ecx, dword ptr ds : map_button_pointer_2
		call render_map_addr

		mov eax, [esi + 0x08]
		mov ecx, [esi + 0x04]
		add ecx, -285
		add eax, -311
		push eax
		push ecx
		lea ecx, dword ptr ds : map_button_pointer_3
		call render_map_addr

		fldz
		fcomp dword ptr ds : [esi + 0x00000CB4]
		jmp render_map_return


	}
}




DWORD Get_Click = 0x00550A10;//005513F0;
DWORD Raid_Click_Return = 0x0053F46A;//0053FE1A;
_declspec(naked) void Click_Raid_Button() {
	_asm {
		pushad
		lea ecx, dword ptr ds : raid_btn_1
		call Get_Click
		test eax, eax
		jne Raid_1
		popad

		pushad
		lea ecx, dword ptr ds : raid_btn_2
		call Get_Click
		test eax, eax
		jne Raid_2
		popad


		pushad
		lea ecx, dword ptr ds : raid_btn_3
		call Get_Click
		test eax, eax
		jne Raid_3
		popad


		pushad
		lea ecx, dword ptr ds : raid_btn_4
		call Get_Click
		test eax, eax
		jne Raid_4
		popad

		pushad
		lea ecx, dword ptr ds : raid_btn_5
		call Get_Click
		test eax, eax
		jne Raid_5
		popad

		originalcode :
		cmp dword ptr ds : [0x022AA800] , ebp
			jmp Raid_Click_Return


			Raid_1 :
		popad
			mov byte ptr ds : [raid_pointer] , 0x00
			jmp originalcode

			Raid_2 :
		popad
			mov byte ptr ds : [raid_pointer] , 0x01
			jmp originalcode


			Raid_3 :
		popad
			mov byte ptr ds : [raid_pointer] , 0x02
			jmp originalcode

			Raid_4 :
		popad
			mov byte ptr ds : [raid_pointer] , 0x03
			jmp originalcode

			Raid_5 :
		popad
			mov byte ptr ds : [raid_pointer] , 0x04
			jmp originalcode
	}
}

DWORD original_code_addr = 0x00551072;//00551A52;
DWORD Send_Holding_Return = 0x00550F5D;// 0055193D;
_declspec(naked) void Send_Holding() {
	_asm {
		cmp byte ptr ds : [raid_pointer] , 00
		je Send_Holding_Raid_1
		cmp byte ptr ds : [raid_pointer] , 01
		je Send_Holding_Raid_2
		cmp byte ptr ds : [raid_pointer] , 02
		je Send_Holding_Raid_3
		cmp byte ptr ds : [raid_pointer] , 03
		je Send_Holding_Raid_4
		cmp byte ptr ds : [raid_pointer] , 04
		je Send_Holding_Raid_5



	originalcode:
		cmp byte ptr ds : [esi + 0x06] , 00
			je original_code_conditional
			jmp Send_Holding_Return

			Send_Holding_Raid_1 :
		mov byte ptr ds : [raid_btn_1 + 0x06] , 01
			jmp originalcode

			Send_Holding_Raid_2 :
		mov byte ptr ds : [raid_btn_2 + 0x06] , 01
			jmp originalcode

			Send_Holding_Raid_3 :
		mov byte ptr ds : [raid_btn_3 + 0x06] , 01
			jmp originalcode

			Send_Holding_Raid_4 :
		mov byte ptr ds : [raid_btn_4 + 0x06] , 01
			jmp originalcode

			Send_Holding_Raid_5 :
		mov byte ptr ds : [raid_btn_5 + 0x06] , 01
			jmp originalcode



		original_code_conditional:
		jmp original_code_addr
	}
}

void hook::Buttons() {


	util::detour((void*)0x0053F8CE, Render_Raid_Buttons, 6);
	util::detour((void*)0x0053F464, Click_Raid_Button, 6);
	util::detour((void*)0x00550F53, Send_Holding, 10);
	util::detour((PVOID)0x0042B6CB, New_Send_BUttons_To_Memory, 7);

	util::detour((void*)0x004E113B, render_map_buttons, 8);
	util::detour((void*)0x004DEE75, Hover_and_Click_Map_Button, 9);
	util::detour((void*)0x518773, invenbutton_render, 5);
	util::detour((void*)0x51A4E2, invenbutton_click, 6);
}