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
vector<pii>cond;
vector<pii>mapping;
int balls[105];
int ans;
int k;
void solve(int curr)
{
    // for(int i=0;i<10;i++)
    //     cout<<balls[i]<<" ";
    if(curr==k)
    {
        //reached end of line
        //check for answer
        int ans_temp=0;
        for(int i=0;i<cond.size();i++)
        {
            if(balls[cond[i].first]>0 && balls[cond[i].second]>0)
                ans_temp++;
        }
        ans=max(ans,ans_temp);
    }
    //choose the first ball
    if(curr<k){
    balls[mapping[curr].first]++;
    solve(curr+1);
    balls[mapping[curr].first]--;
    balls[mapping[curr].second]++;
    solve(curr+1);
    balls[mapping[curr].second]--;
    }
    return;
}
int main()
{
        FIO;
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        pii temp;
        cin>>temp.first>>temp.second;
        temp.first--;
        temp.second--;
        cond.pb(temp);
    }
    cin>>k;
    for(int i=0;i<k;i++)
    {
        pii temp;
        cin>>temp.first>>temp.second;
        temp.first--;
        temp.second--;
        mapping.pb(temp);
    }
    ans=0;
    solve(0);
    cout<<ans<<endl;


        

return 0;
}