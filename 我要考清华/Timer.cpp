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


//	getTime_()	��ʽ�����ʱ�� ������
/*
	�������ϳ������⣡����
	2019/1/27 0:47
*/
void getTime_(void)
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	printf("%4d/%02d/%02d\t����%d\t%02d:%02d:%02d\n", sys.wYear, sys.wMonth, sys.wDay, sys.wDayOfWeek, sys.wHour, sys.wMinute, sys.wSecond);
	cout << sys.wDayOfWeek << endl;
}

void getTime(void)
{
	cout << getTime_t() << endl;
}


string getTime_t(int x)
{
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	char p[30];
	x ? strftime(p, 30, "%F %T", &timeinfo) : strftime(p, 30, "%F %T %A", &timeinfo);
	string nowTime = p;
	return nowTime;
}