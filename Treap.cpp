#include<bits/stdc++.h>

using namespace std;


//structure for node
struct node
{
	int data;
	node *parent,*right,*left;
	int p;
};


//create new node
node * createNode(int k)
{
	node * temp= (node*) malloc(sizeof(node));
	temp->right=NULL;
	temp->left=NULL;
	temp->p=rand();
	temp->data=k;
}
 



// int updateheight(node* r)
// {
// 	if(r==NULL)
// 	return 0;
// 	return 1+max(updateheight(r->left),updateheight(r->right));
// }
// int height(node* r)
// {
// 	if(r==NULL)
// 	return 0;
// 	return r->height;
// }



//rotation functions
node * rightrotate(node * r)
{
	node * temp = r->left->right, *n=r->left;
	r->left->right=r;
	r->left=temp;
	// r->height=updateheight(r);
	// n->height=updateheight(n);
	return n;
}

node * leftrotate(node * r)
{
	node * temp = r->right->left, *n=r->right;
	r->right->left=r;
	r->right=temp;
	// r->height=updateheight(r);
	// n->height=updateheight(n);
	return n;
}




//To balance tree
// node* balancenew(node *r)
// {
// 	int d=height(r->left)-height(r->right);
// 	if(d>1)
// 	{
// 		if(height(r->left->right)>height(r->left->left))
// 			r->left=leftrotate(r->left);
// 		r=rightrotate(r);
// 	}
// 	else if(d<-1)
// 	{
// 		if(height(r->right->left)>height(r->right->right))
// 			r->right=rightrotate(r->right);
// 		r=leftrotate(r);
// 	}
// 	return r;
// }



//delete node using key
node* deleteNode(node* root, int key)  
{  
    if(root==NULL)
	return root;
	else if(root->data>key)
	{
		  root->left=deleteNode(root->left,key);
	}
	  else if(root->data<key)
	{	
		  root->right=deleteNode(root->right,key);
	}
	else{
		if(root->left==NULL||root->right==NULL)
		{
			node * t=root->left?root->left:root->right;
			if(t)
			{
				*root=*t;
				free(t);
				t=NULL;
			}
			else 
			{
				free(root);
				root=NULL;
			}
		}
		else
		{
            if(root->right->p>root->left->p)
            {
                root=leftrotate(root);
                deleteNode(root->left,key);
            }
            else 
            {
                root=leftrotate(root);
                deleteNode(root->right,key);
            }
			// node* t=root->right;
			// while(t->left!=NULL)
			// t=t->left;
			// root->data=t->data;
			//root->right=deleteNode(root->right,t->data);
		}
	}
	// if(root!=NULL)
	// {root=balancenew(root);
	// root->height=updateheight(root);}
	return root;
    
}




//insert using pointer to node

node * insert ( node * root , node *t)
{
	node *n;
	if(root==NULL)
	return t;
	else if( t->data >root->data)
	{root->right=insert(root->right,t); 
     if(root->p<root->right->p)
     root=leftrotate(root);
     }
	else 
	{root->left=insert(root->left,t); 
     if(root->p<root->left->p)
     root=rightrotate(root);
     }
	//root=balancenew(root);
	//root->height=updateheight(root);
	return root;
}


//search
node * search(node * root,int key)
{
	if(root==NULL)
	return root;
	if(root->data>key)
	return search(root->left,key);
	else if(root->data<key)
	return search(root->right,key);
	else return root;
}

//print
void printInorder( node* t) 
{ 	node* root=t;
    if (root==NULL) 
        return; 
    printInorder(root->left); 
    cout << root->data<<' '; 
    printInorder(root->right); 
} 

int main()
{
	node * n=createNode(2),*root=NULL;
	int q;
	cin>>q;

	while(q--)
	{
		int t;
		cin>>t;
		n=createNode(t);
		root=insert(root,n);
	}

	printInorder(root);
	cout<<endl;
	if(search(root,2)==NULL)
	cout<<"Not found"<<endl;
	else cout<<"Found"<<endl;
	root=deleteNode(root,77);
	printInorder(root);
	cout<<endl;
	return 0;
}