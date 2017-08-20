/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;

struct M{
	int m[2][2];
	M(){m[0][0]=m[1][1]=1;m[0][1]=m[1][0]=0;}
	M operator*(const M&t) const{
		M ret;
		for(int i=0;i<2;i++)
			for(int tmp=0,j=0;j<2;j++){
				for(int k=0;k<2;k++)
					tmp=(tmp+m[i][k]*t.m[k][j])%mod;
				ret.m[i][j]=tmp;
			}
		return ret;
	}
	M operator-(const M &t) const{
		M ret;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				ret.m[i][j]=m[i][j]-t.m[i][j];
		return ret;
	}
};

M _mpow(M t,int n)
{
	M ret;
	M xt=ret;
	while(n){
		if(n%2)
			ret=ret*xt;
		xt=xt*xt;
		n/=2;
	}
	return t*ret;
}

int n;



int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1006.in","r",stdin);
    //freopen("1006.out","w",stdout);
#endif
	int T;
	cin >> T;
	int n,m;
	while(T--){
		cin >> n >> m;
		M m1,ret,m2,mn;
		m1.m[0][0]=1;m1.m[1][0]=m1.m[1][1]=0;m1.m[0][1]=2;
		m2-m1;
		mn= m1*_mpow(_mpow(m1,n)-m2,m-1);
		m2= _mpow(m1,n);
		cout << m2.m[0][0] <<" " <<  m2.m[0][1] << " " << m2.m[1][0] <<"  "<< m2.m[1][1]<<endl;
		cout << mn.m[0][0] <<" " << mn.m[0][1] << endl;
	}
	return 0;
}
