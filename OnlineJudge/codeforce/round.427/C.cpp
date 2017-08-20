/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int sum[105][105][15];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	int N, Q, C, i, j, k;
	scanf("%d %d %d", &N, &Q, &C);
	for (i = 1; i <= N; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		sum[t1][t2][t3]++;
	}
	for (i = 1; i <= 100; i++) {
		for (j = 1; j <= 100; j++) {
			for (k = 0; k <= C; k++) sum[i][j][k] += sum[i - 1][j][k] + sum[i][j - 1][k] - sum[i - 1][j - 1][k];
		}
	}
	while (Q--) {
		int t, sx, sy, ex, ey;
		scanf("%d %d %d %d %d", &t, &sx, &sy, &ex, &ey);
		
		int ans = 0;
		for (i = 0; i <= C; i++) {
			int x = (t + i) % (C + 1);
			ans += x * (sum[ex][ey][i] - sum[sx - 1][ey][i] - sum[ex][sy - 1][i] + sum[sx - 1][sy - 1][i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
