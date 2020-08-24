#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int dp[n];
	dp[0]=n;
	for(int i=1;dp[i-1]>0;i++)
	{
		//Take dp[i-1] and find its maximum digit and minus it and repeat unill it becomes 0
			int maximum=0;
			int number=dp[i-1];
			while(number!=0)
			{
				int rem=number%10;
				number=number/10;
				maximum=max(rem,maximum);
			}
			dp[i]=dp[i-1]-maximum;
	}
	int count=0;
	for(int i=0;dp[i]>0;i++)
		count++;
	cout<<count;
}
