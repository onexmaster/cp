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
		int n,s,k;
		cin>>n>>s>>k;
		vector<int>v(k);
		for(int i=0;i<k;i++)
			cin>>v[i];
		unordered_set<int>st(v.begin(),v.end());
		for(int i=0;i<n;i++)
		{
			if(s+i<=n &&st.find(s+i)==st.end())
			{
				cout<<i<<endl;
				break;
			}
			else if(s-i>0 && st.find(s-i)==st.end())
			{
				cout<<i<<endl;
				break;
			}
				
		}
	}
	
}