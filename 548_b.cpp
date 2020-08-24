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

int a[500][500];
int maxi[500];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	int x,y;
	int ans;
	int k1;
	//find the longest continous 1's for each row and store it in maxi
	for(int i=0;i<n;i++)
	{
		k1=0;
		maxi[i]=0;
		for(int j=0;j<m;j++)
		{
			if(a[i][j])
				k1++;
			else
			{
				maxi[i]=max(maxi[i],k1);
				k1=0;
			}
		}
		maxi[i]=max(maxi[i],k1);
	}
	while(q--)
	{
		//for each query update the max value in maxi and return the max value 
		cin>>x>>y;
		a[x-1][y-1]=(a[x-1][y-1])?0:1;
		k1=0;
		maxi[x-1]=0;
		for(int j=0;j<m;j++)
		{
			if(a[x-1][j])
				k1++;
			else
			{
				maxi[x-1]=max(maxi[x-1],k1);
				k1=0;
			}
		}
		maxi[x-1]=max(maxi[x-1],k1);
		ans=0;
		for(int i=0;i<n;i++)
			ans=max(ans,maxi[i]);
		cout<<ans<<endl;
	}
	return 0;
}