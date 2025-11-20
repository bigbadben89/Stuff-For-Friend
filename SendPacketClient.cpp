#include "pch.h"
#include <algorithm>
#include "database.h"
#include <atlconv.h>
extern CDataBase g_DBobj;
extern CDataBase g_DBobj2;
using namespace std;
int isCharSex;
int isCharJob;
int isCharFamily;
char isCharName[30];
char isOwnKill[30];
int ispointerCharID = 0;
int isgetValueQuickSlot[11];
char rewardArray[300];
DWORD balancePointer = 0;
int getValuesItemsReward() {
	int result = selectAndSortRewardTypes(rewardArray);
	return result;
}

int divideResultByteCountsBy3() {
	if (resultByteCounts == 0) {
		LogErrorToFile(L"Erro: resultByteCounts é zero. Divisão por zero não é permitida.");
		return -1; // Retorna 0 ou pode lidar com o erro de outra forma
	}

	int divisor = 4;
	int quociente = resultByteCounts / divisor;

	return quociente;
}



int getValuesTableQuickSlot() {
	int result = select2ndQuickSlotChar(ispointerCharID, isgetValueQuickSlot);
	// Adicione tratamento de erro ou outras operações aqui, se necessário
	return result;
}

int isOrderID = 0; // aqui vai ser a função onde vai o ps_game assim que logar vai enviar para o charID a Reward
int isgetValueRewards[4];
int isUserUID = 0;
char packetRewardItems[35];
int getValuesTableRewardBar() {
	int result = selectRewardBar(isOrderID, isgetValueRewards);
	return result;
}

int getValueRewardOrder() {
	int result = getCurrentRewardOrder(isUserUID);
	return result;
}


int getCharNameASCII(int OrdemCount) {
	CStringW resultW = getCharName(OrdemCount);
	wstring resultStdW = (LPCWSTR)resultW;
	string resultUTF8 = ConvertWideToUTF8(resultStdW);

	if (resultUTF8.size() >= sizeof(isCharName)) {
		return -1;
	}

	memcpy(isCharName, resultUTF8.c_str(), resultUTF8.size() + 1);

	int resultW2 = getOwnKillForChar(OrdemCount);
	string resultUTF82 = to_string(resultW2); // Converte int para string

	// Certifique-se de que isOwnKill é grande o suficiente
	if (resultUTF82.size() >= sizeof(isOwnKill)) {
		return -1;
	}

	// Usa snprintf para evitar truncamento acidental
	snprintf(isOwnKill, sizeof(isOwnKill), "%s", resultUTF82.c_str());

	CStringW charJobStr = getCharJob(OrdemCount);
	wstring charJobWStr;
	charJobWStr.assign(charJobStr, charJobStr.GetLength()); // Converte CStringW para wstring

	// Chama ConvertToInt com a string convertida
	int conversionResult = ConvertToInt(charJobWStr, isCharJob);
	if (conversionResult != 0) {
		// Lidar com falha na conversão
		return -1;
	}

	CStringW charFamilyStr = getCharFamily(OrdemCount);
	wstring charFamilyWStr;
	charFamilyWStr.assign(charFamilyStr, charFamilyStr.GetLength()); // Converte CStringW para wstring

	// Chama ConvertToInt com a string convertida
	int conversionResult2 = ConvertToInt(charFamilyWStr, isCharFamily);
	if (conversionResult2 != 0) {
		// Lidar com falha na conversão
		return -1;
	}

	CStringW charSexStr = getCharSex(OrdemCount);
	wstring charSexWStr;
	charSexWStr.assign(charSexStr, charSexStr.GetLength()); // Converte CStringW para wstring

	// Chama ConvertToInt com a string convertida
	int conversionResult3 = ConvertToInt(charSexWStr, isCharSex);
	if (conversionResult3 != 0) {
		// Lidar com falha na conversão
		return -1;
	}

	return 0;
}
int isCharColor;
int getColorNameASCII(int CharID) {
	CStringW charColorStr = getCharColor(CharID);
	wstring charColorWStr;
	charColorWStr.assign(charColorStr, charColorStr.GetLength()); // Converte CStringW para wstring

	// Chama ConvertToInt com a string convertida
	int conversionResult3 = ConvertToInt(charColorWStr, isCharColor);
	if (conversionResult3 != 0) {
		// Lidar com falha na conversão
		return -1;
	}

	return 0;
}

