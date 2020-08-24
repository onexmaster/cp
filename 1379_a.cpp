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
string p="abacaba";
vector<int> z_algo(string s)
{
	string f=p+"$"+s;
	int n=f.size();
	vector<int>z_array(n);
	z_array[0]=0;
	int l,r=0;
	for(int i=1;i<n;i++)
	{
		if(i>r)
		{
			l=r=i;
			while(r<n && f[r-l]==f[r] || (f[r]=='?' && f[r-l]!='$'))
				r++;
			z_array[i]=r-l;
			r--;
		}
		else
		{
			int k=i-l;
			if(z_array[k]<r-i+1)
				z_array[i]=z_array[k];
			else
			{
				l=i;
				while(r<n && f[r-l]==f[r] || (f[r]=='?' && f[r-l]!='$'))
					r++;
				z_array[i]=r-l;
				r--;
			}
		}
	}
	
		
	return z_array;
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
		int a;
		cin>>a;
		string st;
		cin>>st;
		int found=st.find(p);
		if(found!=std::string::npos)
		{
			//if we have only one occurance of p 
			if(st.substr(found+1,st.length()).find(p)==std::string::npos)
			{
				for(int i=0;i<st.size();i++)
				{
					if(st[i]=='?')
						st[i]='z';
				}
				cout<<"YES"<<endl;
				cout<<st<<endl;
				continue;
			}
			else
			{
				cout<<"NO"<<endl;
				continue;
			}

		}
		//if not found then buidl the z_array and check if we can get atleast 1 pattern
		//if yes then print answer and fill the remaining ? with z 
		//if we cannot get any pattern then answer is no
		else
		{
			vector<int>first=z_algo(st);
			//for(int i=0;i<first.size();i++)
			//	cout<<first[i]<<" ";
			bool ok=false;
			for(int i=0;i<first.size();i++)
			if(first[i]==p.size())
			{
				ok=true;
			}
			if(!ok)
			{
				cout<<"NO"<<endl;
				continue;
			}
			else
			{
				bool ok1=false;
				for(int i=0;i<first.size();i++)
				{
					if(first[i]==p.size())
					{
						string st1=st;
						int start=i;
						start-=8;
						int i=0;
						while(i<p.size() && start<st.size())
						{	
							st1[start]=p[i];
							i++;
							start++;
						}
						int found1=st1.find(p);
						if(st1.substr(found1+1).find(p)==std::string::npos)
						{
							ok1=true;
							for(int i=0;i<st1.size();i++)
							{
								if(st1[i]=='?')
									st1[i]='z';
							}
							cout<<"YES"<<endl;
							cout<<st1<<endl;
						}
					}
					if(ok1)
						break;
				}
				if(!ok1)
				{
					cout<<"NO"<<endl;
					continue;
				}	
			}
				
				
			}

		}
	}