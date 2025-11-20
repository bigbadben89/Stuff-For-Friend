#include "pch.h"
#include <algorithm>
#include <atlbase.h>
#include <atldbcli.h> // Inclua este cabeçalho para acesso a ADO
#include <chrono>
#include "database.h"
#include <atlconv.h>
#include <nanodbc/nanodbc.h>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <fstream>  // Necessário para trabalhar com arquivos
using namespace std;
void LogSqlQuery(const CStringW& sqlQuery) {
	std::ofstream logFile;
	logFile.open("log.txt", std::ios::app);
	if (logFile.is_open()) {
		logFile << "SQL Query: " << CStringA(sqlQuery) << std::endl;
		logFile.close();
	}
}

void LogErrorToFile(const std::wstring& errorMessage)
{
	std::wofstream logFile(L"log.txt", std::ios::app); // Abre no modo append

	if (!logFile)
	{
		std::wcerr << L"Failed to open log file!" << std::endl;
		return;
	}

	// Obtém a data e hora atual
	std::time_t now = std::time(nullptr);
	std::tm localTime{};
	localtime_s(&localTime, &now);

	wchar_t timeBuffer[100];
	wcsftime(timeBuffer, sizeof(timeBuffer) / sizeof(wchar_t), L"%Y-%m-%d %H:%M:%S", &localTime);

	// Escreve a mensagem no arquivo
	logFile << L"[" << timeBuffer << L"] " << errorMessage << std::endl;
	logFile.close();
}
CDataBase g_DBobj2;
CDataBase g_DBobj3;
CDataBase g_DBobj;


CStringW getCharCountryCharID(const std::string& charName) {
	static CStringW charID;

	// Converta std::string para CStringW
	CStringW wCharName(charName.c_str());

	CStringW szSql;
	// Utilize aspas simples para envolver o nome do personagem no SQL
	szSql.Format(L"SELECT CharID FROM PS_GameData.dbo.Chars WHERE CharName = '%s' and DEL = 0", wCharName.GetString());

	charID = g_DBobj.ExeSqlByCommand(szSql, L"CharID");

	return charID;
}

CStringW getCharName(int OrdemCount) {
	static CStringW charName;

	CStringW szSql;
	switch (OrdemCount) {
	case 1:
		szSql.Format(L"SELECT CharName FROM PS_GameData.dbo.Chars WHERE TopKills IS NOT NULL  ORDER BY TopKills DESC OFFSET 0 ROWS FETCH NEXT 1 ROWS ONLY;");
		break;
	case 2:
		szSql.Format(L"SELECT CharName FROM PS_GameData.dbo.Chars WHERE TopKills IS NOT NULL  ORDER BY TopKills DESC OFFSET 1 ROWS FETCH NEXT 1 ROWS ONLY;");
		break;
	case 3:
		szSql.Format(L"SELECT CharName FROM PS_GameData.dbo.Chars WHERE TopKills IS NOT NULL  ORDER BY TopKills DESC OFFSET 2 ROWS FETCH NEXT 1 ROWS ONLY;");
		break;
	case 4:
		szSql.Format(L"SELECT CharName FROM PS_GameData.dbo.Chars WHERE TopKills IS NOT NULL  ORDER BY TopKills DESC OFFSET 3 ROWS FETCH NEXT 1 ROWS ONLY;");
		break;
	case 5:
		szSql.Format(L"SELECT CharName FROM PS_GameData.dbo.Chars WHERE TopKills IS NOT NULL  ORDER BY TopKills DESC OFFSET 4 ROWS FETCH NEXT 1 ROWS ONLY;");
		break;
	default:

		return L"";
	}

	charName = g_DBobj.ExeSqlByCommand(szSql, L"CharName");

	return charName;
}

