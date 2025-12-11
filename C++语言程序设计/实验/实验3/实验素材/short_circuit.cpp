#include <iostream>
using namespace std; 

int main() 
{ 
 	int a=1,b=1;
	if( a==1 || (b=2)==2)
	 	cout<<"a="<<a<<" b="<<b<<endl;
	
	if( a==1 | (b=2)==2)
	 	cout<<"a="<<a<<" b="<<b<<endl;

	return 0;
}

