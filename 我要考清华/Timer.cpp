#include "functionTest.h"
#include <sstream>


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


string printTime_t(double consumTime) {
	int consumSec = int(consumTime + 0.5);
	string timeBuf;
	stringstream ss;
	ss << consumSec / 3600 << "Сʱ" << consumSec % 3600 / 60 << "����" << consumSec % 60 << "��";
	ss >> timeBuf;
	return timeBuf;
}


//	getTime()	��ʽ�����ʱ��
void getTime(void)
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	printf("%4d/%02d/%02d\t����%1d\t%02d:%02d:%02d\n", sys.wYear, sys.wMonth, sys.wDay, sys.wDayOfWeek, sys.wHour, sys.wMinute, sys.wSecond);
}


string getTime_t(void)
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	stringstream ss;
	string localTime;
	ss << sys.wYear << "��" << sys.wMonth << "��" << sys.wDay << "��-" << sys.wHour<< "ʱ"<< sys.wMinute << "��" << sys.wSecond << "��";
	ss >> localTime;
	return localTime;
}