#include "functionTest.h"
#include "TimeIt.h"
#include "Event_V2.h"
#include <iostream>
using std::string;
using std::cout;
using std::endl;
//using namespace std;	//	��Ȼ����function.h�а����� using namespace std ������ʱ���ǻᱨ��
						//	2019/12/6	ͷ�ļ��иĳ�std::����ʽ��
//	�汾����
string versionInf = "0.1.4,Ϊ2.0�汾���̵棬����Event�࣬ϣ������ʵ�֣���������ȼ����������������ͳ�Ƽ�����Ŀǰʵ���˲����Ʋ����Ĵ���Ͷ�ȡ,2019/12/06";

//	��������������
bool mainFlag = true;
char mainControler;


int main(void)
{
	system("title ��Ҫ���廪!!!");
	TimeIt timeIt;
	timeIt.getTime();
	cout << timeIt.getTime_t();
	//cout << "\nWhere there is a will, there is a way!\t��־�ߣ��¾��ɣ�\n";
	cout << "Now version is " << versionInf << "\n\n\n";
	makeWorkPath();
	/*
		Event class test
	*/
	Event super_root;
	super_root.load();
	//	end
	while (mainFlag)
	{
		system("title ��Ҫ���廪!!!");
		cout << "���������֣�(1)��¼ʱ�� (2)�����¼ (3)��ѯ��¼_�����Ƴ� (4)�������_�����Ƴ� (5)��¼�Կ���+������־ (6)���԰������־ (8)��ʱ�� (9)����ʱ (0)�˳�����\n";
		mainControler = _getch();
		switch (mainControler) {
		case '1':
			//	ʱ���¼
			contentEnter();
			break;

		case '2':
			//	�����¼
			insertLog();
			break;

		case '3':
			//	��ѯʱ��_������

			break;

		case '4':
			//	����ʱ��_������

			break;

		case '5':
			//	���顢�Կ�����־
			insertMood();
			break;

		case '6':
			super_root.add();
			super_root.save();
			break;

		case '7':
			//	�ʵ�
			familyWithChildren();
			break;

		case '8':
			//	��ʱ��
			timeIt.Timer();
			break;

		case '9':
			//	����ʱ
			timeIt.countDown();
			break;

		case '0':
			//	�˳�����
			mainFlag = false;
			break;

		default:
			cout << "����İ���! ����������!\n";
			break;
		}
	}
	cout << "�ټ������ͣ�\n";
	sendOff();
	return 0;
}
