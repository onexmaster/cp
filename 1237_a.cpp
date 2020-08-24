//Does not work correctly
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int x;
  cin>>x;
  vector<double>vec;
  for(int i=0;i<x;i++)
  {
    double n;
    cin>>n;
    vec.push_back(n);
  }
  int pos_sum=0;
  for(int i=0;i<x;i++)
  {
    if(vec[i]>0)
    {
      vec[i]=floor(vec[i]/2);
      pos_sum+=vec[i];
    }
  }
  //cout<<pos_sum;
  int neg_sum=0;
  for(int i=0;i<x;i++)
  {
    if(vec[i]<0)
    {
      vec[i]=ceil(vec[i]/2);
      neg_sum+=vec[i];
      //cout<<vec[i]<<" ";
    }
  }
  if(pos_sum>abs(neg_sum))
  {
    for(int i=0;i<x;i++)
      if(vec[i]<0)
      {
          vec[i]-=1;
          break;
      }

  }
  //cout<<pos_sum<<" "<<neg_sum;
  int final_sum=0;
  for(int i=0;i<x;i++)
  {
    cout<<vec[i]<<" ";
    final_sum+=vec[i];
  }
  cout<<endl;
  cout<<final_sum;
}
