#include<iostream>
#include"BasicInfo.h"
#include<string>
#include<vector>
#include"Question.h"
#include"Answer.h"
#include"User.h"
using namespace std;
extern user Users[50];
extern vector<question> qvec;
extern vector<answer>avec;


void BasicInfo::initQnum() {
	this->Qnum = 0;
}//��ʼ����������
void BasicInfo::addQnum(){
	this->Qnum++;
}//������������
int BasicInfo::getQnum() {
	return this->Qnum;
}//������������
void BasicInfo::lookup() {

}
void BasicInfo::creat_question(string Name) {

}
void BasicInfo::answer_question() {

}
int BasicInfo::add_focus(int i) {
	return 0;
}
void BasicInfo::praise() {

}

