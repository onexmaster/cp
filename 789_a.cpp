#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,k;
  cin>>n>>k;
  int a[n];
  for(int i=0;i<n;i++)
      cin>>a[i];
  int days=0;
  for(int i=0;i<n;i++)
  {
      days+=a[i]/k;
      if(a[i]%k!=0)
        days++;
  }
  days= (days+1)/2;
  cout<<days;
}
