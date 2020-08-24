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
	trienode *children[10];
	bool isend;
};
trienode *createNode()
{
	trienode *newnode= new trienode;
	newnode->isend=false;
	for(int i=0;i<10;i++)
		newnode->children[i]=NULL;
	return newnode;
}
bool insert(trienode *root, string val)
{
	trienode *crawl=root;
	 string number=val;
	//cout<<number<<endl;
	for(int i=0;i<number.length();i++)
	{
		int index=number[i]-'0';
		//cout<<index<<endl;
		 if(crawl->children[index]  && (crawl->children[index]->isend || i==val.length()-1))
		 {

		 	return true;
		 	//return"prefix found";
		 }
			
		else if(!crawl->children[index])
			crawl->children[index]=createNode();
		crawl=crawl->children[index];
	}
	crawl->isend=true;

	return false;
	//return"prefix not found";


}
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	//#ifndef ONLINE_JUDGE
	//freopen("inputf.in","r",stdin);
	//freopen("outputf.in","w",stdout);
	//#endif

	int t;
	cin>>t;
	while(t--)
	{
		trienode *root=createNode();
		int x;
		cin>>x;
		vector<string>v(x);
		bool ok=true;
		for(int i=0;i<x;i++)
		{
			cin>>v[i];
			//cout<<insert(root,v[i])<<endl;
			
			if(ok)
				if(insert(root,v[i]))
				{
					//cout<<v[i]<<endl;
					ok=false;
				}

		}
		if(!ok)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
			
	}
	
}