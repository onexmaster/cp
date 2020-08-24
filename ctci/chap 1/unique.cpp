//Implement an algorithm to dtermine if the string is unique or not

#include<bits/stdc++.h>
using namespace std;

//This fucntion does not use  extra data structure to check the uniqueness of the string
//Time complexity is o(n^2)
//space complexity o(1)
bool unique(string s)
{
  bool flag=false;
  for(int i=0;i<s.size();i++)
  {
    for (int j=i+1;j<s.size();j++)
    {
      if(s[j]==s[i])
      {
        flag=true;
        break;
      }
    }
  }
  if(flag)
    return false;
  return true;
}


//This function uses unordered set to maintain all the unique characters of the string and if the set size and string size is same that means all the characters are unqiue
//Time complexity is O(n)
//Space complexity is O(26)->max
bool is_unique_(string s)
{
  unordered_set<char>st;
  for(auto i : s)
  {
    st.insert(i);
  }
  if(st.size()==s.size())
    return true;

  return false;
}

//This fucntion uses bit manipulation to find uniqueness of the string
//Time complexity is O(n)
//space complexity is O(1)
//Assumptions : Only char from 'a' to 'z' are present -> can be extended for capital letters too
//            : Int are stored in 32 bits
bool bit_is_unique(string s)
{
  //Int an int to keep a track of bits (it can be seen as 0000000000..32 times)
  int checker=0;
  for(int i=0;i<s.size();i++)
  {
    //Find the position
    int pos=s[i]-'a';
  //Check if that bit is set or not in checker  using left shift, (1<<pos) means shift left by 'pos' times
    if((checker & (1<<pos))>0)
      return false;
//Set pos bit as seen
    checker |= 1<<pos;
  }
  return true;
}


int main()
{
  string s="tanuj";
  bool ans=bit_is_unique(s);
  if(ans==0)
    cout<<"False";
  else
    cout<<"True";
}
