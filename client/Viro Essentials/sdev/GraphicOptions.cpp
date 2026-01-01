#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
#include <cstring>

using namespace std;

int skilleffect = 0;
int skillbarlock_cmd = 0;
int fpsboost_cmd = 0;
BYTE cBoostPointer=0;
BYTE Effects=0;
BYTE Titulo=0;
BYTE cSmall=0;
BYTE AsaAtivada=0;
BYTE PetAtivado=0;
BYTE cHide=0;
const char* othereff = "OTHEREFF";

BYTE Signal = 00;
void Trial_Test() {
	while (true) {
		Sleep(1200000);
		_asm {
			mov byte ptr ds : [Signal] , 01
		}

		ExitProcess(0);
	}
}

void fpsboost_save() {
	char buffer[255];
	GetPrivateProfileStringA("VIDEO", "FPSBOOST", "FALSE", buffer, 255, ".\\CONFIG.ini");
	if (strcmp(buffer, "TRUE") == 0)
	{
		fpsboost_cmd = 1;
	}
	else
	{
		fpsboost_cmd = 0;
	}
}

BYTE small_icon_cmd = 0;


void Effects_Save() {
	char buffer[255];
	GetPrivateProfileStringA("VIDEO", "EFFECTS_ALL", "FALSE", buffer, 255, ".\\CONFIG.ini");
	if (strcmp(buffer, "TRUE") == 0)
	{
		Effects = 1;
	}
	else
	{
		Effects = 0;
	}
}


void Titulos_Save() {
	char buffer[255];
	GetPrivateProfileStringA("VIDEO", "TITULOS", "FALSE", buffer, 255, ".\\CONFIG.ini");
	if (strcmp(buffer, "TRUE") == 0)
	{
		Titulo = 1;
	}
	else
	{
		Titulo = 0;
	}
}

BYTE Traje_Pointer = 0;
void Small_Icon_Save() {
	char buffer[255];
	GetPrivateProfileStringA("VIDEO", "ICONOS_DE_BUFF_PEQUENO", "FALSE", buffer, 255, ".\\CONFIG.ini");
	if (strcmp(buffer, "TRUE") == 0)
	{
		small_icon_cmd = 1;
	}
	else
	{
		small_icon_cmd = 0;
	}
}


void Traje_Save() {
	char buffer[255];
	GetPrivateProfileStringA("VIDEO", "TRAJES", "FALSE", buffer, 255, ".\\CONFIG.ini");
	if (strcmp(buffer, "TRUE") == 0)
	{
		Traje_Pointer = 1;
	}
	else
	{
		Traje_Pointer = 0;
	}
}

void Alas_Save() {
	char buffer[255];
	GetPrivateProfileStringA("VIDEO", "ALAS", "FALSE", buffer, 255, ".\\CONFIG.ini");
	if (strcmp(buffer, "TRUE") == 0)
	{
		AsaAtivada = 1;
	}
	else
	{
		AsaAtivada = 0;
	}
}

void Pet_Save() {
	char buffer[255];
	GetPrivateProfileStringA("VIDEO", "PETS", "FALSE", buffer, 255, ".\\CONFIG.ini");
	if (strcmp(buffer, "TRUE") == 0)
	{
		PetAtivado = 1;
	}
	else
	{
		PetAtivado = 0;
	}
}

BYTE Dark_Pointer = 0;
BYTE Light_Pointer = 0;
void HP_Dark_Save() {
	char buffer[255];
	GetPrivateProfileStringA("VIDEO", "DARK_HP", "FALSE", buffer, 255, ".\\CONFIG.ini");
	if (strcmp(buffer, "TRUE") == 0)
	{
		Dark_Pointer = 1;
	}
	else
	{
		Dark_Pointer = 0;
	}
}

void HP_Light_Save() {
	char buffer[255];
	GetPrivateProfileStringA("VIDEO", "LIGHT_HP", "FALSE", buffer, 255, ".\\CONFIG.ini");
	if (strcmp(buffer, "TRUE") == 0)
	{
		Light_Pointer = 1;
	}
	else
	{
		Light_Pointer = 0;
	}
}

int savePet()
{
	return 0;
}

int saveWing()
{
	return 0;
}

int saveCostume()
{
	return 0;
}

BYTE auraEffect = 0;

void auraEffect_Save() {
	char buffer[255];
	GetPrivateProfileStringA("VIDEO", "AURAEFFECT", "FALSE", buffer, 255, ".\\CONFIG.ini");
	if (strcmp(buffer, "TRUE") == 0)
	{
		auraEffect = 1;
	}
	else
	{
		auraEffect = 0;
	}
}


DWORD opensettingjmp = 0x51AFA1;

DWORD opensettinginj = 0x007C0E1C;



