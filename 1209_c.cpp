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
int N;
string digits;
void solve_case() {
    cin >> N >> digits;
    string answer;
 
    for (int two_start = 0; two_start < 10; two_start++) {
        char one = '0', two = two_start + '0';
        answer = "";
 
        for (char c : digits)
            if (c >= two) {
                two = c;
                answer += '2';
            } else if (c >= one) {
                one = c;
                answer += '1';
            } else {
                break;
            }
 
        if (one <= two_start + '0' && (int) answer.size() == N)
            break;
        else
            answer = "";
    }
 
    cout << ((int) answer.size() < N ? "-" : answer) << '\n';
}
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
        solve_case();
        
    }
return 0;
}