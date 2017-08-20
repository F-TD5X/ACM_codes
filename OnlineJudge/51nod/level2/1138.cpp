/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1138.in","r",stdin);
    //freopen("1138.out","w",stdout);
#endif
	    int sum;
    scanf("%d",&sum);
    int m=sqrt(sum*2+0.5);
    bool ok=false;
    for(int i=m;i>=2;i--)
    {
        if((sum-i*(i-1)/2)%i==0)
        {
            ok=true;
            int a=(sum-i*(i-1)/2)/i;
            printf("%d\n",a);
        }
    }
    if(!ok)  printf("No Solution\n");
	return 0;
}
