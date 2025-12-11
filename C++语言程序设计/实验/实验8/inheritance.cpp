#include <iostream>
using namespace std;

class Parent{
public:
	int getPrivate(){
		return priv;
	}
	int pub = 1;		
protected:
	int prot = 2;
private:
	int priv = 3;
};

class Child1:public Parent{
public:
	int getParentPublic(){
		return pub;
	}
	int getParentProtected(){
		return prot;
	}
	int getParentPrivate(){
		//父类的私有成员对子类是不可见的，如果需要访问，需要通过父类定义的公有或保护类型的成员函数进行
		//return priv;
		return getPrivate();
	}	
};


class Child2:protected Parent{
public:
	int getParentPublic(){
		return pub;
	}
	int getParentProtected(){
		return prot;
	}
	int getParentPrivate(){
		return getPrivate();
	}
};

class Child3:private Parent{
public:
	int getParentPublic(){
		return pub;
	}
	int getParentProtected(){
		return prot;
	}
	int getParentPrivate(){
		return getPrivate();
	}
};

class GrandChild1:public Child1{
public:
	int getGrandParentPublic(){
		return getPrivate();
	}		
};

class GrandChild2:public Child2{
public:
	int getGrandParentPublic(){
		return getPrivate();
	}		
};

class GrandChild3:public Child3{
public:
	//感受一些保护继承和私有继承在内部访问的区别
	int getGrandParentPublic(){
		// 因为Child3是私有继承，所以Child3继承来的所有Parent成员都成了私有的了，因此对Child3的子类来说都是不可见的了。但是Child3自己定义的新的成员对他的子类还是可见的
		//return getPrivate();
		return getParentProtected();	
	}		
};

int main(){
	Child1 c1;
	Child2 c2;
	Child3 c3;
	// 感受下公有继承和其他继承的区别，公有继承来的公有成员还是公有的，因此其父类的公有成员还是可以直接访问。但是保护继承来的公有和保护成员都成了保护成员，私有继承来的所有成员都成了私有成员，因此都对外不可见了。
	cout<<c1.getPrivate()<<endl;
	//cout<<c2.getPrivate()<<endl;
	//cout<<c3.getPrivate()<<endl;
	
	// 感受下保护继承和公有继承在外部访问的区别
	GrandChild1 gc1;
	GrandChild2 gc2;
	
	// GrandChild1公有继承了Child1，Child1又公有继承了Parent，因此Parent的公有成员一直都是公有的，可以直接访问。
	cout<<gc1.getPrivate()<<endl;
	cout<<gc1.getParentPublic()<<endl; 
	cout<<gc1.getGrandParentPublic()<<endl; 
	
	// GrandChild2公有继承了Child2，Child2又保护继承了Parent，因此Parent的公有成员都成了保护类型的，对外是不可见的，但是对内是可见的，因此在其getGrandParentPublic()的函数定义中依然可以访问保护类型的getPrivate()函数
	// cout<<gc2.getPrivate()<<endl; //Child2保护继承了Parent，因此公有函数变保护类型了，对外就不可见了
	cout<<gc2.getParentPublic()<<endl; // GrandChild2公有继承了Child2，因此Child2的公有函数还是公有的
	cout<<gc2.getGrandParentPublic()<<endl; //只能通过再写一个公有函数对这些protected类型的成员进行访问
	
	
	return 0;
}