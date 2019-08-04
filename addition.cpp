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
	for(int i=v.size()-1;i>=0;i--)
		if(v[i]==0)
			v.erase(v.begin()+i);
		else break;
	return v;
}

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
		while(1)			//input a
		{
			c=getchar();
			if(c==' '||c=='\n')
			{break;}
			a.push_back(c-'0');
		}
		while(1)			//input b
		{
			c=getchar();
			if(c==' '||c=='\n')
			{break;}
			b.push_back(c-'0');
		}

		for(int i=0;i<a.size()/2;i++)		//reverse a
		{
			t=a[i];
			a[i]=a[a.size()-1-i];
			a[a.size()-1-i]=t;
		}
		for(int i=0;i<b.size()/2;i++)		//reverse b
		{
			t=b[i];
			b[i]=b[b.size()-1-i];
			b[b.size()-1-i]=t;
		}


		vector<int> v=add(a,b);				//call function
		for(int i=v.size()-1;i>=0;i--)		//display
		{
			cout<<v[i];
		} 
		if(v.size()==0)
			cout<<0;
		cout<<endl;
	}
	return 0;
}
