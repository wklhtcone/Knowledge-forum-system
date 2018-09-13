#pragma once
#include<vector>
#include<iostream>
#include<string>
using namespace std;
class user
{
public:
	string* Focuslist;//关注列表
	int getID();//返回登陆者ID
	string getName();//返回登陆者的登录名
	string getPassword();//返回密码
	void setID(int ID);//写入ID
	void setName(string Name);//写入登录名
	void setPassword(string Password);//写入密码
	int addFocuslist(string Name);//增加关注
	void getFocuslist();//得到关注列表
	friend ostream& operator<<(ostream& ostr, user &u);
	friend istream& operator>>(istream& istr, user &u);
private:
	int ID;//登陆者ID
	string Name;//登陆者登录名
	string Password;//登陆者密码
};
