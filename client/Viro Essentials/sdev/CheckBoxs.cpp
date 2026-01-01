#include "include/main.h"
#include "util/util.h"
#include <pch.h>



using namespace std;
char registerPosChat_y[255];
char registerPosChat_x[255];
char esp_20[255];
char register_pos_y_2[255];
char register_pos_x_2[255];
char register_pos[255];
char pointer_true_false[255];
char get_value_helmet[255];
char get_value_pet[255];
char get_value_wing[255];
char get_value_costume[255];
char get_value_fpsboost[255];
char get_value_smallicon[255];
char get_value_effects[255];
char get_value_titles[255];
char get_value_aura[255];
char get_value_hplight[255];
char get_value_hpdark[255];
char get_value_feed[255];
char get_value_shiftbar[255];
BYTE isFeedEnable = 0;
BYTE isShiftEnable = 0;
std::string True = "TRUE";
void readConfigValue(const char* section, const char* key, char* buffer) {
	GetPrivateProfileStringA(section, key, "", buffer, 255, ".\\extraconfig.ini");
}

// Helper function to set the pointer values based on comparison
void setPointerValue(char* pointer, size_t offset, const char* value) {
	if (strcmp(value, True.c_str()) == 0) {
		pointer[offset] = 0x01;
	}
	else {
		pointer[offset] = 0x00;
	}
}

int get_value_pointer_true() {
	readConfigValue("CHECK_BOX", "HELMET", get_value_helmet);
	readConfigValue("CHECK_BOX", "PET", get_value_pet);
	readConfigValue("CHECK_BOX", "WING", get_value_wing);
	readConfigValue("CHECK_BOX", "COSTUME", get_value_costume);
	readConfigValue("CHECK_BOX", "FPS_BOOST", get_value_fpsboost);
	readConfigValue("CHECK_BOX", "SMALL_ICON", get_value_smallicon);
	readConfigValue("CHECK_BOX", "EFFECTS", get_value_effects);
	readConfigValue("CHECK_BOX", "TITLES", get_value_titles);
	readConfigValue("CHECK_BOX", "LIGHT_HP", get_value_hplight);
	readConfigValue("CHECK_BOX", "DARK_HP", get_value_hpdark);
	readConfigValue("CHECK_BOX", "AURA_EFFECT", get_value_aura);
	readConfigValue("CHECK_BOX", "KILL_FEED", get_value_feed);
	readConfigValue("CHECK_BOX", "SHIFT_BAR", get_value_shiftbar);

	setPointerValue(pointer_true_false, 0, get_value_helmet);
	setPointerValue(pointer_true_false, 4, get_value_pet);
	setPointerValue(pointer_true_false, 8, get_value_wing);
	setPointerValue(pointer_true_false, 12, get_value_costume);
	setPointerValue(pointerSystemEnabled, 0, get_value_fpsboost);
	setPointerValue(pointerSystemEnabled, 4, get_value_smallicon);
	setPointerValue(pointerSystemEnabled, 8, get_value_effects);
	setPointerValue(pointerSystemEnabled, 12, get_value_titles);
	setPointerValue(pointerSystemEnabled, 16, get_value_aura);
	setPointerValue(pointerSystemEnabled, 20, get_value_hplight);
	setPointerValue(pointerSystemEnabled, 24, get_value_hpdark);
	setPointerValue(pointerSystemEnabled, 28, get_value_feed);
	setPointerValue(pointerSystemEnabled, 32, get_value_shiftbar);
	PetAtivado = pointer_true_false[4];
	AsaAtivada = pointer_true_false[8];
	Traje_Pointer = pointer_true_false[12];
	cBoostPointer = pointerSystemEnabled[0];
	cSmall = pointerSystemEnabled[4];
	Effect = pointerSystemEnabled[8];
	Titulo = pointerSystemEnabled[12];
	Traje_Effect = pointerSystemEnabled[16];
	Light_Pointer = pointerSystemEnabled[20];
	Dark_Pointer = pointerSystemEnabled[24];
	isFeedEnable = pointerSystemEnabled[28];
	isShiftEnable = pointerSystemEnabled[32];
	return 0;
}

