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
    int n,d;
    cin>>n>>d;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++)   
        cin>>a[i];
    for(int i=0;i<n;i++)  
        cin>>b[i];
    //best possible ranks is if i get the max points, the current first gets the least and so on
    sort(b.begin(),b.end());
    a[d-1]+=b.back();
    int i=0,j=0;
    while(i<n && j<n)
    {
        if(i==d-1)
            i++;
        else
        {
            a[i]+=b[j];
            i++;
            j++;
        }
        
    }
    int look=a[d-1];
    sort(a.rbegin(),a.rend());
    for(auto it:a)
    cout<<it<<" ";
    int rank=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==look)
            break;
        else
        {
            rank++;
        }
        
    }
    cout<<rank+1;
    


return 0;
}