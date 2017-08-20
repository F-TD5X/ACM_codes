/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isr(int t)
{
	return (t%4==0 && t%100!=0)||(t%400==0);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1005.in","r",stdin);
    //freopen("1005.out","w",stdout);
#endif
	int T;
	scanf("%d",&T);
	while(T--){
		int y,m,d,sum=0;
		scanf("%d-%d-%d",&y,&m,&d);
		if(isr(y) && m==2 && d==29){
			y+=4,sum+=5;
			while(sum%7!=0){
				sum+=5;
				y+=4;
			}
		}
		else
		while(sum<7){
			if(m<3)
				if(isr(y))
					sum+=2;
				else
					sum+=1;
			else
				if(isr(y+1))
					sum+=2;
				else
					sum+=1;
			y++;
		}
		cout << y<<endl;
	}
	return 0;
}
