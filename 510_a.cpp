#include<bits/stdc++.h>
using namespace std;
int main()
{
  int rows,cols;
  cin>>rows>>cols;
  char arr[rows][cols];
  for(int i=0;i<rows;i+=2)
{
    for(int j=0;j<cols;j++)
    {
      arr[i][j]='#';
    }
}


for(int i=1;i<rows;i+=4)
{
  arr[i][cols-1]='#';
  for(int j=0;j<cols-1;j++)
    arr[i][j]='.';
}

for(int i=3;i<rows;i+=4)
{
  arr[i][0]='#';
  for(int j=1;j<cols;j++)
    arr[i][j]='.';
}
    //print array
    for(int i=0;i<rows;i++)
    {
      for(int j=0;j<cols;j++)
        cout<<arr[i][j];
      cout<<endl;
    }
}
