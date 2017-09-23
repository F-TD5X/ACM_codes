/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
map<char,int> mp;
vector<int> G[55];
char s[55][2];
bool vis[55];

bool dfs(int st,int cnt){
	vis[st]=1;
	if(mp[s[st][0]]==1 && mp[s[st][1]]==1 && cnt !=n)
		return 0;
	else if(cnt == n)
		return 1;
	bool ret=0;
	for(auto v:G[st]){
		ret |=dfs(v,cnt+1);
	}
	vis[st]=0;
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("H.in","r",stdin);
    //freopen("H.out","w",stdout);
#endif
	while(cin >> n){
		mp.clear();
		for(int i=1;i<=n;i++){
			cin >>s[i];
			mp[s[i][0]]++;
			mp[s[i][1]]++;
			G[i].clear();
		}
		bool flag=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(s[i][0]==s[j][0] || s[i][1]==s[j][1]){
					G[i].push_back(j);
					G[j].push_back(i);
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(mp[s[i][0]]==1 || mp[s[i][1]]==1)
				if(dfs(i,1)){
					flag=1;
					break;
				}
		}
		if(flag)
			puts("YES");
		else
			puts("NO");
	}

	return 0;
}
