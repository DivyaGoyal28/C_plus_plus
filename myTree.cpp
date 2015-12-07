#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <limits.h>

#define MAX(a,b) (a>b)?(a):(b)

using namespace std;


typedef struct node {
int data;
node *lchild;
node *rchild;
}node;

template <class T>
class my_tree {
	
	private:
	
	public:
	  my_tree();
	  void del_node();	
	  void insert(T **tree,int data);
	  void in_order(T *root);
	  int size_of_tree(T *root);
	  int height_of_tree(T *root);
	  void mirror(T *root);
	  void root_to_leaf(T *root);
	  int min_val(T *root);
	  int count_leaf_node(T *root);
	  void level_order(T *root);
	  T* LCA(T *root, int n1, int n2);
	  bool BSTorNot(T *root);
	  int diameter(T *root);
	  int width(T *root);
	  void left_view(T *root);
	  void right_view(T *root);
	  void levelorder_spiral(T *root);
	  void child_sum_property(T *root);
};

template <class T>
my_tree<T>::my_tree()
{
	
}

void swap(node **a,node **b)
{
	node *temp;
	temp = *a;
	*a = *b;
	*b = temp;
	
}

template <class T>
void my_tree<T>::insert(T **root,int data)
{
	node * temp=NULL;
	if((*root)==NULL)
	{
		temp=new node();
		temp->data=data;
		temp->lchild=NULL;
		temp->rchild=NULL;
		*root=temp;
		return;
	}
		if(data < (*root)->data)
		insert(&(*root)->lchild,data);
		else
		insert(&(*root)->rchild,data);
		
}

template <class T>
void my_tree<T>::in_order(T *root)
{
	if(root)
	{
		in_order(root->lchild);
		cout << " " << root->data << endl;
		in_order(root->rchild);
	}
}

template <class T>
int my_tree<T>::size_of_tree(T *root)
{
	if(!root)
	return 0;
	else
	return(size_of_tree(root->lchild)+1+size_of_tree(root->rchild));
	
	
}

template <class T>
int my_tree<T>::height_of_tree(T *root)
{
	int lheight;
	int rheight;
	if(root==NULL)
	return 0;
	else
	{
        lheight = height_of_tree(root->lchild);
        rheight = height_of_tree(root->rchild);
	    return (MAX(lheight,rheight)+1);
	}
	
}

template <class T>
void my_tree<T>::mirror(T *root)
{
	if(root==NULL)
	return ;
	if(root->lchild || root->rchild)
	swap(&(root->lchild),&(root->rchild));
	if(root->lchild)
	mirror(root->lchild);
	if(root->rchild)
	mirror(root->rchild);
}

void printpath(int path[],int pathlen)
{
	for (int i=0 ;i < pathlen ;i++)
	cout << path[i] << "->";
	cout << endl;
}

void root_to_leaf_util(node *root,int pathlen,int path[])
{
	if(root==NULL)
	return;
	
	path[pathlen]=root->data;
	pathlen++;
	
	if(root->lchild==NULL && root->rchild==NULL )
	{
		printpath(path,pathlen);
	}
	else
	{
		root_to_leaf_util (root->lchild,pathlen,path);
		root_to_leaf_util (root->rchild,pathlen,path);
	}
	
}

template <class T>
void my_tree<T>::root_to_leaf(T *root)
{
	int path[1000];
	if(root)
    root_to_leaf_util (root,0,path);
    else
    return;
 }

template <class T>
int my_tree<T>::min_val(T *root)
{
	if(root==NULL)
	return -1;
	
	if(root->lchild==NULL)
	return root->data;
	else
	min_val(root->lchild);
	
}

template <class T>
int my_tree<T>::count_leaf_node(T *root)
{
	
	if(root==NULL)
	return 0;
	if(root->lchild==NULL && root->rchild==NULL)
	{
		return 1;
	}
	   return(count_leaf_node(root->lchild)+count_leaf_node(root->rchild));
}

template <class T>
void my_tree<T>::level_order(T *root)
{
	node *temp =root;
	queue <node*> q;
	if(root==NULL)
	return;
	if(root)
	q.push(root);
	while(!q.empty())
	{
	   node * temp = q.front();
	   cout << endl;
	   cout << " " << temp->data ;
       if(temp->lchild)
	   q.push(temp->lchild);
	   if(temp->rchild)
	   q.push(temp->rchild);
	   q.pop();
    }
	
}

