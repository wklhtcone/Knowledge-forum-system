#include<iostream>
#include<string>
#include"LogIn.h"
#include"User.h"
#include"BasicInfo.h"
#include"Question.h"
#include"Answer.h"
#include"Search.h"
#include<fstream>
using namespace std;
extern user Users[50];
extern vector<question>qvec;
extern vector<answer>avec;

void LogIn() {
	int i = 0;
	int num;
	int focus_num;//���ڲ鿴��ע�û���������ش𣬴����˹�ע�б�����ѡ�û������
	int search_choice;//����ȷ��������ʽ����ʱ�仹�Ǳ��⣬
	int flag = 1;//Ϊ��ʵ��ע�����ܣ�������flag
	string time1;//��ʱ������ʱ�û��������ʼʱ��
	string time2;//��ʱ������ʱ�û��������ֹʱ��
	string input_title;//����������ʱ�û�����ı���
	string Name;//��¼�û����û���
	string chosen_Name;//�鿴��ע�û������ش����еĵ�һ����������ʾ��ѡ��ע�û�������
	string Password;//�û����������
	question q;//question���һ��������������ĸ�ֵ����push_back������������
	ofstream file1;
	q.init();
	cout << "����������û���:";
	cin >> Name;
	for (i = 0; Users[i].getName() != Name&&i < 50; i++);
		if (i >= 50)
			cout << "��Ǹ�������ڴ��û���\n\n" << endl;
		else {
			cout << "����������:";
			cin >> Password;
			while (Password != Users[i].getPassword()) {
				cout << "����������������������:" ;
				cin >> Password;
			}
			cout << "��¼�ɹ�����ӭ����" << endl;
			while (flag==1) {
				cout << "\n������������ѡ��" << endl;
				cout << "1.�鿴��������" << endl << "2.����������" << endl << "3.�鿴��ע�б�"<<endl << "4.�鿴������ע�˵�����" 
					<<endl<< "5.�鿴������ע�˵Ļش�"<<endl <<"6.��������Ҫ������"<<endl<<"7.ע��" << endl;
				cin >> num;
				switch (num) {
				case 1:
					lookup_question(i);
					break;
				case 2:
					ask(q, Name);
					qvec.push_back(q);
/**********************************************��������������ʡ����ļ�**************************************/
					//��Ӹ����⵽Questions.txtĩβ�����۵�ʱ��������ˢ��Questions.txt��ˢ��Anum���ش�����
					file1.open("Questions.txt", ios::app);
					if (!file1.is_open())
						cout << "�ļ���ʧ��" << endl;
					else {
						file1 << q;
						cout << "�ѽ����������Questions.txt��" << endl;
					}
					file1.close();
/***********************************************��������������ʡ����ļ�**************************************/
					break;
				case 3:
					Users[i].getFocuslist();
					break;
				case 4:
					Users[i].getFocuslist();
					cout << "���������ѡ��һ���ˣ�" << endl;
					cin >> focus_num;
					while (Users[i].Focuslist[focus_num - 1] == "NULL") {
						cout << "�����ڴ���ţ����������룺" << endl;
						cin >> focus_num;
					}
					chosen_Name = Users[i].Focuslist[focus_num - 1];
					lookup_question(chosen_Name, i);
					break;
				case 5:
					Users[i].getFocuslist();
					cout << "���������ѡ��һ���ˣ�" << endl;
					cin >> focus_num;
					while (Users[i].Focuslist[focus_num - 1] == "NULL") {
						cout << "�����ڴ���ţ����������룺" << endl;
						cin >> focus_num;
					}
					chosen_Name = Users[i].Focuslist[focus_num - 1];
					lookup_answer(chosen_Name,focus_num,i);
					break;
				case 6:
					cout << "����1����������������ʱ������" << endl;
					cin >> search_choice;
					getchar();
					if (search_choice == 1) {
						cout << "���������������ı������������Ĺؼ���" << endl;
						cin >> input_title;
						Search(input_title);
					}
					else {
						cout << "��������ھ����ա���-��-�� ʱ:��:�롱��24Сʱ��ʽ��Ӣ��ð���á�shift���ֺš�����ʡȥʱ���ֻ���" << endl;
						cout << "������������������ʼʱ�䣺" << endl;
						getline(cin, time1);
						cout << "������������������ֹʱ�䣺" << endl;
						getline(cin, time2);
						Search(time1, time2);
					}
					break;
				case 7:
					flag = 0;
					cout << "\n\n";
					break;
				}
			}
		}		
}

