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
	vector<int>nums(t);
	for(int i=0;i<t;i++)
		cin>>nums[i];
	int p1=0;
	while(nums[p1+1]>nums[p1])
		p1++;
	int p2=t-1;
	while(nums[p2-1]>nums[p2])
		p2--;
	int temp=nums[p1];
	for(int i=p1;i<=p2;i++)
		if(nums[i]!=temp)
		{
			cout<<"NO";
			return 0;
		}
	cout<<"YES";	
}