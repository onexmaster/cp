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
int moves[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int main()
{
        FIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,k;
        cin>>a>>b>>k;
        vector<int>boys(k),girls(k);
        for(int i=0;i<k;i++)
            cin>>boys[i];
        for(int i=0;i<k;i++)
            cin>>girls[i];
        vector<pair<int,int>>temp(k);
        for(int i=0;i<k;i++)
            temp[i]={boys[i],girls[i]};
        map<int,unordered_set<int>>mp_b,mp_g;
        for(int i=0;i<k;i++)
            mp_b[temp[i].first].insert(temp[i].second);
        for(int i=0;i<k;i++)
            mp_g[temp[i].second].insert(temp[i].first);
        
    }
return 0;
}