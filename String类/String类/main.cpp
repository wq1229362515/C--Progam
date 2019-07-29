#include"String.h"
using namespace wq;



int main(){




	String b;
	String str("123");
	String a(str);
	b = a;
	cout << a.Size() << endl;
	cout << a.Empty() << endl;


	return 0;
}