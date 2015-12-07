#include <iostream>
#include <string>
#include <vector>
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
	unsigned int i=0;
	vector<int> v(5);
	vector<string> vs;
	
	while(i < 5)
    {
		v[i]=i;
		i++;
	}
	
	vector<int>::iterator it_begin=v.begin();
	vector<int>::iterator it_end=v.end();
	display(it_begin,it_end);
	
	if(!v.empty())
	v.erase(v.begin());
	
	it_begin=v.begin();
	it_end=v.end();
	display(it_begin,it_end);
	
	//playing with strings
	
	vs.push_back("divya");
	vs.push_back("shikhar");
	vs.push_back("shelly");
	vs.push_back("sheila");
	
	vector<string>::iterator its_begin=vs.begin();
	vector<string>::iterator its_end=vs.end();
	display(its_begin,its_end);
	
	sort(vs.begin(),vs.end());
	
	vs.erase(vs.begin()); // adding/removing first element ; should be avoided as it is inefficient for long vectors
	its_begin=vs.begin();
	its_end=vs.end();
	display(its_begin,its_end);
	
	return 0;
}
