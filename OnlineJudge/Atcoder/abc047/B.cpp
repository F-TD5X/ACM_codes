#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int X,Y,Q;
int x,y,a;
int ans=0;
int ma[111][111];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	cin >> X >> Y >> Q;
	memset(ma,0,sizeof(ma));
	for(int i=0;i<Q;i++)
	{
		cin >> x >> y>>a;
		if(a==1)
		{
			for(int i=1;i<=Y;i++)
				for(int j=1;j<=x;j++)
					ma[i][j]=1;
		}
		else if(a==2)
			for(int i=1;i<=Y;i++)
				for(int j=x+1;j<=X;j++)
					ma[i][j]=1;
		else if(a==3)
			for(int i=1;i<=y;i++)
				for(int j=1;j<=X;j++)
					ma[i][j]=1;
		else if(a==4)
			for(int i=y+1;i<=Y;i++)
				for(int j=1;j<=X;j++)
					ma[i][j]=1;
	}
	ans=0;
	for(int i=1;i<=Y;i++)
		for(int j=1;j<=X;j++)
			if(ma[i][j])
				ans++;
	cout <<X*Y-ans <<endl;
	return 0;
}
