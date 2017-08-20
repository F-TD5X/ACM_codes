#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[30];
ll ans;

int lcm(int a,int b)
{
	return a/__gcd(a,b)*b;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	while(cin >> n >> m)
	{
		ans=n;
		for(int i=0;i<m;i++)
			cin >> a[i];
		for(int i=1;i<(1<<m);i++)
		{
			int mult=1;
			int bits=0;
			for(int j=0;j<m;j++)
			{
				if(i&(1<<j))
				{
					++bits;
					mult=lcm(mult,a[j]);
				}
			}
			if(bits%2)
				ans-=n/mult;
			else
				ans+=n/mult;
		}
		cout <<ans<<endl;
	}
	return 0;
}
