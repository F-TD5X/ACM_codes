/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 500;
int s[6];
struct Point {
    int x, y;
} poi[N];

int sqare(Point a, Point b) {
    return (a.x - b.x)*(a.x - b.x)+(a.y - b.y)*(a.y - b.y);
}

bool judge(Point a, Point b, Point c, Point d) {
    int t = 0;
    s[t++]=sqare(a, b);
    s[t++]=sqare(b, c);
    s[t++]=sqare(c, d);
    s[t++]=sqare(d, a);
    s[t++]=sqare(a, c);
    s[t++]=sqare(b, d);
    sort(s, s + 6);
    if(s[0]==s[1] && s[2]==s[3] && s[1]==s[2] && s[4]==2*s[0] && s[5]==s[4])
        return true;
    return false;
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &poi[i].x, &poi[i].y);
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                for(int k = j+1; k < n; k++)
                    for(int u = k+1; u < n; u++)
                        if(judge(poi[i], poi[j], poi[k], poi[u]))
                            ans++;
        printf("%d\n", ans);
    }
    return 0;
}
