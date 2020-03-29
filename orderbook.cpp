#include<bits/stdc++.h>
using namespace std;
#define lli long long
lli mod=1e9+7;
lli cno=1;

//to store order details
class order{
    public:
    lli order_number;
    time_t time1;
    lli quantity;
    double price;
    char type;
    void display()
    {
        char buff[20];
        strftime(buff, 20, "%H:%M", localtime(&time1));
        cout<<"| #"<<setw(5)<<order_number<<" | "<<setw(10)<<buff<<" | "<<setw(8)<<quantity<<" | "<<setw(10)<<price<<" |"<<endl;
    }
};

//node for tree to store orders
struct node{
    order data;
    node *parent,*left,*right;
    int height;
};

node *buy=NULL,*sell=NULL;


//order compare function
bool compare(order o1,order o2)
{
    if(o1.price<o2.price)
    return true;
    else if(o1.price>o2.price)
    return false;
    else return o1.time1<o2.time1;
}

//***tree functions start
node * createNode(order c)
{
	node * temp= (node*) malloc(sizeof(node));
	temp->right=NULL;
	temp->left=NULL;
    temp->parent=NULL;
    temp->data=c;
    temp->height=0;
}
 
int updateheight(node* r)
{
	if(r==NULL)
	return 0;
	return 1+max(updateheight(r->left),updateheight(r->right));
}

int height(node* r)
{
	if(r==NULL)
	return 0;
	return r->height;
}

node * rightrotate(node * r)
{
	node * temp = r->left->right, *n=r->left;
	r->left->right=r;
	r->left=temp;
	r->height=updateheight(r);
	n->height=updateheight(n);
	return n;
}

node * leftrotate(node * r)
{
	node * temp = r->right->left, *n=r->right;
	r->right->left=r;
	r->right=temp;
	r->height=updateheight(r);
	n->height=updateheight(n);
	return n;
}


node* balancenew(node *r)
{
	int d=height(r->left)-height(r->right);
	if(d>1)
	{
		if(height(r->left->right)>height(r->left->left))
			r->left=leftrotate(r->left);
		r=rightrotate(r);
	}
	else if(d<-1)
	{
		if(height(r->right->left)>height(r->right->right))
			r->right=rightrotate(r->right);
		r=leftrotate(r);
	}
	return r;
}

node * insert ( node * root , node *t)
{
	if(root==NULL)
	return t;
	else if(compare(root->data,t->data))
	{
        root->right=insert(root->right,t); 
    }
	else 
	{
        root->left=insert(root->left,t); 
    }
	root=balancenew(root);
	root->height=updateheight(root);
	return root;
}

node* deleteNode(node* root, order key)  
{  
    if(root==NULL)
	return root;
	else if(compare(key,root->data))
	{
		  root->left=deleteNode(root->left,key);
	}
	  else if(compare(root->data,key))
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
			node* t=root->right;
			while(t->left!=NULL)
			t=t->left;
			root->data=t->data;
			root->right=deleteNode(root->right,t->data);
		}
	}
	if(root!=NULL)
	{root=balancenew(root);
	root->height=updateheight(root);}
	return root;
    
}
//***tree functions end

//find order with max price
node * maxorder(node *root){
    if(root==NULL)
    return NULL;
    else if(root->right==NULL)
    return root;
    return maxorder(root->right);
}

//find order with min price
node * minorder(node *root){
    if(root==NULL)
    return NULL;
    else if(root->left==NULL)
    return root;
    return minorder(root->left);
}

//execute sell order
lli executesell(lli a,double b)
{
    node *top=maxorder(buy);
    if(top!=NULL)
    if(top->data.price>=b)
    {
        lli t=min(top->data.quantity,a);
        a-=t;
        top->data.quantity-=t;
        cout<<"--> Sold "<<t<<" at "<<top->data.price<<"."<<endl;
        if(top->data.quantity==0)
        {
            buy=deleteNode(buy,top->data);
        }
        if(a)
        {
            a=executesell(a,b);
        }
    }
    return a;
}

//execute buy order
lli executebuy(lli a, double b)
{
    node *bottom = minorder(sell);
    if(bottom!=NULL)
    {
    if(bottom->data.price<=b)
    {
        lli t=min(bottom->data.quantity,a);
        a-=t;
        bottom->data.quantity-=t;
        cout<<"\n--> Bought "<<t<<" at "<<bottom->data.price<<"."<<endl;
        if(bottom->data.quantity==0)
        {
            sell=deleteNode(sell,bottom->data);
        }
        if(a)
        {
            a=executebuy(a,b);
        }
    }
    }
    return a;
}

void sellorder()
{
    order c;
    cout<<"Enter type(Limit-L/Market-M): ";
    cin>>c.type;
    cout<<"Enter Quantity: ";
    cin>>c.quantity;
    if(c.type=='M')
    {
        executesell(c.quantity,0);
        return;
    }
    cout<<"Enter Price: ";
    cin>>c.price;
    c.quantity=executesell(c.quantity,c.price);
    if(c.quantity)
    {
        c.time1=time(0);
        c.order_number=cno;
    }
    cno++;
    node *temp=createNode(c);
    if(c.quantity)
    sell=insert(sell,temp);
}

void buyorder()
{
    order c;
    cout<<"Enter type(Limit-L/Market-M): ";
    cin>>c.type;
    cout<<"Enter Quantity: ";
    cin>>c.quantity;
    if(c.type=='M')
    {
        executebuy(c.quantity,INT_MAX);
        return;
    }
    cout<<"Enter Price: ";
    cin>>c.price;
    c.quantity=executebuy(c.quantity,c.price);
    if(c.quantity)
    {
        c.time1=time(0);
        c.order_number=cno;
    }
    cno++;
    node *temp=createNode(c);
    if(c.quantity)
    buy=insert(buy,temp);
}

//print order-tree
void printInorder(node* t) 
{ 	
    node* root=t;
    if (root==NULL) 
        return; 
    if(root->right!=NULL)
    printInorder(root->right);
    t->data.display(); 
    if(root->left!=NULL)
    printInorder(root->left); 
    
} 

int main()
{
    cout<<"Enter choice:\n1. Place buy order.\n2. Place sell order. \n3. Show order Book.\n4. Exit\n";
    while(1)
    {
        cout<<"\n\nEnter choice: ";
        int c;
        cin>>c;
        cout<<endl<<endl;
        switch(c){
            case 1: buyorder();
                break;
            case 2: sellorder();
                break;
            case 3: 
                    cout<<"Sell Orders"<<endl;
                    cout<<"-----------------------------------------------"<<endl;
                    printInorder(sell);
                    cout<<"-----------------------------------------------"<<endl;
                    cout<<endl;
                    cout<<"Buy Orders"<<endl;
                    cout<<"-----------------------------------------------"<<endl;
                    printInorder(buy);
                    cout<<"-----------------------------------------------"<<endl;
                break;
            default: return 0;
        }
    }
}