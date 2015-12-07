#include <iostream>

using namespace std;

class A {
	int a;
	public:
	A(int a=0):a(a)
	{
		cout <<"ctor a= "<< a <<endl;
	}
		virtual ~A()
	{
		cout <<"A dest"<<endl;
	}
};

class B : public A {
	int b;
	public:
    B(int b=0):b(b)
	{
		cout <<"ctor b= "<< b <<endl;
	}
	void fun() {
		
		cout << "const fun " <<endl;
	
	}
	~B()
	{
		cout <<"B dest"<<endl;
	}
};
	

int main()
{

    A *obj = new B();
	obj->fun();
	delete obj;
	return 0;
}
