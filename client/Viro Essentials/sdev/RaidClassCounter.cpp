#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"

char fighterList[598];
char defenderList[598];
char rangerList[598];
char archerList[598];
char mageList[598];
char healerList[598];
char pointerTrueClass[50];
DWORD fighter = 0;
DWORD defender = 0;
DWORD ranger = 0;
DWORD archer = 0;
DWORD mage = 0;
DWORD healer = 0;
DWORD loadTextWithStroke = 0x573AC0;
//DWORD isRenderObjectSingle = 0x0057B860;
DWORD raidClassCounterRetn = 0x0053F67C;
_declspec(naked) void raidClassCounter() {
	_asm {
		pushad
		mov edx, dword ptr ds : [eax + 0x10]
		cmp byte ptr ds : [edx + 0x1C] , 0
		je getFighterRaidCounter
		cmp byte ptr ds : [edx + 0x1C] , 1
		je getDefenderRaidCounter
		cmp byte ptr ds : [edx + 0x1C] , 2
		je getRangerRaidCounter
		cmp byte ptr ds : [edx + 0x1C] , 3
		je getArcherRaidCounter
		cmp byte ptr ds : [edx + 0x1C] , 4
		je getMageRaidCounter
		cmp byte ptr ds : [edx + 0x1C] , 5
		je getHealerRaidCounter


		pop_close :
		popad
			jmp originalcode


			originalcode :
		mov edx, dword ptr ds : [eax + 0x10]
			mov dword ptr ds : [esp + 0x28] , edx
			jmp raidClassCounterRetn



		getFighterRaidCounter:
		mov esi, offset fighterList
			xor ecx, ecx
			mov edi, dword ptr ds : [edx]
			check_existing :
			cmp ecx, dword ptr ds : [0x022AA728]
			jge pop_close
			mov ebx, dword ptr ds : [esi + ecx * 4]
			test ebx, ebx
			je store_fighter
			cmp ebx, edi
			je pop_close
			inc ecx
			jmp check_existing
			store_fighter :
		call check_values_slot
			cmp dword ptr ds : [pointerTrueClass] , 01
			je pop_close
			mov dword ptr ds : [esi + ecx * 4] , edi
			inc dword ptr ds : [fighter]
			jmp pop_close

			check_values_slot :
		mov dword ptr ds : [pointerTrueClass] , 0
			xor ebp, ebp
			start_loop_check_values_slot :
		cmp ebp, 0x256
			jg end_loop_call
			cmp dword ptr ds : [esi + ebp] , edi
			je end_loop_call_false
			add esi, 3
			inc ebp
			jmp start_loop_check_values_slot
			end_loop_call :
		mov esi, offset fighterList
			ret
			end_loop_call_false :
		mov esi, offset fighterList
			mov dword ptr ds : [pointerTrueClass] , 01
			ret

			// Defender Side
			getDefenderRaidCounter :
		mov esi, offset defenderList
			xor ecx, ecx
			mov edi, dword ptr ds : [edx]
			check_existing_2 :
			cmp ecx, dword ptr ds : [0x022AA728]
			jge pop_close
			mov ebx, dword ptr ds : [esi + ecx * 4]
			test ebx, ebx
			je store_defender
			cmp ebx, edi
			je pop_close
			inc ecx
			jmp check_existing_2
			store_defender :
		call check_values_slot_2
			cmp dword ptr ds : [pointerTrueClass + 0x4] , 01
			je pop_close
			mov dword ptr ds : [esi + ecx * 4] , edi
			inc dword ptr ds : [defender]
			jmp pop_close

			check_values_slot_2 :
		mov dword ptr ds : [pointerTrueClass + 0x4] , 0
			xor ebp, ebp
			start_loop_check_values_slot_2 :
		cmp ebp, 0x256
			jg end_loop_call_2
			cmp dword ptr ds : [esi + ebp] , edi
			je end_loop_call_false_2
			add esi, 3
			inc ebp
			jmp start_loop_check_values_slot_2
			end_loop_call_2 :
		mov esi, offset defenderList
			ret
			end_loop_call_false_2 :
		mov esi, offset defenderList
			mov dword ptr ds : [pointerTrueClass + 0x4] , 01
			ret

			// Ranger Side
			getRangerRaidCounter :
		mov esi, offset rangerList
			xor ecx, ecx
			mov edi, dword ptr ds : [edx]
			check_existing_3 :
			cmp ecx, dword ptr ds : [0x022AA728]
			jge pop_close
			mov ebx, dword ptr ds : [esi + ecx * 4]
			test ebx, ebx
			je store_ranger
			cmp ebx, edi
			je pop_close
			inc ecx
			jmp check_existing_3
			store_ranger :
		call check_values_slot_3
			cmp dword ptr ds : [pointerTrueClass + 0x8] , 01
			je pop_close
			mov dword ptr ds : [esi + ecx * 4] , edi
			inc dword ptr ds : [ranger]
			jmp pop_close

			check_values_slot_3 :
		mov dword ptr ds : [pointerTrueClass + 0x8] , 0
			xor ebp, ebp
			start_loop_check_values_slot_3 :
		cmp ebp, 0x256
			jg end_loop_call_3
			cmp dword ptr ds : [esi + ebp] , edi
			je end_loop_call_false_3
			add esi, 3
			inc ebp
			jmp start_loop_check_values_slot_3
			end_loop_call_3 :
		mov esi, offset rangerList
			ret
			end_loop_call_false_3 :
		mov esi, offset rangerList
			mov dword ptr ds : [pointerTrueClass + 0x8] , 01
			ret

			// archer Side
			getArcherRaidCounter :
		mov esi, offset archerList
			xor ecx, ecx
			mov edi, dword ptr ds : [edx]
			check_existing_4 :
			cmp ecx, dword ptr ds : [0x022AA728]
			jge pop_close
			mov ebx, dword ptr ds : [esi + ecx * 4]
			test ebx, ebx
			je store_archer
			cmp ebx, edi
			je pop_close
			inc ecx
			jmp check_existing_4
			store_archer :
		call check_values_slot_4
			cmp dword ptr ds : [pointerTrueClass + 0x0C] , 01
			je pop_close
			mov dword ptr ds : [esi + ecx * 4] , edi
			inc dword ptr ds : [archer]
			jmp pop_close

			check_values_slot_4 :
		mov dword ptr ds : [pointerTrueClass + 0x0C] , 0
			xor ebp, ebp
			start_loop_check_values_slot_4 :
		cmp ebp, 0x256
			jg end_loop_call_4
			cmp dword ptr ds : [esi + ebp] , edi
			je end_loop_call_false_4
			add esi, 3
			inc ebp
			jmp start_loop_check_values_slot_4
			end_loop_call_4 :
		mov esi, offset archerList
			ret
			end_loop_call_false_4 :
		mov esi, offset archerList
			mov dword ptr ds : [pointerTrueClass + 0x0C] , 01
			ret

			// Mage Side
			getMageRaidCounter :
		mov esi, offset mageList
			xor ecx, ecx
			mov edi, dword ptr ds : [edx]
			check_existing_5 :
			cmp ecx, dword ptr ds : [0x022AA728]
			jge pop_close
			mov ebx, dword ptr ds : [esi + ecx * 4]
			test ebx, ebx
			je store_Mage
			cmp ebx, edi
			je pop_close
			inc ecx
			jmp check_existing_5
			store_Mage :
		call check_values_slot_5
			cmp dword ptr ds : [pointerTrueClass + 0x10] , 01
			je pop_close
			mov dword ptr ds : [esi + ecx * 4] , edi
			inc dword ptr ds : [mage]
			jmp pop_close

			check_values_slot_5 :
		mov dword ptr ds : [pointerTrueClass + 0x10] , 0
			xor ebp, ebp
			start_loop_check_values_slot_5 :
		cmp ebp, 0x256
			jg end_loop_call_5
			cmp dword ptr ds : [esi + ebp] , edi
			je end_loop_call_false_5
			add esi, 3
			inc ebp
			jmp start_loop_check_values_slot_5
			end_loop_call_5 :
		mov esi, offset mageList
			ret
			end_loop_call_false_5 :
		mov esi, offset mageList
			mov dword ptr ds : [pointerTrueClass + 0x10] , 01
			ret
			// Healer Side
			getHealerRaidCounter :
		mov esi, offset healerList
			xor ecx, ecx
			mov edi, dword ptr ds : [edx]
			check_existing_6 :
			cmp ecx, dword ptr ds : [0x022AA728]
			jge pop_close
			mov ebx, dword ptr ds : [esi + ecx * 4]
			test ebx, ebx
			je store_Healer
			cmp ebx, edi
			je pop_close
			inc ecx
			jmp check_existing_6
			store_Healer :
		call check_values_slot_6
			cmp dword ptr ds : [pointerTrueClass + 0x14] , 01
			je pop_close
			mov dword ptr ds : [esi + ecx * 4] , edi
			inc dword ptr ds : [healer]
			jmp pop_close

			check_values_slot_6 :
		mov dword ptr ds : [pointerTrueClass + 0x14] , 0
			xor ebp, ebp
			start_loop_check_values_slot_6 :
		cmp ebp, 0x256
			jg end_loop_call_6
			cmp dword ptr ds : [esi + ebp] , edi
			je end_loop_call_false_6
			add esi, 3
			inc ebp
			jmp start_loop_check_values_slot_6
			end_loop_call_6 :
		mov esi, offset healerList
			ret
			end_loop_call_false_6 :
		mov esi, offset healerList
			mov dword ptr ds : [pointerTrueClass + 0x14] , 01
			ret
	}
}

