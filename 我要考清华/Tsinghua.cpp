#include "functionTest.h"

//	�汾����
string nowVersion = "0.0.4";
string versionInf = "����Ŀ�ϴ���GitHub";
string discipline[10] = {
	"Mathematics_��ѧ", "Chinese_����", "English_Ӣ��",
	"Physics_����", "Chemistry_��ѧ", "biology_����"
};

//	��������������
bool mainFlag = true;	
char mainControler;

//	��ʱ����������
clock_t start, finish;
double consumeTime, consumeTime_buf;
char timerControler;	//	��¼��ʱ��״̬
bool timerFlag = true;	

//	����ʱ��������
int countDownHH, countDownMM, countDownSS;





int main(void)
{
	system("title ��Ҫ���廪!!!");
	getTime();
	cout << "Where there is a will, there is a way!\t��־�ߣ��¾��ɣ�\n";
	cout << "Now version is " << nowVersion << "\n\n\n";

	while (mainFlag)
	{
		cout << "���������֣�(1)��¼ʱ�� (2)��ѯ��¼_comming_soon (3)�������_comming_soon (5)��ʱ�� (6)����ʱ (0)�˳�����\n";
		mainControler = _getch();
		switch (mainControler) {
			case '1':
				//	ʱ���¼

				break;

			case '2':
				//	��ѯʱ��_������

				break;

			case '3':
				//	����ʱ��_������

				break;

			case '4':
				//	����_title����
				cout << "I am arrive 4\n";
				system("title �廪�廪�廪!");
				mainFlag = false;
				break;

			case '5':
				//	��ʱ��
				timerFlag = true;
				consumeTime = consumeTime_buf = 0;
				getTime();
				cout << "�������ⰴ���Կ�ʼ��ʱ\n";
				_getch();
				start = clock();
				while (timerFlag) {
					system("cls");
					cout << "**********************��ʱ��************************\n����ʱ��Ϊ";
					cout << "�������ⰴ������ͣ��ʱ\n";
					_getch();
					finish = clock();
					consumeTime_buf = (double)(finish - start) / CLOCKS_PER_SEC;
					consumeTime += consumeTime_buf;
					printTime(consumeTime);
					cout << "ֹͣ�밴0�����ఴ������\n";
					timerControler = _getch();
					if (timerControler == '0') {
						timerFlag = false;
						printTime(consumeTime);
					}
					start = clock();
				}
				break;

			case '6':
				//	����ʱ
				cout << "���������赹��ʱ��ʱ�� (hours minutes seconds)���Ի��н�������:";
				cin >> countDownHH >> countDownMM >> countDownSS;
				countDown(countDownHH, countDownMM, countDownSS);
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
	cout << "Good Bye! Tsinghua University is waiting for the man who is hardworking!\n";
	sendOff();
	return 0;
}