#include<bits/stdc++.h>

using namespace std;

vector<vector<pair<string,int>>> radixsort(vector<vector<pair<string,int>>> v,int n)
{
	vector<vector<pair<string,int>>> v1(10);

	for(int k=0;k<10;k++)
	{
		for(int i=0;i<v[k].size();i++)
		{
			// if(v[k][i].length()==n-1)
			// 	v1[(v[k][i][0]-'0')*2+2].push_back(v[k][i]);
			// else 
			v1[v[k][i].first[n-1]-'0'].push_back(v[k][i]);
			//cout<<v[k][i].first<<' ';
		}
	}
	//cout<<1;
	if(n==1)
		return v1;
	// for(int k=0;k<10;k++)
	// 	{
	// 		for(int i=0;i<v1[k].size();i++)
	// 			cout<<v1[k][i].first<<' ';
	// 		cout<<endl;
	// 	}
	 return radixsort(v1,n-1);
}

int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long q;
		string s;
		cin>>q;
		vector<vector<pair<string,int>>> v(10),v1;
		string s1="0000000000000000000000000000000000000000";
		for(int i=0;i<q;i++)
		{
			cin>>s;
			for(int i=0;i<41;i++)
			s1[i]=s[i%s.length()];
			v[s[0]-'0'].push_back({s1,s.length()});
		}
		//cout<<1;
		// for(int k=0;k<10;k++)
		// {
		// 	for(int i=0;i<v[k].size();i++)
		// 		cout<<v[k][i].first<<' '<<v[k][i].second;
		// 	cout<<endl;
		// }
		v1=radixsort(v,40);
		for(int i=9;i>=0;i--)
		{
			for(int k=v1[i].size()-1;k>=0;k--)
				for(int j=0;j<v1[i][k].second;j++)
					cout<<v1[i][k].first[j];
		}
		// for(int k=0;k<10;k++)
		// {
		// 	for(int i=0;i<v1[k].size();i++)
		// 		cout<<v1[k][i].first<<' '<<v1[k][i].second;
		// 	cout<<endl;
		// }
		cout<<endl;
	}
	return 0;
}
