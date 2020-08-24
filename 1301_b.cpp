// Created by Tanuj Jain
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
  ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

  #ifndef ONLINE_JUDGE
  freopen("inputf.in","r",stdin);
  freopen("outputf.in","w",stdout);
  #endif

  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int mx=0;
    int mn=1e9;
    std::vector<int> v(n);
    for(int i=0;i<n;i++)
      cin>>v[i];
    for(int i=0;i<n-1;i++)
    {
      if(v[i]==-1 && v[i+1]!=-1)
      {
        mx=max(mx,v[i+1]);
        mn=min(mn,v[i+1]);
      }

    }
    for(int i=1;i<n;i++)
    {
      if(v[i]==-1 && v[i-1]!=-1)
      {
        mx=max(mx,v[i-1]);
        mn=min(mn,v[i-1]);
      }
    }

    int mis=(mx+mn+1)/2;

    for(int i=0;i<n;i++)
      if(v[i]==-1)
        v[i]=mis;
  
    int mx_d=0;
    for(int i=0;i<n-1;i++)
      mx_d=max(mx_d,abs(v[i]-v[i+1]));
    cout<<mx_d<<" "<<mis<<endl;
  }

  
}