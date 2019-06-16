// Client_MyDll.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<Windows.h>

typedef int(*FNPTR1) (int, int);
typedef int(*FNPTR2) (int, int);
typedef double(*FNPTR3) (int, int);
typedef float(*FNPTR4) (int, int);
int main()
{
	int a, b;
	HINSTANCE hInst = LoadLibrary(L"C:\\Users\\harla\\Documents\\Visual Studio 2017\\Harla's DLLs\\MyDll.dll");//Path where dll is located
	if (!hInst)
	{
		std::cout << "\nCould not load the Library\n";
		return 1;
	}
	
	//Resolve the function address
	FNPTR1 fp1 = (FNPTR1)GetProcAddress(hInst, "?add@MyDll@@SAHHH@Z");//Name mangling
												//Name found using DUMPBIN /EXPORTS "DLL_PATH\MyDll.dll"
	if (!fp1)
	{
		std::cout << "Could not locate the add function";
		return 1;
	}
	FNPTR2 fp2 = (FNPTR2)GetProcAddress(hInst, "?subtract@MyDll@@SAHHH@Z");//Name mangling
	if (!fp2)									//Name found using DUMPBIN /EXPORTS "DLL_PATH\MyDll.dll"
	{
		std::cout << "Could not locate the subtract function";
		return 1;
	}
	FNPTR3 fp3 = (FNPTR3)GetProcAddress(hInst, "?multiply@MyDll@@SANHH@Z");//Name mangling
	if (!fp3)                                   //Name found using DUMPBIN /EXPORTS "DLL_PATH\MyDll.dll"
	{
		std::cout << "Could not locate the multiply function";
		return 1;             
	}
	FNPTR4 fp4 = (FNPTR4)GetProcAddress(hInst, "?divide@MyDll@@SAMHH@Z");
	if (!fp4)
	{
		std::cout << "Could not locate the divide function";
		return 1;
	}
	
	std::cout << "Enter the value for a :\n";
	std::cin >> a;
	std::cout << "Enter the value for b :\n";
	std::cin >> b;
	std::cout << "The sum is :  " << fp1(a, b);
	std::cout << "The difference is : " << fp2(a, b);
	std::cout << "The product is :" << fp3(a, b);
	std::cout << "The division is : " << fp4(a, b);
	
	FreeLibrary(hInst);
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
