#include<iostream>
#include<string>
#include"User.h"
#include"Question.h"
using namespace std;
int user::getID() {
	return this->ID;
}//�õ�ID
string user::getName() {
	return this->Name;
}//�õ�����
string user::getPassword() {
	return this->Password;
}//��������


void user::setID(int ID) {
	this->ID = ID;
}//����ID

void user::setName(string Name) {
	this->Name = Name;
}//�����û���
void user::setPassword(string Password) {
	this->Password = Password;
}//��������

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
}//���ӹ�ע����

void user::getFocuslist() {
	if (this->Focuslist[0] == "NULL")
		cout << "Ŀǰ�޹�ע����\n\n";//�ж��Ƿ��й�ע����
	else {
		cout << "��ע�б����£�" << endl;
		int i = 0;
		for (i = 0; this->Focuslist[i] != "NULL"; i++)
			cout << i+1 <<"."<<this->Focuslist[i] << endl;//����У�һ��һ�����
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
