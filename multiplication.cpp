#include <bits/stdc++.h>

using namespace std;

int main()
{
int q;
cin>>q;
getchar();
while(q--)
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
vector<vector<int>> v(b.size(),vector<int>(a.size()+b.size(),0));
for(int i=0;i<b.size();i++)
{
	/*for(int j=0;j<i;j++)
	{
		v[i][j]=0;
	}*/
	t=0;
	for(int j=0;i+j<a.size()+b.size();j++)
	{
		//cout<<v[i][i+j]<<' ';
		if(j<a.size())
		v[i][i+j]=a[j]*b[i];
		
		v[i][i+j]+=t;
		
		t=v[i][i+j]/10;
		
		v[i][i+j]%=10;
		
		//cout<<v[i][i+j]<<' ';
	}
}
/*for(int i=0;i<b.size();i++)
{
	for(int j=v[i].size()-1;j>=0;j--)
	{
		cout<<v[i][j];
	}
cout<<endl;
}*/
vector<int> r(a.size()+b.size(),0);
t=0;
for(int k=0;k<b.size();k++)
{
for(int i=0;i<max(v[k].size(),r.size());i++)
{
	if(i<v[k].size())
		r[i]+=v[k][i];
	r[i]+=t;
	if(r[i]>9)
	{
		r[i]-=10;
		t=1;
	}
	else
		t=0;
	//cout<<v[i]<<endl;
}
}
int f=1;
cout<<endl;
for(int i=r.size()-1;i>=0;i--)
{
	if(r[i]==0&&f)
		continue;
	else f=0;
	cout<<r[i];
}
}
cout<<endl;
return 0;
}
