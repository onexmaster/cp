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
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n,t;
	cin>>n>>t;
	vector<int>v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	for(int i=0;i<n;i++)
		cout<<v[i]<<" ";
	//vector<int>prefix;
	//prefix[0]=v[0];
	//for(int i=1;i<n;i++)
	//	prefix[i]+=v[i-1];
	//for(int i=0;i<n;i++)
	//	cout<<prefix[i]<<" ";
	//cout<<n<<t;
	int l=0;
	int h=v.size()-1;
	int u=-1;
	while(l<=h)

	{
		int m=l+(h-l)/2;

	}
}