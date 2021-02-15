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
int moves[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
char grid[6][7];
bool check(int row, int col, char turn)
{
    //check all the 8 dire
    for(int i=0;i<8;i++)
    {
        int count=0;
        for(int j=1;j<=3;j++)
        {
            int new_x=row+moves[i][0]*j;
            int new_y=col+moves[i][1]*j;
            if(new_x>=0 && new_x<6 && new_y>=0 && new_y<7 && grid[new_x][new_y]==turn)
                count++;
        }
         if(count==3)
                return true;
    }
    return false;
}
//map the last col used for each row
map<int,int>used;
int mark(int col, char turn)
{
    if(used.find(col)==used.end())
    {
        used[col]=5;
        grid[5][col]=turn;
        return 5;
    }
    else
    {
        int last=used[col];
        last--;
        grid[last][col]=turn;
        used[col]=last;
        return last;
    }
    
}
void print()
{
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<7;j++)
            cout<<grid[i][j];
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
        FIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    char turn='R';
    bool win=false;
    for(int i=0;i<42;i++)
    {
        if(i%2==0)
        {
            turn='R';
        }
        else
        {
            turn='Y';
        }
        int col;
        cin>>col;
        col--;
        int row=mark(col,turn);
        //print();
        if(check(row,col,turn))
        {
            win=true;
            if(turn=='R')
                cout<<"RED"<<" "<<i+1;
            else
            {
                cout<<"YELLOW"<<" "<<i+1;
            }
            
        }
        if(win)
            break;
        
    }
    if(!win)
        cout<<"DRAW";

return 0;
}