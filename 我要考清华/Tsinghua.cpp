#include "functionTest.h"
#include "TimeIt.h"
//using namespace std;	//	��Ȼ����function.h�а����� using namespace std ������ʱ���ǻᱨ��

//	�汾����
string versionInf = "0.1.1,�޲�����0.1.0�г��ֵ�show()����ˢ�µ��µļ�¼ʱ�����ʱ���������,2019/02/20";


//	��������������
bool mainFlag = true;
char mainControler;


int main(void)
{
	system("title ��Ҫ���廪!!!");
	TimeIt timeIt;
	timeIt.getTime();
	cout << timeIt.getTime_t();
	cout << "\nWhere there is a will, there is a way!\t��־�ߣ��¾��ɣ�\n";
	cout << "Now version is " << versionInf << "\n\n\n";
	makeWorkPath();

	while (mainFlag)
	{
		system("title ��Ҫ���廪!!!");
		cout << "���������֣�(1)��¼ʱ�� (2)�����¼ (3)��ѯ��¼_�����Ƴ� (4)�������_�����Ƴ� (5)��¼������־ (8)��ʱ�� (9)����ʱ (0)�˳�����\n";
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
			//	������־
			insertMood();
			break;

		case '8':
			//	��ʱ��
			timeIt.Timer();
			break;

		case '9':
			//	����ʱ
			timeIt.countDown();
			break;

		case '7':
			//	�ʵ�
			familyWithChildren();
			break;

		case '0':
			//	�˳�����
			mainFlag = false;
			break;

		default:
			cout << "Wrong Key! Please Try Again!\n";
			break;
		}
	}
	cout << "Good Bye! TsingHua University is waiting for the man who is hardworking!\n";
	sendOff();
	return 0;
}
