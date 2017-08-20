<<<<<<< HEAD
<<<<<<< HEAD
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int T;
const int maxn=1e5+100;
ll arr[maxn];
ll ans,t;
int n;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%lld",arr+i);
		sort(arr,arr+n);
		for(int i=n-1;i>=0;--i)
			for(int j=i-1;j>=0;--j){
				t=arr[i]*arr[j];
				if(t*arr[j]<=ans)
					break;
				ans=max(ans,t*(arr[j]&arr[i]));
			}
		printf("%lld\n",ans);
	}
	return 0;
}
=======
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int T;
const int maxn=1e5+100;
ll arr[maxn];
ll ans,t;
int n;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%lld",arr+i);
		sort(arr,arr+n);
		for(int i=n-1;i>=0;--i)
			for(int j=i-1;j>=0;--j){
				t=arr[i]*arr[j];
				if(t*arr[j]<=ans)
					break;
				ans=max(ans,t*(arr[j]&arr[i]));
			}
		printf("%lld\n",ans);
	}
	return 0;
}
>>>>>>> e30efc2bee7b85c64b5cc40b21a84d4cb2f8cc56
=======
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int T;
const int maxn=1e5+100;
ll arr[maxn];
ll ans,t;
int n;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%lld",arr+i);
		sort(arr,arr+n);
		for(int i=n-1;i>=0;--i)
			for(int j=i-1;j>=0;--j){
				t=arr[i]*arr[j];
				if(t*arr[j]<=ans)
					break;
				ans=max(ans,t*(arr[j]&arr[i]));
			}
		printf("%lld\n",ans);
	}
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
