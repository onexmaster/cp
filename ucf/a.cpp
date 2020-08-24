#include<bits.stdc++.h>
using namespace std;

int num_rev(int num)
{
  int rev_num = 0;
    while(num > 0)
    {
        rev_num = rev_num*10 + num%10;
        num = num/10;
    }
    return rev_num;
}
int main()
{
  int n,s;
  cin>>n>>s;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  unordered_set<int>st;
  for(int i=0;i<n;i++)
  {
    int num=arr[i];
    if(st.find(num)==st.end())
    {
      st.insert(arr[i]);
      int num_rev=rev(num);
      st.insert(num);
    }


  }
}
