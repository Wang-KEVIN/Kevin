#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<sstream>
#include<cstdio>
#include<cctype>
#include <fstream>
#include<iterator>
#include<algorithm>
#include<iomanip>
#include"Student_change.h"
#include"Student_info.h"
#include"make_first.h"
//#include"expression.h"
#include"Student_change.h"
#include"change_info.h"//自己的头文件不能少啊！！


using namespace std;
int WordNumber = 1;

/*int IncludeChinese(string str)		//判断一个字符串是否有汉字！！
{
	int nRet = 0;
	for(string::size_type i = 0;i!=str.size();i++)
	{
		//如果字符高位为1且下一字符高位也是1则有中文字符
		if ((str[i] & 0x80) && (str[i+1] & 0x80))
		{
			nRet = 1;
			break;
		}
	}
	return nRet;
}*/

void max_student(const vector<Student_info>& stu,string choice)		
{
	double temp = 0.0;		//只进行读操作用const_iterator即不修改容器内容
	vector<Student_info> vtemp;
	if (choice == "体重")
	{
		for (vector<Student_info>::const_iterator it = stu.begin(); it != stu.end(); it++)
			temp = max(temp, (double)it->weight);
		for (vector<Student_info>::const_iterator it = stu.begin(); it != stu.end(); it++)
		{
			if (it->weight == temp)
			{
				vtemp.push_back(*it);
			}
		}
		//注意sort的类型！！！用于结构排序时要注意要加compare
		sort(vtemp.begin(), vtemp.end(), [](Student_info x, Student_info y) {return x.name > y.name; });
		//sort(vtemp.begin(), vtemp.end());不行！要考虑各个方面都要符合！
		cout << "最大体重为:  ";
		cout << temp << endl;
		for (vector<Student_info>::const_iterator it = vtemp.begin(); it != vtemp.end(); it++)
			cout << it->name << "\t";

	}
	else if (choice == "金钱")
	{
		for (vector<Student_info>::const_iterator it = stu.begin(); it != stu.end(); it++)
			temp = max(temp, it->money);
		for (vector<Student_info>::const_iterator it = stu.begin(); it != stu.end(); it++)
		{
			if (it->money == temp)
			{
				vtemp.push_back(*it);
			}
		}
		sort(vtemp.begin(), vtemp.end(), [](Student_info x, Student_info y) {return x.name > y.name; });
		cout << "最大金钱为:  ";
		cout << temp << endl;
		for (vector<Student_info>::const_iterator it = vtemp.begin(); it != vtemp.end(); it++)
			cout << it->name << "\t";
	}
	else if (choice == "知识")
	{
		for (vector<Student_info>::const_iterator it = stu.begin(); it != stu.end(); it++)
			temp = max(temp, it->knowledge);
		for (vector<Student_info>::const_iterator it = stu.begin(); it != stu.end(); it++)
		{
			if (it->knowledge == temp)
			{
				vtemp.push_back(*it);
			}
		}
		sort(vtemp.begin(), vtemp.end(), [](Student_info x, Student_info y) {return x.name > y.name; });
		cout << "最大知识为:  ";
		cout << temp << endl;
		for (vector<Student_info>::const_iterator it = vtemp.begin(); it != vtemp.end(); it++)
			cout << it->name << "\t";
	}
	else if(choice=="魅力")
	{
		for (vector<Student_info>::const_iterator it = stu.begin(); it != stu.end(); it++)
			temp = max(temp, it->charm);
		for (vector<Student_info>::const_iterator it = stu.begin(); it != stu.end(); it++)
		{
			if (it->charm == temp)
			{
				vtemp.push_back(*it);
			}
		}
		sort(vtemp.begin(), vtemp.end(), [](Student_info x, Student_info y) {return x.name > y.name; });
		cout << "最大魅力为:  ";
		cout << temp << endl;
		for (vector<Student_info>::const_iterator it = vtemp.begin(); it != vtemp.end(); it++)
			cout << it->name << "\t";
	}
	else {
		cout << "An error choice!  please enter again" << endl;
	}

}
void min_student(const vector<Student_info>& stu, string choice)
{
	double temp = 10000.0;//用的是min,不能轻易设0.0
	vector<Student_info> vtemp;
	if (choice == "体重")
	{
		for (vector<Student_info>::const_iterator it = stu.begin(); it != stu.end(); it++)
			temp = min(temp, (double)it->weight);			//类型要匹配！
		for (vector<Student_info>::const_iterator it = stu.begin(); it != stu.end(); it++)
		{
			if (it->weight == temp)
			{
				vtemp.push_back(*it);
			}
		}
		sort(vtemp.begin(), vtemp.end(), [](Student_info x, Student_info y) {return x.name > y.name; });
		std::cout << "最小体重为:  ";
		cout << temp << endl;
		for (vector<Student_info>::const_iterator it = vtemp.begin(); it != vtemp.end(); it++)
			std::cout << it->name << "\t";
	}
	else if (choice == "金钱")
	{
		for (vector<Student_info>::const_iterator it = stu.begin(); it != stu.end(); it++)
			temp = min(temp, (double)it->money);
		for (vector<Student_info>::const_iterator it = stu.begin(); it != stu.end(); it++)
		{
			if (it->money == temp)
			{
					vtemp.push_back(*it);
			}
		}
		sort(vtemp.begin(), vtemp.end(), [](Student_info x, Student_info y) {return x.name > y.name; });
		std::cout << "最小金钱为:  ";
		cout << temp << endl;
		for (vector<Student_info>::const_iterator it = vtemp.begin(); it != vtemp.end(); it++)
			std::cout << it->name << "\t";
	}
	else if (choice == "知识")
	{
		for (vector<Student_info>::const_iterator it = stu.begin(); it != stu.end(); it++)
			temp = min(temp, it->knowledge);
		for (vector<Student_info>::const_iterator it = stu.begin(); it != stu.end(); it++)
		{
			if (it->knowledge == temp)
			{
				vtemp.push_back(*it);
			}
		}
		sort(vtemp.begin(), vtemp.end(), [](Student_info x, Student_info y) {return x.name > y.name; });
		std::cout << "最小知识为:  ";
		cout << temp << endl;
		for (vector<Student_info>::const_iterator it = vtemp.begin(); it != vtemp.end(); it++)
			std::cout << it->name << "\t";
	}
	else if (choice == "魅力")
	{
		for (vector<Student_info>::const_iterator it = stu.begin(); it != stu.end(); it++)
			temp = min(temp, it->charm);
		for (vector<Student_info>::const_iterator it = stu.begin(); it != stu.end(); it++)
		{
			if (it->charm == temp)
			{
				vtemp.push_back(*it);
			}
		}
		sort(vtemp.begin(), vtemp.end(), [](Student_info x, Student_info y) {return x.name > y.name; });
		std::cout << "最小魅力为:  ";
		cout << temp << endl;
		for (vector<Student_info>::const_iterator it = vtemp.begin(); it != vtemp.end(); it++)
			std::cout << it->name << "\t";
	}
	else {
		cout << "An error choice!  please enter again" << endl;
	}
}
void   range_student(const vector<Student_info>& stu,string choice,double first,double end)
{
	vector<Student_info> temp;
	if (choice == "体重")
	{
		for (vector<Student_info>::const_iterator it = stu.begin(); it != stu.end(); it++)
		{
			if ((double)it->weight>=first&&(double)it->weight<=end)
			{
				temp.push_back(*it);
			}
		}
		sort(temp.begin(), temp.end(), [](Student_info x, Student_info y) {return x.name > y.name; });
		cout << "符合要求的总数:" << "\t" << temp.size() << "\t" << "具体为:" << endl;
		for (vector<Student_info>::iterator iter = temp.begin(); iter != temp.end(); iter++)
			cout << iter->name << "\t" << iter->weight << "\t";
		cout << endl;
	}
	else if (choice == "金钱")
	{
		for (vector<Student_info>::const_iterator it = stu.begin(); it != stu.end(); it++)
		{
			if (it->money >= first && it->money <= end)
			{
				temp.push_back(*it);
			}
		}
		sort(temp.begin(), temp.end(), [](Student_info x, Student_info y) {return x.name > y.name; });
		cout << "符合要求的总数:" << "\t" << temp.size() << "\t" << "具体为:" << endl;
		for (vector<Student_info>::iterator iter = temp.begin(); iter != temp.end(); iter++)
			cout << iter->name << "\t" << iter->money << "\t";
		cout << endl;
	}
	else if (choice == "知识")
	{
		for (vector<Student_info>::const_iterator it = stu.begin(); it != stu.end(); it++)
		{
			if (it->knowledge >= first && it->knowledge <= end)
			{
				temp.push_back(*it);
			}
		}
		sort(temp.begin(), temp.end(), [](Student_info x, Student_info y) {return x.name > y.name; });
		cout << "符合要求的总数:" << "\t" << temp.size() << "\t" << "具体为:" << endl;
		for (vector<Student_info>::iterator iter = temp.begin(); iter != temp.end(); iter++)
			cout << iter->name << "\t" << iter->knowledge << "\t";
		cout << endl;
	}
	else if (choice == "魅力")
	{
		for (vector<Student_info>::const_iterator it = stu.begin(); it != stu.end(); it++)
		{
			if (it->charm >= first && it->charm <= end)
			{
				temp.push_back(*it);
			}
		}
		sort(temp.begin(), temp.end(), [](Student_info x, Student_info y) {return x.name > y.name; });
		cout << "符合要求的总数:" << "\t" << temp.size() << "\t" << "具体为:" <<endl;
		for (vector<Student_info>::iterator iter = temp.begin(); iter != temp.end(); iter++)
			cout << iter->name << "\t" << iter->charm << "\t";
		cout << endl;
	}
	else {
		cout << "An error choice!  please enter again" << endl;
	}
}
int word_number(string s)
{
	bool isWord = 0;
	int WordNumber = 0;		//都没有声明定义！！细节！！浪费了很长时间debug！！！
	//std::cout << s.size() << endl;
	string::size_type size = s.size();
	//一种方式解决不了！！要学会换一种针对所有条件都符合的！！
	for (string::size_type i = 0; i != size; i++)
	{
		//当中文在前面的时候要这样操作！！！
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n') {
			if (!isWord) {
				WordNumber++;
				isWord = 1;
			}
		}
		else {
			isWord = 0;
		}
	}
	return(WordNumber);
}


