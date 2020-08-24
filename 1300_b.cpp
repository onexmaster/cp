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
    vector<int>temp;
    for(int i=0;i<2*n;i++)
    {
      int x;
      cin>>x;
      temp.push_back(x);
    }
    sort(temp.begin(),temp.end());
    cout<<temp[n]-temp[n-1]<<endl;
  }
}