int pointerCharID = 0;
int pointerBag = 0;
int pointerSlot = 0;
bool pointerSlotEquiped = 0;
int pointerType = 0;
int pointerTypeID = 0;
int pointerBag2 = 0;
int pointerSlot2 = 0;
bool pointerSlotEquiped2 = 0;
int pointerType2 = 0;
int pointerTypeID2 = 0;
int pointerRewardOrder = 0;
int pointerRewardUserUID = 0;
void UpsertFunctionDirectly() {
	upsert2ndQuickSlotChar(pointerCharID, pointerBag, pointerSlot, pointerSlotEquiped,
		pointerType, pointerTypeID, pointerBag2, pointerSlot2,
		pointerSlotEquiped2, pointerType2, pointerTypeID2);
}

int checkPlayerTime() {

	int status = checkPlayerRewardTime(pointerRewardOrder);

	return status;
}

int insertLogReward() {

	SYSTEMTIME actionTime;
	GetLocalTime(&actionTime);
	// Chamar a função para inserir ou atualizar o log
	int result = upsertRewardBarLog(pointerRewardUserUID, pointerRewardOrder, actionTime);

	return result;

}

int checkRewardOrder() {
	int result = getNextRewardOrder(pointerRewardUserUID);
	return result;
}

int checkCurrentRewardOrder() {
	int result = getCurrentRewardOrder(pointerRewardUserUID);
	return result;
}

int getValueLastRewardOrder() {
	if (getLastRewardOrder() == 0) { // Verifica se a consulta foi bem-sucedida
		return g_LastRewardOrder;   // Retorna o valor armazenado na variável global
	}
	else {
		return -1; // Indica falha ao obter o valor
	}
}
const char* balanceNoticeEnabled = "The administrator enabled the auto balance";
const char* balanceNoticeDisabled = "The administrator disabled the auto balance";
char isOwnKillPacket[50];
char rewardReceive[10];
DWORD loopCount = 0;
DWORD SendPacketClientMainRetn = 0x00474BB4;
DWORD SendPacket = 0x004ED0E0;
DWORD continueFuncPacket = 0x004750D3;
DWORD findUserByCharID = 0x00414CC0;
DWORD getItemInfo = 0x004059B0;
DWORD sentPlayerItem = 0x0046BD10;
char bPacketNotice[100];
DWORD countBytes = 0;

