#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int ans;
int x;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("J.in","r",stdin);
    //freopen("J.out","w",stdout);
#endif
	while(~scanf("%d",&n))
	{
		int t;
		ans=0;
		for(int i=0;i<n;i++)
		{
			t=0;
			scanf("%d",&x);
			while(x)
			{
				t+=!!((x & 0x000000ff)=='a');
				x>>=8;
			}
			ans+=t;
		}
		printf("%d\n",ans);
	}
	return 0;
}
