#include "functionTest.h"
#include "TimeIt.h"

void insertLog(void) {
	TimeIt timeIt;
	int year, month, day, beginHour, beginMin, beginSec, finishHour, finishMin, finishSec;
	string beginTime, finishTime, spendTime, others;
	char insertCheck;

	cout << "�����ǲ���ģʽ��\n";
	string log = contentEnter_sub();
	cout << "���������ڣ� YYYY MM DD(�Կո������س���������):";
	cin >> year >> month >> day;
	cout << "�����뿪ʼʱ�䣺 HH MM SS(�Կո������س���������):";
	cin >> beginHour >> beginMin >> beginSec;
	beginTime = timeIt.toStd(year, month, day, beginHour, beginMin, beginSec);
	cout << "���������ʱ�䣺 HH MM SS(�Կո������س���������):";
	cin >> finishHour >> finishMin >> finishSec;
	finishTime = timeIt.toStd(year, month, day, finishHour, finishMin, finishSec);
	
	changeColor(���ɫ, ���ɫ);
	cout << "����ʱ�������Ƿ���ȷ��\n��ʼʱ��:" << beginTime << "\n����ʱ��:" << finishTime << endl;
	changeColor();
	
INSERTCHECK:
	cout << "(1)û����\t(0)��������\n";
	insertCheck = _getch();
	switch (insertCheck) {
	case '1':
		spendTime = timeIt.stdSubtract(finishTime, beginTime);
		if (spendTime == "Error") return;
		log += beginTime + ',' + finishTime + ',' + spendTime + ',';
		cout << "�����±�ע:";
		cin >> others;
		log += others + ',' + timeIt.getTime_t() + "����";
		addLog(log);
		break;
	case '0':
		return insertLog();
		break;
	default:
		cout << "�������,�����ԣ�";
		goto INSERTCHECK;
		break;
	}
	
}