#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long LL;
typedef unsigned long long ull;
using namespace std;
const int dir[8][2] = {{0,1},{1,0},{0,-1},{-1,0},{-1,1},
  {1,1},{1,-1},{-1,-1}};
LL dp[21][3]; unsigned long long int n; int a[25];
int main(void){
#ifndef ONLINE_JUDGE
#endif
  int t; scanf("%d", &t);
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 1; i < 21; ++i){
    dp[i][0] = dp[i-1][0] * 10 - dp[i-1][1];
    dp[i][1] = dp[i-1][0];
    dp[i][2] = dp[i-1][2] * 10 + dp[i-1][1];
  }
  while (t--){
    //cin >> n;
    scanf("%I64d", &n);
    int len = 0; memset(a, 0, sizeof(a));
    n++;
    while (n){
      a[++len] = n % 10; n /= 10;
    } LL ans = 0; int last = 0; bool flag = false;
    for (int i = len; i >= 1; --i){
      ans += (dp[i-1][2] * a[i]);
      if (flag) ans += dp[i-1][0] * a[i];
      if (!flag && a[i] > 4) {ans += dp[i-1][1];}
      if (last == 4 && a[i] == 9) {flag = true;}
      last = a[i];
    }

    //cout << ans << endl;
    printf("%I64d\n", ans);
  }

  return 0;
}
