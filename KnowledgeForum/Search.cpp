#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include"Search.h"
#include"Question.h"
extern vector<question>qvec;
void Search(string input_title) {
	int i = 0;
	int number=0;//number��ʾƥ�䵽�ı����а���input_title������
	int qsize = qvec.size();
	for (i = 0; i < qsize; i++) {
		if (qvec[i].getTitle().find(input_title) != string::npos) {
			cout << "\n���⣺" << qvec[i].getTitle() << endl << "��ϸ������" << qvec[i].getDetailed_question() << endl;
			cout << "��������" << qvec[i].getName() << "������" << qvec[i].getTime();
			cout << "Ŀǰ����" << qvec[i].getAnum()<< "���ش�" << endl << endl;
			number++;
		}
	}
	if (number == 0)
		cout << "û���ѵ�����������ֶε�����" << endl;
}
void Search(string time1,string time2) {
	int i = 0;
	int qsize = qvec.size();
	int number = 0;//number��ʾƥ�䵽�ı�����ʱ����time1��time2֮�������
	for (i = 0; i < qsize; i++) {
		if (time1 <= qvec[i].getTime() && time2 >= qvec[i].getTime()) {
			cout << "\n���⣺" << qvec[i].getTitle() << endl << "��ϸ������" << qvec[i].getDetailed_question() << endl;
			cout << "��������" << qvec[i].getName() << "������" << qvec[i].getTime();
			cout << "Ŀǰ����" << qvec[i].getAnum() << "���ش�" << endl << endl;
			number++;
		}
	}
	if (number == 0)
		cout << "û���ѵ��ڴ�ʱ����ڵ�����" << endl;
}
