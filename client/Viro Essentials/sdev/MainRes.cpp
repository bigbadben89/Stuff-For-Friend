#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"

DWORD orderNewResReturn = 0x00521586;
__declspec(dllexport) _declspec(naked) void orderNewRes() {
	_asm {
		mov dword ptr ds:[0x022B03D8],20
		jmp orderNewResReturn 
	}
}
DWORD renderOptionRessLoginReturn = 0x0051AF01;
__declspec(dllexport) _declspec(naked) void renderOptionRessLogin() {
	_asm {
		cmp dword ptr ds:[0x007AB0E8], 1366 // new res
		je is1366
		cmp dword ptr ds:[0x007AB0E8], 1400 // new res
		je is1400

		cmp dword ptr ds:[0x007AB0E8],3440
		je is3440

		cmp dword ptr ds:[0x007AB0E8] , 3840 // new res
		je isCheck3840
		cmp dword ptr ds : [0x007AB0E8] , 2560 // new res
		je isCheck2560


	
		mov dword ptr ds:[0x022B03D8], eax
		jmp renderOptionRessLoginReturn

			is1366 :
		mov dword ptr ds:[0x022B03D8], 14
			jmp renderOptionRessLoginReturn

			is1400 :
		mov dword ptr ds:[0x022B03F0], 15
			jmp renderOptionRessLoginReturn

			is3840 :
		mov dword ptr ds:[0x022B0408],19
			jmp renderOptionRessLoginReturn

			is2560 :
		mov dword ptr ds : [0x022B0420] , 16
			jmp renderOptionRessLoginReturn

			is2560x1440 :
		mov dword ptr ds : [0x22B0438] , 17
			jmp renderOptionRessLoginReturn

			is3840x1080 :
		mov dword ptr ds : [0x22B0450] ,18
			jmp renderOptionRessLoginReturn


			isCheck3840:
			cmp dword ptr ds : [0x007AB0E8 + 04] , 1080 // new res
			je is3840x1080
			jmp is3840


			isCheck2560:
			cmp dword ptr ds : [0x007AB0E8 + 04] , 1440 // new res
			je is2560x1440
			jmp is2560

			is3440:
			mov dword ptr ds : [0x22B0468] , 20
			jmp renderOptionRessLoginReturn
	}
}


DWORD renderOptionRessLoginReturn2 = 0x0051AEDB;
__declspec(dllexport) _declspec(naked) void renderOptionRessLogin2() {
	_asm {
		cmp dword ptr ds : [0x007AB0E8] , 1366 // new res
		je is1366
		cmp dword ptr ds : [0x007AB0E8] , 1400 // new res
		je is1400
		cmp dword ptr ds : [0x007AB0E8] , 3440 // new res
		je is3440
		cmp dword ptr ds : [0x007AB0E8] , 3840 // new res
		je isCheck3840
		cmp dword ptr ds : [0x007AB0E8] , 2560 // new res
		je isCheck2560

		mov dword ptr ds : [0x022B0224] , eax
		jmp renderOptionRessLoginReturn2

		is1366 :
		mov dword ptr ds : [0x022B0224] , 14
		jmp renderOptionRessLoginReturn2

		is1400 :
		mov dword ptr ds : [0x022B0224] , 15
		jmp renderOptionRessLoginReturn2

		is3440 :
		mov dword ptr ds : [0x022B0224] , 20
		jmp renderOptionRessLoginReturn2

		is3840 :
		mov dword ptr ds : [0x022B0224] , 19
		jmp renderOptionRessLoginReturn2

		is2560:
		mov dword ptr ds : [0x022B0224] , 16
		jmp renderOptionRessLoginReturn2


		is2560x1440:
		mov dword ptr ds : [0x022B0224] , 17
		jmp renderOptionRessLoginReturn2

		is3840x1080:
		mov dword ptr ds : [0x022B0224] , 18
		jmp renderOptionRessLoginReturn2


		isCheck3840 :
		cmp dword ptr ds : [0x007AB0E8 + 04] , 1080 // new res
		je is3840x1080
		jmp is3840


		isCheck2560 :
		cmp dword ptr ds : [0x007AB0E8 + 04] , 1440 // new res
		je is2560x1440
		jmp is2560

        
	}
}

