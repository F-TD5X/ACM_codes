#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int h,m;
char c;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	cin >> n;
	cin >> h>>c>>m;
	if(n == 12)
	{
		if(h/10>=2)
		{
			if(h%10==0)
				h=h%10+10;
			else
				h%=10;
		}
		if(h/10==1 && h%10>=3)
			h=10;
		if(h==0)
			h=1;
	}
	else if(n==24)
	{
		if(h/10>=3)
			h%=10;
		if(h/10==2 && h%10>=4)
			h%=10;
	}
	if(m >=60)
		m%=10;
	printf("%.2d:%.2d\n",h,m);
	return 0;
}
