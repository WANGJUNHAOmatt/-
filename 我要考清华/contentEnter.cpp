#include "functionTest.h"
#include "TimeIt.h"
#include <sstream>


string contentEnter_sub(void) {
	TimeIt nowTime;
	string log, classifyName, tagName, contentName;
	char contentCheck;
	cout << "��ӭ��¼���ʱ�䣡\n�������㼴�����е����ݵĴ����:";
	cin >> classifyName;
	cout << "��������Ҫѧϰ���ӷ��ࣺ";
	cin >> tagName;
	cout << "��������Ҫѧϰ�����ݣ�";
	cin >> contentName;

	changeColor(���ɫ);
	cout << "��ȷ��������룬�����������Ǿ�Ҫ������!!!\n";
	cout << "�����:" << classifyName << "\t�ӷ���:" << tagName << "\tѧϰ����:" << contentName << endl;
	changeColor();

CONTENTCHECK:
	cout << "(1)ȷ������\t(0)��Ҫ����\n";
	contentCheck = _getch();
	switch (contentCheck) {
	case '1':
		log = classifyName + ',' + tagName + ',' + contentName + ',';
		return log;
		break;
	case '0':
		return contentEnter_sub();
		break;
	default:
		changeColor(���ɫ);
		cout << "�������룬�����ԣ�����";
		changeColor();
		goto CONTENTCHECK;
	}
}

void contentEnter(void) {
	TimeIt nowTime;
	string log, spendTime, others;
	char saveCheck;
	
	log = contentEnter_sub() + nowTime.getTime_t() + ',';

	spendTime = nowTime.Timer();
	log += nowTime.getTime_t() + ',' + spendTime + ',';

SAVECHECK:
	changeColor(���ɫ, ���ɫ);
	cout << log << endl;
	changeColor();

	cout << "��Ҫ������\t(1)�ǵ��뱣��\t(0)�벻Ҫ����\n";
	saveCheck = _getch();
	switch (saveCheck) {
	case '1':
		cout << "�����±�ע:";
		cin >> others;
		log += others;
		addLog(log);
		return;
		break;
	case '0':
		log = "";
		return;
		break;
	default:
		goto SAVECHECK;
	}
}

