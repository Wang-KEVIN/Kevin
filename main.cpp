#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include <fstream>
#include<stdio.h>
#include<string>
#include <iomanip>
//#include"expression.h"
#include"make_first.h"
#include "Student_info.h"
#include"change_info.h"
//#include"Student_change.h"
using namespace std;

int main()
{
	std::string::size_type maxlen = 0;
	string temp,stemp1,stemp2;
	std::vector<Student_info> students;
	Student_info s;
	std::vector<Student_info>::size_type j = 0;
	building d;
	double food_weight;
	double food_cost;
	double study_weight;
	double study_knowledge;
	double work_money;
	double work_weight;
	double	love_threshold;
	double	love_change_threshold;
	//double WEIGHT_INC;
	//double	MONEY_INC;
	//double	KNOWLEDGE_INC;
	//double CHARM_INC;


	/*FILE*fp;
	if ((fp = fopen("dispatch.txt", "r")) == NULL)
	{
		printf("error\n");
	}
	//读取学生的姓名，性别，所住楼层和房间！
	char a[100][100];
	int i = 0;
	
	while (!feof(fp) && fgets(a[i], 100, fp) != NULL)
	{
		//char 与 string!! 还有记得&&！！！！
		sscanf(a[i], "%s %s %d %c %d", s.name, s.sex,&s.floor,&c,&s.room);//这个也可以不过要用length存一下长度
		read_make(s);
		//char 长度！！				
		int length = strlen(s.name);
		//cout << length << endl;
		maxlen = (maxlen,length);
		students.push_back(s);
		i++;
	}*/
	std::ifstream infile1;
	infile1.open("dispatch.txt");	
/*输入流！！原来是根据的是： 如果fin>>不能再读入数据了，才发现到了文件结尾，这时才给流设定文件结尾的标志，此后调用eof()时，
才返回真。假设fin >> x; //此时文件刚好读完最后一个数据（将其保存在x中）
但是， 这时 fin.eof（）仍未假 因为，fin流的标志eofbit是FALSE， fin流此时认为文件还没有到末尾只有当流再次读写时
fin >> x； 发现已无可读写数据，此时流才知道到达了结尾，这时才将标志eofbit修改为TRUE
此时流才知道了文件到底了末尾	也就是说，eof在读取完最后一个数据后，仍是False,当再次试图读一个数据时，由于发现没数据可读了 才知道到末尾了，此时才修改标志，eof变为TRUE
*/
	if (!infile1) cout << "error" << endl;
	while (infile1 >> s.name >> s.sex >> temp) {
		/*if (!infile1.good())	break;
		{
			cout << "sb\n";
			break;
		}当读到文件尾部会发出信息*/
		//infile1 >> s.name >> s.sex >> temp;
		//cout << s.name << s.sex << temp;
		//每读完一次要清处！！
		stemp1.push_back(temp[0]);
		stemp1.push_back(temp[1]);
		stemp2.push_back(temp[3]);
		stemp2.push_back(temp[4]);
		//cout << temp[0]<<temp[1]<<temp[2];
		//cout << stemp1 << stemp2 << endl;;
		s.floor = stemp1;
		s.room = stemp2;
		//cout << s.floor;
		read_make(s);
		maxlen = max(maxlen,s.name.size());
		students.push_back(s);
		stemp1.clear();
		stemp2.clear();
	}
	
	infile1.close();
	//学生姓名排序！！
	//cout << maxlen << endl;
	std::sort(students.begin(), students.end(), []
	(const Student_info& x, const Student_info &y)
	{return x.name < y.name; });

	//输出学生基本情况！
	for (j = 0; j != students.size(); j++)
	{
		std::cout << students[j].name;
		//cout << students[j].name.size();
		std::cout << string(maxlen + 4 - students[j].name.size(), ' ');//students[j]写成了s!!!!?????注意细节！！
		cout << left<<setw(6);
		std::cout << students[j].sex;
		std::cout << students[j].floor << "-" << students[j].room;
		cout << endl;
	}
	//读取
	read_first(d, food_weight, food_cost, study_weight, study_knowledge, work_money, work_weight,love_threshold,love_change_threshold);

	cout << "please enter some instructtion:" << endl;

	change_info(students, d, food_weight, food_cost, study_weight, study_knowledge, work_money, work_weight, love_threshold, love_change_threshold);
	//输出显示！！
	print_out(students, d);
	system("pause");
	return 0;
}

