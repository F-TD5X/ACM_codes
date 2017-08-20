#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
#include <string>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn=180;
char t[maxn],w[maxn];
int dp[maxn],dp2[maxn];
char str[maxn];
int n;

int get_word(char *s,char* &s0)
{
    if(!*s0)
        return 0;
    int i=0,j=0;
    while(s0[i]==' ')
        i++;
    for(j=0;s0[i]&&s0[i]!=' ';i++)
        s[j++]=s0[i];
    s[j]='\0';
    s0+=i;
    return j;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
    while(~scanf("%d",&n) && n)
    {
        memset(dp,0,sizeof(dp));
        set<string>s;
        while(n--)
        {
            cin >>str;
            s.insert(str);
        }
        scanf("\n");
        while(gets(str) && strcmp(str,"LAST CASE")!=0)
        {
            memset(dp,0,sizeof(dp));
            dp[0]=1;
            char *p=str;
            int tlen=get_word(t,p);
            for(int i=0;t[i];i++)
                t[i]+='a'-'A';
            while(get_word(w,p))
            {
                if(s.count(w)!=0)
                    continue;
                memset(dp2,0,sizeof(dp2));
                for(int i=0;w[i];i++)
                    for(int j=tlen-1;j>=0;j--)
                        if(w[i]==t[j])
                            dp2[j+1]+=dp[j]+dp2[j];
                copy(dp2,dp2+maxn,dp);
            }
            for(int i=0;i<tlen;i++)
                t[i]-='a'-'A';
            int ans=dp[tlen];
            if(ans)
                printf("%s can be formed in %d ways\n",t,ans);
            else 
                printf("%s is not a valid abbreviation\n",t);
            memset(str,0,sizeof(str));
        }
    }
    return 0;
}
