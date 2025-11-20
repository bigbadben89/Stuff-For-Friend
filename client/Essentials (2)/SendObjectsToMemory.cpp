#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
// test
std::string pvp_list[255];
std::string warMove[255];
std::string pvp_cover[255];
std::string check_btn[255];
std::string teleportButton[255];
std::string closeButton[255];
std::string battleground[255];
std::string debuff[255];
std::string isPagination[255];
std::string isPagination2[255];
std::string isCheckChat[255];
std::string isClassIconDPSLoad[255];
std::string isClassIconRangeLoad[255];
std::string isClassIconMagicLoad[255];
std::string isClassIconCureLoad[255];
std::string isClassIconBloodLoad[255];
std::string isClassIconTankLoad[255];
std::string ownKillTable[32];
std::string isOwnKillClose[255];
std::string isOwnKillIcon[255];
std::string isFace[16];
std::string isFace2[16];
std::string isFace3[16];
std::string isFace4[16];
std::string isFace5[16];
std::string isFace6[16];
std::string isFace7[16];
std::string isFace8[16];
std::string raidFighter[16];
std::string flagAllianceLight[16];
std::string flagAllianceFury[16];
std::string raidDefender[16];
std::string raidRanger[16];
std::string raidArcher[16];
std::string raidMage[16];
std::string raidHealer[16];// for simple targa 
LPCSTR pvpload = "pvp_list.tga";
LPCSTR checkboxLoad = "checkbox.tga";
LPCSTR isCheck = "chat_check.tga";
LPCSTR paginationLoad = "pagination.tga";
LPCSTR loaddebuff = "debufficon.tga";
LPCSTR isClassIconDPS = "lut-war.tga";
LPCSTR isOwnKillTableLoad = "global_kills.png";
LPCSTR isClassIconRange = "arq-hunter.tga";
LPCSTR isClassIconMagic = "mag-pag.tga";
LPCSTR isClassIconCure = "priest-orc.tga";
LPCSTR isClassIconBlood = "rang-assas.tga";
LPCSTR isClassIconTank = "def-tank.tga";

