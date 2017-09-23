/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const double PI=acos(-1);
struct Point{
	int x,y;
	double rad,dis;
	double t;
}p[maxn];
bool cmp1(Point a,Point b){
	return a.t>b.t;
}

bool cmp2(Point a,Point b){
	
}

int n,xx,yy,xx1,yy1;

bool solve(double m){
	double ret=0;
	ret += m*xx*m*xx;
	ret += 1.0*(yy+xx)/m;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			scanf("%d%d",&p[i].x,&p[i].y);
			p[i].rad=atan(1.0*p[i].y/p[i].x);
			p[i].dis=sqrt(p[i].x*p[i].x+p[i].y*p[i].y);
			p[i].t=p[i].dis*sin(fabs(p[i].rad-PI/4));
		}
		sort(p+1,p+n+1,cmp1);
		xx=p[1].x;yy=p[1].y;
		for(int i=2;i<=n;i++){
			p[i].rad=atan(1.0*(p[i].y-yy)/(p[i].x-xx));
		}
		sort(p+2,p+n+1,cmp2);
		double l=-1e9,r=p[2].rad;
		while(r-l > 1e-5){
			double m1=(l+r)/2;
			double m2=(m1+r)/2;
			if(solve(m1) <= solve(m2)){
				r=m2;
			}else{
				l=m1;
			}
		}
		cout << solve(l) << endl;
	}

	return 0;
}
