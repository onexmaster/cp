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
int solve(string &st,int start, int end, char to_make)
{
	//cout<<start<<" "<<end<<" "<<to_make<<endl;
	if(start==end && st[start]==to_make)
		return 0;
	if(start==end && st[start]!=to_make)
		return 1;
	int mid=(start+end)/2; 
	//calulate the total number of first half chars which are not equal to_make
	int count=0;
	//cout<<mid<<endl;
	for(int i=start;i<=mid;i++)
	{
		if(st[i]!=to_make)
			count++;
	}
	//cout<<count<<endl;
	//get the count to make the next half of string as c+1 good
	int count1=solve(st,mid+1,end,to_make+1);
	int total1=count+count1;


	///////OR find the reverse as well/////
	//make the second c good and make the first half c+1 good
	int count2=0;
	for(int i=mid+1;i<=end;i++)
	{
		if(st[i]!=to_make)
			count2++;
	}
	//get the count to make the first half c+1 good
	int count3=solve(st,start,mid,to_make+1);
	int total2=count2+count3;
	//cout<<count2<<endl;
	return min(total1,total2);
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
	while(t--)
	{
		int n;
		cin>>n;
		string st;
		cin>>st;
		//int n=st.length()-1;
		int ans1=solve(st,0,n-1,'a');
		// reverse(st.begin(),st.end());
		//int ans2=solve(st,0,n-1,'a');
		cout<<ans1<<endl;
	}

}