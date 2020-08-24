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

    int n;
    cin>>n;
    vector<int>a(n);
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
    }
  	
    int l[n];
    int r[n+1];
    l[0]=1;
    for(int i=1;i<n;i++)
    {
    	if(a[i]>a[i-1])
    		l[i]=l[i-1]+1;
    	else
    		l[i]=1;
    }
    r[n]=0;
    for(int i=n-1;i>=0;i--)
    {
    	if(a[i+1]>a[i])
    		r[i]=r[i+1]+1;
    	else
    		r[i]=1;
    }
    //for(int i=0;i<n;i++)
    //	cout<<l[i]<<" ";
    //cout<<endl;
    //for(int i=0;i<n;i++)
    //	cout<<r[i]<<" ";
   int ans=0;
    for(int i=0;i<n;i++)
    	ans=max(ans,max(l[i],r[i]));
    for(int i=1;i<n-1;i++)
    	if(a[i-1]<a[i+1])
    		ans=max(ans,l[i-1]+r[i+1]);
    cout<<ans;
    }