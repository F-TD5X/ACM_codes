#include<bits/stdc++.h>
using namespace std;
char s[10000];
long long sum;
int main()
{
    while(scanf("%s",s)!= EOF && s[0] != '0')
    {
        sum = 0;
        for(int i=0;i<strlen(s);i++)
            sum += s[i] - '0';
        while(sum >9)
            sum %=9;
        if(sum == 0)
            sum = 9;
        printf("%lld\n",sum);
    }
}
