#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <set>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn=200;
int dp[maxn],dp2[maxn],cnt,n;
string T,word[maxn];
set<string> s;
char tstr[maxn];

void pre(char *s)
{
    stringstream ss(s);
    ss >> T;
    while(ss >> word[cnt++]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("A.in","r",stdin);
    //freopen("A-o.out","w",stdout);
#endif
    string str;
    while(cin >> n && n)
    {
        cnt=1;
        s.clear();
        while(n--)
        {
            cin >>str;
            s.insert(str);
        }
        scanf("\n");
        while(gets(tstr) && strcmp(tstr,"LAST CASE")!=0)
        {
            memset(dp,0,sizeof(dp));
            cnt=1;
            pre(tstr);
            dp[0]=1;
            for(int i=0;i<T.size();i++)
                T[i]+='a'-'A';
            for(int i=1;i<cnt-1;i++)
            {
                if(s.count(word[i])!=0)
                    continue;
                memset(dp2,0,sizeof(dp2));
                for(int j=0;word[i][j];j++)
                    for(int k=T.size()-1;~k;k--)
                    {
                        if(word[i][j] == T[k])
                            dp2[k+1] += dp[k]+dp2[k];
                    } 
                copy(dp2,dp2+maxn,dp);
            }
            for(int i=0;i<T.size();i++)
                T[i]-='a'-'A';
            if(dp[T.size()])
                printf("%s can be formed in %d ways\n",T.c_str(),dp[T.size()]);
            else
                printf("%s is not a valid abbreviation\n",T.c_str());
        }
    }
    return 0;
}
