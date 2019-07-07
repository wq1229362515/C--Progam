#pragma once
#define Max 7
#define Max_info 1024
using namespace std;
#include<iostream>
#include<fstream>
// 学生基本信息
struct student {
	int id;
	char name[1024];
	int  sex;
	int	 donumber;
	int  phonenumber;
};
//文件二做成一个结构体
struct studentinfo {
	int id;
	char courseID[1024];	//课程ID
	char coursename[1024];	//课程名称
	int op;			// 学分
	int n_score;	//平时成绩
	int e_score;	//实验成绩
	int	j_score;	//卷面成绩
	int argv_score; //平均成绩
	int e_op;		//实验学分
};



struct student stud[Max];
struct student info[1024];
void inputdata1();
void findstudent();