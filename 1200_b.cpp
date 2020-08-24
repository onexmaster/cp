#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,m,k;
    cin>>n>>m>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    int val;
    int i;
    for( i=0;i<n-1;i++)
    {
      val=max(0,arr[i+1]-k);
      arr[i]+=m;
      if(arr[i]<val)
        break;
      m=arr[i]-val;
    }
    if(i==n-1)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
}
