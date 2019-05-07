#pragma once
//Í·ÎÄ¼þ Student_info
//#include<iostream>
//#include<algorithm>
#include<string>
#include<vector>
//#include <fstream>
//#include<stdio.h>

struct Student_info
{
	std::string name;
	std::string sex;
	std::string floor;
	std::string room;
	unsigned int weight;
	double charm;
	double money;
	double knowledge;
	std::string now_partner;
	std::vector<std::string> previous_partner;

	
};

void read_make(Student_info& s);

	/*ifstream infile;
    infile.open("1.txt");
    if(!infile) cout<<"error"<<endl;

    std::string str;
    int t1;
	while(getline(infile,str))   
	 {   
        infile.getline(str,20);
		
        cout<<str<<endl;
	 }*/
