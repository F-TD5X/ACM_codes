#include<bits/stdc++.h>
using namespace std;
int c[1111],T,n;
long double ans;
long double p[1111];
long long num[1111][1111];
int table[1111];
long long all;
long double ap;

void sol(int x,int xx,long double pp,int pos)
{
    if(xx >n)
        return;
    for(int i = pos+1;i<n;i++)
    {
        if(!table[i])
        {
            ans += (x-c[i])*(pp/p[i]*(1-p[i]));
            //cout << (x-c[i])*(pp/p[i]*(1-p[i])) << endl;
            //cout  <<i <<" "<<pp <<" " << p[i] << " "<< pp/p[i]  << endl;
            table[i]=1;
            sol(x-c[i],xx+1,pp/p[i]*(1-p[i]),i);
            table[i]=0;
        }
    }
}

int main()
{
    freopen("B.in.txt","r",stdin);
    while(cin >> n)
    {
        ans = 0;
        memset(p,0,sizeof(p));
        memset(table,0,sizeof(table));
        ap = 1;
        all =0;
        for(int i=1;i<=n;i++)
        {
            cin >> c[i];
            all+=c[i];
            if(i != 1 && i!=n)
            {
                for(int j =2;j<n-i;j++)
                {
                    p[i] += (1.0/(n-i-i))*((double)(j-1-i)/(n-1-i))*((double)(j-2-i)*(n-2-i));
                }
                p[i] += (1.0/n);
            }
            else
            {
                for(int j = 2;j<=n-i;j++)
                {
                    p[i] += (1.0/(n-i))*((double)(j-1-i)/(n-1-i));
                }
            }
        }
        for(int i=1;i<n;i++)
        {ap*=p[i];cout <<i<<" " << p[i] << endl;}
        ans = ap*all;
        sol(all,0,ap,1);
        cout << ans << endl;
    }
}
