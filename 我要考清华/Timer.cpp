#include "functionTest.h"


//	modIt(double a, int b)	��double��mod
double modIt(double a, int b)
{
	while (a > b)
	{
		a -= b;
	}
	return a;
}

//	printTime(double consumeTime)	������ʱ��
void printTime(double consumeTime)
{
	bool hourFlag = false;
	if (consumeTime > 3600) {
		cout << int(consumeTime / 3600) << "h ";
		consumeTime = modIt(consumeTime, 3600);
		hourFlag = true;
	}
	if (consumeTime > 60 || hourFlag == true) {
		cout << int(consumeTime / 60) << "min ";
		consumeTime = modIt(consumeTime, 60);
	}
	cout << consumeTime << "s\n";
}

//	getTime()	��ʽ�����ʱ��
void getTime()
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	printf("%4d/%02d/%02d\t����%1d\t%02d:%02d:%02d\n", sys.wYear, sys.wMonth, sys.wDay, sys.wDayOfWeek, sys.wHour, sys.wMinute, sys.wSecond);
}