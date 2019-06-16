// CreateRegistryKey.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Creates a new Key called MyVeryOwnKey under WOW6432

#include <iostream>
#include<windows.h>
      
HKEY OpenRegistryKey(HKEY hRootKey, const wchar_t* strSubKey)
{
	HKEY hKey;
				//Opens the specified registry key
						  //^
						  //| //A handle to an open registry key. This handle is returned by the RegCreateKeyEx 
						  //|    //|                                     //pointer to a variable that receives a handle to the opened key
	LONG lError = RegOpenKeyEx(hRootKey, strSubKey, NULL, KEY_ALL_ACCESS, &hKey);
											//^				//^
											//|         //A mask that specifies the desired access rights to the key to be opened
											//|
									// name of the registry subkey to be opened
	
	if (ERROR_FILE_NOT_FOUND == lError)
	{
		//Create a key
		lError = RegCreateKeyEx(hRootKey, strSubKey, NULL, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);

	}
	if (lError != ERROR_SUCCESS)
	{
		std::cout << "Something is wrong.Could not open or create a key";

	}
	return hKey;
}

int main()
{
	//Open Registry Key
	//If key not present, create one
	HKEY hKey = OpenRegistryKey(HKEY_LOCAL_MACHINE, L"SOFTWARE\\MyVeryOwnKey");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
