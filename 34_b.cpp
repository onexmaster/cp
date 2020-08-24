#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,m;
  cin>>n>>m;
  vector<int>vec;
  for(int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    vec.push_back(x);
  }
  sort(vec.begin(),vec.end());
  int money=0;
  int i=0;
  int max_money=INT_MIN;
  if(vec[0]>=0)
    max_money=0;
  else
  {
    while(m>0 && i<n)
    {
      if(vec[i]<0)
        money+=abs(vec[i]);
      else
        money-=vec[i];
      max_money=max(money,max_money);
      m--;
      i++;
    }
  }
  cout<<max_money;
}
