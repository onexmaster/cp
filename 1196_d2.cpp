// Created by Tanuj Jain
//Does not work
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
int z_algo(string s, string p,int end)
{
	cout<<p<<" "<<s<<endl;
	string f=p+"$"+s;
	int n=f.size();
	int z_value[n];
	z_value[0]=0;
	int l,r=0;
	for(int i=1;i<n;i++)
	{
		if(i>r)
		{
			l=r=i;
			while(r<n && f[r-l]==f[r])
				r++;
			z_value[i]=r-l;
			r--;
		}
		else
		{
			int k=i-l;
			if(z_value[k]<r-i+1)
				z_value[i]=z_value[k];
			else
			{
				l=i;
				while(r<n && f[r-l]==f[r])
					r++;
				z_value[i]=r-l;
				r--;
			}
		}
	}
	for(int i=0;i<n;i++)
		cout<<z_value[i]<<" ";
	cout<<endl;
	int mx=0;
	int idx=-1;
	int start=p.size();
	for(int i=start;i<n;i++)
	{
		if(mx<z_value[i])
		{
			idx=i;
			mx=z_value[i];
		}
	}
		
	return mx;

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
		if(k==1)
		{
			cout<<0<<endl;
			continue;
		}
		else if(k==2)
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
			string s1="RGB";
			string s2="GBR";
			string s3="BRG";
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
			int val1=z_algo(st,s1_temp,k);
			int val2=z_algo(st,s2_temp,k);
			int val3=z_algo(st,s3_temp,k);
			cout<<val1<<" "<<val2<<" "<<val3<<endl;
			//cout<<ans<<endl;
		}
	}

}