


#include<iostream>
#include <vector>


namespace wq {
	template<class T>
	class auto_ptr{
	public:
		auto_ptr(T* ptr = nullptr) :_ptr(ptr) {
			std::cout << "auto_ptr()" << std::endl;
		}
		~auto_ptr() {
			if (_ptr) {
				delete _ptr;
			}
		}
		T& operator->() {
			return _ptr;
		}
		T& operator*() {
			return *_ptr;
		}
	private:
		T* _ptr;
	};
}

using namespace wq;
void Test() {
	int* tmp = new int;
	auto_ptr<int>_ptr(tmp);
	//_ptr_ptr = tmp;
	std::auto_ptr<int>ptr(tmp);
	

}
void Mergesort(int*a, int n) {
	int* tmp = (int*)malloc(sizeof(int)*n);
	auto_ptr<int> sp(tmp);


	std::vector<int> v(100000000000000000, 10);
}
int main() {

	try {
		int a[5] = { 1, 2, 3, 4, 5 };
		Mergesort(a, 5);
	}
	catch (const char* str) {
		std::cout << str << std::endl;
	}
	try{
		Test();
	}
	catch (const char* str) {
		std::cout << str << std::endl;
	}

}