#include<bits/stdc++.h>

using namespace std;

vector<pair<long long,long long>> v;
long long maxid=-1;

long long find(long long k)
{
	long long start=0,end=v.size()-1,mid;
	while(start<=end)
	{
		mid=(start+end)/2;
		if(v[mid].first>k)
			end=mid-1;
		else if(v[mid].first<k)
			start=mid+1;
		else return mid;
	}
	return -1;
}


long long insert(long long k,long long am)
{
	long long start=0,end=v.size()-2,mid;
	long long i=-1;
	while(start<=end)
	{
		mid=(start+end)/2;
		if(v[mid].first<=k&&v[mid+1].first>k)
		{
			i=mid+1;
			break;
		}
		else if(v[mid].first>k)
		{
			end=mid-1;
		}
		else if(v[mid+1].first<=k)
			start=mid+1;
	}
	if(i==-1)
	{
		if(v.size()==0)
		{
			v.push_back({k,am});
			return 0;
		}
		if(k<v[0].first)
			{
				v.insert(v.begin(),1,{k,am});
				return 0;
			}
		else if(k>=v[v.size()-1].first)
		{
			v.push_back({k,am});
			return v.size()-1;
		}
	}
	else v.insert(v.begin()+i,1,{k,am});
	return i;
}

void recharge()
{
	//cout<<1;
	long long uid,am;
	cin>>uid>>am;
	//cout<<uid<<am;
	long long i=find(uid);
	if(i>=0)
	{
		v[i].second+=am;
		if(v[i].second>v[maxid].second)
		{
			maxid=i;
		}
	}
	else
	{
		i=insert(uid,am);
		if(i<=maxid)
			maxid++;
		if(maxid!=-1)
		{
			if(am>v[maxid].second)
				maxid=i;
		}
		else maxid=i;
		//cout<<endl<<maxid;
	}
	//cout<<maxid<<'o'<<endl;
}

void show()
{
	for(int i=0;i<v.size();i++)
		cout<<v[i].first<<' '<<v[i].second<<endl;
}

void max()
{
	if(maxid!=-1)
		cout<<v[maxid].first<<endl;
	else
		cout<<"No data available."<<endl;
}

int main()
{
	int n;
	cin>>n;
	long long q;
	cin>>q;
	int c;
	while(q--)
	{
		cin>>c;
		switch(c)
		{
			case 1: recharge();
					break;
			case 2: max();
					break;
			case 0: return 0;
		}
	//show();
	}
	return 0;
}