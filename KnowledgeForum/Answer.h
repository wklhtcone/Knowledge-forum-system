#pragma once
#include<iostream>
#include"BasicInfo.h"

using namespace std;
class answer :public BasicInfo
{
public:
	virtual void answer_question(string UserName,int Serial);//UserName是登陆者的登录名，Serial是输入的问题编号
	virtual int add_focus(int serial_of_user);//serial_of_user是登陆者的编号
	virtual void praise();//点赞操作
	void init();//对私有变量进行初始化
	void setName(string Name);//回答问题时记录回答者的登录名并写入该回答的私有变量
	string getName();//返回提问者的登录名
	void setDetailed_answer(string Detailed_answer);//写入回答
	string getDetailed_answer();//返回回答
	int getPnum();//返回点赞数
	void setSerial(int Serial);//写入提问的编号
	int getSerial();//返回提问的编号
	void setTime();//写入时间
	string getTime();//返回时间
	friend ostream& operator<<(ostream& ostr, answer &a);
	friend istream& operator>>(istream& istr, answer &a);

private:
	int Pnum;//该回答的被赞数 
	int Serial;//该回答对应的问题编号，借助vector
	string Name;//回答该问题的人的登录名
	string Detailed_answer;//具体的回答内容
	string Time;//创建的时间
};
void reply(answer &a,string Name,int Serial);//回答，a是answer类的一个对象，Name是登陆者的登录名，Serial是输入的问题编号
