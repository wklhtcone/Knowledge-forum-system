#pragma once
#include<iostream>
#include<string>
using namespace std;
class BasicInfo
{
public:
	virtual void creat_question(string Name);//创建一个问题，虚函数，在question子类中实现
	virtual void answer_question();//回答一个问题，虚函数，在answer子类中实现
	virtual int add_focus(int i);//i是登陆者的ID号，可以根据i找到Users[]数组中这个人，再get一下登陆者所选问题的作者Name，添加到该登陆者的Focuslist中
	virtual void praise();//点赞
	void lookup();//预览
	void initQnum();
	void addQnum();
	int getQnum();
private:
	int Serial;//回答对应的问题编号，借助vector
	int Qnum;//问题的数量
	int Pnum;//回答的被赞数 
	string Name;//创建问题的人的用户名
	string Time;//创建的时间
	string Title;//该问题的标题
	string Detailed_question;//该问题的具体描述
	string Detailed_answer;//具体的回答内容
};
