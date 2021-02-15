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
	string s;
	cin>>s;
	vector<int>v(t,0);
	if(s[0]=='G')
		v[0]=1;
	else
		v[0]=0;
	for(int i=1;i<t;i++)
	{
		if(s[i]=='G' && s[i-1]=='G')
			v[i]=v[i-1]+1;
		if(s[i]=='G' && s[i-1]=='S')
			v[i]=1;
	}
	for(int i=t-2;i>=0;i--)
	{
		if(v[i]!=0)
			v[i]=max(v[i+1],v[i]);
	}
	int mx=*max_element(v.begin(),v.end());
	//if can swap is >=2 then i can swap the current s with any of the g 
	vector<int>prefix(t,0),suffix(t,0);
	if(s[0]=='G')
		prefix[0]=1;
	for(int i=1;i<t;i++)
	{
		if(s[i]=='G')
			prefix[i]=prefix[i-1]+1;
		else
			prefix[i]=prefix[i-1];
	}
		
	if(s[t-1]=='G')
		suffix[t-1]=1;
	for(int i=t-2;i>=0;i--)
	{
		if(s[i]=='G')
			suffix[i]=suffix[i+1]+1;
		else
			suffix[i]=suffix[i+1];
	}
		

	//print
	 // for(int i=0;i<t;i++)
	 // 	cout<<v[i]<<" ";
	 // cout<<endl;
	 // for(int i=0;i<t;i++)
	 // 	cout<<prefix[i]<<" ";
	 // cout<<endl;
	 // for(int i=0;i<t;i++)
	 // 	cout<<suffix[i]<<" ";
	 // cout<<endl;
	 //print over
	 for(int i=1;i<t-1;i++)
	 {
	 	if(v[i]==0 && v[i-1]!=0 && v[i+1]!=0)
	 	{
	 		//check if we have an extra g to swap beyond the 2 consective seq
	 		bool ok=false;
	 		int look_back=i-v[i-1]-1;
	 		int look_front=i+v[i+1]+1;
	 		//cout<<i<<" "<<look_back<<" "<<look_front<<endl;
	 		if(look_back>=0 && prefix[look_back]>0)
	 			ok=true;
	 		if(look_front<t && suffix[look_front]>0)
	 			ok=true;
	 		if(ok)
	 			mx=max(mx,v[i-1]+v[i+1]+1);
	 		else
	 			mx=max(mx,v[i-1]+v[i+1]);
	 	}
	 	//case 1 GSSGGGG
	 	//if here i replce the first S i get the size of 2 if I replace the second S i get 4
	 	else if(v[i]==0 && v[i-1]!=0)
	 	{
	 		//we are extending the last segment
	 		int look_front=i;
	 		int look_back=i-v[i-1]-1;
	 		bool ok=false;
	 		if(suffix[look_front]>0)
	 			ok=true;
	 		if(look_back>=0 && prefix[look_back]>0)
	 			ok=true;
	 		if(ok)
	 			mx=max(mx,v[i-1]+1);

	 	}
	 	else if(v[i]==0 && v[i+1]!=0)
	 	{
	 		bool ok=false;
	 		int look_front=i+v[i+1]+1;
	 		int look_back=i;
	 		if(prefix[look_back]>0)
	 			ok=true;
	 		if(look_front<t && suffix[look_front]>0)
	 			ok=true;
	 		if(ok)
	 			mx=max(mx,v[i+1]+1);
	 	}
	 }
	 cout<<mx<<endl;

	return 0;

}