#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
<<<<<<< HEAD
int n;
int a[5000], le[5001], ri[5001], d[5001];
bool was[5001];


const int INF=0x3f3f3f3f;
=======
const int maxn=5000+100;
int n;
int arr[maxn];
set<int> used;

int *fi(int *l,int *r,int aim)
{
	int *ret=NULL;
	for(int *i =l;i<=r;i++)
		if(*i == aim)
			ret=i;
	if(ret != NULL)
		return ret;
	return r;
}

int solve(int rt)
{
	if(rt > n)
		return 0;
	if(used.count(arr[rt]))
		return solve(rt+1);
	int r= fi(arr+1,arr+n+1,arr[rt])-arr;
	int ret=0;
	set<int> s;
	for(int i=rt;i<=r && i <= n;i++)
	{
		if(used.count(arr[i]))
			return 0;
		s.insert(arr[i]);
		r=max(r,int(fi(arr+1,arr+n+1,arr[i])-arr));
		//cout << i <<" " << r <<" " << ret << endl;
	}
	for(auto a:s)
		ret^=a;
	return ret+solve(r+1);
}

>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
<<<<<<< HEAD
	for(int i=0;i<5001;i++) {
        le[i] = INF;
        ri[i] = -INF;
    }
    scanf("%d", &n);
    for(int i=0;i< n;i++) {
        scanf("%d", a + i);
        le[a[i]] = min(le[a[i]], i);
        ri[a[i]] = max(ri[a[i]], i);
    }
    for(int i=0;i< n + 1;i++) {
        d[i] = -INF;
    }
    d[0] = 0;
    for(int i=0;i< n;i++) 
		if (d[i] != -INF) {
        d[i + 1] = max(d[i + 1], d[i]);
        int l = i;
        int r = i;
        int sum = 0;
        memset(was, 0, sizeof was);
        for (int j = i; j <= r; ++j) {
            l = min(l, le[a[j]]);
            r = max(r, ri[a[j]]);
            if (!was[a[j]]) {
                was[a[j]] = true;
                sum ^= a[j];
            }
        }
        if (l == i) {
            d[r + 1] = max(d[r + 1], d[i] + sum);
        }
    }
    cout << d[n] << endl;
=======
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> arr[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(solve(i),ans);
		used.insert(arr[i]);
	}
	cout << ans << endl;
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
	return 0;
}
