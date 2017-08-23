/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1111;
bool link[maxn][maxn],vis[maxn];
vector<int> mp[maxn];
int n,m;
int T;


void dfs(int st,int fa){
	vis[st]=1;
	for(auto v:mp[st]){
		if(!vis[v]){
			link[fa][v]=1;
			dfs(v,fa);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1005.in","r",stdin);
    //freopen("1005.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		memset(link,0,sizeof(link));
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++)
			mp[i].clear();
		for(int u,v,i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			mp[u].push_back(v);
		}
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			dfs(i,i);
		}
		bool flag=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				if(i!=j){
					if(!(link[i][j]  || link[j][i]))
						flag=0;
				}
		}
		if(flag)
			puts("I love you my love and our love save us!");
		else
			puts("Light my fire!");
	}
	return 0;
}
