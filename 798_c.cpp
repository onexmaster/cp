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
int main()
{
        FIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    //odd + odd  ->even
    //odd - odd  ->even
    //odd + even -> odd
    //odd - even -> odd

    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int gcd=v[0];
    for(int i=1;i<n;i++)
        gcd=__gcd(gcd,v[i]);
    if(gcd>1)
        cout<<"YES \n"<<0<<endl;
    else
    {
        int moves=0;
        vector<bool>is_even(n,false);
        for(int i=0;i<n-1;i++)
        {
            //if number is odd
            //use the i+1 number to change it to even and it also changes the i+1 to even  
            if(v[i]%2 && !is_even[i])
            {
                //odd odd combo
                if(v[i+1]%2)
                {
                    moves++;
                    is_even[i+1]=true;
                }
                else
                {
                    moves+=2;
                    is_even[i+1]=true;
                }
                
            }
        }
        //for the last ele
        if(v[n-1]%2 && !is_even[n-1])
        {
            //we will have an even odd pair in the end
            moves+=2;
        }
        cout<<"YES \n"<<moves<<endl;
    }
    
return 0;
}