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

int bfs(int a, int b, int c)
{
	//queue holds water in jug a, jug b
	//my task is to reach from 0,0 to some state c,0 or 0,c in the sortest way possible
	set<pair<int,int>>vis;
	queue<pair<int,int>>q;
	q.push({0,0});
	//vis.insert({0,0});
	int steps=0;
	while(!q.empty())
	{
		int curr_size=q.size();
		for(int i=0;i<curr_size;i++)
		{
			int jug_a=q.front().first;
			int jug_b=q.front().second;
			q.pop();
			cout<<jug_a<<" "<<jug_b<<endl;
			//what moves i can perform
			if((jug_b==c) || (jug_a==c))
				return steps;
			//Fill jug a to its capacity  
			//int new_jug_a=a;
			//if(vis.find({a,jug_b})==vis.end())
			//{
				q.push({a,jug_b});
				//vis.insert({a,jug_b});
			//}
			//fill jug b to its capacity
			//int new_jug_b=b;
			//if(vis.find({jug_a,b})==vis.end())
			//{
				q.push({jug_a,b});
				//vis.insert({jug_a,b});
			//}
			
			for(int j=0;j<=max(a,b);j++)
			{
				//transfer  'j' water from jug b to jug a
				int new_jug_a=jug_a+j;
				int new_jug_b=jug_b-j;
				//check if it possible or not
				if(new_jug_a==a && new_jug_b>=0) //&& vis.find({new_jug_a,new_jug_b})==vis.end())
				{
					q.push({new_jug_a,new_jug_b});
					//vis.insert({new_jug_a,new_jug_b});
				}
				//transfer  'j' water from jug a to jug b
				 new_jug_b=jug_b+j;
				 new_jug_a=jug_a-j;
				if(new_jug_a>=0 && new_jug_b==b) //&& vis.find({new_jug_a,new_jug_b})==vis.end())
				{
					q.push({new_jug_a,new_jug_b});
					//vis.insert({new_jug_a,new_jug_b});
				}
			}
			//empty jug a 
			 //new_jug_a=0;
			//if(vis.find({0,jug_b})==vis.end())
			//{
				q.push({0,jug_b});
				//vis.insert({0,jug_b});
			//}
			//empty jug b
			 //new_jug_b=0;
			//if(vis.find({jug_a,0})==vis.end())
			//{
				q.push({jug_a,0});
			//	vis.insert({jug_a,0});
			//}

		}
		steps++;
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

	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		cout<<bfs(a,b,c)<<endl;
	}
}