LPCSTR is1366 = "1366x768";
LPCSTR is3440 = "3440x1440";
LPCSTR is1400 = "1400x900";
LPCSTR is3840 = "3840x2160";
LPCSTR is3840x1080 = "3840x1080";
LPCSTR is2560 = "2560x1080";
LPCSTR is2560x1440 = "2560x1440";
DWORD renderNewResReturn = 0x0051E869;
DWORD isContinueAddrJmp = 0x0051E872;
__declspec(dllexport) _declspec(naked) void renderNewRes() {
	_asm {
		mov dword ptr ds:[0x022B03D8],14
		mov dword ptr ds:[0x022B03F0],15
		mov dword ptr ds:[0x022B0408],16
		mov dword ptr ds:[0x022B0420],17
		mov dword ptr ds:[0x022B0438],18
		mov dword ptr ds:[0x022B0450],19
		mov dword ptr ds:[0x022B0468],20
		pushad
	    mov eax,dword ptr ds:[is1366]
		lea edi,[eax]
		mov esi, 0x022B03DC

		copy_loop:
		mov al, [edi]
		mov [esi], al
		inc edi
		inc esi
		cmp byte ptr ds:[edi], 0
		jne copy_loop
		mov eax,dword ptr ds:[is1400]
		lea edi, [eax]
		mov esi, 0x022B03F4
		loop_1400 :
		mov al, [edi]
		mov [esi], al
		inc edi
		inc esi
		cmp byte ptr ds:[edi], 0
		jne loop_1400


		mov eax, dword ptr ds : [is3840]
		lea edi, [eax]
		mov esi, 0x022B0454 //22B03FC
		loop_3840:
		mov al, [edi]
		mov[esi], al
		inc edi
		inc esi
		cmp byte ptr ds:[edi],0
		jne loop_3840

		mov eax, dword ptr ds : [is3840x1080]
		lea edi, [eax]
		mov esi, 0x022B043C //022B0414
		loop_3840x1080:
		mov al, [edi]
		mov[esi], al
		inc edi
		inc esi
		cmp byte ptr ds : [edi] , 0
		jne loop_3840x1080

		mov eax, dword ptr ds : [is2560]
		lea edi, [eax]
		mov esi, 0x22B040C//22B03FC //022B042C
		loop_2560:
		mov al, [edi]
		mov[esi], al
		inc edi
		inc esi
		cmp byte ptr ds:[edi],0
		jne loop_2560

		mov eax, dword ptr ds : [is2560x1440]
		lea edi, [eax]
		mov esi, 0x022B0424 //022B0414 //022B0444
		loop_2560x1440:
		mov al, [edi]
		mov[esi], al
		inc edi
		inc esi
		cmp byte ptr ds : [edi] , 0
		jne loop_2560x1440

		mov eax, dword ptr ds : [is3440]
		lea edi, [eax]
		mov esi, 0x022B046C //022B0414 //022B0444
		loop_3440x1440 :
		mov al, [edi]
		mov[esi], al
		inc edi
		inc esi
		cmp byte ptr ds : [edi] , 0
		jne loop_3440x1440
		popad


		originalcode:
		cmp dword ptr ds:[edx], edi
		je continue_addr
		inc eax
		jmp renderNewResReturn 


		continue_addr:
		jmp isContinueAddrJmp
	}
}

DWORD alterLimitResReturn = 0x0051E84F;
__declspec(dllexport) _declspec(naked) void alterLimitRes() {
	_asm {
		mov dword ptr ds:[0x007ADEB4],21

		mov ecx, dword ptr ds:[0x007ADEB4]
		jmp alterLimitResReturn 
	}
}
LPCSTR is1366ini = "1366";
LPCSTR is1400ini = "1400";
LPCSTR is900ini = "900";
LPCSTR is3840ini = "3840";
LPCSTR is2160ini = "2160";
LPCSTR is2560ini = "2560";
LPCSTR is1440ini = "1440";
LPCSTR is1080ini = "1080";
LPCSTR is3440ini = "3440";

