#include<bits/stdc++.h>

using namespace std;

int findset(int p[], int x){
	if(x!=p[x]){
		p[x]=findset(p,p[x]);
	}
	return p[x];
}

void unionset(int p[],int r[],int a,int b){
	int x=findset(p,a);
	int y=findset(p,b);
	if(x!=y){
		if(r[x]<r[y]) swap(x,y);
		p[y]=x;
		if(r[x]==r[y]){
			r[x]++;
		}
	}
}

int main()
{
    int n,m;
    cin>>n>>m;
    long long N=1e9+7;
    int x,y,w;
    vector<pair<int,pair<int,int>>> E;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>w;
        E.push_back({w,{x-1,y-1}});
    }
    sort(E.begin(),E.end());
    int p[n],r[n];
    for(int i=0;i<n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
    vector<int> v;
    for(int i=m-1;i>=0;i--)
    {
        x=findset(p,E[i].second.first);
        y=findset(p,E[i].second.second);
        if(x!=y)
        {
            v.push_back(i);
            unionset(p,r,E[i].second.first,E[i].second.second);
        }
    }
    long long s=1;
    for(int i=0;i<v.size();i++)
    s=(s*E[v[i]].first)%N;
    cout<<s<<endl;
    return 0;
}