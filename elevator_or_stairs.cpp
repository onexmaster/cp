#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,c;
	cin>>n>>c;
	//Store stairs in array
	int stairs[n-1];
	for(int i=0;i<n-1;i++)
		cin>>stairs[i];
	//Store elevator in array
	int elevator[n-1];
	for(int i=0;i<n-1;i++)
		cin>>elevator[i];
	//Create a dp array of size n and store the min values so far
	int dp[n][2];
	dp[0][0]=0;
	dp[0][1]=c;
	for(int i=1;i<n;i++)
	{
		dp[i][0]=min(dp[i-1][0],dp[i-1][1])+stairs[i-1];
		dp[i][1]=dp[i][0]+c;
		dp[i][1]=min(dp[i][1],dp[i-1][1]+elevator[i-1]);
	}
	for(int i=0;i<n;i++)
	cout<<min(dp[i][0],dp[i][1])<<" ";
	return 0;
}

