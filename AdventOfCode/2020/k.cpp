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
int moves[8][2]={{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{1,1},{-1,1},{1,-1}};
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
int row, col;

int main()
{
        FIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    char grid[100][1000];
    string line;
    int i=0;
    while(getline(cin,line))
    {
        col=line.size();
        for(int j=0;j<line.size();j++)
            grid[i][j]=line[j];
        i++;
    }
    row=i;
    vector<vector<char>>grid2(row,vector<char>(col,'.'));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
            grid2[i][j]=grid[i][j];
    }
   vector<vector<char>>gridog(row,vector<char>(col,'.'));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
            gridog[i][j]=grid[i][j];
    }
while(true)
{
    bool change=false;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(grid2[i][j]=='L')
            {
                int curr_x=i;
                int curr_y=j;
                int occ=0;
                //go right
                 curr_x=i;
                curr_y=j+1;
                while(curr_y<col && grid[curr_x][curr_y]=='.')
                    curr_y++;
                if(curr_x>=0 && curr_x<row && curr_y>=0 && curr_y<col && grid2[curr_x][curr_y]=='#')
                        occ++; 
                //go left
                curr_x=i;
                curr_y=j-1;
                while(curr_y>=0 && grid[curr_x][curr_y]=='.')
                    curr_y--;
                if(curr_x>=0 && curr_x<row && curr_y>=0 && curr_y<col && grid2[curr_x][curr_y]=='#')
                        occ++;
                //go up
                curr_x=i-1;
                curr_y=j;
                while(curr_x>=0 && grid[curr_x][curr_y]=='.')
                    curr_x--;
                if(curr_x>=0 && curr_x<row && curr_y>=0 && curr_y<col && grid2[curr_x][curr_y]=='#')
                        occ++;
                //go down
                curr_x=i+1;
                curr_y=j;
                while(curr_x<row && grid[curr_x][curr_y]=='.')
                    curr_x++;
                if(curr_x>=0 && curr_x<row && curr_y>=0 && curr_y<col && grid2[curr_x][curr_y]=='#')
                        occ++;
                //go south east diagonal down
                curr_x=i+1;
                curr_y=j+1;
                while(curr_x<row && curr_y<col && grid[curr_x][curr_y]=='.')
                    curr_x++,curr_y++;
                if(curr_x>=0 && curr_x<row && curr_y>=0 && curr_y<col && grid2[curr_x][curr_y]=='#')
                        occ++;
                //go north east diagonal up
                curr_x=i-1;
                curr_y=j+1;
                while(curr_x>=0 && curr_y<col && grid[curr_x][curr_y]=='.')
                    curr_x--,curr_y++;
                if(curr_x>=0 && curr_x<row && curr_y>=0 && curr_y<col && grid2[curr_x][curr_y]=='#')
                        occ++;
                //go south west
                 curr_x=i+1;
                curr_y=j-1;
                while(curr_x<row && curr_y>=0 && grid[curr_x][curr_y]=='.')
                    curr_x++,curr_y--;
                if(curr_x>=0 && curr_x<row && curr_y>=0 && curr_y<col && grid2[curr_x][curr_y]=='#')
                        occ++;
                //go north west
                 curr_x=i-1;
                curr_y=j-1;
                while(curr_x>=0 && curr_y>=0 && grid[curr_x][curr_y]=='.')
                    curr_x--,curr_y--;
                if(curr_x>=0 && curr_x<row && curr_y>=0 && curr_y<col && grid2[curr_x][curr_y]=='#')
                        occ++;

                if(occ==0)
                {
                    gridog[i][j]='#';
                    change=true;
                }
            }
             else if(grid2[i][j]=='#')
            {
                int curr_x=i;
                int curr_y=j;
                int occ=0;
                //go right
                curr_x=i;
                curr_y=j+1;
                while(curr_y<col && grid[curr_x][curr_y]=='.')
                    curr_y++;
                if(curr_x>=0 && curr_x<row && curr_y>=0 && curr_y<col && grid2[curr_x][curr_y]=='#')
                        occ++; 
                //go left
                curr_x=i;
                curr_y=j-1;
                while(curr_y>=0 && grid[curr_x][curr_y]=='.')
                    curr_y--;
                if(curr_x>=0 && curr_x<row && curr_y>=0 && curr_y<col && grid2[curr_x][curr_y]=='#')
                        occ++;
                //go up
                curr_x=i-1;
                curr_y=j;
                while(curr_x>=0 && grid[curr_x][curr_y]=='.')
                    curr_x--;
                if(curr_x>=0 && curr_x<row && curr_y>=0 && curr_y<col && grid2[curr_x][curr_y]=='#')
                        occ++;
                //go down
                curr_x=i+1;
                curr_y=j;
                while(curr_x<row && grid[curr_x][curr_y]=='.')
                    curr_x++;
                if(curr_x>=0 && curr_x<row && curr_y>=0 && curr_y<col && grid2[curr_x][curr_y]=='#')
                        occ++;
                //go south east diagonal down
                curr_x=i+1;
                curr_y=j+1;
                while(curr_x<row && curr_y<col && grid[curr_x][curr_y]=='.')
                    curr_x++,curr_y++;
                if(curr_x>=0 && curr_x<row && curr_y>=0 && curr_y<col && grid2[curr_x][curr_y]=='#')
                        occ++;
                //go north east diagonal up
                curr_x=i-1;
                curr_y=j+1;
                while(curr_x>=0 && curr_y<col && grid[curr_x][curr_y]=='.')
                    curr_x--,curr_y++;
                if(curr_x>=0 && curr_x<row && curr_y>=0 && curr_y<col && grid2[curr_x][curr_y]=='#')
                        occ++;
                //go south west
                 curr_x=i+1;
                curr_y=j-1;
                while(curr_x<row && curr_y>=0 && grid[curr_x][curr_y]=='.')
                    curr_x++,curr_y--;
                if(curr_x>=0 && curr_x<row && curr_y>=0 && curr_y<col && grid2[curr_x][curr_y]=='#')
                        occ++;
                //go north west
                 curr_x=i-1;
                curr_y=j-1;
                while(curr_x>=0 && curr_y>=0 && grid[curr_x][curr_y]=='.')
                    curr_x--,curr_y--;
                if(curr_x>=0 && curr_x<row && curr_y>=0 && curr_y<col && grid2[curr_x][curr_y]=='#')
                        occ++;
                //cout<<i<<" "<<j<<" "<<occ<<endl;
                 
                if(occ>=5)
                {
                    gridog[i][j]='L';
                    change=true;
                }
            }
        }
    }
    grid2=gridog;
        if(!change)
            break;
    }

    int occ=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
            if(grid2[i][j]=='#')
                occ++;
    }
    cout<<occ;
return 0;
}