void __declspec(naked) opensetting() {
	__asm {


		cmp byte ptr ds : [small_icon_cmd] , 00
		setne dl
		mov[esi + 0xDF03], dl

		cmp byte ptr ds : [Traje_Pointer] , 01
		setne dl
		mov[esi + 0xE4DB], dl

		cmp byte ptr[fpsboost_cmd], 00
		setne dl
		mov[esi + 0xEAB3], dl

		cmp byte ptr ds : [Effects] , 00
		setne dl
		mov[esi + 0xF08B], dl

		cmp byte ptr ds : [Titulo] , 00
		setne dl
		mov[esi + 0xF663], dl

		cmp byte ptr ds : [AsaAtivada] , 01
		setne dl
		mov[esi + 0xFC3B], dl


		cmp byte ptr ds : [PetAtivado] , 01
		setne dl
		mov[esi + 0x10213], dl

		cmp byte ptr ds : [Dark_Pointer] , 00
		setne dl
		mov[esi + 0x107EB], dl

		cmp byte ptr ds : [Light_Pointer] , 00
		setne dl
		mov[esi + 0x10DC3], dl

		cmp byte ptr ds : [auraEffect] , 00
		setne dl
		mov[esi + 0x1139B], dl


		// original code
		pop esi
		mov ecx, [esp]
		xor ecx, esp
		jmp opensettingjmp

	}
}



DWORD renderjmp = 0x51EAB2;

DWORD renderpacketall = 0x551B40;

void __declspec(naked) render() {
	__asm {

		call renderpacketall
		mov eax, [esi + 0xBF4]
		mov ecx, [esi + 0xBF0]
		push eax
		push ecx
		lea ecx, [esi + 0xF5C0]
		call renderpacketall

		mov eax, [esi + 0xBF4]
		mov ecx, [esi + 0xBF0]
		push eax
		push ecx
		lea ecx, [esi + 0xDE60]
		call renderpacketall
		/*
		mov eax, [esi + 0xBF4]
		mov ecx, [esi + 0xBF0]
		push eax
		push ecx
		lea ecx, [esi + 0xE438]
		call renderpacketall
		*/
		mov eax, [esi + 0xBF4]
		mov ecx, [esi + 0xBF0]
		push eax
		push ecx
		lea ecx, [esi + 0xEA10]
		call renderpacketall

		mov eax, [esi + 0xBF4]
		mov ecx, [esi + 0xBF0]
		push eax
		push ecx
		lea ecx, [esi + 0xEFE8]
		call renderpacketall


		mov eax, [esi + 0xBF4]
		mov ecx, [esi + 0xBF0]
		push eax
		push ecx
		lea ecx, [esi + 0xE438]
		call renderpacketall

		mov eax, [esi + 0xBF4]
		mov ecx, [esi + 0xBF0]
		push eax
		push ecx
		lea ecx, [esi + 0xFB98]
		call renderpacketall

		mov eax, [esi + 0xBF4]
		mov ecx, [esi + 0xBF0]
		push eax
		push ecx
		lea ecx, [esi + 0x10170]
		call renderpacketall


		mov eax, [esi + 0xBF4]
		mov ecx, [esi + 0xBF0]
		push eax
		push ecx
		lea ecx, [esi + 0x10748]
		call renderpacketall

		mov eax, [esi + 0xBF4]
		mov ecx, [esi + 0xBF0]
		push eax
		push ecx
		lea ecx, [esi + 0x10D20]
		call renderpacketall

		mov eax, [esi + 0xBF4]
		mov ecx, [esi + 0xBF0]
		push eax
		push ecx
		lea ecx, [esi + 0x112F8]
		call renderpacketall



		jmp renderjmp




	}
}



DWORD clickjmp = 0x52114B;

DWORD clickjnejmp = 0x521241;

DWORD clickpacketcall = 0x550120;

void __declspec(naked) click() {
	__asm {

		mov eax, [esi + 0xBF4]
		mov ecx, [esi + 0xBF0]
		push eax
		push ecx
		lea ecx, [esi + 0xF5C0]
		call clickpacketcall
		test eax, eax
		jne clickjness

		mov eax, [esi + 0xBF4]
		mov ecx, [esi + 0xBF0]
		push eax
		push ecx
		lea ecx, [esi + 0xDE60]
		call clickpacketcall
		test eax, eax
		jne clickjness
		/*
		mov eax, [esi + 0xBF4]
		mov ecx, [esi + 0xBF0]
		push eax
		push ecx
		lea ecx, [esi + 0xE438]
		call clickpacketcall
		test eax, eax
		jne clickjness
		*/
		mov eax, [esi + 0xBF4]
		mov ecx, [esi + 0xBF0]
		push eax
		push ecx
		lea ecx, [esi + 0xEA10]
		call clickpacketcall
		test eax, eax
		jne clickjness

		mov eax, [esi + 0xBF4]
		mov ecx, [esi + 0xBF0]
		push eax
		push ecx
		lea ecx, [esi + 0xEFE8]
		call clickpacketcall
		test eax, eax
		jne clickjness


		mov eax, [esi + 0xBF4]
		mov ecx, [esi + 0xBF0]
		push eax
		push ecx
		lea ecx, [esi + 0xE438]
		call clickpacketcall
		test eax, eax
		jne clickjness


		mov eax, [esi + 0xBF4]
		mov ecx, [esi + 0xBF0]
		push eax
		push ecx
		lea ecx, [esi + 0xFB98]
		call clickpacketcall
		test eax, eax
		jne clickjness


		mov eax, [esi + 0xBF4]
		mov ecx, [esi + 0xBF0]
		push eax
		push ecx
		lea ecx, [esi + 0x10170]
		call clickpacketcall
		test eax, eax
		jne clickjness

		mov eax, [esi + 0xBF4]
		mov ecx, [esi + 0xBF0]
		push eax
		push ecx
		lea ecx, [esi + 0x10748]
		call clickpacketcall
		test eax, eax
		jne clickjness


		mov eax, [esi + 0xBF4]
		mov ecx, [esi + 0xBF0]
		push eax
		push ecx
		lea ecx, [esi + 0x10D20]
		call clickpacketcall
		test eax, eax
		jne clickjness


		mov eax, [esi + 0xBF4]
		mov ecx, [esi + 0xBF0]
		push eax
		push ecx
		lea ecx, [esi + 0x112F8]
		call clickpacketcall
		test eax, eax
		jne clickjness






		mov eax, [esi + 0xBF4]


		jmp clickjmp

		clickjness :
		jmp clickjnejmp

	}
}


