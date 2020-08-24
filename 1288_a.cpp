#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;

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
		int n,d;
		cin>>n>>d;
		bool flag=false;
		if(d<=n)
		{
			flag=true;
			cout<<"YES"<<endl;
		}
		if(!flag)
			{
				int l=0;
				int h=n-1;
				while(l<h)
				{
					int m=l+(h-l)/2;
					int s_up=ceil(double(d)/double(m+1));
					if(s_up+m <=n)
					{
						cout<<"YES"<<endl;
						flag=true;
						break;
					}
					else
					{
						l=m+1;
					}
				}

			}
			if(!flag)
				cout<<"NO"<<endl;
		
	}
}