#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int low=0;
  int high=n-1;
  ll low_sum=arr[0];
  ll high_sum=arr[n-1];
  ll max_sum=INT_MIN;
  bool flag=false;
  while(low<high)
  {
    if(low_sum<high_sum)
    {
      low++;
      low_sum+=arr[low];
    }
    else if(low_sum>high_sum)
    {
      high--;
      high_sum+=arr[high];
    }
    else
      {
        max_sum=max(max_sum,low_sum);
        low++;
        high--;
        low_sum+=arr[low];
        high_sum+=arr[high];
        flag=true;
      }
  }
  if(!flag)
    cout<<0;
  else
    cout<<max_sum;
}
