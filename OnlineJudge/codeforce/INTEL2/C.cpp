#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+100;
vector<int> a[maxn*2],b[maxn*2];
ll ans[maxn];
pair<int,int> po[maxn];
const int dir[4][2]={1,1,1,-1,-1,-1,-1,1};

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	int n,m,k;
	cin >> n >> m >> k;
	memset(ans,-1,sizeof(ans));
	for(int i=0,x,y;i<k;i++)
	{
		cin >> x >> y;
		po[i]=make_pair(x,y);
		a[x-y+maxn].push_back(i);
		b[x+y].push_back(i);
	}
	int x=0,y=0,id=0;
	ll t=0;
	while(1)
	{
		if(id&1)
		{
			for(auto u:b[x+y])
				if(!~ans[u])
					ans[u]=t+abs(po[u].first-x);
			b[x+y].clear();
		}
		else
		{
			for(auto u:a[x-y+maxn])
				if(!~ans[u])
					ans[u]=t+abs(po[u].first-x);
			a[x-y+maxn].clear();
		}
		int u=dir[id][0];
		int v=dir[id][1];
		int tx=u>0?n-x:x;
		int ty=v>0?m-y:y;
		if(tx==ty)
			break;
		if(tx<ty)
		{
			if(id&1)
				(id+=1)&=3;
			else
				(id+=3)&=3;
			x+=tx*u;
			y+=tx*v;
			t+=tx;
		}
		else
		{
			if(id&1)
				(id+=3)&=3;
			else
				(id+=1)&=3;
			x+=ty*u;
			y+=ty*v;
			t+=ty;
		}
	}
	for(int i=0;i<k;i++)
		cout << ans[i]<<endl;
	return 0;
}
