#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e6+100;
int n;
int a[maxn],b[maxn];
int x,k;

int extE(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;y=0;
		return a;
	}
	int ans=extE(b,a%b,x,y);
	int tmp=x;
	x=y;
	y=tmp-a/b*y;
	return ans;
}

int CRT(int a[],int m[],int n)
{
	int M=1;
	int ret=0;
	for(int i=0;i<n;i++)
		M*=m[i];
	for(int i=0;i<n;i++)
	{
		int x,y;
		int Mi=M/m[i];
		extE(Mi,m[i],x,y);
		ret=(ret+Mi*x*a[i])%M;
	}
	if(ret<0)
		ret+=M;
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	while(cin >> x >> k)
	{
		for(int i=0;i<x;i++)
		{
			cin >> a[i];
			b[i]=x%a[i];
		}
		int ret=CRT(b,a,x);
		if(ret==x)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
