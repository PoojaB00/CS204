// seabreeeze //

#include<bits/stdc++.h>
 
using namespace std;
 
#define lli long long
lli MOD=1e9+7;
 
#define MAXN 2000006 

// Template function //
lli powermod(lli x, lli y)  
{  
    lli res = 1;  
    x = x % MOD;
    if (x == 0) return 0;  
    while (y > 0)  
    {  
        if (y & 1)  
            res = (res*x) % MOD;  
        y = y>>1;   
        x = (x*x) % MOD;  
    }  
    return res;  
}
lli modinv(lli x)
{
    return powermod(x,MOD-2);
}
// Template functions end //

// Custom funtions //
lli tree[MAXN];

void buildTree(vector<lli> a, int n)
{
    for(int i=0;i<n;i++)
        tree[n+i] = a[i];
    for(int i=n-1;i>0;i--)
    {
        tree[i] = tree[i<<1] + tree[i<<1|1];
    }
}

void updateTree(int n, int p, lli value)
{
    tree[p+n] = value;
    p+=n;
    for(int i=p; i>1;i >>= 1)
        tree[i>>1] = tree[i] + tree[i^1];
}

lli queryTree(int n, int l, int r)
{
    lli res = 0;
    for(l+=n,r+=n;l<r;l>>=1, r>>=1)
    {
        if(l&1)
            res += tree[l++];
        if(r&1)
            res += tree[--r];
    }
    return res;
}

// Custom functions end //

int main()
{
    lli q=1;
    // cin>>q;
    time_t start, end;
    time(&start);
    for(lli tc=1;tc<=q;tc++)
    {
        // Start solution //
        int n, t;
        cin>>n>>t;
        vector<lli> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        buildTree(a,n);
        lli c, A, B;
        for(int i=0;i<t;i++)
        {
            cin>>c>>A>>B;
            if(c==2)
            cout<<queryTree(n,A-1,B)<<endl;
            if(c==1)
            updateTree(n,A-1,B);
            //cout<<i<<endl;
        }
        
        end:;
        // End Solution //
    }
    
    time(&end);
    // cout<<fixed<<double(end - start)<<setprecision(10)<<endl;
    return 0;
}