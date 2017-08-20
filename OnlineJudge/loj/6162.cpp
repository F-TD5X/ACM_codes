#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
double v,u;
const int maxn=1111;
double c[maxn],d[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("6162.in","r",stdin);
    //freopen("6162.out","w",stdout);
#endif
	cin >>n>>v>>u;
	for(int i=1;i<=n;i++)
		cin >> c[i];
	for(int i=1;i<=n;i++)
		cin >> d[i];
	double ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			ans+=u/(c[i]-d[i]*(j-1)-v);
		}
	printf("%.3f\n",ans);
	return 0;
}
