#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,l;
  cin>>n>>l;
  vector<int>v(n);
  for(int i=0;i<n;i++)
    cin>>v[i];
  sort(v.begin(),v.end());
  int lo=v[0]-0;
  int hi=l-v[n-1];
  double mx=max(lo,hi);
  for(int i=0;i<n-1;i++)
    mx=max((double(v[i+1])-double(v[i]))/2,mx);
  cout<<fixed<<setprecision(9)<<mx;
}
