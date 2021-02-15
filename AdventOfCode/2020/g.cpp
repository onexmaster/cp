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
map<string,set<pair<string,int>>>mapping;
set<string>vis;
bool found;
map<string,int>dp;
ll ans;
int dfs(string curr)
{
    if(dp.find(curr)!=dp.end())
        return dp[curr];
    int sz=1;
    for(auto edges:mapping[curr])
    {
        sz+=dfs(edges.first)*edges.second;
    }    
    dp[curr]=sz;
    return dp[curr];

}
int main()
{
        FIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ll gold=0;
    string line;
  
    while(getline(cin,line))
    {
        stringstream ss(line);
        string word;
        int i=0;
        vector<string>temp;
        bool cannot=true;
        while(ss>>word)
        {
            if(word=="no")
            {
                cannot=false;
           
            }
             temp.pb(word);
            
        }
        if(!cannot)
            continue;
        else
        {
            string temp1=temp[0]+temp[1];
            for(int i=0;i<temp.size();i++)
            {
                string curr=temp[i];
                if(curr[curr.size()-1]==',' || curr[curr.size()-1]=='.')
                {
                    string bag=temp[i-2]+temp[i-1];
                    int count=stoi(temp[i-3]);
                    mapping[temp1].insert({bag,count});
                }
            }
        }
        
        



    }
    // for(auto it:mapping)
    // {
    //     cout<<it.first<<" ";
    //     for(auto st:it.second)
    //         cout<<st.first<<" "<<st.second<<" ";
    //     cout<<endl;
    // }
    cout<<dfs("shinygold")-1;
return 0;
}
