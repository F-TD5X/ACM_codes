#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+100;
int n;
int arr[maxn],b[maxn];

int fi(int t,int l,int r)
{
	int m;
	while(l<=r){
		m=(l+r)>>1;
		if(t >= b[m])
			l=m+1;
		else
			r=m-1;
	}
	return l;
}

bool Do(int *a)
{
	int len=1,pos;
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		if(a[i] >= b[len]){
			len++;
			b[len]=a[i];
		}
		else{
			pos=fi(a[i],1,len);
			b[pos]=a[i];
		}
	}
	if(len >= n-1)
		return 1;
	else
		return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("HDU-5532.in","r",stdin);
    //freopen("HDU-5532.out","w",stdout);
#endif
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",arr+i);
		}
		bool flag=Do(arr);
		reverse(arr+1,arr+1+n);
		flag |= Do(arr);
		if(flag)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
