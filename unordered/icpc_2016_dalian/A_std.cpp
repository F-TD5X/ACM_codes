#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1005;
const int maxm=10005;
short gb_no[maxn];
int uset[maxn];
int urel[maxn];
short rmap[maxn];

int pair_rel[maxm][2];

void init(int n)
{
	memset(gb_no,-1,sizeof(gb_no));
	memset(urel,0,sizeof(urel));
	memset(rmap,0,sizeof(rmap));
	for(int i=1;i<=n;i++)
		uset[i]=i;
}

int fat(int ind,int &rel)
{
	if(uset[ind]==ind)
	{
		rel=0;
		return ind;
	}
	int relt,f;
	f=fat(uset[ind],relt);
	urel[ind]=relt^urel[ind];
	uset[ind]=f;
	rel=urel[ind];
	return f;
}

bool insert(int a,int b)
{
	int fa,fb,rela,relb,rel;
	fa=fat(a,rela);
	fb=fat(b,relb);
	rel=rela^relb^1;
	if(fa==fb && rel!=0)
		return false;
	if(fa!=fb)
	{
		uset[fa]=fb;
		urel[fa]=rel;
	}
	return 1;
}

bool set_fat_no(int a)
{
	int fa,rela;
	fa=fat(fa,rela);
	if(gb_no[fa]>=0 && gb_no[a]>=0)
		return (gb_no[fa]^gb_no[a])==rela;
	else if(gb_no[fa]==-1)
		gb_no[fa]=gb_no[a]^rela;
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("A_std.in","r",stdin);
    //freopen("A_std.out","w",stdout);
#endif
	int n,m,x,y,ai,bi,t=0;
	bool flag;
	while(~scanf("%d%d%d%d",&n,&m,&x,&y))
	{
		init(n);
		flag=1;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&ai,&bi);
			rmap[ai]=rmap[bi]=1;
			flag=flag && insert(ai,bi);
		}
		for(int i=0;i<x;i++)
		{
			scanf("%d",&ai);
			if(gb_no[ai]!=-1 && gb_no[ai]!=1)
				flag=0;
			gb_no[ai]=1;
			flag=flag&& set_fat_no(ai);
		}
		for(int i=0;i<y;i++)
		{
			scanf("%d",&bi);
			if(gb_no[bi]!=-1 && gb_no[bi]!=0)
				flag=0;
			gb_no[bi]=0;
			flag=flag&&set_fat_no(bi);
		}
		for(int i=1;i<=n;i++)
			flag=flag && (rmap[i]!=0 || gb_no[i]!=-1);
		printf("%s\n",flag?"YES":"NO");
	}
	return 0;
}
