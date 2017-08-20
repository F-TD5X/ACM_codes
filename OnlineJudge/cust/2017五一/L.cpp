#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1111;
int n;
int a[maxn],b[maxn];

int cmp(int a,int b)
{
	return a>b;
}

int low(int t)
{
	int l=0,r=n-1;
	while(r-l>1)
	{
		int m=(l+r)/2;
		if(b[m]>t)
			r=m;
		else
			l=m;
	}
	return b[r]==t?r:l;
}
set<int> s;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("L.in","r",stdin);
    //freopen("L.out","w",stdout);
#endif
	while(~scanf("%d",&n) && n)
	{
		s.clear();
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		for(int j=0;j<n;j++)
			scanf("%d",b+j);
		sort(a,a+n,cmp);
		sort(b,b+n);
		int ans=0;
		bool flag=0;
		for(int pos,i=0;i<n;i++)
		{
			pos=low(a[i]);
			while(s.count(pos))
				pos--;
			if(!flag)
			{
				s.insert(pos);
				cout << pos << endl;
				if(pos==0)
					flag=1;
				if(a[i] >b[pos])
					ans+=200;
				else if(a[i]<b[pos])
					ans-=200;
				continue;
			}
			if(a[i]<b[i])
				ans-=200;
		}
		cout <<ans << endl;
	}
	return 0;
}
