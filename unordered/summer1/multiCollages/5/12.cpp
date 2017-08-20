
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=55555;
int n;
LL num[maxn], tmpa[maxn];
LL c[maxn];
LL left_large[maxn], left_small[maxn];
LL right_small[maxn], right_large[maxn];
LL tol_cnt[maxn], tol_small[maxn], tol_large[maxn];

LL lowbit(LL x) {
    return x & (-x);
}

void update(LL x, LL d) {
    while(x <=n) {
        c[x] += d;
        x += lowbit(x);
    }
}

LL get_sum(LL x) {
    LL ret = 0;
    while(x > 0) {
        ret += c[x];
        x -= lowbit(x);
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    //IN;

    while(scanf("%d", &n) != EOF)
    {
        for(int i=1; i<=n; i++)
            scanf("%d", &num[i]), tmpa[i] = num[i];
        sort(tmpa+1, tmpa+1+n);

        map<LL, LL> mymap;
        LL sz = 0; mymap.clear();
        for(int i=1; i<=n; i++) {
            if(!mymap.count(tmpa[i])) {
                sz++;
                mymap.insert(make_pair(tmpa[i], sz));
            }
        }

        for(int i=1; i<=n; i++) {
            num[i] = mymap[num[i]];
        }

        memset(left_large, 0, sizeof(left_large));
        memset(right_large, 0, sizeof(right_large));
        memset(right_small, 0, sizeof(right_small));
        memset(left_small, 0, sizeof(left_small));
        memset(tol_small, 0, sizeof(tol_small));
        memset(tol_large, 0, sizeof(tol_large));
        memset(tol_cnt, 0, sizeof(tol_cnt));
        memset(c, 0, sizeof(c));

        for(int i=1; i<=n; i++) {
            tol_cnt[num[i]]++;
        }
        for(int i=1; i<=sz; i++) {
            tol_small[i] = tol_small[i-1] + tol_cnt[i-1];
        }
        for(int i=sz; i>=1; i--) {
            tol_large[i] = tol_large[i+1] + tol_cnt[i+1];
        }

        LL all_less = 0;
        for(int i=1; i<=n; i++) {
            left_large[i] = get_sum(sz) - get_sum(num[i]);
            right_large[i] = tol_large[num[i]] - left_large[i];

            left_small[i] = get_sum(num[i]-1);
            right_small[i] = tol_small[num[i]] - left_small[i];

            all_less += right_small[i];

            update(num[i], 1);
        }

        LL ans = 0;
        for(int i=1; i<=n; i++) {
            ans += left_small[i] * (all_less - left_large[i] - right_small[i]);
            ans -= right_large[i] * (left_large[i] + right_small[i]);
        }

        printf("%I64d\n", ans);
    }

    return 0;
}
