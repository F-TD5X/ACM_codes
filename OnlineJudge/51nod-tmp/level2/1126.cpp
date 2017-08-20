#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=7;
struct M
{
	int m[4][4];
	M(int n=0)
	{
		memset(m,0,sizeof(m));
		if(n==1)
			for(int i=0;i<4;i++)
				m[i][i]=1;
	}
};

M operator*(M a,M b)
{
	M c(0);
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			int t=0;
			for(int k=0;k<3;k++)
				t=(t+a.m[i][k]*b.m[k][j]+7)%mod;
			c.m[i][j]=t;
		}
	return c;
}

void pow_mod(M &m,int p)
{
	M t=m,ans(1);
	while(p)
	{
		if(p&1)
			ans=ans*t;
		t=t*t;
		p>>=1;
	}
	m=ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1126.in","r",stdin);
    //freopen("1126.out","w",stdout);
#endif
	int a,b,n;
	cin >> a >> b >> n;
	M tp;
	tp.m[0][0]=a;
	tp.m[1][0]=b;
	tp.m[0][1]=1;
	M d;
	d.m[0][0]=1;
	d.m[0][1]=1;
	pow_mod(tp,n-2);
	M c=d*tp;
	/*for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			cout << c.m[i][j] <<" ";
		cout <<endl;
	}*/
	cout << c.m[0][0]<<endl;
	return 0;
}

