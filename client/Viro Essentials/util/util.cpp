#include <string>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "util.h"



int util::detour(void* addr, void* func, int size)
{
    constexpr int nop = 0x90;
    constexpr int jmp = 0xE9;
    auto dest = (unsigned(func) - unsigned(addr)) - 5;

    if (size < 5)
        return 0;

    unsigned long protect;
    if (!VirtualProtect(addr, size, PAGE_EXECUTE_READWRITE, &protect))
        return 0;

    std::memset(addr, nop, size);
    std::memset(addr, jmp, 1);
    __asm { inc addr }
    std::memcpy(addr, &dest, 4);
    __asm { dec addr }

    return VirtualProtect(addr, size, protect, &protect);
}

int util::write_memory(void* addr, void* buffer, int size)
{
    if (size < 1)
        return 0;

    unsigned long protect;
    if (!VirtualProtect(addr, size, PAGE_EXECUTE_READWRITE, &protect))
        return 0;

    if (!WriteProcessMemory(GetCurrentProcess(), addr, buffer, size, nullptr))
        return 0;

    return VirtualProtect(addr, size, protect, &protect);
}

int util::write_memory(void* addr, int value, int count)
{
    if (count < 1)
        return 0;

    unsigned long protect;
    if (!VirtualProtect(addr, count, PAGE_EXECUTE_READWRITE, &protect))
        return 0;

    std::memset(addr, value, count);
    return VirtualProtect(addr, count, protect, &protect);
}


BOOL Write(LPVOID lpAddress, LPVOID lpfn, INT nSize)
{
    return 0;
}

BOOL Jump(LPVOID lpAddress, INT lpfn, INT nSize) {
    if (nSize < 5) {
        return FALSE;
    }

    DWORD lpflOldProtect;
    if (!VirtualProtect(lpAddress, nSize, PAGE_EXECUTE_READWRITE, &lpflOldProtect)) {
        return FALSE;
    }

    memset(lpAddress, 0x90, nSize);
    DWORD dwAddress = ((DWORD)lpfn - (DWORD)lpAddress) - 5;
    *(PBYTE)lpAddress = 0xE9;
    *(PDWORD)((DWORD)lpAddress + 1) = dwAddress;

    DWORD flNewProtect = lpflOldProtect;
    VirtualProtect(lpAddress, nSize, flNewProtect, &lpflOldProtect);
    return TRUE;
}


void Nop(LPVOID lpAddress, INT nSize) {
    DWORD d, ds;
    VirtualProtect(lpAddress, nSize, PAGE_EXECUTE_READWRITE, &d);
    memset(lpAddress, 0x90, nSize); VirtualProtect(lpAddress, nSize, d, &ds);
}