void lookup_question(int serial_of_user) {
	int i = 0;
	int num;//num������ı��
	int input;//input�������ѡ��
	int flag = 1;//����switch�˳���������һ��
	int page_choice;
	string tempName;
	ofstream file1;
	answer a;//answer���һ��������������д��
	a.init();//�Զ���a��ʼ��
	int num2 = qvec.size();//num2�������б����������
	if (num2 <= 0)//�ж����������Ƿ�������
		cout << "Ŀǰû������" << endl;
	else {
		cout << "\n�����������б�" ;
		int qserial = num2 - 1;
		while (qserial >= 0) {
			for (i = 0; i < 3 && qserial >=0; i++) {
				cout << "\n���" << qserial << ":" << qvec[qserial].getTitle() << "--" << qvec[qserial].getName() << "," << "��" << qvec[qserial].getTime() << endl;
				cout << "      " << qvec[qserial].getAnum() << "���ش�";
				qserial--;
			}
		    cout << "\n����1��ʾ��һҳ������2��ʾ��һҳ������3ͣ�ڱ�ҳ" << endl;
		    cin >> page_choice;
			switch (page_choice) {
			case 1:
				if (num2 % 3 == 0) {
					if (qserial + 6 > num2 - 1) {
						cout << "û����һҳ��";
						qserial = -1;
					}//��һҳ����������num2-1���򲻴�����һҳ
					else qserial = qserial + 6;
				}//����������3�ı������ص���һҳ��һ�����⣬���Ӧ��+6
				else
				{
					if (qserial + num2 % 3 + 3 > num2 - 1) {
						cout << "û����һҳ��";//��һҳ����������num2-1���򲻴�����һҳ
						qserial = -1;
					}
					else {
						if (qserial == -1)
						qserial = qserial + num2 % 3 + 3; //�����ҳ�����һҳ�������+num2%3+3����Ϊ��ҳ��Ŵ�ͷ��β����num2%3
						else qserial = qserial + 6;//�����ҳ�������һҳ�������+6����Ϊ��ҳ��Ŵ�ͷ��β����3
					}
				}//������������3�ı������ص���һҳ��һ�����⣬Ӧ�÷���������������ҳ�����һҳ�������+num%2+3���������+6
				break;
			case 2:
				if (qserial == -1) {
					cout << "û����һҳ��,����1�ص���һҳ������2ͣ�ڱ�ҳ";//���qserial�Ѿ���-1��˵���Ѿ������һҳ�ˣ�Ӧ��ʾ�û��Ƿ�ص���һҳ
					int c;
					cin >> c;
					if (c == 1) 
					{
						if (num2 % 3 == 0) {
							if (qserial + 6 > num2 - 1) {
								cout << "û����һҳ��";//��һҳ����������num2-1���򲻴�����һҳ
								qserial = -1;
							}
							else qserial = qserial + 6;//����������3�ı������ص���һҳ��һ�����⣬���Ӧ��+6
						}
						else
						{
							if (qserial + num2 % 3 + 3 > num2 - 1) {
								cout << "û����һҳ��";//��һҳ����������num2-1���򲻴�����һҳ
								qserial = -1;
							}
							else {
								if (qserial == -1)
									qserial = qserial + num2 % 3 + 3;//�����ҳ�����һҳ�������+num2%3+3����Ϊ��ҳ��Ŵ�ͷ��β����num2%3
								else qserial = qserial + 6;//�����ҳ�������һҳ�������+6����Ϊ��ҳ��Ŵ�ͷ��β����3
							}//else if(qserial == -1)
						}//else if(num2 % 3 == 0)
					}//if(c==1)
				}//if(qserial==-1)
				else break;
				break;
			case 3:
				qserial = -1;
				break;
			}//switch
		}//while(qserial >= 0)		


		cout << "\n����������ѡ�����Ȥ�����⣺";
		cin >> num;
		while (num < 0 || num >= num2) {
			cout << "����ŵ����ⲻ���ڣ����������룺";
			cin >> num;
		}//�ж��������������Ƿ����
		cout << "\n��������" << qvec[num].getName() << "������" << qvec[num].getTime();
		cout << "���⣺" << qvec[num].getTitle() << endl << "��ϸ������" << qvec[num].getDetailed_question();//��ʽ����ӡ�б�
		while (flag == 1) {
			cout << "\n\n������������ѡ��" << endl << "1.�鿴����������лش�" << endl << "2.д����Ļش�" << endl << "3.��ע��������û�" << endl << "4.�ص���ҳ" << endl;
			cin >> input;
			switch (input) {
			case 1:
				lookup_answer(num,serial_of_user);//�鿴�ش�
				break;
			case 2:
				reply(a, Users[serial_of_user].getName(), num);//�����ش�
				avec.push_back(a);
				qvec[num].addAnum();
/***********************************************������������ش𡱵��ļ�**************************************/
				//��Ӹûش�Answers.txt��ĩβ�����޵�ʱ��������ˢ��Answers.txt��ˢ��Pnum����������
				file1.open("Answers.txt", ios::app);
				if (!file1.is_open())
					cout << "Answers.txt��ʧ��" << endl;
				else {
					file1 << a;
					cout << "��ע�ᵽ�ļ���" << endl;
				}
				file1.close();


				//��Questions.txtˢ�£����ĸ������Anum���ش�����
				file1.open("Questions.txt");
				if (!file1.is_open())
					cout << "Questions.txt��ʧ��" << endl;
				else {
					for (int n = 0; n < num2; n++)
						file1 << qvec[n];
					cout << "��ע�ᵽQuestion.txt,�����˸������Anum��" << endl;
				}
				file1.close();
/***********************************************������������ش𡱵��ļ�**************************************/
				break;
			case 3:
				int flag2;
				flag2=qvec[num].add_focus(serial_of_user);//��ע�������û�
				if (flag2 == 1) {
					cout << "�û�" << Users[serial_of_user].getName() << "��ע" << "�û�" << qvec[num].getName() << "�ɹ�" << endl;
					tempName = Users[serial_of_user].getName() + ".txt";
					file1.open(tempName, ios::app);//�����������¼�û���ע�б���ļ�
					if (!file1.is_open())
						cout << "���ļ�" << tempName << "ʧ��" << endl;
					else {
						file1 << qvec[num].getName() << endl;
						cout << "�û�" << qvec[num].getName() << "����ӵ��û�" << Users[serial_of_user].getName()<<"�Ĺ�ע�б��ļ���"<< endl;
						file1.close();
					}
				}
				else cout << "���ѹ�ע���û��������ظ���ע~" << endl;
				break;
			case 4:
				flag = 0;//�˳�ѭ��
				cout << "\n";
				break;

			}//switch
		}//while(flag==1)
	}//else
}//void


