#include<bits/stdc++.h>
using namespace std;
#define mp(x,y) make_pair(x,y)
typedef long long ll;

const int maxn=5e5+10;
int n;
map<pair<int,int>,char> mp;
int xx,yy;
int x,y;
char c;
int mov_b[8][2]={2,1,2,-1,1,2,1,-2,-2,1,-2,-1,-1,2,-1,-2};
int mov_r[4][2]={1,-1,-1,-1,1,1,-1,1};
int mov_q[8][2]={1,-1,-1,-1,1,1,-1,1,1,0,-1,0,0,1,0,-1};
map<pair<int,int>,pair<int,int>> pos;

pair<int,int> Min(pair<int,int> a,pair<int,int> b)
{
	if(a<b)
		return a;
	return b;
}

struct Node
{
	char c;
	int x,y;
}BQ[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	int cnt=0;
	cin >> n;
	cin >>xx>>yy;
	bool flag=0;
	for(int i=-1;i<=1;i++)
		for(int j=-1;j<=1;j++)
			pos[{i,j}]=mp(0x3f3f3f3f,0x3f3f3f3f);
	for(int i=0;i<n;i++)
	{
		scanf("%s%d%d",&c,&x,&y);
		if(c=='R')
		{
			for(int i=0;i<8;i++)
				if(x==xx+mov_b[i][0] && y==yy+mov_b[i][1]) {flag=1;break;}
			int tx=xx-x,ty=yy-y;
			if(tx)
				tx/=abs(tx);
			if(ty)
				ty/=abs(ty);
			pos[{tx,ty}]=Min({abs(xx-x),abs(yy-y)},pos[{tx,ty}]);
		}
		else if(c=='B')
		{
			int tx=xx-x,ty=yy-y;
			if(tx)
				tx/=abs(tx);
			if(ty)
				ty/=abs(ty);
			if(tx==0 || ty==0)
				pos[{tx,ty}]=Min({abs(xx-x),abs(yy-y)},pos[{tx,ty}]);
			if(abs(xx-x)==abs(yy-y))
				BQ[cnt++]={c,x,y};
		}
		else if(c=='Q')
		{
			if(abs(xx-x)==abs(yy-y))
				continue;
			BQ[cnt++]={c,x,y};
		}
		if(flag)
			break;
	}

	for(int i=0;i<cnt;i++)
	{
		x=BQ[i].x;y=BQ[i].y;c=BQ[i].c;
		if(c=='B')
		{
			if(abs(xx-x)!=abs(yy-y))
				continue;
			int tx=xx-x,ty=yy-y;
			if(tx)
				tx/=abs(tx);
			if(ty)
				ty/=abs(ty);
			for(int i=0;i<4;i++)
				if(mov_r[i][0]==tx && mov_r[i][1]==ty &&(mp(abs(xx-x),abs(yy-y))<pos[{tx,ty}]))
				{flag=1;break;}
		}
		else if(c=='Q')
		{
			if(abs(xx-x)==abs(yy-y))
				continue;
			int tx=xx-x,ty=yy-y;
			if(tx)
				tx/=abs(tx);
			if(ty)
				ty/=abs(ty);
			for(int i=0;i<8;i++)
				if(mov_r[i][0]==tx && mov_r[i][1]==ty &&(mp(abs(xx-x),abs(yy-y))<pos[{tx,ty}]))
				{flag=1;break;}
		}
		if(flag)
			break;
	}
	if(flag)
		puts("YES");
	else
		puts("NO");
	return 0;
}