LPCSTR isFaceLoad = "create_appearance_def_face.tga";
LPCSTR isFaceLoad2 = "create_appearance_dem_face.tga";
LPCSTR isFaceLoad3 = "create_appearance_elf_face.tga";
LPCSTR isFaceLoad4 = "create_appearance_elm_face.tga";
LPCSTR isFaceLoad5 = "create_appearance_huf_face.tga";
LPCSTR isFaceLoad6 = "create_appearance_hum_face.tga";
LPCSTR isFaceLoad7 = "create_appearance_vif_face.tga";
LPCSTR isFaceLoad8 = "create_appearance_vim_face.tga";
DWORD sendtoMemory = 0x00634137;
DWORD sendObjectMemoryReturn = 0x0044F896;
DWORD sendMemory2 = 0x0057B560;
__declspec(dllexport) _declspec(naked) void sendObjectMemory() {
	_asm {



		pushad
		push 0x0054FE50
		push 0x0054FCE0
		push 0x02
		push 0x000005D8
		lea eax, dword ptr ds : pvp_list
		push eax
		call sendtoMemory
		push 0x0054FE50
		push 0x0054FCE0
		push 0x02
		push 0x000005D8
		lea eax, dword ptr ds : isOwnKillClose
		push eax
		call sendtoMemory
		push 0x0054FE50
		push 0x0054FCE0
		push 0x02
		push 0x000005D8
		lea eax, dword ptr ds : isOwnKillIcon
		push eax
		call sendtoMemory
		push 0x0054FE50
		push 0x0054FCE0
		push 0x02
		push 0x000005D8
		lea eax, dword ptr ds : teleportButton
		push eax
		call sendtoMemory
		push 0x0054FE50
		push 0x0054FCE0
		push 0x02
		push 0x000005D8
		lea eax, dword ptr ds : pvp_cover
		push eax
		call sendtoMemory
		push 0x0054FE50
		push 0x0054FCE0
		push 0x02
		push 0x000005D8
		lea eax, dword ptr ds : warMove
		push eax
		call sendtoMemory
		push 0x0054FE50
		push 0x0054FCE0
		push 0x02
		push 0x000005D8
		lea eax, dword ptr ds : closeButton
		push eax
		call sendtoMemory

		push 0x0054FE50
		push 0x0054FCE0
		push 0x02
		push 0x000005D8
		lea eax, dword ptr ds : isPagination
		push eax
		call sendtoMemory

		push 0x0054FE50
		push 0x0054FCE0
		push 0x02
		push 0x000005D8
		lea eax, dword ptr ds : isPagination2
		push eax
		call sendtoMemory

		push 0x00000200
		push 0x00000100
		push pvpload
		push 0x0748194
		lea ecx, dword ptr ds : battleground
		call sendMemory2

		push 0x17
		push 0x17
		push loaddebuff
		push 0x0748194
		lea ecx, dword ptr ds : debuff
		call sendMemory2

		push 0x20
		push 0x20
		push isClassIconDPS
		push 0x0748194
		lea ecx, dword ptr ds : isClassIconDPSLoad
		call sendMemory2

		push 0x20
		push 0x20
		push isClassIconTank
		push 0x0748194
		lea ecx, dword ptr ds : isClassIconTankLoad
		call sendMemory2

		push 0x20
		push 0x20
		push isClassIconRange
		push 0x0748194
		lea ecx, dword ptr ds : isClassIconRangeLoad
		call sendMemory2

		push 0x200
		push 0x200
		push isOwnKillTableLoad
		push 0x0748194
		lea ecx, dword ptr ds : ownKillTable
		call sendMemory2

		push 0x20
		push 0x20
		push isClassIconMagic
		push 0x0748194
		lea ecx, dword ptr ds : isClassIconMagicLoad
		call sendMemory2

		push 0x20
		push 0x20
		push isClassIconCure
		push 0x0748194
		lea ecx, dword ptr ds : isClassIconCureLoad
		call sendMemory2

		push 0x20
		push 0x20
		push isClassIconBlood
		push 0x0748194
		lea ecx, dword ptr ds : isClassIconBloodLoad
		call sendMemory2


		push 12
		push 12
		push isCheck
		push 0x0748194
		lea ecx, dword ptr ds : check_btn
		call sendMemory2

		push 15
		push 14
		push checkboxLoad
		push 0x0748194
		lea ecx, dword ptr ds : isCheckChat
		call sendMemory2

		push 0x28
		push 0x28
		push isFaceLoad
		push 0x0748194
		lea ecx, dword ptr ds : isFace
		call sendMemory2

		push 0x28
		push 0x28
		push isFaceLoad2
		push 0x0748194
		lea ecx, dword ptr ds : isFace2
		call sendMemory2

		push 0x28
		push 0x28
		push isFaceLoad3
		push 0x0748194
		lea ecx, dword ptr ds : isFace3
		call sendMemory2

		push 0x28
		push 0x28
		push isFaceLoad4
		push 0x0748194
		lea ecx, dword ptr ds : isFace4
		call sendMemory2

		push 0x28
		push 0x28
		push isFaceLoad5
		push 0x0748194
		lea ecx, dword ptr ds : isFace5
		call sendMemory2


		push 0x28
		push 0x28
		push isFaceLoad6
		push 0x0748194
		lea ecx, dword ptr ds : isFace6
		call sendMemory2

		push 0x28
		push 0x28
		push isFaceLoad7
		push 0x0748194
		lea ecx, dword ptr ds : isFace7
		call sendMemory2


		push 0x28
		push 0x28
		push isFaceLoad8
		push 0x0748194
		lea ecx, dword ptr ds : isFace8
		call sendMemory2
		popad


		push 0x0074AA94
		jmp sendObjectMemoryReturn
	}
}

