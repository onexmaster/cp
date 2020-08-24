#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	vector<int>dp(n,1);
	int res=1;
	for(int i=1;i<n;i++)
	{
		if(arr[i]<=2*(arr[i-1]))
		{
			dp[i]=dp[i-1]+1;
			res=max(res,dp[i]);
		}
	}
	cout<<res;
}
