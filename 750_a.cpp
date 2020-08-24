#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,k;
  cin>>n>>k;
  int rem_time=240-k;
  int count=0;
  int i=1;
  while(rem_time-5*i>=0 && i<=n)
  {
    rem_time-=5*i;
    count++;
    i++;
  }
  cout<<count;
}
