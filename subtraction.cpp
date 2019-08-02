#include <bits/stdc++.h>

using namespace std;

vector<int> subtract(vector<int> a, vector<int> b)
{
	
}

int main()
{
vector<int> a,b;
char c;
int t;
while(1)
{
	
	
	c=getchar();
	if(c==' '||c=='\n')
	{break;}
	a.push_back(c-'0');
}
while(1)
{

	
	c=getchar();
	if(c==' '||c=='\n')
	{break;}
	b.push_back(c-'0');
}
for(int i=0;i<a.size()/2;i++)
{
	t=a[i];
	a[i]=a[a.size()-1-i];
	a[a.size()-1-i]=t;
}
for(int i=0;i<b.size()/2;i++)
{
	t=b[i];
	b[i]=b[b.size()-1-i];
	b[b.size()-1-i]=t;
}
vector<int> v(max(a.size(),b.size()),0);
	if(a.size()>b.size())
	{
		for(int i=0;i<a.size();i++)
		{
			if(i<b.size())
				v[i]=a[i]-b[i];
			else v[i]=a[i];
			if(v[i]<0)
			{
				v[i]+=10;
				a[i+1]--;
			}
		}
	}
	else if(b.size()>a.size())
	{
		for(int i=0;i<b.size();i++)
		{
			if(i<b.size())
				v[i]=b[i]-a[i];
			else v[i]=b[i];
			if(v[i]<0)
			{
				v[i]+=10;
				b[i+1]--;
			}
		}
	}
	else 
	{
		int j=-1;
		for(int i=a.size()-1;i>=0;i--)
		{
			if(a[i]!=b[i])
				{
					j=i; break;
				}
		}
		if(j>=0)
		{
			if(a[j]>b[j])
			for(int i=0;i<=j;i++)
			{
			if(i<b.size())
				v[i]=a[i]-b[i];
			else v[i]=a[i];
			if(v[i]<0)
			{
				v[i]+=10;
				a[i+1]--;
			}
		}
		else
		for(int i=0;i<=j;i++)
		{
			if(i<b.size())
				v[i]=b[i]-a[i];
			else v[i]=b[i];
			if(v[i]<0)
			{
				v[i]+=10;
				b[i+1]--;
			}
		}

		}
	}
int f=1;

for(int i=v.size()-1;i>=0;i--)
{
	if(v[i]==0&&f)
		continue;
	else f=0;
	cout<<v[i];
} 
if(f==1)
cout<<0;
cout<<endl;
return 0;
}

