#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

void LIS(int *arr)
{
	int *ptr1=arr[0];
	int *ptr2=arr[0];
	int *temp;
	int len=0,max_len_here=0;
	
	for(int i=0;ptr2<ptr1 && ptr2<12 ;i++)
	{
		if(*ptr2 > *ptr1 && *ptr2 )
		{
			len=(ptr2-ptr1)/sizeof(int);
			if(max_len_here < len)
			max_len_here = len;
			ptr2++;
		}
		else
		{
			temp=ptr1;
			temp++;
			while (*temp <= *ptr2){
			}
			
		}
	}
}

int main()
{
	int arr[15]={1,12,14,15,16,17,3,4,5,6,7,8};

	return 0;
}
