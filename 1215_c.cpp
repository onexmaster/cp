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

	int a;
	cin>>a;
	string s,t;
	cin>>s>>t;
	vector<int>mis_b_a,mis_a_b;
	for(int i=0;i<a;i++)
	{
		if(s[i]!=t[i])
		{
			if(s[i]=='b')
				mis_b_a.pb(i);
			else
				mis_a_b.pb(i);
		}
	}
	if(mis_a_b.size()%2==0 && mis_b_a.size()%2!=0 || mis_a_b.size()%2!=0 && mis_b_a.size()%2==0)
		cout<<-1;
	//both are even
	else if(mis_a_b.size()%2==0 && mis_b_a.size()%2==0)
	{
		
		cout<<mis_a_b.size()/2 + mis_b_a.size()/2<<endl;
		int n1=mis_a_b.size();
		int n2=mis_b_a.size();
		for(int i=0;i<n1/2;i++)
			cout<<mis_a_b[i]+1<<" "<<mis_a_b[n1-1-i]+1<<endl;
		for(int i=0;i<n2/2;i++)
			cout<<mis_b_a[i]+1<<" "<<mis_b_a[n2-i-1]+1<<endl;
	}
	//if both are odd
	else
	{
		cout<<(mis_a_b.size()-1)/2+(mis_b_a.size()-1)/2+2<<endl;
		int n1=mis_a_b.size();
		int n2=mis_b_a.size();
		for(int i=0;i<n1/2;i++)
			cout<<mis_a_b[i]+1<<" "<<mis_a_b[n1-1-i]+1<<endl;
		for(int i=0;i<n2/2;i++)
			cout<<mis_b_a[i]+1<<" "<<mis_b_a[n2-i-1]+1<<endl;
		//swap the middle element
		cout<<mis_a_b[n1/2]+1<<" "<<mis_a_b[n1/2]+1<<endl;
		//swap with the middle element of t;
		cout<<mis_a_b[n1/2]+1<<" "<<mis_b_a[n2/2]+1<<endl;

	}


}