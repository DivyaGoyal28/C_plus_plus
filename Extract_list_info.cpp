#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

typedef struct info {
string name;
int id;
}info;

template <class T> 
void display (T &start,T &end)
{
	while(start!=end)
	{
		cout << start->id <<"has name "<<start->name <<endl;
	    start++;
	}
	cout<<endl;
}

int main()
{
	list<info> l1;
	
	list<info>::iterator it_begin;
	list<info>::iterator it_end;
	info obj1[2];
	
	obj1[0].name="divya";
	obj1[0].id=1;
	obj1[1].name="shikhar";
	obj1[1].id=2;
	
	l1.push_back(obj1[0]);
	l1.push_back(obj1[1]);
	
	it_begin=l1.begin();
	it_end=l1.end();
	display(it_begin,it_end);
	
	return 0;
}
