#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <conio.h>	//	getch();
#include <Windows.h>


using namespace std;
void sendOff(void);
void songOfJoy(void);
void peppaPig(void);
void familyWithChildren(void);
void printTime(double consumeTime);
string printTime_t(double consumeTime);
void changeColor(int word = 7, int background = 0);
void addLog(string logData);
//void eventAdd(void);
//void clockPlay(void);

enum color {
	��ɫ, ����ɫ, ����ɫ, ����ɫ,���ɫ, ���ɫ, ���ɫ, ���ɫ,
	��ɫ, ǳ��ɫ, ǳ��ɫ, ǳ��ɫ,ǳ��ɫ, ǳ��ɫ, ǳ��ɫ, ǳ��ɫ,
};