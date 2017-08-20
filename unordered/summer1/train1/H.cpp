#include<iostream>
using namespace std;
const int maxn = 2e5+7;
int a[maxn],f[maxn], table[maxn];
int fi(int x)
{
    if(f[x] == x)
        return x;
    return f[x] = fi(f[x]);
}
int uni(int x,int y)
{
    int u = fi(x);
    int v = fi(y);
    if(u != v)
    {
        f[v] = u;
        return 1;
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
        f[i] = i; 
    }
    int ans = 0;
    int pre = -1;
    //建立并查集，处理成环的情况
    for(int i = 1;i<=n;i++)
    {
        if(!uni(a[i],i) && a[i]!=i)
        {
            ans++;
            table[i] = 1;
            if(pre != -1){
                uni(i,pre);
            }
            pre = i;
        }
    } 
    //处理<x,x> 关系
    for(int i = 1;i<=n;i++)
    {
        if(i == f[i])
        {
            ans++;
            table[i] = 1;
            if(pre != -1)
            {
                uni(i,pre);
            }
            pre = i;
        }
    }
    cout << ans-1 << " " <<endl;
    for(int i = 1;i<=n;i++)
    {
        if(table[i])
            cout <<f[i] << " ";
        else
            cout << a[i]<<" ";
    }
    cout << endl;
    return 0;
}