DWORD interfaceContinue = 0x0051B351;
DWORD setNewResReturn = 0x0051B314;
DWORD return_addr = 0x0051B696;
__declspec(dllexport) _declspec(naked) void setNewRes() {
	_asm {

		cmp eax,14
		je putNewRes
		cmp eax,15
		je put1400Res
		cmp eax,16
		je put2560Res
		cmp eax,17
		je put2560x1440Res
		cmp eax,18
		je put3840x1080Res
		cmp eax,19
		je put3840Res
		cmp eax,20
		je put3440Res


		cmp eax, 0x0D
		ja return_jmp
		jmp setNewResReturn 
	

		putNewRes :
		push 0x07C0720
		push [is1366ini]
		push 0x0746E30
		push 0x0746E38
		call esi
		push 0x07C0720
		push 0x0752374
		push 0x0746E28
		push 0x0746E38
		call esi
		mov eax, 0x00000300
		mov ecx, 1366
		jmp interfaceContinue


		put1400Res :
		push 0x07C0720
		push [is1400ini]
		push 0x0746E30
		push 0x0746E38
		call esi
		push 0x07C0720
		push [is900ini]
		push 0x0746E28
		push 0x0746E38
		call esi
		mov eax, 900
		mov ecx, 1400
		jmp interfaceContinue

		put3840Res :
		push 0x07C0720
		push [is3840ini]
		push 0x0746E30
		push 0x0746E38
		call esi
		push 0x07C0720
		push [is2160ini]
		push 0x0746E28
		push 0x0746E38
		call esi
		mov eax, 2160
		mov ecx, 3840
		jmp interfaceContinue

		put3840x1080Res :
		push 0x07C0720
		push [is3840ini]
		push 0x0746E30
		push 0x0746E38
		call esi
		push 0x07C0720
		push [is1080ini]
		push 0x0746E28
		push 0x0746E38
		call esi
		mov eax, 1080
		mov ecx, 3840
		jmp interfaceContinue


		put2560Res :
		push 0x07C0720
		push [is2560ini]
		push 0x0746E30
		push 0x0746E38
		call esi
		push 0x07C0720
		push [is1080ini]
		push 0x0746E28
		push 0x0746E38
		call esi
		mov eax, 1080
		mov ecx, 2560
		jmp interfaceContinue


		put2560x1440Res:
		push 0x07C0720
		push [is2560ini]
		push 0x0746E30
		push 0x0746E38
		call esi
		push 0x07C0720
		push [is1440ini]
		push 0x0746E28
		push 0x0746E38
		call esi
		mov eax, 1440
		mov ecx, 2560
		jmp interfaceContinue

		put3440Res:
		push 0x07C0720
		push [is3440ini]
		push 0x0746E30
		push 0x0746E38
		call esi
		push 0x07C0720
		push [is1440ini]
		push 0x0746E28
		push 0x0746E38
		call esi
		mov eax, 1440
		mov ecx, 3440
		jmp interfaceContinue

		return_jmp:
		jmp return_jmp
	}
}

DWORD is1400addr = 0x0054F7C1;
DWORD is1366addr = 0x0054F849;
DWORD is3840addr = 0x0054F894;
DWORD isOriginaladdr = 0x0054F849;
DWORD setAdjustInterfaceReturn = 0x0054F779;
__declspec(dllexport) _declspec(naked) void setAdjustInterface() {
	_asm {
		cmp eax, 0x0E
		je is1366jmp
		cmp eax, 0x0F
		je is1400jmp
		cmp eax,0x10
		je is3840jmp
		cmp eax,0x11
		je is3840jmp
		cmp eax, 0x12
		je is3840jmp
		cmp eax, 0x13
		je is3840jmp
		cmp eax, 0x14
		je is3840jmp
		cmp eax, 0x15
		je is3840jmp

		cmp eax, 0x0D
		ja isOriginaljmp
		jmp setAdjustInterfaceReturn

		is1400jmp:
		jmp is1400addr

		is1366jmp:
		jmp is1366addr 

		is3840jmp:
		jmp is3840addr

		isOriginaljmp:
		jmp isOriginaladdr
	}
}


