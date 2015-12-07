#include <iostream>
#include <typeinfo>

using namespace std;
class A {
	private:
	int a;
	public:
	A(){cout <<"in ctor A="<< endl;}
	virtual void fun()
	{
		cout <<"in fun A="<< endl;
	}
};
class B :public A {
	int b;
	public:
	B() {cout <<"in ctor B="<< endl;}
	void fun()
	{
		cout <<"in fun B="<< endl;
	}
};

int main()
{
	A *obj=new A();
	B* a = dynamic_cast < B *>(obj); // A doesn't know about B
	if(a !=NULL )
	a->fun();
	return 0;
	
}
