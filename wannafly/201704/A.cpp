<<<<<<< HEAD
<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
double x,y,v;
double ans;
const double PI=acos(-1);
const double eps=1e-10;
double C1(double mid)
{
	double vx=v*cos(mid),vy=v*sin(mid);
	return vy*x/vx - 9.8*x/vx*x/vx/2;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%lf%lf%lf",&x,&y,&v);
		double lb=0,rb=PI/2;
		while(rb-lb>eps){
			double m=(lb+rb)/2,m2=(rb+m)/2;
			if(C1(m)>C1(m2))
				rb=m2;
			else
				lb=m;
		}
		if(C1(rb)<y){
			puts("-1");
			continue;
		}
		lb=0;
		while(rb-lb>eps){
			double m=(lb+rb)/2;
			if(C1(m)>=y)
				rb=m;
			else
				lb=m;
		}
		printf("%.6f\n",rb);
	}

	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
double x,y,v;
double ans;
const double PI=acos(-1);
const double eps=1e-10;
double C1(double mid)
{
	double vx=v*cos(mid),vy=v*sin(mid);
	return vy*x/vx - 9.8*x/vx*x/vx/2;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%lf%lf%lf",&x,&y,&v);
		double lb=0,rb=PI/2;
		while(rb-lb>eps){
			double m=(lb+rb)/2,m2=(rb+m)/2;
			if(C1(m)>C1(m2))
				rb=m2;
			else
				lb=m;
		}
		if(C1(rb)<y){
			puts("-1");
			continue;
		}
		lb=0;
		while(rb-lb>eps){
			double m=(lb+rb)/2;
			if(C1(m)>=y)
				rb=m;
			else
				lb=m;
		}
		printf("%.6f\n",rb);
	}

	return 0;
}
>>>>>>> e30efc2bee7b85c64b5cc40b21a84d4cb2f8cc56
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
double x,y,v;
double ans;
const double PI=acos(-1);
const double eps=1e-10;
double C1(double mid)
{
	double vx=v*cos(mid),vy=v*sin(mid);
	return vy*x/vx - 9.8*x/vx*x/vx/2;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%lf%lf%lf",&x,&y,&v);
		double lb=0,rb=PI/2;
		while(rb-lb>eps){
			double m=(lb+rb)/2,m2=(rb+m)/2;
			if(C1(m)>C1(m2))
				rb=m2;
			else
				lb=m;
		}
		if(C1(rb)<y){
			puts("-1");
			continue;
		}
		lb=0;
		while(rb-lb>eps){
			double m=(lb+rb)/2;
			if(C1(m)>=y)
				rb=m;
			else
				lb=m;
		}
		printf("%.6f\n",rb);
	}

	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
