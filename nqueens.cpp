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
int n;
vector<int>ans;
int grid[17][17];
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
	//check this cols on the left side
		for(i=0;i<curr_y;i++)
			if(grid[curr_x][i])
				return false;
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
bool solve(int queens)
{
	//ans found
	//cout<<queens<<endl;
	if(queens>=n)
		return true;
	//place the first queen
	for(int j=0;j<n;j++)
	{
		//before choosing make sure we can plcae the queen here
		if(ok(j,queens))
		{
			grid[j][queens]=1;
			ans.pb(j);
			//explore
			if(solve(queens+1))
				return true;
			//backtrack
			ans.pop_back();
			grid[j][queens]=0;	
			
		}
		
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	// #ifndef ONLINE_JUDGE
	// freopen("inputf.in","r",stdin);
	// freopen("outputf.in","w",stdout);
	// #endif

	int t;
	cin>>t;
	while(t--)
	{
		for(int i=0;i<=17;i++)
			for(int j=0;j<=17;j++)
				grid[i][j]=0;
		cin>>n;
		ans.clear();
		solve(0);
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]+1<<" ";
		cout<<endl;
		//printSolution();

	}

}