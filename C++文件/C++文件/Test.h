#pragma once
int  Size = 7;			//学生的数量
#define Max_info 1024   //信息最大录入量
#define Itemnum 6		//信息录入实际量
using namespace std;
#include<iostream>
#include<fstream>
// 学生基本信息(文件一)结构体
struct student {
	int id;
	char name[1024];
	int  sex;
	int	 donumber;
	int  phonenumber;
};
//文件二结构体
struct studentinfo {
	int id;
	char courseID[1024];	//课程ID
	char coursename[1024];	//课程名称
	int op;			// 学分
	int n_score;	//平时成绩
	int e_score;	//实验成绩
	int	j_score;	//卷面成绩
	int argv_score; //综合成绩
	int e_op;		//实验学分
};



struct student stud[7];
struct studentinfo info[1024];

//加载数据,显示屏输出数据
void inputdata1();
void outputdata1(); 
void inputdata2();
void outputdata2();
//条件查找
void findstudent();			//Id查找学生
void findstudent_dor();			//宿舍号查找学生


void calculateScore();		//计算学生成绩
void Scoreinquire();		//学生成绩查询
void DeleteStudent();		//删除学生,通过学号Id删除
void Sortscore();			//排序综合成绩