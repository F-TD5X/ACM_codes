#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n, x, y;
    cin >> n >> x >> y;
    pair<int, char> mn[3][3];
    for (int i = 0; i < 9; i++) mn[i / 3][i % 3] = { INT_MAX, '?' };
    for (int i = 0; i < n; i++) {
        char t;
        int xx, yy;
        scanf(" %c %d %d", &t, &xx, &yy);
        xx -= x; yy -= y;
        if (xx == 0 || yy == 0 || abs(xx) == abs(yy)) {
            pair<int, char> &tmp = mn[(xx >= 0) + (xx > 0)][(yy >= 0) + (yy > 0)];
            tmp = min(tmp, { max(abs(xx), abs(yy)), t });
        }
    }
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
        if (mn[i][j].second == 'Q') return true;
        if (mn[i][j].second == ((i + j) % 2 == 0 ? 'B' : 'R')) return true;
    }
    return false;
}

int main() {
    puts(solve() ? "YES" : "NO");
}
