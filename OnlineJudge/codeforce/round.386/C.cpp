#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int s,x1,x2,t1,t2,p,d;
int ans=0;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	cin >> s >> x1>>x2>>t1>>t2>>p>>d;
	int tt1,tt2,tt3,tt4;
	tt2=abs(x1-x2)*t2;
	if(x1>x2)
	{
		if(d==1)
			tt1=(s-p+s-x2)*t1;
		else
		{
			if(p<x1)
				tt1=(s+p+s-x2)*t1;
			else
				tt1=(p-x2)*t1;
		}
	}
	else
	{
		if(d==1)
		{
			if(p>x1)
				tt1=(s+x2+s-p)*t1;
			else
				tt1=(x2-p)*t1;
		}
		else
			tt1=(p+x2)*t1;
	}
	cout <<min(tt1,tt2)<<endl;
	return 0;
}