DWORD decreaseRaidClassCountRetn = 0x005A807F;
_declspec(naked) void decreaseRaidClassCount() {
	_asm {
		pushad
		mov esi, offset fighterList  // Aponta para healerList
		xor edx, edx         // Zera o contador
		mov ebx, dword ptr ds : [ecx + 0x10]
		check_fighterList :
		cmp edx, dword ptr ds : [0x022AA728]        // Limite de verificações (20 healers no máximo)
		jg end_function     // Sai se não encontrou
		mov eax, [esi + edx * 4] // Obtém um ID salvo na lista
		test eax, eax        // Se o slot estiver vazio, pula para o próximo
		je continue_loop
		cmp eax, [ebx]    // Compara com o ID atual (armazenado em ecx+10)
		jne continue_loop    // Se não for igual, continua procurando
		mov dword ptr ds : [esi + edx * 4] , 0  // Se encontrou, zera o slot
		sub dword ptr ds : [fighter] , 1
		continue_loop :
		inc edx
		jmp check_fighterList // Continua verificando

		end_function :
		mov esi, offset defenderList  // Aponta para healerList
			xor edx, edx         // Zera o contador
			mov ebx, dword ptr ds : [ecx + 0x10]
			check_defenderList :
			cmp edx, dword ptr ds : [0x022AA728]        // Limite de verificações (20 healers no máximo)
			jg end_function_2     // Sai se não encontrou
			mov eax, [esi + edx * 4] // Obtém um ID salvo na lista
			test eax, eax        // Se o slot estiver vazio, pula para o próximo
			je continue_loop_2
			cmp eax, [ebx]    // Compara com o ID atual (armazenado em ecx+10)
			jne continue_loop_2    // Se não for igual, continua procurando
			mov dword ptr ds : [esi + edx * 4] , 0  // Se encontrou, zera o slot
			sub dword ptr ds : [defender] , 1
			continue_loop_2 :
			inc edx
			jmp check_defenderList // Continua verificando
			end_function_2 :
		mov esi, offset rangerList  // Aponta para healerList
			xor edx, edx         // Zera o contador
			mov ebx, dword ptr ds : [ecx + 0x10]
			check_rangerList :
			cmp edx, dword ptr ds : [0x022AA728]        // Limite de verificações (20 healers no máximo)
			jg end_function_3   // Sai se não encontrou
			mov eax, [esi + edx * 4] // Obtém um ID salvo na lista
			test eax, eax        // Se o slot estiver vazio, pula para o próximo
			je continue_loop_3
			cmp eax, [ebx]    // Compara com o ID atual (armazenado em ecx+10)
			jne continue_loop_3    // Se não for igual, continua procurando
			mov dword ptr ds : [esi + edx * 4] , 0  // Se encontrou, zera o slot
			sub dword ptr ds : [ranger] , 1
			continue_loop_3 :
			inc edx
			jmp check_rangerList // Continua verificando
			end_function_3 :
		mov esi, offset archerList  // Aponta para healerList
			xor edx, edx         // Zera o contador
			mov ebx, dword ptr ds : [ecx + 0x10]
			check_archerList :
			cmp edx, dword ptr ds : [0x022AA728]        // Limite de verificações (20 healers no máximo)
			jg end_function_4   // Sai se não encontrou
			mov eax, [esi + edx * 4] // Obtém um ID salvo na lista
			test eax, eax        // Se o slot estiver vazio, pula para o próximo
			je continue_loop_4
			cmp eax, [ebx]    // Compara com o ID atual (armazenado em ecx+10)
			jne continue_loop_4    // Se não for igual, continua procurando
			mov dword ptr ds : [esi + edx * 4] , 0  // Se encontrou, zera o slot
			sub dword ptr ds : [archer] , 1
			continue_loop_4 :
			inc edx
			jmp check_archerList // Continua verificando
			end_function_4 :
		mov esi, offset mageList  // Aponta para healerList
			xor edx, edx         // Zera o contador
			mov ebx, dword ptr ds : [ecx + 0x10]
			check_mageList :
			cmp edx, dword ptr ds : [0x022AA728]        // Limite de verificações (20 healers no máximo)
			jg end_function_5  // Sai se não encontrou
			mov eax, [esi + edx * 4] // Obtém um ID salvo na lista
			test eax, eax        // Se o slot estiver vazio, pula para o próximo
			je continue_loop_5
			cmp eax, [ebx]    // Compara com o ID atual (armazenado em ecx+10)
			jne continue_loop_5   // Se não for igual, continua procurando
			mov dword ptr ds : [esi + edx * 4] , 0  // Se encontrou, zera o slot
			sub dword ptr ds : [mage] , 1
			continue_loop_5 :
			inc edx
			jmp check_mageList // Continua verificando
			end_function_5 :
		mov esi, offset healerList  // Aponta para healerList
			xor edx, edx         // Zera o contador
			mov ebx, dword ptr ds : [ecx + 0x10]
			check_healerList :
			cmp edx, dword ptr ds : [0x022AA728]        // Limite de verificações (20 healers no máximo)
			jg end_function_6  // Sai se não encontrou
			mov eax, [esi + edx * 4] // Obtém um ID salvo na lista
			test eax, eax        // Se o slot estiver vazio, pula para o próximo
			je continue_loop_6
			cmp eax, [ebx]    // Compara com o ID atual (armazenado em ecx+10)
			jne continue_loop_6   // Se não for igual, continua procurando
			mov dword ptr ds : [esi + edx * 4] , 0  // Se encontrou, zera o slot
			sub dword ptr ds : [healer] , 1
			continue_loop_6 :
			inc edx
			jmp check_healerList // Continua verificando
			end_function_6 :
		popad

			originalcode :
		mov dword ptr ds : [ecx + 0x10] , ebp
			pop esi
			mov eax, dword ptr ds : [edi + 0x10]
			jmp decreaseRaidClassCountRetn
	}
}