DWORD is1366_addr = 0x0054F2AA;
DWORD is1400_addr = 0x0054F3BC;
DWORD is3840_addr = 0x0054F2F5;
DWORD isOriginal_addr = 0x0054F59B;
DWORD setAdjustInterface2Return = 0x0054F1DA;
__declspec(dllexport) _declspec(naked) void setAdjustInterface2() {
	_asm {
		cmp eax, 0x0E
		je is1366jmp
		cmp eax, 0x0F
		je is1400jmp
	    cmp eax,0x10
		je is3840jmp
		cmp eax, 0x11
		je is3840jmp
		cmp eax, 0x12
		je is3840jmp
		cmp eax, 0x13
		je is3840jmp
		cmp eax, 0x14
		je is3840jmp
		cmp eax, 0x15
		je is3840jmp

		originalcode:
		cmp eax, 0x0D
		ja isOriginal
		jmp setAdjustInterface2Return

		is1366jmp:
		jmp is1366_addr

		is1400jmp:
		jmp is1400_addr

		is3840jmp:
		jmp is3840_addr

		isOriginal:
		jmp isOriginal_addr
	}
}



DWORD is1366_addr2 = 0x004959B6;
DWORD is1400_addr2 = 0x00495EC0;
DWORD is3840_addr2 = 0x00495EC0;
DWORD isOriginal_addr2 = 0x0049650D;
DWORD setAdjustInterface3Return = 0x004954EA;
__declspec(dllexport) _declspec(naked) void setAdjustInterface3() {
	_asm {
		cmp eax, 0x0E
		je is1366jmp
		cmp eax, 0x0F
		je is1400jmp
		cmp eax, 0x10
		je is1400jmp
		cmp eax, 0x11
		je is1400jmp
		cmp eax, 0x12
		je is1400jmp
		cmp eax, 0x13
		je is1400jmp
		cmp eax, 0x14
		je is1400jmp
		cmp eax, 0x15
		je is1400jmp

		originalcode :
		cmp eax, 0x0D
		ja isOriginal
		jmp setAdjustInterface3Return


		is1366jmp:
		push ebx
		push ebp
		push edi
		jmp is1366_addr2

		is1400jmp :
		push ebx
		push ebp
		push edi
		jmp is1400_addr2

		isOriginal:
		jmp isOriginal_addr2
	}
}


DWORD is1366_addr3 = 0x00494D6E;
DWORD is1400_addr3 = 0x00494D80;
DWORD isOriginal_addr3 = 0x00494D90;
DWORD setAdjustInterface4Return = 0x00494D52;
__declspec(dllexport) _declspec(naked) void setAdjustInterface4() {
	_asm {
		cmp eax, 0x0E
		je is1366jmp
		cmp eax, 0x0F
		je is1400jmp
		cmp eax, 0x10
		je is1400jmp
		cmp eax, 0x11
		je is1400jmp
		cmp eax, 0x12
		je is1400jmp
		cmp eax, 0x13
		je is1400jmp
		cmp eax, 0x14
		je is1400jmp
		cmp eax, 0x15
		je is1400jmp

		originalcode :
		cmp eax, 0x0D
		ja isOriginal
		jmp setAdjustInterface4Return

		is1366jmp:
		jmp is1366_addr3

		is1400jmp:
		jmp is1400_addr3

		isOriginal:
		jmp isOriginal_addr3
	}
}



