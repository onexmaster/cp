#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  string s;
  cin>>s;
  int count_0=0;
  int count_1=0;
  for(int i=0;i<n;i++)
  {
    if(s[i]=='0')
      count_0++;
    else
      count_1++;
  }
  cout<<(n-(min(count_0,count_1)*2));
}
