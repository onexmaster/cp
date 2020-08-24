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
const int MAXN=5001;
int l[MAXN],b[MAXN],s[MAXN],cnt[MAXN],path[MAXN];
bool cmp(const &x, const &y)
{
	if(l[x]==l[y])
		return b[x]<b[y];
	return l[x]<l[y];
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

	int n,L,B;
	cin>>n>>L>>B;
	for(int i=0;i<n;i++)
	{
		cnt[i]=1;path[i]=-1;s[i]=i;
		cin>>l[i]>>b[i];
	}
	sort(s,s+n,cmp);
	//sorted in decreasing order
	//try to extend the chain
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if( l[s[j]]>L && b[s[j]]>B && l[s[i]]>l[s[j]] && b[s[i]]>b[s[j]])
			{
				if(cnt[j]+1>cnt[i])
				{
					cnt[i]=cnt[j]+1;
					path[i]=j;
				}
			}
		}
	}
	int best=0;
	int idx=-1;
	for(int i=0;i<n;i++)
	{
		if(l[s[i]]>L && b[s[i]]>B)
		{
			if(cnt[i]>best)
			{
				best=cnt[i];
				idx=i;
			}
		}
	}
	cout<<best<<endl;
	//build path
	vector<int>temp;
	if(idx!=-1)
	{
		while(idx!=-1)
		{
			temp.pb(s[idx]+1);
			idx=path[idx];
		}
	}
	reverse(temp.begin(),temp.end());
	for(int i=0;i<temp.size();i++)
		cout<<temp[i]<<" ";
}