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
double find(double x1,double y1, double x2, double y2)
{
    return (sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
}
int main()
{
        FIO;
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int n;
    int x=1;
    while(cin>>n)
    {
        if(n==0)
        break;
        double s1x,s1y,s2x,s2y,ene;
        cin>>s1x>>s1y>>s2x>>s2y>>ene;
        vector<pair<double,double>>v(n);
        for(int i=0;i<n;i++)
            cin>>v[i].first>>v[i].second;
        vector<pair<double,int>>dist1,dist2;
        for(int i=0;i<n;i++)
        {
            double dista1=find(s1x,s1y,v[i].first,v[i].second);
            double dista2=find(s2x,s2y,v[i].first,v[i].second);
            dist1.pb({dista1,i});
            dist2.pb({dista2,i});
        }
        //solve for the first base
        sort(dist1.begin(),dist1.end());
        //fix the radius of the first tower as dist[i] and accordingly find the value 
        //dont count duplicate missile
        // for(int i=0;i<dist1.size();i++)
        // cout<<dist1[i].first<<" "<<dist1[i].second<<endl;
        unordered_set<int>seen;
        int global_ans=n;
        for(int i=0;i<n;i++)
        {
            //distribute the energy
            double ene1=(3.141*dist1[i].first*dist1[i].first);
            //cout<<ene1<<endl;
            if(ene1>ene)
                continue;
            //add in set so you dont count dups
            seen.insert(dist1[i].second);
            double r2=sqrt((ene-ene1)/3.141);
            //count the missiles which will hit the base
            int local_ans=0;
            for(int j=0;j<n;j++)
            {
                if(seen.find(dist2[j].second)==seen.end())
                {
                    if(dist2[j].first>r2)
                    local_ans++;
                }
            }
            global_ans=min(global_ans,local_ans);


        }
        //solve for the 2nd base 
        sort(dist2.begin(),dist2.end());
        seen.clear();
        for(int i=0;i<n;i++)
        {
            //distribute the energy
            double ene2=(3.141*dist2[i].first*dist2[i].first);
            //cout<<ene2<<endl;
            if(ene2>ene)
                continue;
            //add in set so you dont count dups
            seen.insert(dist2[i].second);
            double r1=sqrt((ene-ene2)/3.141);
            //count the missiles which will hit the base
            int local_ans=0;
            for(int j=0;j<n;j++)
            {
                if(seen.find(dist1[j].second)==seen.end())
                {
                    if(dist1[j].first>r1)
                    local_ans++;
                }
            }
            global_ans=min(global_ans,local_ans);


        }

        cout<<x<<"."<<" "<<global_ans<<endl;
        x++;


    }
return 0;
}