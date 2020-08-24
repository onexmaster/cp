#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int global_min=INT_MAX;
  for(int i=1;i<n-1;i++)
  {
    int local_min=0;
    for(int j=0;j<n-1;j++)
    {
      local_min=max(local_min,arr[j+1]-arr[j]);
      if(j==i-1)
      local_min=max(local_min,arr[j+2]-arr[j]);
    }

    global_min=min(global_min,local_min);
  }
  cout<<global_min;

}