CStringW getCharJob(int OrdemCount) {
	static CStringW charJob;
	CStringW szSql;
	switch (OrdemCount) {
	case 1:
		szSql.Format(L"SELECT Job FROM PS_GameData.dbo.Chars WHERE TopKills IS NOT NULL  ORDER BY TopKills DESC OFFSET 0 ROWS FETCH NEXT 1 ROWS ONLY;");
		break;
	case 2:
		szSql.Format(L"SELECT Job FROM PS_GameData.dbo.Chars WHERE TopKills IS NOT NULL  ORDER BY TopKills DESC OFFSET 1 ROWS FETCH NEXT 1 ROWS ONLY;");
		break;
	case 3:
		szSql.Format(L"SELECT Job FROM PS_GameData.dbo.Chars WHERE TopKills IS NOT NULL  ORDER BY TopKills DESC OFFSET 2 ROWS FETCH NEXT 1 ROWS ONLY;");
		break;
	case 4:
		szSql.Format(L"SELECT Job FROM PS_GameData.dbo.Chars WHERE TopKills IS NOT NULL  ORDER BY TopKills DESC OFFSET 3 ROWS FETCH NEXT 1 ROWS ONLY;");
		break;
	case 5:
		szSql.Format(L"SELECT Job FROM PS_GameData.dbo.Chars WHERE TopKills IS NOT NULL  ORDER BY TopKills DESC OFFSET 4 ROWS FETCH NEXT 1 ROWS ONLY;");
		break;
	default:

		return L"";
	}

	charJob = g_DBobj.ExeSqlByCommand(szSql, L"Job");

	return charJob;

}


CStringW getCharFamily(int OrdemCount) {
	static CStringW charFamily;
	CStringW szSql;
	switch (OrdemCount) {
	case 1:
		szSql.Format(L"SELECT Family FROM PS_GameData.dbo.Chars WHERE TopKills IS NOT NULL  ORDER BY TopKills DESC OFFSET 0 ROWS FETCH NEXT 1 ROWS ONLY;");
		break;
	case 2:
		szSql.Format(L"SELECT Family FROM PS_GameData.dbo.Chars WHERE TopKills IS NOT NULL  ORDER BY TopKills DESC OFFSET 1 ROWS FETCH NEXT 1 ROWS ONLY;");
		break;
	case 3:
		szSql.Format(L"SELECT Family FROM PS_GameData.dbo.Chars WHERE TopKills IS NOT NULL  ORDER BY TopKills DESC OFFSET 2 ROWS FETCH NEXT 1 ROWS ONLY;");
		break;
	case 4:
		szSql.Format(L"SELECT Family FROM PS_GameData.dbo.Chars WHERE TopKills IS NOT NULL  ORDER BY TopKills DESC OFFSET 3 ROWS FETCH NEXT 1 ROWS ONLY;");
		break;
	case 5:
		szSql.Format(L"SELECT Family FROM PS_GameData.dbo.Chars WHERE TopKills IS NOT NULL  ORDER BY TopKills DESC OFFSET 4 ROWS FETCH NEXT 1 ROWS ONLY;");
		break;
	default:

		return L"";
	}

	charFamily = g_DBobj.ExeSqlByCommand(szSql, L"Family");

	return charFamily;

}

CStringW getCharSex(int OrdemCount) {
	static CStringW charSex;
	CStringW szSql;
	switch (OrdemCount) {
	case 1:
		szSql.Format(L"SELECT Sex FROM PS_GameData.dbo.Chars WHERE TopKills IS NOT NULL  ORDER BY TopKills DESC OFFSET 0 ROWS FETCH NEXT 1 ROWS ONLY;");
		break;
	case 2:
		szSql.Format(L"SELECT Sex FROM PS_GameData.dbo.Chars WHERE TopKills IS NOT NULL  ORDER BY TopKills DESC OFFSET 1 ROWS FETCH NEXT 1 ROWS ONLY;");
		break;
	case 3:
		szSql.Format(L"SELECT Sex FROM PS_GameData.dbo.Chars WHERE TopKills IS NOT NULL  ORDER BY TopKills DESC OFFSET 2 ROWS FETCH NEXT 1 ROWS ONLY;");
		break;
	case 4:
		szSql.Format(L"SELECT Sex FROM PS_GameData.dbo.Chars WHERE TopKills IS NOT NULL  ORDER BY TopKills DESC OFFSET 3 ROWS FETCH NEXT 1 ROWS ONLY;");
		break;
	case 5:
		szSql.Format(L"SELECT Sex FROM PS_GameData.dbo.Chars WHERE TopKills IS NOT NULL  ORDER BY TopKills DESC OFFSET 4 ROWS FETCH NEXT 1 ROWS ONLY;");
		break;
	default:

		return L"";
	}

	charSex = g_DBobj.ExeSqlByCommand(szSql, L"Sex");

	return charSex;

}

