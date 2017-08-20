<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=4e6+100;
const int mod=998244353;
vector<int> ans;
struct UF{
	int f[maxn];
	void init(int n){
		for(int i=0;i<=n;i++)
			f[i]=i;
	}
	int Find(int x){
		return x==f[x]?f[x]:f[x]=Find(f[x]);
	}
	void Union(int v,int u){
		v=Find(v),u=Find(u);
		if(v!=u)
			f[u]=v;
	}
}uf;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("109.in","r",stdin);
    //freopen("109.out","w",stdout);
#endif
	int n,m;
	cin >> n >> m;
	uf.init(n);
	ll ans=0;
	for(int op,u,v,i=0;i<m;i++){
		scanf("%d%d%d",&op,&u,&v);
		if(op){
			ans=ans*2+(uf.Find(u)==uf.Find(v));
			if(ans>mod)
				ans%=mod;
		}
		else
			uf.Union(u,v);
	}
	cout << ans << endl;
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=4e6+100;
const int mod=998244353;
vector<int> ans;
struct UF{
	int f[maxn];
	void init(int n){
		for(int i=0;i<=n;i++)
			f[i]=i;
	}
	int Find(int x){
		return x==f[x]?f[x]:f[x]=Find(f[x]);
	}
	void Union(int v,int u){
		v=Find(v),u=Find(u);
		if(v!=u)
			f[u]=v;
	}
}uf;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("109.in","r",stdin);
    //freopen("109.out","w",stdout);
#endif
	int n,m;
	cin >> n >> m;
	uf.init(n);
	ll ans=0;
	for(int op,u,v,i=0;i<m;i++){
		scanf("%d%d%d",&op,&u,&v);
		if(op){
			ans=ans*2+(uf.Find(u)==uf.Find(v));
			if(ans>mod)
				ans%=mod;
		}
		else
			uf.Union(u,v);
	}
	cout << ans << endl;
	return 0;
}
>>>>>>> 15efef77bd5e792465c034dce28c633a41daf492
