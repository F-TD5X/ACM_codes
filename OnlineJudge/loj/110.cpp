<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e6+100;
ll inv[maxn];
ll n,p;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("110.in","r",stdin);
    //freopen("110.out","w",stdout);
#endif
	cin >> n >> p;
	inv[1]=1;
	printf("%d\n",1);
	for(ll t,k,i=2;i<=n;i++){
		k=p%i;t=(p-k)/i;t=t*t%p;
		inv[i]=(i*t%p)*(inv[k]*inv[k]%p)%p;
		printf("%d\n",inv[i]);
	}

	return 0;
}

=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e6+100;
ll inv[maxn];
ll n,p;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("110.in","r",stdin);
    //freopen("110.out","w",stdout);
#endif
	cin >> n >> p;
	inv[1]=1;
	printf("%d\n",1);
	for(ll t,k,i=2;i<=n;i++){
		k=p%i;t=(p-k)/i;t=t*t%p;
		inv[i]=(i*t%p)*(inv[k]*inv[k]%p)%p;
		printf("%d\n",inv[i]);
	}

	return 0;
}

>>>>>>> 15efef77bd5e792465c034dce28c633a41daf492
