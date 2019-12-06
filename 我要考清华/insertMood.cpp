#include "functionTest.h"
#include "TimeIt.h"
#include <io.h>
using namespace std;


void insertMood(void) {
	TimeIt timeIt;
	string logData;
	int starsOfMood;
	int ageOfSelfControl;
	cout << "�����������յ���������(1-5) : ";
	cin >> starsOfMood;
	cout << "�����������յ��Կ�������(10-20):";
	cin >> ageOfSelfControl;
	cout << "���������ı�ע : ";
	cin >> logData;
	string workPath = getWorkPath();
	string logPath = workPath + "\\����+�Կ�����־.csv";
	if (_access(logPath.c_str(), 0) == -1){
		fstream log(logPath.c_str(), ios::app);
		cout << "�����ļ� : " << logPath << endl;
		log << "ʱ��,��������,�Կ�������,��ע\n";
		log.close();
	}
	fstream log(logPath.c_str(), ios::app);
	logData = timeIt.getTime_t() + ',' + to_string(starsOfMood) + ',' + to_string(ageOfSelfControl) + ',' + logData + "\n";
	changeColor(ǳ��ɫ);
	cout << logData;
	changeColor();
	log.good() ? log << logData, cout << "From addLog : Save Log Successful!" << endl : cerr << "failed Open the file!\n";
	log.close();
}