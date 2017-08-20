<<<<<<< HEAD
<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
double ans;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	while(cin >> n >> m) {
		ans=n;
		for(int i=n;i;i--) {
			ans-=pow(1.0*(i-1)/n,m);
		}
		printf("%.6f\n",ans);
	}
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
double ans;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	while(cin >> n >> m) {
		ans=n;
		for(int i=n;i;i--) {
			ans-=pow(1.0*(i-1)/n,m);
		}
		printf("%.6f\n",ans);
	}
	return 0;
}
>>>>>>> e30efc2bee7b85c64b5cc40b21a84d4cb2f8cc56
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
double ans;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	while(cin >> n >> m) {
		ans=n;
		for(int i=n;i;i--) {
			ans-=pow(1.0*(i-1)/n,m);
		}
		printf("%.6f\n",ans);
	}
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