DWORD sendNoticePacket = 0x00419120;
_declspec(naked) void SendPacketClientMain() {
	_asm {
		cmp word ptr ds : [edi] , 0xF49A
		je balanceEnabled

		cmp word ptr ds : [edi] , 0xF49B
		je balanceDisabled

		cmp word ptr ds : [edi] , 0x05F1
		je checkSignal

		cmp word ptr ds : [edi] , 0x05F2
		je checkSignal2

		cmp word ptr ds : [edi] , 0x01F8
		je getOwnKillData

		cmp word ptr ds : [edi] , 0x03F12
		je checkPlayerTimeReward

		originalcode :
		movzx ecx, word ptr ds : [edi]
			mov eax, ecx
			jmp SendPacketClientMainRetn

			checkSignal :
		mov dword ptr ds : [ebx + 0x6430] , 0
			labelContinuePacket :
			jmp continueFuncPacket

			checkSignal2 :
		mov dword ptr ds : [ebx + 0x6434] , 0
			jmp labelContinuePacket

			balanceEnabled :
		cmp byte ptr ds : [ebx + 0x5808] , 02
			je packetBalanceEnabled
			cmp byte ptr ds : [ebx + 0x5808] , 03
			je packetBalanceEnabled
			cmp byte ptr ds : [ebx + 0x5808] , 01 // isUserAdmin
			jne labelContinuePacket
			packetBalanceEnabled :
		mov dword ptr ds : [balancePointer] , 01
			jmp continueNoticeFunc

			balanceDisabled :
		cmp byte ptr ds : [ebx + 0x5808] , 02
			je packetBalanceDisabled
			cmp byte ptr ds : [ebx + 0x5808] , 03
			je packetBalanceDisabled
			cmp byte ptr ds : [ebx + 0x5808] , 01 // isUserAdmin
			jne labelContinuePacket
			packetBalanceDisabled :
		mov dword ptr ds : [balancePointer] , 00


			continueNoticeFunc :
			pushad
			mov word ptr ds : [bPacketNotice] , 0xF90B
			call noticeLenght

			mov al, byte ptr ds : [countBytes]
			add al, 01
			mov byte ptr ds : [bPacketNotice + 0x02] , al
			cmp word ptr ds : [edi] , 0xF49B
			jne isDataNoticeEnabled
			mov eax, offset balanceNoticeDisabled
			mov edi, [eax]
			jmp continueDataLoop
			isDataNoticeEnabled :
		mov eax, offset balanceNoticeEnabled
			mov edi, [eax]
			continueDataLoop :
			mov esi, offset bPacketNotice + 03
			mov ecx, 0

			start_loop_menssage :
			mov al, byte ptr ds : [edi]
			mov byte ptr ds : [esi + ecx] , al
			cmp al, 00
			je pop_return
			inc edi
			inc ecx
			jmp start_loop_menssage


			pop_return :
		mov esi, dword ptr ds : [0x00587960] // CWORLD
			mov eax, dword ptr ds : [countBytes]
			add eax, 03 // LENGHT
			lea ecx, dword ptr ds : [bPacketNotice] // DATA
			push eax
			//mov edi,esi
			call sendNoticePacket
			add esp, 0x04
			popad
			jmp continueFuncPacket

			noticeLenght :
		cmp word ptr ds : [edi] , 0xF49B
			jne isEnabledNotice
			mov eax, offset balanceNoticeDisabled
			mov esi, [eax]
			jmp continueLoopFunc
			isEnabledNotice :
		mov eax, offset balanceNoticeEnabled
			mov esi, [eax]
			continueLoopFunc :
			mov ecx, 0
			count_bytes_loop :
			cmp byte ptr ds : [esi] , 0
			je end_count_bytes

			inc ecx
			inc esi
			jmp count_bytes_loop

			end_count_bytes :
		mov dword ptr ds : [countBytes] , ecx
			ret

			checkPlayerTimeReward :
		pushad
			pushfd
			call getValueLastRewardOrder
			mov eax, dword ptr ds : [ebx + 0x582C]
			mov dword ptr ds : [pointerRewardUserUID] , eax
			mov edi, ebx
			mov eax, dword ptr ds : [edi + 0x6378] // CUser::PlayerRewardOrder



			mov dword ptr ds : [pointerRewardOrder] , eax
			mov dword ptr ds : [isOrderID] , eax
			call checkPlayerTime
			cmp eax, -01
			je isEndCodeReward
			cmp dword ptr ds : [edi + 0x6370] , eax
			jb isEndCodeReward



			call getValuesTableRewardBar
			cmp eax, -01
			je completeReward
			mov eax, dword ptr ds : [isgetValueRewards]
			mov ecx, dword ptr ds : [isgetValueRewards + 4]
			call getItemInfo
			mov ebp, edi
			mov ecx, ebp
			movzx ebx, byte ptr ds : [isgetValueRewards + 8]
			test ebx, ebx
			je isEndCodeReward
			push ebx
			push eax // ItemInfo recebido da função 004059B0
			call sentPlayerItem
			mov dword ptr ds : [edi + 0x6370] , 0 // reset player time
			inc dword ptr ds : [edi + 0x6378] //CUser::PlayerRewardOrder

			mov eax, dword ptr ds : pointerRewardOrder

			add eax, 1
			mov ebx, dword ptr ds : g_LastRewardOrder
			cmp eax, ebx
			jg completeReward

			mov dword ptr ds : [isOrderID] , eax

			call getValuesTableRewardBar
			cmp eax, -01
			je completeReward
			mov word ptr ds : [packetRewardItems] , 0x03F11
			movzx eax, byte ptr ds : [isgetValueRewards]
			mov byte ptr ds : [packetRewardItems + 03] , al
			movzx eax, byte ptr ds : [isgetValueRewards + 04]
			mov byte ptr ds : [packetRewardItems + 06] , al
			movzx eax, byte ptr ds : [isgetValueRewards + 8]
			mov byte ptr ds : [packetRewardItems + 8] , al
			mov eax, dword ptr ds : [isgetValueRewards + 12]
			mov dword ptr ds : [packetRewardItems + 11] , eax
			rewardPacketFunc :
		push 20
			lea ecx, dword ptr ds : packetRewardItems
			push ecx
			mov ecx, edi
			call SendPacket

			call insertLogReward

			mov word ptr ds : [rewardReceive] , 0x03F15
			push 04
			lea ecx, dword ptr ds : rewardReceive
			push ecx
			mov ecx, edi
			call SendPacket

			isEndCodeReward :
		popfd
			popad
			jmp continueFuncPacket

			completeReward :
		mov word ptr ds : [packetRewardItems] , 0x03F11
			mov byte ptr ds : [packetRewardItems + 03] , 00
			mov byte ptr ds : [packetRewardItems + 06] , 00
			mov byte ptr ds : [packetRewardItems + 8] , 00
			mov dword ptr ds : [packetRewardItems + 11] , 00
			jmp rewardPacketFunc



		getOwnKillData:
		pushad
			xor edx, edx
			isLoopOwnKill :
		cmp edx, 04
			jg isEndCode
			mov[loopCount], edx

			cmp edx, 01
			je isGetRank2
			cmp edx, 02
			je isGetRank3
			cmp edx, 03
			je isGetRank4
			cmp edx, 04
			je isGetRank5



			mov word ptr ds : [isOwnKillPacket] , 0x01F9
			mov eax, 01 // order count
			push eax


			continueFunc :
		call getCharNameASCII
			add esp, 04

			test eax, eax // checking sucess
			jne isEndCode

			mov al, byte ptr ds : [isCharFamily]
			mov byte ptr ds : [isOwnKillPacket + 39] , al
			mov al, byte ptr ds : [isCharJob]
			mov byte ptr ds : [isOwnKillPacket + 40] , al
			mov al, byte ptr ds : [isCharSex]
			mov byte ptr ds : [isOwnKillPacket + 41] , al



			mov edi, offset isOwnKillPacket + 0x02
			mov esi, offset isCharName
			xor ecx, ecx
			start_loop :
		mov al, [esi]
			mov byte ptr ds : [edi + ecx] , al
			test al, al
			je end_loop
			inc esi
			inc ecx
			jmp start_loop

			end_loop :
		mov edi, offset isOwnKillPacket + 0x1E
			mov esi, offset isOwnKill
			xor ecx, ecx
			start_loop_2 :
		mov al, byte ptr ds : [esi]
			mov byte ptr ds : [edi + ecx] , al
			test al, al
			je end_loop_2
			inc esi
			inc ecx
			jmp start_loop_2

			end_loop_2 :
		push 48
			lea ecx, [isOwnKillPacket]
			push ecx
			mov ecx, ebx
			call SendPacket
			mov edx, [loopCount]
			inc edx
			jmp isLoopOwnKill
			isEndCode :
		popad
			jmp continueFuncPacket

			isGetRank2 :
		mov eax, 02
			mov word ptr ds : [isOwnKillPacket] , 0x02F9
			push eax
			jmp continueFunc

			isGetRank3 :
		mov eax, 03
			mov word ptr ds : [isOwnKillPacket] , 0x03F9
			push eax
			jmp continueFunc

			isGetRank4 :
		mov eax, 04
			mov word ptr ds : [isOwnKillPacket] , 0x04F9
			push eax
			jmp continueFunc

			isGetRank5 :
		mov eax, 05
			mov word ptr ds : [isOwnKillPacket] , 0x05F9
			push eax
			jmp continueFunc

	}
}

