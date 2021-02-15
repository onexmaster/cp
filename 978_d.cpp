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
	for(int i=0;i<t;i++)
		cin>>v[i];
	if(t<=2)
	{
		cout<<0;
		return 0;
	}
	int a=v[0];
	int b=v[1];
	int min_changes=INT_MAX;
	bool global_ok=false;
	for(int i=-1;i<=1;i++)
	{
		v[0]=a+i;
		for(int j=-1;j<=1;j++)
		{
			//v[0]=a+i;
			v[1]=b+j;
			int diff=v[1]-v[0];
			int changes=0;
			if(i!=0)
				changes++;
			if(j!=0)
				changes++;
			bool ok=true;
			//cout<<"HERE"<<endl;
			//cout<<v[0]<<" "<<v[1]<<" "<<diff<<endl;
			//the i'th term for the above sequcne shoudl be a+(n-1)*d;
			//if the present term is not equal to the above term and if the change re
			//is greater than 1
			for(int k=2;k<t;k++)
			{
				int should=v[0]+(k)*(diff);
				//cout<<should<<" ";
				//temp is should-have
				int temp_diff=abs(should-v[k]);
				//cout<<should<<" "<<temp_diff<<" ";
				if(abs(temp_diff)>1)
				{
					ok=false;
					break;
				}
				if(abs(temp_diff)==1)
				{
					changes++;
				}
			}
			//cout<<endl;
			if(ok)
			{
				
				//cout<<v[0]<<" "<<v[1]<<" "<<changes<<endl;
				global_ok=true;
				min_changes=min(min_changes,changes);
			}

		}
	}
	if(!global_ok)
		cout<<-1;
	else
		cout<<min_changes;
	return 0;

}