LPCSTR cTitulo01 = "Title1.tga";
LPCSTR cTitulo02 = "Title2.tga";
LPCSTR cTitulo03 = "Title3.tga";
LPCSTR cTitulo04 = "Title4.tga";
LPCSTR cTitulo05 = "Title5.tga";
LPCSTR cTitulo06 = "Title6.tga";
LPCSTR cTitulo07 = "Title7.tga";
LPCSTR cTitulo08 = "Title8.tga";
LPCSTR cTitulo09 = "Title9.tga";
LPCSTR cTitulo10 = "Title10.tga";
LPCSTR cTitulo11 = "title11.tga";
LPCSTR cTitulo12 = "title12.tga";
LPCSTR cTitulo13 = "title13.tga";
LPCSTR cTitulo14 = "title14.tga";
LPCSTR cTitulo15 = "title15.tga";
LPCSTR cTitulo16 = "title16.tga";
LPCSTR cTitulo17 = "title17.tga";
LPCSTR cTitulo18 = "title18.tga";
LPCSTR cTitulo19 = "title19.tga";
LPCSTR cTitulo20 = "title20.tga";
LPCSTR cTitulo21 = "title21.tga";
LPCSTR cTitulo22 = "title22.tga";
LPCSTR cTitulo23 = "title23.tga";
LPCSTR cTitulo24 = "title24.tga";
LPCSTR cTitulo25 = "title25.tga";
LPCSTR cTitulo26 = "title26.tga";
LPCSTR cTitulo27 = "title27.tga";
LPCSTR cTitulo28 = "title28.tga";
LPCSTR cTitulo29 = "title29.tga";
LPCSTR cTitulo30 = "title30.tga";
LPCSTR cTitulo31 = "title31.tga"; // gs title
LPCSTR cTitulo32 = "title32.tga"; // gm title
LPCSTR cTitulo33 = "title33.tga"; // adm title
LPCSTR cTitulo34 = "title34.tga"; // dev title 
LPCSTR cTitulo35 = "title35.tga"; // mvp title
LPCSTR cTitulo36 = "title36.tga";
LPCSTR cTitulo37 = "title37.tga";
LPCSTR cTitulo38 = "title38.tga";
LPCSTR cTitulo39 = "title39.tga";
LPCSTR cTitulo40 = "title40.tga";
LPCSTR cTitulo41 = "title41.tga";
LPCSTR cTitulo42 = "title42.tga";
LPCSTR cTitulo43 = "title43.tga";
LPCSTR cTitulo44 = "title44.tga";
LPCSTR cTitulo45 = "title45.tga";
LPCSTR cTitulo46 = "title46.tga";
LPCSTR cTitulo47 = "title47.tga";
LPCSTR cTitulo48 = "title48.tga";
LPCSTR cTitulo49 = "title49.tga";
LPCSTR cTitulo50 = "title50.tga";
LPCSTR cTitulo51 = "title51.tga";
LPCSTR cTitulo52 = "title52.tga";
LPCSTR cTitulo53 = "title53.tga";
LPCSTR cTitulo54 = "title54.tga";
LPCSTR cTitulo55 = "title55.tga";
LPCSTR cTitulo56 = "title56.tga";
LPCSTR cTitulo57 = "title57.tga";
LPCSTR cTitulo58 = "title58.tga";
LPCSTR cTitulo59 = "title59.tga";
LPCSTR cTitulo60 = "title60.tga";

LPCSTR HP_Bar_New = "player_hpbar.tga";
LPCSTR HP_Bar_New_2 = "player_hpbar_dark.tga";
LPCSTR HP_Bar_Bg = "monster_hpbar_bg.tga";
DWORD cGetCall = 0x0057B560;
DWORD cAllocReturn = 0x0044F8DE;
_declspec(naked) void cAllocTitle()
{
	_asm {

		push 0x08
		push 0x80
		push HP_Bar_New
		push 0x00748194 // interface
		lea ecx, [esi + 0x00142050]
		call cGetCall

		push 0x08
		push 0x80
		push HP_Bar_New_2
		push 0x00748194 // interface
		lea ecx, [esi + 0x00142100]
		call cGetCall

		push 0x08
		push 0x80
		push HP_Bar_Bg
		push 0x00748194 // interface
		lea ecx, [esi + 0x00142000]
		call cGetCall




		push 0x40
		push 0x100
		push cTitulo01
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141000]
		call cGetCall

		push 0x40
		push 0x100
		push cTitulo02
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141020]
		call cGetCall


		push 0x40
		push 0x100
		push cTitulo03
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141040]
		call cGetCall


		push 0x40
		push 0x100
		push cTitulo04
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141060]
		call cGetCall

		push 0x40
		push 0x100
		push cTitulo05
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141080]
		call cGetCall

		push 0x40
		push 0x100
		push cTitulo06
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141100]
		call cGetCall

		push 0x40
		push 0x100
		push cTitulo07
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141120]
		call cGetCall

		push 0x40
		push 0x100
		push cTitulo08
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141140]
		call cGetCall

		push 0x40
		push 0x100
		push cTitulo09
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141160]
		call cGetCall

		push 0x40
		push 0x100
		push cTitulo10
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141180]
		call cGetCall



		push 0x40
		push 0x100
		push cTitulo11
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141240]
		call cGetCall

		push 0x40
		push 0x100
		push cTitulo12
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141260]
		call cGetCall

		push 0x40
		push 0x100
		push cTitulo13
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141280]
		call cGetCall

		push 0x40
		push 0x100
		push cTitulo14
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141300]
		call cGetCall


		push 0x40
		push 0x100
		push cTitulo15
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141320]
		call cGetCall

		push 0x40
		push 0x100
		push cTitulo16
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141340]
		call cGetCall

		push 0x40
		push 0x100
		push cTitulo17
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141360]
		call cGetCall

		push 0x40
		push 0x100
		push cTitulo18
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141380]
		call cGetCall


		push 0x40
		push 0x100
		push cTitulo19
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141400]
		call cGetCall

		push 0x40
		push 0x100
		push cTitulo20
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141420]
		call cGetCall

		push 0x40
		push 0x100
		push cTitulo21
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141440]
		call cGetCall

		push 0x40
		push 0x100
		push cTitulo22
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141460]
		call cGetCall


		push 0x40
		push 0x100
		push cTitulo23
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141480]
		call cGetCall

		push 0x40
		push 0x100
		push cTitulo24
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141500]
		call cGetCall

		push 0x40
		push 0x100
		push cTitulo25
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141520]
		call cGetCall

		push 0x40
		push 0x100
		push cTitulo26
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141540]
		call cGetCall


		push 0x40
		push 0x100
		push cTitulo27
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141560]
		call cGetCall


		push 0x40
		push 0x100
		push cTitulo28
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141580]
		call cGetCall


		push 0x40
		push 0x100
		push cTitulo30
		push 0x00748194 // interface
		lea ecx, [esi + 0x00141600]
		call cGetCall



		push 0x20
		push 0x20
		push 0x74AA5C
		push 0x748194
		jmp cAllocReturn

	}
}




