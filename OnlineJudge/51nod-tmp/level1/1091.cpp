#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct node
{
    int x,y;
}p[50001];
int cmp(node a,node b)
{
    if(a.x!=b.x) return a.x<b.x;
    else return a.y<b.y;
}
int main()
{
    int n,i,j,maxn=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d%d",&p[i].x,&p[i].y);
    sort(p,p+n,cmp);
    int m=p[0].y;
    for(i=1;i<n;i++)
    {
        if(p[i].y>=m)  
        {  
            maxn=max(maxn,m-p[i].x);
            m=p[i].y;
        }
        else 
            maxn=max(maxn,p[i].y-p[i].x);
    }
    printf("%d\n",maxn);
    return 0;
}

