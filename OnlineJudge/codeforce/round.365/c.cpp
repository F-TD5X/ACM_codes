/*===============================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   文件名称：c.cpp
*   创 建 者：NoZuoNoDieWhyITry
*   创建日期：2016年08月05日
*
================================================================*/
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const double eps=1e-9; 
const int maxn=1e4+50;
int judge(double x)
{
    if(x>eps) return 1;
    else if(x <-eps) return -1;
    else return 0;
}

double u,v,w;
int n;
struct Node
{
    double x,y;
}p[maxn];

bool check1()
{
    for(int i=0;i<n;i++)
        if(judge(u*p[i].x-v*p[i].y)<0)
            return 0;
    return 1;
}

bool check2(double t)
{
    for(int i=0;i<n;i++)
        if(judge(u*p[i].x-v*p[i].y-u*v*t)>0)
            return 0;
    return 1;
}

int main()
{
    cin >> n >>w>>v>>u;
    for(int i=0;i<n;i++)
        cin >> p[i].x >> p[i].y;
    if(check1())
        printf("%.10f\n",1.0*w/u);
    else
    {
        double l=0,r=2e9;
        for(int i=0;i<100;i++)
        {
            double mid = (l+r)/2;
            if(check2(mid))
                r= mid;
            else

                l=mid;
        }
        printf("%.10f\n",1.0*w/u+(l+r)/2);
    }
    return 0;
}
