#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int boys[n];
	for(int i=0;i<n;i++)
		cin>>boys[i];
	int m;
	cin>>m;
	int girls[m];
	for(int i=0;i<m;i++)
		cin>>girls[i];
	sort(boys,boys+n);
	sort(girls,girls+m);
	int count=0;
	int i=0;
	int j=0;
	while(i<n || j<m)
	{
		if(abs(boys[i]-girls[j])==0 || abs(boys[i]-girls[j])==1)
		{
			count++;
			i++;
			j++;
		}
		else if( boys[i]-girls[j]<0)
			i++;
		else if(boys[i]-girls[j]>1)
			j++;
	}
	cout<<count;
}
