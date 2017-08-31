/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxn=400;
struct Point{
	int x,y;
}p[maxn];
int matching[maxn];
bool vis[maxn];
vector<int> G[maxn];
int L;

bool dfs(int st){
	for(auto v:G[st])
		if(!vis[v]){
			vis[v]=1;
			if(matching[v]==-1||dfs(matching[v])){
				matching[v]=st;
				matching[st]=v;
				return 1;
			}
		}
	return 0;
}

int Match(){
	int ret=0;
	memset(matching,-1,sizeof(matching));
	for(int i=1;i<=n;i++)
		if(matching[i]==-1){
			memset(vis,0,sizeof(vis));
			if(dfs(i))
				ret++;
		}
	return ret;
}

void Build(){
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y)<=L){
				G[i].push_back(j);
				G[j].push_back(i);
			}
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("3726.in","r",stdin);
    //freopen("3726.out","w",stdout);
#endif
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			scanf("%d%d",&p[i].x,&p[i].y);
			G[i].clear();
		}
		scanf("%d",&L);
		Build();
		Match();
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(matching[i]!=-1)
				cnt++;
		if(cnt==n) puts("YES");
		else puts("NO");
	}
	return 0;
}
