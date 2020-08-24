//Take an input string and check wether it is a permutation of any palindrome or not
//Assumptions : considered lower case and upper case letters as different ->can  be changed as required
//To change to lower case use transform(s.begin(), s.end(), s.begin(), ::tolower);
#include<bits/stdc++.h>
using namespace std;

//Time complexity ->O(n)
//Space complexity ->O(58)==onstant
string is_permutation(string s)
{
  //int chars[58]={0};
  vector<int>chars(58,0);
  int  flag=0;
  for(int i=0;i<s.size();i++)
  {
    chars[s[i]-'A']++;
  }
  for(int i=0;i<58;i++)
      cout<<chars[i]<<" ";
  for(int i=0;i<58;i++)
  {
    if(chars[i]!=0 && chars[i]%2!=0)
      flag++;
    if(flag>1)
      return "False";
  }
    return "True";

}

int main()
{
  string s ="tact coa";
  cout<<is_permutation(s);
}
