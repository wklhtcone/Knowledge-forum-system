#pragma once
#include<iostream>
#include"BasicInfo.h"
#include<string>
using namespace std;


class question :public BasicInfo
{
public:
	virtual void create_question(string Name);
	/*参数Name是登录用户的名字，在LogIn()中由cin传入，
	这里作为参数传入提问函数，以记录提问者的登录名*/
    virtual int add_focus(int serial_of_user);//serial_of_user是登陆者的ID号，可以根据serial_of_user找到Users[]数组中这个人，再get一下登陆者所选问题的作者Name，添加到该登陆者的Focuslist中
	void init();//对问题的私有属性进行初始化
	void addAnum();//增加回答数
	int getAnum();//返回回答数
	void setName(string Name);//写入提问者登录名
	string getName();//返回提问者登录名
	void setTitle(string Title);//写入问题标题
	string getTitle();//返回问题标题
	void setDetailed_question(string Detailed_question);//写入具体描述
	string getDetailed_question();//返回具体描述
	void setTime();//写入提问的时间
	string getTime();//返回提问的时间
	friend ostream& operator<<(ostream& ostr, question &q);
	friend istream& operator>>(istream& istr, question &q);
	
private:
	int Anum;//该问题的回答数量
	string Name;//创建问题的人的用户名
	string Time;//创建的时间
	string Title;//该问题的标题
	string Detailed_question;//该问题的具体描述
};


void ask(question &q, string Name);//问问题，其中调用answer_question

