/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
#define FI first
#define SE second
using namespace std;
typedef long long ll;
int n,k;
const int maxn=1e6+100;
vector<pair<int,int>> mp[maxn];
int root;
int ans;
bool vis[maxn];
vector<int> leaf;

int dfs(int st){
	
	int ret=0;
	for(auto v:mp[st]){
		if(vis[v.FI])
			continue;
		ret+=dfs(v.FI)+v.SE;
	}
	return ret;
}

struct Node{
	int FI,SE;
	bool operator<(const Node &t) const{
		return FI>t.FI;
	}
};

int bfs(){
	k--;
	priority_queue<Node> q;
	q.push({0,1});
	Node t;
	int ret=0;
	while(!q.empty()){
		t=q.top();q.pop();
		if(t.FI && k){
			ret+=t.FI;
			if(mp[t.SE].size()==0 || mp[t.SE].size()==1)
				vis[t.SE]=1;
			k--;
		}
		for(auto v:mp[t.SE]){
			q.push({t.FI+v.SE,v.FI});
		}
	}
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1005.in","r",stdin);
    //freopen("1005.out","w",stdout);
#endif
	while(~scanf("%d%d",&n,&k)){
		ans=0;
		for(int i=0;i<=n;i++)
			mp[i].clear();
		memset(vis,0,sizeof(vis));
		for(int v,u,c,i=0;i<n-1;i++){
			scanf("%d%d%d",&v,&u,&c);
			mp[v].push_back({u,c});
		}
		ans=bfs();
		printf("%d\n",ans+dfs(1));
	}
	return 0;
}
