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
		i++;//�Զ�����ע����ID
	cout << "\n�������û���" << endl;
	cin >> Name;
	for (i = 0; Users[i].getName() != "NULL"; i++) {
		if (Users[i].getName() == Name) {
			cout << "���û����ѱ�ע�ᣬ���������룡" << endl;
			cin >> Name;
		}
	}//�ж�����ĵ�¼���Ƿ��ѱ�ע��
	Users[i].setName(Name);
	cout << "����������" << endl;
	cin >> Password;
	Users[i].setPassword(Password);
	cout << "�ٴ�����ղŵ�������ȷ��" << endl;//����ȷ������
	while (flag == 0) {
		cin >> Password;
		if (Users[i].getPassword() == Password) {
			cout << "����������ͬ��ע��ɹ�~" << endl;
/**********************************************�����������ע�ᡱ���ļ�**************************************/
			file1.open("Users.txt", ios::app);
			if (!file1.is_open())
				cout << "�ļ���ʧ��" << endl;
			else {
				file1 << Users[i];
				cout << "��ע�ᵽUsers.txt~\n" << endl;
			}
			file1.close();
/**********************************************�����������ע�ᡱ���ļ�**************************************/
			flag = 1;
		}
		else cout << "�������벻һ�£����������룡" << endl;//����������벻�ԣ�ѭ����������
	}

}
