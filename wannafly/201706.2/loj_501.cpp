/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a[1111];
bool flag=0;
int t;

void Work(ll n,int nw=0)
{
	if(n==1){
		cout<<t<<endl;
		for(int i = 1; i <= t; i++) 
			cout<<a[i]<<" ";
		flag=1;
		exit(0);
	}
	int tmp=t;
	for(ll i=3,s=2;i<=1e18;i=i*2+1,s++){
		if(n%i==0){
			for(int j=1;j<=s;j++)
				a[++t]=nw;
			Work(n/i,!nw);
			t=tmp;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("loj_501.in","r",stdin);
    //freopen("loj_501.out","w",stdout);
#endif
	cin >> n;
	a[1]=1;a[2]=2;
	int tmp=2;
	t=2;
	while(n%2==0)
		a[++t]=++tmp,n/=2;
	Work(n,0);
	if(flag==0)
		cout <<"qnq"<<endl;
	return 0;
}