void lookup_answer(int Serial_of_question,int serial_of_user) {
	ofstream file1;
	int num2 = avec.size();//�ش�����������
	int b = 0;//���ڱ����ش�Ĵ�ӡ
	int num;//��������ش�ı��
	int flag = 1;//����switch��ѭ��
	int input;//��������switch��ѡ��
	string tempName;//�������ɡ��õ�½��.txt�����ļ���
	for (b = 0; b < num2 && avec[b].getSerial() != Serial_of_question; b++);
	if (b >= num2)//�ж���ѡ�����Ƿ��лش�
		cout << "��������ʱ�޻ش�" << endl;
	else {
		cout << "\n�ش����£�" << endl;
		for (int b = num2 - 1; b >= 0; b--) {
			if (avec[b].getSerial() == Serial_of_question) {
				cout << "���" << b << ":" << avec[b].getDetailed_answer() << "--" << avec[b].getName() << "," << "��" << avec[b].getTime()<<endl;
				cout << "      " << avec[b].getPnum() << "������\n";//����ش��б�
			}
		}
		cout << "\n����������ѡ�����Ȥ�Ļش�";
		cin >> num;
		while (num < 0 || num >= num2 || avec[num].getSerial() != Serial_of_question) {
			cout << "����ŵĻش𲻴��ڣ����������룺";
			cin >> num;
		}//�ж���������Ƿ��ж�Ӧ�ش�
		while (flag == 1) {
			cout << "\n\n������������ѡ��" << endl << "1.Ϊ�����۵���" << endl << "2.��ע�˻ش���û�" << endl << "3.����" << endl;
			cin >> input;
			switch (input) {
			case 1:
				avec[num].praise();//����ѡ�ش����
				cout << "\n���޳ɹ�" << endl;
/***********************************************���ǡ����ޡ����ļ�����**************************************/
                //��Answers.txtˢ�£����ĸ������Pnum���������� 
				file1.open("Answers.txt");
				if (!file1.is_open())
					cout << "Answers.txt��ʧ��" << endl;
				else {
					for (int n = 0; n < num2; n++)
						file1 <<avec[n];
					cout << "��ע�ᵽAnswers.txt,�����˸������Pnum��" << endl;
				}
				file1.close();
/***********************************************���ǡ����ޡ����ļ�����**************************************/

				break;
			case 2:
				int flag2;
				flag2=avec[num].add_focus(serial_of_user);//����ѡ�ش�Ļش��߼����ע�б�
				if (flag2 == 1) {
					cout << "�û�" << Users[serial_of_user].getName() << "��ע" << "�û�" << avec[num].getName() << "�ɹ�" << endl;
					tempName = Users[serial_of_user].getName() + ".txt";
					file1.open(tempName, ios::app);
					if (!file1.is_open())//�����������¼�û���ע�б���ļ�
						cout << "���ļ�" << tempName << "ʧ��" << endl;
					else {
						file1 << avec[num].getName() << endl;
						cout << "�û�" << avec[num].getName() << "����ӵ��û�" << Users[serial_of_user].getName() << "�Ĺ�ע�б��ļ���" << endl;
						file1.close();
					}
				}
				else cout << "���ѹ�ע���û��������ظ���ע~" << endl;
				break;
			case 3:
				flag = 0;
				break;
			}//switch
		}//while
	}//else
}//void



