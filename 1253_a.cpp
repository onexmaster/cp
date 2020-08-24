//Not working correctly 
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  while(n--)
  {
    int x;
    cin>>x;
    int arr1[x];
    int arr2[x];
    for(int i=0;i<x;i++)
      cin>>arr1[i];
    for(int i=0;i<x;i++)
        cin>>arr2[i];
    for(int i=0;i<x;i++)
      arr1[i]=arr2[i]-arr1[i];
    unordered_set<int>st;
    int low=INT_MAX;
    int high=INT_MIN;
    for(int i=0;i<x;i++)
      if(arr1[i]!=0 && st.find(arr1[i])==st.end())
        st.insert(arr1[i]);
    if(st.size()==1)
    {
      auto x=st.begin();
      if(*x>0)
        cout<<"YES"<<endl;
      else
        cout<<"NO"<<endl;
    }

    else if(st.empty())
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
}