char charColorsPacket[20];
DWORD sendPacketAll = 0x00427470;
DWORD getOwnCharColorNameReturn = 0x0041C7E6;
_declspec(naked) void getOwnCharColorName() {
	_asm {

		mov ecx, dword ptr ds : [edi + 0x00001800]
		pushad
		mov word ptr ds : [charColorsPacket] , 0x01F10
		mov eax, [edi + 0xDC]
		push eax
		call getColorNameASCII
		add esp, 0x04
		test eax, eax
		jne continueCode
		mov al, byte ptr ds : [isCharColor]
		mov byte ptr ds : [charColorsPacket + 0x0B] , al
		mov eax, [edi + 0xDC]
		mov dword ptr ds : [charColorsPacket + 0x05] , eax
		continueCode :
		push 13
			lea ecx, [charColorsPacket]
			push ecx
			mov ecx, edi
			call SendPacket



		pop_out:
		popad
			originalcode :
		mov cl, 0x0A
			fstp dword ptr ds : [esp + 0x19]
			jmp getOwnCharColorNameReturn
	}
}
char charColorsPlayerPacket[20];
DWORD getPlayersNameColorReturn = 0x00426B17;
_declspec(naked) void getPlayersNameColor() {
	_asm {
		pushad
		mov edi, ebx // player get pointer
		mov word ptr ds : [charColorsPlayerPacket] , 0x01F10
		mov eax, [edi + 0xDC]
		push eax
		call getColorNameASCII
		add esp, 0x04
		test eax, eax
		jne continueCode
		mov al, byte ptr ds : [isCharColor]
		mov byte ptr ds : [charColorsPlayerPacket + 0x0B] , al
		mov eax, [edi + 0xDC]
		mov dword ptr ds : [charColorsPlayerPacket + 0x05] , eax
		continueCode :
		mov eax, dword ptr ds : [edi + 0xE0]
			test eax, eax
			je pop_out
			push 13

			lea edx, dword ptr ds : charColorsPlayerPacket
			push edx
			push eax
			mov eax, dword ptr ds : [edi + 0x000000E8]
			mov ecx, dword ptr ds : [edi + 0x000000E4]
			call sendPacketAll




		pop_out:
		popad
			originalcode :
		movzx eax, byte ptr ds : [ebx + 0x00000131]


			jmp getPlayersNameColorReturn
	}
}


