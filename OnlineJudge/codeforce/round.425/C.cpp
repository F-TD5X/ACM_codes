#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+100;
double eps=1e-7;

int n,s;
struct Node
{
	int x,v,t;
	Node(){}
	Node(int x,int v,int t):x(x),v(v),t(t){}
	bool operator < (const Node &t) const{
		return x < t.x;
	}
}l[maxn];


double check(double mid){
	double lt=0,rt=0;
	double tt1=0,tt2=0;
	for(int i=0;i<n;i++){
		if(l[i].t==2){
			double t1= (l[i].x-mid)/(s-l[i].v);
			double t2= (1e6-l[i].x+l[i].v*t1)/(l[i].v+s);
			tt1=max(tt1,t1+t2);
		}
		else if(l[i].t==1)
			tt2=max(tt2,(double)l[i].x/l[i].v);
	}	
	for(int i=n-1;i>=0;i--){
		if(l[i].t==1){
			double t1=(mid-l[i].x)/(s-l[i].v);
			double t2=(l[i].x-t1*l[i].v)/(s+l[i].v);
			tt2=max(tt2,t1+t2);
		}
		else
			tt1=max(tt1,(1e6-l[i].x)/l[i].v);
	}
	return min(tt1,tt2);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C.in","r",stdin);
    //freopen("C.out","w",stdout);
#endif
	cin>>n>>s;
	int ma=0,mi=0x3f3f3f3f;
	for(int i=0;i<n;i++){
		cin >> l[i].x >> l[i].v>>l[i].t;
		ma=max(ma,l[i].x);
		mi=min(mi,l[i].x);
	}
	sort(l,l+n);
	double l=mi,r=ma;
	double lt=check(mi),rt=check(ma);
	while(r-l>eps){
		double mid1=(l+r)/2;
		double mid2=(mid1+r)/2;
		double t1,t2;
		t1=check(mid1);
		t2=check(mid2);
		if(t2 < t1)
			r=mid2;
		else
			l=mid1;
		cout <<mid1 <<" " << mid2 <<" " <<  t1 << " " << t2 << endl;
		cout << r-l <<" " << eps << endl;
	}
	cout <<fixed << setprecision(8)<< check(l)<< endl;


	return 0;
}
