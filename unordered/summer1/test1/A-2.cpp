#include<bits/stdc++.h>
using namespace std;

int n;
const int maxn = 166;
char str[maxn];
char tar[maxn];
char word[maxn];

int sscan_line(char *s,char *&s0)
{
    if(!*s0) return 0;
    int i = 0, j = 0;
    while(s0[i] == ' ') i++;
    for(j = 0;s0[i] && s0[i] != ' '; i++){
        s[j++] = s0[i];
    }
    s[j] = '\0'; s0+=i;
    return j;
}

int main()
{
    //freopen("B.in","r",stdin);
    while(~scanf("%d",&n)&&n){
        set<string> ig;
        while(n--){
            scanf("%s",str);
            ig.insert(str);
        }
        scanf("\n");
        while(gets(str) && strcmp(str,"LAST CASE") != 0){
            //stringstream sin.(str)
            char *p = str;
            int tlen = sscan_line(tar,p);
            int dp[maxn]={} ; dp[0] = 1;
            for(int i = 0; tar[i]; i++){
                tar[i] += 'a'-'A';
            }
            while(sscan_line(word,p)){
                if(ig.count(word) != 0) continue;
                int ndp[maxn]={};
                for(int i = 0; word[i]; i++)
                    for(int j = tlen-1; ~j; j--)
                        if(word[i] == tar[j])
                            ndp[j+1] += dp[j]+ndp[j];
                copy(ndp,ndp+maxn,dp);
            }
            for(int i = 0; i < tlen; i++){
                tar[i] -= 'a'-'A';
            }
            int ans = dp[tlen];
            if(ans) printf("%s can be formed in %d ways\n",tar,ans);
            else printf("%s is not a valid abbreviation\n",tar);
        }
    }
    return 0;
}
