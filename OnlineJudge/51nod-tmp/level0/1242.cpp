
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define mod 1000000009

using namespace std;

long long int n;

struct node 
{
    long long int c[2][2];
} t;

node mult(node a,node b) 
{
    node cc;
    for(int i=0; i<2; i++) 
        for(int j=0; j<2; j++) 
        {
            cc.c[i][j] = 0;
            for(int k=0; k<2; k++)
                cc.c[i][j] += (a.c[i][k]*b.c[k][j])%mod;
            cc.c[i][j] = cc.c[i][j]%mod;
        }
    return cc;
}

node expo(long long int nn) 
{
    node pt = t;
    if(nn<0)
        return pt;
    while(nn) 
    {
        if(nn&1) 
        {
            pt = mult(pt,t);
            nn--;
        }
        t = mult(t,t);
        nn = nn>>1;
    }
    return pt;
}

int main() 
{
    while(scanf("%lld",&n)!=EOF) 
    {
        t.c[0][0] = 1;
        t.c[0][1] = 1;
        t.c[1][0] = 1;
        t.c[1][1] = 0;
        node tt = expo(n-2);
        printf("%lld\n",tt.c[0][0]);
    }
    return 0;
}
