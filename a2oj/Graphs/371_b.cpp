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
unordered_set<int>factors;
unordered_map<int,int>dista;
unordered_map<int,int>distb;
void get(int x)
{
	while(x%2==0)
	{
		factors.insert(2);
		x/=2;
	}
	for(int i=3;i<=sqrt(x);i+=2)
	{
		while(x%i==0)
		{
			factors.insert(i);
			x/=i;
		}
	}
	if(x>2)
		factors.insert(x);
}
void bfsa(int start)
{
	queue<int>q;
	q.push(start);
	dista[start]=0;
	while(!q.empty())
	{
		int curr=q.front();
		q.pop();
		if(curr%2==0)
		{
			int new_state=curr/2;
			if(dista.count(new_state)==0)
			{
				q.push(new_state);
				dista[new_state]=dista[curr]+1;
			}
		}
		if(curr%3==0)
		{
			int new_state=curr/3;
			if(dista.count(new_state)==0)
			{
				q.push(new_state);
				dista[new_state]=dista[curr]+1;
			}
		}
		if(curr%5==0)
		{
			int new_state=curr/5;
			if(dista.count(new_state)==0)
			{
				q.push(new_state);
				dista[new_state]=dista[curr]+1;
			}
		}
	}
}
int bfsb(int start)
{
	queue<int>q;
	q.push(start);
	distb[start]=0;
	while(!q.empty())
	{
		int curr=q.front();
		q.pop();
		if(dista[curr]!=0)
			return curr;
		if(curr%2==0)
		{
			int new_state=curr/2;
			if(distb.count(new_state)==0)
			{
				q.push(new_state);
				distb[new_state]=distb[curr]+1;
			}
		}
		if(curr%3==0)
		{
			int new_state=curr/3;
			if(distb.count(new_state)==0)
			{
				q.push(new_state);
				distb[new_state]=distb[curr]+1;
			}
		}
		if(curr%5==0)
		{
			int new_state=curr/5;
			if(distb.count(new_state)==0)
			{
				q.push(new_state);
				distb[new_state]=distb[curr]+1;
			}
		}

	}
	return -1;

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

	int a,b;
	cin>>a>>b;
	if(a==b)
	{
		cout<<0;
		return 0;
	}
	// factors.clear();
	// get(a);
	// 	for(auto it:factors)
	// 	{
	// 		if(it!=2 && it!=3&&it!=5)
	// 		{
	// 			cout<<-1;
	// 			return 0;
	// 		}
		
	// 	}
		
	
	// factors.clear();
	// get(b);
	// for(auto it:factors)
	// 	{
	// 		if(it!=2 && it!=3 && it!=5)
	// 		{
	// 			cout<<-1;
	// 			return 0;
	// 		}
		
	// 	}
		if(b>a)
			swap(a,b);
		bfsa(a);
		int common=bfsb(b);
		if(common==-1)
			cout<<-1;
		else
			cout<<dista[common]+distb[common];
	
}