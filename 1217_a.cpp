#include<bits/stdc++.h>
using namespace std;
int str,inte,expr;
void solve()
{
  cin>>str>>inte>>expr;
  if(expr==0 && str>inte)
  {
      cout<<1<<endl;
      return;
  }
  else if(expr==0 && str<inte)
  {
    cout<<0<<endl;
    return;
  }
  else
  {

  int low=0;
  int high=expr;
  while(low<=high)
  {
    int mid=low+(high-low)/2;
    if(str+mid >inte+(expr-mid))
      high=mid-1;
    else
      low=mid+1;
  }
  cout<<expr-low+1<<endl;
  return;
}
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    solve();
  }
}