template <class T>
T* my_tree<T>::LCA(T *root, int n1, int n2)
{
	if(root==NULL)
	return NULL;
	if (n1 < root->data && n2 > root->data)
	return root;
	if(n1 > root->data && n2 > root->data)
	return LCA(root->rchild,n1,n2);
	if(n1 < root->data && n2 < root->data)
	return LCA(root->lchild,n1,n2);
	
}

bool BSTutil(node *root, int min ,int max)
{
	if(root == NULL)
	return true;
	if(root->data < min || root->data > max)
	return false;
	return (BSTutil(root->lchild,min,root->data-1) && BSTutil(root->rchild,root->data+1,max));
}
	

template <class T>
bool my_tree<T>::BSTorNot(T *root)
{
	/*
	if(root==NULL)
	return true;
	else
	{
	return (BSTorNot(root->lchild) && BSTorNot(root->lchild));
	if(root->lchild->data < root->data && root->rchild->data >= root->data)
	return true;
	else return false;
   }*/
 return (BSTutil(root,INT_MIN,INT_MAX));
}

template <class T>
int my_tree<T>::diameter(T *root)
{
	if(root==NULL)
	return 0;
	
	int height_l,height_r,left_d,right_d;
	height_l = height_of_tree(root->lchild);
	height_r = height_of_tree(root->rchild);
    left_d = diameter(root->lchild);
    right_d = diameter(root->rchild);
	
	return (MAX((height_l + height_r + 1),(MAX(left_d,right_d))));
}
int level_util_width(node *root,int h)
{
	if(root==NULL)
	return 0;
	if(h==1)
	return 1;
	if(h > 1)
	return level_util_width(root->lchild,h-1)+level_util_width(root->rchild,h-1);
}

template <class T>
int my_tree<T>::width(T *root)
{
	/*int max_width=0;
	int w;
	int h = height_of_tree(root);
	for(int i=1; i<=h; i++)
	{
		w = level_util_width(root,i);
		if(w > max_width)
		max_width=w;
	}
	return max_width;*/
	//Using Level order traversal
	node *temp =root;
	int count=0;
	int max_count=0;
	queue <node*> q;
	
	if(root==NULL)
	return 0;
	
	if(root)
	q.push(root);
	
	while(!q.empty())
	{
	   count=q.size();
	   if(max_count < count)
	   max_count = count;
	   while(count > 0)
	   {
		   node *temp = q.front();
		   if(temp->lchild)
		   q.push(temp->lchild);
	       if(temp->rchild)
		   q.push(temp->rchild);
	       q.pop();
	       count--;
	   }
   }
   return max_count;
}

template <class T>
void my_tree<T>::left_view(T *root)
{
	node *temp =root;
	int count=0;
	queue <node*> q;
	
	if(root==NULL)
	return;
	
	if(root)
	q.push(root);
	
	while(!q.empty())
	{
	   count=q.size();
	   int orig_count=count;
	   while(count > 0)
	   {
		   node *temp = q.front();
		   if(count == orig_count)
		   cout << temp->data << endl;
		   if(temp->lchild)
		   q.push(temp->lchild);
	       if(temp->rchild)
		   q.push(temp->rchild);
	       q.pop();
	       count--;
	   }
   }
	
}

template <class T>
void my_tree<T>::right_view(T *root)
{
	node *temp =root;
	int count=0;
	queue <node*> q;
	
	if(root==NULL)
	return;
	
	if(root)
	q.push(root);
	
	while(!q.empty())
	{
	   count=q.size();
	   while(count > 0)
	   {
		   node *temp = q.front();
		   if(temp->lchild)
		   q.push(temp->lchild);
	       if(temp->rchild)
		   q.push(temp->rchild);
		   if(count == 1)
		   cout << temp->data << endl;
	       q.pop();
	       count--;
	       
	   }
   }
	
}

