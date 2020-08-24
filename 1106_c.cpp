#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<int>vec;
  for(int i=0;i<n;i++)
    {
      int c;
      cin>>c;
      vec.push_back(c);
    }
    sort(vec.begin(),vec.end());
    int low=0;
    int high=n-1;
    long long sum=0;
    while(low<high)
    {
      sum+=(vec[low]+vec[high])*(vec[low]+vec[high]);
      low++;
      high--;
    }
    cout<<sum;
}
