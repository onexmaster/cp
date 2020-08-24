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
unordered_set<string>st1;
int bfs(string source, string destination)
{
			set<string>vis;
			int step=0;
			queue<string>q;
			q.push(source);
			vis.insert(source);
			while(!q.empty())
			{
				int curr_size=q.size();
				for(int i=0;i<curr_size;i++)
				{
					string curr=q.front();
					//cout<<curr<<" "<<step<<endl;
					q.pop();
					if(curr==destination)
					{
						return step;
					}
					for(int j=0;j<curr.size();j++)
					{
						string temp1=curr;
						for(char k='a';k<='z';k++)
						{
								temp1[j]=k;
								if(st1.find(temp1)!=st1.end()  && vis.find(temp1)==vis.end())
								{
									q.push(temp1);
									vis.insert(temp1);
								}
							}
						}
					}
					step++;
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
		
		string temp;
		while(cin>>temp)
		{
			if(temp=="*")
				break;
			else
				st1.insert(temp);
		}
		string src,dest;

		while(cin>>src>>dest)
		{
			cout<<src<<" "<<dest<<" "<<bfs(src,dest)<<endl;
				
		}
		st1.clear();
		}
		return 0;
	}