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
    char grid[324][5000];
int main()
{
        FIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    string temp;
    int i=0;
    int m;
    while(getline(cin,temp))
    {
         m=temp.size();
        for(int j=0;j<m;j++)
            grid[i][j]=temp[j];
        for(int j=m;j<5000;j++)
            grid[i][j]=grid[i][j%m];
        i++;
    }
    ll trees1=0;
    int sx=0,sy=0;
    while(sx<323)
    {
        //cout<<sx<<" "<<sy<<endl;
        if(grid[sx][sy]=='#')
            trees1++;
            sy+=3;
            sx+=1;
       
    }
    ll trees2=0;
    sx=0,sy=0;
     while(sx<323)
    {
        //cout<<sx<<" "<<sy<<endl;
        if(grid[sx][sy]=='#')
            trees2++;
            sy+=1;
            sx+=1;
       
    }
   ll trees3=0;
    sx=0,sy=0;
     while(sx<323)
    {
        //cout<<sx<<" "<<sy<<endl;
        if(grid[sx][sy]=='#')
            trees3++;
            sy+=5;
            sx+=1;
       
    }
    ll trees4=0;
    sx=0,sy=0;
     while(sx<323)
    {
        //cout<<sx<<" "<<sy<<endl;
        if(grid[sx][sy]=='#')
            trees4++;
            sy+=7;
            sx+=1;
       
    }
    ll trees5=0;
    sx=0,sy=0;
     while(sx<323)
    {
        //cout<<sx<<" "<<sy<<endl;
        if(grid[sx][sy]=='#')
            trees5++;
            sy+=1;
            sx+=2;
       
    }
    cout<<trees1*trees2*trees3*trees4*trees5;
return 0;
}