int getOwnKillForChar(int OrdemCount) {
	int ownKill = -1; // Valor padrão para indicar falha

	CStringW szSql;
	if (OrdemCount >= 1 && OrdemCount <= 5) {
		szSql.Format(L"SELECT TOP 1 TopKills FROM PS_GameData.dbo.Chars "
			L"WHERE CharName IN (SELECT CharName FROM PS_GameData.dbo.Chars "
			L"WHERE TopKills IS NOT NULL ORDER BY TopKills DESC OFFSET %d ROWS FETCH NEXT 1 ROWS ONLY) "
			L"AND TopKills IS NOT NULL ORDER BY TopKills DESC;", OrdemCount - 1);

		CStringW result = g_DBobj.ExeSqlByCommand(szSql, L"TopKills");

		if (!result.IsEmpty()) {
			ownKill = _wtoi(result); // Converte para int
		}
	}

	return ownKill;
}

CStringW getCharColor(int CharID) {
	static CStringW charColor;
	CStringW szSql;

	szSql.Format(L"SELECT ColorHex FROM PS_GameData.dbo.CharacterColors WHERE CharID = %d", CharID);

	charColor = g_DBobj.ExeSqlByCommand(szSql, L"ColorHex");

	return charColor;
}

int ConvertToInt(const CStringW& value) {
	if (value.CompareNoCase(L"True") == 0 || value.CompareNoCase(L"-1") == 0) {
		return 1;  // TRUE
	}
	return 0;  // FALSE
}








int getCurrentRewardOrder(int UserUID) {
	CStringW szSql;
	CStringW szSql2;
	CStringW charRewardOrder;
	CStringW userUIDOrder;

	// Formata a consulta SQL para obter RewardOrder e UserUID
	szSql.Format(L"SELECT TOP 1 RewardOrder FROM PS_GameData.dbo.RewardBarLogs WHERE UserUID = %d ORDER BY RewardOrder DESC", UserUID);
	szSql2.Format(L"SELECT TOP 1 UserUID FROM PS_GameData.dbo.RewardBarLogs WHERE UserUID = %d", UserUID);

	// Executa as consultas e obtém os valores
	charRewardOrder = g_DBobj.ExeSqlByCommand(szSql, L"RewardOrder");
	userUIDOrder = g_DBobj.ExeSqlByCommand(szSql2, L"UserUID"); // Aqui estava errado, agora corrigido

	// Se a string estiver vazia ou contiver "NULL" ou "0", retorna -1
	if (userUIDOrder.IsEmpty() || userUIDOrder.CompareNoCase(L"NULL") == 0 || userUIDOrder.Compare(L"0") == 0) {
		return -1;
	}

	// Converte RewardOrder para inteiro
	int rewardOrder = 0;
	if (swscanf_s(charRewardOrder, L"%d", &rewardOrder) != 1) {
		LogErrorToFile(L"Falha ao converter para inteiro!");
		return -1;
	}

	return rewardOrder;
}

string ConvertWideToUTF8(const wstring& wideStr) {
	int bufferSize = WideCharToMultiByte(CP_UTF8, 0, wideStr.c_str(), -1, nullptr, 0, nullptr, nullptr);
	string utf8Str(bufferSize, 0);
	WideCharToMultiByte(CP_UTF8, 0, wideStr.c_str(), -1, &utf8Str[0], bufferSize, nullptr, nullptr);
	return utf8Str;
}

int ConvertToInt(const std::wstring& wideStr, int& intValue) {
	try {
		std::string utf8Str = ConvertWideToUTF8(wideStr);
		intValue = std::stoi(utf8Str);
		return 0;
	}
	catch (const std::exception& e) {
		return -1;
	}
}
using std::wstring;

int upsert2ndQuickSlotChar(
	int CharID, int Bag, int Slot, bool SlotEquiped, int Type, int TypeID,
	int Bag2, int Slot2, bool SlotEquiped2, int Type2, int TypeID2)
{
	CStringW sql;
	sql.Format(
		L"EXEC upsert2ndQuickSlotChar @CharID = %d, @Bag = %d, @Slot = %d, @SlotEquiped = %d, @Type = %d, @TypeID = %d, @Bag2 = %d, @Slot2 = %d, @SlotEquiped2 = %d, @Type2 = %d, @TypeID2 = %d",
		CharID, Bag, Slot, SlotEquiped ? 1 : 0, Type, TypeID, Bag2, Slot2, SlotEquiped2 ? 1 : 0, Type2, TypeID2);

	try {
		bool success = g_DBobj.ExeSqlByCommand(sql);
		return success ? 0 : -1; 
	}
	catch (...) {
		LogErrorToFile(L"Erro ao executar a stored procedure upsert2ndQuickSlotChar.");
		return -1; 
	}
}

