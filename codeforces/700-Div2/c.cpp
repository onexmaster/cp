// Created by Tanuj Jain
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
# define M_PI           3.14159265358979323846  /* pi */
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int INF = 0x3f3f3f3f;
int moves[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int localMinima(int left, int right, int n)
{
    int mid = left + (right - left)/2;
    int prev=mid-1;
    int next=mid+1;
    int val1,val2,val3;
    cout<<"? prev";
    fflush(stdout);
    cin>>val1;
    cout<<"? mid";
    fflush(stdout);
    cin>>val2;
    cout<<"? next";
    fflush(stdout);
    cin>>val3;
   if ((mid == 0 || val1 > val2) && (mid == n-1 || val3 > val2))
      return mid;
   else if (mid > 0 && val1 < val2)
      return localMinima( left, (mid -1), n);
   return localMinima((mid + 1), right, n);}
int main()
{
        FIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    int l=0;
    int r=n-1;
    int local_minima=localMinima(0,n-1,n);
    cout<<"! "<<to_string(local_minima)<<endl;;
    fflush(stdout);
return 0;
}