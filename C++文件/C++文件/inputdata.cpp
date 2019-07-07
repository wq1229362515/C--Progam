#include "Test.h"
void inputdata(){
	
	stud[0] = {01,"Zhang",1,501,1334123};
	stud[1] = {02,"Su",2,502,1334123};
	stud[2] = {03,"Li",1,503,1334123};

	ofstream outfile("A.txt", ios::binary);
	if (!outfile){
		cerr <<  "open error!" << endl;
		abort();
	}
	for (int i = 0; i < 3; i++){
		outfile.write((char*)&stud[i], sizeof(stud[i]));
	}
	outfile.close();
					
}