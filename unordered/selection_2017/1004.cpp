/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;
char str[maxn], tmp[maxn], tt[maxn];
int nxt1[maxn], nxt2[maxn];
int pre[maxn], pp, pre2[maxn];
ll ans = 0;

void getnext(char *t, int *nxt)
{
	int len = strlen(t);
	int j = 0;
	nxt[0] = nxt[1] = 0;
	for (int i = 1; i < len; i++)
	{
		while (j > 0 && t[i] != t[j])
			j = nxt[j];
		if (t[i] == t[j])
			j++;
		nxt[i + 1] = j;
	}
}

int kmp(char *s, char *t, int *nxt)
{
	int j = 0;
	int ret = 0;
	int len = strlen(t);
	int pt = 0;
	pp = 0, ans = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		while (j > 0 && s[i] != t[j])
		{
			ans += pre[nxt[j]];
			j = nxt[j];
		}
		if (s[i] == s[j])
			j++;
		if (j == len)
		{
			if (pp == 0)
			{
				pp = i - j + len;
				ans += pre[len];
			}
			else
			{
				pt = pp - (i - j + 1) + 1;
				ans += pre[len] - pre2[pt];
				pp = i - j + len;
			}
			j = nxt[j];
		}
		if (ans >= mod)
			ans -= mod;
	}
}

void p()
{
	getnext(tt, nxt2);
	memset(pre, 0, sizeof(pre));
	for (int i = 1; i <= strlen(tt); i++)
	{
		int j = i;
		while (j)
		{
			pre[j] += j;
			j = nxt2[j];
		}
	}
	for (int i = 1; i <= strlen(tt); i++)
		pre[i] += pre[i - 1];
}

int main()
{
#ifndef ONLINE_JUDGE
	//freopen("1004.in","r",stdin);
	//freopen("1004.out","w",stdout);
#endif
	int T;
	//init();
	scanf("%d", &T);
	for (int i = 1; i <= 1e6 + 5; i++)
		pre2[i] = pre2[i] + i;
	while (T--)
	{
		ans = 0;
		scanf("%s%s", str, tmp);
		strcpy(tt, tmp);
		getnext(tmp, nxt1);
		for (int i = 0, j = strlen(tt) - 1; i <= j; i++, j--)
			swap(tt[i], tt[j]);
		p();
		kmp(str, tmp, nxt1);
		printf("%lld\n", ans);
	}
	return 0;
}
