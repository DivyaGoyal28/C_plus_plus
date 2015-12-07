#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <malloc.h>

//Heap
using namespace std;

template <class T>
class my_heap {
	
	private:
     T *m_heap;
     int m_size;
     int heap_size;
	
	public:
	  my_heap(int size);
	  void del_min();	
	  void insert(T elem);
	  void up_heap(int pos);
	  void down_heap(int pos);
	  void swap(T *a,T *b);
	  void print_array();
};

template <class T>
my_heap<T>::my_heap(int size)
{
	m_size=size;
	heap_size=0;
	m_heap = new T[m_size];
}

template <class T>
void my_heap<T>::insert(T elem)
{
	heap_size++;
	m_heap[heap_size-1]=elem;
	up_heap(heap_size-1);
    
}

template <class T>
void my_heap<T>::del_min()
{
	m_heap[0]=m_heap[heap_size-1];
    heap_size--;
     if(heap_size > 0)
     down_heap(0);
}

template <class T>
void my_heap<T>::up_heap(int pos)
{
	if(pos!=0)
	{
		int parent = (pos-1)/2;
		if(m_heap[pos] < m_heap[parent])
		{
			swap(&m_heap[pos],&m_heap[parent]);
			up_heap(parent);
		}
		
	}
}

template <class T>
void my_heap<T>::down_heap(int pos)
{
	int left=2*pos+1;
	int right=2*pos+2;
	int min_index=0;
	
	if(left >= heap_size || right >= heap_size)
	return;
	
	if(m_heap[right] >= m_heap[left])
	min_index=left;
	else
	min_index=right;
	
	if(m_heap[min_index] < m_heap[pos])
	{
		swap(&m_heap[min_index],&m_heap[pos]);
		down_heap(min_index);
	}
	
	
}

template <class T>
void my_heap<T>::swap(T *a,T *b)
{
	T temp;
	temp=*a;
	*a=*b;
	*b=temp;
	
}

template <class T>
void my_heap<T>::print_array()
{
	for(int i=0;i<heap_size;i++)
	cout<<m_heap[i]<<endl;
}


int main ()
{
my_heap<int> *obj_int = new my_heap<int>(6);
obj_int->insert(3);
obj_int->insert(5);
obj_int->insert(1);
obj_int->insert(8);
obj_int->insert(2);
obj_int->insert(7);
obj_int->print_array();
obj_int->del_min();
cout<<endl;
obj_int->print_array();
my_heap<string> *obj_string = new my_heap<string>(6);
obj_string->insert("divya");
obj_string->insert("shikhar");
obj_string->insert("shelly");
obj_string->insert("ishu");
obj_string->insert("mummy");
obj_string->insert("papa");
obj_string->print_array();
obj_string->del_min();
obj_string->del_min();
cout<<endl;
obj_string->print_array();

return 0;

}
