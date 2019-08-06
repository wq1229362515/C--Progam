#include "MYSQL.h"



//��ʼ�����Ӳ��ҷ���һ�����,����������

Mysql::Mysql(){
	_mysql = mysql_init(nullptr);
	if (_mysql == NULL)
		cout << "mysql_init()faile" << endl;
	else
		cout << "mysql_init()success" << endl;
}
Mysql::~Mysql(){
	mysql_close(_mysql);
}
//ʹ��mysql_real_connect()����һ����mysql���ݿ������
bool Mysql::Connection(const char* host,
						const char*user,
						const char*passwd,
						const char*db_name,
						unsigned int port = 3306 ){
	if (!mysql_real_connect(_mysql, host, user, passwd, db_name, port, NULL, 0)){
		cout << "connect mysql error" << endl;
		return false;
	}
	cout << "connect success" << endl;

	mysql_query(_mysql,"set names 'gbk'");
	return true;
}

//��ѯ����
bool Mysql::Enquiry(const string& str){
	if (str.empty()){
		cout << "enquiry str is empty" << endl;
		return false;
	}
	//select *form tables(xxxx);
	int ret = mysql_query(_mysql, str.c_str());
	//��������ѯ����ɹ��ķ���ֵ��һ�� 0 ???
	if ( !ret ){
		//MYSQL_RES = mysql_store_result(); ����ѯ�Ľ���õ�, ��ȡ��¼��
		MYSQL_RES* result = mysql_store_result(_mysql);
		if (result == NULL){
			mysql_error(_mysql);
			return false;
		}
		//��������˵����ȡ��������
		//int item = mysql_num_field(MYSQL_RES) ���ؼ�¼һ�����ж��ٸ��ֶ�,Ҳ�����ж��ٸ�Ԫ������ (�����Ǽ�¼��)
		int item = mysql_num_fields(result);
		cout << "Table item is " << item << endl;

		//��item�õ�֮����ȥ��ѯ�ж��ٸ���,Ҳ�����ж��ٸ�Ԫ��
		//mysql_fetch_row(MYSQL_RES)�������������һ�� �õ�����������ÿһ�� ��󷵻ؿ�
		//MYSQL_ROW ��һ������ָ�������

		/*
			MYSQL_FIFELD ��һ���ṹ�������и��ֵ�����
		*/
		cout << endl;
		MYSQL_ROW row = NULL;
		while (row = mysql_fetch_row(result)){
			for (int i = 0; i < item; ++i){
				cout << row[i]<<" ";
			}
			cout << endl;
		}
		cout << "Enquiry success" << endl;
	}
	return true;
}

bool Mysql::Add(const string& cmd){
	if (cmd.empty()){
		cout << "Your input is incorrect " << endl;
		return false;
	}
	if (mysql_query(_mysql, cmd.c_str())){
		cout << "input data success" << endl;
		return true;
	}
	return false;
}
bool Mysql::Delete(const string& cmd){
	if (cmd.empty()){
		cout << "Your input is incorrect " << endl;
		return false;
	}
	if (mysql_query(_mysql, cmd.c_str())){
		cout << "delete data success" << endl;
		return true;
	}
	return false;
}
bool Mysql::Update(const string& cmd){
	if (cmd.empty()){
		cout << "Your input is incorrect " << endl;
		return false;
	}
	if (mysql_query(_mysql, cmd.c_str())){
		cout << "Update data success" << endl;
		return true;
	}
	return false;
}


vector<vector<string>> Mysql::SelectDB(const string& db_name){
	vector<vector<string>> vret;

	if (mysql_query(_mysql, db_name.c_str())){
		vret[0][0] = (mysql_error(_mysql));
		cout << "Your input is incorrect" << endl;
		return vret;
	}
	MYSQL_RES* res = mysql_store_result(_mysql);
	if (res == NULL){
		return vret;
	}
	//��ȡitem
	int item = mysql_num_fields(res);
	MYSQL_ROW row = NULL;
	while (row = mysql_fetch_row(res)){
		vector<string> temp;
		temp.resize(item);
		for (int i = 0; i < item; ++i){
			temp[i] = row[i];
		}
		//������β�嵽��ά������
		vret.push_back(temp);
	}

	const char*str = mysql_error(_mysql);

	mysql_free_result(res);

	return vret;
	
}







