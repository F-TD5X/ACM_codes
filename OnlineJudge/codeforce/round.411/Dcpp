#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


const ll MOD=1e9+7;
string s;
ll a,b;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	cin >> s;
	for(int i=s.size()-1;i>=0;i--)
	{
		if(s[i]=='b')
			b=(b+1)%MOD;
		if(s[i]=='a')
		{
			a=(a+b)%MOD;
			b=(b<<1)%MOD;
		}
	}
	cout << a << endl;

	return 0;
}
