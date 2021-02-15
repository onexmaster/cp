// Created by Tanuj Jain
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
# define M_PI           3.14159265358979323846  /* pi */
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
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
    //inserctions of spruce is not allowed 
        FIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        int row,col;
        cin>>row>>col;
        vector<vector<char>>grid(row,vector<char>(col,'.'));
        int i=0;
        int total=0;
        for(int i=0;i<row;i++)
        {
            string st;
            cin>>st;
            for(int j=0;j<st.size();j++)
            {
                grid[i][j]=st[j];
                if(grid[i][j]=='*')
                    total++;
            }
                
        }
        //start with size 2 and go on increasing 
        vector<vector<char>>grid2=grid;
        //count prefix sums of stars in each row
        vector<vector<int>>prefix(row,vector<int>(col+1,0));
        for(int i=0;i<row;i++)
        {
            if(grid[i][0]=='*')
                prefix[i][1]=1;
        }
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                if(grid[i][j]=='*')
                    prefix[i][j+1]=prefix[i][j]+1;
                else
                {
                    prefix[i][j+1]=prefix[i][j];
                }
                
            }
        }
        // for(int i=0;i<prefix.size();i++)
        // {
        //     for(int j=0;j<prefix[0].size();j++)
        //         cout<<prefix[i][j]<<" ";
        //     cout<<endl;
        // }
        //now check only the corner points for each spruce size
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    if(grid[i][j]=='*')
                    {
                        //for the below rows check the stars we have at boundary;
                        int req=3;
                        for(int height=1;height<=max(row,col);height++)
                        {
                            int curr_row=i+height;
                            //cout<<i<<" "<<height<<endl;
                            if(curr_row>=row || j+height+1>=col+1 || j-height<0)
                                break;
                            //for the current rows check stars
                            
                            if(prefix[curr_row][j+height+1]-prefix[curr_row][j-height]==req)
                            {
                                //cout<<i<<" "<<curr_row<<" "<<prefix[curr_row][j+height+1]-prefix[curr_row][j-height]<<endl;
                                 total++;
                            }
                            else
                            {
                                break;
                            }  
                            req+=2; 
                        }
                        
                    }
                }
            }
            cout<<total<<endl;
        }

return 0;
}