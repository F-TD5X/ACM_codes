#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
int x,y;
int co;
ll list[1111];
int n,m,q;
ll ma[111111];
int cnt=1;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1004.in","r",stdin);
    //freopen("1004.out","w",stdout);
#endif
	int T;
	cin >>T;
	while(T--)
	{
		memset(ma,0,sizeof(ma));
		cin >> n >> m >> q;
		cnt=1;
		for(int i=1;i<=m;i++)
		{
			cin >>co;
			if(co==1)
			{
				cin >> x >> y;
				list[x]+=y;
				ma[i]=ma[i-1]+y;
			}
			else if(co==2)
			{
				cin >> x;
				ma[i]=ma[i-1]-list[x];
				list[x]=0;
			}
			else
			{
				cin >> x >> y;
				swap(list[x],list[y]);
				ma[i]=ma[i-1];
			}
		}
		while(q--)
		{
			cin >> x;
			cout <<ma[x]<<endl;
		}

	}
	return 0;
}