int clearRewards() {
	int result = clearRewardBarLogs(pointerCharID);
	return result;
}


DWORD isAddressJump = 0x00474A80;
DWORD isInsertValues2ndQuickPotionReturn = 0x0047496B;
_declspec(naked) void isInsertValues2ndQuickPotion() {
	_asm {

		cmp word ptr ds : [edi] , 0x01F11
		je insertMain

		originalcode :
		cmp eax, esi
			jne isJumpAddr
			jmp isInsertValues2ndQuickPotionReturn

			isJumpAddr :
		jmp isAddressJump

			insertMain :
		pushad
			mov eax, [edi + 0x02] // charID
			mov dword ptr ds : [pointerCharID] , eax
			mov al, byte ptr ds : [edi + 0x06]// bag
			mov byte ptr ds : [pointerBag] , al
			mov al, byte ptr ds : [edi + 0x08] // slot
			mov byte ptr ds : [pointerSlot] , al
			mov al, byte ptr ds : [edi + 0x09] // slotEquiped
			mov byte ptr ds : [pointerSlotEquiped] , al
			mov al, byte ptr ds : [edi + 0x0A] // Type
			mov byte ptr ds : [pointerType] , al
			mov al, byte ptr ds : [edi + 0x0C] // TypeID
			mov byte ptr ds : [pointerTypeID] , al
			mov al, byte ptr ds : [edi + 0x0E] // bag 2
			mov byte ptr ds : [pointerBag2] , al
			mov al, byte ptr ds : [edi + 0x10] // slot 2
			mov byte ptr ds : [pointerSlot2] , al
			mov al, byte ptr ds : [edi + 0x12] // slot equiped 2
			mov byte ptr ds : [pointerSlotEquiped2] , al
			mov al, byte ptr ds : [edi + 0x13] // type 2
			mov byte ptr ds : [pointerType2] , al
			mov al, byte ptr ds : [edi + 0x15] // type id 2
			mov byte ptr ds : [pointerTypeID2] , al
			call UpsertFunctionDirectly

			popad
			jmp originalcode

	}
}


