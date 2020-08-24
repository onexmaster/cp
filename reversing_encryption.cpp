#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	string st;
	cin>>n;
	cin>>st;
	for(int i=1;i<=n;i++)
	{
		if(n%i==0)
			reverse(st.begin(),st.begin()+i);
	}
	cout<<st;
	return(0);
}
