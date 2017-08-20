<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=111111;
int n,l,r;
int a[maxn],b[maxn],c[maxn],p[maxn],pp[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	cin >> n >>l>>r;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++)
	{cin >> p[i];pp[p[i]]=i;}
	int mi=-0x3f3f3f3f;
	for(int val,i=1;i<=n;i++)
	{
		val=max(l,mi+a[pp[i]]+1);
		if(val>r)
		{puts("-1");return 0;}
		b[pp[i]]=val;
		mi=b[pp[i]]-a[pp[i]];
	}
	for(int i=1;i<=n;i++)
		cout <<b[i]<<" ";
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=111111;
int n,l,r;
int a[maxn],b[maxn],c[maxn],p[maxn],pp[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	cin >> n >>l>>r;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++)
	{cin >> p[i];pp[p[i]]=i;}
	int mi=-0x3f3f3f3f;
	for(int val,i=1;i<=n;i++)
	{
		val=max(l,mi+a[pp[i]]+1);
		if(val>r)
		{puts("-1");return 0;}
		b[pp[i]]=val;
		mi=b[pp[i]]-a[pp[i]];
	}
	for(int i=1;i<=n;i++)
		cout <<b[i]<<" ";
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