DWORD sendnfoToMemory = 0x00551860;
DWORD sendfoToMemoryReturn = 0x0047DA4C;
//LPCSTR invenCheck = "inven_check.tga";
LPCSTR ownBtn = "Main_Bottom_Btn_WarMode.tga";
LPCSTR teleportBtn = "teleportButton.tga";
LPCSTR pvpListLoad = "pvp_list.tga";
LPCSTR pvpcoverLoad = "pvp_list_cover.tga";
LPCSTR warMoveLoad = "WarMove.tga";
LPCSTR talkCloseLoad = "close_button_battleground.tga";
LPCSTR talkCloseLoad2 = "talk1_close_button.tga";
__declspec(dllexport) _declspec(naked) void sendObject_Memory() {
	_asm {


		fldz
		push 00
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
		fld dword ptr ds : [0x748164]
		fstp dword ptr ds : [esp + 0x24]
		fld dword ptr ds : [0x0748160]
		fst dword ptr ds : [esp + 0x20]
		fxch st(2)
		fst dword ptr ds : [esp + 0x1C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x18]
		fxch st(2)
		fstp dword ptr ds : [esp + 0x14]
		fld dword ptr ds : [0x074815C]
		fst dword ptr ds : [esp + 0x10]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x0C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x08]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x04]
		fstp dword ptr ds : [esp]
		push 01
		//fld dword ptr ds : [0x07ABB20]
		push 0x40
		push 0x400
		push teleportBtn
		push 00
		push 49
		push 171
		push 0x40
		push 0x100
		push ebx
		push ebx
		push ebx
		push ebx
		lea ecx, dword ptr ds : teleportButton
		call sendnfoToMemory

		fldz
		push 00
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
		fld dword ptr ds : [0x748164]
		fstp dword ptr ds : [esp + 0x24]
		fld dword ptr ds : [0x0748160]
		fst dword ptr ds : [esp + 0x20]
		fxch st(2)
		fst dword ptr ds : [esp + 0x1C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x18]
		fxch st(2)
		fstp dword ptr ds : [esp + 0x14]
		fld dword ptr ds : [0x074815C]
		fst dword ptr ds : [esp + 0x10]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x0C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x08]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x04]
		fstp dword ptr ds : [esp]
		push 01
		//	fld dword ptr ds:[0x07ABB20]
		push 0x40
		push 0x100
		push ownBtn
		push 00
		push 25
		push 32
		push 0x40
		push 0x40
		push ebx
		push ebx
		push ebx
		push ebx
		lea ecx, dword ptr ds : isOwnKillIcon
		call sendnfoToMemory

		fldz
		push 00
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
		fld dword ptr ds : [0x748164]
		fstp dword ptr ds : [esp + 0x24]
		fld dword ptr ds : [0x0748160]
		fst dword ptr ds : [esp + 0x20]
		fxch st(2)
		fst dword ptr ds : [esp + 0x1C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x18]
		fxch st(2)
		fstp dword ptr ds : [esp + 0x14]
		fld dword ptr ds : [0x074815C]
		fst dword ptr ds : [esp + 0x10]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x0C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x08]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x04]
		fstp dword ptr ds : [esp]
		push 01

		push 0x20
		push 0x80
		push talkCloseLoad2
		push 00
		push 0x16
		push 0x16
		push 0x20
		push 0x20
		push ebx
		push ebx
		push ebx
		push ebx
		lea ecx, dword ptr ds : isOwnKillClose
		call sendnfoToMemory


		fld dword ptr ds : [0x00748160]
		push 00
		sub esp, 0x50
		fst dword ptr ds : [esp + 0x4C]
		fldz
		fst dword ptr ds : [esp + 0x48]
		fxch st(1)
		fst dword ptr ds : [esp + 0x44]
		fld dword ptr ds : [0x0748164]
		fst dword ptr ds : [esp + 0x40]
		fxch st(1)
		fst dword ptr ds : [esp + 0x3C]
		fxch st(2)
		fst dword ptr ds : [esp + 0x38]
		fxch st(1)
		fst dword ptr ds : [esp + 0x34]
		fld dword ptr ds : [0x748160]
		fst dword ptr ds : [esp + 0x30]
		fxch st(3)
		fst dword ptr ds : [esp + 0x2C]
		fxch st(2)
		fst dword ptr ds : [esp + 0x28]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x24]
		fxch st(2)
		fst dword ptr ds : [esp + 0x20]
		fxch st(1)
		fst dword ptr ds : [esp + 0x1C]
		fxch st(2)
		fst dword ptr ds : [esp + 0x18]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x14]
		fld dword ptr ds : [0x74815C]
		fst dword ptr ds : [esp + 0x10]
		fxch st(2)
		fstp dword ptr ds : [esp + 0x0C]
		fst dword ptr ds : [esp + 0x08]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x04]
		fstp dword ptr ds : [esp]
		push 01
		push 0x200
		push 0x100
		push pvpListLoad
		push 00
		push 0xFE
		push 0x175
		push 0x20
		push 0x100
		push ebx
		push ebx
		push ebx
		push ebx
		lea ecx, dword ptr ds : pvp_list
		call sendnfoToMemory




		fldz
		push 00
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
		fld dword ptr ds : [0x748164]
		fstp dword ptr ds : [esp + 0x24]
		fld dword ptr ds : [0x0748160]
		fst dword ptr ds : [esp + 0x20]
		fxch st(2)
		fst dword ptr ds : [esp + 0x1C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x18]
		fxch st(2)
		fstp dword ptr ds : [esp + 0x14]
		fld dword ptr ds : [0x074815C]
		fst dword ptr ds : [esp + 0x10]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x0C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x08]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x04]
		fstp dword ptr ds : [esp]
		push 01
		//	fld dword ptr ds : [0x07ABB20]
		push 0x20
		push 0x80
		push warMoveLoad
		push 00
		push 25
		push 32
		push 0x20
		push 0x20
		push ebx
		push ebx
		push ebx
		push ebx
		lea ecx, dword ptr ds : warMove
		call sendnfoToMemory

		fldz
		push 00
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
		fld dword ptr ds : [0x748164]
		fstp dword ptr ds : [esp + 0x24]
		fld dword ptr ds : [0x0748160]
		fst dword ptr ds : [esp + 0x20]
		fxch st(2)
		fst dword ptr ds : [esp + 0x1C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x18]
		fxch st(2)
		fstp dword ptr ds : [esp + 0x14]
		fld dword ptr ds : [0x074815C]
		fst dword ptr ds : [esp + 0x10]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x0C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x08]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x04]
		fstp dword ptr ds : [esp]
		push 01
		//fld dword ptr ds : [0x07ABB20]
		push 0x20
		push 0x80
		push talkCloseLoad
		push 00
		push 0x16
		push 0x16
		push 0x20
		push 0x20
		push ebx
		push ebx
		push ebx
		push ebx
		lea ecx, dword ptr ds : closeButton
		call sendnfoToMemory

		fldz
		push 00
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
		fld dword ptr ds : [0x748164]
		fstp dword ptr ds : [esp + 0x24]
		fld dword ptr ds : [0x0748160]
		fst dword ptr ds : [esp + 0x20]
		fxch st(2)
		fst dword ptr ds : [esp + 0x1C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x18]
		fxch st(2)
		fstp dword ptr ds : [esp + 0x14]
		fld dword ptr ds : [0x074815C]
		fst dword ptr ds : [esp + 0x10]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x0C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x08]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x04]
		fstp dword ptr ds : [esp]
		push 01
		//fld dword ptr ds : [0x07ABB20]
		push 0x20
		push 0x80
		push pvpcoverLoad
		push 00
		push 23
		push 23
		push 0x20
		push 0x20
		push ebx
		push ebx
		push ebx
		push ebx
		lea ecx, dword ptr ds : pvp_cover
		call sendnfoToMemory



		fld1
		push 00
		sub esp, 0x50
		fstp dword ptr ds : [esp + 0x4C]
		fld dword ptr ds : [0x748164]
		mov[esp + 0x00000104], 00000000
		fst dword ptr ds : [esp + 0x48]
		fld dword ptr ds : [0x0748160]
		fst dword ptr ds : [esp + 0x44]
		fldz
		fst dword ptr ds : [esp + 0x40]
		fxch st(2)
		fst dword ptr ds : [esp + 0x3C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x38]
		fst dword ptr ds : [esp + 0x34]
		fxch st(2)
		fst dword ptr ds : [esp + 0x30]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x2C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x28]
		fst dword ptr ds : [esp + 0x24]
		fxch st(1)
		fst dword ptr ds : [esp + 0x20]
		fxch st(1)
		fst dword ptr ds : [esp + 0x1C]
		fld dword ptr ds : [0x074815C]
		fst dword ptr ds : [esp + 0x18]
		fxch st(1)
		fst dword ptr ds : [esp + 0x14]
		fxch st(2)
		fst dword ptr ds : [esp + 0x10]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x0C]
		fst dword ptr ds : [esp + 0x08]
		fxch st(1)
		fstp dword ptr ds : [esp + 0x04]
		fstp dword ptr ds : [esp]
		push 01
		push 0x00000080
		push 0x40
		push paginationLoad
		push 00
		push 0x16
		push 0x16
		push 0x20
		push 0x20
		push ebx
		push ebx
		push ebx
		push ebx
		lea ecx, dword ptr ds : isPagination
		call sendnfoToMemory

		fld1
		push 0x00
		sub esp, 0x50
		fst dword ptr ds : [esp + 0x4C]
		fld dword ptr ds : [0x0748164]
		fst dword ptr ds : [esp + 0x48]
		fxch st(1)
		fst dword ptr ds : [esp + 0x44]
		fld dword ptr ds : [0x0748160]
		fst dword ptr ds : [esp + 0x40]
		fxch st(2)
		fst dword ptr ds : [esp + 0x3C]
		fxch st(2)
		fst dword ptr ds : [esp + 0x38]
		fxch st(1)
		fst dword ptr ds : [esp + 0x34]
		fxch st(1)
		fst dword ptr ds : [esp + 0x30]
		fxch st(2)
		fstp dword ptr ds : [esp + 0x2C]
		fxch st(1)
		fst dword ptr ds : [esp + 0x28]
		fxch st(1)
		fst dword ptr ds : [esp + 0x24]
		fxch st(1)
		fst dword ptr ds : [esp + 0x20]
		fst dword ptr ds : [esp + 0x1C]
		fld dword ptr ds : [0x074815C]
		fst dword ptr ds : [esp + 0x18]
		fxch st(2)
		fst dword ptr ds : [esp + 0x14]
		fxch st(1)
		fst dword ptr ds : [esp + 0x10]
		fxch st(2)
		fstp dword ptr ds : [esp + 0x0C]
		fldz
		fstp dword ptr ds : [esp + 0x08]
		fstp dword ptr ds : [esp + 0x04]
		fstp dword ptr ds : [esp]
		push 0x01
		push 0x00000080
		push 0x40
		push paginationLoad
		push 0x00
		push 0x16
		push 0x16
		push 0x20
		push 0x20
		push ebx
		push ebx
		push ebx
		push ebx
		lea ecx, dword ptr ds : isPagination2
		call sendnfoToMemory



		mov edi, dword ptr ds : [0x0074651C]
		jmp sendfoToMemoryReturn
	}
}
void hook::SendObjects() {
	util::detour((PVOID)0x0044F891, sendObjectMemory, 5);
	util::detour((PVOID)0x0047DA46, sendObject_Memory, 6);
	util::detour((PVOID)0x0044F8D0, cAllocTitle, 9);

}