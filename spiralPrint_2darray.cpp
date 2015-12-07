#include <iostream>

using namespace std;
void print_array(int a[4][6],int m,int n)
{
	for (int i=0;i< m;i++)
	{
		for(int j=0;j< n;j++)
		cout << a[i][j]<< " ";
		cout <<endl;
	}
}
void print_spiral(int a[4][6],int m,int n)
{
	int k,l,row,col;
	k=0;l=0;row=0;col=0;
    
    /*k starting row index
     *l starting col index
     *m ending row idex
     *n ending col index */
     
	while (k < m && l < n)
	{
	//right
	while (col < n)
	{
		cout << a[row][col] <<" ";
		col++;
	} 
	n--;
	row++;
	col--;
	//cout << "col " << col << "row " <<row <<endl; 
	//down
	while( row < m)
	{
		cout << a[row][col]<<" ";
		row++;
	} m--;
	col--;
	row--;
	//cout << "col " << col << "row " <<row <<endl; 
	//left
	while (col >= l)
	{
		cout << a[row][col]<<" ";
		col--;
	}
	l++;
	row--;
	col++;
	//cout << "col " << col << "row " <<row <<endl;
	//up
	while (row > k)
	{
		
		cout << a[row][col]<<" ";
		row--;
	}
	k++;
	col++;
	row++;
	//cout << "col " << col << "row " <<row <<endl;
}

	
}
int main()
{
	int a[4][6] = {
		{1,2,3,15,32,120},
		{4,5,6,19,134,142},
		{7,8,9,21,0,14},
		{10,11,12,23,50,100}
		};
	print_array(a,4,6);
	print_spiral(a,4,6);
	return 0;
}
