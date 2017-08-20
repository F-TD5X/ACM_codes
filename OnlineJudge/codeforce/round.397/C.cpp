<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	int k,a,b;
	cin >>k>>a>>b;
	if((a%k && b<k) || (b%k && a<k))
		return puts("-1"),0;
	cout << a/k+b/k <<endl;
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	int k,a,b;
	cin >>k>>a>>b;
	if((a%k && b<k) || (b%k && a<k))
		return puts("-1"),0;
	cout << a/k+b/k <<endl;
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
