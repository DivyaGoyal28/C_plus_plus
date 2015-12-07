#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int **arr=new int*[10];
	int *c_arr=(int*) malloc (sizeof(int*)*10) ; //
	for(int i=0;i<12;i++)
	{
	 arr[i]=new int[12];
	}
	return 0;
}
