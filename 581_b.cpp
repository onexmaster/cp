#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<ll>vec;
  for(int i=0;i<n;i++)
  {
    ll x;
    cin>>x;
    vec.push_back(x);
  }
  vector<ll>ans(n+1);
  ans[n-1]=0;
  ll max_val=vec[n-1];
  for(int i=n-2;i>=0;i--)
  {
    if(vec[i]<=max_val)
      ans[i]=max_val-vec[i]+1;
    else
    {
      ans[i]=0;
      max_val=vec[i];
    }
  }
  for(int i=0;i<n;i++)
    cout<<ans[i]<<" ";
}
