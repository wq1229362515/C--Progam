#pragma once
int  Size = 7;			//ѧ��������
#define Max_info 1024   //��Ϣ���¼����
#define Itemnum 6		//��Ϣ¼��ʵ����
using namespace std;
#include<iostream>
#include<fstream>
// ѧ��������Ϣ(�ļ�һ)�ṹ��
struct student {
	int id;
	char name[1024];
	int  sex;
	int	 donumber;
	int  phonenumber;
};
//�ļ����ṹ��
struct studentinfo {
	int id;
	char courseID[1024];	//�γ�ID
	char coursename[1024];	//�γ�����
	int op;			// ѧ��
	int n_score;	//ƽʱ�ɼ�
	int e_score;	//ʵ��ɼ�
	int	j_score;	//����ɼ�
	int argv_score; //�ۺϳɼ�
	int e_op;		//ʵ��ѧ��
};



struct student stud[7];
struct studentinfo info[1024];

//��������,��ʾ���������
void inputdata1();
void outputdata1(); 
void inputdata2();
void outputdata2();
//��������
void findstudent();			//Id����ѧ��
void findstudent_dor();			//����Ų���ѧ��


void calculateScore();		//����ѧ���ɼ�
void Scoreinquire();		//ѧ���ɼ���ѯ
void DeleteStudent();		//ɾ��ѧ��,ͨ��ѧ��Idɾ��
void Sortscore();			//�����ۺϳɼ