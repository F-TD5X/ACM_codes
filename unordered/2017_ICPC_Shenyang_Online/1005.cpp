/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//f[2*k+2]-1;
const int SMod= 998244353;

struct Matrix
{
    int m[3][3];
};

Matrix Mul(Matrix a,Matrix b)
{
    Matrix c;
    memset(c.m,0,sizeof(c.m));
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
                c.m[i][j] += ((a.m[i][k]*b.m[k][j])%SMod + SMod)%SMod;
    return c;
}

Matrix fastm(Matrix a,ll n) 
{
    Matrix res;
    memset(res.m,0,sizeof(res.m));
    res.m[0][0] = res.m[1][1] = res.m[2][2] = 1;
    while(n){
        if(n&1)
            res = Mul(res,a);
        n>>=1;
        a = Mul(a,a);
    }
    return res;
}

Matrix MPow(Matrix a,ll n)
{
    if(n == 1)
        return a;
    Matrix res = fastm(a,n/2);
    res = Mul(res,res);
    if(n&1)
        res = Mul(res,a);
    return res;
}

int solve(int n){
	Matrix c,res;
	c.m[0][0]=c.m[0][1]=c.m[1][0]=1;
	c.m[1][1]=0;
	res=fastm(c,n);
	cout << c.m[0][1]<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1005.in","r",stdin);
    //freopen("1005.out","w",stdout);
#endif
	int k;
	while(cin >> k){
		solve(2*k+2);
	}

	return 0;
}
