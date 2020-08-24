#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int global_max=1;
	int local_max=1;
	for(int i=0;i<n-1;i++)
	{
	if(arr[i]<=arr[i+1])
	{
		local_max++;
		global_max=max(global_max,local_max);
	}
	else
		local_max=1;
	}

	cout<<global_max;
	return 0;
}
