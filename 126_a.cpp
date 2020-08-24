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

	string s;
	cin >> s;
	vector<int> r;
	for (string t: {"twone", "one", "two"}) {
    for (size_t pos = 0; (pos = s.find(t, pos)) != string::npos;) {
        s[pos + t.length() / 2] = '?';
        r.push_back(pos + t.length() / 2);
    }
}
cout << r.size() << endl;
for (auto rr: r)
    cout << rr + 1 << " ";
cout << endl;
}
	
}