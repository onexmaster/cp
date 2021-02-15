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
	vector<int>v(t);
	int freq[105]={0};
	//memset(freq,0,sizeof(freq));
	for(int i=0;i<t;i++)
	{
		cin>>v[i];
		freq[v[i]]++;
		
	}
	//i need numbers who appear only once and the numbers which appear twice
	//the numbers which appear twice cannot be used to split the array 
	int one=0;
	int g_two=0;
	for(int i=0;i<t;i++)
	{
		if(freq[v[i]]>2)
			g_two++;
		else if(freq[v[i]]==1)
			one++;
	}
	//if we have no number repeated more than twice and if one is odd 
	if(g_two==0 && one%2!=0)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	bool treba = 0;
	if (one & 1)
		treba = 1;
	
	int balance = 0;
	for(int i=0;i<t;i++)
	{
		if (freq[v[i]] == 1)
		{
			if (balance == 0)
				cout << "A";
			else
				cout << "B";
			
			balance ^= 1;
			continue;
		}
		
		if (freq[v[i]] == 2 || !treba)
		{
			cout << "A";
			continue;
		}
		
		if (treba)
		{
			cout << "B";
			treba = 0;
		}		
	}	


}