#include <iostream>
#include <cstdlib>
using namespace std;
 
struct node
{
    int val;
    node *l;
    node *r;
    node *up;
};

 
void insert(node *&root, int x) 
{
    if (root == NULL)
    {
        node *p = new node;
        p->val = x;
        p->l = NULL;
        p->r = NULL;
        root = p;
    }
    else
    {
        if (x >= root->val)
            insert(root->r, x);
        else
            insert(root->l, x);
    }
}

void insert2(node * & root, int k)
{
  node * x, * p;
  x = new node;
  x->l =NULL;
  x->r =NULL;

  p = root; 
  if(!p)                   
    root = x;            
  else
    while(true)           
      if(k < p->val)        
      {                      
        if(!p->l)        
        {
          p->l = x;       
          break;          
        }
        else p = p->l;
      }
      else
      {
        if(!p->r)      
        {
          p->r = x;    
          break;           
        }
        else p = p->r;
      }
  x->up  = p;               
  x->val = k; 
}
 
void inorder(node *root) 
{
    if (root != NULL)
    {
        if (root->l != NULL)
            inorder(root->l);
        cout << root->val << " ";
        if (root->r != NULL)
            inorder(root->r);
    }   
}
 
int search(node *root, int x) 
{
        if(root!=NULL)
        {
                if(root->val==x)
                        return root->val;
                else
                {
                        if(x<root->val)
                                search(root->l,x);
                        else
								search(root->r,x);
                }
        }
        else
                return 0;
}

void odnajwiekszych(node *root)
{
	if (root != NULL)
	{
		if (root->r != NULL)
			odnajwiekszych(root->r);
			cout <<root->val << " ";
		if (root->l != NULL)
			odnajwiekszych(root->l);
	}
}

 void rotacja_prawo(node *&root){
	if(root)
	{
		if(root->l)
		{
			node *a, *b;
			a = root->l;
                if(a->r){
					b = a->r;
					root->l = b;
				}
        else
			root->l = NULL;
       
            a->l = root;
            root = a;
         }
    }
}
void rot_prawo(node * & root, node * a)
{
 node *b = a->l, *p = a->up;

  if(b != NULL)
  {
    a->l = b->r;
    if(a->l) a->l->up = a;

    b->r = a;
    b->up = p;
    a->up = b;

    if(p != NULL)
    {
      if(p->l == a) 
		  p->l = b; 
	  else p->r= b;
    }
    else root = b;
  }
}



 
int main()
{
    node * root = NULL;

	insert2(root,7);
	insert2(root,1);
 	insert2(root,19);
	insert2(root,99);
	insert2(root,-5);
	insert2(root,2);
	insert2(root,20);
	insert2(root,13);
	insert2(root,25);
	insert2(root,19);


	inorder(root);
	cout<<endl<<endl<<"Czytanie max -> min"<<endl;

	odnajwiekszych(root);
	cout<<endl;
	cout<<"\nInorder: ";
	inorder(root);
	cout<<endl;
	cout<< "\npo obrocie w prawo";
	rot_prawo(root,root->r);
	cout<<endl; 

	inorder(root);
    cout << endl;
    cout<<endl;

    system("pause");
    return 0;
}