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
	while(t--)
	{
		int n;
		cin>>n;
		map<int,int>freq;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			freq[x]++;
		}
		vector<pii>v;
		for(auto it:freq)
			if(it.second>=2)
				v.pb({it.first,it.second});
		double ans=DBL_MAX;
		int p1,p2;
		for(int i=0;i<v.size()-1;i++)
		{
			//we can use all the 4 sticks to form a rectangle
			if(v[i].second>=4)
			{
				double area=v[i].first*v[i].first;
				double per=2*(v[i].first+v[i].first);
				double ans1=(per*per)/area;
				if(ans1<ans)
				{
					p1=v[i].first;
					p2=v[i].first;
					ans=min(ans,ans1);
				}
			}
			else
			{
				double area=v[i].first*v[i+1].first;
				double per=2*(v[i].first+v[i+1].first);
				double ans1=(per*per)/area;
				//cout<<area<<" "<<per*per<<" "<<ans1<<endl;
				if(ans1<ans)
				{
					p1=v[i].first;
					p2=v[i+1].first;
					ans=min(ans,ans1);
				}	
			}
		}
		//check the last value
		if(v[v.size()-1].second>=4){
				double area=v[v.size()-1].first*v[v.size()-1].first;
				double per=2*(v[v.size()-1].first+v[v.size()-1].first);
				double ans1=(per*per)/area;
				if(ans1<ans)
				{
					p1=v[v.size()-1].first;
					p2=v[v.size()-1].first;
					ans=min(ans,ans1);
				}
			}

		cout<<p1<<" "<<p1<<" "<<p2<<" "<<p2<<endl;
	}

}