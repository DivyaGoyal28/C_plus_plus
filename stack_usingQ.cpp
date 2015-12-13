#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;
queue <int> q;
typedef struct stack
{
   int element;
   void s_push(int i)
   {
        element=i;
        q.push(i);
   
   }
   int s_pop ()
   {
       int count = q.size();
       int elem;
       while((count-1) != 0)
       {
         q.push(q.front());
         q.pop();
         count--;
       }
       return q.front();
   }
};

int main()
{
    stack my_stack;
    my_stack.s_push(1);
    my_stack.s_push(2);
    cout << my_stack.s_pop() << endl;
    cout << my_stack.s_pop() <<endl;
    my_stack.s_push(3);
    my_stack.s_push(4);
    my_stack.s_push(5);
    cout << my_stack.s_pop() << endl;
    cout << my_stack.s_pop() <<endl;
    cout << my_stack.s_pop() << endl;
    system("PAUSE");
    return 0;
}