void change_info(std::vector<Student_info>& s, struct building &b, const double &food_weight, const double& food_cost, const double& study_weight, const double& study_knowledge, const double& work_money, const double& work_weight, const double& doublelove_threshold, const double& love_change_threshold)
{
	std::ifstream infile;
	vector<string> instruction;
	int number;
	string temp;
	string Tstring;
	double Temp1, Temp2;
	int i = 0;
	infile.open("instructions.txt");
	string str;
	if (!infile) std::cout << "error" << endl;

	while (infile.peek() != EOF)// && !feof(infile))
	{
		//要学会调试！！各种情况都要考虑一下
		std::getline(infile, str);
		//getline也会读入一行的空格！！！放到外面都会导致不会读入新的一行的情况，要考虑程序一步一步怎么走的！！
		std::stringstream strin(str);
		number = word_number(str);
		for (i = 0; i < number; i++)
		{
			strin >> temp;
			instruction.push_back(temp);
			//temp = NULL;
		}

		if (str == "") {
			instruction.clear();
			continue;
		}//空行跳过！！！

		if (!number) continue;
		string::size_type k = 0;
		//for (i = 0; i < number; i++)	std::cout << instruction[i];
		std::cout << str << endl;
		if (instruction[k] == "ADD")
		{
			if (instruction[k + 2] == "FLOOR(s)")
			{
				//转化！！
				vector<int> rtemp;
				Tstring = instruction[k + 1];
				Temp1 = atoi(Tstring.c_str());
				b.floor_number += (int)Temp1;
				for (int i = 0; i < Temp1; i++)
				{
					b.room_number.push_back(20);
					for (int j = 0; j < 20; j++)
					{
						rtemp.push_back(8);		//不要跟二维数组搞混！！完全不一样的东西
					}
					b.capacity.push_back(rtemp);	//二维vector的push_back！！
				}
				//cout << "floor";
			}

			else if (instruction[k + 2] == "ROOM(s)")
			{
				Temp1 = atoi(instruction[k + 1].c_str());
				Temp2 = atoi(instruction[k + 4].c_str());
				b.room_number[(int)Temp2] += (int)Temp1;
				for (int i = 0; i < Temp1; i++)	b.capacity[(int)Temp1].push_back(20);
				//break;
				//cout << "Rooms";
			}
			else if (instruction[k + 2] == "BED(s)")
			{
				string STemp = instruction[k + 4];
				string STemp1, STemp2;
				if (STemp[0] != 0)		STemp1.push_back(STemp[0]);

				STemp1.push_back(STemp[1]);
				STemp2.push_back(STemp[3]);
				STemp2.push_back(STemp[4]);
				int TTemp1 = atoi(STemp1.c_str());		//字符相连接！！
				int TTemp2 = atoi(STemp2.c_str());
				b.capacity[TTemp1][TTemp1] += atoi(instruction[k + 1].c_str());
				//break;
				//cout << "BED";
			}
		}//括号要对准！！！
		else
		{
			//std::cout << "dsa";
				//if(IncludeChinese(instruction[0]) 判断汉字！！！
			for (vector<Student_info>::iterator iter = s.begin(); iter != s.end(); iter++)	//不能少()!!!
			{
				if (iter->name == instruction[0])
				{
					for (k = 1; k < instruction.size();)
					{
						//注意死循环！！！！!用cout试验！！

						if (instruction[k] == "EAT")
						{

							Temp1 = atoi(instruction[k + 1].c_str());
							change_eat(*iter, Temp1, food_weight, food_cost);
							/*Temp2 = exp(Temp1, food_weight, 0.0, 0.0, 0.0, 0.0);
							iter->weight += Temp2;
							iter->money += exp(0.0, 0.0, Temp1, food_cost);
							iter->charm += exp(0.0, Temp2);*/
							k += 2;
						}
						else if (instruction[k] == "STUDY")
						{
							Temp1 = atoi(instruction[k + 1].c_str());
							change_learn(*iter, Temp1, study_knowledge, study_weight);
							/*
							Temp2 = exp(0.0, 0.0, Temp1, study_weight, 0.0, 0.0);
							iter->weight += Temp2;
							Temp3 = exp(Temp1, study_knowledge);
							iter->knowledge += Temp3;
							iter->charm += exp(Temp3, Temp2);	*/
							k += 2;
						}
						else if (instruction[k] == "WORK")
						{
							Temp1 = atoi(instruction[k + 1].c_str());
							change_work(*iter, Temp1, work_money, work_weight);
							/*
							Temp2 = exp(0.0, 0.0, 0.0, 0.0, Temp1, work_weight);
							iter->weight += Temp2;
							iter->money += exp(Temp1, work_money, 0.0, 0.0);
							iter->charm += exp(0.0, Temp2);*/

							k += 2;
						}
						else if (instruction[k] == "QUIT")
						{
							iter->floor.clear();
							iter->room.clear();
							int btemp = atoi(iter->floor.c_str());		//二维数据可以用下标！！要注意类型！！
							int btemp1 = atoi(iter->room.c_str());
							b.capacity[btemp][btemp1]--;
							k += 1;
						}
						else if (instruction[k] == "ENROL")
						{
							string STemp = instruction[k + 1];		//字符相连！！！
							string STemp1, STemp2;
							STemp1.push_back(STemp[0]);
							STemp1.push_back(STemp[1]);
							STemp2.push_back(STemp[3]);
							STemp2.push_back(STemp[4]);
							//int TTemp1 = atoi(STemp1.c_str());
							//int TTemp2 = atoi(STemp2.c_str());
							iter->floor = STemp1;
							iter->room = STemp2;
							k += 2;
						}
						else if (instruction[k] == "WOO")
						{
							//引用传递改变问题！！！
							// Student_info& first_people = Student_info();//引用可以先用一个空赋值！！
							 //Student_info& second_people = Student_info();
							// Student_info& third_people = Student_info();
							//结构体引用和迭代器之间修改！！！不同相互适应！！
							 vector<Student_info>::iterator iter3;
							 vector<Student_info>::iterator iter4;
							 vector<Student_info>::iterator iter5;
							for (vector<Student_info>::iterator iter1 = s.begin(); iter1 != s.end(); iter1++)
							{
								if (iter1->name == instruction[k - 1] )
								{
									iter3 = iter1;
								}
								if (iter1->name == instruction[k + 1])
								{
									iter4 = iter1;
								}
							}
							if (iter3->now_partner.empty())
							{
								if(iter4->now_partner.empty())
								    woo(*iter3,*iter4, doublelove_threshold);
								else
								{
									for (vector<Student_info>::iterator iter = s.begin(); iter!= s.end(); iter++)
									{
										if (iter->name == iter4->now_partner)	iter5 = iter;
									}
									if (Delta2order(*iter4, *iter5, *iter3, love_change_threshold))
									{
										break_up(*iter4, *iter5);
										woo(*iter3,*iter4,doublelove_threshold);
									}
									else cout << "插足失败" << endl;
								}
							}
							else cout << "八荣八耻" << endl;
							break;
						}
						else if (instruction[k + 1] == "BREAK" && instruction[k + 2] == "UP")
						{
							//这里操作不了，因为局部变量的原因，会导致数据清空！
							//而且引用一定要初始化！！！
							//Student_info &first_people = Student_info{};
							//Student_info &second_people = Student_info{};
							vector<Student_info>::iterator iter2, iter3;
							for (vector<Student_info>::iterator iter1 = s.begin(); iter1 != s.end(); iter1++)
							{
								if (iter1->name == instruction[k-1])
								{
									iter2 = iter1;
								}
								if (iter1->name == instruction[k])
								{
									iter3 = iter1;
								}
							//	if (!(*iter2).name.empty() && !(*iter3).name.empty())
							//没有初始化，里面的内容不能确定
								//	break;
							}
							if((*iter2).now_partner==(*iter3).name && !(*iter2).now_partner.empty())
							break_up(*iter2,*iter3);
							else cout << "该两人不是情侣" << endl;
							break;						
						}
						else {
							string STemp = instruction[k + 2];		//字符相连！！！
							string STemp1 = instruction[k + 4];
							string STemp2, STemp3, STemp4, STemp5;
							STemp2.push_back(STemp[0]);
							STemp2.push_back(STemp[1]);
							STemp3.push_back(STemp[3]);
							STemp3.push_back(STemp[4]);
							STemp4.push_back(STemp1[0]);
							STemp4.push_back(STemp1[1]);
							STemp5.push_back(STemp1[3]);
							STemp5.push_back(STemp1[4]);
							/*int TTemp1 = atoi(STemp2.c_str());
							int TTemp2 = atoi(STemp3.c_str());
							int TTemp3 = atoi(STemp4.c_str());
							int TTemp4 = atoi(STemp5.c_str());
							*/
							iter->floor = STemp4;
							iter->room = STemp5;
							k += 5;
							//房间现有人数！！！
						}

					}
					break;
				}
			}
		}
		instruction.clear();
		//TODO:afjakljda //快速到这里！！

	}
	infile.close();

}





