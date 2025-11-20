// dllmain.cpp : Define o ponto de entrada para o aplicativo DLL.
#include "pch.h"

extern  "C"  __declspec(dllexport) void __cdecl Main()
{


}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        Main();
        //MainProtect();
      isBossAttackedNotice();
     // ChangeAppareance();
     CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(SendPacketClient), NULL, 0, 0);
     autoBalance();
     CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(changeFacctionMain), NULL, 0, 0);
       
    
        break;
    }
    return TRUE;
}

