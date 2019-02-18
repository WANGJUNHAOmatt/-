#include "functionTest.h"
#include "TimeIt.h"
#include <sstream>
#include <iomanip>

void TimeIt::getTime(void) {
	char dayOfWeek[7][4] {
		"��", "һ", "��", "��", "��", "��", "��"
	};
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	printf("%4d/%02d/%02d ����%s %02d:%02d:%02d\n", sys.wYear, sys.wMonth, sys.wDay, dayOfWeek[sys.wDayOfWeek], sys.wHour, sys.wMinute, sys.wSecond);
}

string TimeIt::getTime_t(void) {
	stringstream ss;
	string getTimeIt;
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	ss << setw(4) <<sys.wYear << '/' << setw(2) << setfill('0') <<sys.wMonth << '/' 
		<< setw(2) << setfill('0') << sys.wDay << '-' 
		<< setw(2) << setfill('0') << sys.wHour << ':' 
		<< setw(2) << setfill('0') << sys.wMinute << ':' 
		<< setw(2) << setfill('0') << sys.wSecond;
	ss >> getTimeIt;
	return getTimeIt;
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
	timerFlag = false;
}

string TimeIt::show(void) {
	stringstream ss;
	string consumeTimePrint;
	if (consumeTime >= 3600) {
		ss << consumeTime / 3600 << "Сʱ";
		consumeTime %= 3600;
	}
	if (consumeTime >= 60) {
		ss << consumeTime / 60 << "����";
		consumeTime %= 60;
	}
	ss << consumeTime << "��";
	ss >> consumeTimePrint;
	cout << consumeTimePrint << endl;
	return consumeTimePrint;
}

string TimeIt::Timer(void) {
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
		if (timerControler == '0') {
			stop();
			return show();
		}
		else {
			start();
		}
	}
	_getch();
	return "";
}


string TimeIt::toStd(int year, int month, int day, int hour, int minute, int second) {
	stringstream ss;
	string stdTime;
	ss << setw(4) << year << '/' 
		<< setw(2) << setfill('0') << month << '/'
		<< setw(2) << setfill('0') << day << '-'
		<< setw(2) << setfill('0') << hour << ':'
		<< setw(2) << setfill('0') << minute << ':'
		<< setw(2) << setfill('0') << second;
	ss >> stdTime;
	return stdTime;
}

string TimeIt::stdSubtract(string a, string b)
{
	return string();
}
