#include<bits/stdc++.h>
using namespace std;
int N,n[1001];
char col[1001][16];
int main()
{
    while(scanf("%d",&N)!=EOF)
    {
        memset(n,0,sizeof(n));
        if(N)
        {
            scanf("%s",col[0]);
            for(int i =1;i < N;i++)
            {
                scanf("%s",col[i]);
                for(int j = 0;j < i-1;j++)
                {
                    if(strcmp(col[i],col[j])== 0)
                        n[i]++;
                }
            }
            int ma = 0,t = 0;
            for(int i =1;i < N;i++)
            {
                if(ma < n[i])
                {
                    ma = n[i];
                    t = i;
                }
            }
            printf("%s\n",col[t]);

        }
        else
            break;
    }
    return 0;
}
