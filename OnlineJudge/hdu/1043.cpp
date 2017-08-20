#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ma[1111][1111];
int a[11111111];
int n;
int posx,posy,pos;

int dfs(int x,int y)
{
	
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1043.in","r",stdin);
    //freopen("1043.out","w",stdout);
#endif
	int x;
	int cnt=0;
	while(cin >> x)
	{
		a[cnt++]=x;
		if(x=='x')
			pos=cnt-1;
	}
	n=sqrt(cnt+1);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			ma[i][j]=arr[i*n+j];
	posx=pos%n;
	posy=pos-pos/n*n;
	dfs(posx,posy);
	return 0;
}
