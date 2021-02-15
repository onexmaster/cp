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
string s,t;
int n,m;
bool is_sub(string a)
{
	//check if m is a subsequnce of the changed string a
	if(a.size()<m)
		return false;
	int j=m;
	int i=a.size();
	while(i>=0 && j>=0)
	{
		if(a[i]==t[j])
		{
			i--;
			j--;
		}
		else
			i--;
	}
	if(i<0 && j<0)
		return true;
	if(i<0 && j>=0)
		return false;
	return true;

}
bool poss(int mid)
{
	//remove the substring of size mid and check if it possible to remove any substring of the given size
	for(int i=0;i<=n-mid;i++)
	{
		string temp=s.substr(0,i)+s.substr(i+mid,n);
		//cout<<mid<<" "<<temp<<endl;
		if(is_sub(temp))
			return true;
	}
	return false;


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
	cin>>s>>t;
	n=s.size();
	m=t.size();
	int l=0;
	int h=n-m;
	int ans=0;
	while(l<=h)
	{
		int mid=l+(h-l)/2;
		if(poss(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
			h=mid-1;
	}
	cout<<ans<<endl;

}