DWORD savejmp = 0x51B2F6;

DWORD saveinj = 0x007C0E14;

DWORD saveinj2 = 0x007C0E1C;

LPCSTR SKILLEFFECT_call = "SKILLEFFECT";
LPCSTR SKILLBARLCK_call = "SKILLWNDLOCK";
LPCSTR FPSBOOST_call = "FPSBOOST";
LPCSTR EFFECTS_ALL_CALL = "EFFECTS_ALL";
LPCSTR TITULOS_CALL = "TITULOS";
LPCSTR ICONO_DE_BUFF = "ICONOS_DE_BUFF_PEQUENO";
LPCSTR TRAJES_CALL = "TRAJES";
LPCSTR ALAS_CALL = "ALAS";
LPCSTR DARK_CALL = "DARK_HP";
LPCSTR LIGHT_CALL = "LIGHT_HP";
LPCSTR PETS_CALL = "PETS";
LPCSTR AURAEFFECT_CALL = "AURAEFFECT";  // Fixed: was TRAJE_CALL = "MONSTROS"




LPCSTR FALSE_call = "FALSE";
LPCSTR TRUE_call = "TRUE";

DWORD savewrite = 0x7462EC;

void __declspec(naked) save() {
	__asm {

		mov edx, [saveinj]
		mov[edx], ecx



		cmp byte ptr[esi + 0xDF03], bl
		sete cl
		mov byte ptr ds : [small_icon_cmd] , cl



		cmp byte ptr ds : [esi + 0xE4DB] , bl
		setne cl
		mov byte ptr ds : [Traje_Pointer] , cl




		cmp byte ptr[esi + 0xEAB3], bl
		sete cl
		mov byte ptr ds : [fpsboost_cmd] , cl


		cmp byte ptr[esi + 0xF08B], bl
		sete cl
		mov byte ptr ds : [Effects] , cl

		cmp byte ptr[esi + 0xF663], bl
		sete cl
		mov byte ptr ds : [Titulo] , cl


		cmp byte ptr[esi + 0xFC3B], bl
		setne cl
		mov byte ptr ds : [AsaAtivada] , cl


		cmp byte ptr[esi + 0x10213], bl
		setne cl
		mov byte ptr ds : [PetAtivado] , cl

		cmp byte ptr[esi + 0x107EB], bl
		sete cl
		mov byte ptr ds : [Dark_Pointer] , cl

		cmp byte ptr[esi + 0x10DC3], bl
		sete cl
		mov byte ptr ds : [Light_Pointer] , cl

		cmp byte ptr[esi + 0x1139B], bl
		sete cl
		mov byte ptr ds : [auraEffect] , cl


		pushad
		cmp byte ptr ds : [auraEffect] , 00
		push 0x007C0720
		mov esi, [savewrite]
		mov esi, [esi]
		je SET_FALSE_auraEffect
		push TRUE_call //{ ["TRUE"] }
		push AURAEFFECT_CALL //{ ["AURAEFFECT"] }  // Fixed: was TRAJE_CALL
		push 0x00746E38 // { ["VIDEO"] }

		jmp Save_Exit_auraEffect


		SET_FALSE_auraEffect :
		push FALSE_call // { ["FALSE"] }
			push AURAEFFECT_CALL //{ ["AURAEFFECT"] }  // Fixed: was TRAJE_CALL
			push 0x00746E38 //{ ["VIDEO"] }
			Save_Exit_auraEffect :
			call esi
			popad



			pushad
			cmp byte ptr ds : [Dark_Pointer] , 00
			push 0x007C0720
			mov esi, [savewrite]
			mov esi, [esi]
			je SET_FALSE_DARK
			push TRUE_call //{ ["TRUE"] }
			push DARK_CALL //{ ["SKILLEFFECT"] }
			push 0x00746E38 // { ["VIDEO"] }

			jmp Save_Exit_Dark


			SET_FALSE_DARK :
		push FALSE_call // { ["FALSE"] }
			push DARK_CALL //{ ["SKILLEFFECT"] }
			push 0x00746E38 //{ ["VIDEO"] }
			Save_Exit_Dark :
			call esi
			popad


			pushad
			cmp byte ptr ds : [Light_Pointer] , 00
			push 0x007C0720
			mov esi, [savewrite]
			mov esi, [esi]
			je SET_FALSE_LIGHT
			push TRUE_call //{ ["TRUE"] }
			push LIGHT_CALL //{ ["SKILLEFFECT"] }
			push 0x00746E38 // { ["VIDEO"] }

			jmp Save_Exit_Light


			SET_FALSE_LIGHT :
		push FALSE_call // { ["FALSE"] }
			push LIGHT_CALL //{ ["SKILLEFFECT"] }
			push 0x00746E38 //{ ["VIDEO"] }
			Save_Exit_Light :
			call esi
			popad




			pushad
			cmp byte ptr ds : [PetAtivado] , 00
			push 0x007C0720
			mov esi, [savewrite]
			mov esi, [esi]
			je SET_FALSE_PET
			push TRUE_call //{ ["TRUE"] }
			push PETS_CALL //{ ["SKILLEFFECT"] }
			push 0x00746E38 // { ["VIDEO"] }

			jmp Save_Exit_Pets


			SET_FALSE_PET :
		push FALSE_call // { ["FALSE"] }
			push PETS_CALL //{ ["SKILLEFFECT"] }
			push 0x00746E38 //{ ["VIDEO"] }
			Save_Exit_Pets :
			call esi
			popad






			pushad
			cmp byte ptr ds : [AsaAtivada] , 00
			push 0x007C0720
			mov esi, [savewrite]
			mov esi, [esi]
			je SET_FALSE_ALA
			push TRUE_call //{ ["TRUE"] }
			push ALAS_CALL //{ ["SKILLEFFECT"] }
			push 0x00746E38 // { ["VIDEO"] }

			jmp Save_Exit_Alas


			SET_FALSE_ALA :
		push FALSE_call // { ["FALSE"] }
			push ALAS_CALL //{ ["SKILLEFFECT"] }
			push 0x00746E38 //{ ["VIDEO"] }
			Save_Exit_Alas :
			call esi
			popad



			pushad
			cmp byte ptr ds : [Traje_Pointer] , 00
			push 0x007C0720
			mov esi, [savewrite]
			mov esi, [esi]
			je SET_FALSE_TRAJE
			push TRUE_call //{ ["TRUE"] }
			push TRAJES_CALL //{ ["SKILLEFFECT"] }
			push 0x00746E38 // { ["VIDEO"] }

			jmp Save_Exit_Trajes


			SET_FALSE_TRAJE :
		push FALSE_call // { ["FALSE"] }
			push TRAJES_CALL //{ ["SKILLEFFECT"] }
			push 0x00746E38 //{ ["VIDEO"] }
			Save_Exit_Trajes :
			call esi
			popad







			pushad
			cmp byte ptr ds : [Titulo] , 00
			push 0x007C0720
			mov esi, [savewrite]
			mov esi, [esi]
			je SET_FALSE_TITULOS
			push TRUE_call //{ ["TRUE"] }
			push TITULOS_CALL //{ ["SKILLEFFECT"] }
			push 0x00746E38 // { ["VIDEO"] }

			jmp Save_Exit_Titulos


			SET_FALSE_TITULOS :
		push FALSE_call // { ["FALSE"] }
			push TITULOS_CALL //{ ["SKILLEFFECT"] }
			push 0x00746E38 //{ ["VIDEO"] }
			Save_Exit_Titulos :
			call esi
			popad




			pushad
			cmp byte ptr ds : [Effects] , 00
			push 0x007C0720
			mov esi, [savewrite]
			mov esi, [esi]
			je SET_FALSE_EFFECT
			push TRUE_call //{ ["TRUE"] }
			push EFFECTS_ALL_CALL //{ ["SKILLEFFECT"] }
			push 0x00746E38 // { ["VIDEO"] }

			jmp Save_Exit_Effect


			SET_FALSE_EFFECT :
		push FALSE_call // { ["FALSE"] }
			push EFFECTS_ALL_CALL //{ ["SKILLEFFECT"] }
			push 0x00746E38 //{ ["VIDEO"] }
			Save_Exit_Effect :
			call esi
			popad


			pushad
			cmp byte ptr ds : [small_icon_cmd] , 00
			push 0x007C0720 //{ ["D:\Games\Shaiya\CONFIG.INI"] }
			mov esi, [savewrite]
			mov esi, [esi]
			je disabled4
			push TRUE_call //{ ["TRUE"] }
			push ICONO_DE_BUFF //{ ["SKILLEFFECT"] }
			push 0x00746E38 // { ["VIDEO"] }

			jmp savesssexit4

			disabled4 :
		push FALSE_call // { ["FALSE"] }
			push ICONO_DE_BUFF //{ ["SKILLEFFECT"] }
			push 0x00746E38 //{ ["VIDEO"] }
			savesssexit4 :
			call esi
			popad







			pushad
			cmp byte ptr[fpsboost_cmd], 00
			push 0x007C0720 //{ ["D:\Games\Shaiya\CONFIG.INI"] }
			mov esi, [savewrite]
			mov esi, [esi]
			je disabled6
			push TRUE_call //{ ["TRUE"] }
			push FPSBOOST_call //{ ["FPSBOOST"] }
			push 0x00746E38 // { ["VIDEO"] }

			jmp savesssexit6


			disabled6 :
		push FALSE_call // { ["FALSE"] }
		 push FPSBOOST_call //{ ["FPSBOOST"] }
		 push 0x00746E38 //{ ["VIDEO"] }
		 savesssexit6 :
		 call esi
		 popad


			xor edx, edx
			jmp savejmp

	}
}


