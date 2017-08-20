#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=5555;
int n;
int xl[maxn],xr[maxn],yl[maxn],yr[maxn],x[maxn],y[maxn];

bool solve(int *a,int *b,int *c,int n)
{
	fill(c,c+n,-1);
	for(int co=1;co<=n;co++)
	{
		int r=-1,mb=n+1;
		for(int i=0;i<n;i++)
			if(c[i]<0&&b[i]<mb&&co>=a[i])
			{
				r=i;mb=b[i];
			}
		if(r<0||co>mb)
			return 0;
		c[r]=co;
	}
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("11134.in","r",stdin);
    //freopen("11134.out","w",stdout);
#endif
	while(cin >> n)
	{
		for(int i=0;i<n;i++)
			cin>>xl[i]>>yl[i]>>xr[i]>>yr[i];
		if(solve(xl,xr,x,n) && solve(yl,yr,y,n))
			for(int i=0;i<n;i++)
				cout <<x[i]<<" " << y[i]<<endl;
		else
			puts("IMPOSSIBLE");
	}
	return 0;
}
