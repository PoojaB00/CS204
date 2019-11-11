#include<bits/stdc++.h>
using namespace std;
#define lli long long
int main()
{
    map<string,short> m;
    string s,str;
    lli n;
    cin>>n;
    short f=0;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        str=s;
        reverse(str.begin(), str.end()); 
        if(m.find(str)!=m.end()&&s!=str)
        f=1;
        m.insert({s,1});
    }
    if(f)
    cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}