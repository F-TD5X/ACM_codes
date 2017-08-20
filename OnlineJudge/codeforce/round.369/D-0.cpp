#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int n,a[SZ];
int M=0,fst[SZ],vb[SZ],nxt[SZ];
void ad_de(int a,int b)
{
	++M; nxt[M]=fst[a]; fst[a]=M; vb[M]=b;
}
int ds[SZ],qs[SZ];
void adde(int a,int b) {++ds[a]; ++ds[b]; ad_de(a,b); ad_de(b,a);}
void fc()
{
	int h=0,t=0;
	for(int i=1;i<=n;i++)
	{
		if(ds[i]==1)
		{
			ds[i]=0; qs[t++]=i;
		}
	}
	while(h!=t)
	{
		int x=qs[h++];
		for(int e=fst[x];e;e=nxt[e])
		{
			int b=vb[e]; --ds[b];
			if(ds[b]==1)
			{
				ds[b]=0; qs[t++]=b;
			}
		}
	}
}
int ff[SZ];
int gf(int x)
{
	return ff[x]?ff[x]=gf(ff[x]):x;
}
void uni(int a,int b)
{
	int ga=gf(a),gb=gf(b);
	if(ga^gb) ff[ga]=gb;
}
int cyc[SZ];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		adde(i,a[i]);
		uni(i,a[i]);
	}
	fc();
	int ff=n;
	for(int i=1;i<=n;i++)
	{
		if(ds[i]==2) --ff, cyc[gf(i)]++;
	}
	ll ans=1,MOD=1000000007;
	for(int i=1;i<=ff;i++) ans=ans*2%MOD;
	for(int i=1;i<=n;i++)
	{
		if(!cyc[i]) continue;
		ll tmp=1;
		for(int j=1;j<=cyc[i];j++) tmp=tmp*2%MOD;
		tmp=(tmp-2)%MOD;
		ans=ans*tmp%MOD;
	}
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}



int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D-0.in","r",stdin);
    //freopen("D-0.out","w",stdout);
#endif

    return 0;
}
