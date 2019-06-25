#pragma  once


//类的模板
template <class T>
class SeqList{    //SeqList  不是类名
public:
	SeqList(size_t capacity = 3)
		//在构造函数中函数的内部完成的初始化叫做赋值
		//只有在这这个参数列表里面完成的赋值,才叫做初始化
		//顺序表的初始化就可在构造函数中完成
		//在对数组进行操作的时候那么,就需要用到函数模板操作
		:_Array(new T[capacity])
		, Size(0)
		, Capacity(capacity)
	{}
	~SeqList();
	//只要是改变数据类操作的那么就需要书写成模板的格式
	void CheckCapacity(){
		if (Size == Capacity){
			size_t NewCapacity = 2 * Capacity;
			// T *Newtemp =(T*) malloc(int*NewCapacuty);
			T *Newtemp = new T[NewCapacity];
			for (int i = 0; i<Size; i++){
				Newtemp[i] = _Array[i];
			}
			_Array = Newtemp;
			Capacity = NewCapacity;
		}
		else
			return;
	}
	void Pushback(const T& data){
		CheckCapacity();
		_Array[Size++] = data;
	}
	void Popback() const{
		Size--;
	}

	//运算符重载
	//实现的是随机的访问
	T& operator[] (size_t index){
		return _Array[index];
	}

	void Getsize() const{
		return Size;
	}
	bool Isempty() const{
		return 0 == Size;
	}

private:
	T * _Array;
	size_t Size;
	size_t Capacity;

};


template <class T>
SeqList<T> ::~SeqList(){
	if (_Array){
		delete[] _Array;
		Capacity = 0;
	}
}

