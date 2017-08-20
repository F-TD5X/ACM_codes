#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <stack>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int n,a[55555];
int s[55555],len=1,t;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("1134.in","r",stdin);
    //freopen("1134.out","w",stdout);
#endif
    scanf("%d",&n);
    scanf("%d",&s[0]);
    for(int i=1;i<n;i++)
    {
        scanf("%d",&t);
        if(t>s[len-1])
            s[len++]=t;
        else
        {
            *upper_bound(s,s+len,t)=t;
        }
    }
    cout << len << endl;
    return 0;
}
