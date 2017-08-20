<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,k;
int pre[maxn],after[maxn];
pair< int,int > sub[maxn];
int ans;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	cin >> n >> k;
	for(int i=0;i<n;i++)
		cin >>pre[i];
	for(int i=0;i<n;i++)
	{
		cin >> after[i];
		sub[i].first=pre[i]-after[i];
		sub[i].second=i;
	}
	sort(sub,sub+n);
	int i=0;
	for(i;i<k;i++)
		ans+=pre[sub[i].second];
	for(i;i<n;i++)
		ans+=min(pre[sub[i].second],after[sub[i].second]);
	cout << ans << endl;
	
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,k;
int pre[maxn],after[maxn];
pair< int,int > sub[maxn];
int ans;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	cin >> n >> k;
	for(int i=0;i<n;i++)
		cin >>pre[i];
	for(int i=0;i<n;i++)
	{
		cin >> after[i];
		sub[i].first=pre[i]-after[i];
		sub[i].second=i;
	}
	sort(sub,sub+n);
	int i=0;
	for(i;i<k;i++)
		ans+=pre[sub[i].second];
	for(i;i<n;i++)
		ans+=min(pre[sub[i].second],after[sub[i].second]);
	cout << ans << endl;
	
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
