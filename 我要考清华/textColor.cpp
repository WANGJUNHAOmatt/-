#include "functionTest.h"

void changeColor(int word, int background)
{
	//	word
	//	1   ����ɫ
	//	2   ����ɫ
	//	3   ����ɫ
	//	4   ���ɫ
	//	5   ���ɫ
	//	6   ��ɫ
	//	7   ���ɫ
	//	8   ��ɫ
	//	9   ǳ��ɫ
	//	10  ǳ��ɫ
	//	11  ǳ��ɫ
	//	12  ǳ��ɫ
	//	13  ǳ��ɫ
	//	14  ǳ��ɫ
	//	15  ǳ��ɫ

	//	background
	//	1~15        ��ɫ
	//	16~31       ����ɫ
	//	32~47       ����ɫ
	//	48~63       ����ɫ
	//	64~79       ���ɫ
	//	80~95       ���ɫ
	//	96~111      ���ɫ
	//	112~127     ���ɫ
	//	128~143     ��ɫ
	//	144~159     ǳ��ɫ
	//	160~175     ǳ��ɫ
	//	176~191     ǳ��ɫ
	//	192~207     ǳ��ɫ
	//	208~223     ǳ��ɫ
	//	224~239     ǳ��ɫ
	//	240~255     ǳ��ɫ
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);//���
	SetConsoleTextAttribute(hout, word + background * 16);
}


//	����
	//HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);//���
	//cout << "ԭɫ" << endl;
	//SetConsoleTextAttribute(hout, 7);//û�������ɫ��ԭɫ
	//cout << "ԭɫ" << endl;
	//SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//��ɫ��ӣ���ɫ
	//cout << "��ɫ" << endl;
	//SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_RED);//��ɫ
	//cout << "��ɫ" << endl;
	//SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_GREEN);//��ɫ
	//cout << "��ɫ" << endl;
	//SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_BLUE);//��ɫ
	//cout << "��ɫ" << endl;
	//SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);//��ɫ����ɫ��ӣ���ɫ
	//cout << "��ɫ" << endl;
	//SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);//��ɫ����ɫ��ӣ���ɫ
	//cout << "��ɫ" << endl;
	//SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);//��ɫ����ɫ��ӣ���ɫ
	//cout << "��ɫ" << endl;
	//SetConsoleTextAttribute(hout, 64 + 15);
	//cout << "���ɫ������ɫ��ǳ��ɫ������ɫ" << endl;
	//SetConsoleTextAttribute(hout, 79);
	//cout << "���ɫ������ɫ��ǳ��ɫ������ɫ" << endl;