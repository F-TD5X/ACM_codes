#include <cstdio>
#include <cstring>
#include <cstdlib>
#define LL long long 
#define MAXN 216000+10
#define min(a,b) ((a)<(b)?(a):(b))
LL a[MAXN];
int main(void) {
    int i, j, k, p;
    i = j = k = 0; 
    a[0] = 1;
    for (p = 1; p <= 12690; ++p) {
        a[p] = min(a[i]*2, min(a[j]*3, a[k]*5));
        if (a[p] == a[i] * 2) ++i;
        if (a[p] == a[j] * 3) ++j;
        if (a[p] == a[k] * 5) ++k;
    }
    int T; scanf("%d",&T);
    while (T--) {
        LL n;
        scanf("%I64d", &n);
        int low = 1, high = 12690, mid, last;
        LL goal;
        goal = n;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (a[mid] < goal) low = mid + 1;
            else if (a[mid] > goal) high = mid - 1;
            else {last = mid; break;}
        }
        if (high == low) {
            last = high;
        }
        else if (low > high) last = low;
        if (goal == 1) last = 1;
        if (a[last] < goal) last++;
        printf("%I64d\n", a[last]);
    }

    return 0;
}
