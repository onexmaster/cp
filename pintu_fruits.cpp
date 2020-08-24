#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int m,n;
    cin>>n>>m;
    vector<int>fruit_type;
    for(int i=0;i<n;i++)
    {
      int x;
      cin>>x;
      fruit_type.push_back(x);
    }
    vector<int>basket_cost;
    for(int i=0;i<n;i++)
    {
      int x;
      cin>>x;
      basket_cost.push_back(x);
    }
    vector<int>sum
    for(int i=0;i<n;i++)
    {
      sum[fruit_type[i]-1]+=basket_cost[i];
    }
    int min_cost=INT_MAX;
    for(int i=0;i<m;i++)
    {
      if(sum[i]!=0)
        min_cost=min(min_cost,sum[i]);
    }
    cout<<
  }
}
