#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 66;
int siz[1 << 10], nex[1 << 10][10]; // nex[i][j]表示已经用了i状态的序列，再加入数字j且使得序列状态不变会变成的状态
int bit[20], K;
//因为K只有10，所以构成这个序列的最长也就是0~9,所以用一个二进制表示0~9中哪些已经用过了
ll dp[N][1<<10][11];//dp[len][high][state][lis];长度为len，最高位为high，已使用过的有效子序列的状态为state,最长上升子序列为lis
ll dfs(int len, int state, bool zero, bool flag){
	if (len == 0)return siz[state] == K;
	if (!flag && dp[len][state][K] != -1)return dp[len][state][K];

	ll ans = 0;
	int end = flag ? bit[len] : 9;
	for (int i = 0; i <= end; i++)
		ans += dfs(len - 1, (zero&&i == 0) ? 0 : nex[state][i], zero&&i == 0, flag&&i == end);

	if (!flag)dp[len][state][K] = ans;
	return ans;
}

ll solve(ll x){
	int len = 0;
	for (ll tmp = x; tmp; tmp /= 10)bit[++len] = tmp % 10;
	return dfs(len, 0, 1, 1);
}
int find_nex(int status, int num){
	for (int i = num; i < 10; i++)
	if (status&(1 << i))return(status ^ (1 << i)) | (1 << num);
	return status | (1 << num);
}

int main() {
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < 1 << 10; i++){
		siz[i] = 0;
		for (int j = 0; j < 10; j++)
		{
			if (i&(1 << j))siz[i]++;
			nex[i][j] = find_nex(i, j);
		}
	}
	int T, Cas = 1; scanf("%d", &T);
	while (T-- > 0){
		ll l, r;
		cin >> l >> r >> K;
		printf("Case #%d: %I64d\n", Cas++, solve(r) - solve(l - 1));
	}
	return 0;
}
