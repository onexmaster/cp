// Created by Tanuj Jain
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
void merge(vector<int>&v, int l, int m, int r)
{
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	int temp1[n1],temp2[n2];
	for( i=0;i<n1;i++)
		temp1[i]=v[l+i];
	for(j=0;j<n2;j++)
		temp2[j]=v[m+j+1];
	i=0;//pointer for 1st temp1
	j=0;//pointer for 2nd temp array
	k=l;//k==l
	while(i<n1 && j<n2)
	{
		if(temp1[i]<=temp2[j])
		{
			v[k]=temp1[i];
			i++;
			k++;
		}
		else
		{
			v[k]=temp2[j];
			j++;
			k++;
		}
	}
	while(i<n1)
	{
		v[k]=temp1[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		v[k]=temp2[j];
		j++;
		k++;
	}
}
void merge_sort(vector<int>&v, int l, int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
		merge_sort(v,l,m);
		merge_sort(v,m+1,r);
		merge(v,l,m,r);
	}
}
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	int t;
	cin>>t;
	vector<int>v(t);
	for(int i=0;i<t;i++)
		cin>>v[i];
	merge_sort(v, 0,t-1);
	for(int i=0;i<t;i++)
		cout<<v[i]<<" ";
	
}