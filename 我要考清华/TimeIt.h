#pragma once


class TimeIt {
private:
	clock_t begin, finish;
	int consumeTime;
	double consumeTime_buf;
	bool timerFlag;

public:
	void getTime(void);
	std::string getTime_t(void);
	void reset(void);
	void start(void);
	void pause(void);
	void stop(void);
	std::string show(void);
	void countDown(void);	//	����ʱ
	void newCountDown(void);	//	����ʱ��ͬʱ��ʾ��ǰʣ��ʱ�䣨��ʵ�֣�
	std::string Timer(void);
	std::string toStd(int year, int month, int day, int hour, int minute, int second);
	std::string stdSubtract(std::string a, std::string b);
	std::string TimeSub(int h1, int m1, int s1, int h2, int m2, int s2);
};