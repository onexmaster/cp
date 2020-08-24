#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repA(i,a,b) for(int i=a;i<=b;i++)
#define repD(i,b,a) for(int i=b;i>=a;i--)
#define fill(a,val) memset(a,val,sizeof(a))
#define f first
#define s second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll moves[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("inputf.in","r",stdin);
    freopen("outputf.in","w",stdout);
    #endif
    ll row,col,k;
    cin>>row>>col>>k;
    vector<vector<char>>grid(row,vector<char>(col));
    ll x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    x1--;
    y1--;
    x2--;
    y2--;
    rep(i,0,row)
    {
        rep(j,0,col)
        cin>>grid[i][j];
    }
    vector<vector<ll>>dist(row,vector<ll>(col,1e3));
    dist[x1][y1]=0;
    queue<pair<ll,ll>>q;
    q.push({x1,y1});
    while(!q.empty())
    {
        ll curx=q.front().f;
        ll cury=q.front().s;
        q.pop();
        rep(i,0,4)
        {
            repA(j,1,k)
            {
                ll nx=curx+moves[i][0]*j;
                ll ny=cury+moves[i][1]*j;
                 if(nx>=0 && nx<row && ny>=0 && ny<col && grid[nx][ny]=='.' && (dist[nx][ny]==1e3 || dist[nx][ny]==dist[curx][cury]+1))
                {
                    if(dist[nx][ny]==1e3)
                    {
                        dist[nx][ny]=1+dist[curx][cury];
                        q.push({nx,ny});

                    }
                }
                else
                break;
            }
        }
    }
    for(ll i=0;i<row;i++)
    {
        for(ll j=0;j<col;j++)
            cout<<dist[i][j]<<" ";
        cout<<endl;
    }
    if(dist[x2][y2]>=LLONG_MAX)
    cout<<-1<<endl;
    else
    cout<<dist[x2][y2]<<endl;
}