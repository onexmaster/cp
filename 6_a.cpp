#include<bits/stdc++.h>
using namespace std;
int main()
{
  vector<int>vec;
  for(int i=0;i<4;i++)
  {
    int x;
    cin>>x;
    vec.push_back(x);
  }
  sort(vec.begin(),vec.end());
  if(vec[1]+vec[2]>vec[3] || vec[0]+vec[1]>vec[2])
    cout<<"TRIANGLE";
  else if(vec[1]+vec[2]==vec[3] || vec[0]+vec[1]==vec[2])
    cout<<"SEGMENT";
  else
    cout<<"IMPOSSIBLE";
}
