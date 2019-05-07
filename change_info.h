#pragma once
//Í·ÎÄ¼þchange_info.h

#include<iostream>
#include<string>
#include<vector>
//#include<cctype>
#include"Student_info.h"
//#include"expression.h"
#include"make_first.h"


void change_info(std::vector<Student_info>& s, struct building &b, const double &food_weight, const double& food_cost, const double& study_weight, const double& study_knowledge, const double& work_money, const double& work_weight, const double& doublelove_threshold, const double& love_change_threshold);
int word_number(std::string);
//int IncludeChinese(std::string);
void print_out(const std::vector<Student_info>& s, const building& b);