#include "functionTest.h"
#include <io.h>
#include <direct.h>


void makeWorkPath(void) {
	string workPath = getWorkPath();
	if (_access(workPath.c_str(), 0) == -1) {
		_mkdir(workPath.c_str());
		cout << "�Ѿ������� : " << workPath << endl;
	}
	else {
		cout << "�Ѵ��� : " << workPath << endl;
	}
	cout << endl;
}


string getWorkPath(void) {
	char nowPath[256];
	_getcwd(nowPath, 256);
	string workPath = nowPath;
	workPath += "\\��Ҫ���廪";
	cout << workPath << endl;
	return workPath;
}

void addLog(string logData)
{
	string workPath = getWorkPath();
	string logPath = workPath + "\\log.csv";
	if (_access(logPath.c_str(), 0) == -1) {
		logData = "ѧ��,֪ʶ��,����,��ʼʱ��,���ʱ��,����ʱ��,��ע\n" + logData;
	}
	fstream log(logPath.c_str(), ios::app);
	log.good() ? log << logData << endl, cout << "From addLog : Save Log Successful!" << endl : cerr << "failed Open the file!\n";
}