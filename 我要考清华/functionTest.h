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


void changeColor(int word = 7, int background = 0);

void addLog(string logData);
void contentEnter(void);
string contentEnter_sub(void);
void insertLog(void);

enum color {
	��ɫ, ����ɫ, ����ɫ, ����ɫ,���ɫ, ���ɫ, ���ɫ, ���ɫ,
	��ɫ, ǳ��ɫ, ǳ��ɫ, ǳ��ɫ,ǳ��ɫ, ǳ��ɫ, ǳ��ɫ, ǳ��ɫ,
};