#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

long long F[100070];

void init(long long p)  
{  
    F[0] = 1;  
    for(int i = 1;i <= p;i++)  
        F[i] = F[i-1]*i % (10007);  
}  
long long inv(long long a,long long m)  
{  
    if(a == 1)return 1;  
    return inv(m%a,m)*(m-m/a)%m;  
}  
long long Lucas(long long n,long long m,long long p)  
{  
    long long ans = 1;  
    while(n&&m)  
    {  
        long long a = n%p;  
        long long b = m%p;  
        if(a < b)return 0;  
        ans = ans*F[a]%p*inv(F[b]*F[a-b]%p,p)%p;  
        n /= p;  
        m /= p;  
    }  
    return ans;  
}  

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	int t;
	cin >> t;
	LL n,m;
	init(100070);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		if(m==0)
		{
			puts("1");
			continue;
		}
		printf("%lld\n",(Lucas(m+n,m,1e4+7)-Lucas(m+n,m-1,1e4+7)+LL(1e4+7))%LL(1e4+7));
	}
	return 0;
}
