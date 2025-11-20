// pch.h: esse é um arquivo de cabeçalho pré-compilado.
// Os arquivos listados a seguir são compilados somente uma vez, melhorando o desempenho dos builds futuros.
// Isso também afeta o desempenho do IntelliSense, incluindo a conclusão de código e muitos recursos de navegação de código.
// No entanto, os arquivos listados aqui serão TODOS recompilados se qualquer um deles for atualizado entre builds.
// Não adicione aqui arquivos que você atualizará com frequência, pois isso anula a vantagem de desempenho.

#ifndef PCH_H
#define PCH_H

// adicione os cabeçalhos que você deseja pré-compilar aqui
#include <sdkddkver.h>
#include <windows.h>
#include <atlstr.h>

#include <comdef.h>
#include "sysinfoapi.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring> // Para usar strcpy
#include <exception>
#include <bitset>
#include <hidusage.h>
#include <vector>
#include <typeinfo>
#include <sstream>
#pragma warning(disable : 4996)
#pragma warning(disable : 4838)




extern char isMapName[100];
extern int isMapNameFunction(int MapID);
void SendPacketClient();
void isBossAttackedNotice();
void userShape();
BOOL Hook(void* pAddr, void* pNAddr, int len = 5);
void ChangeAppareance();
void MainProtect();
extern int setFamily(int family, int job);
extern int setType(int type);
extern DWORD sendPacketView;
extern DWORD getPartyValue;
extern DWORD sendEquipament;
extern DWORD continueFuncPacket;
extern DWORD findUserByCharID;
extern int g_LastRewardOrder;
void changeFacctionMain();
void KillFeedEp5();
int getCurrentRewardOrder(int UserUID);
extern CStringW getCharName(int OrdemCount);
extern int getLastRewardOrder();
extern CStringW getCharCountryCharID(const std::string& charName);
extern CStringW getCharJob(int OrdemCount);
extern CStringW getCharFamily(int OrdemCount);
extern int resultByteCounts;
int getCurrentRewardOrder(int UserUID);
extern int selectAndSortRewardTypes(char* resultArray);
extern int selectRewardBar(int OrderID, int resultArrayReward[4]);
void SendPacketReward();
extern DWORD isPlayerDestroyParty;
extern DWORD balancePointer;
extern DWORD isLightCharCurrent;
extern DWORD isDarkCharCurrent;
extern DWORD sentPacketClient;
extern int checkPlayerRewardTime(int RewardOrder);
extern int upsertRewardBarLog(int CharID, int RewardOrder, const SYSTEMTIME& ActionTime);
extern int getNextRewardOrder(int CharID);
extern int clearRewardBarLogs(int CharID);
extern CStringW getCharSex(int OrdemCount);
void autoBalance();
void LogErrorToFile(const std::wstring& errorMessage);
void userShape2();
void getUserPermissions(int UserUID, DWORD CPlayer);
extern int getOwnKillForChar(int OrdemCount);
extern CStringW getCharColor(int CharID);
extern std::string ConvertWideToUTF8(const std::wstring& wideStr);
extern int ConvertToInt(const std::wstring& wideStr, int& intValue);
extern int upsert2ndQuickSlotChar(int CharID, int Bag, int Slot, bool SlotEquiped, int Type, int TypeID, int Bag2, int Slot2, bool SlotEquiped2, int Type2, int TypeID2);
extern int select2ndQuickSlotChar(int CharID, int resultArray[11]);
#endif //PCH_H
