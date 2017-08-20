#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int l[4],s[4],r[4],p[4];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
   for (int i = 0; i < 4; i++)
        scanf("%d%d%d%d", &l[i], &s[i], &r[i], &p[i]);
    for (int i = 0; i < 4; i++)
        if (p[i] && (l[i] || s[i] || r[i] || l[(i + 1) % 4] || s[(i + 2) % 4] || r[(i + 3) % 4])) {
            puts("YES");
            return 0;
        }
    puts("NO");
	return 0;
}
