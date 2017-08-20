/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
#define FI first
#define SE second
using namespace std;
typedef long long ll;
const int maxn=1e5+100;
int T;
int n;
int val[maxn];
int ans[maxn];
vector<int> mp[maxn];
bool vis[maxn];
set<int> s1,s2;

void dfs(int st,bool l){
	if(mp[st].size()==1 && vis[mp[st][0]]){
		if(l)
			s1.insert(val[st]);
		else
			s2.insert(val[st]);
		ans[st]=val[st];
		return;
	}
	vis[st]=1;
	bool flag=1;
	for(auto v:mp[st]){
		if(!vis[v]){
			dfs(v,flag);
			flag=!flag;
		}
	}
	s1.insert(s2.begin(),s2.end());
	s1.insert(val[st]);
	int tmp=0;
	for(auto v:s1){
		ans[st]+=tmp+v;
		tmp+=v;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1001.in","r",stdin);
    //freopen("1001.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		for(int i=0;i<=n;i++)
			mp[i].clear();
		for(int i=1;i<=n;i++){
			scanf("%d",val+i);
		}
		for(int u,v,i=1;i<n;i++){
			scanf("%d%d",&u,&v);
			mp[u].push_back(v);
			mp[v].push_back(u);
		}
		dfs(1,1);
		for(int i=1;i<=n;i++){
			printf("%d ",ans[i]);
		}
		puts("");

	}

	return 0;
}
