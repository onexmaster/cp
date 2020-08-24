#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
  ll n,x;
  cin>>n>>x;
  vector<ll>vec;
  for(int i=0;i<n;i++)
  {
    ll a;
    cin>>a;
    vec.push_back(a);
  }
  sort(vec.begin(),vec.end());
  ll ans=0;
  for(int i=0;i<n;i++)
  {
    if(x>0)
    {
      ans+=vec[i]*x;
      x--;
    }
    else
    {
      ans+=vec[i];
    }

  }
  cout<<ans;
}
