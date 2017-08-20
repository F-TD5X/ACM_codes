#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pm[50];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	ll n,k;
	for(int i=1;i<=50;i++)
		pm[i]=pow(2,i);
	while(cin >> n >> k)
	{
		if(k%2)
			cout << 1 <<endl;
		else
		{
			for(int i=n;i>=0;i--)
			{
				if((k-pm[i-1])%pm[i]==0)
				{
					cout << i<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
