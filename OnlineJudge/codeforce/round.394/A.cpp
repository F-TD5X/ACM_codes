<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	int a,b;
	cin >> a>>b;
	if(a==b && a==0)
	{
		puts("NO");
		return 0;
	}
	if(abs(a-b)>1)
		puts("NO");
	else
		puts("YES");
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	int a,b;
	cin >> a>>b;
	if(a==b && a==0)
	{
		puts("NO");
		return 0;
	}
	if(abs(a-b)>1)
		puts("NO");
	else
		puts("YES");
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
