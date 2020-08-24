// Given two strings check if one is the permutation of the other or not
//Assumptions : String contain only upper case and lower case letters and both are considered different

#include<bits/stdc++.h>
using namespace std;
# define no_of_chars 256

//This fucntions sorts the two strings and cheks for their equality
//Time Complexity -(nlogn)
//spcae Complexity-O(1)
string is_permutation(string a , string b)
{
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  if(a==b)
    return "True";
  else
    return "False";
}


//This functions create a vector of size 52 and maps the chartacers present in  one string into the vector and then checks the other string by decreseing the value
//Time complexity- O(size of a/b)
//spcae Complexity- O(52)

string is_permutation_map(string a , string b)
{
  if(a.size()!=b.size())
    return "False";

  int alphabets[no_of_chars];

  for(int i=0;i<a.size();i++)
  {
    //int pos=a[i]-'a';
    alphabets[a[i]]++;
  }
  for(int i=0;i<b.size();i++)
  {
    //int pos=b[i]-'a';
    alphabets[b[i]]--;
  }
  for(int i=0;i<256;i++)
    if(alphabets[i]!=0)
      return "False";
  return "True";

}
int main()
{
  string a="geeks";
  string b="aekgs";
  cout<<is_permutation_map(a,b);
}
