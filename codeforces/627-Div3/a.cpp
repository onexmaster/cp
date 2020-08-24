#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int arr[n];
    int max_ele=INT_MIN;
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
      max_ele=max(max_ele,arr[i]);
    }
    bool flag=false;
    for(int i=0;i<n;i++)
    {
      //cout<<max_ele-arr[i];
      if((max_ele-arr[i])&1==1)
        flag=true;
    }
    if(!flag)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;

  }
}
