<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100],b[100];
int n,l;

bool check(int pos)
{
	int tmp=(b[pos]-a[0]+l)%l;
	for(int i=0;i<n;i++)
		if((a[i]+tmp)%l!=b[(pos+i)%n])
			return 0;
	return 1;
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("b.in","r",stdin);
    //freopen("b.out","w",stdout);
#endif
	cin >> n >> l;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
		cin >>b[i];
	for(int i=0;i<n;i++)
		if(check(i))
		{
			puts("YES");
			return 0;
		}
	puts("NO");
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100],b[100];
int n,l;

bool check(int pos)
{
	int tmp=(b[pos]-a[0]+l)%l;
	for(int i=0;i<n;i++)
		if((a[i]+tmp)%l!=b[(pos+i)%n])
			return 0;
	return 1;
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("b.in","r",stdin);
    //freopen("b.out","w",stdout);
#endif
	cin >> n >> l;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
		cin >>b[i];
	for(int i=0;i<n;i++)
		if(check(i))
		{
			puts("YES");
			return 0;
		}
	puts("NO");
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
