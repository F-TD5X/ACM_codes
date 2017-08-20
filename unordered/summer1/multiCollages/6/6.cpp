#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll arr[22][22];
int dep;
ll ansl,ansr;
int dig[22];
int x;

void dfs(int i, int cx, long long sum)
{
	if (i == dep)
	{
		if (ansr > sum || (ansr == sum && x > cx))
			ansr = sum, x = cx;
	}
	else
		for (dig[i] = 0; dig[i] < 2; ++dig[i])
		{
			long long nsum = sum + arr[i][i];
			for (int j = 0; j < i; ++j)
				if (dig[i] ^ dig[j])
					nsum -= arr[i][j];
				else
					nsum += arr[i][j];
			dfs(i + 1, cx | (dig[i] << i),  nsum);
		}
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("1006.in","r",stdin);
    freopen("1006","w",stdout);
#endif
    int T;
    cin >> T;
    while(T--)
    {
       memset(arr,0,sizeof(arr));
       int n,x,y;
       cin >> n >> x;
       for(int i=1;i<n;i++)
       {
           cin >> y;
          int hig= 19;
         while(hig >= 0 && ~(x^y) >> hig & 1)
            hig--;
         int big = max(x,y);
         int small = min(x,y);
         for(int j = hig;~j;j--)
         {
            arr[hig][j]+=(big >> j &1) - (small >> j &1);
         }
         swap(x,y);
       }
       dep = 20;
       while(dep >0 && !arr[dep-1][dep-1])
           dep--;
       for(int i=0;i<=dep;i++)
           for(int j=0;j<=i;j++)
                arr[i][j] <<=j;
       ansr=1e18;
       x = 0;
       dfs(0,0,0);
       cout << x << " " << ansr << endl;
    }
    return 0;
}
