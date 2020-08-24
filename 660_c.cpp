//TO print the array values
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

	int n,k;
	cin>>n>>k;
	vector<int>v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	vector<int>res;
	int cnt=0;
	int l=0;
	int r=0;
	int mx=0;
	while(r<n)
	{
		if(v[r]!=1)
		{

			cnt++;
			v[r]=0;
		}
		while(cnt>k)
		{
			if(v[l]!=1)
			{
				v[l]=0;
				cnt--;
			}
			l++;
		}
		if(r-l+1>mx)
		{
			mx=r-l+1;
			res=v;
		}
		r++;
	}
	for(int i=0;i<n;i++)
		cout<<res[i]<<" ";
	cout<<endl;
	cout<<mx;
	
}