<<<<<<< HEAD
<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
struct po
{
    double x,y;
}p[10005];
const double eps=1e-9;
double Y;
int n;
double makeR(double h)
{
    double R=0;
    for(int i=0;i<n;i++)
    {
       //R=max(R,h*p[i].x/(h-p[i].y));
       if(R*(h-p[i].y)<h*p[i].x)
       R=h*p[i].x/(h-p[i].y);
    }
    return R;
}
void solve()
{
    double L=Y,R=1<<30,tmp;
    while(R-L>eps)
    {
         tmp=(R-L)/3.0;
        double mid1=L+tmp;
        double mid2=L+2.0*tmp;
        double R1=makeR(mid1);
        double R2=makeR(mid2);
       // cout<<L<<"　"<<R<<endl;
        if(R1*R1*mid1>R2*R2*mid2)
        {
            L=mid1;
        }
        else
        {
            R=mid2;
        }
    }
    printf("%.3f %.3f\n",L+eps,makeR(L)+eps);
}
int main()
{
    int i,j,k;
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        double tx,ty,Left=0;
        Y=0;
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf%lf",&tx,&ty,&p[i].y);
            p[i].x=sqrt(tx*tx+ty*ty);
            Y=max(p[i].y,Y);
        }
        solve();
    }
    return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
struct po
{
    double x,y;
}p[10005];
const double eps=1e-9;
double Y;
int n;
double makeR(double h)
{
    double R=0;
    for(int i=0;i<n;i++)
    {
       //R=max(R,h*p[i].x/(h-p[i].y));
       if(R*(h-p[i].y)<h*p[i].x)
       R=h*p[i].x/(h-p[i].y);
    }
    return R;
}
void solve()
{
    double L=Y,R=1<<30,tmp;
    while(R-L>eps)
    {
         tmp=(R-L)/3.0;
        double mid1=L+tmp;
        double mid2=L+2.0*tmp;
        double R1=makeR(mid1);
        double R2=makeR(mid2);
       // cout<<L<<"　"<<R<<endl;
        if(R1*R1*mid1>R2*R2*mid2)
        {
            L=mid1;
        }
        else
        {
            R=mid2;
        }
    }
    printf("%.3f %.3f\n",L+eps,makeR(L)+eps);
}
int main()
{
    int i,j,k;
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        double tx,ty,Left=0;
        Y=0;
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf%lf",&tx,&ty,&p[i].y);
            p[i].x=sqrt(tx*tx+ty*ty);
            Y=max(p[i].y,Y);
        }
        solve();
    }
    return 0;
}
>>>>>>> e30efc2bee7b85c64b5cc40b21a84d4cb2f8cc56
=======
#include<bits/stdc++.h>
using namespace std;
struct po
{
    double x,y;
}p[10005];
const double eps=1e-9;
double Y;
int n;
double makeR(double h)
{
    double R=0;
    for(int i=0;i<n;i++)
    {
       //R=max(R,h*p[i].x/(h-p[i].y));
       if(R*(h-p[i].y)<h*p[i].x)
       R=h*p[i].x/(h-p[i].y);
    }
    return R;
}
void solve()
{
    double L=Y,R=1<<30,tmp;
    while(R-L>eps)
    {
         tmp=(R-L)/3.0;
        double mid1=L+tmp;
        double mid2=L+2.0*tmp;
        double R1=makeR(mid1);
        double R2=makeR(mid2);
       // cout<<L<<"　"<<R<<endl;
        if(R1*R1*mid1>R2*R2*mid2)
        {
            L=mid1;
        }
        else
        {
            R=mid2;
        }
    }
    printf("%.3f %.3f\n",L+eps,makeR(L)+eps);
}
int main()
{
    int i,j,k;
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        double tx,ty,Left=0;
        Y=0;
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf%lf",&tx,&ty,&p[i].y);
            p[i].x=sqrt(tx*tx+ty*ty);
            Y=max(p[i].y,Y);
        }
        solve();
    }
    return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
