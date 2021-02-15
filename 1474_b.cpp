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
vector<int>primes;
void sieve()
{
const int MAXN=1e6;
vector<char> is_prime(MAXN+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i * i <= MAXN; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= MAXN; j += i)
            is_prime[j] = false;
    }
}
for(int i=2;i<MAXN;i++)
    if(is_prime[i])
        primes.pb(i);
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
    sieve();
     char c=255;
        cout<<c<<endl;
    cout<<float(1/2)<<endl;
    while(t--)
    {
       
        int d;
        cin>>d;
        vector<ll>v(4);
        v[0]=1;
        v[1]=primes[lower_bound(primes.begin(),primes.end(),v[0]+d)-primes.begin()];
        v[2]=primes[lower_bound(primes.begin(),primes.end(),v[1]+d)-primes.begin()];
        v[3]=lcm(v[2],v[1]);
        cout<<v[3]<<endl;

    }
return 0;
}