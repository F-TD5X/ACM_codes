#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int maxn=80*1e5;
int num[maxn],cnt=1,d[maxn][2];

void update(int x){
    int p=1;
    for(int i=30;i>=0;i--){
        if(d[p][(x>>i)&1] ==0)
            d[p][(x>>i)&1]=++cnt;
        p=d[p][(x>>i)&1];
        num[p]++;
    }
}

void update1(int x){
    int p=1;
    for(int i=30;i>=0;i--){
        p=d[p][(x>>i)&1];
        num[p]--;
    }
}

int query(int x){
    int ret=0;
    int p=1;
    for(int i=30;i>=0;i--){
        int t=(x>>i)&1;
        if(num[d[p][1^t]]){
            p=d[p][1^t];
            ret+=(1<<i);
        }
        else
            p=d[p][t];
    }
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("d.in","r",stdin);
    //freopen("d.out","w",stdout);
#endif
    char c;
    int n,x;
    cin >> n;
    update(0);
    for(int i=0;i<n;i++){
        cin >> c >> x;
        if(c == '+')
            update(x);
        else if(c=='-')
            update1(x);
        else 
            cout << query(x)<<endl;
    }
    return 0;
}
