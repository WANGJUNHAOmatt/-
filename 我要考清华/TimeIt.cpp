#include "functionTest.h"
#include "TimeIt.h"

void TimeIt::getTime(void) {
	char dayOfWeek[7][4] {
		"��", "һ", "��", "��", "��", "��", "��"
	};
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	printf("%4d/%02d/%02d ����%s %02d:%02d:%02d\n", sys.wYear, sys.wMonth, sys.wDay, dayOfWeek[sys.wDayOfWeek], sys.wHour, sys.wMinute, sys.wSecond);
}

string TimeIt::getTime_t(int x) {
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	char p[30];
	x ? strftime(p, 30, "%F %T", &timeinfo) : strftime(p, 30, "%F %T %A", &timeinfo);
	string nowTime = p;
	return nowTime;
}

void TimeIt::countDown(void) {
	int countDownHH, countDownMM, countDownSS;
	cout << "���������赹��ʱ��ʱ�� (hours minutes seconds)���Ի��н�������:";
	cin >> countDownHH >> countDownMM >> countDownSS;
	countDownSS += countDownHH * 3600 + countDownMM * 60;
	countDownSS *= 1000;
	Sleep(countDownSS);
	cout << "ʱ�䵽������" << endl;
	countDownHH > 0 || countDownMM >= 1 ? songOfJoy() : familyWithChildren();
}

void TimeIt::reset(void) {
	consumeTime = consumeTime_buf = 0;
}

void TimeIt::start(void) {
	begin = clock();
}

void TimeIt::pause(void) {
	finish = clock();
	consumeTime_buf = (int)(finish - begin) / CLOCKS_PER_SEC;
	consumeTime += consumeTime_buf;
	show();
}

void TimeIt::stop(void) {
	system("cls");
	show();
	timerFlag = false;
	reset();
}

void TimeIt::show(void) {
	if (consumeTime >= 3600) {
		cout << consumeTime / 3600 << "Сʱ";
		consumeTime %= 3600;
	}
	if (consumeTime >= 60) {
		cout << consumeTime / 60 << "����";
		consumeTime %= 60;
	}
	cout << consumeTime << "��" << endl;
}

void TimeIt::Timer(void) {
	reset();
	system("title ��ʱ��");
	timerFlag = true;
	cout << "�������ⰴ���Կ�ʼ��ʱ\n";
	_getch();
	start();
	while (timerFlag) {
		system("cls");
		cout << "********************************************************��ʱ��********************************************************\n";
		cout << "�������ⰴ������ͣ��ʱ\n";
		_getch();
		system("cls");
		cout << "********************************************************��ʱ��********************************************************\n";
		pause();
		cout << "ֹͣ�밴0�����ఴ������\n";
		char timerControler = _getch();
		timerControler == '0' ? stop() : start();
	}
	_getch();
}