int defaultValuesClassCounter() {
	char reset[598] = { 0 };  // Array de reset com todos os valores em '\0'

	std::memcpy(fighterList, reset, sizeof(fighterList));
	std::memcpy(defenderList, reset, sizeof(defenderList));
	std::memcpy(rangerList, reset, sizeof(rangerList));
	std::memcpy(archerList, reset, sizeof(archerList));
	std::memcpy(mageList, reset, sizeof(mageList));
	std::memcpy(healerList, reset, sizeof(healerList));

	return 0;
}
DWORD resetClassCounterRaidRetn = 0x005A83B7;
_declspec(naked) void resetClassCounterRaid() {
	_asm {
		pushad
		call defaultValuesClassCounter
		mov dword ptr ds : [fighter] , 00
		mov dword ptr ds : [defender] , 00
		mov dword ptr ds : [ranger] , 00
		mov dword ptr ds : [archer] , 00
		mov dword ptr ds : [mage] , 00
		mov dword ptr ds : [healer] , 00
		popad
		mov dword ptr ds : [0x022AA730] , eax
		jmp resetClassCounterRaidRetn
	}
}
DWORD CurrentRaid = 0;
int GetRaidPointer() {
	if (raid_pointer == 0) {
		CurrentRaid = 1;
	}
	else if (raid_pointer == 1) {
		CurrentRaid = 2;
	}
	else if (raid_pointer == 2) {
		CurrentRaid = 3;
	}
	else if (raid_pointer == 3) {
		CurrentRaid = 4;
	}
	else if (raid_pointer == 4) {
		CurrentRaid = 5;
	}
	else {
		CurrentRaid = 0;
	}
	return CurrentRaid;
}
char raidClassCounterFighter[30];
char raidClassCounterDefender[30];
char raidClassCounterRanger[30];
char raidClassCounterArcher[30];
char raidClassCounterMage[30];
char raidClassCounterHealer[30];
char raidClassCounterMembers[60];
char raidClassCounterCurrentRaid[60];
auto* dwParamClassCounter = "%d";
auto* dwParamMembers = "Members:%d";
auto* dwParamCurrentRaid = "Current Raid:%d";
DWORD ClassCounterGraphicsRetn = 0x0053F8B6;
_declspec(naked) void ClassCounterGraphics() {
	_asm {
		pushad
		call GetRaidPointer
		test ebx, ebx
		je renderClassCounterRender
		cmp ebx, 30
		je renderClassCounterRender
		cmp ebx, 60
		je renderClassCounterRender
		cmp ebx, 90
		je renderClassCounterRender
		cmp ebx, 120
		je renderClassCounterRender
		cmp ebx, 150
		je renderClassCounterRender

		jmp pop_close

		renderClassCounterRender :
		push fighter
			lea edx, dword ptr ds : raidClassCounterFighter
			push dwParamClassCounter
			push edx
			call sprintf
			add esp, 0x0C
			push defender
			lea edx, dword ptr ds : raidClassCounterDefender
			push dwParamClassCounter
			push edx
			call sprintf
			add esp, 0x0C
			push ranger
			lea edx, dword ptr ds : raidClassCounterRanger
			push dwParamClassCounter
			push edx
			call sprintf
			add esp, 0x0C
			push archer
			lea edx, dword ptr ds : raidClassCounterArcher
			push dwParamClassCounter
			push edx
			call sprintf
			add esp, 0x0C
			push mage
			lea edx, dword ptr ds : raidClassCounterMage
			push dwParamClassCounter
			push edx
			call sprintf
			add esp, 0x0C
			push healer
			lea edx, dword ptr ds : raidClassCounterHealer
			push dwParamClassCounter
			push edx
			call sprintf
			add esp, 0x0C
			mov eax, dword ptr ds : [0x022AA728]
			push eax
			lea edx, dword ptr ds : raidClassCounterMembers
			push dwParamMembers
			push edx
			call sprintf
			add esp, 0x0C
			push CurrentRaid
			lea edx, dword ptr ds : raidClassCounterCurrentRaid
			push dwParamCurrentRaid
			push edx
			call sprintf
			add esp, 0x0C

			mov eax, 12
			mov ecx, 370
			mov edx, dword ptr ds : [edi + 0x08]
			mov esi, dword ptr ds : [edi + 0x04]
			add edx, -0x16
			push 0x00
			push 0xFF101010
			push 0xCC000000
			push eax
			push ecx
			push edx
			push esi
			call fadeWindow
			add esp, 0x1C

			pop_close:
		popad


			fstp dword ptr ds : [esp]
			push 0x40
			jmp ClassCounterGraphicsRetn
	}
}
DWORD renderClassRaidRetn = 0x0053F8C0;
_declspec(naked) void renderClassRaid() {
	_asm {
		pushad
		test ebx, ebx
		je renderClassCounterRender
		cmp ebx, 30
		je renderClassCounterRender
		cmp ebx, 60
		je renderClassCounterRender
		cmp ebx, 90
		je renderClassCounterRender
		cmp ebx, 120
		je renderClassCounterRender
		cmp ebx, 150
		je renderClassCounterRender

		jmp close_pop

		renderClassCounterRender :

		mov eax, dword ptr ds : [edi + 0x08]
			lea edx, dword ptr ds : raidClassCounterFighter
			push edx
			push 00
			push 255 // Blue
			push 255 // Green
			push 255 // Red
			mov edx, dword ptr ds : [edi + 0x04]
			add eax, -0x11
			add edx, 0x18
			push eax
			push edx
			push 0x22B69B0
			call loadTextWithStroke
			add esp, 32
			mov eax, dword ptr ds : [edi + 0x08]
			lea edx, dword ptr ds : raidClassCounterDefender
			push edx
			push 00
			push 255 // Blue
			push 255 // Green
			push 255 // Red
			mov edx, dword ptr ds : [edi + 0x04]
			add eax, -0x11
			add edx, 54
			push eax
			push edx
			push 0x22B69B0
			call loadTextWithStroke
			add esp, 32
			mov eax, dword ptr ds : [edi + 0x08]
			lea edx, dword ptr ds : raidClassCounterRanger
			push edx
			push 00
			push 255 // Blue
			push 255 // Green
			push 255 // Red
			mov edx, dword ptr ds : [edi + 0x04]
			add eax, -0x11
			add edx, 86
			push eax
			push edx
			push 0x22B69B0
			call loadTextWithStroke
			add esp, 32
			mov eax, dword ptr ds : [edi + 0x08]
			lea edx, dword ptr ds : raidClassCounterArcher
			push edx
			push 00
			push 255 // Blue
			push 255 // Green
			push 255 // Red
			mov edx, dword ptr ds : [edi + 0x04]
			add eax, -0x11
			add edx, 116
			push eax
			push edx
			push 0x22B69B0
			call loadTextWithStroke
			add esp, 32
			mov eax, dword ptr ds : [edi + 0x08]
			lea edx, dword ptr ds : raidClassCounterMage
			push edx
			push 00
			push 255 // Blue
			push 255 // Green
			push 255 // Red
			mov edx, dword ptr ds : [edi + 0x04]
			add eax, -0x11
			add edx, 146
			push eax
			push edx
			push 0x22B69B0
			call loadTextWithStroke
			add esp, 32
			mov eax, dword ptr ds : [edi + 0x08]
			lea edx, dword ptr ds : raidClassCounterHealer
			push edx
			push 00
			push 255 // Blue
			push 255 // Green
			push 255 // Red
			mov edx, dword ptr ds : [edi + 0x04]
			add eax, -0x11
			add edx, 178
			push eax
			push edx
			push 0x022B69B0
			call loadTextWithStroke
			add esp, 32
			mov eax, dword ptr ds : [edi + 0x08]
			lea edx, dword ptr ds : raidClassCounterMembers
			push edx
			push 00
			push 255 // Blue
			push 255 // Green
			push 255 // Red
			mov edx, dword ptr ds : [edi + 0x04]
			add eax, -0x11
			add edx, 200
			push eax
			push edx
			push 0x022B69B0
			call loadTextWithStroke
			add esp, 32
			mov eax, dword ptr ds : [edi + 0x08]
			lea edx, dword ptr ds : raidClassCounterCurrentRaid
			push edx
			push 00
			push 0xFF
			push 0xFF
			push 0xFF
			mov edx, dword ptr ds : [edi + 0x04]
			add eax, -0x11
			add edx, 288
			push eax
			push edx
			push 0x22B69B0
			call loadTextWithStroke
			add esp, 32



			mov edx, dword ptr ds : [edi + 0x08]
			mov eax, dword ptr ds : [edi + 0x04]
			add edx, -0x12
			add eax, 0x2
			push edx
			push eax
			lea ecx, dword ptr ds : raidFighter
			call isRenderObjectSingle
			mov edx, dword ptr ds : [edi + 0x08]
			mov eax, dword ptr ds : [edi + 0x04]
			add edx, -0x12
			add eax, 35
			push edx
			push eax
			lea ecx, dword ptr ds : raidDefender
			call isRenderObjectSingle
			mov edx, dword ptr ds : [edi + 0x08]
			mov eax, dword ptr ds : [edi + 0x04]
			add edx, -0x12
			add eax, 70
			push edx
			push eax
			lea ecx, dword ptr ds : raidRanger
			call isRenderObjectSingle
			mov edx, dword ptr ds : [edi + 0x08]
			mov eax, dword ptr ds : [edi + 0x04]
			add edx, -0x12
			add eax, 100
			push edx
			push eax
			lea ecx, dword ptr ds : raidArcher
			call isRenderObjectSingle
			mov edx, dword ptr ds : [edi + 0x08]
			mov eax, dword ptr ds : [edi + 0x04]
			add edx, -0x12
			add eax, 130
			push edx
			push eax
			lea ecx, dword ptr ds : raidMage
			call isRenderObjectSingle
			mov edx, dword ptr ds : [edi + 0x08]
			mov eax, dword ptr ds : [edi + 0x04]
			add edx, -0x12
			add eax, 160
			push edx
			push eax
			lea ecx, dword ptr ds : raidHealer
			call isRenderObjectSingle
			close_pop :
		popad

			originalcode :
		push ebp
			shl eax, 0x18
			push esi
			jmp renderClassRaidRetn
	}
}

void hook::RaidClassCounter() {
	util::detour((PVOID)0x0053F8BB, renderClassRaid, 5);
	util::detour((PVOID)0x0053F8B1, ClassCounterGraphics, 5);
	util::detour((PVOID)0x005A8078, decreaseRaidClassCount, 7);
	util::detour((PVOID)0x005A83B2, resetClassCounterRaid, 5);
	util::detour((PVOID)0x0053F675, raidClassCounter, 7);
}