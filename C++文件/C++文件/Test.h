#pragma once
#define Max 7
#define Max_info 1024
using namespace std;
#include<iostream>
#include<fstream>
// ѧ��������Ϣ
struct student {
	int id;
	char name[1024];
	int  sex;
	int	 donumber;
	int  phonenumber;
};
//�ļ�������һ���ṹ��
struct studentinfo {
	int id;
	char courseID[1024];	//�γ�ID
	char coursename[1024];	//�γ�����
	int op;			// ѧ��
	int n_score;	//ƽʱ�ɼ�
	int e_score;	//ʵ��ɼ�
	int	j_score;	//����ɼ�
	int argv_score; //ƽ���ɼ�
	int e_op;		//ʵ��ѧ��
};



struct student stud[Max];
struct student info[1024];
void inputdata1();
void findstudent();