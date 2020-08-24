#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,y;
	cin>>n>>x>>y;
	int arr[n];
	int day;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(day=x;day<=x+y;day++)
	{
		for(int j=0;j<x;j++)
		{
			if(arr[j]<arr[day])
			{
				day=j;
			}
		}
		for(int k=day;k<=x+y;k++)
		{
			if(arr[k]<arr[day])
			{
				day=k;
			}
		}
	break;
	}
	cout<<day;
	return(day);
}
