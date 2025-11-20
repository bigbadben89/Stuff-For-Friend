#include <windows.h>
#include "encrypt.h"
#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
#include <tlhelp32.h>
#include <iostream>
#include <vector>
#include <future>
#include <thread>
#include <chrono>

using namespace std;
void* g_GetTickCountAddress = nullptr;
string globalEncryptKey = "AuWknJhToP";



// Definição da função MessageBoxTimeout
typedef int (WINAPI* MBT)(HWND, LPCWSTR, LPCWSTR, UINT, WORD, DWORD);

int MessageBoxTimeout(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType, WORD wLanguageId, DWORD dwMilliseconds) {
	HMODULE hUser32 = LoadLibraryW(L"user32.dll");
	if (!hUser32) {
		return 0;
	}
	MBT pMessageBoxTimeout = (MBT)GetProcAddress(hUser32, "MessageBoxTimeoutW");
	int result = 0;
	if (pMessageBoxTimeout) {
		result = pMessageBoxTimeout(hWnd, lpText, lpCaption, uType, wLanguageId, dwMilliseconds);
	}
	FreeLibrary(hUser32);
	return result;
}

// Função para obter o ID do processo
DWORD GetProcessID(const wchar_t* processName) {
	DWORD processID = 0;
	HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (snap != INVALID_HANDLE_VALUE) {
		PROCESSENTRY32W pe; // Usar a versão Unicode de PROCESSENTRY32
		pe.dwSize = sizeof(pe);
		if (Process32FirstW(snap, &pe)) { // Usar a versão Unicode de Process32First
			do {
				if (_wcsicmp(pe.szExeFile, processName) == 0) {
					processID = pe.th32ProcessID;
					break;
				}
			} while (Process32NextW(snap, &pe)); // Usar a versão Unicode de Process32Next
		}
	}
	CloseHandle(snap);
	return processID;
}


bool ReadMemory(HANDLE hProcess, uintptr_t startAddress, uintptr_t endAddress, std::vector<BYTE>& buffer) {
	SIZE_T bytesRead;
	return ReadProcessMemory(hProcess, (LPCVOID)startAddress, buffer.data(), buffer.size(), &bytesRead);
}

bool IsExcludedAddress(uintptr_t address) {
	static std::vector<uintptr_t> excludedAddresses = { 0x414B13, 0x414B67, 0x4137A2, 0x413847, 0x41389B};
	return std::find(excludedAddresses.begin(), excludedAddresses.end(), address) != excludedAddresses.end();
}

bool CompareMemory(const std::vector<BYTE>& oldBuffer, const std::vector<BYTE>& newBuffer, uintptr_t startAddress, HANDLE hProcess) {
	for (size_t i = 0; i < oldBuffer.size(); ++i) {
		uintptr_t currentAddress = startAddress + i;

		if (IsExcludedAddress(currentAddress)) {
			continue;  // Skip the comparison for excluded addresses
		}

		if (oldBuffer[i] != newBuffer[i]) {
			MessageBoxTimeout(NULL, L"Hasta la vista, Bitch! :*", L"Anti Cheat 1.0", MB_OK | MB_ICONWARNING, 0, 3000);
			TerminateProcess(hProcess, 0);
			return true;
		}
	}
	return false;
}

