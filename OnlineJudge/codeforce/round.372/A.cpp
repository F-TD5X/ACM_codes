#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,t;
int x;
int ans;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	cin >> n >> t;
	int bef=0;
	bool ok=0;
	for(int i=0;i<n;i++)
	{
		cin >> x;
		if(i==0)
		{
			ans++;
			ok =1;
		}
		else
		{
			if(x-bef<=t)
			{
				ans++;
				ok=1;
			}
			else if(x-bef>t && ok)
			{
				ans=1;
				ok=0;
			}
		}
		bef=x;
	}
	cout <<ans<<endl;
	return 0;
}
