#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 10000 + 5;
const int DEG = 20;

struct edge {
    int to, nxt;
} e[maxn << 1];

int head[maxn], tot;

void addedge(int u, int v) {
    e[tot].to = v;
    e[tot].nxt = head[u];
    head[u] = tot++;
}

void init() {
    tot = 0;
    memset(head, -1, sizeof(head));
}

int fa[maxn][DEG];
int deg[maxn];

void bfs(int root) {
    queue<int> q;
    deg[root] = 0;
    fa[root][0] = root;
    q.push(root);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 1; i < DEG; i++)
            fa[u][i] = fa[fa[u][i-1]][i-1];
        for (int i = head[u]; i != -1; i = e[i].nxt) {
            int v = e[i].to;
            if (v == fa[u][0]) continue;
            deg[v] = deg[u] + 1;
            fa[v][0] = u;
            q.push(v);
        }
    }
}

int lca(int u, int v) {
    if (deg[u] > deg[v]) swap(u, v);
    int hu = deg[u], hv = deg[v];
    int tu = u, tv = v;
    for (int det = hv - hu, i = 0; det; det >>= 1, i++)
        if (det & 1) tv = fa[tv][i];
    if (tu == tv) return tu;
    for (int i = DEG - 1; i >= 0; i--) {
        if (fa[tu][i] == fa[tv][i]) continue;
        tu = fa[tu][i];
        tv = fa[tv][i];
    }
    return fa[tu][0];
}

int in[maxn];

int main() {
    //freopen("in.txt", "r", stdin);
    int t, n,m, u, v;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n,&m);
        init();
        memset(in, 0, sizeof(in));
        for (int i = 1; i < n; i++) {
            scanf("%d%d", &u, &v);
            addedge(u, v);
            addedge(v, u);
            in[v]++;
        }
        for (int i = 1; i <= n; i++) {
            if (!in[i]) {
                bfs(i);
                break;
            }
        }
		while(m--){
        scanf("%d%d", &u, &v);
        printf("%d\n", lca(u, v));
		}
    }
    return 0;
}