__declspec(dllexport) _declspec(naked) void isSave() {
	_asm {

       cmp edi,01
	   je pet_save
	   cmp edi,02
	   je wing_save
	   cmp edi,03
	   je costume_save
	   jmp return_

	    pet_save:
		mov al, [pointer_true_false + 0x4]
		mov byte ptr ds:[PetAtivado],al
		mov byte ptr ds:[globalPet],al
		push [globalPet]
		call savePet
		add esp,04
		jmp return_

		wing_save:
		mov al,[pointer_true_false + 0x8]
		mov byte ptr ds:[AsaAtivada],al
		mov byte ptr ds:[globalWing] ,al
		push [globalWing]
	    call saveWing
		add esp,04
		jmp return_

		costume_save:
		mov al, [pointer_true_false + 12]
		mov byte ptr ds: [globalCostume],al
		mov byte ptr ds: [Traje_Pointer],al
		push [globalCostume]
		call saveCostume
		add esp,04

		

		return_:
		xor eax, eax
		ret 0x008
	}
}




DWORD inv_open = 0;
DWORD pointer_inv_jmp_addr = 0x051ABB0;
DWORD pointer_inv_return = 0x0051A551;
__declspec(dllexport) _declspec(naked) void pointer_inv_open() {
	_asm {
		push eax
		mov eax, [esi + 0x20]
		mov dword ptr ds:[inv_open], eax
		pop eax
		cmp dword ptr ds:[esi + 0x20], 0x00
		je pointer_inv_jmp
		jmp pointer_inv_return
		pointer_inv_jmp:
		jmp pointer_inv_jmp_addr
	}
}

DWORD send_render = 0x0552520;
DWORD send_pos = 0x0631AB0;
DWORD render_check_box_inventory_return = 0x0051A5DE;
DWORD send_render_ = 0x5183F0;
__declspec(dllexport) _declspec(naked) void render_check_box_inventory() {
	_asm {
		cmp dword ptr ds:[esi+0x20],01
		jne originalcode
		pushad
		pushfd
		xor edi,edi
		start_loop:
		cmp edi,03
		jg end_loop
		lea eax, dword ptr ds:pointer_true_false
		cmp byte ptr ds:[edi*0x4+eax], 00
		jne render_inv_check
		jmp continue_
		render_inv_check:
		mov eax, [esi + 0x08]
		mov ecx, [esi + 0x04]
		add ecx, 0x47
		add eax, 0x3F
		mov dword ptr ds:[register_pos_x_2], ecx
		mov dword ptr ds:[register_pos_y_2], eax
		add ecx, 0x57
		mov dword ptr ds:[register_pos_x_2+0x04], ecx
		mov dword ptr ds:[register_pos_y_2+0x04], eax
		add eax, 0x19
		mov dword ptr ds:[register_pos_x_2+0x08], ecx
		mov dword ptr ds:[register_pos_y_2+0x08], eax
		add eax, 0x7B
		add ecx, 0x12
		mov dword ptr ds:[register_pos_x_2+0x0C], ecx
		mov dword ptr ds:[register_pos_y_2+0x0C], eax
		mov eax, dword ptr ds:[edi*0x4+register_pos_y_2]
		mov ecx, dword ptr ds:[edi*0x4+register_pos_x_2]
		push eax
		push ecx
		lea ecx,dword ptr ds:check_btn
		call isRenderObjectSingle
		continue_:
		inc edi
		jmp start_loop

		end_loop:
		popfd
		popad
		jmp originalcode_pop

		originalcode:
		mov ecx, esi
		call send_render_
		jmp render_check_box_inventory_return

		originalcode_pop:
		pushad
		mov eax, [esi + 0x08]
		mov ecx, [esi + 0x04]
		add ecx, 0x47
		add eax, 0x3F
		mov dword ptr ds:[register_pos_x_2], ecx
		mov dword ptr ds:[register_pos_y_2], eax
		add ecx, 0x57
		mov dword ptr ds:[register_pos_x_2+0x04], ecx
		mov dword ptr ds:[register_pos_y_2+0x04], eax
		add eax, 0x19
		mov dword ptr ds:[register_pos_x_2+0x08], ecx
		mov dword ptr ds:[register_pos_y_2+0x08], eax
		add eax, 0x7B
		add ecx, 0x12
		mov dword ptr ds:[register_pos_x_2 + 0x0C], ecx
		mov dword ptr ds:[register_pos_y_2 + 0x0C], eax
		popad
		jmp originalcode
	}
}
DWORD pointer_true = 0;
DWORD click_check_box_inventory_return = 0x0056440A;
__declspec(dllexport) _declspec(naked) void click_check_box_inventory() {
	_asm {
		cmp dword ptr ds:[inv_open], 01
		jne originalcode
		pushad
		pushfd
		mov ecx, dword ptr ds:[0x7C3C10]// y mouse
		mov edi, dword ptr ds:[0x7C3C0C]// x mouse
		mov ebp, dword ptr ds:[0x7AB0DC]// resolução
		cmp ecx, ebp
		jg pop_and_jmp
		xor edi, edi
		get_pos :
		mov edx, dword ptr ds:[edi*4+register_pos_x_2]
		lea eax, [edx]
		mov edx, dword ptr ds:[edi*4+register_pos_y_2]
		lea edx, [edx]
		mov dword ptr ds:[register_pos], edx
		mov edx, dword ptr ds:[0x7C3C0C]
		cmp edx, eax
		jl start_inc
		add eax, 0x10
		cmp edx, eax
		jg start_inc
		mov eax, dword ptr ds:[register_pos]
		cmp ecx, eax
		jl start_inc
		add eax, 19
		cmp ecx, eax
		jg start_inc
		cmp edi, 04
		jg pop_and_jmp
		xor eax, eax
		//cmp edi, eax
		//je check_helmet
		cmp edi, 01
		je check_pet
		cmp edi, 02
		je check_wing
		cmp edi, 03
		je check_costume
		jmp start_inc

		check_helmet :
		cmp dword ptr ds:[pointer_true_false], eax
		lea ecx, dword ptr ds:[pointer_true]
		sete al
		push ecx
		push 0x00
		mov dword ptr ds:[pointer_true_false], eax
		jmp end_

		check_pet :
		cmp dword ptr ds:[pointer_true_false + 0x04], eax
		lea ecx, dword ptr ds:[pointer_true]
		sete al
		push ecx
		push 00
		mov dword ptr ds:[pointer_true_false + 0x04], eax

		jmp end_

		check_wing:
		cmp dword ptr ds:[pointer_true_false + 0x08], eax
		lea ecx, dword ptr ds:[pointer_true]
		sete al
		push ecx
		push 00
		mov dword ptr ds:[pointer_true_false + 0x08], eax


		jmp end_


		check_costume :
		cmp dword ptr ds:[pointer_true_false + 0x0C], eax
		lea ecx, dword ptr ds:[pointer_true]
		sete al
		push ecx
		push 00
		mov dword ptr ds:[pointer_true_false + 0x0C], eax


		end_:
		mov ecx, dword ptr ds:[0x7C06F8]
		call isSave
		mov ecx, dword ptr ds:[0x7C3C10]
		mov ebp, dword ptr ds:[0x7AB0DC]
		start_inc:
		inc edi
		cmp edi,04
		jl get_pos
		popfd
		popad

		originalcode:



		mov dword ptr ds:[esi + 0x18], 00000001
		jmp click_check_box_inventory_return

		pop_and_jmp:
		popfd
		popad
		jmp originalcode
	}
}


