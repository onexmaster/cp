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
	struct trienode *children[26];
	bool isend;
};
trienode* createNode()
{
	trienode *newnode = new trienode;
	newnode->isend=false;
	for(int i=0;i<26;i++)
		newnode->children[i]=NULL;
	return newnode;
}
void insert(trienode *root, string key)
{
	trienode *crawl=root;
	for(int i=0;i<key.length();i++)
	{
		int index=key[i]-'a';
		if(!crawl->children[index])
			crawl->children[index]=createNode();
		crawl=crawl->children[index];
	}
	crawl->isend=true;
}
bool search(trienode *root, string key)
{
	 trienode *crawl=root;
	for(int i=0;i<key.length();i++)
	{
		int index=key[i]-'a';
		if(!crawl->children[index])
			return false;
		crawl=crawl->children[index];
	}
	return(crawl!=NULL && crawl->isend);
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

	string keys[] = {"the", "a", "there", 
                    "answer", "any", "by", 
                     "bye", "their" }; 
    int n = sizeof(keys)/sizeof(keys[0]); 
      trienode *root =createNode();
     for (int i = 0; i < n; i++) 
        insert(root, keys[i]); 
    search(root, "the")? cout << "Yes\n" : 
                         cout << "No\n"; 
    search(root, "these")? cout << "Yes\n" : 
                           cout << "No\n";
     search(root, "answer")? cout << "Yes\n" : 
                           cout << "No\n";
      search(root, "byee")? cout << "Yes\n" : 
                           cout << "No\n"; 
       search(root, "there")? cout << "Yes\n" : 
                           cout << "No\n";



}