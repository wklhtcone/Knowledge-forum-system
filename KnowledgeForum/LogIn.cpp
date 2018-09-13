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
	int focus_num;//用于查看关注用户的问题与回答，代表了关注列表中所选用户的序号
	int search_choice;//用于确认搜索方式，按时间还是标题，
	int flag = 1;//为了实现注销功能，设置了flag
	string time1;//按时间搜索时用户输入的起始时间
	string time2;//按时间搜索时用户输入的终止时间
	string input_title;//按标题搜索时用户输入的标题
	string Name;//登录用户的用户名
	string chosen_Name;//查看关注用户所作回答函数中的第一个参数，表示所选关注用户的名字
	string Password;//用户输入的密码
	question q;//question类的一个对象，用于输入的赋值，并push_back到问题容器中
	ofstream file1;
	q.init();
	cout << "请输入你的用户名:";
	cin >> Name;
	for (i = 0; Users[i].getName() != Name&&i < 50; i++);
		if (i >= 50)
			cout << "抱歉，不存在此用户！\n\n" << endl;
		else {
			cout << "请输入密码:";
			cin >> Password;
			while (Password != Users[i].getPassword()) {
				cout << "密码输入有误，请重新输入:" ;
				cin >> Password;
			}
			cout << "登录成功，欢迎回来" << endl;
			while (flag==1) {
				cout << "\n请输入数字来选择" << endl;
				cout << "1.查看所有提问" << endl << "2.发起新提问" << endl << "3.查看关注列表"<<endl << "4.查看你所关注人的问题" 
					<<endl<< "5.查看你所关注人的回答"<<endl <<"6.搜索你想要的内容"<<endl<<"7.注销" << endl;
				cin >> num;
				switch (num) {
				case 1:
					lookup_question(i);
					break;
				case 2:
					ask(q, Name);
					qvec.push_back(q);
/**********************************************这是输出到“提问”的文件**************************************/
					//添加该问题到Questions.txt末尾，评论的时候再重新刷新Questions.txt来刷新Anum（回答数）
					file1.open("Questions.txt", ios::app);
					if (!file1.is_open())
						cout << "文件打开失败" << endl;
					else {
						file1 << q;
						cout << "已将问题输出到Questions.txt！" << endl;
					}
					file1.close();
/***********************************************这是输出到“提问”的文件**************************************/
					break;
				case 3:
					Users[i].getFocuslist();
					break;
				case 4:
					Users[i].getFocuslist();
					cout << "请输入序号选择一个人：" << endl;
					cin >> focus_num;
					while (Users[i].Focuslist[focus_num - 1] == "NULL") {
						cout << "不存在此序号，请重新输入：" << endl;
						cin >> focus_num;
					}
					chosen_Name = Users[i].Focuslist[focus_num - 1];
					lookup_question(chosen_Name, i);
					break;
				case 5:
					Users[i].getFocuslist();
					cout << "请输入序号选择一个人：" << endl;
					cin >> focus_num;
					while (Users[i].Focuslist[focus_num - 1] == "NULL") {
						cout << "不存在此序号，请重新输入：" << endl;
						cin >> focus_num;
					}
					chosen_Name = Users[i].Focuslist[focus_num - 1];
					lookup_answer(chosen_Name,focus_num,i);
					break;
				case 6:
					cout << "输入1按标题搜索，否则按时间搜索" << endl;
					cin >> search_choice;
					getchar();
					if (search_choice == 1) {
						cout << "请输入你想搜索的标题中所包含的关键字" << endl;
						cin >> input_title;
						Search(input_title);
					}
					else {
						cout << "输入的日期均按照“年-月-日 时:分:秒”的24小时格式，英文冒号用“shift＋分号”，可省去时、分或秒" << endl;
						cout << "请输入你想搜索的起始时间：" << endl;
						getline(cin, time1);
						cout << "请输入你想搜索的终止时间：" << endl;
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
	int num;//num是问题的编号
	int input;//input是输入的选择
	int flag = 1;//用于switch退出，返回上一层
	int page_choice;
	string tempName;
	ofstream file1;
	answer a;//answer类的一个对象，用于数据写入
	a.init();//对对象a初始化
	int num2 = qvec.size();//num2是问题列表的现有容量
	if (num2 <= 0)//判断问题容器是否有问题
		cout << "目前没有问题" << endl;
	else {
		cout << "\n以下是问题列表：" ;
		int qserial = num2 - 1;
		while (qserial >= 0) {
			for (i = 0; i < 3 && qserial >=0; i++) {
				cout << "\n编号" << qserial << ":" << qvec[qserial].getTitle() << "--" << qvec[qserial].getName() << "," << "于" << qvec[qserial].getTime() << endl;
				cout << "      " << qvec[qserial].getAnum() << "个回答";
				qserial--;
			}
		    cout << "\n输入1显示上一页，输入2显示下一页，输入3停在本页" << endl;
		    cin >> page_choice;
			switch (page_choice) {
			case 1:
				if (num2 % 3 == 0) {
					if (qserial + 6 > num2 - 1) {
						cout << "没有上一页了";
						qserial = -1;
					}//上一页序号如果超过num2-1，则不存在上一页
					else qserial = qserial + 6;
				}//总问题数是3的倍数，回到上一页第一个问题，序号应该+6
				else
				{
					if (qserial + num2 % 3 + 3 > num2 - 1) {
						cout << "没有上一页了";//上一页序号如果超过num2-1，则不存在上一页
						qserial = -1;
					}
					else {
						if (qserial == -1)
						qserial = qserial + num2 % 3 + 3; //如果此页是最后一页，则序号+num2%3+3，因为本页序号从头到尾减了num2%3
						else qserial = qserial + 6;//如果此页不是最后一页，则序号+6，因为本页序号从头到尾减了3
					}
				}//总问题数不是3的倍数，回到上一页第一个问题，应该分两种情况，如果此页是最后一页，则序号+num%2+3，否则序号+6
				break;
			case 2:
				if (qserial == -1) {
					cout << "没有下一页了,输入1回到上一页，输入2停在本页";//如果qserial已经是-1，说明已经是最后一页了，应提示用户是否回到上一页
					int c;
					cin >> c;
					if (c == 1) 
					{
						if (num2 % 3 == 0) {
							if (qserial + 6 > num2 - 1) {
								cout << "没有上一页了";//上一页序号如果超过num2-1，则不存在上一页
								qserial = -1;
							}
							else qserial = qserial + 6;//总问题数是3的倍数，回到上一页第一个问题，序号应该+6
						}
						else
						{
							if (qserial + num2 % 3 + 3 > num2 - 1) {
								cout << "没有上一页了";//上一页序号如果超过num2-1，则不存在上一页
								qserial = -1;
							}
							else {
								if (qserial == -1)
									qserial = qserial + num2 % 3 + 3;//如果此页是最后一页，则序号+num2%3+3，因为本页序号从头到尾减了num2%3
								else qserial = qserial + 6;//如果此页不是最后一页，则序号+6，因为本页序号从头到尾减了3
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


		cout << "\n请输入编号来选择感兴趣的问题：";
		cin >> num;
		while (num < 0 || num >= num2) {
			cout << "该序号的问题不存在，请重新输入：";
			cin >> num;
		}//判断输入的问题序号是否存在
		cout << "\n该问题由" << qvec[num].getName() << "创建于" << qvec[num].getTime();
		cout << "标题：" << qvec[num].getTitle() << endl << "详细描述：" << qvec[num].getDetailed_question();//格式化打印列表
		while (flag == 1) {
			cout << "\n\n请输入数字来选择" << endl << "1.查看此问题的所有回答" << endl << "2.写出你的回答" << endl << "3.关注此问题的用户" << endl << "4.回到主页" << endl;
			cin >> input;
			switch (input) {
			case 1:
				lookup_answer(num,serial_of_user);//查看回答
				break;
			case 2:
				reply(a, Users[serial_of_user].getName(), num);//创建回答
				avec.push_back(a);
				qvec[num].addAnum();
/***********************************************这是输出到“回答”的文件**************************************/
				//添加该回答到Answers.txt的末尾，点赞的时候再重新刷新Answers.txt来刷新Pnum（点赞数）
				file1.open("Answers.txt", ios::app);
				if (!file1.is_open())
					cout << "Answers.txt打开失败" << endl;
				else {
					file1 << a;
					cout << "已注册到文件！" << endl;
				}
				file1.close();


				//对Questions.txt刷新，更改该问题的Anum（回答数）
				file1.open("Questions.txt");
				if (!file1.is_open())
					cout << "Questions.txt打开失败" << endl;
				else {
					for (int n = 0; n < num2; n++)
						file1 << qvec[n];
					cout << "已注册到Question.txt,更新了该问题的Anum！" << endl;
				}
				file1.close();
/***********************************************这是输出到“回答”的文件**************************************/
				break;
			case 3:
				int flag2;
				flag2=qvec[num].add_focus(serial_of_user);//关注此问题用户
				if (flag2 == 1) {
					cout << "用户" << Users[serial_of_user].getName() << "关注" << "用户" << qvec[num].getName() << "成功" << endl;
					tempName = Users[serial_of_user].getName() + ".txt";
					file1.open(tempName, ios::app);//这是输出到登录用户关注列表的文件
					if (!file1.is_open())
						cout << "打开文件" << tempName << "失败" << endl;
					else {
						file1 << qvec[num].getName() << endl;
						cout << "用户" << qvec[num].getName() << "已添加到用户" << Users[serial_of_user].getName()<<"的关注列表文件中"<< endl;
						file1.close();
					}
				}
				else cout << "您已关注此用户，无需重复关注~" << endl;
				break;
			case 4:
				flag = 0;//退出循环
				cout << "\n";
				break;

			}//switch
		}//while(flag==1)
	}//else
}//void


void lookup_answer(int Serial_of_question,int serial_of_user) {
	ofstream file1;
	int num2 = avec.size();//回答容器的容量
	int b = 0;//用于遍历回答的打印
	int num;//用于输入回答的编号
	int flag = 1;//用于switch的循环
	int input;//用来输入switch的选择
	string tempName;//用于生成“该登陆者.txt”的文件名
	for (b = 0; b < num2 && avec[b].getSerial() != Serial_of_question; b++);
	if (b >= num2)//判断所选问题是否有回答
		cout << "此问题暂时无回答" << endl;
	else {
		cout << "\n回答如下：" << endl;
		for (int b = num2 - 1; b >= 0; b--) {
			if (avec[b].getSerial() == Serial_of_question) {
				cout << "编号" << b << ":" << avec[b].getDetailed_answer() << "--" << avec[b].getName() << "," << "于" << avec[b].getTime()<<endl;
				cout << "      " << avec[b].getPnum() << "个点赞\n";//输出回答列表
			}
		}
		cout << "\n请输入编号来选择感兴趣的回答：";
		cin >> num;
		while (num < 0 || num >= num2 || avec[num].getSerial() != Serial_of_question) {
			cout << "该序号的回答不存在，请重新输入：";
			cin >> num;
		}//判断输入序号是否有对应回答
		while (flag == 1) {
			cout << "\n\n请输入数字来选择" << endl << "1.为该评论点赞" << endl << "2.关注此回答的用户" << endl << "3.返回" << endl;
			cin >> input;
			switch (input) {
			case 1:
				avec[num].praise();//给所选回答点赞
				cout << "\n点赞成功" << endl;
/***********************************************这是“点赞”的文件操作**************************************/
                //对Answers.txt刷新，更改该问题的Pnum（点赞数） 
				file1.open("Answers.txt");
				if (!file1.is_open())
					cout << "Answers.txt打开失败" << endl;
				else {
					for (int n = 0; n < num2; n++)
						file1 <<avec[n];
					cout << "已注册到Answers.txt,更新了该问题的Pnum！" << endl;
				}
				file1.close();
/***********************************************这是“点赞”的文件操作**************************************/

				break;
			case 2:
				int flag2;
				flag2=avec[num].add_focus(serial_of_user);//将所选回答的回答者加入关注列表
				if (flag2 == 1) {
					cout << "用户" << Users[serial_of_user].getName() << "关注" << "用户" << avec[num].getName() << "成功" << endl;
					tempName = Users[serial_of_user].getName() + ".txt";
					file1.open(tempName, ios::app);
					if (!file1.is_open())//这是输出到登录用户关注列表的文件
						cout << "打开文件" << tempName << "失败" << endl;
					else {
						file1 << avec[num].getName() << endl;
						cout << "用户" << avec[num].getName() << "已添加到用户" << Users[serial_of_user].getName() << "的关注列表文件中" << endl;
						file1.close();
					}
				}
				else cout << "您已关注此用户，无需重复关注~" << endl;
				break;
			case 3:
				flag = 0;
				break;
			}//switch
		}//while
	}//else
}//void



void lookup_question(string chosen_Name, int serial_of_user)//用于查看关注用户所提问题，实现了重载；string是用户输入的字符串，serial_of_user是登录用户的序号
{
	int num2 = avec.size();
	int i = 0;
	int number=0;//number表示qvec中Name为Users[serial_of_user]的数量
	int qsize = qvec.size();
	for (i = 0; i < qsize; i++) {
		if (qvec[i].getName() == chosen_Name) {
			cout << "\n标题：" << qvec[i].getTitle() << endl << "详细描述：" << qvec[i].getDetailed_question();
			cout << "\n该问题由" << qvec[i].getName() << "创建于" << qvec[i].getTime();
			cout << "目前已有" << qvec[i].getAnum() << "个回答\n";//格式化打印列表
			cout << "\n回答如下：" << endl;
			for (int b = num2 - 1; b >= 0; b--) {
				if (avec[b].getSerial() == i) {
					cout << "编号" << b << ":" << avec[b].getDetailed_answer() << "--" << avec[b].getName() << "," << "于" << avec[b].getTime() << endl;
					cout << "      " << avec[b].getPnum() << "个点赞\n";
				}//输出回答列表
			}
			number++;
		}
	}
	if (number == 0)
		cout << "该用户还没有发表过提问" << endl << endl;
}


void lookup_answer(string chosen_Name,int input,int serial_of_user)//用于查看关注用户所作回答，实现了重载；string是用户输入的字符串，serial_of_user是登录用户的序号
{
	int i = 0;
	int number = 0;//number表示qvec中Name为Users[serial_of_user]的数量
	int asize = avec.size();
	for (i = 0; i < asize; i++) {
		if (avec[i].getName() == chosen_Name) {
			cout << "编号" << i+1<< ":" << avec[i].getDetailed_answer() << "--" << avec[i].getName() << "," << "于" << avec[i].getTime();
			cout << "      " << avec[i].getPnum() << "个点赞\n";//输出回答列表
			number++;
		}
	}
	if (number == 0)
		cout << "该用户还没有发表过回答" << endl << endl;
}














