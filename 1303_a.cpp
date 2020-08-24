#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string s;
    cin>>s;
    int count1=0;
    int first_index=s.find_first_of('1');
    int last_index=s.find_last_of('1');
    while(first_index<last_index)
    {
      if(s[first_index]=='0')
      {
        count1++;
        first_index++;
      }
      else
        first_index++;


    }

    cout<<count1<<endl;
  }
}
