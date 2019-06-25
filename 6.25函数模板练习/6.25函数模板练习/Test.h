#pragma  once


//���ģ��
template <class T>
class SeqList{    //SeqList  ��������
public:
	SeqList(size_t capacity = 3)
		//�ڹ��캯���к������ڲ���ɵĳ�ʼ��������ֵ
		//ֻ��������������б�������ɵĸ�ֵ,�Ž�����ʼ��
		//˳���ĳ�ʼ���Ϳ��ڹ��캯�������
		//�ڶ�������в�����ʱ����ô,����Ҫ�õ�����ģ�����
		:_Array(new T[capacity])
		, Size(0)
		, Capacity(capacity)
	{}
	~SeqList();
	//ֻҪ�Ǹı��������������ô����Ҫ��д��ģ��ĸ�ʽ
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

	//���������
	//ʵ�ֵ�������ķ���
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

