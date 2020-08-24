//https://leetcode.com/problems/search-suggestions-system/discuss/442359/C%2B%2B-Three-Way-Solution-With-Picturearrary-sort-Trie(hash%2Barray)Trie(hash%2Bheap))
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

struct trienode{
	unordered_map<char,trienode*>children={};
	set<string>dict={};
};
void insert(trienode *root, string val)
{
	trienode *crawl=root;
	for(auto c :val)
	{
		if(!crawl->children[c])
			crawl->children[c]=new trienode();
		crawl=crawl->children[c];
		crawl->dict.insert(val);	
	}
}
void search(trienode *root, string val, int no)
{
	trienode *crawl=root;
	int i=0;
	for(auto c :val)
	{
		if(!crawl->children[c])
			break;
		//go to the end of the word
		else
		{
			crawl=crawl->children[c];
			i++;
		}
	}
	//if the prefix we are looking for matches partially , return no match
	if(crawl->dict.size()==0 || i!=val.length())
	{
		cout<<"Case #"<<no<<":"<<"\n"<<"No match.";
	}
	//if the prefix matches completely
	else if(i==val.length())
	{
		cout<<"Case #"<<no<<":"<<endl;
		if(crawl->dict.find(val)!=crawl->dict.end())
			crawl->dict.erase(val);
		for(auto it:crawl->dict)
			cout<<it<<endl;
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
	trienode *root=new trienode();
	for(int i=0;i<t;i++)
	{
		string st;
		cin>>st;
		insert(root,st);
	}
	int a;
	cin>>a;
	for(int i=0;i<a;i++)
	{
		string st;
		cin>>st;
		search(root,st,i+1);
	}
	
}