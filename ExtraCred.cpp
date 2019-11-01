#include<bits/stdc++.h>

using namespace std;

#define lli long long

lli S;
lli count(lli i,lli j,lli n,lli m,lli k,short c[],short v[])
{
    v[i*n+j]=0;
    S++;
    //cout<<S<<'u';
    if(i>0)
    {
        if(c[(i-1)*n+j]==k&&v[(i-1)*n+j])
        count(i-1,j,n,m,k,c,v);
    }
    if(j>0)
    {
        if(c[i*n+j-1]==k&&v[i*n+j-1])
        count(i,j-1,n,m,k,c,v);
    }
    if(i<n-1)
    {
    	//cout<<c[i*n+j]<<'   '<<v[i*n+j]<<endl;
        if(c[(i+1)*n+j]==k&&v[(i+1)*n+j])
        count(i+1,j,n,m,k,c,v);
    }
    if(j<m-1)
    {
        if(c[i*n+j+1]==k&&v[i*n+j+1])
        count(i,j+1,n,m,k,c,v);
    }
    //cout<<S<<'x'<<i<<' '<<j<<' '<<c[i*n+j]<<endl;
    return S;
}

int main()
{
    lli n,m;
    cin>>n>>m;
    lli k;
    cin>>k;
    vector<pair<lli,lli>> V;
    short c[n*m],v[n*m];

    lli x,y;
    lli M=0;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        cin>>x;
        v[i*n+j]=1;
        c[i*n+j]=x;
    }
    // for(int i=0;i<k;i++)
    // {
    //     cin>>x>>y;
    //     x--;
    //     y--;
    //     V.push_back({x,y});
    //     c[x][y]=1;
    // }
    
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        
        if(v[i*n+j])
        {
            S=0;
            lli C=count(i,j,n,m,c[i*n+j],c,v);
            M=max(M,C);
            //cout<<c[i*n+j]<<i<<j<<endl;
            //cout<<V[i].first<<' '<<V[i].second<<endl;
        }
    }
    cout<<M<<endl;
    return 0;
}
