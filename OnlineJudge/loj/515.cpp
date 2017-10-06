/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,l,r;
bitset<maxn> b[110];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("515.in","r",stdin);
    //freopen("515.out","w",stdout);
#endif
    while(~scanf("%d", &n)){
        b[0].set(0);
        for(int i=1; i<=n; i++){
            b[i].reset();
            scanf("%d %d", &l,&r);
            for(int j=l; j<=r; j++){
                b[i]|=(b[i-1]<<(j*j));
            }
        }
        printf("%d\n", b[n].count());
    }
    return 0;
}
