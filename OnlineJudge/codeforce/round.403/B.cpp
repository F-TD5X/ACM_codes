<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e6+10;
int n;
double ma,ans_x,ans,po[maxn],sp[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> po[i];
	for(int i=0;i<n;i++)
		cin >> sp[i];
	double l,r,mid,tl,tr;
	for(l=0,r=1e9;r-l>1e-9;tl=-2e9,tr=2e9)
	{
		mid=(l+r)/2;
		for(int i=0;i<n;i++)
		{
			tl=max(tl,po[i]-sp[i]*mid);
			tr=min(tr,po[i]+sp[i]*mid);
		}
		if(tl <= tr)
			r=mid;
		else
			l=mid;
	}
	printf("%.9f\n",(l+r)/2);
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e6+10;
int n;
double ma,ans_x,ans,po[maxn],sp[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> po[i];
	for(int i=0;i<n;i++)
		cin >> sp[i];
	double l,r,mid,tl,tr;
	for(l=0,r=1e9;r-l>1e-9;tl=-2e9,tr=2e9)
	{
		mid=(l+r)/2;
		for(int i=0;i<n;i++)
		{
			tl=max(tl,po[i]-sp[i]*mid);
			tr=min(tr,po[i]+sp[i]*mid);
		}
		if(tl <= tr)
			r=mid;
		else
			l=mid;
	}
	printf("%.9f\n",(l+r)/2);
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
