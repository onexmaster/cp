//Fix for 1 case

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
    string s;
    cin>>s;
    int max_right=INT_MIN;
    int high=s.size()-1;
    int end=s.size();
    bool flag=false;
    while(high>=0)
    {
      if(s[high]=='R')
        {
          flag=true;
          max_right=max(max_right,end-high);
          end=high;
          high--;
        }
      else
        high--;
    }
    if(flag)
    {
      int low=0;
      while(s[low]!='R')
        low++;
      max_right=max(max_right,low+1);
      cout<<max_right<<endl;
    }
    else
      cout<<s.size()+1<<endl;

     }
   }
