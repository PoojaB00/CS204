#include<bits/stdc++.h>

using namespace std;
bool lb(char c)
{
	if(c=='('||c=='{'||c=='['||c=='<')
		return true;
	return false;
}

bool rb(char c)
{
	if(c==')'||c=='}'||c==']'||c=='>')
		return true;
	return false;
}

char lr(char c)
{
	switch(c)
	{
		case ')': return '(';
		case '}':return '{';
		case ']':return '[';
		case '>':return '<';
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		stack <char> S;
		char c;
		string s;
		cin>>s;
		int f=1;
		for(int i=0;i<s.length();i++)
		{
			c=s[i];
			if(f)
			{
				if(lb(c))
				{
					S.push(c);
				}
				else if(rb(c))
				{
					if(S.empty())
						f=0;
					else if(S.top()!=lr(c))
						f=0;
					else S.pop();
				}
				else if(c=='|')
				{
					if(S.empty())
						S.push(c);
					else if(S.top()=='|')
						S.pop();
					else S.push(c);
				}
			}
		}
			if(!S.empty())
				f=0;
			if(f)
				cout<<"YES"<<endl;
			else 
				cout<<"NO"<<endl;
	}
return 0;
}
