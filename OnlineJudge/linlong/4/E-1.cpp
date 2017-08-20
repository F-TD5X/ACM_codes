#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+100;
const int mod=1e9+7;
int cnt[100];
int a[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("E-1.in","r",stdin);
    //freopen("E-1.out","w",stdout);
#endif
	int T;
	cin >> T;
	int n;
	while(T--)
	{
		cin >> n;
		int x;
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			int t=log2(x);
			if(t==int(t))
				if(t==0)
					cnt[0]=(cnt[0]+1)%mod;
				else
					cnt[t]=(cnt[t]+cnt[t-1])%mod;
		}
		ll ans=0;
		for(int i=0;i<=16;i++)
			ans=(ans+cnt[i])%mod;
		cout << ans << endl;
	}
	return 0;

}
