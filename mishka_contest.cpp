#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int i=0;
	int j=n-1;
	int prob=0;
	while(i<=j)
	{
		if(arr[i]<=k)
		{
			prob++;
			i++;
		}
		else if(arr[j]<=k)
		{
			prob++;
			j--;
		}
		else
		{
			break;
		}
	}
	cout<<prob<<endl;
}

