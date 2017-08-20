#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1111;
int m[maxn][maxn],pm[maxn][maxn];
int r,c,k;
int ansi,ansa;


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	int T;
	scanf("%d",&T);
	while(T--){
		memset(m,0,sizeof(m));
		memset(pm,0,sizeof(pm));
		ansi=1e9;
		scanf("%d%d%d",&r,&c,&k);
		for(int i=1;i<=r;++i)
			for(int j=1;j<=c;++j)
				scanf("%d",&pm[i][j]);
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				pm[i][j]+=pm[i][j-1];
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				pm[i][j]+=pm[i-1][j];
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++)
				cout << pm[i][j] <<" ";
			puts("");
		}
		for(int i=k;i<=r;++i)
			for(int j=k;j<=c;j++){
				ansi=min(ansi,pm[i][j]-pm[i-k][j]-pm[i][j-k]+pm[i-k][j-k]);
			}
		cout <<ansi <<" " << m[r][c]<<endl;
	}

	return 0;
}