void print_out(const vector<Student_info>& s, const building& b)
{

	std::cout << "宿舍楼情况如下：" << endl;
	std::cout << "楼层数量:" << b.floor_number << endl;
	for (auto i = 0; i <(int) b.floor_number; i++)
	{
		std::cout << "第" << i + 1 << "层房间数为：" << b.room_number[i] << endl;
		std::cout << "该层各个房间的情况为:" << endl;
		for (auto j = 0; j < (int)b.room_number[i]; j++)
		{
			std::cout << b.capacity[i][j] << "\t";

		}
		cout << endl;
	}
	std::cout << "各个学生的状况如下：" << endl;
	std::cout << std::left << setw(10) <<"姓名:" << setw(10) << "性别:" << setw(20) << " 楼层-房间:" <<setw(10) << "体重:"<<setw(10) << "知识:" << setw(10) << "金钱:" << setw(10) << "魅力:" << setw(10) << "伴侣:" << endl;
	for (vector<Student_info>::const_iterator iter = s.begin(); iter != s.end(); iter++)
	{

		std::cout << std::left << setw(10) << iter->name  << setw(14) << iter->sex << iter->floor << "-" << setw(14) <<iter->room << setw(10) <<
		iter->weight << setw(10) << iter->knowledge << setw(10) << iter->money << setw(10) << iter->charm;
		if (!iter->now_partner.empty())	cout << setw(10) << iter->now_partner << endl;
		else
		{
			cout << endl;
		}
	}


	//查询功能！
	cout << "请选择想要查询的信息：" << endl;
	cout << "////////////////////" << endl;
	cout << "0)结束" << endl;
	cout << "1)学生属性的查询" << endl;
	cout << "2)学生房间的查询" << endl;
	cout << "3)查询某房间的学生信息" << endl;
	cout << "4）查询某学生恋爱信息" << endl;

	cout << "请输入选项: ";
	int number;
	while (cin >> number)
	{
		switch (number)
		{
		case 0: cout << "请输入^Z结束" << endl; break;
		case 1:
		{
			cout << "请选择查询方式:" << endl;
			cout << "///////////////" << endl;
			cout << "0)结束" << endl;
			cout << "1)最大值查询" << endl;
			cout << "2)最小值查询" << endl;
			cout << "3)范围查询" << endl;
			cout << "please enter your number:";
			int number1;
			while (cin >> number1)
			{
				if (number1 == 0)	break;
				cout << "请选择所要查询的信息" << endl;
				cout << "////////////////////" << endl;
				cout << "0)结束" << endl;
				cout << "1)体重" << endl;
				cout << "2)金钱" << endl;
				cout << "3)知识" << endl;
				cout << "4)魅力" << endl;
				switch (number1)
				{

				case 1:
				{
					int number11;
					cout << "请选择所要查询的信息" << endl;
					while (cin >> number11)
					{
				
						if (number11 == 0) {
							cout << "请继续输入选项或者输入0退出" << endl;
							break;
						}
						switch (number11)
						{
						case 1: max_student(s, "体重"); cout << endl; break;
						case 2:max_student(s, "金钱"); cout << endl; break;
						case 3:max_student(s, "知识"); cout << endl; break;
						case 4:max_student(s, "魅力"); cout << endl; break;
						default:cout << "put an error number" << endl;
						}
					}
				}break;
				case 2:
				{
					int number12;
					cout << "请选择所要查询的信息" << endl;
					while (cin >> number12)
					{
						if (number12 == 0) {
							cout << "请继续输入选项或者输入0退出" << endl;
							break;
						}
						switch (number12)
						{
						case 1: min_student(s, "体重"); cout << endl; break;
						case 2:min_student(s, "金钱"); cout << endl; break;
						case 3:min_student(s, "知识"); cout << endl; break;
						case 4:min_student(s, "魅力"); cout << endl; break;
						default:cout << "put an error number" << endl;
						}
					}
				}break;
				case 3:
				{
					cout << "请选择所要查询的信息" << endl;
					int stu_first, stu_end, number13;
					while (cin >> number13)
					{
						if (number13 == 0) {
							cout << "请继续输入选项或者输入0退出" << endl;
							break;
						}
						cout << "请输入查询信息的范围: ";
						cin >> stu_first >> stu_end;
						switch (number13)//会直接跳到相应的case语句！！！其他部分就不会执行到！！！
						{

						case 1: range_student(s, "体重", stu_first, stu_end); break;
						case 2: range_student(s, "金钱", stu_first, stu_end); break;
						case 3: range_student(s, "知识", stu_first, stu_end); break;
						case 4: range_student(s, "魅力", stu_first, stu_end); break;
						default:cout << "put an error number" << endl;
						}
						cout << "请选择所要查询的信息或者输入0结束" << endl;
					}
				}break;
				default:cout << "put an error number" << endl;
				}
			}
		}break;	//case可以不用{}括起来
		case 2:
		{
			string name;
			cout << "请输入学生姓名:" << "\t";
			cin >> name;
			for (vector<Student_info>::const_iterator it = s.begin(); it != s.end(); it++)
			{
				if (it->name == name)
				{
					if (it->floor.empty())	cout << "该学生已退学"<<endl;
					else
					{
						cout << it->name << "所住的宿舍为: " << it->floor << "-" << it->room << endl;
					}

				}
			}
			cout << "请继续输入选项或者输入0退出" << endl;
		}break;
		case 3:
		{
			cout << "请输入房间号: ";
			string Temp;
			vector<string> stu;
			cin >> Temp;
			string STemp1, STemp2;
			STemp1.push_back(Temp[0]);
			STemp1.push_back(Temp[1]);
			STemp2.push_back(Temp[3]);
			STemp2.push_back(Temp[4]);
			//int TTemp1 = atoi(STemp1.c_str());
			//int TTemp2 = atoi(STemp2.c_str());
			for (vector<Student_info>::const_iterator iter = s.begin(); iter != s.end(); iter++)
			{
				if (iter->floor == STemp1 && iter->room == STemp2)
				{
					stu.push_back(iter->name);
				}
			}
			if (stu.empty())			cout << "未找到该房间" << endl;
			else {
				sort(stu.begin(), stu.end());
				cout << "该房间的学生有";
				for (vector<string>::iterator it = stu.begin(); it != stu.end(); it++)
				{
					cout << *it << "\t";
				}
				cout << endl;
			}
			cout << "请继续输入选项或者输入0退出" << endl;
		}break;
		case 4:
		{
			int number4;
			cout << "请选择:" << endl;
			cout << "0)结束" << endl;
			cout << "1)查询某个学生的恋爱历史" << endl;
			cout << "2)查询所有学生中恋爱人数最多的人" << endl;
			cout << "3)查询谈过恋爱的学生中魅力值最高的人" << endl;
			while (cin >> number4)
			{
				if (number4 == 0) {
					break;
				}
				switch (number4)
				{
				case 1:
				{
					cout << "请输入要查询学生的姓名:" << "\t";
					string name;
					cin >> name;
					for (vector<Student_info>::const_iterator iter = s.begin(); iter != s.end(); iter++)
					{
						if (iter->name == name) {
							if (iter->previous_partner.empty() && iter->now_partner.empty())	cout << "该学生没有恋爱经历" << endl;
							else
							{
								cout << "现任为: " << iter->now_partner << endl;
								cout << "前任为: ";
								for (vector<string>::const_iterator it = iter->previous_partner.begin(); it != iter->previous_partner.end(); it++)
									cout << *it << "\t";
								cout << endl;
							}
						}

					}
					cout << "请继续输入选项或者输入0退出" << endl;
				}break;
				case 2:
				{
					int mtemp;
					vector<string> vtemp;
					for (vector<Student_info>::const_iterator iter = s.begin(); iter != s.end(); iter++)
					{
						int ntemp = 0;
						if (!iter->previous_partner.empty())	ntemp = iter->previous_partner.size();
						if (!iter->now_partner.empty())			ntemp++;
						mtemp = max(ntemp, mtemp);
					}
					for (vector<Student_info>::const_iterator iter = s.begin(); iter != s.end(); iter++)
					{
						int ntemp = 0;
						if (!iter->previous_partner.empty())	ntemp = iter->previous_partner.size();
						if (!iter->now_partner.empty())			ntemp++;
						if (ntemp == mtemp)
						{
							vtemp.push_back(iter->name);
						}
					}
					cout << "学生中恋爱人数最多为: " << mtemp << endl;
					cout << "分别是: ";
					for (vector<string>::iterator it = vtemp.begin(); it != vtemp.end(); it++)
					{
						cout << *it << "\t";
					}
					cout << endl;
					cout << "请继续输入选项或者输入0退出" << endl;
				}break;
				case 3:
				{

					double mtemp = 0;
					vector<string> temp;
					for (vector<Student_info>::const_iterator iter = s.begin(); iter != s.end(); iter++)
					{
						double ntemp = 0;
						if (!iter->previous_partner.empty() || !iter->now_partner.empty())
						{
							ntemp = iter->charm;
							mtemp = max(mtemp, ntemp);
						}
					}
					for (vector<Student_info>::const_iterator iter = s.begin(); iter != s.end(); iter++)
					{
						double ntemp = iter->charm;
						if (!iter->previous_partner.empty() || !iter->now_partner.empty())
							if (ntemp == mtemp)	temp.push_back(iter->name);
					}
					if (temp.empty())	cout << "没有学生谈过恋爱" << endl;
					else {
						cout << "魅力值最高为: " << endl;
						std::cout << "分别是: ";
						for (vector<string>::iterator it = temp.begin(); it != temp.end(); it++)
						{
							std::cout << *it << "\t";
						}
					}
					cout << endl;
					cout << "请继续输入选项或者输入0退出" << endl;
				}break;
				default:cout << "put an error number" << endl;
				}
			}
		}break;
		default: cout << "put an error number" << endl;
		//cout << "请继续输入选项或者输入0退出";在这里没用！
		}
		if(number!=0)	cout << "请继续输入选项或者输入0退出";
	}

}