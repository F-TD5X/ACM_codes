#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include<string>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
char s[111];
int cnt[28];
int ans ;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("e.in","r",stdin);
    //freopen("e.out","w",stdout);
#endif
    while(cin >> s)
    {
        ans=0;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<strlen(s);i++)
        {
            cnt[s[i]-'a']++;
        }
        sort(cnt,cnt+28);
        for(int i =0;i<26;i++)
        {
            ans += cnt[i];
        }
        cout << ans << endl;
    }
    return 0;
}
