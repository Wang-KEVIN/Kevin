#include"Student_change.h"
#include"expression.h"
#include"Student_info.h"
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

double out_judge(double x)
{
	double a = 100.0;
	double b = 0.0;
	if (x>=0 && x<=100)	return x;		//&&!!!!����ѧ�е��ǲ�ͬ�ģ�����ϸ�ڣ�
	else if (x > 100)	return a;
	else				return b;
}

//һ������һ������������
/*void change_buliding(Student_info& s)
{
	string newfloor, newroom;
	cout << "please enter new floor and room:" << endl;
	cin >> newfloor >> newroom;
	s.floor = newfloor;
}

/*void change_school(Student_info& stu,string s)
{
	if (s == "quit")
	{
		stu.floor.clear();
		stu.room.clear();
	}
	else
	{
		cout << "please enter student's floor and room:" << endl;
		cin >> stu.floor >> stu.room;
	}
}*/
//����û���������������Ȼû����ʲô�仯��
void change_eat(Student_info &s,double food_taken,double food_weight,double food_cost)
{	double temp	= exp(food_taken, food_weight, 0.0, 0.0, 0.0, 0.0);
	double temp1 = exp(0.0, 0.0, food_taken, food_cost);		//��Ҫ����һ������
	s.money += temp1;
	if (s.money <= 0.0)	s.money = 0.0;
	s.weight += temp;
	s.charm += expcharm(0.0, temp);
	s.charm = out_judge(s.charm);
}
void change_learn(Student_info& s,double study_time,double study_knowledge,double study_weight)
{
	double temp_study = exp(study_time, study_knowledge);
	double temp_weight = exp(0.0, 0.0, study_time, study_weight, 0.0, 0.0);
	s.knowledge += temp_study;
	s.knowledge=out_judge(s.knowledge);		//���÷���ֵ�ı䣬��������double ���ã�����Ϊ�ǽṹ�壡��
	s.weight += temp_weight;
	s.charm += expcharm(temp_study, temp_weight);
	s.charm = out_judge(s.charm);
}

void change_work(Student_info& s, double work_time, double work_money,double work_weight)
{
	double temp = exp(0.0, 0.0, 0.0, 0.0, work_time, work_weight);
	s.money += exp(work_time, work_money, 0.0, 0.0);
	if (s.money <= 0.0)	s.money = 0.0;
	s.weight += temp;		//doubleת��unsigned int
	s.charm += expcharm(0.0, temp);
	s.charm = out_judge(s.charm);
}

double delta(const double& x, const double& y)			//�ж�����ֵ��ֵ
{
	double temp;
	double maxtemp = max(x, y);
	if (maxtemp==x)
	{
		temp = (x - y) / maxtemp;
	}
	else
	{
		temp = (y - x) / maxtemp;
	}
	return(temp);
}

bool Delta2order(Student_info& x,Student_info& y,Student_info& z,const double& standard)		//���ǹ�ϵ
{
	double temp = (delta(x.charm, y.charm) - delta(x.charm, z.charm)) / delta(x.charm, z.charm);
	if (temp > standard)
	{
		x.previous_partner.push_back(x.now_partner);
		y.previous_partner.push_back(y.now_partner);
		y.now_partner.clear();
		x.now_partner = z.name;			//const!!!
		z.now_partner = x.name;
		return(true);
	}
	else
	{
		return(false);
	}

}


void  woo(Student_info& x, Student_info& y,const double& standrad)
{
	double temp;
	temp = delta(x.charm, y.charm);
	if (temp > standrad)
	{
		cout << "the two people can't be a partner because of charm" << endl;
	}
	else
	{
		cout << "the two people can be a partner" << endl;
		x.now_partner = y.name;
		y.now_partner = x.name;
	}
}


void break_up(Student_info& x, Student_info& y)
{
	//ͬһ���˷��ֶ�β��ظ��������ʷ
	if(find(x.previous_partner.begin(),x.previous_partner.end(),x.now_partner)!=x.previous_partner.end())
	x.previous_partner.push_back(x.now_partner);
	if (find(y.previous_partner.begin(), y.previous_partner.end(), y.now_partner) != y.previous_partner.end())
	y.previous_partner.push_back(y.now_partner);
	x.now_partner.clear();
	y.now_partner.clear();
	cout << "���ֿ���" << endl;
}
