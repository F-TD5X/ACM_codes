#include<bits/stdc++.h>
using namespace std;
int num[500000];
int a[500000];
int n,T;
int lowbit(int x)
{
    return x&(-x);
}

int sum(int i)
{
    int sum = 0;
    while(i>0)
    {
        sum += num[i];
        i = i - lowbit(i);
    }
    return sum;
}
void add(int i,int add)
{
    while(i<=n)
    {
        num[i]+=add;
        i=i+lowbit(i);
    }
}
int main()
{
    cin >> T;
    for(int cas =1;cas <= T;cas++)
    {
        scanf("%d",&n);
        memset(num,0,sizeof(num));
        int w;
        for(int i = 1;i<=n;i++)
        {
            scanf("%d",&w);
            add(i,w);
        }
        printf("Case %d:\n",cas);
        char com;
        int x,y;
        while(scanf("%s",&com)!=EOF)
        {
            //cout << com <<endl;
            if(com == 'E') break;
            scanf("%d%d",&x,&y);
            if(com == 'Q')
            {
                printf("%d\n",sum(y)-sum(x-1));
            }
            else if(com == 'A')
            {
                add(x,y);
            }
            else if(com == 'S')
            {
                add(x,-y);
            }
        }
    }
}
