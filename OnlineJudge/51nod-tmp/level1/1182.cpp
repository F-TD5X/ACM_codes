#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int num[28];
char s[111111];
ll ans;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1182.in","r",stdin);
    //freopen("1182.out","w",stdout);
#endif
    cin >> s;
    for(int i=0;i<strlen(s);i++)
    {
        num[tolower(s[i])-'a']++;
    }
    sort(num,num+28);
    int mul=26;
    for(int i=27;i>=0;i--)
    {
        ans+=num[i]*mul--;
        if(num[i]==0)
            break;
    }
    cout <<ans<<endl;
    return 0;
}
