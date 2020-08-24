#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string a;
    string b;
    string c;
    cin>>a;
    cin>>b;
    cin>>c;
    bool flag=false;
    for(int i=0;i<a.size();i++)
    {
      if(a[i]!=c[i] && b[i]!=c[i])
      {
          flag=true;
          break;
      }

    }
    if(!flag)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
}
