#include <iostream>
#include <cstdlib>

using namespace std;
void print_array(int a[3][3],int m , int n)
{
     for(int i=0;i<3;i++)
    {
            for(int j=0;j<3;j++)
            {
                    cout << a[i][j] <<" ";
            }
                    cout <<endl;
    }
}
int main()
{
    int a[3][3]={10,16,28,11,20,30,15,33,42};
    int num=33;
    int i,j;
    print_array(a,3,3);
            for(i=2,j=0;i >= 0 && j < 3;)
            {
                            if(num==a[i][j])
                            {
                                 cout << num << "found at a[" << i << "][" << j << "]" <<endl;
                                 break;
                            }
                            if(num>a[i][j])
                            j++;
                            if(num<a[i][j])
                            i--;

            }
    
    system("PAUSE");
    return 0;
}
