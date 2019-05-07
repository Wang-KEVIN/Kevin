#pragma once
#include<vector>
//头文件 make_first.h

//判断宿舍人满
struct building
{
	unsigned int floor_number;
	std::vector<int> room_number;//用push_back!列表法该怎么用？？？
	std::vector<std::vector<int>> capacity;//初始化问题！！;
	//房间现有人数！

};
void read_first(building& s,double &food_weight,double& food_cost,double& study_weight,double& study_knowledge,double& work_money,double& work_weight, double& love_threshold, double& love_change_threshold);
