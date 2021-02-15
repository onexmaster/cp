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
ll alpas[27],alphat[27];
string s,t;
ll cntq;
//need to have 'have' occ of t in s
ll poss(int have)
{
	//in order to have 'have' occ of t in s , find the total number of alpbah we have
	ll need=0;
	for(int i=0;i<26;i++)
		//i need to have alpha[i]*have occ of each alpha- i alrady have
		//if i have more use 0;
		need+=max(0LL,(alphat[i]*have)-alpas[i]);
	return need;
}

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	string s,t;
	cin>>s>>t;
	cntq=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='?')
			cntq++;
		else
			alpas[s[i]-'a']++;
	}
	for(int i=0;i<t.size();i++)
		alphat[t[i]-'a']++;
	int l=0;
	int h=1e6;
	int ans=0;
	ll have=cntq;
	while(l<=h)
	{
		int mid=l+(h-l)/2;
		ll need=poss(mid);
		//cout<<mid<<" "<<need<<endl;
		if(need<=have)
		{
			ans=mid;
			l=mid+1;

		}
		else
			h=mid-1;
	}
	//cout<<ans<<endl;
	for(int i=0;i<26;i++)
	{
		alpas[i]-=alphat[i]*ans;
		//cout<<alpas[i]<<" ";
	}
	//cout<<endl;
	//now alphas have all the negative values which denote we need to fill the question
	//mark these value
	alpas[26]=-10000;
	for(int i=0,j=0;i<s.length();i++)
	{
		if(s[i]=='?')
		{

			while(alpas[j]>=0)
				j++;
		s[i]=min('z',char('a'+j));
		alpas[s[i]-'a']++;
		}
		
	}
	cout<<s;
	return 0;

}