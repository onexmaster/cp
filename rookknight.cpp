// Created by Tanuj Jain
//DOES NOT WORK
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
int rookknight_moves[4][2]={{-2,-1},{2,-1},{1,-2},{-1,-2}};
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
int n;
vector<vector<int>>total;
vector<int>ans;
int grid[1005][1005];
void printSolution() 
{ 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) 
            printf(" %d ", grid[i][j]); 
        printf("\n"); 
    } 
} 

bool ok(int curr_x, int curr_y)
{
	//cout<<curr_x<<" "<<curr_y<<endl;
	//this function checks wether we can place the queen at curr pos or not
	int i,j;
	//check this knight moves on the left side
		for(int k=0;k<8;k++)
		{
			int new_x=curr_x+rookknight_moves[i][0];
			int new_y=curr_y+rookknight_moves[i][1];
			if(new_x>=0 && new_y>=0 && grid[i][j])
				return false;
		}
	//no need to check this row, since each row has only 1 queen

	//check the upper dialgonal om left side
		 for (i = curr_x, j = curr_y; i >= 0 && j >= 0; i--, j--) 
        	if (grid[i][j]) 
            	return false;
      //check the lower diagonal on left side
            for (i = curr_x, j = curr_y; j >= 0 && i < n; i++, j--) 
        		if (grid[i][j]) 
            		return false;
        return true;

}
bool solve(int rookknight)
{
	//ans found
	//cout<<queens<<endl;
	if(rookknight>=n)
		return true;
	//place the first queen
	for(int j=0;j<n;j++)
	{
		//before choosing make sure we can plcae the queen here
		if(ok(j,rookknight))
		{
			grid[j][rookknight]=1;
			ans.pb(j);
			//explore
			if(solve(rookknight+1))
			{
				total.pb(ans);
				return true;
			}
			//backtrack
			ans.pop_back();
			grid[j][rookknight]=0;	
			
		}
		
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t;
	cin>>t;
	while(t--)
	{
		for(int i=0;i<=1005;i++)
			for(int j=0;j<=1005;j++)
				grid[i][j]=0;
		cin>>n;
		ans.clear();
		total.clear();
		solve(0);
		cout<<total.size();
		cout<<endl;
		//printSolution();

	}
	return 0;

}