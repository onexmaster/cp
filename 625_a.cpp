#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int arr1[n];
  int arr2[n];
  for(int i=0;i<n;i++)
    cin>>arr1[i];
  for(int i=0;i<n;i++)
    cin>>arr2[i];
  int count1=0;
  int count2=0;
  for(int i=0;i<n;i++)
  {
    if(arr1[i]==arr2[i])
      continue;
    if(arr1[i]==1)
      count1++;
    else if(arr2[i]==1)
      count2++;
  }
  if(count1==0)
    cout<<-1;
  else
  cout<<(count2/count1) +1;
}
