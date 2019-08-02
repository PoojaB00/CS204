#include <bits/stdc++.h>

using namespace std;
vector<int> add(vector<int> a,vector<int> b)
{
	vector<int> v(max(a.size(),b.size())+1,0);
	int t=0;
	for(int i=0;i<max(a.size(),b.size())+1;i++)
	{
		if(i<a.size())
			v[i]+=a[i];
		if(i<b.size())
			v[i]+=b[i];
			v[i]+=t;
		if(v[i]>9)
		{
			v[i]-=10;
			t=1;
		}
		else 
			t=0;
	//cout<<v[i]<<endl;
	}
	return v;
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
/*for(int i=0;i<a.size();i++)
cout<<a[i]<<' ';
cout<<endl;
for(int i=0;i<b.size();i++)
cout<<b[i]<<' ';
cout<<endl<<a.size()<<' '<<b.size();
//cout<<'p';*/
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
/*
for(int i=0;i<a.size();i++)
cout<<a[i]<<' ';
cout<<endl;
for(int i=0;i<b.size();i++)
cout<<b[i]<<' ';
cout<<endl;*/
vector<int> v=add(a,b);
for(int i=v.size()-1;i>=0;i--)
{
	if(i==v.size()-1&&v[i]==0)
		continue;
	cout<<v[i];
} 
cout<<endl;
return 0;
}
