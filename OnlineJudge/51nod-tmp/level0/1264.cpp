#include <algorithm>  
#include <iostream>  
#include <cstring>  
#include <climits>  
#include <cstdio>  
#include <string>  
#include <cmath>  
#include <set>  
#include <queue>  
#include <map>  
#include <vector>  
#include <cstdlib>  
#include <stack>  
#include <time.h>  
using namespace std;  
typedef long long LL;  
const int MOD = int(1e9)+7;  
const int INF = 0x3f3f3f3f;  
const double EPS = 1e-9;  
const double PI = acos(-1.0); //M_PI;  
const int maxn = 100001;  
  
struct point  
{  
        double x , y;  
        point(double a , double b) : x(a) , y(b) {};  
        point() {};  
        void input()  
        {  
                scanf("%lf%lf",&x,&y);  
        }  
};  
  
bool line_make_point(point a , point b , point c , point d)  
{  
        double C = (c.y - a.y) * (a.x - b.x) - (a.y - b.y) * (c.x - a.x);  
        double D = (d.y - a.y) * (a.x - b.x) - (a.y - b.y) * (d.x - a.x);  
        if(C * D > 0)   return false;  
        return true;  
}  
  
bool check(point a , point b , point c , point d)  
{  
        if(!line_make_point(a , b , c , d))     return false;  
        if(!line_make_point(c , d , a , b))     return false;  
        return true;  
}  
  
int main()  
{  
    int T;  
    scanf("%d",&T);  
    while(T--)  
    {  
            struct point a , b , c , d;  
            a.input();  
            b.input();  
            c.input();  
            d.input();  
            if(check(a , b , c , d))  
                printf("Yes\n");  
            else  
                printf("No\n");  
    }  
    return 0;  
}  
