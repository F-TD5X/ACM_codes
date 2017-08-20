/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=555;
int T,n,k;
vector<int > mp[maxn];
int num[maxn];
bool flag=0;

int dfs(int st){
	if(!flag)
		return 0;
	int now=0;
	for(int i=0;i<mp[st].size();i++){
		dfs(mp[st][i]);
		if(num[mp[st][i]]>=2)
			return flag=0;
		now+=num[mp[st][i]];
	}
	if(now==1){
		if(k)
			k--,num[st]=0;
		else
			num[st]=2;
	}
	else if(now==0)
		num[st]=1;
	else
		flag=0;
	return 0;
}


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1010.1.in","r",stdin);
    //freopen("1010.1.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		memset(num,0,sizeof(num));
		scanf("%d%d",&n,&k);
		for(int i=0;i<=n;i++)
			mp[i].clear();
		flag=1;
		for(int u,i=2;i<=n;i++){
			scanf("%d",&u);
			mp[u].push_back(i);
		}
		dfs(1);
		if(num[1]==1 || num[1]>2)
			flag=0;
		if(flag)
			puts("Bob");
		else
			puts("Alice");
	}
	return 0;
}
