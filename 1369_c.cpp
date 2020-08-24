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
const int INF = 0x3f3f3f3f;
int knight_moves[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}};
int moves[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	int n;
	cin>>n;
	vector<int>a(n+1),b(n+1);
	int pos[n+1];
	map<int,int>offset;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pos[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		int curr=pos[b[i]]-i;

		if(curr<0)
			curr+=n;
		//cout<<curr<<endl;
		offset[curr]++;
	}	
	int ans = 0;
	for(auto &it:offset)
		ans = max(ans, it.second);
	cout << ans;
	return 0;
	
}