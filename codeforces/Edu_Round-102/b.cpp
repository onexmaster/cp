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
string gcdofstrings(string str1, string str2)
{
    if(str1+str2 != str2+str1) return "";
    return str1.substr(0,gcd(str1.length(),str2.length()));
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
    string s,t1;
    cin>>s>>t1;
    if(s>t1)
        swap(s,t1);
    string ans=gcdofstrings(s,t1);
    if(ans.size()==0)
        cout<<-1<<endl;
    else
    {
        int sz=ans.size();
        int sz1=(int(s.size())/sz);
        int sz2=(int (t1.size())/sz);
        int lc=lcm(sz1,sz2);
        string res;
        for(int i=0;i<lc;i++)
            res+=ans;
        cout<<res<<endl;

        
    }
    
    }
    

return 0;
}