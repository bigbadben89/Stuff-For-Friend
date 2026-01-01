#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <string>
#include <algorithm>
#include "encrypt.h"
#include "util/util.h"

using namespace std;

// -------------------
// Global Encryption Key
// -------------------
string globalEncryptKey = "AuWknJhToP";

// -------------------
// Encrypted Suspicious Strings
// -------------------
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
    encrypt("Cam Limit", encryptionKey),
    encrypt("Attach debugger to process", encryptionKey),
    encrypt("Add Address Manually", encryptionKey),
    encrypt("Token", encryptionKey),
    encrypt("Start address", encryptionKey),
    encrypt("Memory Viewer", encryptionKey),
    encrypt("Undo Scan", encryptionKey),
    encrypt("CopyOnWrite", encryptionKey),
    encrypt("Fast Scan", encryptionKey),
    encrypt("ArtMoney SE v8.01", encryptionKey),
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

// -------------------
// Anti-Debugging
// -------------------
void AntiDebugging() {
    if (IsDebuggerPresent()) {
        ExitProcess(0);
    }
}

// -------------------
// Process Utilities
// -------------------
DWORD GetProcessID(const wchar_t* processName) {
    DWORD processID = 0;
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap != INVALID_HANDLE_VALUE) {
        PROCESSENTRY32W pe;
        pe.dwSize = sizeof(pe);
        if (Process32FirstW(snap, &pe)) {
            do {
                if (_wcsicmp(pe.szExeFile, processName) == 0) {
                    processID = pe.th32ProcessID;
                    break;
                }
            } while (Process32NextW(snap, &pe));
        }
    }
    CloseHandle(snap);
    return processID;
}

bool ReadMemory(HANDLE hProcess, uintptr_t startAddress, uintptr_t endAddress, std::vector<BYTE>& buffer) {
    SIZE_T bytesRead;
    return ReadProcessMemory(hProcess, (LPCVOID)startAddress, buffer.data(), buffer.size(), &bytesRead);
}

bool CompareMemory(const std::vector<BYTE>& oldBuffer, const std::vector<BYTE>& newBuffer, HANDLE hProcess) {
    for (size_t i = 0; i < oldBuffer.size(); ++i) {
        if (oldBuffer[i] != newBuffer[i]) {
            MessageBoxW(NULL, L"Detected memory modification!", L"Anti Cheat", MB_OK | MB_ICONWARNING);
            TerminateProcess(hProcess, 0);
            return true;
        }
    }
    return false;
}

// -------------------
// Anti-Cheat Memory Watchdog
// -------------------
DWORD WINAPI AntiCheatMain(LPVOID lpParam) {
    const wchar_t* processName = L"game.exe";
    DWORD processID = GetProcessID(processName);
    if (processID == 0) ExitProcess(0);

    HANDLE hProcess = OpenProcess(PROCESS_VM_READ | PROCESS_TERMINATE, FALSE, processID);
    if (!hProcess) ExitProcess(0);

    const uintptr_t startAddress = 0x00401000;
    const uintptr_t endAddress = 0x005FFFFF;
    std::vector<BYTE> oldBuffer(endAddress - startAddress + 1);
    std::vector<BYTE> newBuffer(endAddress - startAddress + 1);

    if (!ReadMemory(hProcess, startAddress, endAddress, oldBuffer)) {
        CloseHandle(hProcess);
        ExitProcess(0);
    }

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (!ReadMemory(hProcess, startAddress, endAddress, newBuffer)) {
            CloseHandle(hProcess);
            ExitProcess(0);
        }
        if (CompareMemory(oldBuffer, newBuffer, hProcess)) break;
        oldBuffer = newBuffer;
    }

    CloseHandle(hProcess);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return 0;
}

// -------------------
// Window Checking
// -------------------
bool TerminateProcessByName(const wchar_t* filename) {
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnap == INVALID_HANDLE_VALUE) return false;

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
            }
        } while (Process32NextW(hSnap, &pe));
    }
    CloseHandle(hSnap);
    return false;
}

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
    wchar_t title[256];
    if (GetWindowTextW(hwnd, title, sizeof(title) / sizeof(wchar_t))) {
        for (const auto& encryptedStr : encryptedSuspiciousStrings) {
            std::string decryptedStr = decrypt(encryptedStr, encryptionKey);
            std::wstring decryptedWStr(decryptedStr.begin(), decryptedStr.end());
            if (wcsstr(title, decryptedWStr.c_str())) {
                TerminateProcessByName(L"game.exe");
                return FALSE;
            }
        }
    }
    return TRUE;
}

DWORD WINAPI CheckWindowsThread(LPVOID lpParam) {
    while (true) {
        EnumWindows(EnumWindowsProc, 0);
        Sleep(1000);
    }
    return 0;
}

// -------------------
// IP Checking
// -------------------
__declspec(dllexport) BOOL CheckIp(std::string ip) {
    char ipGame[30];
    DWORD dwOldProtect;
    LPVOID addressToRead = (LPVOID)0x007C0DD0;
    SIZE_T sizeToRead = sizeof(ipGame);

    if (!VirtualProtect(addressToRead, sizeToRead, PAGE_READWRITE, &dwOldProtect)) return FALSE;
    if (!ReadProcessMemory(GetCurrentProcess(), addressToRead, ipGame, sizeToRead, NULL)) {
        VirtualProtect(addressToRead, sizeToRead, dwOldProtect, &dwOldProtect);
        return FALSE;
    }
    VirtualProtect(addressToRead, sizeToRead, dwOldProtect, &dwOldProtect);

    std::string decryptedIp = decrypt(ip, globalEncryptKey);
    return strcmp(ipGame, decryptedIp.c_str()) == 0;
}

__declspec(dllexport) DWORD WINAPI CheckIPThread(LPVOID lpParam) {
    Sleep(10000);
    while (true) {
        if (!CheckIp("bctcYSHc0gtR")) ExitProcess(0);
        Sleep(5000);
    }
    return 0;
}

// -------------------
// Multi-Client Prevention
// -------------------
DWORD WINAPI MultiClientThread(LPVOID lpParam) {
    while (true) {
        HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if (hSnapshot != INVALID_HANDLE_VALUE) {
            PROCESSENTRY32 pe32;
            pe32.dwSize = sizeof(PROCESSENTRY32);
            std::vector<DWORD> pids;
            if (Process32First(hSnapshot, &pe32)) {
                do {
                    if (strcmp(pe32.szExeFile, "game.exe") == 0)
                        pids.push_back(pe32.th32ProcessID);
                } while (Process32Next(hSnapshot, &pe32));
            }
            CloseHandle(hSnapshot);

            if (pids.size() > 1) {
                for (size_t i = 1; i < pids.size(); ++i) {
                    HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pids[i]);
                    if (hProcess) { TerminateProcess(hProcess, 0); CloseHandle(hProcess); }
                }
            }
        }
        Sleep(3000);
    }
    return 0;
}

// -------------------
// Initialize Anti-Cheat
// -------------------
namespace hook {
    void AntiCheat() {
        CreateThread(NULL, 0, AntiCheatMain, NULL, 0, NULL);
        CreateThread(NULL, 0, CheckWindowsThread, NULL, 0, NULL);
        CreateThread(NULL, 0, MultiClientThread, NULL, 0, NULL);
        CreateThread(NULL, 0, CheckIPThread, NULL, 0, NULL);
    }
}