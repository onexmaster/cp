#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
  string s;
  cin>>s;
  int len=s.size();
  int last_digit=int(s[len-1]-'0');
  //bool flag=false;
  for(int i=0;i<len;i++)
  {
    int curr_dig=s[i]-'0';
    if(curr_dig%2==0 && curr_dig<last_digit)
    {
      swap(s[i],s[len-1]);
      cout<<s;
      return 0;
    }
  }
  for(int i=len-2;i>=0;i--)
  {
    int curr_dig=s[i]-'0';
    if(curr_dig%2==0)
    {
      swap(s[i],s[len-1]);
      cout<<s;
      return 0;
    }
  }
   cout<<-1;
   return 0;
}
