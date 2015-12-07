#include <iostream>
#include <typeinfo>
#include <cstring>

using namespace std;
class A {
	private:
	
	public:
	int a;
	A(){cout <<"in ctor A="<< endl;}
	virtual void fun()
	{
		cout <<"in fun A=" <<endl;
	}
	
	~A(){cout <<"in dtor A="<< endl;}
	
};
class B :public A {
	
	public:
	char *ch;
	B(char *a) 
	{
		cout <<"in ctor B="<< endl;
		ch = new char[15];
		memcpy(ch,a,strlen(a));
		cout << ch << endl;
	}
	B(const B& obj)
	{
		
		cout <<"copy ctor B"<<endl;
		ch = new char[15];
		memcpy(ch,obj.ch,strlen(obj.ch));
		cout << ch << endl;
	}
	void fun()
	{
		cout <<"in fun B="<< endl;
		strcpy(ch,"goyal");
	}
	~B(){cout <<"in dtor B="<< endl;delete []ch;};
};

int main()
{
	B obj2("divya");
	cout << obj2.ch << endl;
	B obj3(obj2);
	obj3.fun();
	cout << obj2.ch << endl;
	cout << obj3.ch << endl;
	return 0;
	
}
