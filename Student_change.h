#pragma once

//头文件change_info.h

#include"Student_info.h"
double out_judge(double x);
//void change_buliding(Student_info&);//换宿舍
//void change_school(Student_info& stu, string s);//school;
void change_eat(Student_info &s, double food_taken, double food_weight,double food_cost);	//吃饭
void change_learn(Student_info& s, double study_time, double study_knowledge,double study_weight);//学习
void change_work(Student_info& s, double work_time, double work_money,double work_weight);//打工
void break_up(Student_info& x, Student_info& y);//分手
void  woo(Student_info& x, Student_info& y, const double& standrad);//追求
bool Delta2order(Student_info& x, Student_info& y, Student_info& z, const double& standard);//三角
double delta(const double& x, const double& y);//判断魅力！
