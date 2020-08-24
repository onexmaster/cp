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

	ll n,k;
	cin>>n>>k;
	ll l=0;
	ll h=n;
	ll lb=-1;
	while(l<=h)
	{
		ll m=l+(h-l)/2;
		if((m*(m+1))/2-(n-m)<=k)
		{
			lb=m;
			l=m+1;
		}
		else
			h=m-1;

	}
	cout<<n-lb<<endl;
	return 0;
	
}