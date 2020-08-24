#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<long long>vec;
  for(int i=0;i<n;i++)
  {
    long x;
    cin>>x;
    vec.push_back(x);
  }
  vector<long long>vec_sorted;
  vec_sorted=vec;
  sort(vec_sorted.begin(),vec_sorted.end());

  //find prefix sum for both arrays

  for(int i=1;i<n;i++)
  {
    vec[i]+=vec[i-1];
  }

  for(int i=1;i<n;i++)
  {
    vec_sorted[i]+=vec_sorted[i-1];
  }

  vec.insert(vec.begin(),0);
  vec_sorted.insert(vec_sorted.begin(),0);
  int x;
  cin>>x;
  while(x--)
  {
    int t;
    int l;
    int r;
    cin>>t>>l>>r;
    if(t==2)
    {
      cout<<vec_sorted[r]-vec_sorted[l-1]<<endl;
    }
    else
      cout<<vec[r]-vec[l-1]<<endl;
  }
}
