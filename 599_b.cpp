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
#define REP(i,a) for(int i=0;i<a;++i)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int INF = 0x3f3f3f3f;
int moves[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
const int N = 1e6+10;
int a[N];
map<int,int> M,M1;
int main(){
    FIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
  int n,m;
  scanf("%d%d",&n,&m);
  REP(i,n) {
    int x; scanf("%d",&x);
    M[x]++;
    M1[x]=i;
  }
  int f=0;
  REP(i,m){
    int x; scanf("%d",&x);
    if(M.count(x)==0){
      printf("Impossible\n"); exit(0);
    }else if(M[x]>1) {f=1 ;}
    a[i]=M1[x];
  }
  if(f==1){
    printf("Ambiguity\n"); exit(0);
  }
  printf("Possible\n");
  REP(i,m) printf("%d ",a[i]+1);
  printf("\n");
  return 0;return 0;
}