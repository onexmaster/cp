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
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	int row,col,k;
	cin>>row>>col>>k;
	//map for start pos
	map<int,pair<int,int>>s;
	//map for end pos
	map<int,pair<int,int>>e;
	for(int i=0;i<k;i++)
	{
		int sx,sy;
		cin>>sx>>sy;
		s[i]={sx,sy};
	}
	for(int i=0;i<k;i++)
	{
		int ex,ey;
		cin>>ex>>ey;
		e[i]={ex,ey};
	}
	//move all the chips to 1,1 and then move all the chips over the whole board all together
	//to move all the chips to 1,1 we need col-1 'L' moves and row-1 'U' moves
	//then iterate the whole grid in snake fashion
	string ans;
	for(int i=0;i<col-1;i++)
		ans+='L';
	for(int i=0;i<row-1;i++)
		ans+='U';
	//now traverse in snake fashion
	for(int i=0;i<row;i++)
	{
		//even rows are traversed rom right to left
		if(i%2==0)
		{
			ans.append(col-1,'R');
			if(i!=row-1)
				ans+='D';
		}
		//odd rows are traversed from left to right
		else
		{
			ans.append(col-1,'L');
			if(i!=row-1)
			ans+='D';
		}
	}
	cout<<int(ans.size())<<endl;
	cout<<ans;
	return 0;
}