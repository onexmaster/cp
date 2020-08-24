#include<bits/stdc++.h>
using namespace std;

//This method compresses the string using two pointers
//Time complexity:O(n)
//Space complexity:O(1)
string compression(string a)
{
  string res="";
  //vector<int>count(26,0);
  int string_length=a.size();
  int i=0;
  while(i<a.size())
  {
    //cout<<i;
    int j=i+1;
    while(a[j]==a[i])
      j++;
    res+=a[i];
    res+=to_string(j-i);
    i=j;
  }
  return res;
}
int main()
{
  string a="aaabcccccaa";
  cout<<compression(a);
}
