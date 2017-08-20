#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int p[100010],x,y,n,a;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("J.in","r",stdin);
    //freopen("J.out","w",stdout);
#endif
	cin >> n;
	for(int i=1,a=0;i<=n;i++)
	{
		cin >> x >> y;
		a=0;
		int j;
		for(j=1;j*j<x;j++)
		{
			if(x%j==0)
			{
				if(p[j]<i-y)
					a++;
				p[j]=i;
				if(p[x/j]<i-y)
					a++;
				p[x/j]=i;
			}
		}
		if(x%j==0)
		{
			if(p[j]<i-y)
				a++;
			p[j]=i;
		}
		cout << a<<endl;
	}
	return 0;
}
