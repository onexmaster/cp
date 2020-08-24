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
const int nax = 1e5 + 5;
vector<int> w[nax];
int col[nax];
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
	scanf("%d", &n);
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		w[a].push_back(b);
		w[b].push_back(a);
	}
	for(int i = 1; i <=n ; ++i)
		scanf("%d", &col[i]);
	
	//find the "BAD"Edges for the total tree
	//"BAD Edges" are those edges than different color on both ends
	int bad = 0;
	for(int i = 1; i <= n; ++i)
		for(int b : w[i])
			if(i < b && col[i] != col[b])
				++bad;
	
	for(int i = 1; i <= n; ++i) {
		//NOw for each vertex find the "BAD Edges" and if these match with the original
		//Bad edges, it means this is the vertex which needs to be root coz all the subtree 
		//have a same color

		//Why is this true?- This is true because since all the edges in the original loop
		//are added 
		//So if we come across a vertex which violates the same amout edges, it means this vertex
		//same as the one which gave us the initial bad verex count and hence this is the answer
		int tmp = 0;
		for(int b : w[i])
			if(col[i] != col[b])
				++tmp;
		if(tmp == bad) {
			puts("YES");
			printf("%d\n", i);
			return 0;
		}
	}
	puts("NO");
}
	