#include<iostream>
#include<string>
#include"SignUp.h"
#include"User.h"
#include<fstream>
using namespace std;
extern user Users[50];
void SignUp() {
	string Name;
	string Password;
	int flag = 0;
	int i = 0;
	ofstream file1;
	while(Users[i].getName() != "NULL")
		i++;//自动生成注册者ID
	cout << "\n请输入用户名" << endl;
	cin >> Name;
	for (i = 0; Users[i].getName() != "NULL"; i++) {
		if (Users[i].getName() == Name) {
			cout << "此用户名已被注册，请重新输入！" << endl;
			cin >> Name;
		}
	}//判断输入的登录名是否已被注册
	Users[i].setName(Name);
	cout << "请输入密码" << endl;
	cin >> Password;
	Users[i].setPassword(Password);
	cout << "再次输入刚才的密码以确认" << endl;//二次确认密码
	while (flag == 0) {
		cin >> Password;
		if (Users[i].getPassword() == Password) {
			cout << "两次密码相同，注册成功~" << endl;
/**********************************************这是输出到“注册”的文件**************************************/
			file1.open("Users.txt", ios::app);
			if (!file1.is_open())
				cout << "文件打开失败" << endl;
			else {
				file1 << Users[i];
				cout << "已注册到Users.txt~\n" << endl;
			}
			file1.close();
/**********************************************这是输出到“注册”的文件**************************************/
			flag = 1;
		}
		else cout << "两次密码不一致，请重新输入！" << endl;//如果二次密码不对，循环重新输入
	}

}