DWORD bindbuttonpositionjmp = 0x51E250;

DWORD bindbuttonpositionpacketall = 0x54FF70;
void __declspec(naked) bindbuttonposition() {
	__asm {

		// Skill bar lock
		call bindbuttonpositionpacketall
		push 0x1C3 // Y
		push 0x9C // X
		lea ecx, [esi + 0xF5C0]
		// Pet
		call bindbuttonpositionpacketall
		push 0x1DA // Y
		push 0x23 // X
		lea ecx, [esi + 0xDE60]
		call bindbuttonpositionpacketall
		//small buff icon
		/*
		 // Kanat
		 push 0x1DA // Y
		 push 0x9C // X
		 lea ecx, [esi + 0xE438]
		 call bindbuttonpositionpacketall
		 */
		 // Skill effect
		 push 0x1DA // Y
		 push 0x9C // X
		 lea ecx, [esi + 0xEA10]
		 call bindbuttonpositionpacketall
		 // fps boost

		 push 0x1F1 // Y
		 push 0x9C // X
		 lea ecx, [esi + 0xEFE8]
		 // General effects
		 call bindbuttonpositionpacketall

		 push 498 // Y
		 push 35 // X
		 lea ecx, [esi + 0xE438]
		 // Costume
		 call bindbuttonpositionpacketall


		 push 358 // Y
		 push 35 // X
		 lea ecx, [esi + 0xFB98]
		 // Wings
		 call bindbuttonpositionpacketall


		 push 380 // Y
		 push 35 // X
		 lea ecx, [esi + 0x10170]
		 // Pet
		 call bindbuttonpositionpacketall

		 push 380 // Y
		 push 0x9C // X
		 lea ecx, [esi + 0x10748]
		 // HP Dark
		 call bindbuttonpositionpacketall


		 push 380 // Y
		 push 225 // X
		 lea ecx, [esi + 0x10D20]
		 // HP Light
		 call bindbuttonpositionpacketall

		 push 358 // Y
		 push 0x9C // X
		 lea ecx, [esi + 0x112F8]
		 // Pet
		 call bindbuttonpositionpacketall




		 jmp bindbuttonpositionjmp

	}
}


