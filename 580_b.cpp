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

	ll n,d;
	cin>>n>>d;
	vector<vector<ll>>vec(n,vector<ll>(2));
	for(ll i=0;i<n;i++)
		cin>>vec[i][0]>>vec[i][1];
	sort(vec.begin(),vec.end());
	ll l=0,h=0; 
	ll mx=0;
	ll ff=0;
	for( ;l<n;l++)
	{
		while(h<n && vec[h][0]-vec[l][0] < d) 
		{
			ff+=vec[h][1];
			h++;
			
		}
		mx=max(mx,ff);
		ff-=vec[l][1];
	}
	cout<<mx;

	
}