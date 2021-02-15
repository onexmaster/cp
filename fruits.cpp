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
string s="abcdefg";
vector<string>all;
void solve(int index, int used, string curr)
{
    cout<<index<<" "<<used<<" "<<curr<<endl;
  //if(index>int(s.size()))
   // return ;
  if(used==3)
  {
    all.push_back(curr);
    return ;
  }
  if(index+1<=int(s.size())){
  //do not choose the current index
  solve(index+1,used,curr);
  //choose the current index
  curr+=s[index];
  solve(index+1,used+1,curr);
  }
  return ;
}
int main()
{
     #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
  all.clear();
  //start index,char used
  solve(0,0,"");
  cout<<all.size()<<endl;
  for(auto it:all)
    cout<<it<<endl;
  vector<string>ans;
//   vector<string>mapping{"apples" , "grapes", "oranges", "grapefruit", "kiwi", "tomatoes", "bananas"};
//   for(auto nos: all)
//   {
//     string res;
//     bool space=false;
//     for(char c:nos)
//     {
//       res+=mapping[c-'a'];
//       space=true;
//       if(space)
//         res+=" ";
//     }
//       ans.push_back(res);
//   }
//   for(auto it:ans)
//     cout<<it<<endl;

}
