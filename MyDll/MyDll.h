#ifndef ARITHMETIC_F_
#define ARITHMETIC_F_

class MyDll
{
public:
	MyDll();
	~MyDll();
    __declspec(dllexport) static int add(int a,int b);
	__declspec(dllexport) static int  subtract(int a, int b);
	__declspec(dllexport) static double  multiply(int a, int b);
	__declspec(dllexport) static float  divide(int a, int b);
};
#endif //ARITHMETIC_F_	