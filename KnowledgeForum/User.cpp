#include<iostream>
#include<string>
#include"User.h"
#include"Question.h"
using namespace std;
int user::getID() {
	return this->ID;
}//得到ID
string user::getName() {
	return this->Name;
}//得到名字
string user::getPassword() {
	return this->Password;
}//设置密码


void user::setID(int ID) {
	this->ID = ID;
}//设置ID

void user::setName(string Name) {
	this->Name = Name;
}//设置用户名
void user::setPassword(string Password) {
	this->Password = Password;
}//设置密码

int user::addFocuslist(string Name) {
	int i = 0;
	int flag;
	while (this->Focuslist[i] != "NULL"&&this->Focuslist[i]!=Name)
		i++;
	if (this->Focuslist[i] == Name) 
		flag = 0;
	else {
		this->Focuslist[i] = Name;
		flag = 1;
	}
	return flag;
}//增加关注的人

void user::getFocuslist() {
	if (this->Focuslist[0] == "NULL")
		cout << "目前无关注的人\n\n";//判断是否有关注的人
	else {
		cout << "关注列表如下：" << endl;
		int i = 0;
		for (i = 0; this->Focuslist[i] != "NULL"; i++)
			cout << i+1 <<"."<<this->Focuslist[i] << endl;//如果有，一行一行输出
	}
}

ostream& operator<<(ostream& ostr, user &u) {
	ostr << u.Name << endl;
	ostr << u.Password << endl;
	return ostr;
}

istream& operator>>(istream& istr, user &u) {
	istr >> u.Name;
	istr >> u.Password;
	return istr;
}
