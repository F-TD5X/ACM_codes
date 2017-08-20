#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn = 1e3+10;
struct Node
{
    int ma[maxn][maxn];
    int sum;
};
map<int,Node> state;
int n,m,q;
int sum;
int a,x,y;
int ma[maxn][maxn];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("d.in","r",stdin);
    //freopen("d.out","w",stdout);
#endif
    cin >> n >> m >> q;
    for(int i=1;i<=q;i++)
    {
        cin >>a;
        if(a ==1)
        {
            scanf("%d%d",&x,&y);
            if(!ma[x][y])
            {
                ma[x][y]=1;
                sum++;
            }
        }
        if(a==2)
        {
            scanf("%d%d",&x,&y);
            if(ma[x][y])
            {
                ma[x][y]=0;
                sum--;
            }
        }
        if(a==3)
        {
            scanf("%d",&x);
            for(int j=1;j<=m;j++)
            {
                if(ma[x][j])
                {
                    ma[x][j]=0;
                    sum--;
                }
                else
                {
                    ma[x][j]=1;
                    sum++;
                }
            }
        }
        if(a == 4)
        {
            scanf("%d",&x);
            memcpy(ma,state[x].ma,sizeof(ma));
            sum = state[x].sum;
        }
        memcpy(state[i].ma,ma,sizeof(ma));
        state[i].sum = sum;
        cout << sum << endl;
    }
    return 0;
}
