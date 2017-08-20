#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <list>
using namespace std;

typedef pair<int,int> pii;
priority_queue<pii> com;
priority_queue<pii> a;
priority_queue<pii> b;

int main(int argc, char const *argv[])
{
    //IN;

    int n; int ca = 1;
    while(scanf("%d", &n) != EOF && n)
    {
        printf("Case #%d:\n", ca++);
        while(!a.empty()) a.pop();
        while(!b.empty()) b.pop();
        while(!com.empty()) com.pop();

        int time_cnt = 0;

        while(n--) {
            char op[10]; char aim;
            scanf("%s %c", op,&aim);
            if(op[1] == 'u') {
                int x; scanf("%d", &x);
                if(aim == 'A') {
                    a.push(make_pair(time_cnt++, x));
                } else {
                    b.push(make_pair(time_cnt++, x));
                }
            }
            else if(op[1] == 'o') {
                if(aim == 'A') {
                    if(!a.empty()) {
                        pii x = a.top(); a.pop();
                        printf("%d\n", x.second);
                    } else {
                        pii x = com.top(); com.pop();
                        printf("%d\n", x.second);
                    }
                } else {
                    if(!b.empty()) {
                        pii x = b.top(); b.pop();
                        printf("%d\n", x.second);
                    } else {
                        pii x = com.top(); com.pop();
                        printf("%d\n", x.second);
                    }
                }
            }
            else {
                char tmp[10]; gets(tmp);
                while(!a.empty()) {
                    pii x = a.top();
                    a.pop();
                    com.push(x);
                }
                while(!b.empty()) {
                    pii x = b.top();
                    b.pop();
                    com.push(x);
                }
            }
        }
    }

    return 0;
}
