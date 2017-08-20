#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,m,len,a[100005],b[100005],c[100005];

int find(int l,int r,int x)
{
    if(l==r) return l;
    int mid=(l+r)/2;
    if(c[mid]<=x) 
		return find(mid+1,r,x);
    else 
		return find(l,mid,x);
}

int main()
{
#ifndef ONLINE_JUDGE
	//freopen("F-1.in,"r",stdin");
	//freopen("F-1.out,"w",stdout");
#endif

	cin >> T;
    while(T--)
    {
		cin >> n;
		memset(c,0,sizeof(c));
        for (int i=1;i<=n;i++)
        {
            cin >> a[i];
            b[i]=a[i];
        }
        len=0;
        for(int i=1;i<=n;i++)
        {
           	int j;
            if(a[i]>=c[len]) 
			{
				len++;
				j=len;
			}
            else 
				j=find(1,len,a[i]);
            c[j]=a[i];
        }
        if (len==n-1||len==n)
        {
            puts("YES");
            continue;
        }
        for (int i=1,j=n;i<=n;i++,j--)
        {
			a[i]=b[j];c[i]=0;
        }   
        len=0;
        for(int i=1;i<=n;i++)
        {
            int j;
            if(a[i]>=c[len]) 
			{
				len++;
				j=len;
			}       
			else 
				j=find(1,len,a[i]);
            c[j]=a[i];
        }
        if(len==n-1||len==n)
        {
            puts("YES");
            continue;
        }
        puts("NO");
    }
}
