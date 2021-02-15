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
    int n,m;
    cin>>n>>m;
    map<int,vector<int>>occ;
    for(int i=0;i<m;i++)
    {
        int from, to;
        cin>>from>>to;
        occ[from].pb(to);
    }
    //this vector stores max value at each station
    vector<int>mx(n+1,0);
    //the farther the candy, the less time it should take to send it 
    // for(auto it:occ)
    // {
    //     cout<<it.first<<" ";
    //     for(auto nos:it.second)
    //         cout<<nos<<" ";
    //     cout<<endl;
    // }
    //cout<<"HERE"<<endl;
    for(auto it:occ)
    {
        vector<int>temp;
        vector<int>temp2=it.second;
        for(auto candy:temp2)
        {
            //if the candy needs to be delivered to some station behind me
            //i need to go in a circle to that station
            if(candy<it.first)
            {
                temp.pb(n-it.first+candy);
            }
            else
            {
                temp.pb(candy-it.first);
            }
        }
            //the candy having largest distance should be picked first
            sort(temp.rbegin(),temp.rend());
            for(int i=1;i<temp.size();i++)
            {
                temp[i]=temp[i]+(i*n);
            }
        // cout<<it.first<<" ";
        //     for(auto nos:temp)
        //     cout<<nos<<" ";
        //     cout<<endl;

        int mx_ele=*max_element(temp.begin(),temp.end());
        mx[it.first]=mx_ele;
    }
    
    vector<int>res(n+1,0);
    for(int i=1;i<=n;i++)
    {
        //start at the i'th station and find the remainin value
        int ans=mx[i];
        int j=i;
        int dist=0;
        int candies=m;
        while(candies>0)
        {
           
            ans=max(ans,mx[j]+dist);
            candies-=(occ[j].size());
            j++;
            dist++;
             if(j>n)
                j=1;
        }
        res[i]=ans;
    }
    for(int i=1;i<=n;i++)
        cout<<res[i]<<" ";
return 0;
}