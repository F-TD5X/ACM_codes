int dis[maxn][maxn];// 或者dis[maxn];

void spfa(int st){
	for(auto v:mp[st]){
		if(dis[v]>dis[st]+w[st][v])		//松弛操作
			dis[v]=dis[st]+w[st][v];
		spfa(v);
	}
}



