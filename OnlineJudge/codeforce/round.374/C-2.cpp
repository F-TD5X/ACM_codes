#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <memory.h>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <cmath>

using namespace std;

#define Clear(f, nr) memset(f, nr, sizeof(f))
typedef long long ll;
const int INF = 1 << 30;
const int SIZE = 5010;
const int MSIZE = 100020;

struct Node {
    int y;
    int len;
};
vector<Node> path[SIZE];
vector<int> ans;
int fa[SIZE];
ll tot;
ll T;
int et;
//map<int, ll> dist[SIZE];
ll dist[SIZE][SIZE];

void Print(int x) {
    ans.clear();
    while (x != -1) {
        ans.push_back(x);
        x = fa[x];
    }
}

void dfs(int pre, int x, ll len, int node_nr) {
    if (x == et) {
        if (node_nr > tot && len <= T)  {
            tot = node_nr;
            fa[et] = pre;
            Print(et);
        }
        return ;
    }
    if (dist[x][node_nr] != -1 && dist[x][node_nr] <= len)
        return;
    dist[x][node_nr] = len;
    for (int i = 0; i < path[x].size(); i ++) {
        int now = path[x][i].y;
        fa[now] = x;
        dfs(x, now, len + path[x][i].len, node_nr + 1);
    }
}

int main() {
    int n, m;
    int a, b, x;
    scanf("%d %d", &n, &m);
    cin >> T;
        Clear(fa, -1);
        for (int i = 0; i < m; i ++) {
            scanf("%d %d %d", &a, &b, &x);
            Node now;
            now.y = b;
            now.len = x;
            path[a].push_back(now);
        }
        
        Clear(dist, -1);
        tot = 0;
        et = n;
        dfs(-1, 1, 0, 1);

        printf("%lu\n", ans.size());
        for (int i = ans.size() - 1; i >= 0; i --)
            printf("%d ", ans[i]);
        puts("");
    //}
}

