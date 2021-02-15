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
	string a,b;
	cin>>a>>b;
	vector<pair<int,int>>ans;
	//stors the ? in each string
	vector<int>counta,countb;
	vector<pair<char,int>>a1,b1;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='?')
			counta.pb(i+1);
		else
			a1.pb({a[i],i+1});
		if(b[i]=='?')
			countb.pb({i+1});
		else
			b1.pb({b[i],i+1});

	}
	sort(a1.begin(),a1.end());
	sort(b1.begin(),b1.end());
	vector<int>missed_a,missed_b;
	int i=0;
	int j=0;
	while(i<a1.size() && j<b1.size())
	{
		if(a1[i].first==b1[j].first)
		{
			ans.pb({a1[i].second,b1[j].second});
			i++;
			j++;
		}
		else if(a1[i].first>b1[j].first)
		{
			missed_b.pb(b1[j].second);
			j++;
		}
		else if(a1[i].first<b1[j].first)
		{
			missed_a.pb(a1[i].second);
			i++;
		}
	}
	//add all the missed char of the other string
	if(i!=a1.size())
	{
		while(i<a1.size())
		{
			missed_a.pb(a1[i].second);
			i++;
		}
	}
	if(j!=b1.size())
	{
		while(j<b1.size())
		{
			missed_b.pb(b1[j].second);
			j++;
		}
	}
	//pair the ? from a with the unmatched chars in b
	int ii=0;
	j=0;
	while(ii<counta.size() && j<missed_b.size())
	{
		ans.pb({counta[ii],missed_b[j]});
		ii++;
		j++;
	}
	//pair the ? from b with unmatched chars in a
	int iii=0;
	j=0;
	while(iii<countb.size() && j<missed_a.size())
	{
		ans.pb({missed_a[j],countb[iii]});
		iii++;
		j++;
	}
	//match the remainin ? from a with ? from b
	while(ii<counta.size() && iii<countb.size())
	{
		ans.pb({counta[ii],countb[iii]});
		ii++;
		iii++;
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	return 0;
}