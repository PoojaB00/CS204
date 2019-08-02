#include <bits/stdc++.h>

using namespace std;

int main()
{
	unsigned long long n;
	cin>>n;
	unsigned long long r= sqrt(n);
	for(int i=2;i<r+1;i++)
	{
		if(n%i==0)
		{
			cout<<"Number is not Prime."<<endl;
			return 0;
		}
	}
	cout<<"Number is Prime."<<endl;
	return 0;
}
