#pragma once


class Event {
private:
	int total_time = 0;
	std::map<std::string, Event> child;
	std::vector<std::string> event;
public:
	void load(void);	//	����ȡ����
	void _load(std::fstream &);	//	������ȡ��������
	void save(int flag = 0);
	void pre_save(void);
	void add(void);
};

