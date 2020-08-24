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
	string st1;
	cin>>st1;
	map<char,string>mapp;
	mapp['0']="";
	mapp['1']="";
	mapp['2']="2";
	mapp['3']="3";
	mapp['4']="322";
	mapp['5']="5";
	mapp['6']="53";
	mapp['7']="7";
	mapp['8']="7222";
	mapp['9']="7332";
	string res;
	//cout<<st1<<endl;
	for(int i=0;i<st1.size();i++)
		res+=mapp[st1[i]];
	sort(res.begin(),res.end(),[](auto a, auto b){
		return a>b;
	});
	cout<<res;

	
}