#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int x;
    cin>>x;
    vector<int>temp(x);
    for(int i=0;i<x;i++)
      cin>>temp[i];
    set<int>st(temp.begin(),temp.end());
    cout<<st.size()<<endl;
  }
}
