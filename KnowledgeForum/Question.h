#pragma once
#include<iostream>
#include"BasicInfo.h"
#include<string>
using namespace std;


class question :public BasicInfo
{
public:
	virtual void create_question(string Name);
	/*����Name�ǵ�¼�û������֣���LogIn()����cin���룬
	������Ϊ�����������ʺ������Լ�¼�����ߵĵ�¼��*/
    virtual int add_focus(int serial_of_user);//serial_of_user�ǵ�½�ߵ�ID�ţ����Ը���serial_of_user�ҵ�Users[]����������ˣ���getһ�µ�½����ѡ���������Name����ӵ��õ�½�ߵ�Focuslist��
	void init();//�������˽�����Խ��г�ʼ��
	void addAnum();//���ӻش���
	int getAnum();//���ػش���
	void setName(string Name);//д�������ߵ�¼��
	string getName();//���������ߵ�¼��
	void setTitle(string Title);//д���������
	string getTitle();//�����������
	void setDetailed_question(string Detailed_question);//д���������
	string getDetailed_question();//���ؾ�������
	void setTime();//д�����ʵ�ʱ��
	string getTime();//�������ʵ�ʱ��
	friend ostream& operator<<(ostream& ostr, question &q);
	friend istream& operator>>(istream& istr, question &q);
	
private:
	int Anum;//������Ļش�����
	string Name;//����������˵��û���
	string Time;//������ʱ��
	string Title;//������ı���
	string Detailed_question;//������ľ�������
};


void ask(question &q, string Name);//�����⣬���е���answer_question

