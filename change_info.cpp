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
#include"change_info.h"//�Լ���ͷ�ļ������ٰ�����


using namespace std;
int WordNumber = 1;

/*int IncludeChinese(string str)		//�ж�һ���ַ����Ƿ��к��֣���
{
	int nRet = 0;
	for(string::size_type i = 0;i!=str.size();i++)
	{
		//����ַ���λΪ1����һ�ַ���λҲ��1���������ַ�
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
	double temp = 0.0;		//ֻ���ж�������const_iterator�����޸���������
	vector<Student_info> vtemp;
	if (choice == "����")
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
		//ע��sort�����ͣ��������ڽṹ����ʱҪע��Ҫ��compare
		sort(vtemp.begin(), vtemp.end(), [](Student_info x, Student_info y) {return x.name > y.name; });
		//sort(vtemp.begin(), vtemp.end());���У�Ҫ���Ǹ������涼Ҫ���ϣ�
		cout << "�������Ϊ:  ";
		cout << temp << endl;
		for (vector<Student_info>::const_iterator it = vtemp.begin(); it != vtemp.end(); it++)
			cout << it->name << "\t";

	}
	else if (choice == "��Ǯ")
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
		cout << "����ǮΪ:  ";
		cout << temp << endl;
		for (vector<Student_info>::const_iterator it = vtemp.begin(); it != vtemp.end(); it++)
			cout << it->name << "\t";
	}
	else if (choice == "֪ʶ")
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
		cout << "���֪ʶΪ:  ";
		cout << temp << endl;
		for (vector<Student_info>::const_iterator it = vtemp.begin(); it != vtemp.end(); it++)
			cout << it->name << "\t";
	}
	else if(choice=="����")
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
		cout << "�������Ϊ:  ";
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
	double temp = 10000.0;//�õ���min,����������0.0
	vector<Student_info> vtemp;
	if (choice == "����")
	{
		for (vector<Student_info>::const_iterator it = stu.begin(); it != stu.end(); it++)
			temp = min(temp, (double)it->weight);			//����Ҫƥ�䣡
		for (vector<Student_info>::const_iterator it = stu.begin(); it != stu.end(); it++)
		{
			if (it->weight == temp)
			{
				vtemp.push_back(*it);
			}
		}
		sort(vtemp.begin(), vtemp.end(), [](Student_info x, Student_info y) {return x.name > y.name; });
		std::cout << "��С����Ϊ:  ";
		cout << temp << endl;
		for (vector<Student_info>::const_iterator it = vtemp.begin(); it != vtemp.end(); it++)
			std::cout << it->name << "\t";
	}
	else if (choice == "��Ǯ")
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
		std::cout << "��С��ǮΪ:  ";
		cout << temp << endl;
		for (vector<Student_info>::const_iterator it = vtemp.begin(); it != vtemp.end(); it++)
			std::cout << it->name << "\t";
	}
	else if (choice == "֪ʶ")
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
		std::cout << "��С֪ʶΪ:  ";
		cout << temp << endl;
		for (vector<Student_info>::const_iterator it = vtemp.begin(); it != vtemp.end(); it++)
			std::cout << it->name << "\t";
	}
	else if (choice == "����")
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
		std::cout << "��С����Ϊ:  ";
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
	if (choice == "����")
	{
		for (vector<Student_info>::const_iterator it = stu.begin(); it != stu.end(); it++)
		{
			if ((double)it->weight>=first&&(double)it->weight<=end)
			{
				temp.push_back(*it);
			}
		}
		sort(temp.begin(), temp.end(), [](Student_info x, Student_info y) {return x.name > y.name; });
		cout << "����Ҫ�������:" << "\t" << temp.size() << "\t" << "����Ϊ:" << endl;
		for (vector<Student_info>::iterator iter = temp.begin(); iter != temp.end(); iter++)
			cout << iter->name << "\t" << iter->weight << "\t";
		cout << endl;
	}
	else if (choice == "��Ǯ")
	{
		for (vector<Student_info>::const_iterator it = stu.begin(); it != stu.end(); it++)
		{
			if (it->money >= first && it->money <= end)
			{
				temp.push_back(*it);
			}
		}
		sort(temp.begin(), temp.end(), [](Student_info x, Student_info y) {return x.name > y.name; });
		cout << "����Ҫ�������:" << "\t" << temp.size() << "\t" << "����Ϊ:" << endl;
		for (vector<Student_info>::iterator iter = temp.begin(); iter != temp.end(); iter++)
			cout << iter->name << "\t" << iter->money << "\t";
		cout << endl;
	}
	else if (choice == "֪ʶ")
	{
		for (vector<Student_info>::const_iterator it = stu.begin(); it != stu.end(); it++)
		{
			if (it->knowledge >= first && it->knowledge <= end)
			{
				temp.push_back(*it);
			}
		}
		sort(temp.begin(), temp.end(), [](Student_info x, Student_info y) {return x.name > y.name; });
		cout << "����Ҫ�������:" << "\t" << temp.size() << "\t" << "����Ϊ:" << endl;
		for (vector<Student_info>::iterator iter = temp.begin(); iter != temp.end(); iter++)
			cout << iter->name << "\t" << iter->knowledge << "\t";
		cout << endl;
	}
	else if (choice == "����")
	{
		for (vector<Student_info>::const_iterator it = stu.begin(); it != stu.end(); it++)
		{
			if (it->charm >= first && it->charm <= end)
			{
				temp.push_back(*it);
			}
		}
		sort(temp.begin(), temp.end(), [](Student_info x, Student_info y) {return x.name > y.name; });
		cout << "����Ҫ�������:" << "\t" << temp.size() << "\t" << "����Ϊ:" <<endl;
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
	int WordNumber = 0;		//��û���������壡��ϸ�ڣ����˷��˺ܳ�ʱ��debug������
	//std::cout << s.size() << endl;
	string::size_type size = s.size();
	//һ�ַ�ʽ������ˣ���Ҫѧ�ỻһ������������������ϵģ���
	for (string::size_type i = 0; i != size; i++)
	{
		//��������ǰ���ʱ��Ҫ��������������
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
		//Ҫѧ����ԣ������������Ҫ����һ��
		std::getline(infile, str);
		//getlineҲ�����һ�еĿո񣡣����ŵ����涼�ᵼ�²�������µ�һ�е������Ҫ���ǳ���һ��һ����ô�ߵģ���
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
		}//��������������

		if (!number) continue;
		string::size_type k = 0;
		//for (i = 0; i < number; i++)	std::cout << instruction[i];
		std::cout << str << endl;
		if (instruction[k] == "ADD")
		{
			if (instruction[k + 2] == "FLOOR(s)")
			{
				//ת������
				vector<int> rtemp;
				Tstring = instruction[k + 1];
				Temp1 = atoi(Tstring.c_str());
				b.floor_number += (int)Temp1;
				for (int i = 0; i < Temp1; i++)
				{
					b.room_number.push_back(20);
					for (int j = 0; j < 20; j++)
					{
						rtemp.push_back(8);		//��Ҫ����ά�����죡����ȫ��һ���Ķ���
					}
					b.capacity.push_back(rtemp);	//��άvector��push_back����
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
				int TTemp1 = atoi(STemp1.c_str());		//�ַ������ӣ���
				int TTemp2 = atoi(STemp2.c_str());
				b.capacity[TTemp1][TTemp1] += atoi(instruction[k + 1].c_str());
				//break;
				//cout << "BED";
			}
		}//����Ҫ��׼������
		else
		{
			//std::cout << "dsa";
				//if(IncludeChinese(instruction[0]) �жϺ��֣�����
			for (vector<Student_info>::iterator iter = s.begin(); iter != s.end(); iter++)	//������()!!!
			{
				if (iter->name == instruction[0])
				{
					for (k = 1; k < instruction.size();)
					{
						//ע����ѭ����������!��cout���飡��

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
							int btemp = atoi(iter->floor.c_str());		//��ά���ݿ������±꣡��Ҫע�����ͣ���
							int btemp1 = atoi(iter->room.c_str());
							b.capacity[btemp][btemp1]--;
							k += 1;
						}
						else if (instruction[k] == "ENROL")
						{
							string STemp = instruction[k + 1];		//�ַ�����������
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
							//���ô��ݸı����⣡����
							// Student_info& first_people = Student_info();//���ÿ�������һ���ո�ֵ����
							 //Student_info& second_people = Student_info();
							// Student_info& third_people = Student_info();
							//�ṹ�����ú͵�����֮���޸ģ�������ͬ�໥��Ӧ����
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
									else cout << "����ʧ��" << endl;
								}
							}
							else cout << "���ٰ˳�" << endl;
							break;
						}
						else if (instruction[k + 1] == "BREAK" && instruction[k + 2] == "UP")
						{
							//����������ˣ���Ϊ�ֲ�������ԭ�򣬻ᵼ��������գ�
							//��������һ��Ҫ��ʼ��������
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
							//û�г�ʼ������������ݲ���ȷ��
								//	break;
							}
							if((*iter2).now_partner==(*iter3).name && !(*iter2).now_partner.empty())
							break_up(*iter2,*iter3);
							else cout << "�����˲�������" << endl;
							break;						
						}
						else {
							string STemp = instruction[k + 2];		//�ַ�����������
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
							//������������������
						}

					}
					break;
				}
			}
		}
		instruction.clear();
		//TODO:afjakljda //���ٵ������

	}
	infile.close();

}





void print_out(const vector<Student_info>& s, const building& b)
{

	std::cout << "����¥������£�" << endl;
	std::cout << "¥������:" << b.floor_number << endl;
	for (auto i = 0; i <(int) b.floor_number; i++)
	{
		std::cout << "��" << i + 1 << "�㷿����Ϊ��" << b.room_number[i] << endl;
		std::cout << "�ò������������Ϊ:" << endl;
		for (auto j = 0; j < (int)b.room_number[i]; j++)
		{
			std::cout << b.capacity[i][j] << "\t";

		}
		cout << endl;
	}
	std::cout << "����ѧ����״�����£�" << endl;
	std::cout << std::left << setw(10) <<"����:" << setw(10) << "�Ա�:" << setw(20) << " ¥��-����:" <<setw(10) << "����:"<<setw(10) << "֪ʶ:" << setw(10) << "��Ǯ:" << setw(10) << "����:" << setw(10) << "����:" << endl;
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


	//��ѯ���ܣ�
	cout << "��ѡ����Ҫ��ѯ����Ϣ��" << endl;
	cout << "////////////////////" << endl;
	cout << "0)����" << endl;
	cout << "1)ѧ�����ԵĲ�ѯ" << endl;
	cout << "2)ѧ������Ĳ�ѯ" << endl;
	cout << "3)��ѯĳ�����ѧ����Ϣ" << endl;
	cout << "4����ѯĳѧ��������Ϣ" << endl;

	cout << "������ѡ��: ";
	int number;
	while (cin >> number)
	{
		switch (number)
		{
		case 0: cout << "������^Z����" << endl; break;
		case 1:
		{
			cout << "��ѡ���ѯ��ʽ:" << endl;
			cout << "///////////////" << endl;
			cout << "0)����" << endl;
			cout << "1)���ֵ��ѯ" << endl;
			cout << "2)��Сֵ��ѯ" << endl;
			cout << "3)��Χ��ѯ" << endl;
			cout << "please enter your number:";
			int number1;
			while (cin >> number1)
			{
				if (number1 == 0)	break;
				cout << "��ѡ����Ҫ��ѯ����Ϣ" << endl;
				cout << "////////////////////" << endl;
				cout << "0)����" << endl;
				cout << "1)����" << endl;
				cout << "2)��Ǯ" << endl;
				cout << "3)֪ʶ" << endl;
				cout << "4)����" << endl;
				switch (number1)
				{

				case 1:
				{
					int number11;
					cout << "��ѡ����Ҫ��ѯ����Ϣ" << endl;
					while (cin >> number11)
					{
				
						if (number11 == 0) {
							cout << "���������ѡ���������0�˳�" << endl;
							break;
						}
						switch (number11)
						{
						case 1: max_student(s, "����"); cout << endl; break;
						case 2:max_student(s, "��Ǯ"); cout << endl; break;
						case 3:max_student(s, "֪ʶ"); cout << endl; break;
						case 4:max_student(s, "����"); cout << endl; break;
						default:cout << "put an error number" << endl;
						}
					}
				}break;
				case 2:
				{
					int number12;
					cout << "��ѡ����Ҫ��ѯ����Ϣ" << endl;
					while (cin >> number12)
					{
						if (number12 == 0) {
							cout << "���������ѡ���������0�˳�" << endl;
							break;
						}
						switch (number12)
						{
						case 1: min_student(s, "����"); cout << endl; break;
						case 2:min_student(s, "��Ǯ"); cout << endl; break;
						case 3:min_student(s, "֪ʶ"); cout << endl; break;
						case 4:min_student(s, "����"); cout << endl; break;
						default:cout << "put an error number" << endl;
						}
					}
				}break;
				case 3:
				{
					cout << "��ѡ����Ҫ��ѯ����Ϣ" << endl;
					int stu_first, stu_end, number13;
					while (cin >> number13)
					{
						if (number13 == 0) {
							cout << "���������ѡ���������0�˳�" << endl;
							break;
						}
						cout << "�������ѯ��Ϣ�ķ�Χ: ";
						cin >> stu_first >> stu_end;
						switch (number13)//��ֱ��������Ӧ��case��䣡�����������־Ͳ���ִ�е�������
						{

						case 1: range_student(s, "����", stu_first, stu_end); break;
						case 2: range_student(s, "��Ǯ", stu_first, stu_end); break;
						case 3: range_student(s, "֪ʶ", stu_first, stu_end); break;
						case 4: range_student(s, "����", stu_first, stu_end); break;
						default:cout << "put an error number" << endl;
						}
						cout << "��ѡ����Ҫ��ѯ����Ϣ��������0����" << endl;
					}
				}break;
				default:cout << "put an error number" << endl;
				}
			}
		}break;	//case���Բ���{}������
		case 2:
		{
			string name;
			cout << "������ѧ������:" << "\t";
			cin >> name;
			for (vector<Student_info>::const_iterator it = s.begin(); it != s.end(); it++)
			{
				if (it->name == name)
				{
					if (it->floor.empty())	cout << "��ѧ������ѧ"<<endl;
					else
					{
						cout << it->name << "��ס������Ϊ: " << it->floor << "-" << it->room << endl;
					}

				}
			}
			cout << "���������ѡ���������0�˳�" << endl;
		}break;
		case 3:
		{
			cout << "�����뷿���: ";
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
			if (stu.empty())			cout << "δ�ҵ��÷���" << endl;
			else {
				sort(stu.begin(), stu.end());
				cout << "�÷����ѧ����";
				for (vector<string>::iterator it = stu.begin(); it != stu.end(); it++)
				{
					cout << *it << "\t";
				}
				cout << endl;
			}
			cout << "���������ѡ���������0�˳�" << endl;
		}break;
		case 4:
		{
			int number4;
			cout << "��ѡ��:" << endl;
			cout << "0)����" << endl;
			cout << "1)��ѯĳ��ѧ����������ʷ" << endl;
			cout << "2)��ѯ����ѧ������������������" << endl;
			cout << "3)��ѯ̸��������ѧ��������ֵ��ߵ���" << endl;
			while (cin >> number4)
			{
				if (number4 == 0) {
					break;
				}
				switch (number4)
				{
				case 1:
				{
					cout << "������Ҫ��ѯѧ��������:" << "\t";
					string name;
					cin >> name;
					for (vector<Student_info>::const_iterator iter = s.begin(); iter != s.end(); iter++)
					{
						if (iter->name == name) {
							if (iter->previous_partner.empty() && iter->now_partner.empty())	cout << "��ѧ��û����������" << endl;
							else
							{
								cout << "����Ϊ: " << iter->now_partner << endl;
								cout << "ǰ��Ϊ: ";
								for (vector<string>::const_iterator it = iter->previous_partner.begin(); it != iter->previous_partner.end(); it++)
									cout << *it << "\t";
								cout << endl;
							}
						}

					}
					cout << "���������ѡ���������0�˳�" << endl;
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
					cout << "ѧ���������������Ϊ: " << mtemp << endl;
					cout << "�ֱ���: ";
					for (vector<string>::iterator it = vtemp.begin(); it != vtemp.end(); it++)
					{
						cout << *it << "\t";
					}
					cout << endl;
					cout << "���������ѡ���������0�˳�" << endl;
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
					if (temp.empty())	cout << "û��ѧ��̸������" << endl;
					else {
						cout << "����ֵ���Ϊ: " << endl;
						std::cout << "�ֱ���: ";
						for (vector<string>::iterator it = temp.begin(); it != temp.end(); it++)
						{
							std::cout << *it << "\t";
						}
					}
					cout << endl;
					cout << "���������ѡ���������0�˳�" << endl;
				}break;
				default:cout << "put an error number" << endl;
				}
			}
		}break;
		default: cout << "put an error number" << endl;
		//cout << "���������ѡ���������0�˳�";������û�ã�
		}
		if(number!=0)	cout << "���������ѡ���������0�˳�";
	}

}