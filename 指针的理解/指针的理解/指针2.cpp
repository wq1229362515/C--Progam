#include<iostream>
using namespace std;



int ret;

int add1(int right, int left){
	return right + left;
}
int* add2(int right, int left){
	ret = right + left;
	return &ret;
}

double add(double left, double right){
	return left + right;
}
double sub(double, double);
double mul(double, double);
double div(double, double);

//�ص�����
//const ��*��������ݲ��ܸı�
int comper_ints(void const *a, void const*b){
	if ((*(int *)a) == (*(int *)b)){
		return 0;
	}
	else
		return 1;
}

int compare(int array[],int size, int com_num, int(*comper_ints)(void const *,void const *)){

	int i = 0;
	int temp;
	while (i <= size){
		temp = array[i];
		if (comper_ints(&array[i++], &com_num) == 0){
			break;
		}
	}
	return temp;
}

int main(){

#if 0
	int array[] = { 1, 2, 3 };
	//f��һ�����飬�����Ԫ�����Ͷ���ָ�����ε�ָ��
	//��һ��ָ������
	int *f1[] = {&array[0],&array[1],&array[2]};
	//f2��һ��ָ�룬���������ϵ�˳������������Ƚ�ϣ�����һ��ָ��
	//�ٽ�������±��������һ������ָ��,���е�ÿһ��Ԫ�ض�ָ����һ������Ŀ�ͷ
	int(*f2)[3] = &array;


	//����ָ�������Ӧ���Ǻͺ�����ԭ����һ�µ�(Ҳ����˵���������ʼ��Ϊĳ������),�����ſ��������Ӧ�ĵ�ַ����
	//������ָͨ��һ��,���������Ͳ�һ���ͽ��е�ַ�������
	//���ȡ��ַ�ǿ���ѡ���,������ӵĻ�,������Ҳ�����ת��Ϊ����ָ��
	//������ָ����ݽ����,����һ������,�ٽ��*��ַ�����,��һ��ָ������,�����Ԫ�����Ͷ�������
	//�ٽ��()�������÷�,��ô���������������;ͱ�Ϊ�˺�����ָ��
	//ȡ��ȡ��ַ��������ǿ���ѡ���,��Ϊ�������������ɱ���������ת��Ϊ����ָ��,&��ַ������ֻ����ʽ��˵���˱�����
	//����ִ�е�����!
	int(*f3)(int ,int ) = &add1;
	
	//�ڵ��õ�ʱ��,��ײ�����������ǽ��������ת��Ϊһ������ָ��,
	//���ָ��ָ��������λ��(�ڴ���),Ȼ�������÷������������,ִ�п�ʼ�������ַ�Ĵ���
	cout << add1(1, 2) << endl;
	//�������ָ�������ת��Ϊ��һ��������,�����ڱ����ڼ���ִ�к������ò�����֮ǰ�ֻ����ת����ȥ
	cout << (*f3)(1,2) << endl;

	//�������ֱ�ӻ�Ϊ����ָ��,ʡȥ��һ������
	cout << f3(1,2) << endl;

	//��һ��������ָ��,��������������ص�������һ�����ε�ָ��
	int*(*f4)(int, int) = add2;
	//cout << f4(1, 2) << endl;
	cout << *f4(1, 2) << endl;

#endif


	//����ָ������,Ҳ���Ǻ���ת�Ʊ�
	double (*oper[])(double ,double) = { add };

	cout << oper[0](1, 2) << endl;

	//����ָ�������һ�����þ��ǻص�����

	int  array[] = { 1, 2, 3, 4, 5 };	
	int size = (sizeof(array)/sizeof array[0]);
	ret = compare(array,size, array[4], comper_ints);

	//��C�������±�����úͼ�ӷ��ʱ��ʽ��һ����.
	//ptr[0] = *(ptr+(0));
	/*
		ptr��ʵ��һ��ָ�����εĳ���ָ��,�㲻��ȥ�ı�һ��������ֵ,����sizeof�͵�Ŀ�����&

			int temp1 = ptr[0];
		01218131  mov         eax,4
		01218136  imul        ecx,eax,0
		01218139  mov         edx,dword ptr [ptr]
		0121813C  mov         eax,dword ptr [edx+ecx]
		0121813F  mov         dword ptr [temp1],eax
			int temp2 = *(ptr + (0));
		01218142  mov         eax,dword ptr [ptr]
		01218145  mov         ecx,dword ptr [eax]
		01218147  mov         dword ptr [temp2],ecx
		C���±����漰�Ŀ����Ƚ϶�,���±�������,�������ָ��,֤ʵ�±���ʽ�Ľ��������Ԫ�غ�ָ��
		���ʽ��ָ���Ԫ������ͬһ����,�������Ҫ���������������λ�úͳ��ȷ������Ϣ,���ռ��һ�����ڴ�,
		�ڳ������е�ʱ��,��Щ���ݱ�����и���,��Ϊ����׼����Ϊ�ľ͸ı�������,�������ֻ�ռ��һ����ʱ��.
		 
		array[2] =  2[array]

		array��һ������ָ��,����������ܽ��������Լ�����,����*array�ǿ��Ե�
		������ptrû�б���ʼ��֮ǰ,�������һ��������Ҳ�ǷǷ���,��Ϊû�з����ڴ�ռ�,��һ��Ұָ��
		���Ǵ�ʱ����ptr++Ҳ�ǿ��Ե�,��Ϊptr��һ��ָ�����
	*/
	int *ptr = array;

	int temp1 = ptr[0];
	int temp2 = *(ptr + (0));
	*ptr++;
	
	char str1[] = "hello\n"; //��ʾһ���ַ�����Ԫ��
	char *str2 = "hello\n"; //��ʾһ���������ַ�������

	//������matrix ,�����Կ�����һ��һά����,��������Ԫ��,ÿ��Ԫ�������ǰ���10������Ԫ�ص�����
	//matrix������ֵ�ֵ��һ��ָ�����������е�һ������Ԫ�ص�ָ��,����һά����һ��,ָ��������������ĵ�һ��Ԫ��
	//��ômatrix+1 ����ָ���˵ڶ�������
	int matrix[3][8] = { 0 };

	/*
	*(matrix+1)+5		matrix��һ��ָ��,ָ���˶�ά����ĵڶ���Ԫ��,Ҳ����matrix[1],����һ��ָ��,��ʱ�����+5����,����ָ���˵ڶ�������Ԫ���еĵ�����Ԫ��
	matrix[1]+5			���ʱ����ʵmatrix��һ������,���������matrix�еĵڶ���Ԫ��,�±�ͽ����õĹ�������ͬ��

	*(matrix[1]+5)
	*(*(matrix+1)+5)
	matrix[1][5]
	
	
	*/
	return 0; 
}