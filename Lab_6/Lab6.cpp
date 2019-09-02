#include<bits/stdc++.h>

using namespace std;
long long maxid=-1;
int main()
{
	long long n,q;
	cin>>n>>q;
	long long a[n]={0};
	while(q--)
	{
		int c;
		cin>>c;
		switch(c)
		{
			case 1:
			{
				long long u,am;
				cin>>u>>am;
				a[u-1]+=am;
				if(maxid==-1||am>a[maxid])
					maxid=u-1;
				break;
			}
			case 2:
			{
				if(maxid==-1)
					cout<<"No data available."<<endl;
				else cout<<maxid+1<<endl;
				break;
			}
		}
	}
	return 0;
}