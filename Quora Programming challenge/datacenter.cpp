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
    ll n;
    cin>>n;
    int same=0;
    vector<pii>x(n),y(n),v(n);
    for(int i=0;i<n;i++)
    {
        cin>>x[i].first;
        x[i].second=i;
        cin>>y[i].first;
        y[i].second=i;
        v[i].first=x[i].first;
        v[i].second=y[i].first;
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    //take the middle of x and y 
          //run a brute forcer
        ll dist=LLONG_MAX;
        ll middle1=x[n/2].second;
        ll middle2=x[n/2].second;
        if(n%2==0)
            middle2=x[n/2-1].second;
         ll ans=-1;
        //run for middle 1;
    ll curr_x=v[middle1].first;
    ll curr_y=v[middle1].second;
    //cout<<curr_x<<" "<<curr_y<<endl;
    ll curr=0;
    for(int j=0;j<n;j++)
    {
        ll temp=max(abs(v[j].first-curr_x),abs(v[j].second-curr_y));
        //cout<<temp<<endl;
        curr+=temp;
    }
    if(dist>curr)
    {
        ans=middle1;
        dist=min(dist,curr);
    }
    //cout<<dist<<endl;
    //run for middle 2
    curr_x=v[middle2].first;
    curr_y=v[middle2].second;
    curr=0;
    //cout<<curr_x<<" "<<curr_y<<endl;
    for(int j=0;j<n;j++)
    {
        ll temp=max(abs(v[j].first-curr_x),abs(v[j].second-curr_y));
        curr+=temp;
    }
    if(dist>curr)
    {
        ans=middle2;
        dist=min(dist,curr);
    }
    else if(dist==curr)
    {
        ans=min(ans,middle2);
    }
    //for y value
     middle1=y[n/2].second;
    middle2=y[n/2].second;
        if(n%2==0)
            middle2=y[n/2-1].second;
        //run for middle 1;
     curr_x=v[middle1].first;
     curr_y=v[middle1].second;
     curr=0;
    for(int j=0;j<n;j++)
    {
        ll temp=max(abs(v[j].first-curr_x),abs(v[j].second-curr_y));
        //cout<<temp<<endl;
        curr+=temp;
    }
    if(dist>curr)
    {
        ans=middle1;
        dist=min(dist,curr);
    }
    //run for middle 2
    curr_x=v[middle2].first;
    curr_y=v[middle2].second;
    curr=0;
    for(int j=0;j<n;j++)
    {
        ll temp=max(abs(v[j].first-curr_x),abs(v[j].second-curr_y));
        curr+=temp;
    }
    if(dist>curr)
    {
        ans=middle2;
        dist=min(dist,curr);
    }
    else if(dist==curr)
    {
        ans=min(ans,middle2);
    }

    cout<<ans+1;
return 0;
}