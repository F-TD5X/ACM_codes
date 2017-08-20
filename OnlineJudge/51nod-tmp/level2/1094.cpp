#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn=1e4+10;
int arr[maxn],pre[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1094.in","r",stdin);
    //freopen("1094.out","w",stdout);
#endif
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++)
        cin >> arr[i];
    pre[0]=0;
    for(int i=1;i<n;i++)
        pre[i]=arr[i]+pre[i-1];
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(pre[j]-pre[i]==k)
            {
                cout << i+1 <<" " << j << endl;
                return 0;
            }
    puts("No Solution");
    return 0;
}
