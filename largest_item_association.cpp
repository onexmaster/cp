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
unordered_map<string,vector<string>>ada;
unordered_set<string>vis;
vector<vector<string>>components;
//this set stores all the eleents that are in the itemAssocation
unordered_set<string>seen;
vector<string>comp;
void dfs(string src)
{
	//cout<<src<<endl;
	vis.insert(src);
	comp.pb(src);
	for(auto edges:ada[src])
	{
		if(vis.find(edges)==vis.end())
			dfs(edges);
	}
}
void solve(std::vector<pair<string,string>>&itemAssociation)
{
	//clear all the things
	ada.clear();
	vis.clear();
	components.clear();
	seen.clear();
	//build the graph
	for(int i=0;i<itemAssociation.size();i++)
	{
		string u=itemAssociation[i].first;
		string v=itemAssociation[i].second;
		if(v=="")
		{
			ada[u].pb("");
			seen.insert(u);
		}
		else if(u=="")
		{
			ada[v].pb("");
			seen.insert(v);
		}
		else
		{
			ada[u].pb(v);
			ada[v].pb(u);
			seen.insert(v);
			seen.insert(u);
		}

	}
	for(auto it:seen)
	{
		if(vis.find(it)==vis.end())
		{
			comp.clear();
			dfs(it);
			vector<string>temp;
			//Remove the placebo "" which we added as it might fuck up the answer
			for(int i=0;i<comp.size();i++)
				if(comp[i]!="")
					temp.pb(comp[i]);
			components.pb(temp);
		}
	}
	//print the compnent vector
	// for(int i=0;i<components.size();i++)
	// {
	// 	for(int j=0;j<components[i].size();j++)
	// 		cout<<components[i][j]<<" ";
	// 	cout<<endl;

	//  }

	//sort the components internally first;
	for(int i=0;i<components.size();i++)
		sort(components[i].begin(),components[i].end());
	//take the largest component and if tie take the lexicographically smallest one
	int max_size=INT_MIN;
	vector<string>ans;
	//ans.clear();
	for(int i=0;i<components.size();i++)
	{
		//cout<<components[i].size()<<endl;
		int curr_sz=components[i].size();
		if(curr_sz>max_size)
		{
			max_size=curr_sz;
			ans=components[i];
		}
		else if(curr_sz==max_size)
		{
			//if the first entry in answer is lexicographically larger than the value in current component, we need to replace the answer
			//This works coz an element cannot belong to multiple components, so elemets in each component is unique
			if(ans[0]>components[i][0])
				ans=components[i];
		}
	}
	cout<<ans.size()<<endl;
	for(auto it:ans)
		cout<<it<<" ";
	cout<<endl;
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

	//test with duplicates values
	vector<pair<string, string>> item_assoc_1 = {
    {"item1", "item2"}, {"item1", "item3"}, {"item2", "item7"}, 
    {"item3", "item7"},{"item5", "item6"},{"item3", "item7"}
  };
  	solve(item_assoc_1);
	//test with only single componets
	vector<pair<string, string>> item_assoc_2 ={ {"item2",""}, {"item3",""}, {"item7",""}, 
    {"item3",""},{"", "item6"},{"", "item1"}
  };
  	solve(item_assoc_2);

  //test with og Test case
  	vector<pair<string, string>> item_assoc_3 = {
    {"item1", "item2"}, {"item3", "item4"}, {"item4", "item5"}
  };
  solve(item_assoc_3);
  //random test case
  vector<pair<string, string>> item_assoc_4 = {
    {"item1", "item2"}, {"item4", "item5"}, {"item3", "item4"}, {"item1", "item4"}
  };
  solve(item_assoc_4);
	return 0;

/* OUTPUT 
4
item1 item2 item3 item7 
1
item1 
3
item3 item4 item5 
5
item1 item2 item3 item4 item5 

*/
}