#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t,a;
  cin>>t>>a;
int arr[t][2];
for(int i=0;i<t;i++)
  {
    cin>>arr[i][0]>>arr[i][1];
  }
  double mn=1e9;
  for(int i=0;i<t;i++)
    {
      mn=min(mn,double(arr[i][0])/double(arr[i][1]));
    }
    cout<<fixed<<setprecision(6)<<mn*a;
}
