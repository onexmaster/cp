#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
{
  int n;
  cin>>n;
  string s,t;
  cin>>s>>t;
  vector<int>mismatch;
  for(int i=0;i<n;i++)
  {
    if(s[i]!=t[i])
      mismatch.push_back(i);
  }
  if(mismatch.size()!=2)
    cout<<"NO"<<endl;
  else
    {
      if(s[mismatch[0]]==s[mismatch[1]] && t[mismatch[0]]==t[mismatch[1]] )
        cout<<"YES"<<endl;
      else
        cout<<"NO"<<endl;
    }
}
}
