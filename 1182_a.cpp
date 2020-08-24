#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n%2!=0)
		cout<<0;
	else
	{
		int ans=pow(2,n/2);
		cout<<ans;
	}
}
