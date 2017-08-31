int matching[maxn];	//存储结果
int vis[maxn];

bool dfs(int st){			//寻找增广路
	for(auto v:G[st]){
		if(!vis[v]){		//在交替路中？
			vis[v]=1;
			if(matching[v]==-1||dfs(matching[v])){
				matching[v]=st;
				matching[st]=v;
				return 1;
			}
		}
	}
	return 0;
}

int Hungarian(){
	int ans=0;
	memset(matching,-1,sizeof(matching));
	for(int i=1;i<=n;i++){
		if(matching[i]==-1){
			memset(vis,0,sizeof(vis));
			if(dfs(i))
				++ans;
		}
	}
	return ans;				//匹配数
	/*若匹配数=
	 *
	 *
	 *
	 */
}

