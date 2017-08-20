#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll mod=1e9+7;
int head[200111],nxt[400111],to[400111],etot=1;
vector<int>con[200111];
ll pw[200111];
int n,dis[200111],tot;
ll ans=1;
bool live[200111];
void dfs(int x,int pre=-1)
{
	live[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		if(!dis[to[i]])
		{
			dis[to[i]]=dis[x]+1;
			dfs(to[i],i/2);
		}
		else if(i/2!=pre&&live[to[i]])
		{
			ans=ans*(pw[dis[x]-dis[to[i]]+1]-2+mod)%mod;
			tot-=dis[x]-dis[to[i]]+1;
		}
	}
	live[x]=0;
}
int main()
{
	pw[0]=1;
	for(int i=1;i<=200005;i++)pw[i]=pw[i-1]*2%mod;
    cin >> n;
	tot=n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin >> x;
		nxt[++etot]=head[i];
		head[i]=etot;
		to[etot]=x;
		nxt[++etot]=head[x];
		head[x]=etot;
		to[etot]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(!dis[i])
		{
			dis[i]=1;
			dfs(i);
		}
	}
	cout<<ans*pw[tot]%mod<<endl;
	return 0;
}