template <class T>
void my_tree<T>::levelorder_spiral(T *root)
{
	node *temp =root;
	stack <node*> s1;
	stack <node*> s2;
	s1.push(root);
	while(!s1.empty() || !s2.empty())
	{
		while(!s1.empty())
	    {
	      node * temp = s1.top();
	      cout << endl;
	      cout << " " << temp->data ;
          if(temp->rchild)
	      s2.push(temp->rchild);
	      if(temp->lchild)
	      s2.push(temp->lchild);
	      s1.pop();
         }
	
	     while(!s2.empty())
	     {
	       node * temp = s2.top();
	       cout << endl;
	       cout << " " << temp->data ;
           if(temp->lchild)
	       s1.push(temp->lchild);
	       if(temp->rchild)
	       s1.push(temp->rchild);
	       s2.pop();
	     }
	  }
}

template <class T>
void my_tree<T>::child_sum_property(T *root)
{
	//Using post-order traversal
	int lchild = 0;
	int rchild = 0;
	int root_data = 0;
	
	if(root->lchild==NULL && root->rchild==NULL)
	return;
	
	child_sum_property(root->lchild);
	lchild=root->lchild->data;
	cout <<"lchild = "<< lchild <<endl;
	child_sum_property(root->rchild);
	rchild=root->rchild->data;
	cout <<"rchild = "<< rchild <<endl;
	if(root->data != (rchild+lchild))
	{
		int diff=(lchild+rchild)-(root->data)
	root->data=rchild+lchild;
	cout <<"root data = "<< root->data <<endl;
	}

template <class T>
void my_tree<T>::del_node()
{
	
}


int main()
{
	my_tree<node> *t1 = new my_tree<node>();
	my_tree<node> *t2 = new my_tree<node>();
	node *root;
	root=NULL;
	
	t1->insert(&root,9);
	t1->insert(&root,6);
	t1->insert(&root,15);
	t1->insert(&root,7);
	t1->insert(&root,12);
	t1->insert(&root,17);
	t1->insert(&root,5);
	t1->insert(&root,20);
	t1->insert(&root,1);
	t1->insert(&root,0);
	t1->in_order(root);
  /*  t1->insert(&root,3);
	t1->insert(&root,2);
	t1->insert(&root,5);
	t1->insert(&root,1);
	
	node *temp1=root;
	cout<<temp1->data <<endl;
	temp1=temp1->lchild;
	cout<<temp1->data <<endl;
    
    node *newnode = new node();
	temp1->rchild=newnode;
	newnode->data=4;
	newnode->lchild=NULL;
	newnode->rchild=NULL;
	
	cout << endl;
	cout << root->lchild->data << endl;
	cout << root->lchild->rchild->data << endl;*/
	
	//Size of tree
	cout << "Size  of tree is =" << t1->size_of_tree(root) << endl;
	
	//Height of tree
	cout << "height  of tree is =" << t1->height_of_tree(root) << endl;
	
	//Convert binary tree in mirror tree
	t1->mirror(root);
	//t1->in_order(root);
	t2=t1;
	//t2->in_order(root);
	t1->mirror(root);
	
	//print root-to-leaf paths
	t1->root_to_leaf(root);
	
	//node with minimum value in BST
	cout << "Min value is ="<<t1->min_val(root) <<endl;
	
	//count no.of leaf nodes
	cout<<"no. of leaf nodes " << t1->count_leaf_node(root) <<endl;
	
	//level order traversal
	t1->level_order(root);
	
	//Lowest common ancestor
	node * temp;
	temp=t1->LCA(root,21,23);
	if(temp==NULL)
	cout << "values do not exist in tree" << endl;
	else cout<<"LCA = " << temp->data <<endl;
	
	//Given tree is BST or not
	cout << "BST or not = " << t1->BSTorNot(root)<<endl;
	
	//Diameter of a tree
	cout << "Diameter of tree is ="<< t1->diameter(root)<<endl;
	
	//Width of a tree : is maximum number of nodes at any level
	cout << "width of tree is ="<< t1->width(root)<<endl;
	
	//Left view of tree 
	t1->left_view(root);
	
	//Right view of tree
	t1->right_view(root);
	
	//Top view of tree 
	
	//Bottom view of tree -> ??
	
	//Level order in spiral form
	t1->levelorder_spiral(root);
	
	//children sum property
	t1->child_sum_property(root);
	cout<<"Lvele order"<<endl;
	t1->level_order(root);
	
	//Swap two nodes to restore the property of BST
	
	//kth maximum element in a tree
	
	//Two trees  are identical
	
	//Two trees are isomorphic
	
	//Tree to list
	
	return 0;
}
