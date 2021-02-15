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
double find(double x1,double y1, double x2, double y2)
{
    return (sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
}
int main()
{
        FIO;
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    pair<double,double>start,end;
    cin>>start.first>>start.second>>end.first>>end.second;
    int n;
    cin>>n;
    vector<pair<double,double>>v(n+2);
    v[0]=start;
    for(int i=1;i<=n;i++)
        cin>>v[i].first>>v[i].second;
    v[n+1]=end;
    double max_time=find(v[0].first,v[0].second,v[n+1].first,v[n+1].second);
    double inf=max_time+50.0;
    double grid[n+2][n+2];
    
    for(int i=0;i<n+2;i++)
    {
        for(int j=0;j<n+2;j++)
        {
            if(i==j)
                grid[i][j]=0.0;
            else
            {
                grid[i][j]=inf;
            }
            
        }
    }
    //fill the time taken to run everywhere
        for(int j=1;j<n+2;j++)
        {
            double dist=find(v[0].first,v[0].second,v[j].first,v[j].second);
            grid[0][j]=dist/5.0;
        }
    //fill the value to canonball from one canonball to another or to run to another canonball
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+2;j++)
        {
            double dist=find(v[i].first,v[i].second,v[j].first,v[j].second);
            grid[i][j]=min(2+abs((dist-50.0))/5.0,dist/5.0);
        }
    }
    //floyd warshall
    for(int k=0;k<n+2;k++)
    {
        for(int i=0;i<n+2;i++)
        {
            for(int j=0;j<n+2;j++)
            {
                grid[i][j]=min(grid[i][j],grid[i][k]+grid[k][j]);
            }
        }
    }
    cout<<fixed<<setprecision(6)<<grid[0][n+1];
return 0;
}