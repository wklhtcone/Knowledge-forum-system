#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<ctime>
#include"Answer.h"
#include"User.h"
using namespace std;
extern user Users[50];

void reply(answer &a, string Name, int Serial) {
	string UserName = Name;
	a.answer_question(UserName, Serial);
}//�ش�a��answer���һ������Name�ǵ�½�ߵĵ�¼����Serial�������������
void answer::answer_question(string UserName,int Serial) {
	string Detailed_answer;
	this->setName(UserName);// UserName�ǵ�½�ߵĵ�¼��
	this->setSerial(Serial);//Serial�������������
	this->setTime();
	cout << "��������Ļش����ݣ�";
	cin >> Detailed_answer;
	this->setDetailed_answer(Detailed_answer);
}
int answer::add_focus(int serial_of_user) {
	int flag;
	string str = this->getName(); //serial_of_user�ǵ�½�ߵı��
	flag=Users[serial_of_user].addFocuslist(str);//str�Ǹûش�Ļش�������
	return flag;
}
void answer::praise() {
	this->Pnum++;//Pnum�ǵ�����
}
void answer::init() {
	this->Pnum = 0;
	this->Serial = 0;
	this->Name = "NULL";
	this->Detailed_answer = "NULL";
	this->Time = "NoTime";
}//��ʼ����Serial�Ǹûش��Ӧ�������ţ�Name�ǻش�������

void answer::setName(string Name) {
	this->Name = Name;
}

string answer::getName() {
	return this->Name;
}

void answer::setDetailed_answer(string Detailed_answer) {
	this->Detailed_answer = Detailed_answer;
}

string answer::getDetailed_answer() {
	return this->Detailed_answer;
}


int answer::getPnum() {
	return this->Pnum;
}
void answer::setSerial(int Serial) {
	this->Serial = Serial;
}
int answer::getSerial() {
	return this->Serial;
}

void answer::setTime() {
	char this_time[30];
	time_t a;
	time(&a);
	strftime(this_time, sizeof(this_time), "%Y-%m-%d,%H:%M:%S", localtime(&a));
	this->Time = this_time;
}
string answer::getTime() {
	return this->Time;
}
ostream& operator<<(ostream& ostr, answer &a) {
	ostr << a.Name << endl;
	ostr << a.Time << endl;
	ostr << a.Serial<< endl;
	ostr << a.Detailed_answer << endl;
	ostr << a.Pnum << endl;
	return ostr;
}

istream& operator>>(istream& istr, answer &a) {
	istr >> a.Name;
	istr >> a.Time;
	istr >> a.Serial;
	istr >> a.Detailed_answer;
	istr >> a.Pnum;
	return istr;
}