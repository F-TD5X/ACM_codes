#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxn=1010;
int a[maxn],b[maxn];
int ans;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("L1.in","r",stdin);
    //freopen("L1.out","w",stdout);
#endif
	while(~scanf("%d",&n) && n)
	{
		ans=0;
		for(int i=0;i<n;i++)
			cin >> a[i];
		for(int i=0;i<n;i++)
			cin >> b[i];
		sort(a,a+n);
		sort(b,b+n);
		for(int i=0,j=0,k=n-1,l=n-1;i<=k;)
		{
			if(a[i]>b[j])
				ans++,i++,j++;
			else if(a[k]>b[l])
				ans++,l--,k--;
			else
			{
				if(a[i]<b[l])
					ans--;
				i++;l--;
			}
		}
		cout << ans*200<<endl;
	}
	return 0;
}
