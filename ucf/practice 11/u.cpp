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
bool invalid;
set<string>bad;
vector<string>subs;
void gen(string s)
{
    int n=s.size();
    for (int i = 0; i <n ; i++)
    {
        char temp[n - i + 1];
        int tempindex = 0;
        for (int j = i; j < n; j++)
        {
            temp[tempindex++] = s[j];
            temp[tempindex] = '\0';
          subs.pb(temp);
        }
    }
}
int main()
{
        FIO;
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    int n,m;
    cin>>n>>m;
    
    while(n--)
    {
        string s;
        cin>>s;
        bad.insert(s);
    }
    while(m--)
    {
        string s;
        cin>>s;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')
                s[i]='O';
            if(s[i]=='1')
                s[i]='L';
            if(s[i]=='2')
                s[i]='Z';
            if(s[i]=='3')
                s[i]='E';
            if(s[i]=='5')
                s[i]='S';
            if(s[i]=='6')
                s[i]='B';
            if(s[i]=='7')
                s[i]='T';
            if(s[i]=='8')
                s[i]='B';

        }
        subs.clear();
        gen(s);
        bool ok=true;
        for(auto st:subs)
            if(bad.find(st)!=bad.end())
                ok=false;
        if(!ok)
        cout<<"INVALID"<<endl;
        else 
        cout<<"VALID"<<endl;
        
    }

return 0;
}