#include <windows.h>
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"

char szLocationX[255];
char szLocationY[255];
char newLocationX[255];
char newLocationY[255];

int LocationX;
int LocationY;
int oldLocationX;
int oldLocationY;
int MouseX;
int MouseY;

DWORD mouseReturn = 0x004D73F8;
DWORD newlocationReturn = 0x004D7509;

void LocationConfig()
{
	GetPrivateProfileStringA("BUFF", "LOCATION_X", "", szLocationX, 255, ".\\config.ini");
	GetPrivateProfileStringA("BUFF", "LOCATION_Y", "", szLocationY, 255, ".\\config.ini");
	LocationX = atoi(szLocationX);
	LocationY = atoi(szLocationY);
	oldLocationX = atoi(szLocationX);
	oldLocationY = atoi(szLocationY);
}

void SaveLocation()
{
	_itoa_s(LocationX, newLocationX, 10);
	_itoa_s(LocationY, newLocationY, 10);

	if (oldLocationX != LocationX)
	{
		WritePrivateProfileStringA("BUFF", "LOCATION_X", newLocationX, ".\\config.ini");
		WritePrivateProfileStringA("BUFF", "LOCATION_Y", newLocationY, ".\\config.ini");
	}
}

void __declspec(naked) Mouse()
{
	_asm
	{
		push ebx
		mov ebx, 0x7C3C0C
		mov ebx, [ebx]
		mov[MouseX], ebx
		mov ebx, 0x7C3C10
		mov ebx, [ebx]
		mov[MouseY], ebx
		pop ebx
		mov edi, [LocationX]
		mov ebx, [LocationY]
		jmp mouseReturn
	}
}

void __declspec(naked) GetLocation()
{
	_asm
	{
		push esi
		mov esi, GetAsyncKeyState
		push edi
		mov edi, 0x008000
		lea eax, [ecx + 0x00]
		locationReturn2:
		push 0x12
			call esi
			test di, ax
			je locationReturn2
			push 0x02
			call esi
			test di, ax
			je locationReturn2
			mov eax, [MouseX]
			mov[LocationX], eax
			mov eax, [MouseY]
			mov[LocationY], eax
			jmp locationReturn2
	}
}

void __declspec(naked) NewLocation()
{
	_asm
	{
		mov edi, [LocationX]
		jmp newlocationReturn
	}
}

void UpdateLocations()
{
	while (true)
	{
		SaveLocation();
		Sleep(1000);
	}
}

void IconLocations()
{
	SaveLocation();
	LocationConfig();
	util::detour((LPVOID)0x004D73ED, Mouse, 11);
	util::detour((LPVOID)0x004D7503, NewLocation, 6);
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)GetLocation, NULL, 0, NULL);
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)UpdateLocations, NULL, 0, NULL);
}