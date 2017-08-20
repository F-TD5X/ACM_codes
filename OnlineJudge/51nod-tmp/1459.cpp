#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int n,m,s,e,ma[maxn][maxn];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1459.in","r",stdin);
    //freopen("1459.out","w",stdout);
#endif
    cin >> n >> m>>s>>e;
    int x,y;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> ma[x][y];
    queue<int>q;
    q.push(s);
    while(!q.enpty())
    {
        int x=q.front();
        q.pop();
    }
    return 0;
}
