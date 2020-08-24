#include<bits/stdc++.h>
using namespace std;

int main()
{
 string s;
 cin>>s;
 int a =0;
 int b =0;
 for(int i=0;i<s.size()-1;i+=2)
 {
   if(s[i]=='A')
    a+=s[i+1]-'0';
  else
    b+=s[i+1]-'0';
 }
 if(a>b && a-b>=2)
  cout<<"A";
else if(a<b && b-a>=2)
  cout<<"B";
}