DWORD render_check_box_return = 0x0047E0AF;
LPCSTR autoCommand = "Auto Comando Raid";
DWORD sendStringPos = 0x00631AB0;
DWORD sendString = 0x00532130;
_declspec(naked) void render_check_box() {
	_asm {
		cmp dword ptr ds : [0x022AA730] , 0 // leader
		je continue_
		cmp dword ptr ds : [0x022AA730] , 1 // sub-leader
		je continue_
		jmp originalcode
		continue_:
		pushad
		pushfd
		xor edi, edi
		start_loop :
		cmp edi, 01
		jg end_loop
		
		
		render_inv_check:
		mov eax, [ebx + 0x04]
		mov ecx, [ebx + 0x08]
		add eax, 0x01
		mov dword ptr ds : [registerPosChat_y] , ecx
		mov dword ptr ds : [registerPosChat_x] , eax
		cmp edi, 01
		jne isRenderCheck

		mov eax, [autoCommand]
		lea eax, [eax]
		mov ecx, 0xFFFFEA00
		push eax
		push ecx
		call sendStringPos
		mov eax, [ebx + 0x08]
		mov edx, [ebx + 04]
		push eax
		add edx, 0x15
		push edx
		call sendString
		add esp, 0x10

		mov eax, dword ptr ds : [edi * 0x4 + registerPosChat_y]
		mov ecx, dword ptr ds : [edi * 0x4 + registerPosChat_x]
		lea edx, dword ptr ds : pointer_true_false_chat
		cmp byte ptr ds : [edx] , 00
		jne render_click_box
		jmp isContinue

		render_click_box :
		push eax
		push ecx
		lea ecx, dword ptr ds : check_btn
		call isRenderObjectSingle
		isContinue:
		inc edi
		jmp start_loop

		isRenderCheck :
		mov eax, [ebx + 0x04]
		mov ecx, [ebx + 0x08]
		add eax, 0x02
		mov eax, dword ptr ds : [edi * 0x4 + registerPosChat_y]
		mov ecx, dword ptr ds : [edi * 0x4 + registerPosChat_x]
		push eax
		push ecx
		lea ecx, dword ptr ds : isCheckChat
		call isRenderObjectSingle
		jmp isContinue

		end_loop :
		popfd
		popad
		jmp originalcode_pop

		originalcode :
		movzx eax, byte ptr ds:[ebx + 0x000003CC]
		jmp render_check_box_return

		originalcode_pop:
	    pushad
		mov eax, [ebx + 0x04]
		mov ecx, [ebx + 0x08]
		add eax, 0x02
		mov dword ptr ds : [registerPosChat_y] , ecx
		mov dword ptr ds : [registerPosChat_x] , eax
		mov dword ptr ds : [registerPosChat_y + 0x04] , ecx
		mov dword ptr ds : [registerPosChat_x + 0x04] , eax
		popad
		jmp originalcode
	}
}


