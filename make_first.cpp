#include"make_first.h"
#include<string>
#include <fstream>
#include<iostream>
#include<sstream>
#include<vector>


using std::endl;
using std::cin;
using std::cout;

//初始化学生信息及宿舍楼
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
	getline(infile, str);		//要这样的方式读入！
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
		//可能会是后面的部分出错导致前面报错！！，要学会调试！
		if (word == "FLOOR:")			d.floor_number = temp;//double 到unsigned
		if (word == "ROOM:")
		{
			for (int i = 0; i < d.floor_number; i++)
				d.room_number.push_back(20);
		}
		if (word == "CAPACITY:")
		{
			for (int i = 0; i < d.floor_number; i++)		//有符号无符号不匹配！
			{
				for (int j = 0; j < d.room_number[i]; j++)
				{
					rtemp.push_back(8);		//不要跟二维数组搞混！！完全不一样的东西
				}
				d.capacity.push_back(rtemp);	//二维vector的push_back！！
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
	//调试要学会分段调试！！！有可能是后面的部分出现了错误！！而不是该部分
}