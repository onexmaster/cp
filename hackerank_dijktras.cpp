#include <bits/stdc++.h>
using namespace std;
unordered_map<int,vector<pair<int,int>>>ada;
int dist[3010];
void dijktras(int s)
{
    for(int i=1;i<=3010;i++)
        dist[i]=INT_MAX;
    dist[s]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push({0,s});
    while(!pq.empty())
    {
        int curr_cost=pq.top().first;
        int curr=pq.top().second;
        pq.pop();
        if(dist[curr]!=curr_cost)
            continue;
        for(auto edges:ada[curr])
        {
            //cout<<curr<<" "<<edges.first<<" "<<curr_cost+edges.second<<endl;
            if(dist[edges.first]>curr_cost+edges.second)
            {
                dist[edges.first]=curr_cost+edges.second;
                pq.push({dist[edges.first],edges.first});
            }
        }
    }
}
vector<int>shortestpath(int n,vector<vector<int>>&edges, int &start)
{
    ada.clear();
  int dp[n+1][n+1];
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)
        dp[i][j]=INT_MAX;
}
for(int i=0;i<int(edges.size());i++)
{
    int u=edges[i][0];
    int v=edges[i][1];
    int cost=edges[i][2];
    dp[u][v]=min(dp[u][v],cost);
    dp[v][u]=min(dp[v][u],cost);
}
// for(int i=1;i<=n;i++)
// {
//     for(int j=1;j<=n;j++)
//     {
//         cout<<dp[i][j]<<" ";
//     }
//     cout<<endl;
// }
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)
    {
        if(dp[i][j]!=INT_MAX)
        {
            ada[i].push_back({j,dp[i][j]});
            //ada[j].push_back({i,dp[j][i]});
        }
    }
}
    // for(int i=0;i<int(edges.size());i++)
    // {
    //     int u=edges[i][0];
    //     int v=edges[i][1];
    //     int cost=edges[i][2];
    //     ada[u].push_back({v,cost});
    //     ada[v].push_back({u,cost});
    // }
    dijktras(start);
    vector<int>ans;
    //for(int i=1;i<=n;i++)
    //    cout<<dist[i]<<" ";
    for(int i=1;i<=n;i++)
    {
        if(i==start)
         continue;
        if(dist[i]==INT_MAX)
            ans.push_back(-1);
        else
            ans.push_back(dist[i]);
    }
    return ans;
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
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges;
    while(m--)
    {
      vector<int>temp;
      int u,v,cost;
      cin>>u>>v>>cost;
      temp.push_back(u);
      temp.push_back(v);
      temp.push_back(cost);
      edges.push_back(temp);
    }
    int start;
    cin>>start;
    vector<int>ans=shortestpath(n,edges,start);
    for(int i=0;i<ans.size();i++)
      cout<<ans[i]<<" ";
    cout<<endl;
  }
}

