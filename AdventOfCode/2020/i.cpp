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
int start;
ll look;
bool poss(int sz, vector<ll>&temp)
{
    //track the starting of every window
    ll sum=0;
    for(int i=0;i<sz;i++)
        sum+=temp[i];
    int l=0;
    int h=sz;
    while(h<temp.size())
    {
        if(sum==look)
        {
            start=l;
            return true;
        }
            
        sum+=temp[h];
        sum-=temp[l];
        l++;
        h++;
    }
    if(sum==look)
    {
        start=l;
        return true;

    }
        
    else 
        return false;
}
void solve2(vector<ll>&temp)
{
    unordered_map<ll,int>occ;
    ll curr_sum=0;
    for(int i=0;i<temp.size();i++)
    {
        curr_sum+=temp[i];
        if(curr_sum==look)
        {
            cout<<0<<" "<<i<<endl;
            return;
        }
            
        if(occ.find(curr_sum-look)!=occ.end())
        {
            cout<<occ[curr_sum-look]+1<<" to "<<i<<endl;
            return;
        }
        occ[curr_sum]=i;
    }
}
int main()
{
        FIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    vector<ll>temp;
    ll x;
    while(cin>>x)
        temp.pb(x);
    vector<int>window;
    multiset<ll>st;
    for(int i=0;i<25;i++)
    {
        st.insert(temp[i]);
    }
    int l=0;
    int h=25;
    while(h<temp.size())
    {
        bool ok=false;
        for(auto it:st)
        {
            if(st.find(temp[h]-it)!=st.end())
            {
                ok=true;
                //remove only one occ of the current number not all
                //erase removes all the occ of a current number in the multimap
                st.erase(st.find(temp[l]));
                st.insert(temp[h]);
                l++;
                h++;
                break;
            }
        }
        if(!ok)
            {
                look=temp[h];
                break;
            }
    }
    //try to brute force the size of the contigious set
    // int found=0;
    // for(int i=3;i<temp.size()-1;i++)
    // {
    //     if(poss(i,temp))
    //     {
    //         found=i;
    //         cout<<start<<" "<<i<<endl;
    //         break;
    //     }
    // }
    // ll mn=*min_element(temp.begin()+start,temp.begin()+start+found);
    // ll mx=*max_element(temp.begin()+start,temp.begin()+start+found);
    // cout<<mn+mx<<endl;
    solve2(temp);
return 0;
}