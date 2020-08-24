#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  if(n%2!=0)
    cout<<"Either"<<endl;
  else
  {
    if(n==2 || n==6 || n==10)
      cout<<"Odd";
    else
      cout<<"Even";
  }
}
