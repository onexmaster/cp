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
int knight_moves[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}};
int moves[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int get_max(deque<int>&st)
{
     if(st.size()==2)
        return (abs(*st.begin()-*st.rbegin()));
    //it is always benefical if i stay in the middle and the cows stay around me
    int first=*st.begin();
    int last=*st.rbegin();
    int mid=(first+last)/2;
    auto it=lower_bound(st.begin(),st.end(),mid);
    int val1=*it;
    if(it!=st.begin());
    it--;
    int val2=*it;
    int mx1= max(val1 - first, last - val1);
    int mx2=  max(val2 - first, last - val2);
    return min(mx1,mx2);
}
int main()
{
        FIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int l=0;
    int r=0;
    int temp_k=0;
    deque<int>st;
    int ans=INT_MAX;
    while(r<n)
    {

       while(r<n && temp_k<k+1)
       {
           if(s[r]=='0')
           {
               temp_k++;
              st.push_back(r);  
           }
           r++;
          
       }
       //once we reach here we will have k+1 rooms and the set holds the all the positions of the room
       //get_max will return the max distance between the my room and the furthemost cow room
        if(temp_k==k+1)
        {
            ans=min(ans,get_max(st));
        }
            
        while(l<n && temp_k==k+1)
        {
            if(s[l]=='0')
            {
                temp_k--;
               st.pop_front();
            }
                
            l++;
        }
    }
    
    cout<<ans<<endl;
return 0;
}