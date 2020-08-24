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

	int n,t;
	cin>>n>>t;
	vector<int>v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	//solve it using two pointers
	int pt=0;
	int h=0;
	int mx=0;
	for(int l=0;l<n;l++)
	{
		while(h<n && pt+v[h]<=t)
		{
			pt+=v[h];
			h++;
		}
		mx=max(mx,h-l);
		pt-=v[l];
	}
	cout<<mx<<endl;

}