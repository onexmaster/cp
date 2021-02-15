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
    int n,m,s,e,v;
    cin>>n>>m>>s>>e>>v;
    vector<int>stairs(s),ele(e);
    for(int i=0;i<s;i++)
        cin>>stairs[i];
    for(int i=0;i<e;i++)
        cin>>ele[i];
    int q;
    cin>>q;
    while(q--)
    {
        int sx,sy,ex,ey;
        cin>>sx>>sy>>ex>>ey;
        int ans=INT_MAX;
        if(sx==ex)
        {
            ans=min(ans,abs(sy-ey));
        }
        //use the stairs
        //walk to the nearest stair walk to the floor of dest and walk again to the room
        if(s>0)
        {
            int dist=abs(sx-ex);//the distance between floors
            //find the nearest stair
            int index=lower_bound(stairs.begin(),stairs.end(),sy)-stairs.begin();
            //make sure the index are in the bounds of the array;
            index=max(0,index);
            index=min(index,s-1);
            int index1=index;
            int dist1=dist+abs(stairs[index1]-sy)+abs(stairs[index1]-ey);
            ans=min(ans,dist1);
            if(index>0)
            {
                int index2=index-1;
                int dist2=dist+abs(stairs[index2]-sy)+abs(stairs[index2]-ey);
                ans=min(ans,dist2);
            }
        }
        if(e>0)
        {
            int dist=(abs(sx-ex)+v-1)/v;//the distance between floors
            //find the nearest elevator
            int index=lower_bound(ele.begin(),ele.end(),sy)-ele.begin();
            //make sure the index are in the bounds of the array;
            index=max(0,index);
            index=min(index,e-1);
            int index1=index;
            int dist1=dist+abs(ele[index1]-sy)+abs(ele[index1]-ey);
            ans=min(ans,dist1);
            if(index>0)
            {
                int index2=index-1;
                int dist2=dist+abs(ele[index2]-sy)+abs(ele[index2]-ey);
                ans=min(ans,dist2);
            }
           
        }
         cout<<ans<<endl;
        
    }

return 0;
}