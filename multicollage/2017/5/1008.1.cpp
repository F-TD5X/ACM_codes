#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int maxn = 10005;

int T;
int n,m;
ll b[maxn];
ll C[55][55],ans[55];

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
        b[0]--;
        for(int i = m; i >= 0; i--) b[i] -= b[0];
        b[0] = c;
        while(c--) ans[id++] = 0;
        for(int i = 1; i <= m; i++)
        {
            for(int j = 0; j < b[i]; j++)
			   	ans[id++] = i;
            for(int j = i + i,k = 2; j <= m; j+= i,k++)
                b[j] -= C[b[i]][k];
            for(int j = 1; j < i; j++)
            {
                if(b[j] == 0) continue;
                for(int x = 1; x <= b[i]; x++)
                    for(int y = 1; y <= b[j]; y++)
                    {
                        if(x * i + y * j > m) continue;
                        b[x * i + y * j] -= C[b[i]][x] * C[b[j]][y];
                    }
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
