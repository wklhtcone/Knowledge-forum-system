#include<iostream>
#include"LogIn.h"
#include"SignUp.h"
#include"User.h"
#include"Question.h"
#include"Answer.h"
#include<string>
#include<fstream>

using namespace std;

user Users[50];//�û�������
vector<question>qvec;//��������
vector<answer>avec;//�ش�����
int main()
{
	int i = 0;
	int qsize=0;//qvecӦ�е�����
	int asize=0;//avecӦ�е�����
	int num;//����������ѡ��Ҫ���еĲ���
	int ssize;//svec������
	string tempName;//�������ɡ��õ�½��.txt�����ļ���
	string fName;//��ע�б��ļ�����������
	vector<string>svec;//���ڴ洢��ע�б��ļ�����������
	question q;//question��һ���������ڸ�ֵ
	vector<question>qtemp;//����>>���ص������һ�ж�һ���ո���������qvec���һ�����������һ��qtemp����ʱ����
	answer a;//answer��һ���������ڸ�ֵ
	vector<answer>atemp;//����>>���ص������һ�ж�һ���ո���������avec���һ�����������һ��atemp����ʱ����
	ifstream file2;//����"Users.txt" "Questions.txt" "Answers.txt"���ļ�д��

//�����û��б���ʼ��
	for (i = 0; i < 50; i++) {
		Users[i].setID(i + 1);
		Users[i].setName("NULL");
		Users[i].Focuslist = new string[20];
		for (int a = 0; a < 20; a++)
			Users[i].Focuslist[a] = "NULL";
	}
//���Ǵӡ�ע�ᡱ���ļ���д��
	file2.open("Users.txt");
	if (!file2.is_open())
		cout << "û���ҵ�Users.txt,��ע��" << endl;
	else {
		i = 0;
		while (!file2.eof()) {
			file2 >> Users[i];
			i++;
		}
	}
	file2.close();
//���Ǵӡ����⡱���ļ���д��
	file2.open("Questions.txt");
	if (!file2.is_open())
		cout << "û���ҵ�Questions.txt,�뷢������" << endl;
	else {
		while (!file2.eof()){
			file2 >> q;
			qtemp.push_back(q);//ֱ��push_back���һ������ᱻ�ظ��������������һ����ʱ������������
		}
		qsize = qtemp.size() - 1;//��ʱ����������-1ΪqvecӦ�е�ʵ������
		for (i = 0; i < qsize; i++)
			qvec.push_back(qtemp[i]);
	}
	file2.close();


//���Ǵӡ��ش𡱵��ļ���д��
	file2.open("Answers.txt");
	if (!file2.is_open())
		cout << "û���ҵ�Answers.txt,��ش�\n" << endl;
	else {
		while (!file2.eof()) {
			file2 >> a;
			atemp.push_back(a);
		}
		asize = atemp.size() - 1;//��ʱ����������-1ΪqvecӦ�е�ʵ������
		for (i = 0; i < asize; i++)
			avec.push_back(atemp[i]);
	}
	file2.close();
//���Ǵ��û���ע�б��ļ���д��
	
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
//����������
	while (1) {
		cout << "��ӭ����Ϲ����̳��������������ѡ��";
		cout << endl << "1.���¼" << endl << "2.û���˻���ע��һ��" << endl << "3.�˳�" << endl;
		cin >> num;
		switch (num) {
		case 1:
			LogIn();//��¼������һϵ�еĲ���	
			break;
		case 2:
			try {
				SignUp();//ע��
			}
			catch (runtime_error){
				cout << "��ʱ" << endl;
			     exit(0);
			}
			
			break;
		case 3:
			exit(0);//�˳�����

		}
	}
    return 0;
}

