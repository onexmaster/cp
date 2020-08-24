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

int n;
 
long long x[100007], h[100007];
long long last=-1000000007;
int wyn;
 
int main()
{
  ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

  #ifndef ONLINE_JUDGE
  freopen("inputf.in","r",stdin);
  freopen("outputf.in","w",stdout);
  #endif
  
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld%lld", &x[i], &h[i]);
    }
    for (int i=1; i<n; i++)
    {
        if (x[i]-h[i]>last)
        {
            wyn++;
            last=x[i];
            continue;
        }
        if (x[i]+h[i]<x[i+1])
        {
            wyn++;
            last=x[i]+h[i];
            continue;
        }
        last=x[i];
    }
    wyn++;
    printf("%d", wyn);
    return 0;
}