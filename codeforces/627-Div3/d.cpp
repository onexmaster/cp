#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
  ll n;
  //ll te[n],su[n];
  cin>>n;
  vector<ll>te;
  vector<ll>su;
  ll count=0;
  for(ll i=0;i<n;i++)
  {
    ll x;
    cin>>x;
    te.push_back(x);
  }
  for(ll i=0;i<n;i++)
  {
    ll x;
    cin>>x;
    su.push_back(x);
  }
vector<ll>diff;
for(ll i=0;i<n;i++)
{
  if(te[i]>su[i])
    diff.push_back(te[i]-su[i]);
}
sort(diff.begin(),diff.end());
if(diff.size()<1 || diff[diff.size()-1]==0)
{
  cout<<0;
  return 0;
}

for(ll i=0;i<n;i++)
{
  if(te[i]==su[i])
    count+=diff.size();
  else
  {
    ll dif=abs(su[i]-te[i]);
    ll flag=lower_bound(diff.begin(),diff.end(),dif)-diff.begin();
    count+=(diff.size()-flag);
  }
}
cout<<count;
return 0;
}
