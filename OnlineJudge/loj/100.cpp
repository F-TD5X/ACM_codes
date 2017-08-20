<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=555,mod=1e9+7;
struct M{
	int m[maxn][maxn];
	int r,c;
	M operator*(const M & t){
		M ret;
		if(c!=t.r)
			return ret;
		ret.c=t.c;
		ret.r=r;
		for(int i=0;i<r;i++)
			for(int j=0;j<t.c;j++)
				for(int k=0;k<c;k++)
					ret.m[i][j]=(ret.m[i][j]+m[i][k]*t.m[k][i]+mod)%mod;
		return ret;
	}
};
M a,b;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("100.in","r",stdin);
    //freopen("100.out","w",stdout);
#endif
	int n,p,m;
	cin >> n >>p>> m;
	a.r=n;a.c=b.r=p;b.c=m;
	for(int i=0;i<a.r;i++)
		for(int j=0;j<a.c;j++)
			cin >> a.m[i][j];
	for(int i=0;i<b.r;i++)
		for(int j=0;j<b.c;j++)
			cin >> b.m[i][j];
	M c=a*b;
	for(int i=0;i<c.r;i++){
		for(int j=0;j<c.c;j++)
			cout << c.m[i][j] <<" ";
		cout << endl;
	}
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=555,mod=1e9+7;
struct M{
	int m[maxn][maxn];
	int r,c;
	M operator*(const M & t){
		M ret;
		if(c!=t.r)
			return ret;
		ret.c=t.c;
		ret.r=r;
		for(int i=0;i<r;i++)
			for(int j=0;j<t.c;j++)
				for(int k=0;k<c;k++)
					ret.m[i][j]=(ret.m[i][j]+m[i][k]*t.m[k][i]+mod)%mod;
		return ret;
	}
};
M a,b;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("100.in","r",stdin);
    //freopen("100.out","w",stdout);
#endif
	int n,p,m;
	cin >> n >>p>> m;
	a.r=n;a.c=b.r=p;b.c=m;
	for(int i=0;i<a.r;i++)
		for(int j=0;j<a.c;j++)
			cin >> a.m[i][j];
	for(int i=0;i<b.r;i++)
		for(int j=0;j<b.c;j++)
			cin >> b.m[i][j];
	M c=a*b;
	for(int i=0;i<c.r;i++){
		for(int j=0;j<c.c;j++)
			cout << c.m[i][j] <<" ";
		cout << endl;
	}
	return 0;
}
>>>>>>> 15efef77bd5e792465c034dce28c633a41daf492
