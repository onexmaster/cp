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
const int MAXN=105;
int grid[MAXN][MAXN];
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
	int x=0;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		memset(grid,INF,sizeof(grid));
		for(int i=1;i<=n;i++)
			grid[i][i]=0;
		while(m--)
		{
			int u,v,c;
			cin>>u>>v>>c;
			grid[u][v]=grid[v][u]=min(grid[u][v],c);
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					grid[i][j]=min(grid[i][j],grid[i][k]+grid[k][j]);
				}
			}

		 }
		// for(int i=1;i<=n;i++)
		// {
		// 	for(int j=1;j<=n;j++)
		// 		cout<<grid[i][j]<<" ";
		// 	cout<<endl;
		// }
		 int res = INF;
		 int i,j;
        for( i = 6; i <= n; i++) {
            for( j = 1; j <= 5; j++)
                if(grid[i][j] != grid[i][1])
                    break;
            if(j == 6) {
                int tmp = 0;
                for( j = 1; j <= n; j++)
                    tmp = max(tmp, grid[i][j]);
                res = min(tmp, res);
            }
        }
        printf("Map %d: ", ++x);
        if(res == INF)   puts("-1");
        else            printf("%d\n", res);
    }

	
}