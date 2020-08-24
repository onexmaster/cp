#include<bits/stdc++.h>
using namespace std;
int main()
{
  string first;
  string second;
  string convert;
  cin>>first>>second>>convert;
  unordered_map<char,char>mp;
  for(int i=0;i<first.size();i++)
  {
    mp.insert(make_pair(first[i],second[i]));
  }
  string result;
  for(int i=0;i<convert.size();i++)
  {
    if(isupper(convert[i]))
    {
      result+=toupper((mp[tolower(convert[i])]));
    }
    else if(isdigit(convert[i]))
      result+=convert[i];
    else
      result+=mp[convert[i]];
  }
  cout<<result;
}
