#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000+10;
int cnt[N], a[N];
int main() 
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	int n, m;
	cin >> n >> m;
	int ans1(n / m);
	for(int i=0; i < n; i++) 
	{
		cin >> a[i];
		if(a[i] <= m)
			cnt[a[i]]++;
	}
	int ans2=0;
	for(int i=0; i < n; i++) 
	{
		if(a[i]>m||a[i]<=m&&cnt[a[i]]>ans1) 
		{
			for(int j(1);j<=m;j++) 
			{
				if(cnt[j]<ans1) 
				{
					if(a[i]<=m) 
						cnt[a[i]]--;
					a[i] = j;
					cnt[j] ++;
					ans2++;
					break;
				}
			}
		}
	}
	cout <<ans1<<" " << ans2<<endl;
	for(int i=0; i < n; i++)
		cout << a[i]<<" ";
}