int clearRewardBarLogs(int UserUID)
{
	CStringW sql;
	sql.Format(
		L"EXEC ClearRewardBarLogs @UserUID = %d",
		UserUID);

	try {
		bool success = g_DBobj.ExeSqlByCommand(sql);
		return success ? 0 : -1;
	}
	catch (...) {
		LogErrorToFile(L"Erro ao executar a stored procedure ClearRewardBarLogs.");
		return -1;
	}
}

int checkPlayerRewardTime(int RewardOrder) {
	const char* iniFile = ".\\RewardBar.ini";  // Caminho do arquivo INI
	char section[32];

	// Constrói o nome da seção com base no RewardOrder
	sprintf_s(section, "ITEM_ORDER_%02d", RewardOrder);

	// Tenta ler o valor de Time da seção correspondente
	int time = GetPrivateProfileIntA(section, "Time", 0, iniFile);

	// Verifica se o valor foi encontrado (se for 0, significa que não encontrou)
	if (time == 0) {
		LogErrorToFile(L"Nenhum valor encontrado para o parâmetro Time.");
		return -1;  // Retorna -1 se não encontrou o valor
	}

	// Caso tenha encontrado, retorna o valor de Time
	return time;
}

int getNextRewardOrder(int UserUID)
{
	CStringW sql;
	sql.Format(
		L"DECLARE @NextRewardOrder INT; "
		L"EXEC GetNextRewardOrder @UserUID = %d, @NextRewardOrder = @NextRewardOrder OUTPUT; "
		L"SELECT @NextRewardOrder AS NextRewardOrder;",
		UserUID);

	try
	{
		CString resultado = g_DBobj.ExeSqlByCommand(sql, L"NextRewardOrder");

		if (resultado.IsEmpty())
		{
			LogErrorToFile(L"Resultado vazio ao executar GetNextRewardOrder.");
			return -1;
		}

		// Conversão segura para int
		int valorResultado = 0;
		if (swscanf_s(resultado, L"%d", &valorResultado) == 1)
		{
			return valorResultado;
		}
		else
		{
			LogErrorToFile(L"Falha na conversão do resultado para inteiro.");
			return -1;
		}
	}
	catch (...)
	{
		LogErrorToFile(L"Erro ao executar a stored procedure GetNextRewardOrder.");
		return -1;
	}
}



int select2ndQuickSlotChar(int CharID, int resultArray[11]) {
	CStringW sql;
	sql.Format(L"SELECT Bag, Slot, SlotEquiped, Type, TypeID, Bag2, Slot2, SlotEquiped2, Type2, TypeID2 FROM PS_GameData.dbo.[2ndQuickSlotChars] WHERE CharID = %d", CharID);

	try {
		if (g_DBobj.ExeSqlByCommand(sql)) {
			// Limpa o array de resultados
			memset(resultArray, 0, sizeof(int) * 11);

			int index = 0;
			// Obtém os valores dos slots
			while (!g_DBobj.IsEmpty() && index < 11) {
				// Assumindo que cada coluna representa um valor do array
				resultArray[index++] = _wtoi(g_DBobj.GetValueByField(L"Bag"));
				resultArray[index++] = _wtoi(g_DBobj.GetValueByField(L"Slot"));
				// Convertendo o valor de SlotEquiped para 0 ou 1
				resultArray[index++] = (_wtoi(g_DBobj.GetValueByField(L"SlotEquiped")) != 0) ? 1 : 0;
				resultArray[index++] = _wtoi(g_DBobj.GetValueByField(L"Type"));
				resultArray[index++] = _wtoi(g_DBobj.GetValueByField(L"TypeID"));
				resultArray[index++] = _wtoi(g_DBobj.GetValueByField(L"Bag2"));
				resultArray[index++] = _wtoi(g_DBobj.GetValueByField(L"Slot2"));
				// Convertendo o valor de SlotEquiped2 para 0 ou 1
				resultArray[index++] = (_wtoi(g_DBobj.GetValueByField(L"SlotEquiped2")) != 0) ? 1 : 0;
				resultArray[index++] = _wtoi(g_DBobj.GetValueByField(L"Type2"));
				resultArray[index++] = _wtoi(g_DBobj.GetValueByField(L"TypeID2"));

				g_DBobj.MoveNext();
			}

			return 0; // Retorna 0 em caso de sucesso
		}
		else {
			return -1; // Retorna -1 em caso de falha
		}
	}
	catch (...) {
		// Log("Erro ao executar a consulta.");
		return -1; // Retorna -1 em caso de exceção
	}
}

