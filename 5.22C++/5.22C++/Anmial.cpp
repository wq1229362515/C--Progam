#include "Animal.h"
#include<iostream>
using namespace std;


Animal::Animal(int wight,int hight){
	x = wight;
	y = hight;	
}
Animal::Animal(){
	//不带实参的
}
void Animal::Eat(){
	cout << "anmial eat" << endl;
}
void Animal::Sleep(){
	cout << "anmial sleep" << endl;
}
void Animal::Breath(){
	cout << "anmial breath" << endl;
}
Animal ::~Animal(){

}