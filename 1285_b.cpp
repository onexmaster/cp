#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 100100;
ll a[N];
int n;
bool solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	ll all = 0;
	for (int i = 0; i < n; i++)
		all += a[i];
	ll sum = 0;
	for (int i = 0; i < n - 1; i++) {
		sum += a[i];
		if (sum >= all) return false;
	}
	sum = 0;
	for (int i = n - 1; i > 0; i--) {
		sum += a[i];
		if (sum >= all) return false;
	}
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) {
		if (solve())
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
