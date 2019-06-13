#include<iostream>
using namespace std;


#if 0
int main1(){

	double a, b, c;
	cin >> a >> b >> c;
	system("pause");



	return 0;
}
#endif

#if 0
class A 
{
public:
	A(){
		cout << "Afun" << endl;
	}
	void f(){
		cout << "Call A " << endl;
	}
	virtual ~A(){
		cout << "A concle" << endl;
	}
};
class B:public A 
{
public:
	B(int i){
		cout << "B fun" << endl;
		buf = new char[i];
	}
	void f()
	{
		cout << "Call B" << endl;
	}
	virtual ~B()
	{	
		delete buf;
		cout << "B concle" << endl;
	}
private: 
	char *buf;
};
#endif


#if 0
class C:public A,public B
{
public: 
	void g(){
		cout << "Call C" << endl;
	}
	~C(){
		cout << "C concle" << endl;
	}
	
};
#endif


#if 0
class shape {
public:
	virtual double area() = 0;
};
class Circle :public shape{
public:
	Circle(double r){ 
		radious = r;
	}


	void set(){
		cout << "input radious = "  << endl;
		cin >> radious;
	}
	void show(){
		cout << "the radious is = " << radious << endl;
	}
	double area(){
		return 3.14*radious*radious;
	}
private:
	double radious;
};
double total(shape *s[], int n){
	double sum = 0.0;
	for (int i = 0; i < n; i++){
		sum += s[i]->area();
	}
	return sum;
}
#endif

#if 0

class A {
public:
	A(int s):x(s){}

private:
	int x;
};
#endif 
class point {
public:
	point( int x11, int x12, int y11, int y12 ){
		x1 = x11, x2 = x12, y1 = y11, y2 = y12;
	}
	friend int length(point x );
private: 
	int x1, x2;
	int y1, y2;
};
int length(point x){
	return sqrt(abs(pow((x.y1-x.x1), 2) + pow((x.y2 - x.x2), 2)));
}
int  main(){
	point x(0,0,1,1);
	cout << length(x) << endl;


#if 0
	Circle c(1.0);
	c.show();
	shape *s[] = { &c };
	cout << total(s, 1) << endl;

	int i;
	int& j = i;
	i = 10;
	j = i + 1;
#endif
	/*
	A x(5);
	return 0;
	*/
}






















