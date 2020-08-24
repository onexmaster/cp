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
    vector<int>vec;
    for(int i=0;i<n;i++)
    {
      int x;
      cin>>x;
      vec.push_back(x);
    }
    bool flag=false;
    for(int i=0;i<n-1;i++)
    {
      int diff=abs(vec[i]-vec[i+1]);
      if(diff>=2)
      {
        flag=true;
        cout<<"YES"<<endl;
        cout<<i+1<<" "<<i+2<<endl;
        break;
      }
    }
    if(!flag)
      cout<<"NO"<<endl;
  }
}
