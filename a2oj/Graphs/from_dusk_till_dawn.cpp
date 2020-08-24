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
unordered_map<string,vector<pair<string,pair<int,int>>>>ada;
unordered_map<string,int>dist;
/*
There are some paths the user can take and there are some paths which he cannot take
and of paths which he can take some cost 0 and some cost 1
The path which cost him are 0 are those he doesnt cross the 12:00 mark and he doesnt need anythig to drink
But the paths which crosses the 12:00 mark cost him 1;
*/
int convert(int h)
{
    if(h>=18 && h<24)
        return 24-h+6;
    else
        return 6-h;
}
void modified_bfs(string start)
{
deque<pair<string,int>>q;
q.push_front({start,18});
dist[start]=0;
while(!q.empty())
{
int end_time=q.front().second;
string curr=q.front().first;
q.pop_front();
//cout<<curr<<endl;
for(auto edges:ada[curr])
{
//unordered_map<string,vector<pair<string,pair<int,pair<int,int>>>>>ada;
string dest=edges.first;
int s=edges.second.first;
int e=edges.second.second;
int cost;
if(convert(s)>convert(end_time))
	cost=1;
else
cost=0;
	if(dist.count(dest)==0 || dist[dest]>dist[curr]+cost)
{
dist[dest]=dist[curr]+cost;
if(cost==0)
	q.push_front({dest,e});
else
	q.push_back({dest,e});
}


}
}

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
int x=1;
while(t--)
{
int m;
cin>>m;
while(m--)
{
//unordered_map<string,vector<pair<string,pair<int,pair<int,int>>>>>ada;
//{dest,start,end}
string u,v;
int s,l;
cin>>u>>v>>s>>l;
s%=24;
int e=(s+l)%24;
if((s>=18 || s<=6) && (e>=18 || e<=6))
	ada[u].pb({v,{s,e}});
}
string str,dest;
cin>>str>>dest;
modified_bfs(str);
cout<<"Test Case "<<x<<"."<<endl;
if(dist.count(dest)==0)
cout<<"There is no route Vladimir can take."<<endl;
else
cout<<"Vladimir needs "<<dist[dest]<<" litre(s) of blood."<<endl;
x++;
// for(auto it:dist)
// cout<<it.first<<" "<<it.second<<endl;
dist.clear();
ada.clear();
}


}
