#include "functionTest.h"
#include <io.h>
#include <direct.h>
using namespace std;

void makeWorkPath(void) {
	string workPath = getWorkPath();
	if (_access(workPath.c_str(), 0) == -1) {
		_mkdir(workPath.c_str());
		cout << "�Ѵ��� : " << workPath << endl;
	}
	else {
		cout << "�Ѵ��� : " << workPath << endl;
	}
	cout << endl;
}


string getWorkPath(int flag) {
	char nowPath[256];
	_getcwd(nowPath, 256);
	string workPath = nowPath;
	workPath += "\\��Ҫ���廪";
	if (flag == 0) {
		cout << workPath << endl;
	}
	return workPath;
}

void addLog(string logData)
{
	string workPath = getWorkPath();
	string logPath = workPath + "\\log.csv";
	/*	
		_access(path, mode)
		mode == 0 ֻ����ļ��Ƿ����
				2 дȨ��
				4 ��Ȩ��
				6 ��дȨ��
	*/
	if (_access(logPath.c_str(), 0) == -1) {
		logData = "ѧ��,֪ʶ��,����,��ʼʱ��,���ʱ��,����ʱ��,��ע\n" + logData;
	}
	fstream log(logPath.c_str(), ios::app);
	log.good() ? log << logData << endl, cout << "From addLog : Save Log Successful!" << endl : cerr << "failed Open the file!\n";
	log.close();
}