#include "functionTest.h"
#include <io.h>

void addLog(string logData)
{
	if ((_access("log.csv", 0)) == -1) {
		logData = "ѧ��, ֪ʶ��, ����, ����ʱ��, ���ʱ��, ��ע\n" + logData;
	}
	fstream log("log.csv", ios::app);
	log.good() ? log << logData << endl, cout << "From addLog : Save Log Successful!" << endl : cerr << "failed Open the file!\n";
}