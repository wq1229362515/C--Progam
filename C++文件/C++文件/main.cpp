#include"Test.h"

void inputdata1(){

	stud[0] = { 01, "�ųɳ�", 1, 501, 1334123 };
	stud[1] = { 02, "��ɻ�", 2, 101, 1334123 };
	stud[2] = {03,"���ɷ�",2,101,1334123};
	stud[3] = {04,"������",1,502,1334123};
	stud[4] = {05,"�¶�",2,101,1334123};
	stud[5] = {06,"���",1,502,1334123};
	stud[6] = {07,"��԰԰",2,102,1334123};

	ofstream outfile("A.txt", ios::binary);
	if (!outfile){
		cerr <<  "open error!" << endl;
		abort();
	}
	for (int i = 0; i < Max; i++){
		outfile.write((char*)&stud[i], sizeof(stud[i]));
	}
	outfile.close();
}

void outputdata1(){
	ifstream infile("A.txt", ios::binary);
	if (!infile){
		cerr << "open error!" << endl;
		abort();
	}
	for (int i = 0; i < Max; i++){
		infile.read((char *)&stud[i],sizeof( stud[i]));
	}
	infile.close();
	for (int i = 0; i < Max; i++){
		cout << "id :" << stud[i].id << endl;
		cout << "name :" << stud[i].name<< endl;
		cout << "sex :" << stud[i].sex << endl;
		cout << "dumnum :" << stud[i].donumber << endl;
		cout << "phonenumber :" << stud[i].phonenumber << endl;
		cout << endl;
	}
}

void findstudent(){

	int id;
	cout << "����Ҫ����ѧ����ѧ��:" << endl;
	cin >>id;
	while (1){
		for (int i = 0; i < Max; i++){
			if (id == stud[i].id){
				cout << "id :" << stud[i].id << endl;
				cout << "name :" << stud[i].name << endl;
				cout << "sex :" << stud[i].sex << endl;
				cout << "dumnum :" << stud[i].donumber << endl;
				cout << "phonenumber :" << stud[i].phonenumber << endl;
				cout << endl;
				return;
			}
		}
		cout << "���޴���" << endl;
		return;
	}

}
int main(){


	inputdata1();		//����ѧ���ļ���Ϣ1
	outputdata1();		//��ʾѧ����Ϣ1

	findstudent();
	return 0;
}