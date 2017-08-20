#include<bits/stdc++.h>
using namespace std;
int n;
struct poi
{
    int x,y;
    poi() {}
    poi(int x,int y):x(x),y(y) {}
} p[2][100001],pp[100001];
int max_x,min_x;
double ans;
int main()
{
    int x,y;
    while(cin >> n)
    {
        max_x =0,min_x = 0;
        int k = 0,j = 0;
        ans = 0;
        for(int i = 0; i<n; i++)
        {
            cin >> x>>y;
            pp[i].x = x;
            pp[i].y = y;
            max_x = max(max_x,x);
            min_x = min(min_x,x);
        }
        for(int i =0; i<n; i++)
        {
            if(pp[i].x <= (min_x +max_x)/2)
            {
                p[0][k].x=pp[i].x;
                p[0][k++].y=pp[i].y;
            }
            else
            {
                p[1][j].x = pp[i].x;
                p[1][j++].y = pp[i].y;
            }
        }
        for(int i =0; i<k; i++)
        {
            for(int q = 0; q < j; q++)
            {
                x = abs(p[0][i].x)+abs(p[1][q].x);
                y = abs(p[0][i].y)+abs(p[1][q].y);
                ans = max(ans,sqrt(x*x+y*y));
            }
        }
        cout <<fixed<<setprecision(6)<< ans<<endl;
    }
}
