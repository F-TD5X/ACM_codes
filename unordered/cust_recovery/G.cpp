/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
const int maxn=55;

char mp[maxn][maxn];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("G.in","r",stdin);
    //freopen("G.out","w",stdout);
#endif
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin >> mp[i][j];
			}
		}
		for(int i=n;i;i--){
			for(int j=1;j<=m;j++){
				if(mp[i][j]=='o'){
					int k=i;
					for(k=i+1;k<=n;k++){
						if(mp[k][j]=='#' || mp[k][j]=='o')
							break;
					}
					mp[i][j]='.';
					mp[k-1][j]='o';
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				putchar(mp[i][j]);
			puts("");
		}
	}
	return 0;
}
