#include<bits/stdc++.h>
using namespace std;
int T,type,n,m,SG[1111];
const double p1=(1+sqrt(5.0))/2.0;
const double p2=p1*p1;
int check(int x)
{
    if(n > m) swap(n,m);
    if(x == 1) return (n&1^1)||(m&1^1);
    else if(x==2) return n!=m;
    else if(x == 3)
    {
        if (n<m) swap(n,m);
		if (n%3==0&&m==n-1) return 1;
		if (n==m&&n%3==1) return 0;
        return 2;
    }
    n--;m--;
    return SG[n]==m?0:1;
}

int main()
{
    //freopen("1003.in","r",stdin);
    //freopen("1003","w",stdout);
    int ans;
    for(int i =1;;i++)
    {
        n=i*p1;
        m=i*p2;
        if(m > 1000)break;
        SG[n]=m;
    }
    cin >>T;
    while(T--)
    {
        cin >> type>>n>>m;
        ans = check(type);
        if(ans == 1)cout <<"B"<<endl;
        else if(ans == 0)cout <<"G"<<endl;
        else cout <<"D"<<endl;
    }
}
