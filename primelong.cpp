#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> a;
	char c;
	int t;
	while(1)
	{
		c=getchar();
		if(c==' '||c=='\n')
		{break;}
		a.push_back(c-'0');
	}
	int d;
	vector<int> b(1,2),O(1,1);
	for(;b.size()<=a.size()/2+1;)
	{
		vector<int> u(b.size()-1);
		for(int i=0;i<b.size()-1;i++)
		u[u.size()-1-i]=a[i];
		vector<int> o(1,1);
		for(int i=b.size()-1;i<a.size();i++)
		{
			d=0;
			u.insert(u.begin(),a[i]);
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
				
				/*t=0;
				for(int j=0;j<max(d.size(),o.size());j++)
				{
					if(j<o.size())
						d[j]+=o[j];
						d[j]+=t;
					t=d[j]/10;
					d[j]=d[j]%10;
				}*/
				if(d==0)
				d=1;
				else if(d==1)
					d=2;
			}
		}
		if(u.size()==0&&(d!=1))
		{
			cout<<"Number is not Prime."<<endl;
			return 0;
		}
			t=0;
			for(int j=0;j<max(b.size(),o.size());j++)
			{
				if(j<o.size())
					b[j]+=o[j];
				b[j]+=t;
				t=b[j]/10;
				b[j]=b[j]%10;
			//cout<<v[i]<<endl;
			}
			if(t)
				b.push_back(t);
		
	}
	cout<<"Number is Prime."<<endl;
	return 0;
}
