#include<bits/stdc++.h>

using namespace std;

void bfs(int y, vector<vector<int>> e)
{
    vector<int> v(e.size(),1);
    queue<int> Q;
    Q.push(y);
    v[y]=0;
    while(1)
    {
        if(Q.empty())
        break;
        else
        {
            int x=Q.front();
            Q.pop();
            for(int i=0;i<e[x].size();i++)
            {
                if(v[e[x][i]])
                {
                    Q.push(e[x][i]);
                    v[y]=0;
                }
            }
            cout<<x+1<<' ';
        }
    }
}

void dfs(int x, vector<int> v, vector<vector<int>> e)
{
    v[x]=0;
    cout<<x+1<<' ';
    for(int i=0;i<e[x].size();i++)
    {
        if(v[e[x][i]])
        {
            dfs(e[x][i],v,e);
        }
    }
}

int main()
{
    int n,m,x,y;
    cin>>n>>m;
    int I;
    vector<vector<int>> e(n);
    for(int i=0;i<m;i++)
    {
                
        cin>>x>>y;
        x--; y--;
        if(!i)
        {
            I=x;
        }
        e[x].push_back(y);
        e[y].push_back(x);
    }
    cout<<"BFS"<<endl;
    bfs(I,e);
    cout<<endl;
    cout<<"DFS"<<endl;
    vector<int> v(n,1);
    dfs(I,v,e);
    cout<<endl;
    return 0;

}