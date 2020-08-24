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
unordered_map<string,vector<string>>ada;
unordered_map<string,int>dist;
void bfs()
{
	dist["Erdos,P."]=0;
	queue<string>q;
	q.push("Erdos,P.");
	while(!q.empty())
	{
		string curr=q.front();
		q.pop();
		for(auto edges:ada[curr])
		{
			if(dist.count(edges)==0)
			{
				dist[edges]=dist[curr]+1;
				q.push(edges);
			}
		}
	}
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
	int a=1;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		string st1;
		getline(cin,st1);
		while(n--)
		{
			getline(cin,st1);
			stringstream ss(st1);
			string word;
			vector<string>authors;
			int x=0;
			string temp;
			while(ss>>word)
			{
				temp+=word;
				x++;
				if(x%2==0)
				{
					//cout<<temp.substr(0,temp.size()-1)<<endl;
					authors.pb(temp.substr(0,temp.size()-1));
					temp="";
				}
				if(word[word.size()-1]==':')
					break;
			}
			for(int i=0;i<authors.size()-1;i++)
			{
				for(int j=i+1;j<authors.size();j++)
				{
					ada[authors[i]].pb(authors[j]);
					ada[authors[j]].pb(authors[i]);
				}
			}

		}
		bfs();
		cout<<"Scenario "<<a<<endl;
		while(m--)
		{
			getline(cin,st1);
			stringstream ss(st1);
			string word;
			string temp;
			while(ss>>word)
			{
				cout<<word<<" ";
				temp+=word;
			}
			if(dist.count(temp)==0)
				cout<<"infinity"<<endl;
			else
				cout<<dist[temp]<<endl;
		}
		a++;
		ada.clear();
		dist.clear();

		
	}
	
}