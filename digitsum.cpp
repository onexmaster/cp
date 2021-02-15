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
//make a bitmask 
//put 1's in one group and 0's in another group 
//make the smallest permutation of such group
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	//#ifndef ONLINE_JUDGE
	freopen("digitsum.in","r",stdin);
	//freopen("outputf.in","w",stdout);
	//#endif

	int t;
	while(cin>>t)
	{

	if(t==0)
		return 0;
	vector<char>v(t);
	for(int i=0;i<t;i++)
		cin>>v[i];
	sort(v.begin(),v.end());
	set<pair<string,string>>combo;
	//mask;
	for(int mask=0;mask<(1<<t);mask++)
	{
		string a,b;
		for(int i=0;i<t;i++)
		{
			//if the ith bit is set use it in string a 
			if(mask&(1<<i))
				a+=v[i];
			else
				b+=v[i];
		}
		combo.insert({a,b});
		combo.insert({b,a});
	}
	ll ans=LLONG_MAX;
	for(auto it:combo)
	{
		string a=it.first;
		string b=it.second;
		//if the first digit is zero, swap with the first non zero digit
		if(a[0]=='0')
		{
			bool ok1=false;
			for(int j=1;j<a.size();j++)
			{
					if(a[j]!='0')
					{
						swap(a[0],a[j]);
						ok1=true;
						break;
						
					}
			}
			if(!ok1)
				continue;
				
		}
		
		if(b[0]=='0')
		{
			bool ok2=false;
			for(int j=1;j<b.size();j++)
			{
					if(b[j]!='0')
					{
						swap(b[0],b[j]);
						ok2=true;
						break;

					}
			}
			if(!ok2)
				continue;
				
		}
		ll x=0;
		ll y=0;
		//cout<<a<<" "<<b<<endl;
		if(a.size()!=0)
			 x=stoll(a);
		if(b.size()!=0)
			 y=stoll(b);
		//cout<<"INT"<<endl;
		//cout<<x<<" "<<y<<endl;
		ans=min(ans,x+y);

	}
	cout<<ans<<endl;
}
}