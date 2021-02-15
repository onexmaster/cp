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
const int N = 510031;
 
int n,ar[N];
vector<int> vertices[N],g[N];
vector<int> ans;
int C;
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	cin>>n;
	for (int i=0;i<=n;i++){
		cin>>ar[i];
	}
 
	int is_ok=0;
	for (int i=2;i<=n;i++){
		if (ar[i]>=2&&ar[i-1]>=2){
			is_ok=1;
		}
	}
 
	if (is_ok==0){
		cout<<"perfect"<<endl;
		return 0;
	}
 
	cout<<"ambiguous"<<endl;
 
	// print first
 
	for (int i=0;i<=200000;i++){
		g[i].clear();
		vertices[i].clear();
	}
 
	vertices[0].push_back(1);
	ans.push_back(0);
	C=1;
 
	for (int i=1;i<=n;i++){
		for (int j=0;j<ar[i];j++){
			ans.push_back(vertices[i-1][0]);
			++C;
			vertices[i].push_back(C);
		}
	}
 
	for (int i=0;i<ans.size();i++){
		if (i)
			cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;
 
	// print second
	for (int i=0;i<=200000;i++){
		g[i].clear();
		vertices[i].clear();
	}
	ans.clear();
	vertices[0].push_back(1);
	C=1;
	ans.push_back(0);
 
	for (int i=1;i<=n;i++){
		for (int j=0;j<ar[i];j++){
			if (j==0)
				ans.push_back(vertices[i-1][0]);
			else
				ans.push_back(vertices[i-1].back());
			++C;
			vertices[i].push_back(C);
		}
	}
 
	for (int i=0;i<ans.size();i++){
		if (i)
			cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;
 
}