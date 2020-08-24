#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int vec_sum=0;
  int temp1_sum=0;
  int temp2_sum=0;
  for(int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    vec_sum+=x;
  }
for(int i=0;i<n-1;i++)
  {
    int x;
    cin>>x;
    temp1_sum+=x;
  }
  for(int i=0;i<n-2;i++)
    {
      int x;
      cin>>x;
      temp2_sum+=x;
    }
    cout<<vec_sum-temp1_sum<<endl;
    cout<<temp1_sum-temp2_sum<<endl;
}
