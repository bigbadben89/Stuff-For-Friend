#include "pch.h"
#include "database.h"

CDataBase::CDataBase(void)
{
	m_vecDATABASE.clear();
	m_dwIndex = 0;
}

BOOL CDataBase::LinkDataBase()
{
	CoInitialize(NULL);
	try
	{
		HRESULT hr1 = m_pConnect.CreateInstance(L"ADODB.Connection");
		if (FAILED(hr1))
		{
			return FALSE;
		}
	}
	catch (_com_error)
	{
		OutputDebugString(L"");
	}

	Sleep(500); // Delay the function for a bit

	try {

		wchar_t szUsername[255]; // Initialize the username variable and declare a buffer size
		wchar_t szPassword[255]; // Initialize the password variable and declare a buffer size

		// Get the username and password from the configuration (INI) file
		GetPrivateProfileString(L"ServerTest", L"Uid", L"", szUsername, 255, L".\\evolved.ini"); // Get username key
		GetPrivateProfileString(L"ServerTest", L"Pwd", L"", szPassword, 255, L".\\evolved.ini"); // Get password key

		CString szLink; // Initialize the connection string variable
		CString szUid = szUsername; // Convert the username to a string
		CString szPwd = szPassword; // Convert the password to a string


		szLink.Format(L"Provider=SQLOLEDB;Server=127.0.0.1;Database=PS_GameData;");

		// Connect to the SQL Server database
		m_pConnect->Open(_bstr_t(szLink), _bstr_t(szUid), _bstr_t(szPwd), adModeUnknown);

		return TRUE;
	}
	catch (_com_error& e) {
		std::wstring errorMessage = (LPCTSTR)(CString(L"Erro ao Conectar: ") + CString(e.ErrorMessage()));
		LogErrorToFile(errorMessage);
		DisconnectDataBase();
		return FALSE;
	}
	return TRUE;
}




BOOL CDataBase::ExeSqlByCon(CString szSql)
{
	try {
		m_pConnect->Execute(_bstr_t(szSql), NULL, 1);
	}
	catch (_com_error)
	{
		return FALSE;
	}
	return TRUE;
}

void CDataBase::DisconnectDataBase() {
    if (m_pConnect) {
        if (m_pConnect->State == adStateOpen) {
            m_pConnect->Close();
        }
        m_pConnect.Release();
        m_pConnect = nullptr;
    }
}

BOOL CDataBase::IsConnected()
{
	try
	{
		// Check if the connection is open
		if (m_pConnect->State == adStateOpen)
		{
			return TRUE;
		}
	}
	catch (_com_error)
	{
		// Handle any errors if necessary
	}

	// If not connected, return FALSE
	return FALSE;
}