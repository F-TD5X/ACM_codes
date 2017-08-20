#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn = 1e3+10;
int n,m;
int whell[maxn],ma[maxn][maxn];
bool flag;
int a[maxn][2];
int r[maxn];

int dfs(int x,int k)
{
    if(whell[x])
    {
        if(whell[x] != k)
            flag=1;
        return 0;
    }
    whell[x] = k;
    for(int i=1;i<=n;i++)
        if(ma[x][i])
            dfs(i,3-k);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("K.in","r",stdin);
    //freopen("K.out","w",stdout);
#endif
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i][0] >>a[i][1] >> r[i];
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            ma[i][j] = ma[j][i] = ((a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])*(a[i][1]-a[j][1]))==((r[i]+r[j])*(r[i]+r[j]));
    dfs(1,1);
    if(flag)
    {puts("The input gear cannot move.");return 0;}
    if(whell[n]==0)
    {puts("The input gear is not connected to the output gear.");return 0;}
    if(whell[n]==2)
        cout << '-';
    int t = __gcd(r[1],r[n]);
    cout << r[1]/t <<":"<<r[n]/t<<endl;
    return 0;
}