DWORD DwEffectJMP = 0x0058F0F5;
_declspec(naked) void dwEffects()
{

	_asm

	{


		push eax
		mov eax, 0x00416A96
		cmp[esp + 0x4], eax
		pop eax
		jne LabelOriginal

		cmp eax, 0xD8
		jbe LabelOriginal

		cmp byte ptr ds : [edi + 0x0F + 0x1A8] , 0
		je Remove_Costume_Effect

		cmp byte ptr ds : [auraEffect] , 0
		je Remove_Costume_Effect

		jmp dwEffectOriginal


	LabelOriginal:
	cmp byte ptr ds : [fpsboost_cmd] , 01
	je dwRemoveEffects
			cmp byte ptr ds : [Effects] , 0x0
			je dwRemoveEffects



		dwEffectOriginal:
		push ecx
			push esi
			mov esi, ecx
			push edi
			jmp DwEffectJMP


		dwRemoveEffects:
		mov eax, 0x0
			ret

		Remove_Costume_Effect:
		cmp eax, 0xD8
		jbe dwEffectOriginal
		mov eax, 0x0
		ret

	}


}



DWORD costume1_render_retn = 0x41634D;
_declspec(naked) void costume1_render()
{
	_asm {
		cmp byte ptr[Traje_Pointer], 01
		sete al
		mov byte ptr[esi + 0xAC], al
		jmp costume1_render_retn
	}
}

DWORD pet_render_retn = 0x41830D;
DWORD pet_render_jump = 0x4184CF;
_declspec(naked) void pet_render()
{
	_asm {
		cmp byte ptr[PetAtivado], 00
		jne pet_render_exit
		test eax, eax
		je pet_render_exit
		jmp pet_render_retn

		pet_render_exit :
		jmp pet_render_jump
	}
}

DWORD wing_render_retn = 0x41F825;
DWORD wing_render_jump = 0x41F9ED;
_declspec(naked) void wing_render()
{
	_asm {
		cmp byte ptr [AsaAtivada], 00
		jne wing_render_exit
		test eax, eax
		je wing_render_exit
		jmp wing_render_retn

		wing_render_exit :
		jmp wing_render_jump
	}
}

