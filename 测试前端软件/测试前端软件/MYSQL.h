#pragma once

#include<Winsock2.h>
#include<mysql.h>
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
/*
	��ʼ��,����,��ɾ�Ĳ�,
	�����ӵ�ʱ�������Ѿ����ӵ��������Ҳ����˵�ǿ���ʹ����

*/
class Mysql{
public:
	Mysql();
	bool Connection(const char*host,
					const char* user,
					const char*passwd,
					const char*db_name,
					unsigned int port);				//���Ӻ���
	bool Add(const string& cmd);					//����
	bool Delete(const string& cmd);					//ɾ��
	bool Update(const string& cmd);					//�޸�
	bool Enquiry(const string& str);				//��ѯĳһ�����е�����,����ӡ����
	bool Insert(const string& cmd);
	vector<vector<string>> SelectDB(const string& db_name);			//ѡ������е����ݸ�ֵ��_table
	~Mysql();

private:
	MYSQL *_mysql;				//mysql ʵ�����������ص�һ������
	string _dbname;
	vector<string> _tables;		//һ����,���е���Ϣ���洢�������ά�ַ�����
};


