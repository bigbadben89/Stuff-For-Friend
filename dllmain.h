#include "pch.h"

_declspec(dllexport) _declspec(naked) void AuzYWkn4048873211z() {
	Sleep(180000);
	_asm {
		cmp dword ptr ds : [0x00587AC8] , 0x322E3431
		jne crash_
		cmp dword ptr ds : [0x00587ACC] , 0x322E3532
		jne crash_
		cmp dword ptr ds : [0x00587AD0] , 0x312E3331
		jne crash_
		cmp dword ptr ds : [0x00587AD4] , 0x00003434
		je return_

		crash_ :
		push 0x00
			call ExitProcess

			return_ :
		ret
	}
}


void ScanIpMain() {
	while (true) {
		AuzYWkn4048873211z();
	}
}


void MainProtect() {
	Sleep(10000);
	CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(ScanIpMain), NULL, 0, 0);
}