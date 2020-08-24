#include<bits/stdc++.h>
using namespace std;
int main()
{
  int arr[26]={};
  string s;
  cin>>s;
  for(int i=0;i<s.size();i++)
    arr[s[i]-'a']++;
  int count=0;
  for(int i=0;i<26;i++)
  {
    cout<<arr[i]<<" ";
    if(arr[i]==0)
      count++;
  }
cout<<endl;
cout<<count;
}
