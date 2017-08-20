<<<<<<< HEAD
<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int n;
struct {double first,second;} pi[11111];
double ans;
double Z=0;
const double eps=1e-4;

double check(double m)
{
	double R=0;
	for(int i=0;i<n;i++)
       if(R*(m-pi[i].second)<m*pi[i].first)
		   R=m*pi[i].first/(m-pi[i].second);  
	return R;
}

void solve()
{
	double l=Z,r=1<<30;
	double mid,m1,m2,r1,r2;
	while(r-l>eps){
		mid=(r-l)/3;
		m1=l+mid;
		m2=l+2*mid;
		r1=check(m1);
		r2=check(m2);
		if(r1*r1*m1>r2*r2*m2)
			l=m1;
		else
			r=m2;
	}
	printf("%.3f %.3f\n",l,check(l));
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	scanf("%d",&T);
	double t;
	while(T--){
		scanf("%d",&n);
		Z=0;
		for(int i=0;i<n;i++){
			scanf("%lf%lf%lf",&pi[i].first,&t,&pi[i].second);
			Z=max(Z,pi[i].second);
			pi[i].first=sqrt(pi[i].first*pi[i].first+t*t);
		}
		solve();
	}

	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int n;
struct {double first,second;} pi[11111];
double ans;
double Z=0;
const double eps=1e-4;

double check(double m)
{
	double R=0;
	for(int i=0;i<n;i++)
       if(R*(m-pi[i].second)<m*pi[i].first)
		   R=m*pi[i].first/(m-pi[i].second);  
	return R;
}

void solve()
{
	double l=Z,r=1<<30;
	double mid,m1,m2,r1,r2;
	while(r-l>eps){
		mid=(r-l)/3;
		m1=l+mid;
		m2=l+2*mid;
		r1=check(m1);
		r2=check(m2);
		if(r1*r1*m1>r2*r2*m2)
			l=m1;
		else
			r=m2;
	}
	printf("%.3f %.3f\n",l,check(l));
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	scanf("%d",&T);
	double t;
	while(T--){
		scanf("%d",&n);
		Z=0;
		for(int i=0;i<n;i++){
			scanf("%lf%lf%lf",&pi[i].first,&t,&pi[i].second);
			Z=max(Z,pi[i].second);
			pi[i].first=sqrt(pi[i].first*pi[i].first+t*t);
		}
		solve();
	}

	return 0;
}
>>>>>>> e30efc2bee7b85c64b5cc40b21a84d4cb2f8cc56
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int n;
struct {double first,second;} pi[11111];
double ans;
double Z=0;
const double eps=1e-4;

double check(double m)
{
	double R=0;
	for(int i=0;i<n;i++)
       if(R*(m-pi[i].second)<m*pi[i].first)
		   R=m*pi[i].first/(m-pi[i].second);  
	return R;
}

void solve()
{
	double l=Z,r=1<<30;
	double mid,m1,m2,r1,r2;
	while(r-l>eps){
		mid=(r-l)/3;
		m1=l+mid;
		m2=l+2*mid;
		r1=check(m1);
		r2=check(m2);
		if(r1*r1*m1>r2*r2*m2)
			l=m1;
		else
			r=m2;
	}
	printf("%.3f %.3f\n",l,check(l));
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
#endif
	scanf("%d",&T);
	double t;
	while(T--){
		scanf("%d",&n);
		Z=0;
		for(int i=0;i<n;i++){
			scanf("%lf%lf%lf",&pi[i].first,&t,&pi[i].second);
			Z=max(Z,pi[i].second);
			pi[i].first=sqrt(pi[i].first*pi[i].first+t*t);
		}
		solve();
	}

	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
