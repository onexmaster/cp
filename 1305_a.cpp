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
    vector<int>temp1(x);
    vector<int>temp2(x);
    for(int i=0;i<x;i++)
      cin>>temp1[i];
    for(int i=0;i<x;i++)
      cin>>temp2[i];
    sort(temp1.begin(),temp1.end());
    sort(temp2.begin(),temp2.end());
    for(int i=0;i<x;i++)
      cout<<temp1[i]<<" ";
    cout<<endl;
    for(int i=0;i<x;i++)
      cout<<temp2[i]<<" ";
    cout<<endl;
  }
}
