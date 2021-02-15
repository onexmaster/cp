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
const ll inf=1ll<<32;
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	int t;
	cin>>t;
	//-1 indicates add operation
	//second holds the number of times we need to add this value
	stack<pair<ll,ll>>st;
	ll i=0;
	while(t--)
	{
		string s;
		cin>>s;
		if(s=="add" && st.empty())
			i++;
		else if(s=="add")
		{
			st.push({-1,min(inf,st.top().second)});
		}
		else if(s=="for")
		{
			int x;
			cin>>x;
			if(st.empty())
				st.push({x,x});
			else 
				st.push({x,min(inf,st.top().second)*x});
		}
		else if(s=="end")
		{
			//ll count_add=0;
			//ll count_add_times=0;
			while(!st.empty() && st.top().first==-1)
			{
				i+=st.top().second;
				if(i>=(1LL<<32))
				{	
					cout<<"OVERFLOW!!!";
					return 0;
				}
				st.pop();
			}
			//i+=count_add*(count_add_times);
			
			//pop the topmost for
			st.pop();
		}
	}
	if(i>=(1LL<<32))
	{	
		cout<<"OVERFLOW!!!";
			return 0;
	}
	else
		cout<<i<<endl;

}