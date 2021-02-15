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
int count_inversion(vector<int>&v)
{
    int inv=0;
    oset<int>st;
    int n=v.size();
    st.insert(v[0]);
    for(int i=1;i<n;i++)
    {
        st.insert(v[i]);
        int key=st.order_of_key(v[i]+1);
        inv+=st.size()-key;
    }
    return inv;

}
int main()
{
        FIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>v;
        for(int i=1;i<=k && int(v.size())+1<=n;i++)
            v.pb(i);
        if(n>k)
        {
            for(int i=k-1;i>=0 && int(v.size())+1<=n;i--)
            v.pb(i);
        }
       
    int inv=count_inversion(v);
    if(inv==0)
    {
        for(auto it:v)
            cout<<it<<" ";
        cout<<endl;
    }
    else
    {
        //  for(int i=0;i<v.size();i++)
        //     cout<<v[i]<<" ";
        vector<int>ans(n+1);
        int larg=k;
        set<int>seen;
        for(int i=int(v.size()-1);i>=0;i--)
        {
            if(seen.find(v[i])==seen.end())
            {
                seen.insert(v[i]);
                ans[v[i]]=larg;
                larg--;
            }
        }
        for(int i=1;i<=k;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    
   
    }
    
    

return 0;
}