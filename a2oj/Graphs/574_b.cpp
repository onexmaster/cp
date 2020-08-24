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
const int inf = 100000005;
const int nax = 5005;
int degree[nax];
bool t[nax][nax];
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

 //Create Adajcency MAtrix and iterate over it
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		t[a][b] = t[b][a] = true;
		degree[a]++;
		degree[b]++;
	}
	int result = inf;
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j) {
			// we are O(n^2) times here
			//check 1 and 2 are connected or not, if yes find the 3 vertex
			if(t[i][j]) {
				// we are O(m) times here
				for(int k = j + 1; k <= n; ++k) {
					// O(m * n) times here
					//check if 1 is connected to 3 and is 2 connected to 3
					if(t[i][k] && t[j][k])
						result = min(result, degree[i]+degree[j]+degree[k]);
				}
			}
		}
	if(result == inf) puts("-1");
	else printf("%d\n", result - 6);
	return 0;
}
	