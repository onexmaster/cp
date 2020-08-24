#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<pair<int,int>>vec;
  for(int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    vec.push_back(make_pair(x,i));
  }
  sort(vec.begin(),vec.end());
  for(int i=0;i<n;i++)
  {
    cout<<vec[i].first<<" "<<vec[i].second<<endl;
  }
  int max_sum=vec[n].first;
  for(int i=0;i<n-1;i++)
  {
    int curr_sum=0;
    for(int j=i;)
    {
      curr_sum+=vec[i].first;
      i++;
    }
    max_sum=max(curr_sum,max_sum);
    i--;

  }
  cout<<max_sum;
}
