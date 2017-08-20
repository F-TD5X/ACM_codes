#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
ll D,K,A,B,T,mi;


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("d.in","r",stdin);
    //freopen("d.out","w",stdout);
#endif
	cin>>D>>K>>A>>B>>T;
	if(A*K+T>=B*K) 
    {
		cout<<min(D,K)*A + max(0LL,D-K)*B << endl;
	}
	else 
    {
		ll mi=1LL<<60;
		for(int x=0;x<=min(D,K);x++) 
        {
			ll mv=D-x;
			ll fix=max(0LL,(mv+K-1)/K-1);
			mi=min(mi,x*B + A*(D-x) + fix*T);
		}
		cout<<mi<<endl;
	}
    return 0;
}
