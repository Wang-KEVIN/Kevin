#pragma once

//ͷ�ļ�change_info.h

#include"Student_info.h"
double out_judge(double x);
//void change_buliding(Student_info&);//������
//void change_school(Student_info& stu, string s);//school;
void change_eat(Student_info &s, double food_taken, double food_weight,double food_cost);	//�Է�
void change_learn(Student_info& s, double study_time, double study_knowledge,double study_weight);//ѧϰ
void change_work(Student_info& s, double work_time, double work_money,double work_weight);//��
void break_up(Student_info& x, Student_info& y);//����
void  woo(Student_info& x, Student_info& y, const double& standrad);//׷��
bool Delta2order(Student_info& x, Student_info& y, Student_info& z, const double& standard);//����
double delta(const double& x, const double& y);//�ж�������
