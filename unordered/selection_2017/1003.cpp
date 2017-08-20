/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 3333;
int f[maxn], cnt[maxn];

int fi(int x)
{
	if (f[x] != x)
		f[x] = fi(f[x]);
	return f[x];
}

int uni(int a, int b)
{
	a = fi(a);
	b = fi(b);
	if (a != b)
		f[b] = a;
}

void init(int x)
{
	for (int i = 0; i <= x; i++)
		f[i] = i;
	memset(cnt, 0, sizeof(cnt));
}

int main()
{
#ifndef ONLINE_JUDGE
	//freopen("1003.in","r",stdin);
	//freopen("1003.out","w",stdout);
#endif
	int n, T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		init(n);
		for (int i = 1; i <= n - 1; i++)
		{
			for (int v, j = 1; j <= n - i; j++)
			{
				scanf("%d", &v);
				if (v == 1)
					uni(i, j + i);
			}
		}
		int ans = 0, t = 0;
		bool flag = 1;
		for (int tmp, i = 1; i <= n; i++)
		{
			tmp = fi(i);
			if (cnt[tmp] == 0)
			{
				cnt[tmp]++;
				t++;
			}
			else
				cnt[tmp]++;
			if (cnt[tmp] >= 4)
				flag = 0;
		}
		if (t >= 4)
			flag = 0;
		if (flag)
			puts("Great Team!");
		else
			puts("Bad Team!");

	}
	return 0;
}
