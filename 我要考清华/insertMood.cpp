#include "functionTest.h"
#include "TimeIt.h"
#include <io.h>


void insertMood(void) {
	TimeIt timeIt;
	string logData;
	int starsOfMood;
	cout << "�����������յ���������(1-5) : ";
	cin >> starsOfMood;
	cout << "�������������� : ";
	cin >> logData;
	string workPath = getWorkPath();
	string logPath = workPath + "\\������־.csv";
	if (_access(logPath.c_str(), 0) == -1){
		fstream log(logPath.c_str(), ios::app);
		cout << "�����ļ� : " << logPath << endl;
		log << "ʱ��,����,��ע\n";
		log.close();
	}
	fstream log(logPath.c_str(), ios::app);
	logData = timeIt.getTime_t() + ',' + to_string(starsOfMood) + ',' + logData + "\n";
	changeColor(ǳ��ɫ);
	cout << logData;
	changeColor();
	log.good() ? log << logData, cout << "From addLog : Save Log Successful!" << endl : cerr << "failed Open the file!\n";
	log.close();
}