#include <stdio.h>
typedef long long ll;
int main() {
    int  n, x;
    int  c1 = 0, c2 = 0, cother = 0;
    ll ans = 0;
    
    for(scanf("%d",&n);n--;) 
    {
        scanf("%d",&x);
        if(x==1) 
            ++c1;
        else if(x==2) 
            ++c2;
        else ++cother;
    }
    ans = (ll)c1*(c1+c2+cother-1)+(ll)c2*(c2-1)/2;
    printf( "%I64d\n", ans );
    return 0;
}
