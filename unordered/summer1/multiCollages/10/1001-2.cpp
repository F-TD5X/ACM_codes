#include <bits/stdc++.h>
using namespace std;

int T;
int n,m;
int a[100005];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        int l1,r1,l2,r2;
        while(m--)
        {
            scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
            if(l1>l2||(l1==l2&&r1>r2))
            {
                swap(l1,l2);
                swap(r1,r2);
            }
            int l,r=0;
            int len=r1+r2-l1-l2+2;
            int mid=len/2;
            if(len%2)
                mid++;
            else
                r=1;
            if(l2<=r1)
            {
                if(r2<r1)
                    swap(r1,r2);
                if(mid<=l2-l1)
                {
                    l=l1+mid-1;
                    r+=l;
                }
                else
                {
                    mid-=l2-l1;
                    if(mid<=(r1-l2+1)*2)
                    {
                        l=l2+mid/2-1+mid%2;
                        if(len%2)
                            r=l;
                        else
                        {
                            if(mid%2)
                                r=l;
                            else
                                r=l+1;
                        }
                    }
                    else
                    {
                        mid-=(r1-l2+1)*2;
                        l=r1+mid;
                        r+=l;
                    }
                }
            }
            else
            {
                if(mid<r1-l1+1)
                {
                    l=l1+mid-1;
                    r+=l;
                }
                else if(mid==r1-l1+1)
                {
                    l=r1;
                    if(r)
                        r=l2;
                    else
                        r=l;
                }
                else
                {
                    mid-=r1-l1+1;
                    l=l2+mid-1;
                    r+=l;
                }
            }
            printf("%.1lf\n",1.0*(1.0*a[l]+1.0*a[r])/2.0);
        }
    }
    return 0;
}

