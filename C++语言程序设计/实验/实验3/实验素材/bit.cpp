#include<iostream>
template<typename T>
void Bits(T const& e)
{
	int n(sizeof(T));
	char* ch=(char*)&e;
	for(int i(n-1),j;i>=0;--i)
	{
		for(j=7;j>=0;--j)
			ch[i]&(char(1)<<j) ? std::cout<<1 : std::cout<<0;
		std::cout<<' ';
	}
	std::cout<<"\n";
}
int main()
{	int w=-1082130432;
    unsigned int u= 3212836864;
    float f=-1.0;
    Bits(w);Bits(u);Bits(f);
    
    float a=3.14, b=1.0;
    double d=6.28,e=-1.0;
    int x=-1,z=2147483647;
    
    Bits(a);Bits(b);
    Bits(d);Bits(e);
    Bits(x);
    Bits(z);
    Bits(z+1);
    
    return 0;
}
