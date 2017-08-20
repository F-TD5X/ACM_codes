/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 100, mod = 1e9 + 7;
int nxt[maxn];
char t[maxn], p[maxn];
char s[maxn];
int tl, pl;

void getnxt(char *p)
{
	int pl = strlen(p);
	nxt[0] = -1;
	int j = 0, k = -1;
	while (j < pl)
	{
		if (k == -1 || p[j] == p[k])
			nxt[++j] = ++k;
		else
			k = nxt[k];
	}
}

ll kmp(char *t, char *p)
{
	ll ans = 0;
	ll i = 0, j = 0;
	while (i < tl)
	{
		if (j == -1 || t[i] == p[j])
		{
			++i, ++j;
			if (j == pl)
			{
				ans += j * (j + 1) / 2;
				ans %= mod;
				j = nxt[j];
			}
		}
		else
		{
			ans += j * (j + 1) / 2;
			ans %= mod;
			j = nxt[j];
		}
	}
	while (j != -1)
	{
		ans += j * (j + 1) / 2;
		ans %= mod;
		j = nxt[j];
	}
	return ans;
}


int main()
{
#ifndef ONLINE_JUDGE
	//freopen("1004.1.in","r",stdin);
	//freopen("1004.1.out","w",stdout);
#endif
	int T;
	for (scanf("%d", &T); T; --T)
	{
		scanf("%s%s", t, p);
		tl = strlen(t);
		pl = strlen(p);
		reverse(t, t + tl);
		reverse(p, pl + p);
		getnxt(p);
		printf("%lld\n", kmp(t, p));
	}
	return 0;
}
