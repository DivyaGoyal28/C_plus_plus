#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

class A {

    int a;
	public :
		
	A()
	{
		cout << "const A";
	}
	virtual void pure_fun()=0;
	virtual void fun()
	{
		cout << "fun a" ;
	}

};
class B : virtual public A{
	public:
	B()
	{
		cout << "const B";
	}
	void pure_fun()
	{
		cout << "pure fun b" ;
	}
	void fun()
	{
		cout << "fun b" ;
	}
};
class C : virtual public A{
	public:
	C()
	{
		cout << "const C";
	}
	void pure_fun()
	{
		cout << "pure fun c" ;
	}
	void fun()
	{
		cout << "fun c" ;
	}
};
class D : public B,public C{
	public:
	D()
	{
		// inherited B -> inherited A
		// inherited C -> inherited A
		// since virtual therefore only one copy will be created
		cout << "const D";
	}
	void pure_fun()
	{
		cout << "pure fun d" ;
	}
	void fun()
	{
		cout << "fun d" ;
	}
};

int main()
{
	A *obj = dynamic_cast<A*> (new D());
	obj->fun();
	obj->pure_fun();
	A *cobj = dynamic_cast<A*> (new C());
	if(cobj)
	obj = dynamic_cast<D*> (cobj);
	if(obj)
	cout << "exists";
	else
	cout <<"not" ;
	return 0;
}
