#pragma once
#include<iostream>
#include<string>
using namespace std;
class BasicInfo
{
public:
	virtual void creat_question(string Name);//����һ�����⣬�麯������question������ʵ��
	virtual void answer_question();//�ش�һ�����⣬�麯������answer������ʵ��
	virtual int add_focus(int i);//i�ǵ�½�ߵ�ID�ţ����Ը���i�ҵ�Users[]����������ˣ���getһ�µ�½����ѡ���������Name����ӵ��õ�½�ߵ�Focuslist��
	virtual void praise();//����
	void lookup();//Ԥ��
	void initQnum();
	void addQnum();
	int getQnum();
private:
	int Serial;//�ش��Ӧ�������ţ�����vector
	int Qnum;//���������
	int Pnum;//�ش�ı����� 
	string Name;//����������˵��û���
	string Time;//������ʱ��
	string Title;//������ı���
	string Detailed_question;//������ľ�������
	string Detailed_answer;//����Ļش�����
};
