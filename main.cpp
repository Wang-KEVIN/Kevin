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
	//��ȡѧ�����������Ա���ס¥��ͷ��䣡
	char a[100][100];
	int i = 0;
	
	while (!feof(fp) && fgets(a[i], 100, fp) != NULL)
	{
		//char �� string!! ���мǵ�&&��������
		sscanf(a[i], "%s %s %d %c %d", s.name, s.sex,&s.floor,&c,&s.room);//���Ҳ���Բ���Ҫ��length��һ�³���
		read_make(s);
		//char ���ȣ���				
		int length = strlen(s.name);
		//cout << length << endl;
		maxlen = (maxlen,length);
		students.push_back(s);
		i++;
	}*/
	std::ifstream infile1;
	infile1.open("dispatch.txt");	
/*����������ԭ���Ǹ��ݵ��ǣ� ���fin>>�����ٶ��������ˣ��ŷ��ֵ����ļ���β����ʱ�Ÿ����趨�ļ���β�ı�־���˺����eof()ʱ��
�ŷ����档����fin >> x; //��ʱ�ļ��պö������һ�����ݣ����䱣����x�У�
���ǣ� ��ʱ fin.eof������δ�� ��Ϊ��fin���ı�־eofbit��FALSE�� fin����ʱ��Ϊ�ļ���û�е�ĩβֻ�е����ٴζ�дʱ
fin >> x�� �������޿ɶ�д���ݣ���ʱ����֪�������˽�β����ʱ�Ž���־eofbit�޸�ΪTRUE
��ʱ����֪�����ļ�������ĩβ	Ҳ����˵��eof�ڶ�ȡ�����һ�����ݺ�����False,���ٴ���ͼ��һ������ʱ�����ڷ���û���ݿɶ��� ��֪����ĩβ�ˣ���ʱ���޸ı�־��eof��ΪTRUE
*/
	if (!infile1) cout << "error" << endl;
	while (infile1 >> s.name >> s.sex >> temp) {
		/*if (!infile1.good())	break;
		{
			cout << "sb\n";
			break;
		}�������ļ�β���ᷢ����Ϣ*/
		//infile1 >> s.name >> s.sex >> temp;
		//cout << s.name << s.sex << temp;
		//ÿ����һ��Ҫ�崦����
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
	//ѧ���������򣡣�
	//cout << maxlen << endl;
	std::sort(students.begin(), students.end(), []
	(const Student_info& x, const Student_info &y)
	{return x.name < y.name; });

	//���ѧ�����������
	for (j = 0; j != students.size(); j++)
	{
		std::cout << students[j].name;
		//cout << students[j].name.size();
		std::cout << string(maxlen + 4 - students[j].name.size(), ' ');//students[j]д����s!!!!?????ע��ϸ�ڣ���
		cout << left<<setw(6);
		std::cout << students[j].sex;
		std::cout << students[j].floor << "-" << students[j].room;
		cout << endl;
	}
	//��ȡ
	read_first(d, food_weight, food_cost, study_weight, study_knowledge, work_money, work_weight,love_threshold,love_change_threshold);

	cout << "please enter some instructtion:" << endl;

	change_info(students, d, food_weight, food_cost, study_weight, study_knowledge, work_money, work_weight, love_threshold, love_change_threshold);
	//�����ʾ����
	print_out(students, d);
	system("pause");
	return 0;
}

