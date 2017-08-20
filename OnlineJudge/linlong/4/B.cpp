#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 310
#define inf 1000000000 
#define _clr(x) memset(x,-1,sizeof(int)*MAXN)
const int maxn=310;
int n,m;
int ma[maxn][maxn],ma2[maxn][maxn];
int KM(int m,int n,int mat[][MAXN],int *match1,int *match2)
{
        int s[MAXN],t[MAXN],l1[MAXN],l2[MAXN];
    int p,q,i,j,k,ret=0;
    for(i=0;i<m;i++)
    {
        l1[i]=-inf;
        for(j=0;j<n;j++)
            l1[i]=mat[i][j]>l1[i]?mat[i][j]:l1[i];
        if(l1[i]==-inf)  return -1;
    } 
    for(i=0;i<n;i++)
        l2[i]=0;
    _clr(match1);
    _clr(match2);
    for(i=0;i<m;i++)
    {
        _clr(t);
        p=0;q=0;
        for(s[0]=i;p<=q&&match1[i]<0;p++)
        {
            for(k=s[p],j=0;j<n&&match1[i]<0;j++)
            {
                if(l1[k]+l2[j]==mat[k][j]&&t[j]<0)
                {
                    s[++q]=match2[j];
                    t[j]=k;
                    if(s[q]<0)
                    {
                        for(p=j;p>=0;j=p)
                        {
                            match2[j]=k=t[j];
                            p=match1[k];
                            match1[k]=j;
                        }    
                    }    
                }    
            }    
        } 
        if(match1[i]<0)
        {
            i--;
            p=inf;
            for(k=0;k<=q;k++)
            {
                for(j=0;j<n;j++)
                {
                    if(t[j]<0&&l1[s[k]]+l2[j]-mat[s[k]][j]<p)
                       p=l1[s[k]]+l2[j]-mat[s[k]][j];
                }    
            }  
            for(j=0;j<n;j++)
               l2[j]+=t[j]<0?0:p;
            for(k=0;k<=q;k++)
               l1[s[k]]-=p;  
        }       
    } 
    for(i=0;i<m;i++)
        ret+=mat[i][match1[i]];
    return ret;      
}
int m1[maxn],m2[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
#endif
	int T;
	while(T--)
	{
		cin >> n >>m;
		memset(ma,-1,sizeof(ma));
		memset(ma2,-1,sizeof(ma2));
		for(int i=0;i<n+m;i++)
		{
			for(int j=0;j<m+n;j++)
			{
				cin >> ma[i][j];
				if(j>=n)
					ma2[i][j-n]=ma[i][j];
			}
		}
		ll ans=KM(n,m,ma2,m1,m2);
		cout <<ans <<endl;
	}
	return 0;
}



手动公布一下，随即将序号 162    120   85  151   100  106   43   22   28   249   81  156  250   231  209

