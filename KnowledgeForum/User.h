#pragma once
#include<vector>
#include<iostream>
#include<string>
using namespace std;
class user
{
public:
	string* Focuslist;//��ע�б�
	int getID();//���ص�½��ID
	string getName();//���ص�½�ߵĵ�¼��
	string getPassword();//��������
	void setID(int ID);//д��ID
	void setName(string Name);//д���¼��
	void setPassword(string Password);//д������
	int addFocuslist(string Name);//���ӹ�ע
	void getFocuslist();//�õ���ע�б�
	friend ostream& operator<<(ostream& ostr, user &u);
	friend istream& operator>>(istream& istr, user &u);
private:
	int ID;//��½��ID
	string Name;//��½�ߵ�¼��
	string Password;//��½������
};