char packetSentValueQuickSlot[30];
DWORD sendQuickSlotInfoReturn = 0x0047BBB4;
_declspec(naked) void sendQuickSlotInfo() {
	_asm {

		pushad
		mov eax, dword ptr ds : [ebp + 0x128] // ulong charId
		mov dword ptr ds : [ispointerCharID] , eax

		call getValuesTableQuickSlot

		mov word ptr ds : [packetSentValueQuickSlot] , 0x02F11 // packet 


		mov al, byte ptr ds : [isgetValueQuickSlot] // bag
		mov byte ptr ds : [packetSentValueQuickSlot + 02] , al
		mov al, byte ptr ds : [isgetValueQuickSlot + 4] // slot
		mov byte ptr ds : [packetSentValueQuickSlot + 04] , al
		mov al, byte ptr ds : [isgetValueQuickSlot + 8] // slotequiped
		mov byte ptr ds : [packetSentValueQuickSlot + 6] , al
		mov al, byte ptr ds : [isgetValueQuickSlot + 12] // type
		mov byte ptr ds : [packetSentValueQuickSlot + 8] , al
		mov al, byte ptr ds : [isgetValueQuickSlot + 16] // typeID
		mov byte ptr ds : [packetSentValueQuickSlot + 10] , al
		mov al, byte ptr ds : [isgetValueQuickSlot + 20] // bag2
		mov byte ptr ds : [packetSentValueQuickSlot + 12] , al
		mov al, byte ptr ds : [isgetValueQuickSlot + 24] // slot2
		mov byte ptr ds : [packetSentValueQuickSlot + 14] , al
		mov al, byte ptr ds : [isgetValueQuickSlot + 28] // slot equiped2
		mov byte ptr ds : [packetSentValueQuickSlot + 16] , al
		mov al, byte ptr ds : [isgetValueQuickSlot + 32] // type 2
		mov byte ptr ds : [packetSentValueQuickSlot + 18] , al
		mov al, byte ptr ds : [isgetValueQuickSlot + 36] // typeid 2
		mov byte ptr ds : [packetSentValueQuickSlot + 20] , al

		push 23
		lea ecx, [packetSentValueQuickSlot]
		push ecx
		mov ecx, ebp
		call SendPacket

		popad



	originalcode:
		mov eax, dword ptr ds : [ebp + 0x00000128] // charID 
			jmp sendQuickSlotInfoReturn


	}
}


char FeedMenssagePointer[255];
int FeedMenssage(const char* isMapName, const char* isCharName, const char* isKilled) {
	snprintf(FeedMenssagePointer, sizeof(FeedMenssagePointer), "%s:%s killed %s", isMapName, isCharName, isKilled);
	return 0;
}

char isKillFeedPacket[100];
char isKillerCharName[30];
char isDeadCharName[30];
int MapID = 0;
int Country = 0;
int setMapName(int MapID) {
	isMapNameFunction(MapID);
	return 0;
}

int killFeedMenssage() {
	FeedMenssage(isMapName, isKillerCharName, isDeadCharName);
	return 0;
}
DWORD isCountBytes = 0;
DWORD sendPacketCWorld = 0x00419120;
DWORD sendKillFeedClientInfoReturn = 0x004652A4;
_declspec(naked)void sendKillFeedClientInfo() {
	_asm {


		pushad
		mov edx, dword ptr ds : [esp + 0x34]
		push edx
		call findUserByCharID
		test eax, eax
		je pop_close
		cmp byte ptr ds : [eax + 0x160] , 40 // arena map
		je pop_close
		call getNameKiller
		mov bx, word ptr ds : [edi + 0x160] // mapID
		mov word ptr ds : [MapID] , bx
		push ebx
		call setMapName
		add esp, 0x04
		test eax, eax
		jne pop_close
		call killFeedMenssage
		mov word ptr ds : [isKillFeedPacket] , 0x02F12 // kill feed packet
		call isKillFeedPacketWrite
		mov esi, dword ptr ds : [0x00587960] // CWORLD
		mov eax, [isCountBytes]
		add eax, 04 // LENGHT
		mov edx, [Country]
		mov dword ptr ds : [isKillFeedPacket + eax - 01] , edx
		lea ecx, dword ptr ds : isKillFeedPacket // DATA
		push eax
		call sendPacketCWorld
		add esp, 0x04



	pop_close:
		popad
			mov edx, dword ptr ds : [esp + 0x14]
			mov eax, 0x00000504
			jmp sendKillFeedClientInfoReturn

			getNameKiller :
		mov edx, offset isKillerCharName
			mov esi, eax
			mov eax, [esi + 0x12D] // facction
			mov[Country], eax
			xor ecx, ecx
			xor eax, eax
			start_loop :
		mov al, [esi + 0x184]
			mov byte ptr ds : [edx + ecx] , al
			test al, al
			je isGetDeadName
			inc esi
			inc ecx
			jmp start_loop
			isGetDeadName :
		mov edx, offset isDeadCharName
			mov esi, edi // dead player
			xor ecx, ecx
			xor eax, eax
			start_loop_2 :
		mov al, [esi + 0x184]
			mov byte ptr ds : [edx + ecx] , al
			test al, al
			je isReturnCallFunction
			inc esi
			inc ecx
			jmp start_loop_2
			isReturnCallFunction :
		ret

			isKillFeedPacketWrite :
		mov edx, offset isKillFeedPacket + 02
			mov esi, offset FeedMenssagePointer
			xor ecx, ecx
			start_packet_feed_loop :
		mov al, byte ptr ds : [esi]
			mov byte ptr ds : [edx + ecx] , al
			test al, al
			je isReturnCallFunctionGetBytes
			inc esi
			inc ecx
			jmp start_packet_feed_loop

			isReturnCallFunctionGetBytes :
		mov dword ptr ds : [isCountBytes] , ecx
			jmp isReturnCallFunction

	}
}

