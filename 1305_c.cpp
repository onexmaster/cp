#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,m;
  cin>>n>>m;

  vector<int>temp(n);
  for(int i=0;i<n;i++)
    cin>>temp[i];
    if(n>m)
    {
      cout<<0;
      return 0;
    }
    else
    {


  long long ans=1;
  for(int i=0;i<n;i++)
    {
      for(int j=i+1;j<n;j++)
      {
        //cout<<abs(temp[j]-temp[i]);
      ans*=abs(temp[j]-temp[i]);
      ans%=m;
      }

    }
    cout<<ans;
    return 0;
  }
}
