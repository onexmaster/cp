#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  std::vector<int> v;
  for(int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    v.push_back(x);
  }
  sort(v.begin(),v.end());
  int count=0;
  unordered_set<int>st;
  //st.insert(v[0]);
  for(int i=0;i<n;i++)
  {
    if(st.find(v[i])==st.end())
    {
      st.insert(v[i]);
    }
    else
    {
      int j=1;
      while(st.find(v[i]+j)!=st.end())
        j++;
      count+=j;
      st.insert(v[i]+j);
    }
  }
  cout<<count;
}
