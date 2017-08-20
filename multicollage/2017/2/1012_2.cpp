/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2000;
int n;
int px[maxn],py[maxn];
int mp[maxn][maxn];
const double eps =1e-7;

bool isok(int x,int y)
{
	if(-100 <=x-200 && x-200<=100 && -100 <=y-200  && y-200<=100)
		return 1;
	return 0;
}


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1012_2.in","r",stdin);
    //freopen("1012_2.out","w",stdout);
#endif
	while(~scanf("%d",&n)){
		memset(mp,0,sizeof(mp));
		for(int i=0;i<n;i++)
			scanf("%d%d",px+i,py+i);
		for(int i=0;i<n;i++){
			px[i]+=200,py[i]+=200;
			mp[px[i]][py[i]]=1;
		}
		int ans=0;
		int dx,dy;
		int xx,yy,xxx,yyy;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j)
					continue;
				dx=px[i]-px[j],dy=py[i]-py[j];
				xx=px[j]+dy,yy=py[j]-dx;
				xxx=xx+dx,yyy=yy+dy;
				if(isok(xx,yy) && isok(xxx,yyy) && mp[xx][yy] && mp[xxx][yyy])
						ans++;
			}
		}
		printf("%d\n",ans/4);
	}
	return 0;
}
