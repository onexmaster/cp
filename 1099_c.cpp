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

   int k;string s;
    cin>>s>>k;
    int n=s.size(),q=0,a=0;
    for(char i:s)if(i=='?')q++;else if(i=='*')a++;
    if(k<n-2*a-2*q){cout<<"Impossible";}
    if(a==0&&k>(n-a-q)){cout<<"Impossible";}
    n-=a+q;
    int r=n-k;
    for(int i=0;i<s.size();i++){
        if(s[i+1]=='?'){
            if(r>0){
                r--;i++;continue;
            }
            else{
                cout<<s[i];
                i++;
                continue;
            }
        }
        else if(s[i+1]=='*'){
            if(r>0){
                r--;i++;continue;
            }
            else if(r==0){
                cout<<s[i];
                i++;
                continue;
            }
            else{
                r*=-1;
                r++;char c=s[i];
                while(r--){
                    cout<<c;
                }
                r=0;
                i++;
                continue;
            }
        }
        else{
            cout<<s[i];
        }
    }
}