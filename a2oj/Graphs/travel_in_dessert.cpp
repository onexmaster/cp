#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
int a, b;
int s[10005], t[10005];
float dp[105][105];
int path[105][105];
float r[10005], d[10005];
float max(float a,float b){return (a>b)?a:b;}
float min(float a,float b){return (a<b)?a:b;}
float absval(float a){return (a<0)?-a:a;}
void printPath(int i, int j, char p) {
    if (!path[i][j]) {
        if (!p)
            printf("%d ", i);
        printf("%d", j);
        if (j != b)//if j is not the final node
            putchar(' ');
    } else {
        printPath(i, path[i][j], p);
        printPath(path[i][j], j, 1);
    }
}
int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif
    int n, e, i, j, k;
    while (scanf("%d %d", &n, &e) == 2) {
        scanf("%d %d", &a, &b);
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                dp[i][j] = inf;
        for (i = 0; i < e; i++) {
            scanf("%d %d %f %f", s + i, t + i, r + i, d + i);
            dp[s[i]][t[i]] = min(dp[s[i]][t[i]],r[i]);
            dp[t[i]][s[i]] = min(dp[t[i]][s[i]],r[i]);
        }
        //use floyd warshall to find the lowest tempreture
        for (k = 1; k <= n; k++)
            for (i = 1; i <= n; i++)
                for (j = 1; j <= n; j++)
                    dp[i][j] = min(dp[i][j],max(dp[i][k],dp[k][j]));
        float minTemp = dp[a][b];
        //refill floyd warshall array with edge weights
        //given each edge has minimum weight and tempreture less than lowest tempreture
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++) {
                dp[i][j] = inf;
                path[i][j] = 0;
            }
        for (i = 0; i < e; i++) {
            if (r[i]<minTemp+1e-6) {
                //if there are multiple edges between two nodes,greedily choose the one with smaller length
                dp[s[i]][t[i]] = min(dp[s[i]][t[i]],d[i]);
                dp[t[i]][s[i]] = min(dp[t[i]][s[i]],d[i]);
            }
        }
        //floyd warshall again but this time we'll store the intermidate node for each two nodes to allow path retrival
        for (k = 1; k <= n; k++)
            for (i = 1; i <= n; i++)
                for (j = 1; j <= n; j++)
                    if (dp[i][j] > dp[i][k] + dp[k][j]) {
                        dp[i][j] = dp[i][k] + dp[k][j];
                        path[i][j] = k;
                    }
        printPath(a, b, 0);
        putchar('\n');
        printf("%.1f %.1f\n", dp[a][b], minTemp);
    }
    return 0;
}