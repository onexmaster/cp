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

//char S[1000001];
 

long long a, k, s, C[1000001];
 
int main() {
	string S;
	cin >> k >> S;
	C[0] = 1;
	for (int i = 0; S[i]; ++i) {
		s += S[i] == '1';
		++C[s];
	}
	for (int i = k; i <= s; ++i) {
		if (k == 0) {
			a += (C[i] - 1) * C[i] / 2;
		} else {
			a += C[i] * C[i - k];
		}
	}
	cout << a << endl;
	return 0;

}