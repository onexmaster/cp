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
int helper(string s, string t)
{
	//out<<s<<" "<<t<<endl;
	int res=INT_MAX;
	for(int i=0;i<=int(s.size())-int(t.size());i++)
	{
		string temp=s.substr(i,int(t.size()));
		int ans=0;
		for(int j=0;j<temp.size();j++)
		{
			if(temp[j]!=t[j])
				ans++;
		}
		res=min(res,ans);
	}
	return res;
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
		int n,k;
		cin>>n>>k;
		string st;
		cin>>st;
		string s1="RGB";
		string s2="GBR";
		string s3="BRG";
		if(k==2)
		{
			if(st.find("RG")!=std::string::npos||st.find("GB")!=std::string::npos||st.find("BR")!=std::string::npos)	
			{
				cout<<0<<endl;
				continue;
			}
			else
			{
				cout<<1<<endl;
				continue;
			}
		}
		else
		{
			//genertae the required strings
			int quo=k/3;
			int rem=k%3;
			int temp=1;
			string s1_temp;
			string s2_temp;
			string s3_temp;
			while(temp<=quo)
			{
				s1_temp+=s1;
				s2_temp+=s2;
				s3_temp+=s3;
				temp++;
			}
			if(rem==1)
			{
				s1_temp+="R";
				s2_temp+="G";
				s3_temp+="B";
			}
			else if(rem==2)
			{
				s1_temp+="RG";
				s2_temp+="GB";
				s3_temp+="BR";
			}
			int ans=INT_MAX;
			int ans1=helper(st,s1_temp);
			int ans2=helper(st,s2_temp);
			int ans3=helper(st,s3_temp);
			ans=min(ans,min(ans1,min(ans2,ans3)));
			cout<<ans<<endl;
		}
	}

}