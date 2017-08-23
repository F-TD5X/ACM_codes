#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define CLR(A, X) memset(A, X, sizeof(A))
#define bitcount(X) __builtin_popcountll(X)
//#pragma comment(linker, "/STACK:102400000, 102400000")
const double eps = 1e-10;
int dcmp(double x) { if(fabs(x) < eps) return 0; return x<0?-1:1; }
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5+5;

struct BIT{
    LL c[N];
    LL sum(int x) { LL res=0; while(x > 0) res+=c[x], x-=(x&-x); return res; }
    void add(int x, int d) { while(x<N) c[x]+=d, x+=(x&-x); }
    void reset() { CLR(c,0); }
}A;

int a[N], b[N], p[N][35], deep[N], W;
LL d[N];
vector<int> G[N];
vector<PII> H[N];
struct Fuck {
    int u, v, l, r, x;
}c[N];
map<pair<int, PII>, LL> ms;

int lca(int a, int b) {
    if(deep[a] < deep[b]) swap(a, b);
    int t = deep[a] - deep[b];
    for(int i = 0; (1<<i) <= t; i++) if((1<<i)&t) a = p[a][i];
    for(int i = 22; i >= 0; i--) {
        if(p[a][i] != p[b][i]) a = p[a][i], b = p[b][i];
    }
    return a==b?a:p[a][0];
}

void dfs(int u, int fa) {
    for(int i = 1; i <= 22; i++) p[u][i] = p[p[u][i-1]][i-1];
    A.add(a[u], d[a[u]]);
    for(PII x:H[u]) ms[{u, {x.fi, x.se}}] = A.sum(x.se)-A.sum(x.fi-1);
    for(int v:G[u]) if(v != fa) {
        deep[v] = deep[u]+1;
        p[v][0] = u;
        dfs(v, u);
    }
    A.add(a[u], -d[a[u]]);
}

void dfs2(int u, int fa) {
    for(int i = 1; i <= 22; i++) p[u][i] = p[p[u][i-1]][i-1];
    for(int v:G[u]) if(v != fa) {
        deep[v] = deep[u]+1;
        p[v][0] = u;
        dfs2(v, u);
    }
}

int main() {
    int n, m;
    while(~scanf("%d%d", &n, &m)) {
        A.reset(); ms.clear();
        for(int i = 1; i <= n; i++) G[i].clear(), H[i].clear();
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = a[i];
        sort(b+1, b+1+n);
        W = unique(b+1, b+1+n)-b;
        for(int i = 1; i <= n; i++) {
            int x = a[i];
            a[i] = lower_bound(b+1, b+W, a[i])-b;
            d[a[i]] = x;
        }
        int u, v, l, r, x;
        for(int i = 0; i < n-1; i++) {
            scanf("%d%d", &u, &v);
            G[u].pb(v); G[v].pb(u);
        }
        dfs2(1, -1);
        for(int i = 1; i <= m; i++) {
            scanf("%d%d%d%d", &u, &v, &l, &r);
            int id1 = lower_bound(b+1, b+W, l)-b;
            int id2 = upper_bound(b+1, b+W, r)-b-1;
            if(id2 == 0) id2 = 1;
            H[u].pb({id1, id2}); H[v].pb({id1, id2});
            x = lca(u, v);
            H[x].pb({id1, id2}); H[p[x][0]].pb({id1, id2});
            c[i] = {u, v, id1, id2, x};
        }
        p[1][0] = 0;
        dfs(1, -1);
        for(int i = 1; i <= m; i++) {
            u = c[i].u, v = c[i].v, l = c[i].l, r = c[i].r, x = c[i].x;
            LL ret = ms[{u, {l, r}}]+ms[{v, {l, r}}]-ms[{p[x][0], {l, r}}]-ms[{x, {l, r}}];
            printf("%lld%c", ret, i==m?'\n':' ');
        }
    }
    return 0;
}
