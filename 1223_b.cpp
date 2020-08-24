#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string s,t;
    cin>>s>>t;
    int count=0;
    for(int i=0;i<s.size();i++)
    {
      for(int j=0;j<t.size();j++)
        if(s[i]==t[j])
          count++;
    }
    if(count>0)
      cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
  }
}
