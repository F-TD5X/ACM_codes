#include<bits/stdc++.h>
using namespace std;
stack<long long> a,b;
long long n;
char s[10000];
long long t;
long long ans;
#define E
int main()
{
#ifdef E
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    cin >> n; 
        for(int i=0;i<n;i++)
        {
            scanf("%d%s",&t,s);
            if(strcmp(s,"WITHOUT") == 0)
              b.push(-1);
            else
              b.push(1);
            a.push(t);
        }
        cin >>ans;
        while(!b.empty())
        {
            if(b.top() == 1)
            {
                ans += a.top();
                a.pop();
                b.pop();
            }
            else
            {
                ans = a.top() - ans;
                a.pop();
                b.pop();
            }
        }
        cout << ans;
    
    return 0;
}
