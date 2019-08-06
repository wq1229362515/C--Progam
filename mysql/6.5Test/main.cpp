#include<iostream>
#include "MYSQL.h"
using namespace std;




int main(){

	Mysql mysql;
	//mysql -h 127.0.0.1 -P 3306 -u root -p
	/*
	bool Connection(const char*host,
	const char* user,
	const char*passwd,
	const char*db_name,
	unsigned int port = 3306);
	
	*/
					
	//				服务器的IP  使用的用户 密码    使用的库 使用的端口 
	//192.168.247.132
	//127.0.0.1
	mysql.Connection("192.168.247.132","root","wqwq123","Cashier",3306);

	//mysql.Enquiry("select *from Employee");
	//mysql.Add("insert into employee values(6,'王八','nan','1997-01-07','12336','售货员','15700000006',9000);");
	//mysql.Enquiry("select *from Employee");
	//mysql.Delete("delete from Employee where id=6;");
	//mysql.Enquiry("select *from Employee");


	vector<vector<string>> temp = mysql.SelectDB("select *from Employee");


	return 0;
}