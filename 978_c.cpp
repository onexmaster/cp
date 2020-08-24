#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
  int n,x;
  cin>>n>>x;
  vector<ll>d;
  for(int i=0;i<n;i++)
  {
    ll r;
    cin>>r;
    d.push_back(r);

  }
  vector<ll>letters;
  for(int i=0;i<x;i++)
  {
    ll r;
    cin>>r;
    letters.push_back(r);

  }
  vector<ll>prefix=d;
  for(int i=1;i<n;i++)
  {
    prefix[i]+=prefix[i-1];
  }
  for(int i=0;i<x;i++)
  {
    auto ans=lower_bound(prefix.begin(),prefix.end(),letters[i]);
    int pos=ans-prefix.begin();
    ll number=d[pos]-(prefix[pos]-letters[i]);
    cout<<pos+1<<" "<<number<<endl;
  }
}
