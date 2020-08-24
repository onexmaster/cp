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
const int MAXN=110;
int t,p,target,flag;
int nos[MAXN],path[MAXN],ans[MAXN];
int vis[MAXN][100000];
int judge(int m, int pos)
{
	if(m>=-32000 && m<=32000 && !vis[pos][m])
		return 1;
	return 0;
}
void dfs(int sum, int pos)
{
	//if traversed the whole array
	if(pos>=p)
	{
		//if ans found
		if(sum==target && !flag)
		{

			memcpy(ans,path,sizeof(ans));
			flag=1;
		}
		return;
	}
	//do the 4 operations
	if(!flag)
	{
		//ADD operation
		if(judge(sum+nos[pos],pos))
		{
			vis[pos][sum+nos[pos]]=1;
			path[pos-1]=1;
			dfs(sum+nos[pos],pos+1);
		}
	}
	//MINUS operaton
	if(!flag)
	{
		//ADD operation
		if(judge(sum-nos[pos],pos))
		{
			vis[pos][sum-nos[pos]]=1;
			path[pos-1]=2;
			dfs(sum-nos[pos],pos+1);
		}
	}
	if(!flag)
	{
		//mul operation
		if(judge(sum*nos[pos],pos))
		{
			vis[pos][sum*nos[pos]]=1;
			path[pos-1]=3;
			dfs(sum*nos[pos],pos+1);
		}
	}
	if(!flag && sum%nos[pos]==0)
	{
		//div operation
		if(judge(sum/nos[pos],pos))
		{
			vis[pos][sum/nos[pos]]=1;
			path[pos-1]=4;
			dfs(sum/nos[pos],pos+1);
		}
	}

}
void output()
{
	for(int i=0;i<p;i++)
	{
		cout<<nos[i];
		if(ans[i]==1)
			cout<<"+";
		if(ans[i]==2)
			cout<<"-";
		if(ans[i]==3)
			cout<<"*";
		if(ans[i]==4)
			cout<<"/";
	}
	cout<<"="<<target<<endl;
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
	while(t--)
	{
		cin>>p;
		for(int i=0;i<p;i++)
			cin>>nos[i];
		cin>>target;

		memset(path, 0, sizeof (path));
        memset(vis, 0, sizeof(vis));
        flag = 0 ; vis[0][nos[0]] = 1;
		dfs(nos[0],1);
		if(flag)
			output();
		else
			cout<<"NO EXPRESSION"<<endl;
	}
	
}