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
map<ll,int>factors;
void get_factors(long long n) {
    while (n % 2 == 0) {
        factors[2]++;
        n /= 2;
    }
    for (long long d = 3; d * d <= n; d += 2) {
        while (n % d == 0) {
            factors[d]++;
            n /= d;
        }
    }
    if (n > 1)
        factors[n]++;
}
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
        ll n;
        cin>>n;
        factors.clear();
        get_factors(n);
        int get_max=-1;
        ll mx_no=-1;
        for(auto it:factors)
        {
            
            if(get_max<it.second)
            {
                get_max=max(get_max,it.second);
                mx_no=it.first;
            }
        }
            
        if(get_max==1)
        {
            //the number can be made up of two or more primes
            if(factors.size()>1)
            {
                cout<<1<<endl;
                cout<<n<<endl;
            }
            //the number can be made of multiples of primes or it can be prime itself
            if(factors.size()==1)
            {
                ll num;
                for(auto it:factors)
                    num=it.first;
                cout<<get_max<<endl;
                for(int i=0;i<get_max;i++)
                    cout<<num<<" ";
                cout<<endl;

            }
                
        }
        else
        {
            //use the n-1 factors of the max value
            cout<<get_max<<endl; 
            for(int i=0;i<get_max-1;i++)
            {
                cout<<mx_no<<" ";
                n/=mx_no;
            }
            cout<<n<<endl;
        }
        


        
    }
return 0;
}