#pragma once
#include<iostream>
#include"User.h"
#include"BasicInfo.h"
using namespace std;
void LogIn();//��¼
void lookup_question(int serial_of_user);//����ֵ���û���¼ʱ������û���
void lookup_answer(int num,int serial_of_user);//num������ı��
void lookup_question(string chosen_Name,int serial_of_user);//���ڲ鿴��ע�û��������⣬ʵ�������أ�focus_num���û�����Ĺ�ע�б���ţ�serial_of_user�ǵ�¼�û������
void lookup_answer(string chosen_Name,int input,int serial_of_user);//���ڲ鿴��ע�û������ش�ʵ�������أ�input���������ţ�chosen_Name�Ǹõ�¼�û����û�����serial_of_user�ǵ�¼�û������