#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
const int maxn=310;
int t[maxn][maxn];
int cho[maxn];
int c[maxn];
int ans=0x3f3f3f3f;

int check()
{
	memset(c,0,sizeof(c));
	int temp[maxn]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			if(!cho[t[i][j]]){
				c[t[i][j]]++;
				temp[i]=1;
				break;
			}
		if(temp[i]=0)
			return 0;
	}
	int id=0;
	for(int i=1;i<=m;i++){
		if(c[i]>c[id])
			id=i;
	}
	if(id!=0)
	ans=min(ans,c[id]);
	return id;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> t[i][j];
	int id=0;
	while((id=check())!=0){
		cho[id]=1;
		id=0;
	}
	cout << ans <<endl;

	return 0;
}
