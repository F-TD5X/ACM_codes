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
int T;
int x,t,k;
int ans;


void solve()
{
	int v=x;
	int ans=0;
	while(v>1)
	{
		if(v-t<=1)
			v=1,ans++;
		else if(v-v/k <= t)
			v-=t,ans++;
		else if(v%k==0 && v-t>1)
			v/=k,ans++;
		else
		{
			if(v==1)
				break;
			int p = v%k;
			v=v-v%k;
			ans+=p/t+p%t!=0?1:0;
		}
	}
	cout << ans << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1002.in","r",stdin);
    //freopen("1002.out","w",stdout);
#endif
	cin >>T;
	while(T--)
	{
		cin >> x>> k>>t;
		solve();
	}
	return 0;
}
