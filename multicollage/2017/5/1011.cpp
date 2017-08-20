/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e6;

int T,n,k;
int a[maxn];


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1011.in","r",stdin);
    //freopen("1011.out","w",stdout);
#endif
	scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
            sort(a,a+n);
            int ans=0;
            for(int i=n-1;i>=1;i--){
                if(a[i]-a[i-1]>k){ans=i;break;}
            }
        printf("%d\n",n-ans);
    }

	return 0;
}
