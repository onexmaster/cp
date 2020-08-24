#include<bits/stdc++.h>
using namespace std;
int main()
{
  int c;
  cin>>c;
  string s;
  cin>>s;
  if(s.size()==1)
  {
    cout<<"YES";
    return 0;
  }

  vector<int>temp(26,0);
  for(int i=0;i<s.size();i++)
  {
    temp[s[i]-'a']++;
  }
  bool flag=false;
  for(int i=0;i<26;i++)
    if(temp[i]>=2)
      flag=true;
  if(flag)
    cout<<"YES";
  else
    cout<<"NO";
}
