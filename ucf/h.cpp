#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,h,v;
  cin>>n>>h>>v;
  int max_cake=0;
  int a=max(h,n-h);
  int b=max(v,n-v);
  max_cake=a*b*4;
  cout<<max_cake;
}
