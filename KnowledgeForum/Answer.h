#pragma once
#include<iostream>
#include"BasicInfo.h"

using namespace std;
class answer :public BasicInfo
{
public:
	virtual void answer_question(string UserName,int Serial);//UserName�ǵ�½�ߵĵ�¼����Serial�������������
	virtual int add_focus(int serial_of_user);//serial_of_user�ǵ�½�ߵı��
	virtual void praise();//���޲���
	void init();//��˽�б������г�ʼ��
	void setName(string Name);//�ش�����ʱ��¼�ش��ߵĵ�¼����д��ûش��˽�б���
	string getName();//���������ߵĵ�¼��
	void setDetailed_answer(string Detailed_answer);//д��ش�
	string getDetailed_answer();//���ػش�
	int getPnum();//���ص�����
	void setSerial(int Serial);//д�����ʵı��
	int getSerial();//�������ʵı��
	void setTime();//д��ʱ��
	string getTime();//����ʱ��
	friend ostream& operator<<(ostream& ostr, answer &a);
	friend istream& operator>>(istream& istr, answer &a);

private:
	int Pnum;//�ûش�ı����� 
	int Serial;//�ûش��Ӧ�������ţ�����vector
	string Name;//�ش��������˵ĵ�¼��
	string Detailed_answer;//����Ļش�����
	string Time;//������ʱ��
};
void reply(answer &a,string Name,int Serial);//�ش�a��answer���һ������Name�ǵ�½�ߵĵ�¼����Serial�������������
