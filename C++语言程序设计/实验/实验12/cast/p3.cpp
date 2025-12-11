//dynamic_cast示例
#include <iostream>
#include <string> 
using namespace std; 
class Base{ //有虚函数，因此是多态基类
	public:
		virtual ~Base() { }
};

class Derived:public Base {	};

int main(){
	Base b; 
	Derived d; 
	Derived * pd;
	
	pd = static_cast<Derived*> ( &b);  
	if( pd == NULL) 
		cout << "static_cast succeed" << endl; 
		
	pd = dynamic_cast<Derived*> ( &b);
	if( pd == NULL) 
		cout << "unsafe dynamic_cast_1" << endl;	
		
	pd = dynamic_cast<Derived*> ( &d); 
	if( pd == NULL)	
		cout << "unsafe dynamic_cast_2" << endl; 
	return 0;
}

