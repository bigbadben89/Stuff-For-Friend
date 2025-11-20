#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"

// 022CBA88 = efeito 2
// 022CBBB4 = efeito 3
// 022CBCE0 = efeito 4
// 022CBE0C = efeito 5
// 022CBF38 = efeito 6
// 022CC064 = efeito 7
// 022CC190 = efeito 8
// 022CC2BC = efeito 9
// 022CC3E8 = efeito 10
// 022CC514 = efeito 11
LPCSTR Efeito1 = "effect1.eft";
LPCSTR Efeito2 = "effect2.eft";
LPCSTR Efeito3 = "effect3.eft";
LPCSTR Efeito4 = "effect4.eft";
LPCSTR Efeito5 = "effect5.eft";
LPCSTR Efeito6 = "effect6.eft";
LPCSTR Efeito7 = "effect7.eft";
LPCSTR Efeito8 = "effect8.eft";
LPCSTR Efeito9 = "effect9.eft";
LPCSTR Efeito10 = "effect10.eft";
LPCSTR Efeito11 = "effect11.eft";
DWORD Send_Load_Effect = 0x0058C460;
DWORD Alloc_Return = 0x0042BDB4;
DWORD Effect_Address = 0x0042BC77;

_declspec(naked) void Alloc_Effects() {

	_asm {
		// 022CBA88 = efeito 2
// 022CBBB4 = efeito 3
// 022CBCE0 = efeito 4
// 022CBE0C = efeito 5
// 022CBF38 = efeito 6
// 022CC064 = efeito 7
// 022CC190 = efeito 8
// 022CC2BC = efeito 9
// 022CC3E8 = efeito 10
// 022CC514 = efeito 11


		push Efeito1
		push 0x00748864 // data/effect 
		mov ecx, 0x022CB704 // efeito1 
		Call Send_Load_Effect
		test eax, eax
		je Effect_Continue
		//
		push Efeito2
		push 0x00748864 // data/effect 
		mov ecx, 0x022CBA88 // efeito1  // - / 022BB8B8 = DC
		Call Send_Load_Effect
		test eax, eax
		je Effect_Continue
		//
		push Efeito3
		push 0x00748864 // data/effect   
		mov ecx, 0x022CBBB4 // efeito1  - / 022BB8B8 = DD
		Call Send_Load_Effect
		test eax, eax
		je Effect_Continue

		push Efeito4
		push 0x00748864 // data/effect 
		mov ecx, 0x022CBCE0 // efeito1 - / 022BB8B8 
		Call Send_Load_Effect
		test eax, eax
		je Effect_Continue

		push Efeito5
		push 0x00748864 // data/effect 
		mov ecx, 0x022CBE0C // efeito1  - / 022BB8B8 =
		Call Send_Load_Effect
		test eax, eax
		je Effect_Continue

		push Efeito6
		push 0x00748864 // data/effect 
		mov ecx, 0x022CBF38 // efeito1  - / 022BB8B8 =
		Call Send_Load_Effect
		test eax, eax
		je Effect_Continue

		push Efeito7
		push 0x00748864 // data/effect 
		mov ecx, 0x022CC064 // efeito1 - / 022BB8B8 =
		Call Send_Load_Effect
		test eax, eax
		je Effect_Continue

		push Efeito8
		push 0x00748864 // data/effect 
		mov ecx, 0x022CC190 // efeito1 - / 022BB8B8 =
		Call Send_Load_Effect
		test eax, eax
		je Effect_Continue

		push Efeito9
		push 0x00748864 // data/effect 
		mov ecx, 0x022CC2BC // efeito1 - / 022BB8B8 =
		Call Send_Load_Effect
		test eax, eax
		je Effect_Continue

		push Efeito10
		push 0x00748864 // data/effect 
		mov ecx, 0x022CC3E8 // efeito1 - / 022BB8B8 =
		Call Send_Load_Effect
		test eax, eax
		je Effect_Continue

		push Efeito11
		push 0x00748864 // data/effect 
		mov ecx, 0x022CC514 // efeito1 - / 022BB8B8 =
		Call Send_Load_Effect
		test eax, eax
		je Effect_Continue

		push 0x00749E74
		push 0x00748864
		jmp Alloc_Return

		Effect_Continue :
		jmp Effect_Address



	}

}


void hook::AllocEffects() {
	util::detour((void*)0x0042BDAA, Alloc_Effects, 5);
}