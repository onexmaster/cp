#include<bits/stdc++.h>
typedef long long ll
using namespace std;
int main()
{
  ll n;
  cin>>n;
  ll arr[n];
  ll total=0;
  for(ll i=0;i<n;i++)
  {
    cin>>arr[i];
    total+=arr[i];
  }
  ll sum=0;
  for(ll i=0;i<n;i++)
  {
    sum+=arr[i];
    if(2*sum>=total)
    {
      cout<<i+1;
      return 0;
    }
  }
  cout<<-1;
}
