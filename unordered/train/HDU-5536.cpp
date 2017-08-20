#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[2000];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("HDU-5536.in","r",stdin);
    //freopen("HDU-5536.out","w",stdout);
#endif
	int T;  
    scanf("%d", &T);  
    while(T --)  
    {  
        int n, ma = 0;  
        scanf("%d" ,&n);  
        for(int i = 0; i < n; i++)  
            scanf("%d", &a[i]);  
        for(int i = 0; i < n; i++)  
            for(int j = i + 1; j < n; j++)  
                for(int k = j + 1; k < n; k++)  
                {  
                    ma = max(ma, (a[i] + a[j]) ^ a[k]);  
                    ma = max(ma, (a[i] + a[k]) ^ a[j]);  
                    ma = max(ma, (a[j] + a[k]) ^ a[i]);  
                }  
        printf("%d\n", ma);  
    }  
	return 0;
}