DWORD pointer_true_chat = 0;
DWORD send_save = 0x0420090;
DWORD click_check_box_return = 0x00487B41;
char pointer_true_false_chat[35];
char register_pos_chat[35];
_declspec(naked) void click_check_box() {
	_asm {
		cmp dword ptr ds : [0x022AA730] , 0 // leader
		je continue_
		cmp dword ptr ds : [0x022AA730] , 1 // sub-leader
		je continue_

		jmp originalcode

		continue_:
		pushad
		pushfd
		mov ecx, dword ptr ds:[0x7C3C10]// y mouse
		mov edi, dword ptr ds:[0x7C3C0C]// x mouse
		mov ebp, dword ptr ds:[0x7AB0DC]// resolução
		cmp ecx, ebp
		jg pop_and_jmp
		xor edi, edi
		get_pos:
		mov edx, dword ptr ds:[edi * 4 + registerPosChat_x]
		lea eax, [edx]
		mov edx, dword ptr ds:[edi * 4 + registerPosChat_y]
		lea edx, [edx]
		mov dword ptr ds:[register_pos_chat], edx
		mov edx, dword ptr ds:[0x7C3C0C]
		cmp edx, eax
		jl start_inc
		add eax, 0x10
		cmp edx, eax
		jg start_inc
		mov eax, dword ptr ds:[register_pos_chat]
		cmp ecx, eax
		jl start_inc
		add eax, 19
		cmp ecx, eax
		jg start_inc
		cmp edi, 00
		jg pop_and_jmp
		xor eax,eax
		cmp dword ptr ds:[pointer_true_false_chat], eax
		lea ecx, dword ptr ds:[pointer_true_chat]
		sete al
		push ecx
		push 0x00
		mov dword ptr ds:[pointer_true_false_chat], eax
		mov ecx, dword ptr ds:[0x7C06F8]
		call isSaveChat
		mov ecx, dword ptr ds:[0x7C3C10]
		mov ebp, dword ptr ds:[0x7AB0DC]
		start_inc:
		inc edi
		cmp edi,00
		jl get_pos
		popfd
		popad

		originalcode :
		cmp dword ptr ds:[0x22B24C4], 00
		jmp click_check_box_return

		pop_and_jmp:
		popfd
		popad
		jmp originalcode

		isSaveChat:
		mov al,[pointer_true_false_chat]
		mov byte ptr ds:[Auto_Raid_Command_Pointer] , al
		ret 0x008
	}
}



void hook::CheckBoxs() {
	//Hook((void*)0x0047E0A8, render_check_box, 7);
	//Hook((void*)0x00487B3A, click_check_box, 7);
	util::detour((PVOID)0x0051A547, pointer_inv_open, 5);
	util::detour((PVOID)0x51A5D7, render_check_box_inventory, 7);
	util::detour((PVOID)0x00564403, click_check_box_inventory, 7);
	//DisableCostume();
	CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(get_value_pointer_true), NULL, 0, 0);
}