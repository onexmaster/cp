#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,m;
  cin>>n>>m;
  vector<string>vec;
  for(int i=0;i<n;i++)
  {
    string s;
    cin>>s;
    vec.push_back(s);
  }
  vector<int>marks;
  for(int i=0;i<m;i++)
  {
    int x;
    cin>>x;
    marks.push_back(x);
  }
  int total_marks=0;
  for(int i=0;i<m;i++)
  {
    int chars[26]={};
    for(int j=0;j<n;j++)
    {
      chars[vec[j][i]-'A']++;
    }
    int cur_max=0;
    for(int k=0;k<26;k++)
    {
      cur_max=max(cur_max,chars[k]);
    }
    total_marks+=cur_max*marks[i];

  }
  cout<<total_marks;
}
