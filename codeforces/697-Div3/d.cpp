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
        int n,m;
        cin>>n>>m;
       vector<ll>mem(n),conv(n);
       ll sum=0;
       for(int i=0;i<n;i++)
       cin>>mem[i],sum+=mem[i];
       for(int i=0;i<n;i++)
        cin>>conv[i];
    if(sum<m)
        cout<<-1<<endl;
    else
    {
        vector<ll>imp,non;
        for(int i=0;i<n;i++)
        {
            if(conv[i]==2)
                imp.pb(mem[i]);
            else
            {
                non.pb(mem[i]);
            }
            
        }
        sort(imp.rbegin(),imp.rend());
        sort(non.rbegin(),non.rend());
        //prefix sums for both the imp and non and find the answer
        int imp_sz=imp.size();
        int non_sz=non.size();
        if(imp_sz==0)
           imp.pb(0),imp_sz=1;
        if(non_sz==0)
            non.pb(0),non_sz=1;
        vector<ll>prefix_imp(imp_sz),prefix_non(non_sz);
        prefix_imp[0]=imp[0];
        for(int i=1;i<imp_sz;i++)
            prefix_imp[i]=prefix_imp[i-1]+imp[i];
        prefix_non[0]=non[0];
        for(int i=1;i<non_sz;i++)
            prefix_non[i]=prefix_non[i-1]+non[i];

         //debug
    // for(int i=0;i<imp_sz;i++)
    //     cout<<prefix_imp[i]<<" ";
    // cout<<endl;
    // cout<<"NON"<<endl;
    // for(int i=0;i<non_sz;i++)
    //     cout<<prefix_non[i]<<" ";
    // cout<<endl;

        int ans=INT_MAX;
        int cost=0;
        for(int i=-1;i<imp_sz;i++)
        {
            //using only the non items
            int have;
            int need;
            if(i==-1)
            {
                have=0;
                cost=0;
            }
            else
            {
                have=prefix_imp[i];
                cost+=2;
            }
            need=m-have;
            //cout<<i<<" "<<need<<endl;
            int index=0;
            if(need>0)
            {
                index=lower_bound(prefix_non.begin(),prefix_non.end(),need)-prefix_non.begin();
                index=min(index,non_sz-1);
                index=max(0,index);
                need-=prefix_non[index];
                //cout<<i<<" "<<index<<endl;
                index++;
                if(need<=0)
                {
                    int temp_cost=cost+index;
                    //cout<<i<<" "<<need<<" "<<index<<" "<<temp_cost<<endl;
                    ans=min(temp_cost,ans);
                }
            }
            else if(prefix_imp[i]>m)
            {
                ans=min(ans,cost);
            }
                
            }
     // cout<<ans<<endl;
         cost=0;
        for(int i=-1;i<non_sz;i++)
        {
            //using only the non items
            int have;
            int need;
            if(i==-1)
            {
                have=0;
                cost=0;
            }
            else
            {
                have=prefix_non[i];
                cost+=1;
            }
            need=m-have;
            int index=0;
            //cout<<i<<" "<<need<<endl;
            if(need>0)
            {
                index=lower_bound(prefix_imp.begin(),prefix_imp.end(),need)-prefix_imp.begin();
                 index=min(index,imp_sz-1);
                 index=max(0,index);
                need-=prefix_imp[index];
                index++;
                if(need<=0)
                {
                    int temp_cost=cost+(2*index);
                    //cout<<i<<" "<<need<<" "<<index<<" "<<temp_cost<<endl;
                    ans=min(temp_cost,ans);
                }
            }
            else if(prefix_non[i]>m)
            {
                ans=min(ans,cost);
            }
        }
          cout<<ans<<endl;
    }
    }

return 0;
}