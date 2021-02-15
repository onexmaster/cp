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
    int n,m;
    cin>>n>>m;
    vector<pii>points(n);
    vector<pii>seg(m);
    //red,blue
    vector<pii>seg_c(m,{0,0});
    for(int i=0;i<n;i++)
        cin>>points[i].first,points[i].second=i;
    for(int i=0;i<m;i++)
        cin>>seg[i].first>>seg[i].second;
    sort(points.begin(),points.end());
    sort(seg.begin(),seg.end());
    vector<int>ans(n,0);
    bool bad=false;
    vector<int>d(n,0);
    for(int i=0;i<n;i++)
        d[i]=i%2;
    //1->red
    //0->blue
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(seg[j].first<=points[i].first && seg[j].second>=points[i].first)
            {
               if(d[i])
                seg_c[j].second++;
                else
                {
                    seg_c[j].first++;
                }
                
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        if(abs(seg_c[i].first-seg_c[i].second)>1)
            bad=true;
    }
    if(bad)
    cout<<-1<<endl;
    else
    {
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
            ans[points[i].second]=d[i];
        for(auto it:ans)
            cout<<it<<" ";

    }
    

return 0;
}