#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int a[maxn];
int n,c,b;
double ans1,ans2;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	cin >> n >> b >> c;
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	if(b>c)
		swap(c,b);
	int t=b;
	n--;
	while(t--)
		ans1+=a[n--];
	t=c;
	while(t--)
		ans2+=a[n--];
	printf("%.11f\n",ans1/b+ans2/c);
	return 0;
}
