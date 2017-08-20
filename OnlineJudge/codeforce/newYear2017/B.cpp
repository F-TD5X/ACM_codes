#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int now=0;
bool flag=0;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	int n,m,T,d;
	string s;
	cin >> T;
	while(T--)
	{
		cin >> d >> s;
		if(now==0||now==20000)
		{
			if(s[0]=='E'||s[0]=='W')
				flag=1;
		}
		if(s[0]=='N')
			now-=d;
		else if(s[0]=='S')
			now+=d;
		if(now<0||now>20000)
			flag=1;
	}
	if(now!=0)
		flag=1;
	cout <<(flag?"NO":"YES")<<endl;
	return 0;
}
