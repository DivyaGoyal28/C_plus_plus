#include <iostream>
#include <memory>

using namespace std;

template <typename T> class SP
{
	private:
	T *ptr;
	public:
	static int refcount;
	SP(T *ptr =NULL):ptr(ptr)
	{
		refcount++;
	}
	SP(const SP<T>& sp):ptr(sp.ptr)
	{
		cout << "copy ctor" <<endl;
		refcount++;
	}
	~SP()
	{
		cout << "delete ptr" <<endl;
		refcount--;
		if(refcount==0)
		delete ptr;
	}
	T &operator * ()
	{
		return *ptr;
	}
	T &operator -> ()
	{
		return ptr;
	}
	SP<T> &operator = (const SP<T> &sp)
	{
		if(this != &sp)
		{
			refcount--;
			if(refcount==0)
		    delete ptr;
		    ptr=sp.ptr;
		    refcount++;
		}
		return *this;
	}
	void fun()
	{
		cout << "calling fun p=" << *ptr <<endl;
	}
};
template <typename T> int SP<T>::refcount=0;

int main()
{
	SP<int> p=new int(10);
	p.fun();
	cout << "count="<< SP<int>::refcount <<endl; 
	SP<int> q(new int(20)) ;
	q.fun();
	cout << "count="<< SP<int>::refcount <<endl; 
	SP<char> q1(new char('d'));
	q1.fun();
	cout << "count="<< SP<char>::refcount <<endl; 
	SP<char> q2(new char('d'));
	q2.fun();
	cout << "count="<< SP<char>::refcount <<endl;
	SP<char> q3 = q1;
	q3.fun();
	cout << "count="<< SP<char>::refcount <<endl;
	
	return 0;
}
