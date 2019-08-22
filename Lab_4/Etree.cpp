#include<bits/stdc++.h>

using namespace std;

struct tree 
{
    long long i;
    tree * left,* right,* parent;
};

long long prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else if(c=='$')
	return 4;
    return -1; 
} 

int isop(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/')
    return 1;
    if(c=='^'||c=='$')
    return 2;
    return 0;
}

long long mapop(char c)
{
    switch(c)
    {
        case '+': return -1;
        case '-': return -2;
        case '*': return -3;
        case '/': return -4;
        case '^': return -5;
	    case '$': return -2;
    }
}

vector<long long > postfix(string s)
{
    vector<long long > S;
    stack<long long> O;
    long long f=0,a;
    O.push('N');
    for(long long i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            if(f)
            {
                S[S.size()-1]=S[S.size()-1]*10+s[i]-'0';
            }
            else 
            {
                S.push_back(s[i]-'0');
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
                    S.push_back(mapop(c));
                }
                if(O.top()=='(')
                    O.pop();   
            }
            else if(isop(s[i])==1)
            {
                while(O.top()!='N'&&O.top()!='('&&prec(s[i])<=prec(O.top()))
                {
                    char c=O.top();
                    O.pop();
                    S.push_back(mapop(c));
                }
                O.push(s[i]);
            }
            else if(isop(s[i])==2)
            {
                while(O.top()!='N'&&O.top()!='('&&prec(s[i])<prec(O.top()))
                {
                    char c=O.top();
                    O.pop();
                    S.push_back(mapop(c));
                }
                O.push(s[i]);
            }
        }
    }
    while(O.top()!='N')
        {
            char c=O.top();
            O.pop();
            S.push_back(mapop(c));
        }
    return S;
}

tree * newNode(long long v)
{
    tree * temp=new tree;
    temp->left = NULL;
    temp->right = NULL; 
    temp->i = v; 
    return temp; 
}

tree * etree(vector<long long > v)
{
    tree *t,*t1,*t2;
    stack<tree *> st;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]>=0)
        {
            t=newNode(v[i]);
            st.push(t);
        }
        else
        {
            t=newNode(v[i]);
            t1=st.top();
            st.pop();
            t2=st.top();
            st.pop();
            if(1)
            {t->right=t1;
            t->left=t2;}
            st.push(t);
        }
    }
    return t;
}


void show(vector<long long > s)
{
    for(int i=0;i<s.size();i++)
    {
        cout<<s[i]<<' ';
    }
}

void printInorder(struct tree* node) 
{ 
    if (node == NULL) 
        return; 
    printInorder(node->left); 
    cout << node->i << " "; 
    printInorder(node->right); 
} 

long long eval(tree* root)  
{  
    if (!root)  
        return 0;  
    if (!root->left && !root->right)  
        return root->i;  
    long long l_val = eval(root->left);  
    long long r_val = eval(root->right);  
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
    long long q;
    cin>>q;
    while(q--)
    {
        long long T;
        cin>>T;
        while(T--)
        {
		    int u=1;
            string s;
            cin>>s;
		for(int i=0;i<s.length();i++)
		{
			if(u&&s[i]=='-')
			{
				s[i]='$';
				s.insert(i,"0");
			}
			if(isop(s[i])||s[i]=='(')
				u=1;
			else u=0;
		}
       // cout<<s;
            vector <long long > S;

            S=postfix(s);
            //show(S);
            tree *p=etree(S);
            cout<<eval(p)<<endl;
        }
    }
}
