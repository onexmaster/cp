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

vector<int>z_values(string text, string pattern)
{
	string f=pattern+"$"+text;
	int n=f.size();
	vector<int>z(n);
	z[0]=0;
	int l=0;
	int r=0;
	for(int i=1;i<n;i++)
	{
		if(i>r)
		{
			l=r=i;
			while(r<n && f[r-l]==f[r])
				r++;
			z[i]=r-l;
			r--;
		}
		else
		{
			int k=i-l;
			if(z[k]<r-i+1)
				z[i]=z[k];
			else
			{
				l=i;
				while(r<n && f[r-l]==f[r])
					r++;
				z[i]=r-l;
				r--;
			}
		}
	}	
return z;
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

	string st;
	cin>>st;
	vector<int>z1=(z_values(st,"AB"));
	vector<int>z2=(z_values(st,"BA"));
	bool ok=true;
	//find the first ab and last ab
	int f_ab=INT_MAX;
	int f_ba=INT_MAX;
	int l_ba=-1;
	int l_ab=-1;
	bool ab=false;
	bool ba=false;
	for(int i=0;i<z1.size();i++)
	{

		if(z1[i]==2)
		{
			ab=true;
			f_ab=min(f_ab,i);
			l_ab=max(l_ab,i);
		}
	}
	//find first ba and last ba
		for(int i=0;i<z2.size();i++)
		{
			if(z2[i]==2)
			{
				ba=true;
				f_ba=min(f_ba,i);
				l_ba=max(l_ba,i);
			}
		}
		//cout<<f_ab<<" "<<l_ab<<endl;
		//cout<<f_ba<<" "<<l_ba<<endl;
		//cout<<l_ba-f_ab<<endl;
		//cout<<l_ab-f_ba<<endl;

		if(abs(l_ba-f_ab)==1 && abs(l_ab-f_ba)==1)
			cout<<"NO";
		else if((ab==true && ba==false) || (ab==false && ba==true) || (ab==false && ba==false))
			cout<<"NO";
		else 
			cout<<"YES";
	
}