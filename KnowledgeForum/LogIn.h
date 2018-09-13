#pragma once
#include<iostream>
#include"User.h"
#include"BasicInfo.h"
using namespace std;
void LogIn();//登录
void lookup_question(int serial_of_user);//返回值是用户登录时输入的用户名
void lookup_answer(int num,int serial_of_user);//num是问题的编号
void lookup_question(string chosen_Name,int serial_of_user);//用于查看关注用户所提问题，实现了重载；focus_num是用户输入的关注列表序号，serial_of_user是登录用户的序号
void lookup_answer(string chosen_Name,int input,int serial_of_user);//用于查看关注用户所作回答，实现了重载；input是输入的序号，chosen_Name是该登录用户的用户名，serial_of_user是登录用户的序号