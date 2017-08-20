#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=6005;
int n,a[maxn];

bool P(int x)
{
	if(x<2)
		return 0;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("G.in","r",stdin);
    //freopen("G.out","w",stdout);
#endif
	cin>>n;
    int m=n*(n+1)/2;
	fill(a,a+n+a,1);
    if(!P(m))
    {
        if(m&1&&!P(m-2)) 
			m-=3,a[3]=3;
        for(int i=2;i<m;i++)
            if(P(i)&&P(m-i)) 
			{
				a[i]=2;
			   	break;
			}
    }
    for(int i=1;i<=n;i++) 
		cout<<a[i]<<' ';
}
