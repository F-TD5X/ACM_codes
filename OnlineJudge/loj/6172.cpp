/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=111;
const int mod=1e9+7;
int T;
int n,m,k;
ll v[maxn];
vector<int> mp;


ll solve(int st){
	if(v[st])
		return v[st];
	if(mp[st].size()==0){
		v[st]=m;
		return m;
	}
	ll ret=0;
	for(auto u:mp[st])
		ret=ret*solve(u)%mod;
	return v[st]=ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("6172.in","r",stdin);
    //freopen("6172.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&t);
		for(int u,v,i=0;i<n-1;i++){
			scanf("%d%d",&v,&u);
			mp[v].push_back(u);
		}
		cout << solve(1) << endl;

	}

	return 0;
}
