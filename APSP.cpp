#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int v[n][n];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        if(i==j)
        v[i][i]=0;
        else v[i][j]=10e7;
    }
    int m;
    cin>>m;
    int x,y,w;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>w;
        v[x-1][y-1]=w;
        //v[y-1][x-1]=w;
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v[i][j]==10e7)
            cout<<"INF"<<' ';
            else
            cout<<v[i][j]<<' ';
        }
        cout<<endl;
    }

}