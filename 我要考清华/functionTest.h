#pragma once
#include <conio.h>	//	getch();
#include <Windows.h>
#include <ctime>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>


void sendOff(void);
void songOfJoy(void);
void peppaPig(void);
void familyWithChildren(void);


void changeColor(int word = 7, int background = 0);

void addLog(std::string logData);
void contentEnter(void);
std::string contentEnter_sub(void);
void insertLog(void);
void insertMood(void);
void makeWorkPath(void);
std::string getWorkPath(int flag = 0);

enum color {
	��ɫ, ����ɫ, ����ɫ, ����ɫ,���ɫ, ���ɫ, ���ɫ, ���ɫ,
	��ɫ, ǳ��ɫ, ǳ��ɫ, ǳ��ɫ,ǳ��ɫ, ǳ��ɫ, ǳ��ɫ, ǳ��ɫ,
};