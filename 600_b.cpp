#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a,b;
  cin>>a>>b;
  vector<int>a_vec;
  for(int i=0;i<a;i++)
  {
    int x;
    cin>>x;
    a_vec.push_back(x);
  }
  sort(a_vec.begin(),a_vec.end());
  vector<int>b_vec;
  for(int i=0;i<b;i++)
  {
    int x;
    cin>>x;
    b_vec.push_back(x);
  }
  //do binary search
  for(int i=0;i<b;i++)
  {
    int sol;
    sol=upper_bound(a_vec.begin(),a_vec.end(),b_vec[i]) - a_vec.begin();
    cout<<sol<<endl;
  }

}
