#include<bits/stdc++.h>
using namespace std;
struct poi
{
    int x,y;
   int  operator<(poi &t)
    {
        if(x <= t.x&& y <=t.y)
          return 1;
        else 
          return 0;
    }
    int operator>(poi &t)
    {
        if(x >=t.x && y>=t.y)
          return 1;
        else 
          return 0;
    }
    int operator>=(poi &t)
    {
        if(x >= t.x || y >= t.y)
          return 1;
        else 
          return 0;
    }
    int operator<=(poi &t)
    {
        if(x<=t.x || y<=t.y)
          return 1;
        else
          return 0;
    }
    int operator==(poi &t)
    {
        if(x == t.x && y == t.y)
          return 1;
        else 
          return 0;
    }

}p1,p2,p3,p4;


int main()
{
    cin >> p1.x >> p1.y >> p2.x>>p2.y>>p3.x>>p3.y>>p4.x>>p4.y;
    if(p4 <= p1 || p2 <=p3)
    {
        cout << 1<<endl;
        cout << p1.x << " " << p1.y << " " <<p2.x <<" " <<p2.y<<endl;
    }
    else if(p3 > p1 && p2 < p4)
    {
        cout << 2<<endl;
        cout << p1.x << " " << p1.y << " " << p3.x << " " << p2.y << endl;
        cout << p3.x << " " << p1.y << " " << p2.x << " " << p3.y <<endl; 
    }
    else if(p3 < p1 &&p4 < p2 )
    {
        cout << 2<<endl;
        cout << p1.x << " " << p4.y << " " << p2.x << " " << p4.y <<endl;
        cout << p4.x << " " << p1.y << " " << p2.x << " " << p4.y <<endl;
    }
    else if()
    return 0;
}
