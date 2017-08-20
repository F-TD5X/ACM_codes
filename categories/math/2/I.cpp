#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int ans,tmp;

void solve(int a,int b)
{
	if(!b)
	{
		tmp=n;
		return;
	}
	if(b==1)
	{
		tmp+=a-1;
		return ;
	}
	tmp+=a/b;
	solve(b,a%b);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("I.in","r",stdin);
    //freopen("I.out","w",stdout);
#endif
	int n;
	while(cin >> n)
	{
		ans=n-1;
		for(int i=1;i<n;i++)
		{
			tmp=0;
			solve(n,i);
			if(tmp)
				ans=min(ans,tmp);
		}
		cout << ans << endl;
	}
	return 0;
}
