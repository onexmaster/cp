#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  string s,t;
  cin>>s>>t;
  int cost=0;
  int i=0;
  for(i=0;i<n-1;i++)
  {
    if(s[i]!=t[i] && s[i+1]!=t[i+1] && s[i]!=s[i+1])
    {
      cost++;
      i++;
    }

    else if(s[i]!=t[i])
      cost++;
  }
  if(i==n-1)
    if(s[n-1]!=t[n-1])
      cost++;
  cout<<cost;
}
