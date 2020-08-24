#include<bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  #ifndef ONLINE_JUDGE
  freopen("inputf.in","r",stdin);
  freopen("outputf.in","w",stdout);
  #endif

  int n;
  cin>>n;
  vector<int>vec(n);
  for(int i=0;i<n;i++)
    cin>>vec[i];
  int t;
  cin>>t;
  sort(vec.begin(),vec.end());
  while(t--)
  {
    int c;
    cin>>c;
    int l=0;
    int h=vec.size()-1;
    int upper=-1;
    while(l<=h)
    {
      int m=l+(h-l)/2;
      //cout<<m<<endl;
      if(vec[m]<=c)
        {
          upper=m;
          l=m+1;
        }
        else
        {
          h=m-1;
        }
    }
    cout<<upper+1<<endl;

  }
}