int upsertRewardBarLog(int UserUID, int RewardOrder, const SYSTEMTIME& ActionTime)
{
	CStringW sql;
	CStringW actionTimeStr;

	// Converter SYSTEMTIME para string no formato DATETIME
	actionTimeStr.Format(L"%04d-%02d-%02d %02d:%02d:%02d",
		ActionTime.wYear, ActionTime.wMonth, ActionTime.wDay,
		ActionTime.wHour, ActionTime.wMinute, ActionTime.wSecond);

	// Formatar a consulta SQL
	sql.Format(
		L"EXEC upsertRewardBarLog @UserUID = %d, @RewardOrder = %d, @ActionTime = '%s'",
		UserUID, RewardOrder, actionTimeStr);

	try {
		// Executar a consulta SQL
		bool success = g_DBobj.ExeSqlByCommand(sql);
		return success ? 0 : -1;
	}
	catch (const _com_error& e) {
		LogErrorToFile(L"Erro COM ao executar a stored procedure upsertRewardBarLog");
		return -1;
	}
	catch (...) {
		// Capturar e registrar outros erros
		LogErrorToFile(L"Erro desconhecido ao executar a stored procedure upsertRewardBarLog.");
		return -1;
	}
}



int selectRewardBar(int OrderID, int resultArrayReward[4]) {
	// Caminho do arquivo INI
	const char* iniFile = ".\\RewardBar.ini";

	// Limpa o array de resultados
	std::memset(resultArrayReward, 0, sizeof(int) * 4);

	// Construa a chave de seção ITEM_ORDER_0%d com base no OrderID
	char section[32];
	sprintf_s(section, "ITEM_ORDER_%02d", OrderID);

	// Ler os valores do arquivo INI
	int rewardType = GetPrivateProfileIntA(section, "RewardType", 0, iniFile);
	int rewardTypeID = GetPrivateProfileIntA(section, "RewardTypeID", 0, iniFile);
	int count = GetPrivateProfileIntA(section, "Count", 0, iniFile);
	int time = GetPrivateProfileIntA(section, "Time", 0, iniFile);

	// Armazena os valores lidos no array de resultados
	resultArrayReward[0] = rewardType;
	resultArrayReward[1] = rewardTypeID;
	resultArrayReward[2] = count;
	resultArrayReward[3] = time;

	// Caso o OrderID tenha mais de 1 item, você pode adicionar uma lógica para iterar mais ou expandir o array se necessário
	// Aqui é possível adicionar verificações de falhas no arquivo INI (se não encontrado, usa 0 como valor por padrão)

	return 0;
}

int resultByteCounts = 0;


struct ItemOrder {
	int rewardType;
	int rewardTypeID;
	int time;
};

int selectAndSortRewardTypes(char* resultArray) {
	// Caminho do arquivo INI
	const char* iniFile = ".\\RewardBar.ini";

	ItemOrder itemOrders[20]; // Supondo que você tenha até 6 itens, ajuste conforme necessário

	// Ler os valores do arquivo INI
	for (int i = 0; i < 20; i++) {
		// Construa a chave de seção ITEM_ORDER_0%d
		char section[32];
		sprintf_s(section, "ITEM_ORDER_%02d", i);

		// Ler os valores do arquivo INI
		itemOrders[i].rewardType = GetPrivateProfileIntA(section, "RewardType", 0, iniFile);
		itemOrders[i].rewardTypeID = GetPrivateProfileIntA(section, "RewardTypeID", 0, iniFile);
		itemOrders[i].time = GetPrivateProfileIntA(section, "Time", 0, iniFile);
	}

	// Limpa o array de resultados
	std::memset(resultArray, 0, sizeof(char) * 225); // Ajuste o tamanho para 225 (75 * 3) para armazenar 75 valores com espaçamento

	int index = 0;
	resultByteCounts = 0; // Inicializa o contador de bytes

	// Itera sobre os itens e armazena no array
	for (int i = 0; i < 20; i++) {
		int rewardType = itemOrders[i].rewardType;
		int rewardTypeID = itemOrders[i].rewardTypeID;
		int time = itemOrders[i].time;

		// Armazena os valores no array com espaçamento de 2 bytes entre cada valor
		resultArray[index] = static_cast<char>(rewardType);
		index += 2; // Pula 2 bytes de espaçamento

		if (index < 225) {
			resultArray[index] = static_cast<char>(rewardTypeID);
			index += 2; // Pula 2 bytes de espaçamento
		}
		if (index < 225) {
			std::memcpy(&resultArray[index], &time, sizeof(int));
			index += 4; // Pula 4 bytes de espaçamento
		}

		resultByteCounts += 8; // Incrementa o contador de bytes armazenados
	}

	return 0;
}