int AntiCheatMain() {
	const wchar_t* processName = L"game.exe";
	DWORD processID = GetProcessID(processName);

	if (processID == 0) {
		ExitProcess(0);
		return 1;
	}

	HANDLE hProcess = OpenProcess(PROCESS_VM_READ | PROCESS_TERMINATE, FALSE, processID);
	if (!hProcess) {
		return 1;
	}

	const uintptr_t startAddress = 0x00401000;
	const uintptr_t endAddress = 0x005FFFFF;
	std::vector<BYTE> oldBuffer(endAddress - startAddress + 1);
	std::vector<BYTE> newBuffer(endAddress - startAddress + 1);

	if (!ReadMemory(hProcess, startAddress, endAddress, oldBuffer)) {
		CloseHandle(hProcess);
		return 1;
	}

	while (true) {
		std::this_thread::sleep_for(std::chrono::seconds(1));

		if (!ReadMemory(hProcess, startAddress, endAddress, newBuffer)) {
			CloseHandle(hProcess);
			return 1;
		}

		if (CompareMemory(oldBuffer, newBuffer, startAddress, hProcess)) {
			break;
		}

		oldBuffer = newBuffer;
	}

	CloseHandle(hProcess);
	std::this_thread::sleep_for(std::chrono::seconds(5));
	return 0;
}

const std::string encryptionKey = "TzyATzSTyPokt"; 
const std::vector<std::string> encryptedSuspiciousStrings = {
	encrypt("Spam Trade", encryptionKey),
	encrypt("WallClimb", encryptionKey),
	encrypt("See Item ID", encryptionKey),
	encrypt("Skill Cut", encryptionKey),
	encrypt("No Swin", encryptionKey),
	encrypt("Jack", encryptionKey),
	encrypt("Shaiya Hacker Ep 6", encryptionKey),
	encrypt("Hit On Safe Zone", encryptionKey),
	encrypt("Wall Jack", encryptionKey),
	encrypt("Range jack", encryptionKey),
	encrypt("Speed Jack (Anti-Debuff", encryptionKey),
	encrypt("See Ranger/Assasin on Stealth", encryptionKey),
	encrypt("Mount in Dungeon", encryptionKey),
	encrypt("No Land Obstacle", encryptionKey),
	encrypt("HACK", encryptionKey),
	encrypt("debugger", encryptionKey),
	encrypt("Debugger", encryptionKey),
	encrypt("DEBUGGER", encryptionKey),
	encrypt("Attach", encryptionKey),
	encrypt("Hack", encryptionKey),
	encrypt("hack", encryptionKey),
	encrypt("HACKER", encryptionKey),
	encrypt("Hacker", encryptionKey),
	encrypt("hacker", encryptionKey),
	encrypt("INJECT", encryptionKey),
	encrypt("Inject", encryptionKey),
	encrypt("inject", encryptionKey),
	encrypt("Delite", encryptionKey),
	encrypt("fck stop", encryptionKey),
	encrypt("The HounD", encryptionKey),
	encrypt("See Item ID", encryptionKey),
	encrypt("Cam Limit", encryptionKey),
	encrypt("Hit On Safe Zone", encryptionKey),
	encrypt("Attach debugger to process", encryptionKey),
	encrypt("Add Address Manually", encryptionKey),
	encrypt("Token", encryptionKey),
	encrypt("Start address", encryptionKey),
	encrypt("Memory Viewer", encryptionKey),
	encrypt("Undo Scan", encryptionKey),
	encrypt("CopyOnWrite", encryptionKey),
	encrypt("Fast Scan", encryptionKey),
	encrypt("Memory Scan Options", encryptionKey),
	encrypt("Select a process to open", encryptionKey),
	encrypt("Create hotkey", encryptionKey),
	encrypt("Set hotkeys", encryptionKey),
	encrypt("Set/Change hotkey", encryptionKey),
	encrypt("UndoScan", encryptionKey),
	encrypt("Memory View", encryptionKey),
	encrypt("First Scan", encryptionKey),
	encrypt("Process List", encryptionKey),
	encrypt("debug", encryptionKey)
};

