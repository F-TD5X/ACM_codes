/*Author: NoZuoNoDieWhyITry*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=10010;

bool vis[MAXN][MAXN];

struct Point {
    int x, y;
    Point() {}
    Point(int _x, int _y) {
        x = _x; y = _y;
    }
	bool operator<(const Point&t)const{
		if(x==t.x)
			return y<t.y;
		return x<=t.x;
	}
}dot[MAXN];

struct Matrix {
    Point up, down;
    Matrix() { }
    Matrix(Point a, Point b) {
        up = a;
        down = b;
    }
}maxrix[MAXN];

int area(Matrix m) {
    return (m.down.x-m.up.x)*(m.up.y-m.down.y);
}
vector<Matrix> vec;

int son_judge(Point t, Matrix m) {
    int x1 = m.up.x;
    int y1 = m.up.y;
    int x2 = m.down.x;
    int y2 = m.down.y;
    if(t.x>=x1 && t.x<=x2 && t.y<=y1 && t.y>=y2) {
        if(t.x>x1 && t.x<x2 && t.y<y1 && t.y>y2)
            return 1;
        return 0;
    }
    return -1;
}

int judge(int i, int j) {
    Point t1 = Point(vec[i].up.x, vec[i].down.y);
    Point t2 = Point(vec[i].down.x, vec[i].up.y);

    int ok1 = son_judge(vec[i].up, vec[j]);
    int ok2 = son_judge(vec[i].down, vec[j]);
    int ok3 = son_judge(t1, vec[j]);
    int ok4 = son_judge(t2, vec[j]);
    if(ok1==1&&ok2==1&&ok3==1&&ok4==1)
        return 1;
    if(ok1==-1&&ok2==-1&&ok3==-1&&ok4==-1)
        return -1;
    return 0;
}

int main() {
    int n;
    while(scanf("%d", &n) && n) {
        if(n < 8) {
            puts("imp");
            continue;
        }
        vec.clear();
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<n; ++i) {
            scanf("%d%d", &dot[i].x, &dot[i].y);
            vis[dot[i].x][dot[i].y] = 1;
        }
        sort(dot, dot+n);
        for(int x1,x2,y1,y2,i=0; i<n; ++i) {
            x1 = dot[i].x;
            y1 = dot[i].y;
            for(int j=i+1; j<n; ++j) {
                x2 = dot[j].x;
                y2 = dot[j].y;
                if(x2<=x1 || y2>=y1) 
					continue;
                if(vis[x2][y1] && vis[x1][y2])
                    vec.push_back(Matrix(dot[i], dot[j]));
            }
        }
        int ans = 0;
        for(int i=0; i<vec.size(); ++i)
            for(int j=i+1; j<vec.size(); ++j) {
                int tmp1 = judge(i, j);
                int tmp2 = judge(j, i);
                if(tmp1 == 1 || tmp2 == 1)
                    ans = max(ans, max(area(vec[i]), area(vec[j])));
                else if(tmp1 == -1 && tmp2 == -1)
                    ans = max(ans, area(vec[i])+area(vec[j]));
            }
        if(ans == 0)
            puts("imp");
        else 
			printf("%d\n", ans);
    }
    return 0;
}
