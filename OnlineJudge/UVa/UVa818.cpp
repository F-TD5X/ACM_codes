#include <bits/stdc++.h>
using namespace std;

int n, g[16][16], vis[16], l, kase = 0;

bool line(int k)
{
    for(int i = 0; i < n; ++i){
        if(k&(1<<i)) continue;
        int cnt = 0;
        for(int j = 0; j < n; ++j)
            if(g[i][j] && !(k&(1<<j)))
                ++cnt;
        if(cnt > 2)
            return false;
    }
    return true;
}
bool DFS(int u, int fa, const int k) //成环：True
{
    vis[u] = 1;
    for(int v = 0; v < n; ++v)
        if(g[u][v]){
            if(v == fa || (k&(1<<v))) continue;
            if(vis[v]) return true;
            if(DFS(v, u, k)) return true;
        }
    return false;
}
bool circle(const int k)
{
    for(int i = 0; i < n; ++i){
        if(vis[i] || ((k&(1<<i)))) continue;
        l++;
        if(DFS(i, -1, k)) return true;
    }
    return false;
}
int calc(int k){
    return k == 0 ? 0 : calc(k>>1) + (k&1);
}
int main(){
    while(memset(g, 0, sizeof(g)), cin >> n, n) {
        int x, y;
        while(cin >> x >> y, !(x==-1 && y==-1))
            g[x-1][y-1] = g[y-1][x-1] = 1;
        int res = INT_MAX;
        for(int i = 0; i < (1<<n); ++i) {
            memset(vis, 0, sizeof(vis)); l = 0;
            if(!circle(i) && line(i) && calc(i)>=l-1)
                res = min(calc(i), res);
        }
        printf("Set %d: Minimum links to open is %d\n", ++kase, res);
    }
    return 0;
}
