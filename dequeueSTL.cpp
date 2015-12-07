#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

template <class T> 
void display (T &start,T &end)
{
	while(start!=end)
	{
		cout<<" "<<*start;
	    start++;
	}
	cout<<endl;
}

int main()
{
	deque<string> ds;
	deque<string>::iterator it_begin;
	deque<string>::iterator it_end;
	
	ds.push_back("divya");
	ds.push_back("shikhar");
	ds.push_back("shelly");
	ds.push_back("sheila");
	
	it_begin=ds.begin();
	it_end=ds.end();
	display(it_begin,it_end);
	
	it_begin=ds.begin();
	ds.push_front("mummy");
	ds.insert(it_begin,"papa");
	sort(ds.begin(),ds.end());
	it_begin=ds.begin();
	display(it_begin,it_end);
	
	ds.clear();//removes all the elements
	
	
	return 0;
}
