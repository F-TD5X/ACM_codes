#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int maxn = 10005;

int T;
int n,m;
ll b[maxn];
ll ans[maxn],C[55][55];

void init()
{
    memset(C,0,sizeof C);
    C[0][0] = 1; 
    for(int i = 1; i <= 50; i++)
    {
        C[i][0] = 1;
        for(int j = 1; j <= i; j++)
            C[i][j] = C[i-1][j] + C[i-1][j-1];
    }
}

int main()
{
    //cout<<(1LL<<50)<<endl;
    //freopen("1008.in","r",stdin);
    //freopen("1008.out","w",stdout);
    init();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i = 0; i <= m; i++) scanf("%I64d",b + i);
        int id= 0;
        int c = 0;
        ll base = 1;
        while(base < b[0]) { c++; base *= 2;}
        while(c--) ans[id++] = 0;
        b[0]--;
        for(int i = m; i >= 0; i--) b[i] -= b[0];
        for(int i = 1; i <= m; i++)
        {
            //cout<<i<<" "<<b[i]<<endl;
            int tot = b[i];
            while(b[i]--) ans[id++] = i;
            for(int j = i + i,k = 2; j <= m; j += i,k++)
                b[j] -= C[tot][k];
            for(int j = i + i - 1; j <= m; j++)
                if(j % i)
                {
                    //cout<<233<<endl;
                    b[j] -= b[j-i] * tot;
                }
        }
        for(int i = 0; i < id; i++)
        {
            printf("%d",ans[i]);
            if(i != n - 1) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
