#include<bits/stdc++.h>
using namespace std;
int T,sum,n,x,y;
int num[50010];
int en;
char type[10];
struct NODE
{
    int left,right;
    int data;
}node[500000];

void updateT(int ri)
{
    int a = node[ri<<1].data;
    int b = node[(ri<<1)+1].data;
    node[ri].data = a+b;
}

void buildTree(int i,int l,int r)
{
    node[i].left = l;
    node[i].right = r;
    node[i].data = 0;
    if(l == r)
    {
        node[i].data = num[l];
        return ;
    }
    buildTree(i<<1,l,(r+l)>>1);
    buildTree((i<<1)+1,((r+l)>>1)+1,r);
    updateT(i);
}


void insert(int ri,int a,int b)
{
    NODE &t = node[ri];
    if(t.left == a && t.right == a)
    {
        t.data += b;
        return;
    }
    int mid = (t.left + t.right)>>1;
    if(a <= mid)
    {
        insert(ri<<1,a,b);
    }
    else
    {
        insert((ri<<1)+1,a,b);
    }
    updateT(ri);
}

void fi(int ri,int l,int r)
{
    NODE &t = node[ri];
    if(t.left == l && t.right == r)
    {
        sum += t.data;
        return;
    }
    int mid = (t.left + t.right)>>1;
    if(r <= mid)
    {
        fi(ri<<1,l,r);
    }
    else if(l > mid)
    {
        fi((ri<<1)+1,l,r);
    }
    else
    {
        fi(ri<<1,l,mid);
        fi((ri<<1)+1,mid+1,r);
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    en =  0;
    scanf("%d",&T);
    for(int ca = 1;ca <=T;ca++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&num[i]);
        buildTree(1,1,n);
        char str[10];
        int x,y;
        printf("Case %d:\n",ca);
        while(scanf("%s",str)&&str[0]!='E')
        {
            scanf("%d%d",&x,&y);
            if(str[0] == 'Q')
            {
                 sum = 0;
                 fi(1,x,y);
                 printf("%d\n",sum);
             }
             else if(str[0] == 'A')insert(1,x,y);
             else if(str[0] == 'S')insert(1,x,-y);
        }
    }

}