// Função para terminar um processo pelo nome
bool TerminateProcessByName(const wchar_t* filename) {
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnap == INVALID_HANDLE_VALUE) {
		MessageBoxA(NULL, ("CreateToolhelp32Snapshot failed. Error: " + std::to_string(GetLastError())).c_str(), "Error", MB_OK | MB_ICONERROR);
		return false;
	}

	PROCESSENTRY32W pe;
	pe.dwSize = sizeof(PROCESSENTRY32W);

	if (Process32FirstW(hSnap, &pe)) {
		do {
			if (wcscmp(pe.szExeFile, filename) == 0) {
				HANDLE hProc = OpenProcess(PROCESS_TERMINATE, FALSE, pe.th32ProcessID);
				if (hProc != NULL) {
					TerminateProcess(hProc, 0);
					CloseHandle(hProc);
					CloseHandle(hSnap);
					return true;
				}
				else {
					MessageBoxA(NULL, ("OpenProcess failed. Error: " + std::to_string(GetLastError())).c_str(), "Error", MB_OK | MB_ICONERROR);
				}
			}
		} while (Process32NextW(hSnap, &pe));
	}
	else {
		MessageBoxA(NULL, ("Process32FirstW failed. Error: " + std::to_string(GetLastError())).c_str(), "Error", MB_OK | MB_ICONERROR);
	}

	CloseHandle(hSnap);
	return false;
}

// Função de callback para enumerar janelas
BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
	wchar_t title[256];
	if (GetWindowTextW(hwnd, title, sizeof(title) / sizeof(wchar_t))) {
		for (const auto& encryptedStr : encryptedSuspiciousStrings) {
			std::string decryptedStr = decrypt(encryptedStr, encryptionKey);
			std::wstring decryptedWStr(decryptedStr.begin(), decryptedStr.end());
			if (wcsstr(title, decryptedWStr.c_str())) {
				TerminateProcessByName(L"game.exe");
				return FALSE; // Parar a enumeração
			}
		}
	}
	return TRUE; // Continuar a enumeração
}

// Função para verificar janelas
void TxtCheckWindow() {
	if (!EnumWindows(EnumWindowsProc, 0)) {
		MessageBoxA(NULL, ("EnumWindows failed. Error: " + std::to_string(GetLastError())).c_str(), "Error", MB_OK | MB_ICONERROR);
	}
}

// Função de thread para verificar janelas periodicamente
DWORD WINAPI CheckWindowsThread(LPVOID lpParam) {
	while (true) {
		TxtCheckWindow();
		Sleep(1000); // Dormir por 1 segundo para reduzir o uso da CPU
	}
	return 0;
}

// Função anti-debugging simples
void AntiDebugging() {
	if (IsDebuggerPresent()) {
		exit(1);
	}
}

// Thread watchdog para monitorar e recriar a thread de verificação
DWORD WINAPI WatchdogThread(LPVOID lpParam) {
	HANDLE hCheckThread = NULL;

	while (true) {
		AntiDebugging(); // Verificação anti-debugging
		if (hCheckThread == NULL || WaitForSingleObject(hCheckThread, 0) == WAIT_OBJECT_0) {
			hCheckThread = CreateThread(NULL, 0, CheckWindowsThread, NULL, 0, NULL);
			if (hCheckThread == NULL) {
				MessageBoxA(NULL, ("CreateThread failed. Error: " + std::to_string(GetLastError())).c_str(), "Error", MB_OK | MB_ICONERROR);
				return 1;
			}

			if (!SetThreadPriority(hCheckThread, THREAD_PRIORITY_ABOVE_NORMAL)) {
				MessageBoxA(NULL, ("SetThreadPriority failed. Error: " + std::to_string(GetLastError())).c_str(), "Error", MB_OK | MB_ICONERROR);
			}
		}
		Sleep(1000);
	}

	return 0;
}

// Função principal para criar a thread watchdog
int mainCheckCheatEngine() {
	HANDLE hWatchdogThread = CreateThread(NULL, 0, WatchdogThread, NULL, 0, NULL);
	if (hWatchdogThread == NULL) {
		MessageBoxA(NULL, ("Failed to create watchdog thread. Error: " + std::to_string(GetLastError())).c_str(), "Error", MB_OK | MB_ICONERROR);
		return 1;
	}

	while (true) {
		Sleep(5000);
	}

	CloseHandle(hWatchdogThread);
	return 0;
}


