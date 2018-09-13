#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include"Search.h"
#include"Question.h"
extern vector<question>qvec;
void Search(string input_title) {
	int i = 0;
	int number=0;//number表示匹配到的标题中包含input_title的问题
	int qsize = qvec.size();
	for (i = 0; i < qsize; i++) {
		if (qvec[i].getTitle().find(input_title) != string::npos) {
			cout << "\n标题：" << qvec[i].getTitle() << endl << "详细描述：" << qvec[i].getDetailed_question() << endl;
			cout << "该问题由" << qvec[i].getName() << "创建于" << qvec[i].getTime();
			cout << "目前已有" << qvec[i].getAnum()<< "个回答" << endl << endl;
			number++;
		}
	}
	if (number == 0)
		cout << "没有搜到标题包含该字段的提问" << endl;
}
void Search(string time1,string time2) {
	int i = 0;
	int qsize = qvec.size();
	int number = 0;//number表示匹配到的标题中时间在time1和time2之间的问题
	for (i = 0; i < qsize; i++) {
		if (time1 <= qvec[i].getTime() && time2 >= qvec[i].getTime()) {
			cout << "\n标题：" << qvec[i].getTitle() << endl << "详细描述：" << qvec[i].getDetailed_question() << endl;
			cout << "该问题由" << qvec[i].getName() << "创建于" << qvec[i].getTime();
			cout << "目前已有" << qvec[i].getAnum() << "个回答" << endl << endl;
			number++;
		}
	}
	if (number == 0)
		cout << "没有搜到在此时间段内的提问" << endl;
}
