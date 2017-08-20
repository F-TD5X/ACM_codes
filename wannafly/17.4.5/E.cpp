#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
struct Point
{
	int x,y;
};
const double eps=1e-8;
double p,q,R;
double dis(Point a,Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double time_three1(Point a,Point b,Point m)
{
	Point l=a,r=b;
	Point mid,mm;
	double a1,a2;
	for(int i=0;i<200;i++){	
		mid.x=(l.x+r.x)/2.0;
		mid.y=(l.y+r.y)/2.0;
		mm.x=(l.x+mid.x)/2.0;
		mm.y=(l.y+mid.y)/2.0;
		a1=dis(mid,a)/p+dis(mid,m)/R;
		a2=dis(mm,a)/p+dis(mm,m)/R;
		if(a1<a2)
			l=mm;
		else
			r=mid;
	}	
	return a1;
}

double time_three2(Point a,Point b,Point c,Point d)
{
	Point l=c,r=d,m,mm;
	double a1,a2;
	for(int i=0;i<200;i++){
		m.x=(l.x+r.x)/2.0;
		m.y=(l.y+r.y)/2.0;
		mm.x=(l.x+m.x)/2.0;
		mm.y=(l.y+m.y)/2.0;
		a1=dis(m,d)/q+time_three1(a,b,m);
		a2=dis(mm,d)/q+time_three1(a,b,mm);
		if(a1 < a2)
			l=mm;
		else
			r=m;
	}
	return a1;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("E.in","r",stdin);
    //freopen("E.out","w",stdout);
#endif
	cin >>T;
	Point a,b,c,d;
	while(T--){
		cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
		cin >> p >> q >> R;
		printf("%.2f\n",time_three2(a,b,c,d));
	}

	return 0;
}
