//p20.1.3.cpp,dynamic_cast示例
#include <iostream>
#include <string> 
using namespace std; 
//class Base{ //有虚函数，因此是多态基类
//	public:
//		virtual ~Base() { }
//		int a = 0;
//};
//
//class Derived1:public Base {	
//	public:
//		int a = 10;
//};
//
//class Derived2:public Derived1 {	
//	public:
//		int a = 20;
//};
//
//
//int main(){
////	Base b; Derived d; Derived * pd;
////	pd = reinterpret_cast<Derived*> ( &b);  //不安全 
////	if( pd == NULL) //此处pd不会为NULL。reinterpret_cast不检查安全性，总是进行转换
////		cout << "unsafe reinterpret_cast" << endl; //不会执行
////		
////	pd = dynamic_cast<Derived*> ( &b); //会检查，不安全 
////	if( pd == NULL) //结果会是NULL，因为 &b不是指向派生类对象，此转换不安全
////		cout << "unsafe dynamic_cast1" << endl;	//会执行
////	
////	Base *bp = new Derived();
////	Derived *pb = dynamic_cast<Derived*> (bp); //会检查，不安全 
////	if( pb == NULL) //结果会是NULL，因为 &b不是指向派生类对象，此转换不安全
////		cout << "unsafe dynamic_cast1.5" << endl;	//会执行
////		
////	pd = dynamic_cast<Derived*> ( &d); //安全的转换
////	if( pd == NULL)	//此处pd不会为NULL
////		cout << "unsafe dynamic_cast2" << endl; //不会执行
//
//Base *bp = new Derived2();
//Derived1 *pb = dynamic_cast<Derived1*> (bp);
//Derived2 *pb2 = dynamic_cast<Derived2*> (bp);
//cout<<pb<<" "<<pb->a<<endl;
//cout<<pb2<<" "<<pb2->a<<endl;
//	
//	return 0;
//}


#include<iostream>
using namespace std;
template <typename T>
void swaps(T &a,T &b){
	T temp = a;
	a = b;
	b = temp ;
}
int main(){
	int a = 2,b = 3;
	swaps(a,b);
	float c = 2.0,d = 3.0;
	swaps(c,d);
}