void executeAntiCheatPeriodically() {
	while (true) {
		AntiCheatMain();
		std::this_thread::sleep_for(std::chrono::seconds(5));
	}
}


int mainAnti() {
	std::chrono::steady_clock::time_point nextRunTime = std::chrono::steady_clock::now();
	while (true) {
		auto now = std::chrono::steady_clock::now();
		if (now >= nextRunTime) {

			std::async(std::launch::async, executeAntiCheatPeriodically);


			nextRunTime = now + std::chrono::seconds(5);
		}


		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	return 0;
}

DWORD newPacketRet = 0x005EC724;
_declspec(naked) void newPacket()
{
	_asm {
		
		mov eax, 0x48A9
		jmp newPacketRet
	}
}



void GetAddressOfGetTickCount() {
	g_GetTickCountAddress = GetProcAddress(GetModuleHandleW(L"kernel32.dll"), "GetTickCount");
}

int mainCheckAddr() {
	GetAddressOfGetTickCount();

	return 0;
}

DWORD sendPacketAntiCheatReturn = 0x005EA9B8;
__declspec(dllexport) _declspec(naked) void sendPacketAntiCheat() {
	_asm {

		pushad
		mov eax,dword ptr ds: g_GetTickCountAddress
		cmp byte ptr [eax], 0x51
		popad
		jne isexitProcess

		mov[esp + 0x00001000], eax
		jmp sendPacketAntiCheatReturn

		isexitProcess :
		int 3
			ret
	}
}

__declspec(dllexport) _declspec(naked) void AuzYWkn4048873211z() {

	Sleep(10000);

	_asm {


		cmp dword ptr ds : [0x007C0DD0] , 0x312E3735
		jne crash_
		cmp dword ptr ds : [0x007C0DD4] , 0x302E3932
		jne crash_
		cmp dword ptr ds : [0x007C0DD8] , 0x0031322E
		jne crash_
		cmp dword ptr ds : [0x007C0DD8 + 4] , 0x00000000
		je return_

		crash_ :
		push 0x00
			call ExitProcess

			return_ :
		ret
	}
}



void ip_scan() {
	while (true) {
		AuzYWkn4048873211z();
	}
}

bool KillExtraProcesses(const std::string& processName) {
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnapshot == INVALID_HANDLE_VALUE) return false;

	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);
	std::vector<DWORD> pids;

	if (Process32First(hSnapshot, &pe32)) {
		do {

			std::string currentProcessName = pe32.szExeFile;

			if (processName == currentProcessName) {
				pids.push_back(pe32.th32ProcessID);
			}
		} while (Process32Next(hSnapshot, &pe32));
	}
	CloseHandle(hSnapshot);

	if (pids.size() > 1) {
		MessageBoxA(NULL, "More than one instance of game.exe detected!", "Warning", MB_OK | MB_ICONWARNING);
		for (size_t i = 1; i < pids.size(); ++i) {
			HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pids[i]);
			if (hProcess) {
				TerminateProcess(hProcess, 0);
				CloseHandle(hProcess);
			}
		}
	}
	return true;
}

int mainThreadMultiClient() {
	while (true) {
		if (!KillExtraProcesses("game.exe")) {
			MessageBoxA(NULL, "Error checking processes!", "Error", MB_OK | MB_ICONERROR);
		}
		Sleep(3000);
	}
	return 0;
}



void hook::AntiCheat() {

  CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(mainAnti), NULL, 0, 0);
  CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(mainCheckAddr), NULL, 0, 0);
  //CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(ip_scan), NULL, 0, 0);
  //util::detour((void*)0x005EC71F, newPacket, 5);
 // util::detour((PVOID)0x005EA9B1, sendPacketAntiCheat, 7);
  CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(mainCheckCheatEngine), NULL, 0, 0);
  CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(mainThreadMultiClient), NULL, 0, 0);
}