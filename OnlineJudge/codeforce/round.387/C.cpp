#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
const int maxn=1e5+100;
int a[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	cin >> n >> q;
	int t,k,d,cnt=0,ans=0;
	while(q--)
	{
		cnt=ans=0;
		cin >> t>> k >> d;
		for(int i=1;i<=n;i++)
			if(a[i]<t) cnt++;
		if(cnt<k)
		{
		   	puts("-1");continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]<t)
			{
				a[i]=t-1+d;
				ans+=i;
				k--;
			}
			if(!k)
				break;
		}
		cout << ans << endl;
	}
	return 0;
}