int g_LastRewardOrder;

int getLastRewardOrder() {
	const char* iniFile = ".\\RewardBar.ini"; // Caminho do arquivo INI

	

	// Define o número máximo de itens que você quer verificar
	const int maxOrderID = 15;  // Exemplo, você pode ajustar conforme necessário

	// Itera sobre as seções do arquivo INI, começando de 1 até maxOrderID
	for (int orderID = 1; orderID <= maxOrderID; orderID++) {
		char section[32];
		sprintf_s(section, "ITEM_ORDER_%02d", orderID);  

		
		int rewardOrder = GetPrivateProfileIntA(section, "RewardType", 0, iniFile);

	
		if (rewardOrder != 0) {
			g_LastRewardOrder = orderID;  
		}
	}

	
	if (g_LastRewardOrder == 0) {
		LogErrorToFile(L"Nenhum RewardOrder encontrado nas seções ITEM_ORDER_.");
		return -1;
	}

	return 0;
}


void getUserPermissions(int UserUID, DWORD CPlayer) {
	if (CPlayer == NULL) {
		LogErrorToFile(L"CPlayer é nulo.");
		return;
	}


	try {

		nanodbc::connection conn(NANODBC_TEXT("Driver={SQL Server};Server=127.0.0.1;Database=PS_UserData;Uid=PSM;Pwd=n*xD10x*Lsm;"));

	
		nanodbc::statement stmt(conn);
		nanodbc::prepare(stmt, NANODBC_TEXT(
			"SELECT CanDropItems, CanInitiateBattle, CanInitiateTrade, CanInitiateMarket, "
			"CanUseAuctionBoard, CanNPCItems, CanNPCLinkedEnchantedItems, CanUseWarehouse "
			"FROM dbo.Users_Master WITH (NOLOCK) WHERE UserUID = ? OPTION (RECOMPILE)"
		));
		stmt.bind(0, &UserUID);

		nanodbc::result result = nanodbc::execute(stmt);

		if (!result.next()) {
			LogErrorToFile(L"UserUID: " + std::to_wstring(UserUID) + L" não encontrado.");
			return;
		}

		
		BYTE* offsets[] = {
			(BYTE*)(CPlayer + 0x6380), (BYTE*)(CPlayer + 0x6382), (BYTE*)(CPlayer + 0x6384),
			(BYTE*)(CPlayer + 0x6386), (BYTE*)(CPlayer + 0x6388), (BYTE*)(CPlayer + 0x6390),
			(BYTE*)(CPlayer + 0x6392), (BYTE*)(CPlayer + 0x6394)
		};

	
		for (int i = 0; i < 8; i++) {
			if (result.is_null(i)) {
				LogErrorToFile(L"UserUID: " + std::to_wstring(UserUID) + L" | Campo nulo no índice: " + std::to_wstring(i));
				continue;
			}

			int value = result.get<int>(i);

			// Evita acesso a ponteiros inválidos (pode usar validação extra se necessário)
			if (offsets[i] == nullptr) {
				LogErrorToFile(L"UserUID: " + std::to_wstring(UserUID) + L" | Ponteiro inválido para offset: " + std::to_wstring((DWORD)offsets[i]));
				continue;
			}

			// Escreve o valor na memória do jogador
			*offsets[i] = static_cast<BYTE>(value);
		}
	}
	catch (const std::exception& ex) {
		std::wstring wstr(ex.what(), ex.what() + strlen(ex.what()));
		LogErrorToFile(L"Exception: " + wstr);
	}
	catch (...) {
		LogErrorToFile(L"Exceção desconhecida ao obter permissões para UserUID: " + std::to_wstring(UserUID));
	}
}