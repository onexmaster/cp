#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
      vector<long long>vec;
      for(int i=0;i<3;i++)
        {
          long long x;
          cin>>x;
          vec.push_back(x);
        }
        sort(vec.begin(),vec.end());
        vec[2]-=vec[1]-vec[0];
        //cout<<vec[2]<<endl;
        cout<<(vec[1]+(vec[2]/2))<<endl;
    }
}
