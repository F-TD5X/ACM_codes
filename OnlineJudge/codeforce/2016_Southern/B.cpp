#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node
{
	int mi,ma,d;
	Node(int mi=0,int ma=0,int d=0):mi(mi),ma(ma),d(d){}
};
int n;
Node solve(int l,int r)
{
	if(l==r)
		return Node(l,l,1);
	int mid=(l+r)>>1;
	Node a,b;
	a=solve(l,mid);
	b=solve(mid+1,r);
	Node ret;
	char ch;
	if(a.d ==1 && b.d==1)
	{
		printf("? %d %d\n",a.mi,b.mi);
		fflush(stdout);
		cin >>ch;
		if(ch == '<')
		{
			ret.ma=b.mi;
			ret.mi=a.mi;
		}
		else
		{
			ret.ma=a.mi;
			ret.mi=b.mi;
		}
	}
	else
	{
		printf("? %d %d\n",a.mi,b.mi);
		fflush(stdout);
		cin >>ch;
		if(ch == '<')
			ret.mi=a.mi;
		else
			ret.mi=b.mi;
		printf("? %d %d\n",a.ma,b.ma);
		fflush(stdout);
		cin >> ch;
		if(ch =='<')
			ret.ma=b.ma;
		else
			ret.ma=a.ma;
	}
	ret.d=a.d+1;
	return ret;
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
#endif
	int n;
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n;
		Node ans=solve(1,n);
		printf("! %d %d\n",ans.mi,ans.ma);
	}
	return 0;
}