void lookup_question(string chosen_Name, int serial_of_user)//���ڲ鿴��ע�û��������⣬ʵ�������أ�string���û�������ַ�����serial_of_user�ǵ�¼�û������
{
	int num2 = avec.size();
	int i = 0;
	int number=0;//number��ʾqvec��NameΪUsers[serial_of_user]������
	int qsize = qvec.size();
	for (i = 0; i < qsize; i++) {
		if (qvec[i].getName() == chosen_Name) {
			cout << "\n���⣺" << qvec[i].getTitle() << endl << "��ϸ������" << qvec[i].getDetailed_question();
			cout << "\n��������" << qvec[i].getName() << "������" << qvec[i].getTime();
			cout << "Ŀǰ����" << qvec[i].getAnum() << "���ش�\n";//��ʽ����ӡ�б�
			cout << "\n�ش����£�" << endl;
			for (int b = num2 - 1; b >= 0; b--) {
				if (avec[b].getSerial() == i) {
					cout << "���" << b << ":" << avec[b].getDetailed_answer() << "--" << avec[b].getName() << "," << "��" << avec[b].getTime() << endl;
					cout << "      " << avec[b].getPnum() << "������\n";
				}//����ش��б�
			}
			number++;
		}
	}
	if (number == 0)
		cout << "���û���û�з��������" << endl << endl;
}


void lookup_answer(string chosen_Name,int input,int serial_of_user)//���ڲ鿴��ע�û������ش�ʵ�������أ�string���û�������ַ�����serial_of_user�ǵ�¼�û������
{
	int i = 0;
	int number = 0;//number��ʾqvec��NameΪUsers[serial_of_user]������
	int asize = avec.size();
	for (i = 0; i < asize; i++) {
		if (avec[i].getName() == chosen_Name) {
			cout << "���" << i+1<< ":" << avec[i].getDetailed_answer() << "--" << avec[i].getName() << "," << "��" << avec[i].getTime();
			cout << "      " << avec[i].getPnum() << "������\n";//����ش��б�
			number++;
		}
	}
	if (number == 0)
		cout << "���û���û�з�����ش�" << endl << endl;
}














