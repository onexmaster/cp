#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int dp[n+1];
	dp[0]=1;
	int count=1;
	int res=1;
	for(int i=1;i<n;i++)
	{
		if(arr[i]>arr[i-1])
		{
			count++;
			dp[i]=count;
			res=max(res,dp[i]);
		}
		else
		{
			count=1;
			dp[i]=count;
			res=max(res,dp[i]);
		}
	}
	for(int i=0;i<n;i++)
		cout<<dp[i]<<" ";
	cout<<endl;
	cout<<res;
}


/*Optimized approach


 vector<int> dp(nums.size(), 1);

        for (int i=1; i<nums.size(); i++){
            if (nums[i] > nums[i-1])
                dp[i] = dp[i-1] + 1;
*/


