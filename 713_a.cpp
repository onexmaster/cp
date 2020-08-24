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

	//maps- binary of a number to the freq
	unordered_map<string,ll>freq;
	ll n;
	cin>>n;
	while(n--)
	{
		char type;
		
		cin>>type;;
		if(type=='+')
		{
			string x;
			cin>>x;
			//get the digits which are odd
			string temp;
			temp.append(18,'0');
			int digit=temp.size()-1;
			int j=x.size()-1;
			while(j>=0 && digit>=0)
			{
				int no=x[j]-'0';
				if(no%2!=0)
				{
					temp[digit]='1';
				}
				j--;
				digit--;

			}
			//cout<<x<<" "<<temp<<endl;
			freq[temp]++;
		}
		else if(type=='-')
		{
			string x;
			cin>>x;
			//get the digits which are odd
			string temp;
			temp.append(18,'0');
			int digit=temp.size()-1;
			int j=x.size()-1;
			while(j>=0 && digit>=0)
			{
				int no=x[j]-'0';
				if(no%2!=0)
				{
					temp[digit]='1';
				}
				j--;
				digit--;

			}
			//cout<<x<<" "<<temp<<endl;
			freq[temp]--;
		}
		else
		{ 
			string temp="";
			temp.append(18,'0');
			string bin;
			cin>>bin;
			int i=bin.size()-1;
			int j=temp.size()-1;
			while(i>=0 && j>=0)
			{
				temp[j]=bin[i];
				i--;
				j--;
			}
			cout<<freq[temp]<<endl;

		}
	}

}