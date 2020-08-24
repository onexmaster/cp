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
	vector<int>v(t);
	for(int i=0;i<t;i++)
	{
		cin>>v[i];
		if(v[i]==7 || v[i]==5)
		{
			cout<<-1;
			return 0;
		}
	}
	vector<int>freq(8,0);
	for(int i=0;i<t;i++)
	{
		freq[v[i]]++;
		if(freq[v[i]]>=t/2)
		{
			cout<<-1;
			return 0;
		}
	}
	if(freq[2]+freq[3]!=freq[4]+freq[6] || freq[3]>freq[6] || freq[4]>freq[2])
	{
		cout<<-1;
		return 0;
	}
	for(int i=0;i<freq[4];i++)
	{
		cout<<"1 2 4"<<endl;
		freq[2]--;
	}
	for(int i=0;i<freq[2];i++)
		cout<<"1 2 6"<<endl;
	for(int i=0;i<freq[3];i++)
		cout<<"1 3 6"<<endl;

	
}