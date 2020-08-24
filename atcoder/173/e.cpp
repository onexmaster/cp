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
const int INF = 0x3f3f3f3f;
int knight_moves[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}};
int moves[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
const int mod=1e9+7;
ll maxProductSubarrayOfSizeK(ll A[], int n, int k) 
{ 
   
    sort(A, A + n); 
  
    
    ll product = 1LL; 
  
    
    // k is odd then max product will be 0 
    if (A[n - 1] == 0 && (k & 1)) 
        return 0LL; 
  
    if (A[n - 1] <= 0 && (k & 1)) { 
        for (int i = n - 1; i >= n - k; i--) 
         product= ((product %mod)*(A[i]%mod))%mod; 
        if(product<0)
        	return (product+mod)%mod; 
    } 
  
    
    int i = 0; 
  

    int j = n - 1; 
  

    if (k & 1) { 
        product= ((product %mod)*(A[j]%mod))%mod; 
        j--; 
        k--; 
    } 
  
   
    k >>= 1; 
  
   
    for (int itr = 0; itr < k; itr++) { 
  
        
        int left_product = ((A[i]%mod) * (A[i + 1]%mod))%mod; 
  
         int right_product = ((A[j]%mod) * (A[j - 1]%mod))%mod; 
  
      
        if (left_product > right_product) { 
            product =((product%mod) * (left_product%mod))%mod; 
            i += 2; 
        } 
        else { 
            product =((product%mod) * (right_product%mod)) %mod; 
            j -= 2; 
        } 
    } 
  	if(product<0)
  		 product=(product+mod)%mod;
    return product; 
} 
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	int n,k;
	cin>>n>>k;
	ll A[n];
	for(int i=0;i<n;i++)
		cin>>A[i];
	 cout << maxProductSubarrayOfSizeK(A, n, k); 
}