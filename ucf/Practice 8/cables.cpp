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
unordered_map<int,vector<pair<int,double>>>ada;
int n;
double find(double x1,double y1, double x2, double y2)
{
    return (sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
}
double mst()
{
    priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>>pq;
    double cost=0.00;
    pq.push({0.00,0});
    bool vis[n];
    memset(vis,false,sizeof(vis));
    int stop=0;
    while(!pq.empty())
    {
        double curr_cost=pq.top().first;
        int curr=pq.top().second;
        pq.pop();
        //early breaking
        if(stop==n)
            break;
        //check for cycle
        if(vis[curr])
            continue;
        cost+=curr_cost;
        stop++;
        vis[curr]=true;
        for(auto edges:ada[curr])
        {
            if(!vis[edges.first]);
            {
                pq.push({edges.second,edges.first});
            }
        }
    }
    return cost;
}
int main()
{
        FIO;
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    while(cin>>n)
    {
        if(n==0)
        break;
        ada.clear();
        //cout<<n<<endl;
        vector<pair<double,double>>pt(n);
        for(int i=0;i<n;i++)
            cin>>pt[i].first>>pt[i].second;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==i)
                    continue;
                double cost=find(pt[i].first,pt[i].second,pt[j].first,pt[j].second);
                ada[i].pb({j,cost});
            }
        }
        // for(auto it:ada)
        // {
        //     cout<<it.first<<" ";
        //     for(auto nos:it.second)
        //     {
        //         cout<<nos.first<<" "<<nos.second<<" ";
        //         cout<<endl;
        //     }
        // }
        cout<<fixed<<setprecision(2)<<mst()<<endl;
    }

return 0;
}