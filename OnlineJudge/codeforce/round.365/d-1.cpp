#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn=1e6+10;
int a[maxn],b[maxn];
int n,m,x,y,f[maxn],M[maxn];

struct Node
{
    int x,y,id;
}q[maxn];

int Fi(int x)
{
    int ans =0;
    while(x)
    {
        ans ^=f[x];
        x-=x&-x;
    }   
    return ans;

int add(int k,int x)
{
    while(k<=n)
    {
        f[k]^=x;
        k+=k&-k;
    }
}

int cmp(const Node &a,const Node &b)
{
    return a.y<b.y;
}

int main()
{
    cin >> n;
    a.clear();
    for(int i=1;i<=n;i++)
    {
        cin >> b[i];
        a[i]=a[i-1]^b[i];
    }
    cin >> m;
    for(int i=1;i<=m;i++)
    {
        cin >> q[i].x >> q[i].y;
        q[i].id = i;
    }
    sort(q+1,q+m+1,cmp);
    for(int i=1;i<=m;i++)
    {

    }
    return 0;
}
