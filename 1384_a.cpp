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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        vector<string>res(n+1);
        if(v[0]==0)
        {
            res[0]="z";
            res[1]="b";
        }
        else
        {
            string ans;
            ans.append(v[0],'a');
            res[0]=ans;
            res[1]=ans;
        }
        char app='b';
        bool rotate=false;
        for(int i=1;i<n;i++)
        {
            if(v[i]==0)
            {
                char pre_char=res[i][0];
                for(char c='a' ;c<='z';c++)
                {
                    if(c!=pre_char)
                    {
                        res[i+1]=c;
                        break;
                    }
                }
                continue;
            }
            //i need to change i-1 string 
            else if(v[i]>v[i-1])
            {
                string ans=res[i];
                int sz=ans.size();
                ans.append(v[i]-sz,app);
                res[i]=ans;
                res[i+1]=ans;
                if(rotate)
                    app--;
                else
                   app++;
                if(app>'z')
                {
                    app='x';
                    rotate=true;
                }
                    
            }
            else
            {
                //no need to change any string 
                string ans=res[i];
                res[i+1]=ans.substr(0,v[i]);
            }
            
        }
        for(auto it:res)
            cout<<it<<endl;
    }
return 0;
}