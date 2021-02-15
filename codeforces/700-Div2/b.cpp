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
        ll A,B,n;
        cin>>A>>B>>n;
        vector<ll>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        vector<ll>health(n);
        for(int i=0;i<n;i++)
            cin>>health[i];
        vector<pair<ll,ll>>temp(n);
        for(int i=0;i<n;i++)
            temp[i].first=a[i],temp[i].second=health[i];
        bool flag=false;
        sort(temp.begin(),temp.end());
        for(int i=0;i<n;i++)
        {
            ll attacks_give=(temp[i].second+A-1)/A;
            ll attacks_take=(B+temp[i].first-1)/temp[i].first;
            ll tmp=min(attacks_give,attacks_take);
            ll damage_give=tmp*A;
            ll damage_take=tmp*temp[i].first;
            ll val1 = temp[i].second - damage_give; //remianig of mons
            ll val2 = B - damage_take; //remainig of hero
       if(val2<=0)
        {
            if(val1>0)
            {
                flag=1;
                break;
            }
        }
        
     B = B-damage_take;
     
   }
   if(!flag)
    cout<<"YES"<<endl;
   else
    cout<<"NO"<<endl;
            
    }

return 0;
}