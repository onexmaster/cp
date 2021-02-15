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
	vector<int>v(t);
	for(int i=0;i<t;i++)
		cin>>v[i];
	map<int,int>freq;
	//find the missing elements
	set<int>not_pres;
	for(int i=1;i<=t;i++)
		not_pres.insert(i);
	//remove the present elements
	for(int i=0;i<t;i++)
	{
		freq[v[i]]++;
		//if(not_pres.find(v[i])!=not_pres.end())
		not_pres.erase(v[i]);
	}
	int chan=0;
	int miss=*not_pres.begin();
	set<int>skip;
	set<int>vis;
	for(int i=0;i<t;i++)
	{
		if(freq[v[i]]>1)
		{
			//replce if freq is bigger than 1 and also if the number present there is 
			//bigger than the number which we can insert
			if(miss<v[i])
			{
				--freq[v[i]];
				chan++;
				v[i]=miss;
				not_pres.erase(miss);
				miss=*not_pres.begin();
				
			}
			//if we have skipped this element before we can replace it now
			else if(vis.find(v[i])!=vis.end())
			{
				--freq[v[i]];
				chan++;
				v[i]=miss;
				not_pres.erase(miss);
				miss=*not_pres.begin();
			}
			//skip the first occ 
			else 
			{
				vis.insert(v[i]);
			}
		}
	}
	cout<<chan<<endl;
	for(int i=0;i<t;i++)
		cout<<v[i]<<" ";
	return 0;


}