#pragma once
#include<vector>
//ͷ�ļ� make_first.h

//�ж���������
struct building
{
	unsigned int floor_number;
	std::vector<int> room_number;//��push_back!�б�����ô�ã�����
	std::vector<std::vector<int>> capacity;//��ʼ�����⣡��;
	//��������������

};
void read_first(building& s,double &food_weight,double& food_cost,double& study_weight,double& study_knowledge,double& work_money,double& work_weight, double& love_threshold, double& love_change_threshold);
