#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

char s[1000];
int n,k,pos;
bool flag;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	flag=0;
	cin >> n >> k;
	for(int i=0;i<n;i++)
	{
		cin >>s[i];
		if(s[i]=='G')
			pos=i;
	}
	for(int i=pos;i>=0;i-=k)
	{
		if(s[i]=='T')
		{
			flag=1;
			break;
		}
		else if(s[i]=='#')
			break;
	}
	for(int i=pos;i<n;i+=k)
	{
		if(s[i]=='T')
		{
			flag=1;break;
		}
		else if(s[i]=='#')
			break;
	}
	if(flag)
		puts("YES");
	else
		puts("NO");
	return 0;
}
