#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <psapi.h>
#include<iostream>
// To ensure correct resolution of symbols, add Psapi.lib to TARGETLIBS
// and compile with -DPSAPI_VERSION=1
int c = 0;
int PrintProcessNameAndID(DWORD processID, std::string &sError)
{
	TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

	// Get a handle to the process.
	//Opens an existing local process object
	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
		PROCESS_VM_READ,
		FALSE, processID);

	// Get the process name.

	int i = GetLastError();

	if (NULL != hProcess)
	{
		//HMODULE hMod;
		HANDLE hMod;
		DWORD cbNeeded;
		//Retrieves a handle for each module in the specified process
        //This function fills an array of HMODULE values with the module handles for the specified process
		if (EnumProcessModules(hProcess, (HMODULE *)&hMod, sizeof(hMod),
			&cbNeeded))
		{
			c++;
			GetModuleBaseName(hProcess, (HMODULE)hMod, szProcessName,
				sizeof(szProcessName) / sizeof(TCHAR));
			_tprintf(TEXT("%s  (PID: %u)\n"), szProcessName, processID);
			CloseHandle(hProcess);
			return 1;

		}
		else {
			CloseHandle(hProcess);
			sError = "Base address not found";
			return 0;
		}
	}
	else {
		CloseHandle(hProcess);
		sError = "Handle not found";
		return 0;
	}

	// Print the process name and identifier.

	//_tprintf(TEXT("%s  (PID: %u)\n"), szProcessName, processID);

	// Release the handle to the process.

	
}

int main(void)
{
	// Get the list of process identifiers.
	
	DWORD aProcesses[1024], cbNeeded, cProcesses;
	unsigned int i;


	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
	{
		return 1;

	}


	// Calculate how many process identifiers were returned.

	cProcesses = cbNeeded / sizeof(DWORD);

	std::string sError;

	// Print the name and process identifier for each process.

	for (i = 0; i < cProcesses; i++)
	{
		if (aProcesses[i] != 0)
		{
			if (!PrintProcessNameAndID(aProcesses[i], sError)) {
				std::cout << sError.c_str() << std::endl;
			}
		}
	}
	std::cout<<"Total:"<< cProcesses<<"No displayed:"<< c;

	return 0;
}