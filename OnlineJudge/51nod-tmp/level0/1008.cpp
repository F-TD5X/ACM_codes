#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int n,p;

int fast_multi_mod(int a,int b,int mod)
{
    long long ans = 0;
	while(b)
	{
		if(b & 1)
		{
			b--;
			ans =(ans+ a)%mod;
		}
		b /= 2;
		a = (a + a) % mod;
	}
	return ans;
}

int j(int b)
{
    int ret=1;
    for(int i=1;i<=b;i++)
    {
        ret=fast_multi_mod(ret,i,p);
    }
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1008.in","r",stdin);
    //freopen("1008.out","w",stdout);
#endif
    cin >> n>>p;
    int ans=j(n);
    cout << ans <<endl;


    return 0;
}
