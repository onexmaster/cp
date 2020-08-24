#include<bits/stdc++.h>
using namespace std;
int main()
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
  sort(vec.begin(),vec.end());
  for(int i=n-2;i>=0;i--)
  {
    for(int j=0;j<i;j++)
    {
      //cout<<vec[i]<<" "<<vec[j]<<" "<<vec[i]+vec[j]<<" "<<vec[i+1]<<endl;
      if(vec[i]+vec[j]>vec[i+1])
      {
        cout<<"YES";
        return 0;
      }
    }
  }
  cout<<"NO";
}
