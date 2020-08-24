#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,arr+n);
	int problem=0;
	for(int i=0;i<n-1;i++)
	{
		problem+=(arr[i+1]-arr[i]);
		i++;
	}
	cout<<problem;
	return(0);
}
