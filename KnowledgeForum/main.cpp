#include<iostream>
#include"LogIn.h"
#include"SignUp.h"
#include"User.h"
#include"Question.h"
#include"Answer.h"
#include<string>
#include<fstream>

using namespace std;

user Users[50];//用户的数组
vector<question>qvec;//问题容器
vector<answer>avec;//回答容器
int main()
{
	int i = 0;
	int qsize=0;//qvec应有的容量
	int asize=0;//avec应有的容量
	int num;//输入数字以选择要进行的操作
	int ssize;//svec的容量
	string tempName;//用于生成“该登陆者.txt”的文件名
	string fName;//关注列表文件读出的名字
	vector<string>svec;//用于存储关注列表文件读出的名字
	question q;//question的一个对象，用于赋值
	vector<question>qtemp;//采用>>重载导致最后一行多一个空格，正常读入qvec会多一个，因此设立一个qtemp的临时容器
	answer a;//answer的一个对象，用于赋值
	vector<answer>atemp;//采用>>重载导致最后一行多一个空格，正常读入avec会多一个，因此设立一个atemp的临时容器
	ifstream file2;//用于"Users.txt" "Questions.txt" "Answers.txt"的文件写入

//建立用户列表并初始化
	for (i = 0; i < 50; i++) {
		Users[i].setID(i + 1);
		Users[i].setName("NULL");
		Users[i].Focuslist = new string[20];
		for (int a = 0; a < 20; a++)
			Users[i].Focuslist[a] = "NULL";
	}
//这是从“注册”的文件的写入
	file2.open("Users.txt");
	if (!file2.is_open())
		cout << "没有找到Users.txt,请注册" << endl;
	else {
		i = 0;
		while (!file2.eof()) {
			file2 >> Users[i];
			i++;
		}
	}
	file2.close();
//这是从“问题”的文件的写入
	file2.open("Questions.txt");
	if (!file2.is_open())
		cout << "没有找到Questions.txt,请发起提问" << endl;
	else {
		while (!file2.eof()){
			file2 >> q;
			qtemp.push_back(q);//直接push_back最后一个对象会被重复拷贝，因此设置一个临时容器用于收纳
		}
		qsize = qtemp.size() - 1;//临时容器的容量-1为qvec应有的实际容量
		for (i = 0; i < qsize; i++)
			qvec.push_back(qtemp[i]);
	}
	file2.close();


//这是从“回答”的文件的写入
	file2.open("Answers.txt");
	if (!file2.is_open())
		cout << "没有找到Answers.txt,请回答\n" << endl;
	else {
		while (!file2.eof()) {
			file2 >> a;
			atemp.push_back(a);
		}
		asize = atemp.size() - 1;//临时容器的容量-1为qvec应有的实际容量
		for (i = 0; i < asize; i++)
			avec.push_back(atemp[i]);
	}
	file2.close();
//这是从用户关注列表文件的写入
	
	for (i = 0; Users[i].getName() != "NULL"; i++) {
		tempName = Users[i].getName() + ".txt";
		file2.open(tempName);
		if (file2.is_open()) {
			while (!file2.eof()) {
				file2 >> fName;
				svec.push_back(fName);
			}
			ssize = svec.size() - 1;
			for (int b = 0;b < ssize; b++) {
				Users[i].addFocuslist(svec[b]);
			}	
		}
	}
//这是主界面
	while (1) {
		cout << "欢迎来到瞎扯论坛，请输入数字以选择";
		cout << endl << "1.请登录" << endl << "2.没有账户？注册一个" << endl << "3.退出" << endl;
		cin >> num;
		switch (num) {
		case 1:
			LogIn();//登录并进行一系列的操作	
			break;
		case 2:
			try {
				SignUp();//注册
			}
			catch (runtime_error){
				cout << "超时" << endl;
			     exit(0);
			}
			
			break;
		case 3:
			exit(0);//退出程序

		}
	}
    return 0;
}

