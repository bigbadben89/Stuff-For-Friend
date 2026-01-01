#ifndef LOCAL_RESS_HOOK_H
#define LOCAL_RESS_HOOK_H
#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define NOP 0x90

// Hook installation function
void RessLeaderandLocal();

// Utility functions
BOOL Hook(void* pAddr, void* pNAddr, int len);
BOOL Hook_2(void* pAddr, void* pNAddr, int len);
BOOL writeBytes(void* pAddr, void* value, int size);
void WriteNop(LPVOID lpAddress, INT nSize);

#endif // LOCAL_RESS_HOOK_H
