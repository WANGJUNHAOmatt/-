#include "functionTest.h"
#include "TimeIt.h"
#include <sstream>
#include <iomanip>
using namespace std;


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


void TimeIt::newCountDown(void) {
	/*
		˼·��
			do{
				��ȡ��ǰʱ�䣬
				���㵱ǰʱ���Ŀ��ʱ��Ĳ�ֵ��
				��ʾ��ǰʣ��ʱ�䣬
			}while����ǰʱ��С��Ŀ��ʱ�䣩
	*/
}


void TimeIt::reset(void) {
	consumeTime_buf = consumeTime = 0;
}

void TimeIt::start(void) {
	begin = clock();
}

void TimeIt::pause(void) {
	finish = clock();
	consumeTime_buf = (double)(finish - begin) / CLOCKS_PER_SEC;
	consumeTime += int(consumeTime_buf+0.5) ;
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
	}
	if (consumeTime >= 60) {
		ss << consumeTime % 3600 / 60 << "����";
	}
	ss << consumeTime % 60 << "��";
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
	int yearA, yearB, monthA, monthB, dayA, dayB, hourA, hourB, minA, minB, secA, secB;
	char buf;
	stringstream ss;
	ss << a;
	ss >> yearA >> buf >> monthA >> buf >> dayA >> buf >> hourA >> buf >> minA >> buf >> secA;
	ss.clear();
	ss << b;
	ss >> yearB >> buf >> monthB >> buf >> dayB >> buf >> hourB >> buf >> minB >> buf >> secB;
	//printf("%d/%d/%d %d:%d:%d\n", yearA, monthA, dayA, hourA, minA, secA);
	//printf("%d/%d/%d %d:%d:%d\n", yearB, monthB, dayB, hourB, minB, secB);
	if (yearA == yearB && monthA == monthB && dayA == dayB) {
		return TimeSub(hourA, minA, secA, hourB, minB, secB);
	}
	//	��ʵ��û�л������е��⣬����
	cout << "��δ֧�ֲ���ͬһ���ʱ����㣡����\n";
	return string();
}

string TimeIt::TimeSub(int h1, int m1, int s1, int h2, int m2, int s2) {
	int sec, min, hour;
	string spendTime;
	stringstream ss;
	if (h1 > h2 || (h1 == h2 && m1 > m2) || (h1 == h2 && m1 == m2 && s1 > s2)) {
		s1 >= s2 ? sec = s1 - s2 : (sec = s1 + 60 - s2, m1--);
		m1 >= m2 ? min = m1 - m2 : (min = m1 + 60 - m2, h1--);
		hour = h1 - h2;
		if (hour) {
			ss << hour << "Сʱ" << min << "����" << sec << "��";
		}
		else if (min) {
			ss << min << "����" << sec << "��";
		}
		else {
			ss << sec << "��";
		}
		ss >> spendTime;
		return spendTime;
	}
	else {
		cout << "�����ʱ�䣬���Ϊ����������\n";
		return "Error";
	}
}