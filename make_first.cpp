#include"make_first.h"
#include<string>
#include <fstream>
#include<iostream>
#include<sstream>
#include<vector>


using std::endl;
using std::cin;
using std::cout;

//��ʼ��ѧ����Ϣ������¥
void read_first(building& d, double &food_weight, double& food_cost, double& study_weight, double& study_knowledge, double& work_money, double& work_weight,double& love_threshold,double& love_change_threshold)
{
	std::vector<int> rtemp;
	double temp;
	std::ifstream infile;
	infile.open("config.txt");
	if (!infile) cout << "error" << endl;
	//infile >> s;
	std::string str;
	std::string word;
	getline(infile, str);		//Ҫ�����ķ�ʽ���룡
	while (infile.peek()!=EOF)
	{
		std::string word;
		std:: stringstream strin(str);
		//infile.getline(str, 20);
		//cout << "sad";
		if (str.find("//") != str.npos) {
			getline(infile, str);
			continue;
		}
		else	strin >> word >> temp;
		//���ܻ��Ǻ���Ĳ��ֳ�����ǰ�汨������Ҫѧ����ԣ�
		if (word == "FLOOR:")			d.floor_number = temp;//double ��unsigned
		if (word == "ROOM:")
		{
			for (int i = 0; i < d.floor_number; i++)
				d.room_number.push_back(20);
		}
		if (word == "CAPACITY:")
		{
			for (int i = 0; i < d.floor_number; i++)		//�з����޷��Ų�ƥ�䣡
			{
				for (int j = 0; j < d.room_number[i]; j++)
				{
					rtemp.push_back(8);		//��Ҫ����ά�����죡����ȫ��һ���Ķ���
				}
				d.capacity.push_back(rtemp);	//��άvector��push_back����
			}
		}
		//if(word=="WEIGHT:")				students.weight = temp;
		//if(word=="KNOWLEDGE:")			students.knowledge = temp;
		//if(word=="CHARM:")				students.charm = temp;
		if (word == "FOOD_WEIGHT:")		food_weight = temp;
		if (word == "FOOD_COST:")			food_cost = temp;
		if (word == "STUDY_WEIGHT:")		study_weight = temp;
		if (word == "STUDY_KNOWLEDGE:")	study_knowledge = temp;
		if (word == "WORK_MOENY:")			work_money = temp;
		if (word == "WORK_WEIGHT:")		work_weight = temp;
		if (word == "LOVE_THRESHOLD:")		love_threshold = temp;
		if (word == "LOVER_CHANGE_THRESHOLD:")	love_change_threshold =temp;
		//getline(infile, str);
		cout << str << endl;
		getline(infile, str);
		//if (!infile.good()) break;
	}
	//cout << d.floor_number << endl;
	infile.clear();
	//����Ҫѧ��ֶε��ԣ������п����Ǻ���Ĳ��ֳ����˴��󣡣������Ǹò���
}