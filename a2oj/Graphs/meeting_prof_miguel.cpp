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
const int MAXN=50;
int youth[MAXN][MAXN];
int old[MAXN][MAXN];
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
	while(cin>>t && t!=0)
	{	
		memset(youth,INF,sizeof(youth));
		memset(old,INF,sizeof(old));
		for(int i=0;i<t;i++)
		{
			char grid,type,u,v;
			int c;
			cin>>grid>>type>>u>>v>>c;
			if(grid=='Y')
			{
				if(type=='B')
				{
					youth[u-'A'][v-'A']=c;
					youth[v-'A'][u-'A']=c;
				}
				else
					youth[u-'A'][v-'A']=c;
			}
			else
			{
				if(type=='B')
				{
					old[u-'A'][v-'A']=c;
					old[v-'A'][u-'A']=c;
				}
				else
					old[u-'A'][v-'A']=c;
			}
		}
		for(int i=0;i<27;i++)
		{
			youth[i][i]=0;
			old[i][i]=0;
		}
		//floyd warshall on youth and old
		for(int k=0;k<27;k++)
		{
			for(int i=0;i<27;i++)
			{
				for(int j=0;j<27;j++)
				{
					youth[i][j]=min(youth[i][j],youth[i][k]+youth[k][j]);
					old[i][j]=min(old[i][j],old[i][k]+old[k][j]);
				}
			}
		}
		char src1,src2;
		cin>>src1>>src2;
		int row1=src1-'A';
		int row2=src2-'A';
		int ans=INT_MAX;
		vector<int>temp;
		for(int i=0;i<27;i++)
		{
			if(youth[row1][i]!=INF && old[row2][i]!=INF)
			{
				if(ans>youth[row1][i]+old[row2][i])
				{
					ans=youth[row1][i]+old[row2][i];
					temp.clear();
					temp.pb(i);
				}
				else if(ans==youth[row1][i]+old[row2][i])
					temp.pb(i);

			}
		}
		if(ans==INT_MAX)
			cout<<"You will never meet."<<endl;
		else
		{
			cout<<ans;
			for(int i=0;i<temp.size();i++)
				cout<<" "<<char('A'+temp[i]);
			cout<<endl; 
		}


	}
	
}