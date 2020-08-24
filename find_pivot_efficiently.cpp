#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	//Calculate the left sum of array 
	int left_sum[n];
	left_sum[0]=0;
	for(int i=1;i<n;i++)
	{
		left_sum[i]=left_sum[i-1]+arr[i-1];
	}
/*
	//Print the left sum to check
	for(int i=0;i<n;i++)
	{
		cout<<left_sum[i]<<" ";
	}
*/

	//Calculate thd right sum 
	int right_sum[n];
	right_sum[n-1]=0;
	for(int i=n-2;i>=0;i--)
	{
		right_sum[i]=right_sum[i+1]+arr[i+1];
	}
/*
	//Print the right sum 
	for(int i=0;i<n;i++)
	{
		cout<<right_sum[i]<<" ";
	}
*/
	int res=0;
	for(int i=0;i<n;i++)
	{
		if(left_sum[i]==right_sum[i])
		{
			res=i;
			break;
		}
	}
	cout<<res;
}
