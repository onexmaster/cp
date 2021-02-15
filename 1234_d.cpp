// Created by Tanuj Jain
//My first Segment Tree Program 
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
const int MAXN=1e5+5;
int n;
ll segtree[4*MAXN];
void build(string &s,int v, int left,int right)
{
	if(left==right)
	{
		int x=s[left]-'a';
		segtree[v]|=(1<<x);
	}
	else
	{
		int mid=(left+right)/2;
		build(s,v*2,left,mid);
		build(s,v*2+1,mid+1,right);
		//merge
		segtree[v]=segtree[v*2]|segtree[v*2+1];
	}
}
int query(int v, int curr_left, int curr_right, int query_left, int query_right)
{
	//cout<<curr_left<<" "<<curr_right<<" "<<query_left<<" "<<query_right<<endl;
	if(query_left>query_right)
		return 0;
	// if the query segment match the current segment, return the answer directly
	if(query_left==curr_left && query_right==curr_right)
		return(segtree[v]);
	//get the answer from the children
	int mid=(curr_left+curr_right)/2;
	//left holds the answer for the left to mid
	ll left=query(v*2,curr_left,mid,query_left,min(query_right,mid));
	//right holds the answer for mid+1 to right
	ll right=query(v*2+1,mid+1,curr_right,max(query_left,mid+1),query_right);
	return left|right;
}
void update(int v,int curr_left, int curr_right, int &pos, char &val)
{
	//if node of update reached
	if(curr_left==curr_right)
	{
		//turn the bit present cureently to off
		//i.e set it to 0 
		segtree[v]=0;
		int x=val-'a';
		segtree[v]|=(1<<x);
	}
	else
	{
		int mid=(curr_left+curr_right)/2;
		//if position of update is left than mid go to the left child
		if(pos<=mid)
			update(v*2,curr_left,mid,pos,val);
		else
			update(v*2+1,mid+1,curr_right,pos,val);
		//after the update propogate the changes updwards
		segtree[v]=segtree[v*2]|segtree[v*2+1];

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

	string s;
	cin>>s;
	n=s.size();
	build(s,1,0,n-1);
	int q;
	cin>>q;
	while(q--)
	{
		int type;
		cin>>type;
		if(type==2)
		{
			int left,right;
			cin>>left>>right;
			left--;
			right--;
			int ans=__builtin_popcount(query(1,0,n-1,left,right));
			printf("%d \n",ans);
		}
		else
		{
			int pos;
			char val;
			cin>>pos>>val;
			pos--;
			update(1,0,n-1,pos,val);
		}
	}


}