#include "functionTest.h"

//	�汾����
string nowVersion = "0.0.5";
string versionInf = "���ʱ���¼������";


//	��������������
bool mainFlag = true;	
char mainControler;

//	��¼ʱ����������
string logData;
string classifyName, tagName, contentName, spendTimes, finishedTime, others;
char saveCheck;
char notSaveCheck;
char contentCheck;
char othersCheck;
bool contentCheckFlag;
bool needChangeFlag;
bool saveFlag;

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
		system("title ��Ҫ���廪!!!");
		cout << "���������֣�(1)��¼ʱ�� (2)��ѯ��¼_comming_soon (3)�������_comming_soon (5)��ʱ�� (6)����ʱ (0)�˳�����\n";
		mainControler = _getch();
		switch (mainControler) {
			case '1':
				//	ʱ���¼
				system("title ��¼ʱ��");
				logData = "";
				needChangeFlag = true;
				while (needChangeFlag)
				{
					cout << "��ӭ��¼���ʱ�䣡\n";
					cout << "��������Ҫѧϰ�Ĵ����:";
					cin >> classifyName;
					cout << "��������Ҫѧϰ���ӷ���:";
					cin >> tagName;
					cout << "��������Ҫѧϰ������:";
					cin >> contentName;

					//	ȷ������
					changeColor(6);
					cout << "����ȷ���������󣬼����������Ǿ�Ҫ��ʼ��!!!\n";
					cout << "�����:" << classifyName << "\t�ӷ���:" << tagName << "\tѧϰ����:" << contentName << endl;
					changeColor();
					contentCheckFlag = true;
					while (contentCheckFlag)
					{
						cout << "(1)ȷ������\t(2)��Ҫ����\n";
						contentCheck = _getch();
						switch (contentCheck) {
						case '1':
							contentCheckFlag = false;
							needChangeFlag = false;
							logData = classifyName + ',' + tagName + ',' + contentName + ',';
							break;
						case '2':
							contentCheckFlag = false;
							break;
						default:
							changeColor(6, 12);
							cout << "�������룬������\n";
							changeColor(6);
							break;
						}
					}
				}
				changeColor();

				//	�������ü�ʱ������
				timerFlag = true;
				consumeTime = consumeTime_buf = 0;
				getTime();
				cout << "�������ⰴ���Կ�ʼ��ʱ\n";
				_getch();
				start = clock();
				while (timerFlag) {
					system("cls");
					cout << "**********************��ʱ��************************\n";
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
				_getch();
				system("cls");
				//	�������

				logData += printTime_t(consumeTime) + ',' + getTime_t(1);
				
				saveFlag = true;
				while (saveFlag) {
					changeColor(12, 14);
					cout << logData << endl;
					changeColor();
					cout << "������?\t(1)�ǵģ��뱣��\t(0)��Ҫ����\n";
					saveCheck = _getch();
					switch (saveCheck) {
						case '1':
							saveFlag = false;
							cout << "��Ҫ���汸ע��?\t(1)�ǵģ��������¼��仰\t(0)����Ҫ�ˣ�лл\n";
							othersCheck = _getch();
							if (othersCheck == '1') {
								cout << "�����±�ע����enter������:";
								cin >> others;
								logData += ',' + others;
							}
							addLog(logData);
							cout << "����ɹ���" << endl;
							break;
						case '0':
							cout << "ȷ�ϲ�������\t(1)�����\t(0)���Ĳ�����\n";
							notSaveCheck = _getch();
							if (notSaveCheck == '0')	saveFlag = false;
					}
				}
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
					cout << "**********************��ʱ��************************\n";
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
				_getch();
				system("cls");
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
