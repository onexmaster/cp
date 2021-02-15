// Created by Tanuj Jain
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
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
const int ALPHABET = 26;
 
bool adj[ALPHABET][ALPHABET];
vector<bool> visited;
 
void dfs(int c) {
    if (visited[c])
        return;
 
    cout << (char) ('a' + c);
    visited[c] = true;
 
    for (int i = 0; i < ALPHABET; i++)
        if (adj[c][i])
            dfs(i);
}
 
void run_case() {
    memset(adj, false, sizeof(adj));
    string S;
    cin >> S;
    int N = S.size();
 
    for (int i = 0; i < N - 1; i++) {
        adj[S[i] - 'a'][S[i + 1] - 'a'] = true;
        adj[S[i + 1] - 'a'][S[i] - 'a'] = true;
    }
 
    vector<int> degree(ALPHABET, 0);
 
    for (int c = 0; c < ALPHABET; c++) {
        for (int i = 0; i < ALPHABET; i++)
            degree[c] += adj[c][i];
 
        if (degree[c] > 2) {
            cout << "NO" << '\n';
            return;
        }
    }
 
    if (count(degree.begin(), degree.end(), 2) > 0 && count(degree.begin(), degree.end(), 1) == 0) {
        cout << "NO" << '\n';
        return;
    }
 
    cout << "YES" << '\n';
    visited.assign(ALPHABET, false);
 
    for (int c = 0; c < ALPHABET; c++)
        if (degree[c] == 1) {
            dfs(c);
            break;
        }
 
    for (int c = 0; c < ALPHABET; c++)
        if (!visited[c])
            cout << (char) ('a' + c);
 
    cout << '\n';
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
		run_case();
	}

}