DWORD is1366_addr4 = 0x00493B95;
DWORD is1400_addr4 = 0x004942FE;
DWORD isOriginal_addr4 = 0x00494A82;
DWORD setAdjustInterface5Return = 0x00493450;
__declspec(dllexport) _declspec(naked) void setAdjustInterface5() {
	_asm {
		cmp eax,0x0E
		je is1366jmp
		cmp eax,0x0F
		je is1400jmp
		cmp eax,0x10
		je is1400jmp
		cmp eax, 0x11
		je is1400jmp
		cmp eax, 0x12
		je is1400jmp
		cmp eax, 0x13
		je is1400jmp
		cmp eax, 0x14
		je is1400jmp
		cmp eax, 0x15
		je is1400jmp


		originalcode :
		cmp eax,0x0D
		ja isOriginal
		jmp setAdjustInterface5Return


		is1366jmp :
		jmp is1366_addr4

		is1400jmp :
		jmp is1400_addr4

		isOriginal :
		jmp isOriginal_addr4
	}
}

DWORD alterLimitOkReturn = 0x0051D742;
__declspec(dllexport) _declspec(naked) void alterLimitOk() {
	_asm {
		mov dword ptr ds:[0x07ADEB4], 21
		jmp alterLimitOkReturn
	}
}

DWORD isSaveResReturn = 0x0040659B;
DWORD isSaveContinue = 0x00406774;
_declspec(dllexport) _declspec(naked) void isSaveRes() {
	_asm {
     cmp ecx,1366
	 je isSave1366
	 cmp ecx,1400
	 je isSave1400
	 cmp ecx,3440
	 je isSave3440
	 cmp ecx,3840
	 je checkWhatSize
	 cmp ecx,2560
	 je checkWhatSize2560
	 jmp originalcode

	 checkWhatSize:
	 cmp eax,2160
	 je isSave3840
	 mov dword ptr ds : [0x007C0DFC] , 18
	 jmp isSaveContinue

	 checkWhatSize2560:
	 cmp eax,1440
	 je isSave2560x1440
     mov dword ptr ds : [0x007C0DFC] , 16
	 jmp isSaveContinue
	 

	 isSave1366:
	 mov dword ptr ds:[0x007C0DFC],14
	 jmp isSaveContinue

	 isSave3440:
	 mov dword ptr ds:[0x007C0DFC],20
	 jmp isSaveContinue

	 isSave1400 :
	 mov dword ptr ds:[0x007C0DFC],15
	 jmp isSaveContinue

	 isSave3840:
	 mov dword ptr ds:[0x007C0DFC],19
	 jmp isSaveContinue

     isSave2560x1440:
	 mov dword ptr ds : [0x007C0DFC] , 17
     jmp isSaveContinue

	originalcode:
	mov dword ptr ds:[0x007C0DFC], 0000001
	jmp isSaveResReturn
	}
}
DWORD isGamma = 0;
DWORD isSetNewPointerGammaReturn = 0x0052156C;
_declspec(naked) void isSetNewPointerGamma() {
	_asm {
		cmp eax, dword ptr ds : isGamma
		jmp isSetNewPointerGammaReturn
	}
}

DWORD isSetNewPointerGammaReturn2 = 0x005215BE;
_declspec(naked) void isSetNewPointerGamma2() {
	_asm {
		mov dword ptr ds:[isGamma], eax
		jmp isSetNewPointerGammaReturn2
	}
}

DWORD isSetNewPointerGammaReturn3 = 0x0051B282;
_declspec(naked) void isSetNewPointerGamma3() {
	_asm {
		mov ecx, dword ptr ds : isGamma
		jmp isSetNewPointerGammaReturn3
	}
}


DWORD isDistance = 0;
DWORD isSetNewPointerDistanceReturn = 0x0052156C;
_declspec(naked) void isSetNewPointerDistance() {
	_asm {
		cmp eax, dword ptr ds : isDistance
		jmp isSetNewPointerDistanceReturn

	}
}

DWORD isSetNewPointerDistanceReturn2 = 0x00521586;
_declspec(naked) void isSetNewPointerDistance2() {
	_asm {
		mov dword ptr ds : [isDistance] , eax
		jmp isSetNewPointerDistanceReturn2

	}
}

