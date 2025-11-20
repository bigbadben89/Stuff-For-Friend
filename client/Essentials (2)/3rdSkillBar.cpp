#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"

int skillbar_pointer1 = 0;
// 
DWORD skillbarnew6jmp = 0x42B6DA;

DWORD skillbarnew6call1 = 0x6307F3;

DWORD skillbarnew6call2 = 0x4FE4A0;

__declspec(naked) void skillbar_main()
{

	_asm
	{


		push 0x12C
		call skillbarnew6call1
		add esp, 0x04
		mov[esp + 0x18], eax
		mov byte ptr[esp + 0x24], 0x25
		cmp eax, edi
		je packetmnsje
		push 0x02
		mov ecx, eax
		call skillbarnew6call2
		mov[skillbar_pointer1], eax
		mov byte ptr[eax + 0x04], 0x00
		mov byte ptr[eax + 0x08], 0x78
		jmp packetmnsjejmp
		packetmnsje :
		xor eax, eax
			packetmnsjejmp :
		mov[esp + 0x24], bl
			mov[esi + 0x2A4], eax
			mov eax, [skillbar_pointer1]
			mov bl, 0x00
			mov[eax + 0x20], bl
			mov eax, 0x022AAB3A
			mov byte ptr[eax], 0x02
			mov eax, [esi + 0x17C]
			lea edx, [esi + 0x1D8]
			originalcode:
		jmp skillbarnew6jmp



	}
}




DWORD skillbar_add1jmp = 0x4A4028;

DWORD skillbar_add1jnejmp = 0x4A4004;
DWORD skillbar_add1call = 0x4FDFA0;
void __declspec(naked) skillbar_add1() {
	__asm {

		movzx ecx, byte ptr[edi + 0xFC]
		movzx edx, byte ptr[edi + 0xFD]
		push ecx
		push edx
		mov ecx, [skillbar_pointer1]
		call skillbar_add1call
		test eax, eax
		jne skillbar_addjnes
		movzx ecx, byte ptr[edi + 0xFC]
		jmp skillbar_add1jmp

		skillbar_addjnes :
		jmp skillbar_add1jnejmp



	}
}


DWORD skillbar_add2jmp = 0x4A410B;

DWORD skillbar_add2call = 0x4FDFA0;

void __declspec(naked) skillbar_add2() {
	__asm {



		movzx eax, byte ptr[edi + 0x103]
		mov ecx, [skillbar_pointer1]
		push eax
		push 0x64
		call skillbar_add2call
		test eax, eax
		je skillbar_add2jes
		mov byte ptr[edi + 0x103], -01
		skillbar_add2jes:
		movzx eax, byte ptr[edi + 0x103]
			push eax
			originalcode :
		jmp skillbar_add2jmp



	}
}



DWORD skillbar_add3jmp = 0x4FE582;

DWORD skillbar_add3jejmp = 0x4FE597;


void __declspec(naked) skillbar_add3() {
	__asm {


		mov al, [esp + 0x28]
		cmp byte ptr[esp + 0x28], 0x02
		jnl skillbar_add3exits
		cmp byte ptr[esp + 0x28], 0x00
		je skillbar_add3jes
		jmp skillbar_add3jes

		skillbar_add3exits :
		jmp skillbar_add3jmp

			skillbar_add3jes :
		jmp skillbar_add3jejmp

			originalcode :
		jmp skillbar_add3jejmp



	}
}


DWORD skillbar_add4jmp = 0x4FF2A0;

DWORD skillbar_add4jejmp = 0x4FF44D;

void __declspec(naked) skillbar_add4() {
	__asm {

		cmp byte ptr[esi + 0x124], 0x02
		je skillbar_add4jes
		mov eax, 0x007C0E8C
		mov eax, [eax]
		jmp skillbar_add4jmp

		skillbar_add4jes :
		jmp skillbar_add4jejmp

			originalcode :
		jmp skillbar_add4jejmp

	}
}



// 
DWORD skillbar_add5jmp = 0x4FF959;

DWORD skillbar_add5jajmp = 0x4FF9A5;


void __declspec(naked) skillbar_add5() {
	__asm {

		cmp byte ptr[esi + 0x124], 01
		ja skillbar_add5jajmps
		jmp skillbar_add5jmp

		skillbar_add5jajmps :
		jmp skillbar_add5jajmp

			originalcode :
		jmp skillbar_add5jajmp

	}
}




DWORD skillbar_add6jmp = 0x4FF99B;

void __declspec(naked) skillbar_add6() {
	__asm {

		mov byte ptr[esi + 0x121], 01
		cmp byte ptr[esi + 0x124], 01
		jne skillbar_add6jnejmps
		cmp byte ptr[esi + 0x119], 00
		sete al
		mov esi, [skillbar_pointer1]
		mov[esi + 0x20], al

		skillbar_add6jnejmps :
		jmp skillbar_add6jmp

			originalcode :
		jmp skillbar_add6jmp


	}
}

DWORD skillbar_add7jmp = 0x4FFE77;

DWORD skillbar_add7jejmp = 0x4FFF3C;
DWORD skillbar_add7jnejmp = 0x4FFF8E;

void __declspec(naked) skillbar_add7() {
	__asm {

		cmp byte ptr[edi + 0x124], 02
		je skillbar_add7jes
		cmp byte ptr[edi + 0x124], 00
		jmp skillbar_add7jmp

		skillbar_add7jes :
		jmp skillbar_add7jmps
			mov edx, [esp + 0x14]
			jmp skillbar_add7jejmp //je

			skillbar_add7jmps :
		jmp skillbar_add7jnejmp //jne

			originalcode :
		jmp skillbar_add7jnejmp

	}
}


void rdSkillBar() {

	util::detour((void*)0x42B6D4, skillbar_main, 6);
	//
	util::detour((void*)0x4A4021, skillbar_add1, 7);
	//
	util::detour((void*)0x4A4103, skillbar_add2, 8);
	//
	util::detour((void*)0x4FE57C, skillbar_add3, 6); //Slot plus Görüntü
	//
	//util::detour((void*)0x4FF29B, skillbar_add4, 5);
	//
	util::detour((void*)0x4FF950, skillbar_add5, 9);
	//
	util::detour((void*)0x4FF994, skillbar_add6, 7); // Slot plus + ve - düzeltme
	//
	util::detour((void*)0x4FFE70, skillbar_add7, 7);

	BYTE skillbar_main_memory2[] = { 0x3C, 0x02 };
	memcpy((void*)0x4FEF39, skillbar_main_memory2, 2);

}