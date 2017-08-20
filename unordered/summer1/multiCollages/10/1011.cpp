#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int T;
int n;
char s[10];
int len[100];
int l2[10];
char buf[2];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1011.in","r",stdin);
    //freopen("1011.out","w",stdout);
#endif
    cin >> T;
    len[6]=len[1]=len[2]=3;
    len[8]=len[7]=len[3]=5;
    len[9]=len[4]=len[5]=4;
    len[10]=3;
    len[16]=len[15]=7;
    len[17]=9;
    len[11]=len[12]=6;
    len[13]=len[14]=len[18]=len[19]=8;
    l2[2]=l2[8]=l2[4]=l2[3]=6;
    l2[5]=l2[6]=l2[9]=5;
    l2[7]=7;
    int ans=0;
    while(T--)
    {
        ans=0;
        cin >> n;
        for(int i=1;i<=n;i++)
        {
            itoa(i,s,10);
            reverse(s,s+strlen(s));
            for(int i=strlen(s)-1;i>=0;i--)
            {
                //cout << s[i] << " " << i <<" "<<ans << endl;
                if(i==3)
                    ans+=len[s[i]-'0']+8;
                if(i==2 && s[1] == s[0] && s[0] =='0')
                    ans+=len[s[i]-'0']+7;
                else if(i==2)
                    ans += len[s[i]-'0']+7+3;
                if(i == 1)
                {
                    if(s[1]=='1')
                    {
                        buf[1]=s[0];
                        buf[0]=s[1];
                        int t=atoi(buf);
                        ans+=len[t];
                        break;
                    }
                    else if(s[0]!='0' && s[1]!='1')
                        ans+=l2[s[i]-'0']+1;
                    else if(s[1]!='1' && s[0]=='0')
                    {
                        ans+=l2[s[i]-'0'];
                        break;
                    }
                }
                if(i==0)
                {
                    ans+=len[s[i]-'0'];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
