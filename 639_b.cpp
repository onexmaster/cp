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
    int n,d,h;
    cin>>n>>d>>h;
    if(d>2*h || (h>n-1) || (h==1 && d==1 && n>h+1))
    {
        cout<<-1;
    }
    else
    {
        int i=1;
        int curr_h=0;
        //build the left half
        while(h)
        {
            cout<<i<<" "<<i+1<<endl;
            i++;
            d--;
            h--;
        }
        //build the right half to match the diameter
        if(d==0 && h==0)
        {
            //if the height and depth is same join all the remaning at 2 vertex
            int last_used=i+1;
            for(int x=last_used;x<=n;x++)
                cout<<2<<" "<<x<<endl;
            return 0;
        }
        int last_used=i+1;
        cout<<1<<" "<<last_used<<endl;
        d--;
         i=last_used;
        while(d>0)
        {
            cout<<i<<" "<<i+1<<endl;
            d--;
            i++;
        }
        //join all the remaining vertices to 1
        last_used=i+1;
        for(int x=last_used;x<=n;x++)
        {
            cout<<1<<" "<<x<<endl;
        }
        



    }
    

return 0;
}