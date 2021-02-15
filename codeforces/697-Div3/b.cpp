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
vector<bool>v(1e7+5,false);
void solve()
{
    v[2020]=true;
    v[2021]=true;
    for(int i=2022;i<=v.size();i++)
    {
        if(v[i-2021] || v[i-2020])
            v[i]=true;     
    }
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
    solve();
    while(t--)
    {
        int n;
        cin>>n;
        if(v[n])
            cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
        }
        
    }


return 0;
}