// Created by Tanuj Jain
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
# define M_PI           3.14159265358979323846  /* pi */
#define OJ \
	freopen("input.txt", "r", stdin); \
	freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
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
int n,m;
// bool bfs()
// {
// 	//Causes TLE on OJ
// 	vector<int>a(n);
// 	vector<int>b(m);
// 	for(int i=0;i<n;i++)
// 		cin>>a[i];
// 	for(int i=0;i<m;i++)
// 		cin>>b[i];
// 	set<pair<string,pair<int,int>>>vis;
// 	unordered_set<string>seen;
// 	queue<pair<string,pair<int,int>>>q;
// 	q.push({"",{0,0}});
// 	while(!q.empty())
// 	{
// 		string curr=q.front().first;
// 		int idxa=q.front().second.first;
// 		int idxb=q.front().second.second;
// 		q.pop();
// 		//cout<<curr<<" "<<idxa<<" "<<idxb<<endl;
// 		if(idxa<n)
// 		{
// 			string new_curr=curr;
// 			new_curr+=to_string(a[idxa]);
// 			if(vis.find({new_curr,{idxa+1,idxb}})==vis.end())
// 			{
// 				q.push({new_curr,{idxa+1,idxb}});
// 				vis.insert({new_curr,{idxa+1,idxb}});
// 				seen.insert(new_curr);
// 			}
// 		}
// 		if(idxb<m)
// 		{
// 			string new_curr=curr;
// 			new_curr+=to_string(b[idxb]);
// 			if(vis.find({new_curr,{idxa,idxb+1}})==vis.end())
// 			{
// 				q.push({new_curr,{idxa,idxb+1}});
// 				vis.insert({new_curr,{idxa,idxb+1}});
// 				seen.insert(new_curr);
// 			}	
// 		}
// 	}
// 	string ans;
// 	for(int i=0;i<n+m;i++)
// 	{
// 		char x;
// 		cin>>x;
// 		ans+=x;
// 	}
// 	if(seen.find(ans)!=seen.end())
// 		return true;
// 	else
// 		return false;
	
// }
//const int MAXN=2e3+5;
int memo[1005][1005];

bool solve(int idxa, int idxb, int idxc,vector<int>&a, vector<int>&b,vector<int>&c)
{
	//cout<<idxa<<" "<<idxb<<" "<<idxc<<endl;
	if(idxa+idxb==n+m)
	{
		return true;
	}
	//generate the unique key 
	//string key=to_string(idxa)+"|"+to_string(idxb)+"|"+to_string(idxc);
	if(memo[idxa][idxb]!=-1)
		return memo[idxa][idxb];

	//pick one option
	bool ok1=false;
	bool ok2=false;
	if(idxa<n && a[idxa]==c[idxc])
		ok1=solve(idxa+1,idxb,idxc+1,a,b,c);
	if(idxb<m && b[idxb]==c[idxc])
		ok2=solve(idxa,idxb+1,idxc+1,a,b,c);
	return memo[idxa][idxb]=ok1||ok2;
	
}
bool poss_dp()
{
	vector<int>a(n),b(m);
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++)
		cin>>b[i];
	vector<int>c(n+m);
	for(int i=0;i<n+m;i++)
		cin>>c[i];

	//recursive solutin
	memset(memo,-1,sizeof(memo));
	return(solve(0,0,0,a,b,c));
	

	
}
int main()
{
	//OJ;
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);	
	while(cin>>n>>m)
	{
		if(n==0 && m==0)
			return 0;
		else
		{
			if(poss_dp())
				cout<<"possible"<<endl;
			else
				cout<<"not possible"<<endl;
		}
	}
	
}