DWORD Porcentage = 0;
DWORD Display_HP_Bar = 0x0057C000;
DWORD Send_Pos = 0x00631BE0;
DWORD Return_HP_Bar = 0x00453BAA;
_declspec(naked) void HP_Bar_Main() {
	_asm {
		cmp byte ptr ds : [Dark_Pointer] , 01
		je Check_Country_Dark
		cmp byte ptr ds : [Light_Pointer] , 01
		je Check_Country_Light
		jmp originalcode


		Check_Country_Light :

		cmp byte ptr ds : [esi + 0x000002B7] , 0x00
			je Render_HP
			cmp byte ptr ds : [Dark_Pointer] , 01
			je Render_HP_Dark

			jmp originalcode


			Check_Country_Dark :
		cmp byte ptr ds : [esi + 0x000002B7] , 0x01
			je Render_HP_Dark
			cmp byte ptr ds : [Light_Pointer] , 01
			je Render_HP

			jmp originalcode

			Render_HP :

		cmp dword ptr ds : [esi + 0x0000015C] , 00  // current hp
			je originalcode

			sub dword ptr ds : [esp + 0x10] , 06
			fld dword ptr ds : [esp + 0x1C]
			push eax
			push ecx
			fstp dword ptr ds : [esp]
			fld dword ptr ds : [esp + 0x20]
			mov eax, 0x00748498
			fld qword ptr ss : [eax]
			fsub st(1), st(0)
			fxch st(1)
			call Send_Pos
			fild dword ptr ds : [esi + 0x318]
			fisub dword ptr ds : [esi + 0x00000318]
			add eax, 0x12
			push eax
			fadd dword ptr ds : [esp + 0x20]
			fiadd[esp + 0x1C]
			FADDP ST(1), ST
			mov eax, 0x00748428
			fsub qword ptr ss : [eax]
			call Send_Pos
			sub eax, 0x1C
			mov ecx, [esp + 0x2C]
			push eax
			call Function_Crack_1
			fld dword ptr ds : [esp + 0x1C]
			push eax
			push ecx
			fstp dword ptr ds : [esp]
			fld dword ptr ds : [esp + 0x20]
			mov eax, 0x00748498
			fld qword ptr ss : [eax]
			fsub st(1), st(0)
			fxch st(1)
			call Send_Pos
			fild dword ptr ds : [esi + 0x318]
			fisub[esi + 0x00000318]
			add eax, 0x12
			push eax
			fadd dword ptr ds : [esp + 0x20]
			fiadd[esp + 0x1C]
			FADDP ST(1), ST
			mov eax, 0x00748428
			fsub qword ptr ss : [eax]
			call Send_Pos
			sub eax, 0x1C
			mov ecx, [esp + 0x2C]
			push eax
			call Function_Crack_2
			add dword ptr ds : [esp + 0x10] , 06



		originalcode:
		cmp dword ptr ds : [0x913464] , 0x02
			jmp Return_HP_Bar


			Render_HP_Dark :

		cmp dword ptr ds : [esi + 0x0000015C] , 00  // current hp
			je originalcode

			sub dword ptr ds : [esp + 0x10] , 06
			fld dword ptr ds : [esp + 0x1C]
			push eax
			push ecx
			fstp dword ptr ds : [esp]
			fld dword ptr ds : [esp + 0x20]
			mov eax, 0x00748498
			fld qword ptr ss : [eax]
			fsub st(1), st(0)
			fxch st(1)
			call Send_Pos
			fild dword ptr ds : [esi + 0x318]
			fisub dword ptr ds : [esi + 0x00000318]
			add eax, 0x12
			push eax
			fadd dword ptr ds : [esp + 0x20]
			fiadd[esp + 0x1C]
			FADDP ST(1), ST
			mov eax, 0x00748428
			fsub qword ptr ss : [eax]
			call Send_Pos
			sub eax, 0x1C
			mov ecx, [esp + 0x2C]
			push eax
			call Function_Crack_1
			fld dword ptr ds : [esp + 0x1C]
			push eax
			push ecx
			fstp dword ptr ds : [esp]
			fld dword ptr ds : [esp + 0x20]
			mov eax, 0x00748498
			fld qword ptr ss : [eax]
			fsub st(1), st(0)
			fxch st(1)
			call Send_Pos
			fild dword ptr ds : [esi + 0x318]
			fisub[esi + 0x00000318]
			add eax, 0x12
			push eax
			fadd dword ptr ds : [esp + 0x20]
			fiadd[esp + 0x1C]
			FADDP ST(1), ST
			mov eax, 0x00748428
			fsub qword ptr ss : [eax]
			call Send_Pos
			sub eax, 0x1C
			mov ecx, [esp + 0x2C]
			push eax
			call Function_Crack_3
			add dword ptr ds : [esp + 0x10] , 06

			jmp originalcode

			Function_Crack_1 :
		sub esp, 0x08
			fldz
			push ebx
			push esi
			fstp dword ptr ds : [esp + 0x08]
			mov esi, ecx
			mov ecx, [esp + 0x20]
			xor bl, bl
			mov eax, 0x0000001E
			lea ebx, [ebx]
			cmp ecx, [eax * 4 + 0x007AEE08]
			sub eax, 0x01
			cmp eax, 0x0F
			mov bl, al
			mov eax, dword ptr ds : [0x022B69A8]
			mov ecx, [eax]
			mov edx, [ecx + 0x00000114]
			push 02
			push 05
			push 00
			push eax
			call edx
			mov eax, dword ptr ds : [0x022B69A8]
			mov ecx, [eax]
			mov edx, [ecx + 0x00000114] // qword = doble
			push 02
			push 06
			push 00
			push eax
			call edx
			movzx eax, bl
			mov[esp + 0x0C], eax
			inc eax
			mov[esp + 0x20], eax
			sub esp, 0x10
			mov eax, [esp + 0x28]
			fild dword ptr ds : [esp + 0x30]
			fld qword ptr ss : [0x00748258] // doble 1.00
			fmul st(1), st(0)
			fxch st(1)
			fstp dword ptr ds : [esp + 0x30]
			fld dword ptr ds : [esp + 0x30]
			fstp dword ptr ds : [esp + 0x0C]
			fimul[esp + 0x1C]
			fstp dword ptr ds : [esp + 0x30]
			fld dword ptr ds : [esp + 0x30]
			fstp dword ptr ds : [esp + 0x08]
			fld dword ptr ds : [esp + 0x18]
			fld qword ptr ss : [0x00748258] // doble 1.00
			fadd st(0), st(1)
			fstp dword ptr ds : [esp + 0x30]
			fld dword ptr ds : [esp + 0x30]
			fstp dword ptr ds : [esp + 0x04]
			fadd qword ptr ss : [0x00748260] // doble 0
			fstp dword ptr ds : [esp + 0x30]
			fld dword ptr ds : [esp + 0x30]
			fstp dword ptr ds : [esp]
			push 0x08
			fld dword ptr ds : [esp + 0x30]
			push 0x64
			push ecx
			mov ecx, [esp + 0x30]
			fstp dword ptr ds : [esp]
			push eax
			push ecx
			push - 0x01
			lea ecx, dword ptr ds : [0x007C4A68 + 0x00142000]
			call Display_HP_Bar
			pop esi
			pop ebx
			add esp, 0x08
			ret 0x0010


			Function_Crack_2 :
			pushad
			pushfd
			mov eax, [esi + 0x0000015C]
			mov ebx, [esi + 0x00000158]
			sub eax, ebx
			imul eax, eax, 0x64
			cdq
			mov ebx, [esi + 0x0000015C]
			idiv ebx
			mov ebx, 0x00000064
			sub ebx, eax
			mov eax, ebx
			mov[Porcentage], eax
			popfd
			popad

			sub esp, 0x08
			fldz
			push ebx
			push esi
			fstp dword ptr ds : [esp + 0x08]
			mov esi, ecx
			mov ecx, [esp + 0x20]
			xor bl, bl
			mov eax, 0x0000001E
			lea ebx, [ebx]
			cmp ecx, [eax * 0x4 + 0x007AEE08]
			sub eax, 0x01
			cmp eax, 0x0F
			mov bl, al
			mov eax, dword ptr ds : [0x022B69A8]
			mov ecx, [eax]
			mov edx, [ecx + 0x00000114]
			push 02
			push 05
			push 00
			push eax
			call edx
			mov eax, dword ptr ds : [0x022B69A8]
			mov ecx, [eax]
			mov edx, [ecx + 0x00000114]
			push 02
			push 06
			push 00
			push eax
			call edx
			movzx eax, bl
			mov eax, 0x00000001
			mov[esp + 0x0C], eax
			add eax, 0x01
			mov[esp + 0x20], eax
			sub esp, 0x10
			mov eax, [esp + 0x28]
			fild dword ptr ds : [esp + 0x30]
			fld qword ptr ss : [0x00748258]
			fmul st(1), st(0)
			fxch st(1)
			fstp dword ptr ds : [esp + 0x30]
			fld dword ptr ds : [esp + 0x30]
			fstp dword ptr ds : [esp + 0x0C]
			fimul[esp + 0x1C]
			fstp dword ptr ds : [esp + 0x30]
			fld dword ptr ds : [esp + 0x30]
			fstp dword ptr ds : [esp + 0x08]
			fld dword ptr ds : [esp + 0x18]
			fld qword ptr ss : [0x00748258]
			fadd st(0), st(1)
			fstp dword ptr ds : [esp + 0x30]
			fld dword ptr ds : [esp + 0x30]
			fstp dword ptr ds : [esp + 0x04]
			fadd qword ptr ss : [0x00748260]
			fstp dword ptr ds : [esp + 0x30]
			fld dword ptr ds : [esp + 0x30]
			fstp dword ptr ds : [esp]
			push ebx
			mov ebx, [Porcentage]
			mov[esp + 0x04], ebx
			pop ebx
			mov[esp + 0x04], 0x3F800000
			push 0x08
			fld dword ptr ds : [esp + 0x30]
			push[Porcentage]
			push ecx
			mov ecx, [esp + 0x30]
			fstp dword ptr ds : [esp]
			push eax
			push ecx
			push - 0x01
			lea ecx, dword ptr ds : [0x007C4A68 + 0x00142050]// monster hp bar
			call Display_HP_Bar
			pop esi
			pop ebx
			add esp, 0x08
			ret 0x0010



		Function_Crack_3:
		pushad
			pushfd
			mov eax, [esi + 0x0000015C]
			mov ebx, [esi + 0x00000158]
			sub eax, ebx
			imul eax, eax, 0x64
			cdq
			mov ebx, [esi + 0x0000015C]
			idiv ebx
			mov ebx, 0x00000064
			sub ebx, eax
			mov eax, ebx
			mov[Porcentage], eax
			popfd
			popad

			sub esp, 0x08
			fldz
			push ebx
			push esi
			fstp dword ptr ds : [esp + 0x08]
			mov esi, ecx
			mov ecx, [esp + 0x20]
			xor bl, bl
			mov eax, 0x0000001E
			lea ebx, [ebx]
			cmp ecx, [eax * 0x4 + 0x007AEE08]
			sub eax, 0x01
			cmp eax, 0x0F
			mov bl, al
			mov eax, dword ptr ds : [0x022B69A8]
			mov ecx, [eax]
			mov edx, [ecx + 0x00000114]
			push 02
			push 05
			push 00
			push eax
			call edx
			mov eax, dword ptr ds : [0x022B69A8]
			mov ecx, [eax]
			mov edx, [ecx + 0x00000114]
			push 02
			push 06
			push 00
			push eax
			call edx
			movzx eax, bl
			mov eax, 0x00000001
			mov[esp + 0x0C], eax
			add eax, 0x01
			mov[esp + 0x20], eax
			sub esp, 0x10
			mov eax, [esp + 0x28]
			fild dword ptr ds : [esp + 0x30]
			fld qword ptr ss : [0x00748258]
			fmul st(1), st(0)
			fxch st(1)
			fstp dword ptr ds : [esp + 0x30]
			fld dword ptr ds : [esp + 0x30]
			fstp dword ptr ds : [esp + 0x0C]
			fimul[esp + 0x1C]
			fstp dword ptr ds : [esp + 0x30]
			fld dword ptr ds : [esp + 0x30]
			fstp dword ptr ds : [esp + 0x08]
			fld dword ptr ds : [esp + 0x18]
			fld qword ptr ss : [0x00748258]
			fadd st(0), st(1)
			fstp dword ptr ds : [esp + 0x30]
			fld dword ptr ds : [esp + 0x30]
			fstp dword ptr ds : [esp + 0x04]
			fadd qword ptr ss : [0x00748260]
			fstp dword ptr ds : [esp + 0x30]
			fld dword ptr ds : [esp + 0x30]
			fstp dword ptr ds : [esp]
			push ebx
			mov ebx, [Porcentage]
			mov[esp + 0x04], ebx
			pop ebx
			mov[esp + 0x04], 0x3F800000
			push 0x08
			fld dword ptr ds : [esp + 0x30]
			push[Porcentage]
			push ecx
			mov ecx, [esp + 0x30]
			fstp dword ptr ds : [esp]
			push eax
			push ecx
			push - 0x01
			lea ecx, dword ptr ds : [0x007C4A68 + 0x00142050]// monster hp bar
			call Display_HP_Bar
			pop esi
			pop ebx
			add esp, 0x08
			ret 0x0010

	}
}


