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
    int n,q;
    cin>>n>>q;
    vector<ll>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    //use stack to get next_larger and prev_larger
    //get next larger
    vector<ll>next_greater(n,-1);
    stack<pii>st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && st.top().first<v[i])
        {
            pii curr=st.top();
            st.pop();
            int idx=curr.second;
            next_greater[idx]=i-idx-1;
        }
        st.push({v[i],i});
    }
    while(!st.empty())
    {
        pii curr=st.top();
        st.pop();
        int idx=curr.second;
        next_greater[idx]=(n-idx-1);
    }
    // for(int i=0;i<n;i++)
    //     cout<<next_greater[i]<<" ";
    // cout<<endl;
    //for prev_larger
    vector<ll>prev_greater(n,-1);
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && st.top().first<v[i])
        {
            pii curr=st.top();
            st.pop();
            int idx=curr.second;
            prev_greater[idx]=idx-i-1;
        }
        st.push({v[i],i});
    }
    while(!st.empty())
    {
        pii curr=st.top();
        st.pop();
        int idx=curr.second;
        prev_greater[idx]=(idx);
    }
    // for(int i=0;i<n;i++)
    //     cout<<prev_greater[i]<<" ";
    // cout<<endl;
    

    //for subtask 1
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int curr;
            cin>>curr;
            curr--;
            int count=1;
            //look to the right
            count+=next_greater[curr];
            count+=prev_greater[curr];
            cout<<count<<endl;
        }
        else if(type==2)
        {
            ll curr,val;
            cin>>curr>>val;
            curr--;
            v[curr]=val;
        }
        else if(type==3)
        {
            ll start,end,val;
            cin>>start>>end>>val;
            start--;
            end--;
            for(int i=start;i<=end;i++)
                v[i]=val;

        }
    }
    


return 0;
}