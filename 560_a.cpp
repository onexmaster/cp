#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<int>vec;
  for(int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    vec.push_back(x);
  }
  sort(vec.begin(),vec.end());
  if(vec[0]!=1)
    cout<<1;
  else
    cout<<-1;
}
