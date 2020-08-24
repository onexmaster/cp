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
	for(int i=1;i<20000000;i++)
	{
		int s=0;
		int n=i;
		while(n)
		{
			s+=n%10;
			n/=10;
		}
		if(s==10)
			t--;
		if(t==0)
		{
			cout<<i<<endl;
			return 0;
		}
	}
	
}