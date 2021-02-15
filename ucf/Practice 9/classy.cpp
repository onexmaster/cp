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
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
int n;
cin>>n;
string s;
getline(cin,s);
vector<pair<long double,string>>v;
for(int i=0;i<n;i++){
    getline(cin,s);
    //cout<<s<<endl;
    stringstream ss(s);
    string word;
    string temp;
    string name;
    while(ss>>word)
    {
        if(word!="lower" && word!="upper" && word!="class" && word!="middle")
            name=word;
        else if(word=="lower")
        temp+="1";
        else if(word=="middle")
        temp+="2";
        else if(word=="upper")
        temp+="3";


    }
    reverse(temp.begin(),temp.end());
    while(int(temp.size())<33)
        temp+="2";
    v.pb({stold(temp),name.substr(0,int(name.size())-1)});


}
sort(v.begin(),v.end(),[](auto a ,auto b){
    if(a.first>b.first)
    return true;
    else if(a.first==b.first)
    {
        if(a.second<b.second)
            return true;
        else
        {
            return false;
        }
        
    }
    return false;
});
for(int i=0;i<v.size();i++)
cout<<v[i].second<<endl;
getchar();
return 0;
}