DWORD isSetNewPointerDistanceReturn3 = 0x0051B28E;
_declspec(naked) void isSetNewPointerDistance3() {
	_asm {
		mov edx, dword ptr ds : isDistance
		jmp isSetNewPointerDistanceReturn3

	}
}

DWORD isSetNewPointerDistanceReturn4 = 0x0051AF01;
_declspec(naked) void isSetNewPointerDistance4() {
	_asm {
		mov dword ptr ds : [isDistance] , eax
		jmp isSetNewPointerDistanceReturn4

	}
}
float isFloatValue = 0.0f;

DWORD isSetNewPointerFloatReturn = 0x005223BF;
_declspec(naked) void isSetNewPointerFloat() {
	_asm {
		fstp dword ptr ds : [isFloatValue]
		jmp isSetNewPointerFloatReturn
	}
}

DWORD isSetNewPointerFloatReturn2 = 0x005224D3;
_declspec(naked) void isSetNewPointerFloat2() {
	_asm {
		fld dword ptr ds : [isFloatValue]
		jmp isSetNewPointerFloatReturn2
	}
}

DWORD isSetNewPointerFloatReturn3 = 0x005224EE;
_declspec(naked) void isSetNewPointerFloat3() {
	_asm {
		fstp dword ptr ds : [isFloatValue]
		jmp isSetNewPointerFloatReturn3
	}
}

DWORD isSetNewPointerFloatReturn4 = 0x005224F6;
_declspec(naked) void isSetNewPointerFloat4() {
	_asm {
		fcom dword ptr ds : [isFloatValue]
		jmp isSetNewPointerFloatReturn4
	}
}

DWORD isSetNewPointerFloatReturn5 = 0x0052250D;
_declspec(naked) void isSetNewPointerFloat5() {
	_asm {
		fld dword ptr ds : [isFloatValue]
		jmp isSetNewPointerFloatReturn5
	}
}

void hook::mainRes() {
	util::detour((PVOID)0x00406591, isSaveRes, 10);
	util::detour((PVOID)0x00521581, orderNewRes, 5);
	util::detour((PVOID)0x0051AEFC, renderOptionRessLogin, 5);
	util::detour((PVOID)0x0051AED6, renderOptionRessLogin2, 5);
	util::detour((PVOID)0x0051E864, renderNewRes, 5);
	util::detour((PVOID)0x0051E849, alterLimitRes, 6);
	util::detour((PVOID)0x0051B30B, setNewRes, 9);
	util::detour((PVOID)0x0054F770, setAdjustInterface, 9);
	util::detour((PVOID)0x0054F1D1, setAdjustInterface2, 9);
	util::detour((PVOID)0x004954E1, setAdjustInterface3, 9);
	util::detour((PVOID)0x00494D4D, setAdjustInterface4, 5);
	util::detour((PVOID)0x00493447, setAdjustInterface5, 9);
	util::detour((PVOID)0x0051D738, alterLimitOk, 10);
	util::detour((PVOID)0x00521566, isSetNewPointerGamma, 6);
	util::detour((PVOID)0x005215B9, isSetNewPointerGamma2, 5);
	util::detour((PVOID)0x0051B27C, isSetNewPointerGamma3, 6);
	util::detour((PVOID)0x00521566, isSetNewPointerDistance, 6);
	util::detour((PVOID)0x00521581, isSetNewPointerDistance2, 5);
	util::detour((PVOID)0x0051B288, isSetNewPointerDistance3, 6);
	util::detour((PVOID)0x0051AEFC, isSetNewPointerDistance4, 5);
	util::detour((PVOID)0x005223B9, isSetNewPointerFloat, 6);
	util::detour((PVOID)0x005224CD, isSetNewPointerFloat2, 6);
	util::detour((PVOID)0x005224E8, isSetNewPointerFloat3, 6);
	util::detour((PVOID)0x005224F0, isSetNewPointerFloat4, 6);
	util::detour((PVOID)0x00522507, isSetNewPointerFloat5, 6);
}