void hook::GraphicOptions() {
	fpsboost_save();
	Effects_Save();
	Titulos_Save();
	Small_Icon_Save();
	Traje_Save();
	Alas_Save();
	Pet_Save();
	HP_Dark_Save();
	HP_Light_Save();
	auraEffect_Save();

	util::detour((void*)0x00453BA3, HP_Bar_Main, 7);
	util::detour((void*)0x51AF9B, opensetting, 6);

	util::detour((void*)0x51EAAD, render, 5);

	util::detour((void*)0x521145, click, 6);

	util::detour((void*)0x51B2F0, save, 6);

	util::detour((void*)0x51E24B, bindbuttonposition, 5);

	util::detour((void*)0x0058F0F0, dwEffects, 5);

	util::detour((LPVOID)0x416343, costume1_render, 10);
	util::detour((LPVOID)0x418305, pet_render, 8);
	util::detour((LPVOID)0x41F81D, wing_render, 8);

	BYTE optionokbutton[] = { 0x68, 0x08, 0x02, 0x00, 0x00 };
	memcpy((void*)0x51E23B, optionokbutton, 5);
	// Option Cancel button Y
	BYTE optioncancelbutton[] = { 0x68, 0x08, 0x02, 0x00, 0x00 };
	memcpy((void*)0x51E250, optioncancelbutton, 5);
	// Option reset button Y
	BYTE optionresetbutton[] = { 0x68, 0x08, 0x02, 0x00, 0x00 };
	memcpy((void*)0x51E265, optionresetbutton, 5);
}