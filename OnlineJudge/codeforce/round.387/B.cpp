#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	int n;
	string s;
	cin >> n >> s;
	if(n%4)
		return puts("==="),0;
	int a,c,g,t;
	a=c=g=t=n/4;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='A')
			a--;
		if(s[i]=='C')
			c--;
		if(s[i]=='G')
			g--;
		if(s[i]=='T')
			t--;
	}
	if(a<0||c<0||g<0||t<0)
		return puts("==="),0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='?')
		{
			if(a)
			{
				s[i]='A',a--;continue;
			}
			if(c)
			{
				s[i]='C',c--;continue;
			}
			if(g)
			{
				s[i]='G',g--;continue;
			}
			if(t)
			{
				s[i]='T',t--;continue;
			}
		}
	}
	cout << s << endl;
	return 0;
}
