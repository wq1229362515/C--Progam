#pragma  once 


class Animal {
private:
	int x;
	int y;
public:
	//����������
	Animal(int weight,int hight);
	Animal();
	void Eat();
	void Sleep();
	virtual void Breath();    //�麯��,�ڸ���������,����������д�ú���
	~Animal();

};