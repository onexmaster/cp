#include<bits/stdc++.h>
using namespace std;

//Time complexity :O(s1*s2)
//space complexity:O(n)
bool string_rotation(string s1, string s2)
{
  return s1.length()==s2.length() && (s1+s1).find(s2)!=string::npos;
}

//Todo- Implement a rolling hash method for pattern metching or kmp algorithm

int main()
{
  string s1="erbottlewxt";
  string s2="waterbottle";
  //0 means False and 1 means True;
  cout<<string_rotation(s1,s2);
}
