#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e6*4;
char a[maxn];
int n,t;
char s[maxn];


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	int maxp=0;
	for (int i=1;i<=n;i++)
	{
		int pre,x;
		scanf("%s",s);
		scanf("%d",&t);
		int len=strlen(s);
		pre=-len;
		for (int j=1;j<=t;j++)
		{
			scanf("%d",&x);
			for (int k=max(0,pre+len-x);k<len;k++)
			{
				a[x+k]=s[k];
			}
			pre=x;
			maxp=max(maxp,pre);
		}
	}
	for (int j=maxp;j>=1;j--)
		if (a[j]==0) a[j]='a';
	printf("%s\n",a+1);

	return 0;
}
