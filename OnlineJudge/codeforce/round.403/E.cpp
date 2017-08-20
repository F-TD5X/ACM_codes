<<<<<<< HEAD
//What hell?Why RE? The answer is right!!
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+1000;
int n,m,k;
vector<int> mp[maxn],ans[maxn];
int num_ans=0,step,Uset[maxn];

int UF(int x)
{
	if(x!=Uset[x]) return Uset[x]=UF(Uset[x]);
	return Uset[x];
}

void init(int n)
{
	for(int i=1;i<=n;i++)
		Uset[i]=i;
}

void dfs(int u,int pre)
{
	if(ans[num_ans].size()<step)
		ans[num_ans].push_back(u);
	else
		ans[++num_ans].push_back(u);
	for(auto v:mp[u])
		if(v!=pre)
			dfs(v,u);
	if(pre)
		if(ans[num_ans].size()<step)
			ans[num_ans].push_back(pre);
		else
			ans[++num_ans].push_back(pre);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("E.in","r",stdin);
    //freopen("E.out","w",stdout);
#endif
	cin >> n >> m >> k;
	step=2*n/k;
	init(n);
	for(int u,v,i=0;i<m;i++)
	{
		cin >> u >> v;
		if(UF(u)==UF(v)) continue;
		Uset[UF(u)]=v;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	dfs(1,0);
	for(int i=0;i<=min(num_ans,k-1);i++)
	{
		//cout <<"fuck test   "<<num_ans <<" " << k << " "<< i <<endl;
		
		if(ans[i].size()==0) {puts("1 1");continue;}
		cout << ans[i].size() <<" ";
		for(auto v:ans[i])
			cout << v <<" ";
		cout << endl;
	}
	return 0;
}
=======
//What hell?Why RE? The answer is right!!
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+1000;
int n,m,k;
vector<int> mp[maxn],ans[maxn];
int num_ans=0,step,Uset[maxn];

int UF(int x)
{
	if(x!=Uset[x]) return Uset[x]=UF(Uset[x]);
	return Uset[x];
}

void init(int n)
{
	for(int i=1;i<=n;i++)
		Uset[i]=i;
}

void dfs(int u,int pre)
{
	if(ans[num_ans].size()<step)
		ans[num_ans].push_back(u);
	else
		ans[++num_ans].push_back(u);
	for(auto v:mp[u])
		if(v!=pre)
			dfs(v,u);
	if(pre)
		if(ans[num_ans].size()<step)
			ans[num_ans].push_back(pre);
		else
			ans[++num_ans].push_back(pre);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("E.in","r",stdin);
    //freopen("E.out","w",stdout);
#endif
	cin >> n >> m >> k;
	step=2*n/k;
	init(n);
	for(int u,v,i=0;i<m;i++)
	{
		cin >> u >> v;
		if(UF(u)==UF(v)) continue;
		Uset[UF(u)]=v;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	dfs(1,0);
	for(int i=0;i<=min(num_ans,k-1);i++)
	{
		//cout <<"fuck test   "<<num_ans <<" " << k << " "<< i <<endl;
		
		if(ans[i].size()==0) {puts("1 1");continue;}
		cout << ans[i].size() <<" ";
		for(auto v:ans[i])
			cout << v <<" ";
		cout << endl;
	}
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
