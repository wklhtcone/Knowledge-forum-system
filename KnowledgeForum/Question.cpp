#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
#include"Question.h"
#include<string>
#include<vector>
#include"User.h"
using namespace std;
extern user Users[50];

void question::init() {
	this->Anum = 0;
	this->Name = "NoName";
	this->Title = "NoTitle";
	this->Detailed_question = "NoDetailed_question";
	this->Time = "NoTime";
}//对温题私有属性初始化
void question::addAnum() {
	this->Anum++;
}//增加赞的数量
int question::getAnum() {
	return this->Anum;
}//得到赞数
void question::setName(string Name) {
	this->Name = Name;
}//写入问题对应名字
string question::getName() {
	return this->Name;
}//返回问题对应的名字
void question::setTitle(string Title) {
	this->Title = Title;
}
string question::getTitle() {
	return this->Title;
}
void question::setDetailed_question(string Detailed_question) {
	this->Detailed_question = Detailed_question;
}
string question::getDetailed_question() {
	return this->Detailed_question;
}
/*void question::setTime() {
	string str;
	time_t a;
	a = time(NULL);
	str = ctime(&a);
	this->Time = str;
}//设置时间并写入*/
void question::setTime() {
	char this_time[30];
	time_t a;
	time(&a);
	strftime(this_time, sizeof(this_time), "%Y-%m-%d,%H:%M:%S", localtime(&a));
	this->Time = this_time;
}
string question::getTime(){
	return this->Time;
}
int question::add_focus(int serial_of_user) {
	int flag;
	string str = this->getName();
	flag=Users[serial_of_user].addFocuslist(str);
	return flag;
}
void question::create_question(string Name) {
	string Title;
	string Detailed_question;
	this->setName(Name);//Name是创建问题人的名字
	cout << "请输入你的问题标题：";
	cin >> Title;
	this->setTitle(Title);
	this->setTime();
	cout << "请输入问题的具体描述：";
	cin >> Detailed_question;
	this->setDetailed_question(Detailed_question);
}
ostream& operator<<(ostream& ostr, question &q) {
		ostr << q.Name << endl;
		ostr << q.Time << endl;
		ostr << q.Title << endl;
		ostr << q.Detailed_question << endl;
		ostr << q.Anum << endl;
	return ostr;
}
istream& operator>>(istream& istr, question &q) {
		istr >> q.Name ;
		istr >> q.Time ;
		istr >> q.Title ;
		istr >> q.Detailed_question ;
		istr >> q.Anum ;
	return istr;
}

void ask(question &q,string Name) {
	string UserName = Name;//q是问题对象
	q.create_question(UserName);//UserName是创建问题的人的登录名
}




