/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=7;

struct M{
	int m[2][2];
	M(){memset(m,0,sizeof(m));}
	M operator*(const M & t){
		M ret;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				for(int k=-0;k<2;k++)
					ret.m[i][j]=(ret.m[i][j]+m[i][k]*t.m[k][j])%mod;
		return ret;
	}
};


M mpm(M a,int n){
	M ret;
	ret.m[0][0]=ret.m[1][1]=1;
	while(n){
		if(n%2)
			ret=ret*a;
		a=a*a;
		n>>=1;
	}
	return ret;
}

void show(M t){
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++)
			cout << t.m[i][j] <<" ";
		cout << endl;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1126.in","r",stdin);
    //freopen("1126.out","w",stdout);
#endif
	int a,b,n;
	M tmp;
	tmp.m[0][0]=tmp.m[1][0]=1;
	while(cin >> a >>b >> n){
		M B;
		B.m[0][0]=(a%mod+mod)%mod;B.m[0][1]=(b%mod+mod)%mod;B.m[1][0]=1;B.m[1][1]=0;
		if(n<2){
			cout <<1 <<endl;
			continue;
		}
		M ret=mpm(B,n-2)*tmp;;
		cout << ret.m[0][0]<<endl;
	}
	return 0;
}
