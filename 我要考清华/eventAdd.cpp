//#include "functionTest.h"
//
////	��¼ʱ����������
//string logData;
//string classifyName, tagName, contentName, spendTimes, finishedTime, others;
//char saveCheck;
//char notSaveCheck;
//char contentCheck;
//char othersCheck;
//bool contentCheckFlag;
//bool needChangeFlag;
//bool saveFlag;
//
////	��ʱ����������
//clock_t start, finish;
//double consumeTime, consumeTime_buf;
//char timerControler;	//	��¼��ʱ��״̬
//bool timerFlag = true;
//
//void eventAdd() {
//	//	ʱ���¼
//	system("title ��¼ʱ��");
//	logData = "";
//	needChangeFlag = true;
//	while (needChangeFlag)
//	{
//		cout << "��ӭ��¼���ʱ�䣡\n";
//		cout << "��������Ҫѧϰ�Ĵ����:";
//		cin >> classifyName;
//		cout << "��������Ҫѧϰ���ӷ���:";
//		cin >> tagName;
//		cout << "��������Ҫѧϰ������:";
//		cin >> contentName;
//
//		//	ȷ������
//		changeColor(6);
//		cout << "����ȷ���������󣬼����������Ǿ�Ҫ��ʼ��!!!\n";
//		cout << "�����:" << classifyName << "\t�ӷ���:" << tagName << "\tѧϰ����:" << contentName << endl;
//		changeColor();
//		contentCheckFlag = true;
//		while (contentCheckFlag)
//		{
//			cout << "(1)ȷ������\t(2)��Ҫ����\n";
//			contentCheck = _getch();
//			switch (contentCheck) {
//			case '1':
//				contentCheckFlag = false;
//				needChangeFlag = false;
//				logData = classifyName + ',' + tagName + ',' + contentName + ',';
//				break;
//			case '2':
//				contentCheckFlag = false;
//				break;
//			default:
//				changeColor(6, 12);
//				cout << "�������룬������\n";
//				changeColor(6);
//				break;
//			}
//		}
//	}
//	changeColor();
//
//	//	�������ü�ʱ������
//	timerFlag = true;
//	consumeTime = consumeTime_buf = 0;
//	getTime();
//	cout << "�������ⰴ���Կ�ʼ��ʱ\n";
//	_getch();
//	start = clock();
//	while (timerFlag) {
//		system("cls");
//		cout << "**********************��ʱ��************************\n";
//		cout << "�������ⰴ������ͣ��ʱ\n";
//		_getch();
//		finish = clock();
//		consumeTime_buf = (double)(finish - start) / CLOCKS_PER_SEC;
//		consumeTime += consumeTime_buf;
//		printTime(consumeTime);
//		cout << "ֹͣ�밴0�����ఴ������\n";
//		timerControler = _getch();
//		if (timerControler == '0') {
//			timerFlag = false;
//			printTime(consumeTime);
//		}
//		start = clock();
//	}
//	_getch();
//	system("cls");
//	//	�������
//
//	logData += printTime_t(consumeTime) + ',' + getTime_t(1);
//
//	saveFlag = true;
//	while (saveFlag) {
//		changeColor(12, 14);
//		cout << logData << endl;
//		changeColor();
//		cout << "������?\t(1)�ǵģ��뱣��\t(0)��Ҫ����\n";
//		saveCheck = _getch();
//		switch (saveCheck) {
//		case '1':
//			saveFlag = false;
//			cout << "��Ҫ���汸ע��?\t(1)�ǵģ��������¼��仰\t(0)����Ҫ�ˣ�лл\n";
//			othersCheck = _getch();
//			if (othersCheck == '1') {
//				cout << "�����±�ע����enter������:";
//				cin >> others;
//				logData += ',' + others;
//			}
//			addLog(logData);
//
//			//cout << "����ɹ���" << endl;
//
//			break;
//		case '0':
//			cout << "ȷ�ϲ�������\t(1)�����\t(0)���Ĳ�����\n";
//			notSaveCheck = _getch();
//			if (notSaveCheck == '0')	saveFlag = false;
//		}
//	}
//}
