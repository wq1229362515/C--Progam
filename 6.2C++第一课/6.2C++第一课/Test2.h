#pragma  once
 /*namespace N1{
	int  a;
	int  b;
	class Test {
	public:
		int add(int left, int right);
	};
}
*/

class Date {
public:
	void SetDate(int year, int mouth, int day);
	void PrintDate();
private: 
	int  _year;
	int  _mouth;
	int  _day;
};