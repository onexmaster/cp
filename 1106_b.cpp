// Created by Tanuj Jain
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
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
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	int n,m;
	cin>>n>>m;
	vector<ll>nos(n);
	vector<ll>cost(n);
	for(int i=0;i<n;i++)
		cin>>nos[i];
	for(int i=0;i<n;i++)
		cin>>cost[i];
	vector<pll>min_cost;
	for(int i=0;i<n;i++)
		min_cost.pb({cost[i],i});
	sort(min_cost.begin(),min_cost.end());
	bool all_zero=false;
	int i=0;      
	while(m--)
	{
		ll type,qu;
		cin>>type>>qu;
		type--;
		if(all_zero)
		{
			cout<<0<<endl;
			continue;
		}
		ll ans=0;
		if(nos[type]>=qu)
		{
			nos[type]-=qu;
			ans+=cost[type]*qu;
			cout<<ans<<endl;
			continue;
		}
		else
		{
			ll ans=0;

			if(nos[type]>0)
			{
				qu-=nos[type];
				ans+=(nos[type]*cost[type]);
				nos[type]=0;
			}
			//cout<<qu<<endl;
			
			bool use=false;
			while(i<min_cost.size() && qu>0)
			{
				//if non zero use this dish
				ll curr_quan=nos[min_cost[i].second];
				ll req_qua=qu;
				ll curr_cost=min_cost[i].first;
				if(curr_quan>req_qua)
				{
					ans+=(req_qua*curr_cost);
					nos[min_cost[i].second]-=qu;
					qu=0;
					use=true;
				}
				else
				{
					ans+=(curr_quan*curr_cost);
					qu-=curr_quan;
					nos[min_cost[i].second]=0;
					use=true;
					i++;
				}
				

			}
			if(qu>0)
				cout<<0<<endl;
			else
				cout<<ans<<endl;
			if(!use)
				all_zero=true;
			

		}
	}

}