// MyDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "MyDll.h"
#include<iostream>


extern "C" __declspec(dllexport)  int  MyDll::add(int a, int b)
	{
		return a + b;
	}
extern "C" __declspec(dllexport) int  MyDll::subtract(int a, int b)
	{
		return a - b;
	}
extern "C" __declspec(dllexport) double  MyDll::multiply(int a, int b)
	{
		return a * b;
	}
extern "C"	__declspec(dllexport) float MyDll::divide(int a, int b)
	{
		if (b == 0)
			return -1;
		else
			return a / b;
	}
		


