<<<<<<< HEAD
<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e6;
int s[maxn],z[maxn],ans[maxn];
int n,cnt;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> s[i];
		if(s[i]==0)
			z[cnt++]=i;
	}
	for(int i=0;i<z[0];i++)
		ans[i]=z[0]-i;
	for(int i=z[cnt-1];i<n;i++)
		ans[i]=i-z[cnt-1];
	for(int i=0;i<cnt-1;i++){
		int u=z[i],v=z[i+1];
		for(int j=u+1;j<=(u+v)/2;j++)
			ans[j]=j-u;
		for(int j=v-1;j>(u+v)/2;j--)
			ans[j]=v-j;
	}
	for(int i=0;i<n;i++)
		cout << ans[i] <<" ";

	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e6;
int s[maxn],z[maxn],ans[maxn];
int n,cnt;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> s[i];
		if(s[i]==0)
			z[cnt++]=i;
	}
	for(int i=0;i<z[0];i++)
		ans[i]=z[0]-i;
	for(int i=z[cnt-1];i<n;i++)
		ans[i]=i-z[cnt-1];
	for(int i=0;i<cnt-1;i++){
		int u=z[i],v=z[i+1];
		for(int j=u+1;j<=(u+v)/2;j++)
			ans[j]=j-u;
		for(int j=v-1;j>(u+v)/2;j--)
			ans[j]=v-j;
	}
	for(int i=0;i<n;i++)
		cout << ans[i] <<" ";

	return 0;
}
>>>>>>> e30efc2bee7b85c64b5cc40b21a84d4cb2f8cc56
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e6;
int s[maxn],z[maxn],ans[maxn];
int n,cnt;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> s[i];
		if(s[i]==0)
			z[cnt++]=i;
	}
	for(int i=0;i<z[0];i++)
		ans[i]=z[0]-i;
	for(int i=z[cnt-1];i<n;i++)
		ans[i]=i-z[cnt-1];
	for(int i=0;i<cnt-1;i++){
		int u=z[i],v=z[i+1];
		for(int j=u+1;j<=(u+v)/2;j++)
			ans[j]=j-u;
		for(int j=v-1;j>(u+v)/2;j--)
			ans[j]=v-j;
	}
	for(int i=0;i<n;i++)
		cout << ans[i] <<" ";

	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
