#include"expression.h"


double exp(double FOOD_TAKEN,double FOOD_WEIGHT,double STUDY_TIME,double STUDY_WEIGHT,double WORK_TIME,double WORK_WEIGHT)
{
	return (2 * FOOD_TAKEN * FOOD_WEIGHT - 0.5 * STUDY_TIME  * STUDY_WEIGHT - 1.5 * WORK_TIME * WORK_WEIGHT);
}

double exp(double WORK_TIME,double WORK_MONEY,double FOOD_TAKEN,double FOOD_COST)
{
	return(0.8 * WORK_TIME * WORK_MONEY - 1.2 * FOOD_TAKEN * FOOD_COST);
}

double exp(double STUDY_TIME,double STUDY_KNOWLEDGE)
{
	double a = 0.6 * STUDY_TIME * STUDY_KNOWLEDGE;
	return(a);
}

double expcharm(double KNOWLEDGE_INC,double WEIGHT_INC)
{
	//不是在这里判断！！
	double a = 1.5 * KNOWLEDGE_INC - 0.3 * WEIGHT_INC;	//要返回变量！！！不能直接返回数字!
	return(a);
}