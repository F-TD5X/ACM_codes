#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
const int maxn=1e4+100;
int arr[maxn];
int a,b,l,r,x,bef;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",arr+i);
	while(q--)
	{
		scanf("%d%d%d",&l,&r,&x);
		bef=arr[x];
		int cnt=0;
		for(int i=l;i<=r;i++)
			if(arr[i] < arr[x])
				cnt++;
		if(cnt != x-l)
			puts("No");
		else
			puts("Yes");
	}

	return 0;
}
