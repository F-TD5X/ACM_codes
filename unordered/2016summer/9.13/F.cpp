#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int ar[10];
int T;
char s[10];

bool dfs(int now,int st)
{
    if(now==0)
        return 1;
    for(int s=1;s<(1<<7);s++)
    {
        if(s&st)
            continue;
        int al=0;
        for(int i=0;i<7;i++)
            if((1<<i)&s)
                al+=ar[i];
        if(al==now &&dfs(now-1,st|s))
            return 1;
    }
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("F.in","r",stdin);
    //freopen("F.out","w",stdout);
#endif
    cin >> T;
    while(T--)
    {
        memset(ar,0,sizeof(ar));
        cin >> s;
        for(int i=0;i<strlen(s);i++)
            ar[i]=s[i]-'A'+1;
        cout <<( dfs(5,0)?"YES":"NO" )<< endl;
    }
    return 0;
}
