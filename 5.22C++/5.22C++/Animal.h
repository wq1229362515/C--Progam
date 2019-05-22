#pragma  once 


class Animal {
private:
	int x;
	int y;
public:
	//函数的重载
	Animal(int weight,int hight);
	Animal();
	void Eat();
	void Sleep();
	virtual void Breath();    //虚函数,在父类中修饰,在子类中重写该函数
	~Animal();

};