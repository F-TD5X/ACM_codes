/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=555;

int T,n,k;
bool vis[maxn];
int match[maxn],pre[maxn];
int mp[maxn][maxn];

int maxMatch(){
	int ret=0;
	memset(match,-1,sizeof(match));
	memset(vis,0,sizeof(vis));
	queue<int> q;
	int u;
	for(int i=1;i<=n;i++){
		if(match[i]==-1){
			while(!q.empty()) q.pop();
			q.push(i);
			pre[i]=-1;
			bool flag=0;
			while(!q.empty() && !flag){
				u=q.front();
				for(int v=1;v<=n && !flag;v++){
					if(mp[u][v] && !vis[v]){
						vis[v]=1;
						q.push(match[v]);
						if(match[v]>=0)
							pre[match[v]]=u;
						else{
							flag=1;
							int d=u,e=v;
							while(d!=-1){
								int t=match[d];
								match[d]=e;
								match[e]=d;
								d=pre[d];
								e=t;
							}
						}
					}
				}
				q.pop();
			}
			if(match[i]!=-1)
				++ret;
		}
	}
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1010.in","r",stdin);
    //freopen("1010.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		memset(mp,0,sizeof(mp));
		scanf("%d%d",&n,&k);
		for(int u,i=1;i<n;i++){
			scanf("%d",&u);
			mp[i][u]=1;
		}
		int t=maxMatch();
		cout << t << endl;
		if(t*2 == n && t<=k)
			puts("Bob");
		else
			puts("Alice");
	}
	return 0;
}
