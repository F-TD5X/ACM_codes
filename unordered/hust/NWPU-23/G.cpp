#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int x,sg[2222];

int dfs(int n)
{
    if(sg[n] != -1)
        return sg[n];
    if(n <= 3)
        return sg[n] = 1;
    int h[2222];
    int i;
    memset(h, 0, sizeof(h));
    for(i = 1; i <= n; i ++)
    {
        if(i > 3)
        {
            if(i < n - 2)
                h[dfs(n - i - 2) ^ dfs(i - 3)] = 1;
            else
                h[dfs(i - 3)] = 1;
        }
        else
        {
            if(i < n - 2)
                h[dfs(n - i - 2)] = 1;
            else
                h[0] = 1;
        }
    }
    for(i=0;h[i];i++);
    return sg[n] = i;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("G.in","r",stdin);
    //freopen("G.out","w",stdout);
#endif
    while(cin >> x)
    {
        memset(sg,-1,sizeof(sg));
        cout << (dfs(x)?1:2) << endl;
    }
    return 0;
}
