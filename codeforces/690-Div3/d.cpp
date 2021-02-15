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
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        // queue<vector<int>>q;
        // map<vector<int>,int>dist;
        // q.push(v);
        // dist[v]=0;
        // bool found=false;
        // while(!q.empty() && !found)
        // {
        //     vector<int>curr=q.front();
        //     q.pop();
        //     for(auto it:curr)
        //         cout<<it<<" ";
        //     cout<<endl;
        //     unordered_set<int>temp(curr.begin(),curr.end());
        //         if(temp.size()==1)
        //         {
        //             found=true;
        //             cout<<dist[curr]<<endl;
        //             break;
        //         }
                    
        //     for(int i=0;i<curr.size()-1;i++)
        //     {
        //         vector<int>new_curr=curr;
        //         new_curr[i+1]+=new_curr[i];
        //         new_curr.erase(new_curr.begin()+i);
        //         if(dist.count(new_curr)==0){
        //         q.push(new_curr);
        //         dist[new_curr]=dist[curr]+1;
        //         }
        //     }


        // }
        // if(!found)
        //     cout<<n-1<<endl;
        set<int>temp(v.begin(),v.end());
        if(temp.size()==1)
        {
            cout<<0<<endl;
            continue;
        }
            
        vector<int>prefix(n),suffix(n);
        prefix[0]=v[0];
        for(int i=1;i<n;i++)
            prefix[i]=prefix[i-1]+v[i];
        suffix[n-1]=v[n-1];
        for(int i=n-2;i>=0;i--)
            suffix[i]=suffix[i+1]+v[i];
        map<int,int>occ_pre,occ_suff;
        for(int i=0;i<n;i++)
        {
            occ_pre[prefix[i]]=i;
            occ_suff[suffix[i]]=i;
        }
        int ans=INT_MAX;
        for(auto it:occ_pre)
        {
            if(occ_suff.find(it.first)==occ_suff.end())
                continue;
            else
            {
                if(occ_suff[it.first]==n-1 && it.second==0 || it.second>occ_suff[it.first] || occ_suff[it.first]==0 && it.second==n-1 )
                    continue;
                else 
                {
                    //cout<<it.first<<" "<<it.second<<" "<<occ_suff[it.first]<<endl;
                    ans=min(ans, it.second+(n-occ_suff[it.first]-1));
                }
                    
            }
            
        }
        if(ans==INT_MAX)
            cout<<n-1<<endl;
        else
        {
            cout<<ans<<endl;
        }
        
        
    }

return 0;
}