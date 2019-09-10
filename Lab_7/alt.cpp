#include<bits/stdc++.h>

using namespace std;

vector<vector<pair<string,int>>> radixsort(vector<vector<pair<string,int>>> v,int n)
{
	vector<vector<pair<string,int>>> v1(10);

	for(int k=0;k<10;k++)
	{
		for(int i=0;i<v[k].size();i++)
		{
			v1[v[k][i].first[(n-1)%v[k][i].second]-'0'].push_back(v[k][i]);
		}
	}
	if(n==1)
		return v1;
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
		for(int i=0;i<q;i++)
		{
			cin>>s;
			v[s[0]-'0'].push_back({s,s.length()});
		}
		v1=radixsort(v,40);
		for(int i=9;i>=0;i--)
		{
			for(int k=v1[i].size()-1;k>=0;k--)
				for(int j=0;j<v1[i][k].second;j++)
					cout<<v1[i][k].first[j];
		}
		cout<<endl;
	}
	return 0;
}

