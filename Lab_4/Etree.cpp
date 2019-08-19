#include<bits/stdc++.h>

using namespace std;

struct tree 
{
    int i;
    tree * left,* right,* parent;
};

int prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 

bool isop(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
    return true;
    return false;
}

int mapo(char c)
{
    switch(c)
    {
        case '+': return -1;
        case '-': return -2;
        case '*': return -3;
        case '/': return -4;
        case '^': return -5;
    }
}

stack<int> postfix(char *s)
{
    stack<int> S,O;
    int f=0,a;
    O.push('N');
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            if(f)
            {
                a=S.top();
                S.pop();
                S.push(a*10+s[i]-'0');
            }
            else 
            {
                S.push(s[i]-'0');
                f=1;
            }
        }

        else 
        {
            f=0;
            if(s[i]=='(')
                O.push('(');
            else if(s[i]==')')
            {
                while(O.top()!='N'&&O.top()!='(')
                {
                    char c=O.top();
                    O.pop();
                    S.push(mapo(c));
                }
                if(O.top()=='(')
                    O.pop();   
            }
            else if(isop(s[i]))
            {
                while(O.top()!='N'&&O.top()!='('&&prec(s[i])<=prec(O.top()))
                {
                    char c=O.top();
                    O.pop();
                    S.push(mapo(c));
                }
                O.push(s[i]);
            }
        }
    }
    while(O.top()!='N')
        {
            char c=O.top();
            O.pop();
            S.push(mapo(c));
        }
    return S;
}

tree * newNode(int v)
{
    tree * temp=new tree;
    temp->left = NULL;
    temp->right = NULL; 
    temp->i = v; 
    return temp; 
}

tree * etree(stack<int> s)
{
    tree *t,*t1,*t2;
    //tree->parent=NULL;
    stack<tree *> st;
    while(!s.empty())
    {
        if(s.top()>=0)
        {
            t=newNode(s.top());
            s.pop();
            st.push(t);
        }
        else
        {
            t=newNode(s.top());
            t1=st.top();
            st.pop();
            t2=st.top();
            st.pop();

            t->right=t1;
            t->left=t2;

            st.push(t);
            s.pop();
        }
    }
    return t;
}


void show(stack<int> s)
{
    while(!s.empty())
    {
        int a=s.top();
        s.pop();
        cout<<a<<endl;
    }
}

void printInorder(struct tree* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first recur on left child */
    printInorder(node->left); 
  
    /* then print the data of node */
    cout << node->i << " "; 
  
    /* now recur on right child */
    printInorder(node->right); 
} 




int eval(tree* root)  
{  
    // empty tree  
    if (!root)  
        return 0;  
  
    // leaf node i.e, an integer  
    if (!root->left && !root->right)  
        return root->i;  
  
    // Evaluate left subtree  
    int l_val = eval(root->left);  
  
    // Evaluate right subtree  
    int r_val = eval(root->right);  
  
    // Check which operator to apply  
    if (root->i==-1)  
        return l_val+r_val;  
  
    if (root->i==-2)  
        return l_val-r_val;  
  
    if (root->i==-3)  
        return l_val*r_val;  

    if(root->i==-4)
        return l_val/r_val;
    return pow(l_val,r_val);  
}  


int main()
{   
    int q;
    cin>>q;
    while(q--)
    {
        int T;
        cin>>T;
        while(T--)
        {
            char s[100000];
            cin>>s;
            //scanf(" %[^\n]s",s);
            stack <int> S,s1;
            S=postfix(s);
            while(!S.empty())
            {
                s1.push(S.top());
                S.pop();
            }
            //show(s1);
            tree *p=etree(s1);
            //printInorder(p);
            //cout<<endl;
            cout<<eval(p)<<endl;
            //cout<<evaluate(t)<<endl;
        }
    }
}