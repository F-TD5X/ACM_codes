<<<<<<< HEAD
<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[105],vis[105];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
        scanf("%d",&a[i]);
    int f=1;
    for(int i=1;i<=k;i++)
    {
        a[i]%=(n-i+1);
        for(int j=0;j<a[i];j++)
        {
            f=f%n+1;
            while(vis[f])
				f=f%n+1;
        }
        vis[f]=1;
        printf("%d ",f);
        while(vis[f])
			f=f%n+1;
    }

	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[105],vis[105];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
        scanf("%d",&a[i]);
    int f=1;
    for(int i=1;i<=k;i++)
    {
        a[i]%=(n-i+1);
        for(int j=0;j<a[i];j++)
        {
            f=f%n+1;
            while(vis[f])
				f=f%n+1;
        }
        vis[f]=1;
        printf("%d ",f);
        while(vis[f])
			f=f%n+1;
    }

	return 0;
}
>>>>>>> e30efc2bee7b85c64b5cc40b21a84d4cb2f8cc56
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[105],vis[105];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
        scanf("%d",&a[i]);
    int f=1;
    for(int i=1;i<=k;i++)
    {
        a[i]%=(n-i+1);
        for(int j=0;j<a[i];j++)
        {
            f=f%n+1;
            while(vis[f])
				f=f%n+1;
        }
        vis[f]=1;
        printf("%d ",f);
        while(vis[f])
			f=f%n+1;
    }

	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
