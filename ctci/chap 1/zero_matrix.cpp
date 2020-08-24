//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

#include<bits/stdc++.h>
using namespace std;
int main()
{
  int row;
  int col;
  vector<vector<int>>matrix;
  cin>>row;
  cin>>col;
  for(int i=0;i<row;i++)
  {
    std::vector<int> temp;
    for(int i=0;i<col;i++)
    {
      int x;
      cin>>x;
      temp.push_back(x);
    }
    matrix.push_back(temp);
  }

  unordered_set<int>rows;
  unordered_set<int>cols;
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col;j++)
    {
      if(matrix[i][j]==0)
      {
        rows.insert(i);
        cols.insert(j);
      }
    }
  }


  //set rows as 0 first
  for(auto it : rows)
  {
    cout<<it<<endl;
    for(int j=0;j<col;j++)
    {
      matrix[it][j]=0;
    }
  }

  //set cols as 0
  for(auto it : cols)
  {
    cout<<it<<endl;
    for(int i=0;i<row;i++)
    {
      matrix[i][it]=0;
    }
  }

  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col;j++)
    {
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }

}
