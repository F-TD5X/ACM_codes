/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxn=555;
int px[maxn],py[maxn];
vector<pair<int,int>> dis[maxn];

bool _cmp(int v,int u){
	
}

int _dis(int i,int j)
{
	return (p[i].FI-p[j].FI)*(p[i].FI-p[j].FI)+(p[i].SE-p[j].SE)*(p[i].SE -p[j].SE);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1012_1.in","r",stdin);
    //freopen("1012_1.out","w",stdout);
#endif
	while(~scanf("%d",&n)){
		for(int x,y,i=0;i<n;i++){
			scanf("%d%d",px+i,py+i);
		}
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				dis[_dis(i,j)].push_back({i,j});

	}
	return 0;
}
