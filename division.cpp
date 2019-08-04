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
	//cout<<c-'0'<<endl;
}
while(1)
{
	//cout<<'Q';
	c=getchar();
	//cout<<c-'0'<<endl;
	if(c==' '||c=='\n')
	{break;}
	b.push_back(c-'0');
	
}
for(int i=0;i<b.size()/2;i++)
{
	t=b[i];
	b[i]=b[b.size()-1-i];
	b[b.size()-1-i]=t;
}
vector<int> u(b.size()-1);
for(int i=0;i<b.size()-1;i++)
	u[u.size()-1-i]=a[i];



vector<int> d(0,0),o(1,1);




for(int i=b.size()-1;i<a.size();i++)
{
	u.insert(u.begin(),a[i]);
	d.insert(d.begin(),0);
	for(int j=u.size()-1;j>=0;j--)
	{
		if(!u[j])
			u.erase(u.begin()+j);
		else break;
	}
	int f=1;
	while(f)
	{

		if(u.size()<b.size())
			f=0;
		else if(u.size()==b.size())
		{
			for(int j=u.size()-1;j>=0;j--)
				if(u[j]<b[j])
					{ f=0; break; }
				else if(u[j]>b[j])
				{
					f=1; break;
				}

		}
		if(!f)
			break;
		for(int j=0;j<u.size();j++)
		{
			if(j<b.size())
				u[j]-=b[j];
			if(u[j]<0)
				{
					u[j]+=10;
					u[j+1]--;
				}
		}
		for(int j=u.size()-1;j>=0;j--)
		{
			if(u[j]==0)
				u.erase(u.begin()+j);
			else break;
		}
		
		t=0;
		for(int j=0;j<max(d.size(),o.size())+1;j++)
		{
			if(j<o.size())
				d[j]+=o[j];
				d[j]+=t;
			t=d[j]/10;
			d[j]=d[j]%10;
			if(t==0)
				break;
			//cout<<v[i]<<endl;
		}
		if(t)
			d.push_back(t);
		//cout<<i<<' ';
	}
}
	int f=1;
	cout<<endl;
for(int i=d.size()-1;i>=0;i--)
{
	if(d[i]==0&&f)
		continue;
	cout<<d[i];
	f=0;
		
}
	if(f)
		cout<<0;
	cout<<endl;
f=1;

for(int i=u.size()-1;i>=0;i--)
{
	f=0;
	cout<<u[i];
}
	if(f)
		cout<<0;
}
cout<<endl;
return 0;
}
