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
    cout<<"Enter number of nodes:"<<endl;
    int n;
    cin>>n;
    cout<<"Enter number of edges:"<<endl;
    int m;
    cin>>m;
    int p[n],r[n];
    for(int i=0;i<n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
    int f,g,t=0,x,y;
    for(int i=0;i<m;i++)
    {
        cin>>f>>g;
        f--;
        g--;
        x=findset(p,f);
        y=findset(p,g);
        if(x!=y)
        {
            //v.push_back(i);
            unionset(p,r,f,g);
        }
        else t=1;
    }
    if(t)
    cout<<"Graph contains cycle(s)"<<endl;
    else cout<<"Graph does not contain any cycle"<<endl;
    return 0;
}