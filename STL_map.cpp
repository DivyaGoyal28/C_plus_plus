#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

template <class T> 
void display (T &start,T &end)
{
	while(start!=end)
	{
		cout<<" "<< start->first <<" " << start->second << endl;
	    start++;
	}
	cout<<endl;
}

int main()
{
	int i=0;
	map<int,string> m;
	vector<string> vs;
	vector<int> v(4);
	while(i < 4)
    {
		v[i]=i;
		i++;
	}
	vs.push_back("divya");
	vs.push_back("shikhar");
	vs.push_back("shelly");
	vs.push_back("sheila");
	
	for(int i=0;i<vs.size();i++)
	m.insert(pair<int,string>(v[i],vs[i]));
	
	map<int,string>::iterator it_begin=m.begin();
	map<int,string>::iterator it_end=m.end();
	display(it_begin,it_end);

    cout << "My map has " << m[0] << endl;
    cout << "Roll number 1 is " << m[1];
  
    it_begin=m.begin();
    display(it_begin,it_end);
    
    map<int,string>::iterator p=m.find(2);
    
    if(p!=m.end())
    cout<<p->first<<p->second<<endl;
    else
    cout<<"error not found"<<endl;
    
    cout<<"value of " << m[1];
    
     
	return 0;
}
