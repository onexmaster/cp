#include<bits/stdc++.h>
using namespace std;
int main()
{
  int rows,cols;
  cin>>rows>>cols;
  char arr[rows][cols];
  bool flag=false;
  for(int i=0;i<rows;i++)
  {
      flag=false;
    for(int j=0;j<cols;j++)
    {
      cin>>arr[i][j];
      if(arr[i][j]=='C' || arr[i][j]=='M' || arr[i][j]=='Y')
        flag=true;
  }
  if(flag)
  {
    cout<<"#Color";
    return 0;
  }

}
if(!flag)
  cout<<"#Black&White";
return 0;
}
