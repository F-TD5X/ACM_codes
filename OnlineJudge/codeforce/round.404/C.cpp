<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	scanf("%I64d%I64d",&n,&m);
	if(m>=n){
		printf("%I64d\n",n);
	}
	else{
		n-=m;
		ll l=0,r=2e9;
		while(l<r){
			ll m=(l+r)>>1;
			ll v=m*(m+1)/2;
			if(v>=n)
				r=m;
			else
				l=m+1;
		}
		printf("%I64d\n",l+m);

	}

	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	scanf("%I64d%I64d",&n,&m);
	if(m>=n){
		printf("%I64d\n",n);
	}
	else{
		n-=m;
		ll l=0,r=2e9;
		while(l<r){
			ll m=(l+r)>>1;
			ll v=m*(m+1)/2;
			if(v>=n)
				r=m;
			else
				l=m+1;
		}
		printf("%I64d\n",l+m);

	}

	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