DWORD rewardCount = 0;
DWORD resultDivideReward = 0;
DWORD rewardPacketCount = 0;
char packetSentItemList[300];
int playerActivity[1000];
DWORD sendRewardItemsInfoReturn = 0x0047BBC9;
_declspec(naked) void sendRewardItemsInfo() {
	_asm {
		pushad

		mov edi, ebp

		mov ebp, offset playerActivity


		start_loop_player :
		mov eax, dword ptr ds : [ebp]
			test eax, eax
			je add_player

			cmp eax, edi
			je end_loop

			add ebp, 4


			jmp start_loop_player

			add_player :
		call find_player_pointer
			cmp dword ptr ds : [edi + 0x6374] , 1
			je end_loop
			mov dword ptr ds : [ebp] , edi

			end_loop :

		mov ebp, edi

			mov edx, dword ptr ds : [ebp + 0x582C]
			mov dword ptr[isUserUID], edx
			call getValueRewardOrder
			cmp eax, -01
			je setPlayerOrder
			test eax, eax
			je nextReward
			backPlayerReward :
		cmp dword ptr ds : [ebp + 0x6378] , 0
			je original_player_order
			nextReward :
		call getValueLastRewardOrder
			mov ecx, dword ptr ds : g_LastRewardOrder
			cmp eax, ecx
			jg close_pop
			add eax, 1
			original_player_order :
			mov dword ptr ds : [ebp + 0x6378] , eax
			call getValuesItemsReward
			backPlayerFuncReward :
		test eax, eax
			jne close_pop
			call divideResultByteCountsBy3
			cmp eax, -01
			je close_pop
			mov dword ptr ds : [resultDivideReward] , eax
			mov word ptr ds : [packetSentItemList] , 0x03E11
			call getArrayItems
			test eax, eax
			jne close_pop
			mov eax, [resultByteCounts]
			mov dword ptr ds : [packetSentItemList + 03] , eax
			mov ebx, 4
			xor edx, edx
			div ebx
			mov ebx, 2
			xor edx, edx
			div ebx
			mov[rewardCount], eax
			mov eax, [resultByteCounts] // count
			add eax, 5
			push eax
			movzx edx, byte ptr ds : [rewardCount]
			mov byte ptr ds : [packetSentItemList + 05] , dl
			lea ecx, dword ptr ds : packetSentItemList
			push ecx
			mov ecx, ebp
			call SendPacket

			mov eax, dword ptr ds : [ebp + 0x6378]
			mov dword ptr ds : [isOrderID] , eax // default ever than log
			call getValuesTableRewardBar
			mov word ptr ds : [packetRewardItems] , 0x03F11 // packet sent reward current
			cmp eax, -01
			je clean_packet
			movzx eax, byte ptr ds : [isgetValueRewards]
			mov byte ptr ds : [packetRewardItems + 03] , al
			movzx eax, byte ptr ds : [isgetValueRewards + 04]
			mov byte ptr ds : [packetRewardItems + 06] , al
			movzx eax, byte ptr ds : [isgetValueRewards + 8]
			mov byte ptr ds : [packetRewardItems + 8] , al
			mov eax, dword ptr ds : [isgetValueRewards + 12]
			mov dword ptr ds : [packetRewardItems + 11] , eax
			backPacketSent :
		push 15
			lea ecx, dword ptr ds : packetRewardItems
			push ecx
			mov ecx, ebp
			call SendPacket

			xor ebx, ebx
			start_loop_packet :
		cmp ebx, [isOrderID] // max items
			jge close_pop
			mov word ptr ds : [rewardReceive] , 0x03F15
			push 02
			lea ecx, dword ptr ds : rewardReceive
			push ecx
			mov ecx, ebp
			call SendPacket


			inc ebx
			jmp start_loop_packet

			close_pop :


		mov eax, dword ptr ds : [ebp + 0x582C]
			push ebp
			push eax
			call getUserPermissions
			add esp, 8


			popad



		originalcode:
		xor ebx, ebx
			mov ecx, ebp
			mov word ptr ds : [esp + 0x2C] , dx
			jmp sendRewardItemsInfoReturn

			setPlayerOrder :
		xor eax, eax
			mov dword ptr ds : [ebp + 0x6378] , eax
			jmp backPlayerReward


			getArrayItems :
		mov edi, offset packetSentItemList + 07
			mov esi, offset rewardArray
			mov ecx, [resultByteCounts]
			loop_get_reward_values :
			mov al, byte ptr ds : [esi]
			mov byte ptr ds : [edi] , al
			inc esi
			inc edi
			dec ecx
			test ecx, ecx
			jne loop_get_reward_values
			ret

			clean_packet :
		mov word ptr ds : [packetRewardItems] , 0x03F11
			mov byte ptr ds : [packetRewardItems + 03] , 00
			mov byte ptr ds : [packetRewardItems + 06] , 00
			mov byte ptr ds : [packetRewardItems + 8] , 00
			mov dword ptr ds : [packetRewardItems + 11] , 00
			push 15
			lea ecx, dword ptr ds : packetRewardItems
			push ecx
			mov ecx, ebp
			call SendPacket
			xor ebx, ebx
			mov ecx, dword ptr ds : g_LastRewardOrder
			start_loop_packet_clean :
		cmp ebx, ecx // max rewards
			jg close_pop
			mov word ptr ds : [rewardReceive] , 0x03F15
			push 02
			lea ecx, dword ptr ds : rewardReceive
			push ecx
			mov ecx, ebp
			call SendPacket


			inc ebx
			jmp start_loop_packet_clean

			find_player_pointer :
		xor esi, esi
			mov ebx, offset playerActivity
			loop_find :
		cmp esi, 2512
			jge end_loop_2
			cmp dword ptr ds : [esi + ebx] , edi
			je find_layer_loop

			mov dword ptr ds : [edi + 0x6374] , 00 // player array insert

			add esi, 4

			jmp loop_find

			end_loop_2 :
		ret

			find_layer_loop :
		mov dword ptr ds : [edi + 0x6374] , 01 // player array insert
			ret

	}
}
DWORD register_time_2 = 0;
DWORD kickPlayerFunc = 0x004EC760;
DWORD register_time = 0;
DWORD playerOnlineTimeRetn = 0x004035CA;
_declspec(naked) void playerOnlineTime() {
	_asm {
		pushad



		call check_player_activity


		pop_and_close :
		popad

			originalcode :
		cmp byte ptr ds : [0x0058794C] , 00
			jmp playerOnlineTimeRetn


			check_player_activity :
		xor ebp, ebp

			mov edi, offset playerActivity
			start_check_loop_player_activity :
		cmp ebp, 2512
			jge pop_ret
			cmp dword ptr ds : [ebp + edi] , 0
			je continue_to_code
			mov esi, dword ptr ds : [edi + ebp]

			cmp byte ptr ds : [esi + 0x5860] , 1
			jne continue_func_player
			erase_player_info :
		mov dword ptr ds : [esi + 0x6370] , 0
			mov dword ptr ds : [edi + ebp] , 0
			jmp continue_to_code
			continue_func_player :
		call dword ptr ds : [0x005540D0]
			mov edx, dword ptr ds : [esi + 0x6400]
			add edx, 925 // 1 second
			cmp eax, edx
			jna continue_to_code
			call dword ptr ds : [0x005540D0]
			mov dword ptr ds : [esi + 0x6400] , eax
			inc dword ptr ds : [esi + 0x6370]
			continue_to_code :
			add ebp, 4
			jmp start_check_loop_player_activity


			pop_ret :
		ret
	}
}

void SendPacketClient() {
	if (!g_DBobj.LinkDataBase()) return;


	Sleep(8000);
	//Hook((PVOID)0x004035C3, playerOnlineTime, 7);
	Hook((PVOID)0x00474BAF, SendPacketClientMain, 5);
	Hook((PVOID)0x0046529B, sendKillFeedClientInfo, 9);
	 Hook((PVOID)0x0041C7E0, getOwnCharColorName, 6);
    Hook((PVOID)0x00426B10, getPlayersNameColor, 7);
	//Hook((PVOID)0x0047BBC0, sendRewardItemsInfo, 9);
	 Hook((PVOID)0x00474963, isInsertValues2ndQuickPotion, 8);
	 Hook((PVOID)0x0047BBAE, sendQuickSlotInfo, 6);
}

