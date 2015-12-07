#include <iostream>

using namespace std;


int main()
{
	int a[6] = {2,5,2,4,3,3};
	int n=6;
	for(int i=0;i<n;i++)
	{
		a[i]=a[i]-1;
	}
	
	for(int i=0;i<n;i++)
	{
		a[a[i]%n]=a[a[i]%n]+n;
		cout << a[a[i]%n] << endl ;
	}
	for(int i=0;i<n;i++)
	{
		a[i]=a[i]/6;
		cout << i+1 <<" = "<< a[i] << " " <<endl ;
	}
	
	return 0;
}
