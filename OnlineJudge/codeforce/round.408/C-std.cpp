<<<<<<< HEAD
<<<<<<< HEAD

 #include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(1e9) + 123;

int n;
vector<int> g[300000];
int a[300000];

multiset<int, greater<int> > se;

inline void er(int x) {
    auto it = se.find(x);
    se.erase(it);
}

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    forn(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    int ans = INF;
    int mx = -INF;
    forn(i, n) se.insert(a[i]);
    forn(i, n) {
        er(a[i]);
        for (int to : g[i]) er(a[to]);

        int cur = -INF;
        if (!se.empty()) {
            cur = max(cur, *se.begin() + 2);
        }
        cur = max(cur, a[i]);
        for (int to : g[i]) {
            cur = max(cur, a[to] + 1);
        }
        ans = min(ans, cur);

        se.insert(a[i]);
        for (int to : g[i]) se.insert(a[to]);
    }
    cout << ans << endl;
    return 0;
}
=======

 #include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(1e9) + 123;

int n;
vector<int> g[300000];
int a[300000];

multiset<int, greater<int> > se;

inline void er(int x) {
    auto it = se.find(x);
    se.erase(it);
}

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    forn(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    int ans = INF;
    int mx = -INF;
    forn(i, n) se.insert(a[i]);
    forn(i, n) {
        er(a[i]);
        for (int to : g[i]) er(a[to]);

        int cur = -INF;
        if (!se.empty()) {
            cur = max(cur, *se.begin() + 2);
        }
        cur = max(cur, a[i]);
        for (int to : g[i]) {
            cur = max(cur, a[to] + 1);
        }
        ans = min(ans, cur);

        se.insert(a[i]);
        for (int to : g[i]) se.insert(a[to]);
    }
    cout << ans << endl;
    return 0;
}
>>>>>>> e30efc2bee7b85c64b5cc40b21a84d4cb2f8cc56
=======

 #include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(1e9) + 123;

int n;
vector<int> g[300000];
int a[300000];

multiset<int, greater<int> > se;

inline void er(int x) {
    auto it = se.find(x);
    se.erase(it);
}

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    forn(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    int ans = INF;
    int mx = -INF;
    forn(i, n) se.insert(a[i]);
    forn(i, n) {
        er(a[i]);
        for (int to : g[i]) er(a[to]);

        int cur = -INF;
        if (!se.empty()) {
            cur = max(cur, *se.begin() + 2);
        }
        cur = max(cur, a[i]);
        for (int to : g[i]) {
            cur = max(cur, a[to] + 1);
        }
        ans = min(ans, cur);

        se.insert(a[i]);
        for (int to : g[i]) se.insert(a[to]);
    }
    cout << ans << endl;
    return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
